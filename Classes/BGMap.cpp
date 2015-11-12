#include "BGMap.h"
USING_NS_CC;


void removeBGMapTexture(const char* filename)
{
	if (1)
	{
		TextureCache::getInstance()->removeTextureForKey(filename);
	}
}

void removeBGMapTexture(Texture2D * texture)
{
	if (1)
	{
		TextureCache::getInstance()->removeTexture(texture);
	}
}
BGMap::BGMap()
{
	setAnchorPoint(ccp(0,1));
	m_totalNum = 0;
	m_currentNum = 0;
}
BGMap::~BGMap()
{
	clearAll();
	stopAllActions();
}

void BGMap::build(CCSize& mapSize, CCSize& sliceSize, char* mapPath)
{
	m_width = mapSize.width;
	m_height = mapSize.height;
	m_sliceWidth = sliceSize.width;
	m_sliceHeight = sliceSize.height;
	m_folder.assign(mapPath);

	int colNum = int(ceil(float(m_width)/m_sliceWidth));
	int rowNum = int(ceil(float(m_height)/m_sliceHeight));

	char picFileName[_MAX_PATH_];
	for (int i=0;i<rowNum;i++)//行
	{
		for (int j=0;j<colNum;j++)//列
		{
			memset(picFileName,0,sizeof(picFileName));
			sprintf(picFileName, "%s_%d_%d.png", m_folder.c_str(), i, j);
			m_posDic.insert(std::map<std::string, CCPoint>::value_type(picFileName, ccp(m_sliceWidth*j, m_height-m_sliceHeight*i)));
		}
	}
}
void BGMap::firstLoad(CCRect& rect)
{

	int colBigMin;
	int rowBigMin;
	int colBigMax;
	int rowBigMax;
	int moreLoad = 1;

	int colMin;
	int rowMin;
	int colMax;
	int rowMax;

	colMin = ((int)(rect.origin.x / m_sliceWidth)-1);
	rowMin = ((int)((m_height-rect.origin.y) / m_sliceHeight)-1);
	colMax = (int)(((rect.origin.x + rect.size.width) / m_sliceWidth))+1;
	rowMax = (int)((m_height-rect.origin.y+rect.size.height)/ m_sliceHeight)+1;
	int colUpper = (int)(floor(((float)(m_width - 1) / m_sliceWidth)));
	int rowUpper = (int)(floor(((float)(m_height - 1) / m_sliceHeight)));

	colBigMin = WX_MAX(0, (colMin-moreLoad));
	rowBigMin = WX_MAX(0, (rowMin-moreLoad));
	colBigMax = WX_MIN(colUpper, colMax+moreLoad);
	rowBigMax = WX_MIN(rowUpper, rowMax+moreLoad);

	colMin = WX_MAX(0, colMin);
	rowMin = WX_MAX(0, rowMin);
	colMax = WX_MIN(colUpper, colMax);
	rowMax = WX_MIN(rowUpper, rowMax);
	char picFileName[_MAX_PATH_];
	std::map<std::string, char> visibleDic;
	m_visibleFileNameDic.swap(visibleDic);
	std::map<std::string, char> unvisibleDic;
	m_unvisibleFileNameDic.swap(unvisibleDic);
	std::vector<std::string> realLoadList;//真正要加载的图片
	int colIndex;
	int rowIndex;
	for (colIndex=colBigMin;colIndex<=colBigMax;colIndex++)
	{
		for (rowIndex=rowBigMin;rowIndex<=rowBigMax;rowIndex++)
		{
			memset(picFileName,0,sizeof(picFileName));
			sprintf(picFileName, "%s_%d_%d.png",m_folder.c_str(),rowIndex, colIndex);//行_列(列：从左到右依次增大，行：从上到下依次增大)
			std::map<std::string, CCSprite*>::iterator itr = m_bg.find(picFileName);
			if (itr != m_bg.end())
			{
				itr->second->setVisible(true);
			}
			else
			{
				realLoadList.push_back(picFileName);
			}
			if (colIndex>=colMin && colIndex<=colMax && rowIndex>=rowMin && rowIndex<=rowMax)
			{
				m_visibleFileNameDic.insert(std::map<std::string, char>::value_type(picFileName,0));
			}
			else
			{
				m_unvisibleFileNameDic.insert(std::map<std::string, char>::value_type(picFileName,0));
			}
		}
	}
	m_totalNum = realLoadList.size();
	m_currentNum = 0;
	if (m_totalNum==0)
	{
		if (m_target && m_stopLoadFunc)
		{
			(m_target->*m_stopLoadFunc)();
		}
	}
	else
	{
		if (m_target && m_startLoadFunc)
		{
			(m_target->*m_startLoadFunc)(m_totalNum);
		}
		std::vector<std::string>::iterator loadItr = realLoadList.begin();
		for (;loadItr!=realLoadList.end();loadItr++)
		{
			CCTextureCache::sharedTextureCache()->addImageAsync((*loadItr).c_str(), CC_CALLBACK_1(BGMap::loadTextureCallback,this));
		}
	}
}
void BGMap::loadTextureCallback(CCTexture2D* texture)
{
	std::unordered_map<std::string, Texture2D*> ::iterator it=TextureCache::getInstance()->_textures.begin();
	std::string fileFullName="";
	for (;it!=TextureCache::getInstance()->_textures.end();it++)
	{
		if (it->second==texture)
		{
			fileFullName=it->first;
		}
	}
	
	
	if (fileFullName.compare("")!=0)
	{
        std::map<std::string, cocos2d::CCPoint>::iterator itr=m_posDic.begin();
		for (;itr!=m_posDic.end();itr++ )
		{
			if (fileFullName.compare(FileUtils::getInstance()->fullPathForFilename(itr->first))==0)
			{
				CCSprite* picItem = CCSprite::createWithTexture((CCTexture2D*)texture);
				picItem->setAnchorPoint(ccp(0.0f,1.0f));
				picItem->setPosition(ccp(itr->second.x, itr->second.y));
				picItem->setVisible(true);
				this->addChild(picItem);
				m_bg.insert(std::map<std::string, CCSprite*>::value_type(itr->first, picItem));

				removeBGMapTexture(texture);
			}
		}
	}

	m_currentNum++;
	/*if (m_currentNum>=m_totalNum)
	{
	if (m_target && m_stopLoadFunc)
	{
	(m_target->*m_stopLoadFunc)();
	}
	}
	else
	{
	if (m_target && m_loadingFunc)
	{
	(m_target->*m_loadingFunc)(1);
	}
	}*/
}
void BGMap::load(CCRect& rect)
{
	int colBigMin;
	int rowBigMin;
	int colBigMax;
	int rowBigMax;
	int moreLoad = 1;

	int colMin;
	int rowMin;
	int colMax;
	int rowMax;

	colMin = ((int)(rect.origin.x / m_sliceWidth)-1);
	rowMin = ((int)((m_height-rect.origin.y) / m_sliceHeight)-1);
	colMax = (int)(((rect.origin.x + rect.size.width) / m_sliceWidth))+1;
	rowMax = (int)((m_height-rect.origin.y+rect.size.height)/ m_sliceHeight)+1;
	int colUpper = (int)(floor(((float)(m_width - 1) / m_sliceWidth)));
	int rowUpper = (int)(floor(((float)(m_height - 1) / m_sliceHeight)));

	colBigMin = WX_MAX(0, (colMin-moreLoad));
	rowBigMin = WX_MAX(0, (rowMin-moreLoad));
	colBigMax = WX_MIN(colUpper, colMax+moreLoad);
	rowBigMax = WX_MIN(rowUpper, rowMax+moreLoad);

	colMin = WX_MAX(0, colMin);
	rowMin = WX_MAX(0, rowMin);
	colMax = WX_MIN(colUpper, colMax);
	rowMax = WX_MIN(rowUpper, rowMax);
	char picFileName[_MAX_PATH_];
	std::map<std::string, char> visibleDic;
	m_visibleFileNameDic.swap(visibleDic);
	std::map<std::string, char> unvisibleDic;
	m_unvisibleFileNameDic.swap(unvisibleDic);
	int colIndex;
	int rowIndex;
	for (colIndex=colBigMin;colIndex<=colBigMax;colIndex++)
	{
		for (rowIndex=rowBigMin;rowIndex<=rowBigMax;rowIndex++)
		{
			memset(picFileName,0,sizeof(picFileName));
			sprintf(picFileName, "%s_%d_%d.png",m_folder.c_str(),rowIndex, colIndex);//行_列(列：从左到右依次增大，行：从上到下依次增大)
			std::map<std::string, CCSprite*>::iterator itr = m_bg.find(picFileName);
			if (itr != m_bg.end())
			{
				itr->second->setVisible(true);
			}
			else
			{
				m_backgroundWaitLoad.push_back(picFileName);
			}
			if (colIndex>=colMin && colIndex<=colMax && rowIndex>=rowMin && rowIndex<=rowMax)
			{
				m_visibleFileNameDic.insert(std::map<std::string, char>::value_type(picFileName,0));
			}
			else
			{
				m_unvisibleFileNameDic.insert(std::map<std::string, char>::value_type(picFileName,0));
			}
		}
	}

	std::map<std::string, CCSprite*>::iterator itr = m_bg.begin();
	while( itr != m_bg.end() )
	{
		std::map<std::string, char>::iterator result = m_visibleFileNameDic.find(itr->first);
		if (result == m_visibleFileNameDic.end())
		{
			itr->second->setVisible(false);
		}
		++itr;
	}
	if (m_backgroundWaitLoad.size()>0)
	{
		addBackgroundBg();
	}
}
bool BGMap::addUrgencyBg(int num)
{
	if (!m_urgencyWaitLoad.empty())
	{
		int len = m_urgencyWaitLoad.size();
		len = WX_MIN(num, len);
		for (int i=0;i<len;i++)
		{
			std::map<std::string, CCPoint>::iterator itr = m_posDic.find(m_urgencyWaitLoad.back());
			if (itr!=m_posDic.end())
			{
				CCSprite* picItem = CCSprite::create(m_urgencyWaitLoad.back().c_str());
				picItem->setAnchorPoint(ccp(0.0f,1.0f));
				picItem->setPosition(ccp(itr->second.x, itr->second.y));
				picItem->setVisible(true);
				this->addChild(picItem);
				m_bg.insert(std::map<std::string, CCSprite*>::value_type(itr->first, picItem));
			}
			removeBGMapTexture(itr->first.c_str());
			m_urgencyWaitLoad.pop_back();
		}
		return true;
	}
	return false;
}
bool BGMap::addBackgroundBg()
{
	if (!m_backgroundWaitLoad.empty())
	{
		CCTextureCache::sharedTextureCache()->addImageAsync(m_backgroundWaitLoad.back().c_str(),CC_CALLBACK_1(BGMap::bgLoadTextureCallback,this));
		m_backgroundWaitLoad.pop_back();
		return true;
	}
	return false;
}
void BGMap::bgLoadTextureCallback(Texture2D* texture)
{
	std::unordered_map<std::string, Texture2D*> ::iterator it=TextureCache::getInstance()->_textures.begin();
	std::string fileFullName="";
	for (;it!=TextureCache::getInstance()->_textures.end();it++)
	{
		if (it->second==texture)
		{
			fileFullName=it->first;
		}
	}
	if (fileFullName.compare("")==0)
	{
		return;
	}
	std::map<std::string, CCSprite*>::iterator itr=m_bg.begin();
	for (;itr!=m_bg.end();itr++ )
	{
		if (fileFullName.compare(FileUtils::getInstance()->fullPathForFilename(itr->first))==0)
		{
			if (m_visibleFileNameDic.find(itr->first)!=m_visibleFileNameDic.end())
			{
				itr->second->setVisible(true);
			}
			else if (m_unvisibleFileNameDic.find(itr->first)!=m_unvisibleFileNameDic.end())
			{
				itr->second->setVisible(false);
			}
		}
	}
	if (itr==m_bg.end())
	{
		std::map<std::string, char>::iterator itr=m_visibleFileNameDic.begin();
		for (;itr!=m_visibleFileNameDic.end();itr++ )
		{
			if (fileFullName.compare(FileUtils::getInstance()->fullPathForFilename(itr->first))==0)
			{
				std::map<std::string, CCPoint>::iterator posItr = m_posDic.find(itr->first);
				if (posItr!=m_posDic.end())
				{
					CCSprite* picItem = CCSprite::createWithTexture((CCTexture2D*)texture);
					picItem->setAnchorPoint(ccp(0.0f,1.0f));
					picItem->setPosition(ccp(posItr->second.x, posItr->second.y));
					picItem->setVisible(true);
					addChild(picItem);
					m_bg.insert(std::map<std::string, CCSprite*>::value_type(posItr->first, picItem));
				}
				removeBGMapTexture(itr->first.c_str());
			}
		}
		
		if (itr==m_visibleFileNameDic.end())
		{
			std::map<std::string, char>::iterator itr=m_unvisibleFileNameDic.begin();
			for (;itr!=m_unvisibleFileNameDic.end();itr++ )
			{
				if (fileFullName.compare(FileUtils::getInstance()->fullPathForFilename(itr->first))==0)
				{
					std::map<std::string, CCPoint>::iterator posItr = m_posDic.find(itr->first);
					if (posItr!=m_posDic.end())
					{
						CCSprite* picItem = CCSprite::createWithTexture((CCTexture2D*)texture);
						picItem->setAnchorPoint(ccp(0.0f,1.0f));
						picItem->setPosition(ccp(posItr->second.x, posItr->second.y));
						picItem->setVisible(false);
						addChild(picItem);
						m_bg.insert(std::map<std::string, CCSprite*>::value_type(posItr->first, picItem));
					}
					removeBGMapTexture(itr->first.c_str());
				}
			}
			if (itr==m_unvisibleFileNameDic.end())
			{
				removeBGMapTexture(texture);
			}
		}
	}
}
void BGMap::clearAll()
{
	removeAllChildrenWithCleanup(true);
	std::map<std::string, CCSprite*> blankDic;
	m_bg.swap(blankDic);
	std::map<std::string, CCPoint> blankDic2;
	m_posDic.swap(blankDic2);
	std::map<std::string, char> blankDic3;
	m_visibleFileNameDic.swap(blankDic3);
	std::map<std::string, char> blankDic4;
	m_unvisibleFileNameDic.swap(blankDic3);
	std::vector<std::string> blankList1;
	m_urgencyWaitLoad.swap(blankList1);
	std::vector<std::string> blankList2;
	m_backgroundWaitLoad.swap(blankList2);
}
void BGMap::setTarget(CCNode* target, SEL_CallFuncI startLoadFunc, SEL_CallFuncI loadingFunc, SEL_CallFunc stopLoadFunc)
{
	this->m_target = target;
	this->m_startLoadFunc = startLoadFunc;
	this->m_loadingFunc = loadingFunc;
	this->m_stopLoadFunc = stopLoadFunc;
}