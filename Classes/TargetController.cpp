#include "TargetController.h"
#include "GameGobal.h"
#include "PlayerController.h"
#include "SceneController.h"
#include "PlayerData.h"
#include <time.h>

TargetController::TargetController()
{
	_target = NULL;
	isShowEffect = false;
}
TargetController::~TargetController()
{
	_target = NULL;
}
void TargetController::randomSelectedTarget(int entityType, int npcType)
{
	tPoint tp;
	tp.x = PlayerController::getInstance().getRoleData()->tx;
	tp.y = PlayerController::getInstance().getRoleData()->ty;
	BaseElement* element;
	LivingThing* tempTarget;
	int findTimes = 5;//最多找findTimes次
	while (1)
	{
		findTimes--;
		if (findTimes<0)
		{
			break;
		}
		element = SceneController::getInstance().getSceneManager()->getElementByNearly(tp,entityType,npcType);
		tempTarget = dynamic_cast<LivingThing*>(element);
		if (tempTarget)//找到目标
		{
			if (tempTarget!=_target)//目标不与原来目标一致
			{
				break;
			}
		}
		else//什么都找不到
		{
			break;
		}
	}
	if (tempTarget)
	{
		setTarget(tempTarget);
	}
}

LivingThing* TargetController::randomSwitchTarget()
{
	//tPoint tp;
	//if (getTarget())
	//{
	//	tp.x = getTarget()->tx;
	//	tp.y = getTarget()->ty;
	//}
	BaseElement* element;
	LivingThing* tempTarget = NULL;
	int entityType;
	int npcType;
	int kindSize = 3;//类型数量
	int findTimes = kindSize;//最多找findTimes次

	srand(time(NULL));
	int randomNum = int(rand()%kindSize);
	while (1)
	{
		findTimes--;
		if (findTimes<0)
		{
			break;
		}
		switch (randomNum)
		{
		case 0://普通NPC
			{
				entityType = ENTITY_TYPE_NPC;
				npcType = NPC_TYPE_FUN;
				break;
			}
		case 1://怪物
			{
				entityType = ENTITY_TYPE_NPC;
				npcType = NPC_TYPE_MONSTER;
				break;
			}
		case 2://其它玩家
			{
				entityType = ENTITY_TYPE_OTHER_PLAYER;
				npcType = NPC_TYPE_MONSTER;
				break;
			}
		}
		randomNum = ++randomNum%kindSize;
		element = SceneController::getInstance().getSceneManager()->getRandomElementByNearly(entityType,npcType,getTarget());
		tempTarget = dynamic_cast<LivingThing*>(element);
		if (tempTarget)//找到目标
		{
			if (tempTarget!=_target)//目标不与原来目标一致
			{
				break;
			}
		}
		//else//什么都找不到
		//{
		//	break;
		//}
	}
	if (tempTarget)
	{
		setTarget(tempTarget);
	}
	return tempTarget;
}

void TargetController::toggleTargetHeadImage(bool isShow/* =true */)
{
	if (isShow)
	{
		//GameGobal::getInstance().getGameUILayer()->getMonsterHeadImage()->show(true);
		//GameGobal::getInstance().getGameUILayer()->getMonsterHeadImage()->setTarget(_target);
		isShowEffect = true;
	}
	else
	{
		if (GameGobal::getInstance().getGameUILayer())
		{
			//GameGobal::getInstance().getGameUILayer()->getMonsterHeadImage()->show(false);
			//GameGobal::getInstance().getGameUILayer()->getMonsterHeadImage()->setTarget(NULL);
		}
		isShowEffect = false;
	}
}
void TargetController::setTarget(LivingThing* target)
{
	if (_target==target)
	{
		return;
	}
	targetUnSelected(_target);
	_target = target;
	breakFollower();
	if (target == NULL)
	{
		toggleTargetHeadImage(false);
	}
	else
	{
		toggleTargetHeadImage(true);
		targetSelected(_target);
	}
}
void TargetController::breakFollower()
{
	if (_target)
	{
		//_target->removeFollower((LivingThing*)PlayerController::getInstance().getRole());
	}
}
void TargetController::targetSelected(LivingThing* tar)
{
	if (!tar)
	{
		return;
	}
	const char* effectName = NULL;
	switch(tar->getType())
	{
	case ENTITY_TYPE_OTHER_PLAYER:
		effectName = CONST_EFFECT_SELECT_YELLOW;
		break;
	case ENTITY_TYPE_NPC:
		{
			tar->showName(true);
			switch (tar->getFlag())
			{
			case NPC_TYPE_MONSTER:
				effectName = CONST_EFFECT_SELECT_YELLOW;
				break;
			default:
				effectName = CONST_EFFECT_SELECT_YELLOW;
				break;
			}
			break;
		}
	default:
		effectName = CONST_EFFECT_SELECT_YELLOW;
		break;
	}
	EffectInfo ei;
	ei.m_part = EFFECT_PART_BUTTOM;
	ei.m_effectParent = tar;
	ei.m_type = EFFECT_TYPE_TARGET;
	ei.m_zorder = livingthing_zorder_shadow;
	EffectManager::getInstance().addEffect(effectName, ei);
}
void TargetController::targetUnSelected(LivingThing* tar)
{
	if (!tar)
	{
		return;
	}
	const char* effectName = NULL;
	switch(tar->getType())
	{
	case ENTITY_TYPE_OTHER_PLAYER:
		effectName = CONST_EFFECT_SELECT_YELLOW;
		break;
	case ENTITY_TYPE_NPC:
		{
			switch (tar->getFlag())
			{
			case NPC_TYPE_MONSTER:
				{
					tar->showName(false);
					effectName = CONST_EFFECT_SELECT_YELLOW;
				}
				break;
			default:
				effectName = CONST_EFFECT_SELECT_YELLOW;
				break;
			}
			break;
		}
	default:
		effectName = CONST_EFFECT_SELECT_YELLOW;
		break;
	}
	EffectManager::getInstance().removeEffect(tar, effectName);
}
bool TargetController::checkTarget(LivingThing* target)
{
	if (target==_target)
	{
		return true;
	}
	return false;
}
void TargetController::updateTarget(LivingThing* target)
{
	if (target==_target)
	{
		//GameGobal::getInstance().getGameUILayer()->getMonsterHeadImage()->refreshPanel();
	}
}
void TargetController::targetDead(LivingThing* target)
{
	if (target==_target)
	{
		//GameGobal::getInstance().getGameUILayer()->getMonsterHeadImage()->setHP(0, 1);
	}
}
