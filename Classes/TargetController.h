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

	//�����ȡһ��Ŀ��
	void randomSelectedTarget(int entityType=ENTITY_TYPE_NPC, int npcType=NPC_TYPE_MONSTER);

	LivingThing* randomSwitchTarget();//�������һ��Ŀ��

	void setTarget(LivingThing* target);//����Ŀ�꣨ѡ��Ŀ�꣩
	bool checkTarget(LivingThing* target);//���Ŀ�꣨target�Ƿ���ѡ�е�Ŀ�꣩
	void updateTarget(LivingThing* target);//����Ŀ�꣨����Ŀ����Ϣ��
	void breakFollower();//��ϸ���
	void toggleTargetHeadImage(bool isShow=true);//����Ŀ��ͷ��
	LivingThing* getTarget(){return _target;}

	void targetDead(LivingThing* target);//�е�λ������
	void targetSelected(LivingThing* target);//Ŀ�걻ѡ��
	void targetUnSelected(LivingThing* target);//Ŀ�겻��ѡ��

	CC_SYNTHESIZE(bool, isShowEffect, IsShowEffect);//Ч���Ƿ���ʾ

private:
	TargetController();
	TargetController(const TargetController&);
	TargetController& operator=(const TargetController&);
	~TargetController();

private:
	LivingThing* _target;
};