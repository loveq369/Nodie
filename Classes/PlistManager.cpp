#include "PlistManager.h"
#include "util/ReadUtil.h"
USING_NS_CC;



	PlistManager::PlistManager()
{

}
PlistManager::~PlistManager()
{
	std::map<std::string, std::vector<std::string> > blank;
	m_mUIPlistDic.swap(blank);
}

void PlistManager::addUISpriteFrames( const char* plistPath )
{
	std::map<std::string, std::vector<std::string> >::iterator itr = m_mUIPlistDic.find(plistPath);
	if (itr==m_mUIPlistDic.end())//不存在就加载
	{
		unsigned long fileLen = 0;
		unsigned char *fileData = NULL;
		fileData = CCFileUtils::sharedFileUtils()->getFileData(plistPath, "rb", (ssize_t *)(&fileLen));
		if (!fileData)
		{
			return;
		}
		unsigned char* temp = fileData;
		unsigned long pos = 0;
		std::string picNameStr = "";
		pos += readString(fileData, picNameStr);
		picNameStr = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(picNameStr.c_str(), plistPath);
		CCTexture2D* pobTexture = CCTextureCache::sharedTextureCache()->addImage(picNameStr.c_str());
		if (pobTexture)
		{
			std::vector<std::string> nameList;
			UIPlistFrame uiPlistframe;
			CCSpriteFrame* spriteFrame;
			std::string spriteFrameName;
			short len;
			pos += readShort(fileData, len);
			for (short i=0;i<len;i++)
			{
				pos += readString(fileData, spriteFrameName);
				uiPlistframe.encode(fileData, pos);
				spriteFrame=CCSpriteFrame::createWithTexture(pobTexture,\
					uiPlistframe.m_frame, \
					uiPlistframe.m_rateted, \
					uiPlistframe.m_offset, \
					uiPlistframe.m_sourceSize);
				CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(spriteFrame, spriteFrameName.c_str());
				//spriteFrame->release();
				nameList.push_back(spriteFrameName);
			}

			m_mUIPlistDic[plistPath] = nameList;
		}
		CC_SAFE_DELETE_ARRAY(temp);
	}
}

void PlistManager::removeUISpirteFrames( const char* plistPath )
{
	std::map<std::string, std::vector<std::string> >::iterator itr = m_mUIPlistDic.find(plistPath);
	if (itr!=m_mUIPlistDic.end())
	{
		std::vector<std::string>::iterator listItr = itr->second.begin();
		for (;listItr!=itr->second.end();listItr++)
		{
			CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFrameByName((*listItr).c_str());
		}
		m_mUIPlistDic.erase(itr);
	}
}

UIPlistFrame::UIPlistFrame()
{
	m_frame = cocos2d::CCRect::ZERO;
	m_offset = cocos2d::CCPoint::ZERO;
	m_rateted = false;
	m_sourceSize = cocos2d::CCSize::ZERO;
}

void UIPlistFrame::encode( unsigned char*& data, unsigned long& pos )
{
	short x = 0;
	short y = 0;
	short w = 0;
	short h = 0;
	pos += readShort(data, x);
	pos += readShort(data, y);
	pos += readShort(data, w);
	pos += readShort(data, h);
	m_frame = cocos2d::CCRectMake(x,y,w,h);

	short px = 0;
	short py = 0;
	pos += readShort(data, px);
	pos += readShort(data, py);
	m_offset = ccp(px, py);

	pos += readBool(data, m_rateted);

	pos += readShort(data, px);
	pos += readShort(data, py);
	m_sourceSize = cocos2d::CCSizeMake(px, py);
}