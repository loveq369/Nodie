#pragma once

#include <vector>
#include <map>
#include <string>

#include "Effect.h"


class EffectManager: public cocos2d::CCObject
{
public:
	static EffectManager& getInstance()
	{
		static EffectManager instance;
		return instance;
	}
	void readData(const char* filename);//读取特效静态数据
	EffectConfigData getEffectDataNyName(const char* effectName);//由effectName获取特效静态数据

	void addEffect(const char* effectName, EffectInfo& effectInfo);//添加一个特效（由effectName获取特效静态数据）
	void addEffect(EffectInfo& effectInfo);//添加一个特效
	void removeEffect(EffectNode* effectNode);//移除特效点上的所有特效
	void removeEffect(EffectNode* effectNode, const char* effectName);//移除特效点上的指定特效
	void removeAllEffect();//移除所有特效

	//特效tick（当特效到达时间点，直接移除）
	void tick(float dt);
	//暂停特效tick
	void pauseTick();
	//重新开始特效
	void resumeTick();

private:
	EffectManager();
	EffectManager(const EffectManager&);
	EffectManager& operator=(const EffectManager&);
	~EffectManager();
private:
	std::map<std::string, EffectConfigData> effctConfigDataDic;//静态数据
	std::map<EffectNode*, std::map<std::string, Effect*> > effectDic;//key:特效挂接点，value:该挂接点上所有特效
};
