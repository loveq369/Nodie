#pragma once

#include "LivingThing.h"
#include "NPC.h"
#include "GameDefine.h"

class TargetController
{
public:
	static TargetController& getInstance()
	{
		static TargetController instance;
		return instance;
	}

	//随机获取一个目标
	void randomSelectedTarget(int entityType=ENTITY_TYPE_NPC, int npcType=NPC_TYPE_MONSTER);

	LivingThing* randomSwitchTarget();//随机锁定一个目标

	void setTarget(LivingThing* target);//设置目标（选中目标）
	bool checkTarget(LivingThing* target);//检查目标（target是否是选中的目标）
	void updateTarget(LivingThing* target);//更新目标（更新目标信息）
	void breakFollower();//打断跟随
	void toggleTargetHeadImage(bool isShow=true);//开关目标头像
	LivingThing* getTarget(){return _target;}

	void targetDead(LivingThing* target);//有单位死亡了
	void targetSelected(LivingThing* target);//目标被选中
	void targetUnSelected(LivingThing* target);//目标不被选中

	CC_SYNTHESIZE(bool, isShowEffect, IsShowEffect);//效果是否显示

private:
	TargetController();
	TargetController(const TargetController&);
	TargetController& operator=(const TargetController&);
	~TargetController();

private:
	LivingThing* _target;
};