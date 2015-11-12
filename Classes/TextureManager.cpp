#include "TextureManager.h"
#include "util/TimeUtil.h"
#include "MacrosDefine.h"
USING_NS_CC;


TextureManager::TextureManager()
{
	m_maxLifecycle = 1200;
	m_maxInterval = 300;
	m_currInterval = 0;
	m_isTicking = false;
	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(
		schedule_selector(TextureManager::tick), this, 0, false);
	CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
}
TextureManager::~TextureManager()
{
	std::map<std::string, CCTexture2D*>::iterator itr;
	//CLEAR_UP_MAP(m_staticTextureDic, itr);

	std::map<std::string, TextureLifecycle> blank;
	m_textureLifecycleDic.swap(blank);

	CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(TextureManager::tick), this);
}
CCTexture2D* TextureManager::addImage(const char* filename)
{
	CCTexture2D* texture = NULL;
	std::map<std::string, TextureLifecycle>::iterator itr = m_textureLifecycleDic.find(filename);
	if (itr!=m_textureLifecycleDic.end())
	{
		itr->second.lastReferenceTime = TimeUtil::getInstance().getTimer();
		itr->second.count++;
		texture = itr->second.texture;
	}
	else
	{
		texture = CCTextureCache::sharedTextureCache()->addImage(filename);
		if (texture)
		{
			TextureLifecycle tlc;
			tlc.lastReferenceTime = TimeUtil::getInstance().getTimer();
			tlc.count = 1;
			tlc.texture = texture;
			tlc.texture->retain();
			m_textureLifecycleDic.insert(std::map<std::string, TextureLifecycle>::value_type(filename, tlc));
		}
	}
	if (!m_isTicking && m_textureLifecycleDic.size()>0)
	{
		CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
		m_isTicking = true;
	}
	return texture;
}
CCTexture2D* TextureManager::addStaticImage(const char* filename)
{
	/*std::map<std::string, cocos2d::CCTexture2D*>::iterator itr = m_staticTextureDic.find(filename);
	if (itr!=m_staticTextureDic.end())
	{
		return itr->second;
	}*/
	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(filename);
	/*if (texture)
	{
		texture->retain();
		m_staticTextureDic.insert(std::map<std::string, CCTexture2D*>::value_type(filename, texture));
	}*/
	return texture;
}
void TextureManager::addStaticImageAsync(const char* filename, cocos2d::CCObject *target, cocos2d::SEL_CallFuncO selector)
{
	this->m_target = target;
	this->m_selector = selector;
	/*std::map<std::string, cocos2d::CCTexture2D*>::iterator itr = m_staticTextureDic.find(filename);
	if (itr!=m_staticTextureDic.end())
	{
	if (target && selector)
	{
	(target->*selector)(itr->second, (void*)filename);
	}
	}
	else*/
	{
		CCTextureCache::sharedTextureCache()->addImageAsync(filename,CC_CALLBACK_1(TextureManager::loadTextureCallback,this));
	}
}
void TextureManager::loadTextureCallback(CCTexture2D* texture)
{
	CCTexture2D* tex2D = texture;
	if (tex2D)
	{
		//std::string name = (char*)filename;
		//m_staticTextureDic[name] = tex2D;
		//tex2D->retain();
		if (m_target && m_selector)
		{
			(m_target->*m_selector)(texture);
		}
	}
}
void TextureManager::removeStaticImage(const char* filename)
{
	/*std::map<std::string, cocos2d::CCTexture2D*>::iterator itr = m_staticTextureDic.find(filename);
	if (itr!=m_staticTextureDic.end())
	{*/
		//CC_SAFE_RELEASE(itr->second);
		CCTextureCache::sharedTextureCache()->removeTextureForKey(filename);
		//m_staticTextureDic.erase(itr);
	//}
}
void TextureManager::tick(float dt)
{
	m_currInterval+=dt;
	if (m_currInterval>=m_maxInterval)
	{
		std::map<std::string, TextureLifecycle>::iterator itr = m_textureLifecycleDic.begin();
		while (itr!=m_textureLifecycleDic.end())
		{
			if (checkNeedRelease(itr->second))
			{
				CC_SAFE_RELEASE(itr->second.texture);
				CCTextureCache::sharedTextureCache()->removeTexture(itr->second.texture);
				m_textureLifecycleDic.erase(itr++);
			}
			else
			{
				++itr;
			}
		}
		m_currInterval = 0;
		if (m_isTicking && m_textureLifecycleDic.size()==0)
		{
			CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
			m_isTicking = false;
		}
	}
}
bool TextureManager::checkNeedRelease(TextureLifecycle& tlc)
{
	if (TimeUtil::getInstance().getTimer()-tlc.lastReferenceTime>=m_maxLifecycle)
	{
		return true;
	}
	return false;
}
