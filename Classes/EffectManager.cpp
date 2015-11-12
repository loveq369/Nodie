#include "EffectManager.h"
USING_NS_CC;


	EffectManager::EffectManager(void)
{
	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(
		schedule_selector(EffectManager::tick), this, 0, false);
	CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
}
EffectManager::~EffectManager(void)
{
	std::map<std::string, EffectConfigData> blankData;
	effctConfigDataDic.swap(blankData);
	removeAllEffect();
	CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(EffectManager::tick), this);
}
void EffectManager::pauseTick()
{
	CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
}
void EffectManager::resumeTick()
{
	if (effectDic.size()>0)
	{
		CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
	}
}
void EffectManager::readData(const char* filename)
{
	ssize_t fileLen = 0;
	unsigned char *fileData = NULL;
	fileData = CCFileUtils::sharedFileUtils()->getFileData(CCFileUtils::sharedFileUtils()->fullPathForFilename(filename).c_str(), "rb", (ssize_t *)(&fileLen));
	unsigned char* temp = fileData;
	unsigned long pos = 0;
	while (pos<(fileLen-1))
	{
		EffectConfigData configData;
		configData.encode(fileData, pos);

		effctConfigDataDic.insert(std::map<std::string, EffectConfigData>::value_type(configData.m_effectName, configData));
	}

	CC_SAFE_DELETE_ARRAY(temp);
}
EffectConfigData EffectManager::getEffectDataNyName(const char* effectName)
{
	std::map<std::string, EffectConfigData>::iterator itr = effctConfigDataDic.find(effectName);
	if (itr != effctConfigDataDic.end())
	{
		return itr->second;
	}
	EffectConfigData ecd;
	ecd.m_particleName = "";
	return ecd;
}
void EffectManager::addEffect(const char* effectName, EffectInfo& effectInfo)
{
	effectInfo.m_configData = getEffectDataNyName(effectName);
	addEffect(effectInfo);
}
void EffectManager::addEffect(EffectInfo& effectInfo)
{
	if (effectInfo.m_configData.m_particleName=="" || !effectInfo.m_effectParent)
	{
		return;
	}
	Effect* effect = new Effect();
	effect->setEffectInfo(effectInfo);
	effect->init();
	std::map<EffectNode*, std::map<std::string, Effect*> >::iterator itr = effectDic.find(effectInfo.m_effectParent);
	if (itr!=effectDic.end())
	{
		itr->second.insert(std::map<std::string, Effect*>::value_type(effectInfo.m_configData.m_effectName, effect));
	}
	else
	{
		std::map<std::string, Effect*> effDic;
		effDic.insert(std::map<std::string, Effect*>::value_type(effectInfo.m_configData.m_effectName, effect));
		effectDic.insert(std::map<EffectNode*, std::map<std::string, Effect*> >::value_type(effectInfo.m_effectParent, effDic));
	}
	if (effectDic.size()==1)
	{
		CCDirector::sharedDirector()->getScheduler()->resumeTarget(this);
	}
}
void EffectManager::removeEffect(EffectNode* effectNode)
{
	std::map<EffectNode*, std::map<std::string, Effect*> >::iterator dicItr = effectDic.find(effectNode);
	if (dicItr!=effectDic.end())
	{
		std::map<std::string, Effect*>::iterator itr = dicItr->second.begin();
		while (itr!=dicItr->second.end())
		{
			if (itr->second)
			{
				delete itr->second;
			}
			dicItr->second.erase(itr++);
		}
		effectDic.erase(dicItr);
	}
}
void EffectManager::removeEffect(EffectNode* effectNode, const char* effectName)
{
	std::map<EffectNode*, std::map<std::string, Effect*> >::iterator dicItr = effectDic.find(effectNode);
	if (dicItr!=effectDic.end())
	{
		std::map<std::string, Effect*>::iterator itr = dicItr->second.find(effectName);
		if (itr != dicItr->second.end())
		{
			if (itr->second)
			{
				delete itr->second;
			}
			dicItr->second.erase(itr);
		}
		if (dicItr->second.size()==0)
		{
			effectDic.erase(dicItr);
		}
	}
}
void EffectManager::removeAllEffect()
{
	std::map<EffectNode*, std::map<std::string, Effect*> >::iterator dicItr = effectDic.begin();
	std::map<std::string, Effect*>::iterator itr;
	for (;dicItr!=effectDic.end();dicItr++)
	{
		for (;itr!=dicItr->second.end();itr++)
		{
			if (itr->second)
			{
				delete itr->second;
			}
		}
	}
	std::map<EffectNode*, std::map<std::string, Effect*> > blank;
	effectDic.swap(blank);
}
void EffectManager::tick(float dt)
{
	std::map<EffectNode*, std::map<std::string, Effect*> >::iterator dicItr = effectDic.begin();
	std::map<std::string, Effect*>::iterator itr;
	while (dicItr!=effectDic.end())
	{
		itr = dicItr->second.begin();
		while (itr!=dicItr->second.end())
		{
			itr->second->tick(dt);
			if (itr->second->isDead())
			{
				if (itr->second)
				{
					delete itr->second;
				}
				dicItr->second.erase(itr++);
			}
			else
			{
				++itr;
			}
		}
		if (dicItr->second.size()==0)
		{
			effectDic.erase(dicItr++);
		}
		else
		{
			dicItr++;
		}
	}
	if (effectDic.size()==0)
	{
		CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
	}
}