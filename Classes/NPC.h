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

	virtual std::string getName();//����
	virtual int getCurrentHP();//��ǰѪ��
	virtual int getTotalHP();//Ѫ������
	virtual int getCurrentMP();//��ǰ��
	virtual int getTotalMP();//������

	void updateTaskStatus();//����npc���ϵ�����״̬
	void updateTaskStatus(int status);//����npc���ϵ�����״̬
	void addNPCTitle();
	cocos2d::CCSequence* getTaskStatusSequence(int status);//��ȡnpcҪ���ŵ�������
	cocos2d::CCSequence* getSequence(int type=0, cocos2d::CCCallFunc* callFunc=NULL);
	CREATE_FUNC(NPC);
protected:
	virtual void playStand();
protected:
	cocos2d::CCSprite* taskSprite;//����״̬����
};