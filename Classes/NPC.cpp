#include "NPC.h"
#include "GameDefine.h"
#include "SceneController.h"
#include "GameGobal.h"
#include "Frame.h"
#include "LivingThingData.h"
#include "DataManager.h"
#include "TaskController.h"
#define QUEST_STATUS_COMPLETE		1//完成（已接，但没有提交）
#define QUEST_STATUS_INCOMPLETE		2//未完成
#define QUEST_STATUS_AVAILABLE		3//可接
#define QUEST_STATUS_UNAVAILABLE	4//不可接
#define QUEST_STATUS_SUBMIT		    5//提交完成
NPC::NPC()
{
	livingThingKind = ENTITY_TYPE_NPC;
	taskSprite = NULL;
}
NPC::~NPC()
{
}
void NPC::addedToScene()
{
	LivingThing::addedToScene();
	setName(livingThingData->name.c_str());
	setDirection(livingThingData->direction);
	addNPCTitle();
	setPosition(SceneController::getInstance().positionForTileCoord(livingThingData->tx,livingThingData->ty));
	playStand();

	bornPos.x = livingThingData->tx;
	bornPos.y = livingThingData->ty;
	updateTaskStatus();
}
void NPC::addNPCTitle()
{
	std::string titleName="0";//DataManager::getInstance().getNpcConfigManager()->GetNPCHeadTitle(livingThingData->id);
	if (titleName=="0"||titleName==""||titleName=="chukou"||titleName=="tongtianta")
	{
		return;
	}
	CCSprite *npcTitle=CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s.png",titleName.c_str())->getCString());
	npcTitle->setPosition(ccp(0,30));
	CCNode *namelayer=getNameLayer();
	namelayer->addChild(npcTitle,livingthing_tile,livingthing_tile);
	namelayer->setContentSize(CCSizeMake(0,npcTitle->getContentSize().height));
}
float NPC::getMoveSpeed()
{
	return livingThingData->moveSpeed;
}
std::string NPC::getName()
{
	return livingThingData->name;
}
int NPC::getCurrentHP()
{
	return livingThingData->currentHP;
}
int NPC::getTotalHP()
{
	return livingThingData->totalHP;
}
int NPC::getCurrentMP()
{
	return livingThingData->currentMP;
}
int NPC::getTotalMP()
{
	return livingThingData->totalMP;
}
void NPC::setTileCoord(const tPoint& tp)
{
	livingThingData->tx = tp.x;
	livingThingData->ty = tp.y;
}
tPoint NPC::getTileCoord()
{
	tPoint tp;
	tp.x = livingThingData->tx;
	tp.y = livingThingData->ty;
	return tp;
}
int NPC::getType()
{
	return livingThingData->kind;
}
int NPC::getFlag()
{
	return livingThingData->flag;
}
CCSequence* NPC::getTaskStatusSequence(int status)
{
	const char* str = NULL;
	if (status==QUEST_STATUS_COMPLETE)
	{
		str = "model/scene/npcTask/finishTask.anim";
	}
	else if (status==QUEST_STATUS_AVAILABLE)
	{
		str = "model/scene/npcTask/acceptTask.anim";
	}
	if (str==NULL)
	{
		return NULL;
	}
	return AnimateManager::getInstance().getSequence(str, DEFAULT_ANIMATE_NAME, NULL);
}
void NPC::updateTaskStatus()
{
	if (livingThingData->flag==NPC_TYPE_FUN)
	{
		int status=QUEST_STATUS_AVAILABLE;
		int statusComplete=QUEST_STATUS_COMPLETE;
		if (TaskController::getInstance().checkIsTaskNpcStatue(livingThingData->entryid, status))
		{
		CCSequence* seq = getTaskStatusSequence(status);
		if (seq)
		{
		if (!taskSprite)
		{
		taskSprite = CCSprite::create();
		taskSprite->setPosition(ccp(0, getBodyHeight()+getNameLayer()->getContentSize().height+60));
		addChild(taskSprite);
		}
		taskSprite->stopAllActions();
		taskSprite->runAction(CCRepeatForever::create(seq));
		}
		}
		else if (TaskController::getInstance().checkIsTaskNpcStatue(livingThingData->entryid,statusComplete ))
		{
			CCSequence* seq = getTaskStatusSequence(statusComplete);
			if (seq)
			{
				if (!taskSprite)
				{
					taskSprite = CCSprite::create();
					taskSprite->setPosition(ccp(0, getBodyHeight()+getNameLayer()->getContentSize().height+60));
					addChild(taskSprite);
				}
				taskSprite->stopAllActions();
				taskSprite->runAction(CCRepeatForever::create(seq));
			}
		}
	}
}
void NPC::updateTaskStatus(int status)
{
	if (livingThingData->flag==NPC_TYPE_FUN)
	{
		CCSequence* seq = getTaskStatusSequence(status);
		if (seq)
		{
			if (!taskSprite)
			{
				taskSprite = CCSprite::create();
				taskSprite->setPosition(ccp(0, getBodyHeight()+getNameLayer()->getContentSize().height+60));
				addChild(taskSprite);
			}
			taskSprite->setVisible(true);
			taskSprite->stopAllActions();
			taskSprite->runAction(CCRepeatForever::create(seq));
		}
		else
		{
			if (taskSprite)
			{
				taskSprite->stopAllActions();
				taskSprite->setVisible(false);
			}
		}
	}
}

CCSequence* NPC::getSequence(int type, CCCallFunc* callFunc)
{
	CCSequence* seq = NULL;
	if (type==0)//body
	{
		char str[10];
		memset(str, 0, sizeof(str));
		sprintf(str, "%s%d", _animPrefixStr.c_str(), _direction);
		char display[_MAX_PATH_];
		memset(display, 0, sizeof(display));
		sprintf(display, "%s%d/%d.anim", MODEL_FOLDER_NPC,(int) livingThingData->entryid, livingThingData->res_bodyId);
		seq = AnimateManager::getInstance().getSequence(display, str, callFunc);
	}
	return seq;
}

void NPC::playStand()
{

	setAnimPrefix(ANIMPREFIX_STAND);
	if (oldDir!=_direction || oldPrefix!=_animPrefixStr)
	{
		animCancel();
		CCSequence* seq;
		if (bodyLayer->isVisible())
		{
			seq = getSequence();
			if (seq)
			{
				animAction = bodyLayer->runAction(CCRepeatForever::create(seq));
				bodyLayer->setPositionY(0);
				char str[10];
				memset(str, 0, sizeof(str));
				sprintf(str, "%s%d", _animPrefixStr.c_str(), _direction);
				char display[_MAX_PATH_];
				memset(display, 0, sizeof(display));
				sprintf(display, "%s%d/%d.anim", MODEL_FOLDER_NPC,(int) livingThingData->entryid, livingThingData->res_bodyId);
				bool isFlipX = false;
				CCSpriteFrame* spriteFrame = AnimateManager::getInstance().getFirstSpriteFrame(display, str,isFlipX);
				if (spriteFrame)
				{
					bodyLayer->setDisplayFrame(spriteFrame);
					bodyLayer->setFlipX(isFlipX);
					bodyLayer->setPositionY(0);
					layoutNameLayer(0,bodyLayer->getContentSize().height+10);
				}
			}
			else
			{
				CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PLACEHOLDER_IMAGE);
				if (spriteFrame)
				{
					bodyLayer->setDisplayFrame(spriteFrame);
					bodyLayer->setPositionY(bodyLayer->getContentSize().height/2);
				}
				layoutNameLayer(0, bodyLayer->getContentSize().height+10);
			}
		}
	}
	setPoseState(POSE_STATE_STAND);

	/*char display[_MAX_PATH_];
	memset(display, 0, sizeof(display));
	sprintf(display, "%s%d/%d.anim", MODEL_FOLDER_NPC, livingThingData->res_bodyId, livingThingData->res_bodyId);
	bool isFlipX = false;
	CCSpriteFrame* spriteFrame = AnimateManager::getInstance().getFirstSpriteFrame(display, DEFAULT_ANIMATE_NAME, isFlipX);
	if (spriteFrame)
	{
	bodyLayer->setDisplayFrame(spriteFrame);
	bodyLayer->setFlipX(isFlipX);
	bodyLayer->setPositionY(0);
	layoutNameLayer(0, bodyLayer->getContentSize().height+10);
	}
	else
	{
	spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PLACEHOLDER_IMAGE);
	if (spriteFrame)
	{
	bodyLayer->setDisplayFrame(spriteFrame);
	int y=bodyLayer->getContentSize().height;
	bodyLayer->setPositionY(bodyLayer->getContentSize().height/2);
	}
	layoutNameLayer(0, bodyLayer->getContentSize().height+10);
	}*/
}

void NPC::layoutNameLayer( int x, int y )
{
	nameLayer->setPosition(ccp(x, y));
}
