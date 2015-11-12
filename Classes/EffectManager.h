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
	void readData(const char* filename);//��ȡ��Ч��̬����
	EffectConfigData getEffectDataNyName(const char* effectName);//��effectName��ȡ��Ч��̬����

	void addEffect(const char* effectName, EffectInfo& effectInfo);//���һ����Ч����effectName��ȡ��Ч��̬���ݣ�
	void addEffect(EffectInfo& effectInfo);//���һ����Ч
	void removeEffect(EffectNode* effectNode);//�Ƴ���Ч���ϵ�������Ч
	void removeEffect(EffectNode* effectNode, const char* effectName);//�Ƴ���Ч���ϵ�ָ����Ч
	void removeAllEffect();//�Ƴ�������Ч

	//��Чtick������Ч����ʱ��㣬ֱ���Ƴ���
	void tick(float dt);
	//��ͣ��Чtick
	void pauseTick();
	//���¿�ʼ��Ч
	void resumeTick();

private:
	EffectManager();
	EffectManager(const EffectManager&);
	EffectManager& operator=(const EffectManager&);
	~EffectManager();
private:
	std::map<std::string, EffectConfigData> effctConfigDataDic;//��̬����
	std::map<EffectNode*, std::map<std::string, Effect*> > effectDic;//key:��Ч�ҽӵ㣬value:�ùҽӵ���������Ч
};
