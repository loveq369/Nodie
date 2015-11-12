#pragma once

#include "LivingThing.h"

class NPC: public LivingThing
{
public:
	NPC();
	NPC(const NPC&);
	NPC& operator=(const NPC&);
	virtual ~NPC();

	virtual void addedToScene();
	virtual float getMoveSpeed();
	virtual tPoint getTileCoord();
	virtual void setTileCoord(const tPoint& tp);
	virtual int getType();
	virtual int getFlag();

	virtual void layoutNameLayer(int x, int y);

	virtual std::string getName();//名字
	virtual int getCurrentHP();//当前血量
	virtual int getTotalHP();//血量上限
	virtual int getCurrentMP();//当前蓝
	virtual int getTotalMP();//蓝上限

	void updateTaskStatus();//更新npc身上的任务状态
	void updateTaskStatus(int status);//更新npc身上的任务状态
	void addNPCTitle();
	cocos2d::CCSequence* getTaskStatusSequence(int status);//获取npc要播放的任务动作
	cocos2d::CCSequence* getSequence(int type=0, cocos2d::CCCallFunc* callFunc=NULL);
	CREATE_FUNC(NPC);
protected:
	virtual void playStand();
protected:
	cocos2d::CCSprite* taskSprite;//任务状态动作
};