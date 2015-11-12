#include "WXRichLabelEx.h"
#include "AnimateManager.h"
#include "WXUIDefine.h"
#include "WXLinkLabel.h"
#include "MacrosDefine.h"
USING_NS_CC;


#define		BOUNDARY_LEN		5
#define		BOUNDARY_LEN_RIGHT		2		//右侧特殊控制
WXRichLabelEx::WXRichLabelEx(void)
{
	m_fontName = FONT_NAME_CONSOLAS;
	m_fontSize = 14;			
	m_currentPos = ccp(BOUNDARY_LEN,-BOUNDARY_LEN);
	m_curLabelIndex = 0;
	m_DimensionWidth=100;
	m_startPos=ccp(BOUNDARY_LEN,-BOUNDARY_LEN);
	m_leftWidth=0;
	m_oneCcharWidth=0;
	m_fontHeight=0;
	m_bg = NULL;
	m_bgColor = ccc4(128,128,128,0xaa);
	m_bCrossLabel = true;
	this->setVisible(false);
}


WXRichLabelEx::~WXRichLabelEx(void)
{

}
void WXRichLabelEx::ResetContent()
{
	m_currentPos=m_startPos;
	m_leftWidth = m_DimensionWidth;
	m_curLabelIndex=0;
	m_manageLayer->removeAllChildrenWithCleanup(true);

	std::vector<ClinkData> blank;
	m_data.swap(blank);
}

bool WXRichLabelEx::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!this->isVisible())
		return false;

	CCPoint convertedLocation = this->convertTouchToNodeSpace(pTouch);
	if(m_pTarget && m_pCallBack)
	{
		//判断选中矩形框
		std::vector<ClinkData>::iterator itr = m_data.begin();
		ClinkData* v=NULL;
		while( itr != m_data.end() )
		{
			v = &*itr;
			if (itr->rect.containsPoint(convertedLocation))
			{	
				mask->setPosition( itr->rect.origin );
				mask->setContentSize(CCSize(itr->rect.size.width, itr->rect.size.height));
				mask->setVisible(true);
				return true;
			}
			itr++;
		}
	}
	if (!m_bCrossLabel)
	{
		CCRect r = rect();
		if (r.containsPoint(convertedLocation))
		{
			return true;
		}
	}
	return false;
}

void WXRichLabelEx::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
}
void WXRichLabelEx::onTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	mask->setVisible(false);
}
bool WXRichLabelEx::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	mask->setVisible(false);
	CCPoint convertedLocation = this->convertTouchToNodeSpace(pTouch);
	if(m_pTarget && m_pCallBack)
	{
		//判断选中矩形框
		std::vector<ClinkData>::iterator itr = m_data.begin();
		ClinkData* v=NULL;
		while( itr != m_data.end() )
		{
			v = &*itr;
			if (itr->rect.containsPoint(convertedLocation))
			{	
				(m_pTarget->*m_pCallBack)(v->id);
				return true;
			}
			itr++;
		}
	}
	if (!m_bCrossLabel)
	{
		CCRect r = rect();
		if (r.containsPoint(convertedLocation))
		{
			return true;
		}
	}
	return false;
}

void WXRichLabelEx::Initialize(std::string fontName, float fontSize,CCSize dimension,CCObject* target,SEL_CallFuncI callBack)
{
	m_pTarget = target;
	m_pCallBack = callBack;

	WINSIZE;
	m_manageLayer = CCLayer::create( );
	m_manageLayer->setPosition( ccp(0,0) );
	addChild(m_manageLayer, 3);
	
	m_DimensionWidth = dimension.width-BOUNDARY_LEN-BOUNDARY_LEN_RIGHT;
	m_leftWidth = m_DimensionWidth;
	m_oneCcharWidth=(fontSize+2)/2;
	m_fontHeight=fontSize+7;
	m_fontName = fontName;			
	m_fontSize = fontSize;		

	m_labelCal =CCLabelTTF::create("test", m_fontName.c_str(), m_fontSize);
	m_labelCal->setAnchorPoint(CCPointMake(0, 1));		//左上
	addChild(m_labelCal, 5);
	m_labelCal->setVisible(false);

	//for( int i=0; i < LABEL_CACHE_INIT_SIZE ; i++ )
	//{
	//	m_labelCache[i] = CCLabelTTF::create("test", m_fontName.c_str(), m_fontSize);
	//	m_labelCache[i]->setAnchorPoint(CCPointMake(0, 1));		//左上
	//	m_manageLayer->addChild(m_labelCache[i], 5);
	//	m_labelCache[i]->setVisible(false);
	//}
	
	mask = CCLayerColor::create( ccc4(0xaa, 0x00, 0x00, 0xaa), 10, 10);
	addChild(mask, 3);
	mask->setVisible(false);
}
void WXRichLabelEx::setTarget(cocos2d::CCObject* target, SEL_CallFuncI callBack)
{
	m_pTarget = target;
	m_pCallBack = callBack;
}

//string:输入字符串
//color:文字颜色
//id:0不可点
void WXRichLabelEx::AddString( std::string string, ccColor3B color,int id, bool isUnderLine )
{
	m_labelCal->setString(string.c_str());
	CCSize size = m_labelCal->getContentSize();
	if( m_leftWidth<m_oneCcharWidth )//剩余小于单个英文宽度
		this->EnterPos();

	if( size.width<= m_leftWidth )//一行能显示开
	{
		LabelAdd(string,color,id,isUnderLine);
		m_currentPos.x+=size.width;
		m_leftWidth-=size.width;
	}
	else		//一行显示不开
	{
		int iLeft,unitCount;
		std::string strLeft,strRight;
		unitCount = m_leftWidth/m_oneCcharWidth;
		
		iLeft=0;
		while(1)
		{
			bool b=false;
			//if (string[iLeft] & 0x80)
			if (!((string[iLeft] & 0xF0) ^ 0xE0))
				b=true;

			if(b)//多字节
			{
				iLeft+=3;
				unitCount-=2;
				if(unitCount==0)
					break;
				if(unitCount<0)
				{
					iLeft-=3;
					break;
				}
				
			}
			else//非多字节
			{
				iLeft++;
				unitCount--;
				if(unitCount==0)
					break;
			}
		}
		
		strLeft = string.substr(0,iLeft);
		strRight = string.substr(iLeft,string.length());

		LabelAdd(strLeft,color,id,isUnderLine);
		EnterPos();
		AddString(strRight,color,id,isUnderLine);
	}

}

//换行设置位置参数
void WXRichLabelEx::EnterPos( )
{
	m_currentPos.x=m_startPos.x;
	m_currentPos.y-=m_fontHeight;
	m_leftWidth=m_DimensionWidth;
}

void WXRichLabelEx::LabelAdd( std::string string, ccColor3B color,int id, bool isUnderLine )
{
	if (isUnderLine || id>0)
		m_labelCache = WXLinkLabel::create(string.c_str(), m_fontName.c_str(), m_fontSize);
	else
		m_labelCache = CCLabelTTF::create(string.c_str(), m_fontName.c_str(), m_fontSize);
	m_labelCache->setAnchorPoint(CCPointMake(0, 1));		//左上
	m_manageLayer->addChild(m_labelCache, 5);
	m_labelCache->setVisible(true);
	m_labelCache->setString(string.c_str());

	if( id!=0 )
	{
		ClinkData data;
		CCSize size =m_labelCache->getContentSize();
		data.rect=CCRectMake(m_currentPos.x,m_currentPos.y-size.height,size.width,size.height);
		data.id=id;
		m_data.push_back(data);
	}

	m_labelCache->setColor(color);
	m_labelCache->setPosition(m_currentPos);
	m_curLabelIndex++;
}

//id:表情号
void WXRichLabelEx::AddFace( int id )
{
	char buffer[4];
	sprintf(buffer,"%d",id);
	std::string str;
	str="face";
	str.append(buffer);
	int width;

	m_faceSpirit = CCSprite::create();
	m_faceSpirit->setAnchorPoint(ccp(0,1));
	m_manageLayer->addChild(m_faceSpirit,0);
	width = AnimateManager::getInstance().getFrameHeight(g_defaultFaceFilename.c_str(), str.c_str());
	
	CCSequence* seq = AnimateManager::getInstance().getSequence(g_defaultFaceFilename.c_str(), str.c_str(), NULL);
	if (!seq)
		return;

	m_faceSpirit->runAction(CCRepeatForever::create(seq));
	if( width > m_leftWidth )//换行
		EnterPos();

	m_faceSpirit->setPosition(m_currentPos);
	m_currentPos.x+=width;
	m_leftWidth-=width;
}

//move:移动距离,像素
void WXRichLabelEx::XMove( int move )
{
	m_currentPos.x+=move;
	m_leftWidth-=move;
}

//pic:文件名
void WXRichLabelEx::AddPic( std::string pic )
{
	bool bNotify = CCFileUtils::sharedFileUtils()->isPopupNotify();
	CCFileUtils::sharedFileUtils()->setPopupNotify(false);
	m_picSpirit=CCSprite::create(pic.c_str());
	CCFileUtils::sharedFileUtils()->setPopupNotify(bNotify);
	if (!m_picSpirit)
	{
		return;
	}
	m_manageLayer->addChild(m_picSpirit,10);
	m_picSpirit->setAnchorPoint(ccp(0,1));

	CCSize sz=m_picSpirit->getContentSize();
	if( sz.width > m_leftWidth )//换行
		EnterPos();

	m_picSpirit->setPosition(m_currentPos);
	m_currentPos.x+=sz.width;
	m_leftWidth-=sz.width;
}

//得到当前高度
int WXRichLabelEx::GetCurrentHeight( )
{
	return m_currentPos.y-m_fontHeight;
}

void WXRichLabelEx::showBGColor(bool isShow)
{
	if (isShow)
	{
		if (!m_bg)
		{
			m_bg = CCLayerColor::create(m_bgColor);
			m_bg->setAnchorPoint(CCPoint::ZERO);
			addChild(m_bg, -1);
		}
		m_bg->setContentSize(CCSizeMake(m_DimensionWidth,-GetCurrentHeight()));
		m_bg->setPositionY(GetCurrentHeight());
	}
	if (m_bg) m_bg->setVisible(isShow);
}
void WXRichLabelEx::setBGColor(cocos2d::ccColor4B color)
{
	m_bgColor = color;
	if (m_bg)
		m_bg->setColor(ccc3(color.r,color.g,color.b));
}
CCRect WXRichLabelEx::rect()
{
	return CCRectMake(0,GetCurrentHeight(),m_DimensionWidth, -GetCurrentHeight());
}

void WXRichLabelEx::setDefaultFaceFilename( std::string var )
{
	g_defaultFaceFilename = var;
}

