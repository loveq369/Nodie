#include "WXMessageBox.h"
#include "WXSimpleButton.h"
#include "WXUIDefine.h"
#include "WXMenu.h"
USING_NS_CC;


WXMessageBox::WXMessageBox(void)
{
	m_messageLabel = NULL;
	m_isModal = false;
	m_mbtarget = NULL;
	m_mbselector = NULL;
	m_bindData = NULL;
	m_currentType = WX_MB_TYPE_LEFT_RIGHT;
	m_btnMenu = NULL;
	m_leftBtn = NULL;
	m_centerBtn = NULL;
	m_rightBtn = NULL;
	m_bgSprite = NULL;
}
WXMessageBox::~WXMessageBox(void)
{
	CC_SAFE_DELETE_ARRAY(m_bindData);
}
bool WXMessageBox::init()
{
	bool bRet = false;
	do 
	{
		bRet = true;
	} while (0);
	return bRet;
}
WXMessageBox* WXMessageBox::createWithItem(cocos2d::CCNode* bg, WXSimpleButton* leftBtn, WXSimpleButton* centerBtn, WXSimpleButton* rightBtn)
{
	WXMessageBox* pRet = new WXMessageBox();
	if (pRet && pRet->initWithItem(bg, leftBtn, centerBtn, rightBtn))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool WXMessageBox::initWithItem(cocos2d::CCNode* bg, WXSimpleButton* leftBtn, WXSimpleButton* centerBtn, WXSimpleButton* rightBtn)
{
	setBGSprite(bg);

	m_btnMenu = WXMenu::create();//leftBtn, centerBtn, rightBtn, NULL);
	int hl = 0;
	int hc = 0;
	int hr = 0;
	if (leftBtn)
	{
		this->m_leftBtn = leftBtn;
		hl = leftBtn->getContentSize().height;
		leftBtn->setTarget(this, menu_selector(WXMessageBox::btnCallback));
		m_btnMenu->addChild(leftBtn, 0, WX_MB_ID_LEFT);
	}
	if (centerBtn)
	{
		this->m_centerBtn = centerBtn;
		hc = centerBtn->getContentSize().height;
		centerBtn->setTarget(this, menu_selector(WXMessageBox::btnCallback));
		m_btnMenu->addChild(centerBtn, 0, WX_MB_ID_CENTER);
	}
	if (rightBtn)
	{
		this->m_rightBtn = rightBtn;
		hr = rightBtn->getContentSize().height;
		rightBtn->setTarget(this, menu_selector(WXMessageBox::btnCallback));
		m_btnMenu->addChild(rightBtn, 0, WX_MB_ID_RIGHT);
	}
	int h = hl>hc?hl:hc;
	h = hr>h?hr:h;
	m_btnMenu->setPosition(ccp(getContentSize().width/2, 10+h/2));
	addChild(m_btnMenu);

	layout();
	return true;
}
void WXMessageBox::setBGSprite(CCNode* var)
{
	if (var!=m_bgSprite)
	{
		if (var)
		{
			addChild(var);
			var->setAnchorPoint(CCPoint::ZERO);
		}
		if (m_bgSprite)
		{
			removeChild(m_bgSprite, true);
		}
		m_bgSprite = var;
		setContentSize(m_bgSprite->getContentSize());
	}
}
void WXMessageBox::setLeftBtn(WXSimpleButton* var)
{
	if (var!=m_leftBtn && m_btnMenu)
	{
		if (var)
		{
			m_btnMenu->addChild(var);
			var->setAnchorPoint(CCPoint::ZERO);
		}
		if (m_leftBtn)
		{
			m_btnMenu->removeChild(m_leftBtn, true);
		}
		m_leftBtn = var;
		m_leftBtn->setTag(WX_MB_ID_LEFT);
		layout();
	}
}
void WXMessageBox::setCentreBtn(WXSimpleButton* var)
{
	if (var!=m_centerBtn && m_btnMenu)
	{
		if (var)
		{
			m_btnMenu->addChild(var);
			var->setAnchorPoint(CCPoint::ZERO);
		}
		if (m_centerBtn)
		{
			m_btnMenu->removeChild(m_centerBtn, true);
		}
		m_centerBtn = var;
		m_centerBtn->setTag(WX_MB_ID_CENTER);
		layout();
	}
}
void WXMessageBox::setRightBtn(WXSimpleButton* var)
{
	if (var!=m_rightBtn && m_btnMenu)
	{
		if (var)
		{
			m_btnMenu->addChild(var);
			var->setAnchorPoint(CCPoint::ZERO);
		}
		if (m_rightBtn)
		{
			m_btnMenu->removeChild(m_rightBtn, true);
		}
		m_rightBtn = var;
		m_rightBtn->setTag(WX_MB_ID_RIGHT);
		layout();
	}
}
CCNode* WXMessageBox::getBGSprite()
{
	return m_bgSprite;
}
WXSimpleButton* WXMessageBox::getLeftBtn()
{
	return m_leftBtn;
}
WXSimpleButton* WXMessageBox::getCentreBtn()
{
	return m_centerBtn;
}
WXSimpleButton* WXMessageBox::getRightBtn()
{
	return m_rightBtn;
}
void WXMessageBox::showMessageBox()
{
	show(true);
}
void WXMessageBox::showMessageBox(const char* str)
{
	show(true);
	setString(str);
}
void WXMessageBox::showMessageBox(const char* str, cocos2d::CCObject* target, SEL_CallFuncDD selector)
{
	show(true);
	setString(str);
	setTarget(target, selector);
}
void WXMessageBox::showMessageBox(const char* str, CCObject* target, SEL_CallFuncDD selector, int type/* =WX_MB_YESNO */, bool isModal/* =false */)
{
	show(true);
	setModal(isModal);
	setType(type);
	setString(str);
	setTarget(target, selector);
}
void WXMessageBox::layout()
{
	if (!m_btnMenu)
	{
		return;
	}
	float width = 0;
	int num = 0;
	if ( m_btnMenu->getChildren().size() > 0)
	{
		auto& children = getChildren();
		for(const auto &pObject : children)
		{
			int tag;
			CCNode* pChild = dynamic_cast<CCNode*>(pObject);
			if (pChild)
			{
				tag = pChild->getTag();
				if ((tag&m_currentType)>0)
				{
					pChild->setVisible(true);
					width += pChild->getContentSize().width*pChild->getScaleX();
					num++;
				}
				else
				{
					pChild->setVisible(false);
				}
			}
		}
	}
	int padding = (getContentSize().width-width)/(num+1);
	width = -padding;
	if (getChildren().size() > 0)
	{
		auto& children = getChildren();
		for(const auto &pObject : children)
		{
			CCNode* pChild = dynamic_cast<CCNode*>(pObject);
			if (pChild && pChild->isVisible())
			{
				width += pChild->getContentSize().width*pChild->getScaleX()+padding;
			}
		}
	}

	float x = -width / 2.0f;
	if (getChildren().size() > 0)
	{
		auto& children = getChildren();
		for(const auto &pObject : children)
		{
			CCNode* pChild = dynamic_cast<CCNode*>(pObject);
			if (pChild && pChild->isVisible())
			{
				pChild->setPosition(ccp(x + pChild->getContentSize().width * pChild->getScaleX() / 2.0f, 0));
				x += pChild->getContentSize().width * pChild->getScaleX() + padding;
			}
		}
	}
}
void WXMessageBox::setBtnString(const char* leftStr, const char* centerStr, const char* rightStr)
{
	if ( m_btnMenu->getChildren().size() > 0)
	{
		CCObject* pObject = NULL;
		int index = WX_MB_ID_LEFT;
		auto& children = getChildren();
		for(const auto &pChild : children)
		{
			WXSimpleButton* pChild = dynamic_cast<WXSimpleButton*>(pObject);
			if (pChild)
			{
				switch (index)
				{
				case WX_MB_ID_LEFT:
					pChild->setString(leftStr);
					break;
				case WX_MB_ID_CENTER:
					pChild->setString(centerStr);
					break;
				case WX_MB_ID_RIGHT:
					pChild->setString(rightStr);
					break;
				}
			}
			index = index << 1;
		}
	}
}
void WXMessageBox::setType(int type)
{
	m_currentType = type;
	layout();
}
void WXMessageBox::setModal(bool isModal)
{
	this->m_isModal = isModal;
}
void WXMessageBox::setString(const char* str)
{
	if (!m_messageLabel)
	{
		m_messageLabel = CCLabelTTF::create(" ", FONT_NAME_HELVETICA, 24);
		m_messageLabel->setPosition(ccp(getContentSize().width/2, getContentSize().height-20));
		m_messageLabel->setAnchorPoint(ccp(0.5, 1));
		m_messageLabel->setVisible(false);
		addChild(m_messageLabel);
	}
	m_messageLabel->setString(str);
	if (!str)
	{
		m_messageLabel->setVisible(false);
	}
	else
	{
		m_messageLabel->setVisible(true);
	}
}
void WXMessageBox::setTarget(CCObject* target, SEL_CallFuncDD selector)
{
	this->m_mbtarget = target;
	this->m_mbselector = selector;
}
void WXMessageBox::setBindData(void* data, int len)
{
	CC_SAFE_DELETE_ARRAY(m_bindData);
	m_bindData = new unsigned char[len];
	memset(m_bindData, 0, len);
	memcpy(m_bindData, data, len);
	/*
	unsigned char* source = (unsigned char*)data;
	for (int i=0;i<len;i++)
	{
		*bindData++ = *source++;
	}*/
}
void WXMessageBox::btnCallback(CCObject* pSender)
{
	close();
	if (m_mbtarget && m_mbselector)
	{
		CCMenuItem* btn = dynamic_cast<CCMenuItem*>(pSender);
		if (btn)
		{
			int type;
			switch (btn->getTag())
			{
			case 1:
				type = WX_MB_ID_LEFT;
				break;
			case 2:
				type = WX_MB_ID_CENTER;
				break;
			case 3:
				type = WX_MB_ID_RIGHT;
				break;
			}
			(m_mbtarget->*m_mbselector)((void*)&type, (void*)m_bindData);
		}
	}
}
void WXMessageBox::close()
{
	show(false);
}
bool WXMessageBox::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!isShow())
	{
		return false;
	}
	if (m_btnMenu && m_btnMenu->onTouchBegan(pTouch, pEvent))
	{
		return true;
	}
	if (m_isModal)
	{
		return true;
	}
	return WXSimplePanel::onTouchBegan(pTouch, pEvent);
}
bool WXMessageBox::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!isShow())
	{
		return false;
	}
	if (m_btnMenu && m_btnMenu->onTouchBegan(pTouch, pEvent))
	{
		return true;
	}
	if (m_isModal)
	{
		return true;
	}
	return WXSimplePanel::onTouchEnded(pTouch, pEvent);
}
void WXMessageBox::onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
	if (isShow())
	{
		if (m_btnMenu) m_btnMenu->onTouchCancelled(pTouch, pEvent);
	}
}
void WXMessageBox::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	if (isShow())
	{
		if (m_btnMenu) m_btnMenu->onTouchMoved(pTouch, pEvent);
	}
}
