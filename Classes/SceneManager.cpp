#include "SceneManager.h"
#include "GameDefine.h"
#include "cocos2d.h"
#include "GameGobal.h"
#include "AnimateManager.h"
#include "TextureManager.h"
#include "UIDefine.h"
#include "DataManager.h"
#include "SceneController.h"
#include "NPCData.h"
#include "NPC.h"
#include "PlayerController.h"
#include "TargetController.h"
#include "DialogController.h"
#include "TaskController.h"
using namespace cocos2d;
SceneManager::SceneManager()
{
	_frontBGLayer=NULL;
	sceneLayer=NULL;
	m_pPlayer=NULL;
	_mouseLayer=NULL;
	_clickTarget=NULL;
	_frontBg = NULL;
	npcDic = new std::map<int64, tNpcEntity*>();
}
SceneManager::~SceneManager()
{
	_frontBGLayer=NULL;
	sceneLayer=NULL;
	_frontBg = NULL;
	removeAllEntity();
	m_pPlayer=NULL;
	_mouseLayer=NULL;
	CC_SAFE_DELETE(npcDic);
}
void SceneManager::tick(float dt)
{
	_step++;
	_totalTime+=dt;
	if (!sceneLayer)
	{
		return;
	}
	if ((_step % 10)==0)
	{
		int currNum = 0;//当前加载的个数
		int totalNum = 3;//最多加载个数
		int len = 0;
		if (!waitAddNpcList.empty())
		{
			currNum = 0;
			std::map<int64, tNpcEntity*>::iterator itr = waitAddNpcList.begin();
			while (itr!=waitAddNpcList.end() && currNum<totalNum)
			{
				addNpc(itr->second);
				waitAddNpcList.erase(itr++);
				currNum++;
			}
		}
	}
	if ((_step % 4)==0)
	{
		if (m_pPlayer)
		{
			checkElementOnMask(this->m_pPlayer);

		}
		bool intersectsRect=false;
		bool alpha=false;
		std::map<int64, tNpcEntity*>::iterator itr = npcDic->begin();
		for (;itr!=npcDic->end() && itr->second->view;itr++)
		{
			if (itr->second->view->getRect().intersectsRect(m_pPlayer->getRect()))
			{
				intersectsRect=true;
				if (m_pPlayer->getPosition().y>itr->second->view->getPosition().y)
				{
					alpha=true;
				}
			}
		}
		if (intersectsRect)
		{
			if (alpha==true&&m_pPlayer->getZOrder()>=0)
			{
				m_pPlayer->setZOrder(-1);
			}
			else if (alpha==false&&m_pPlayer->getZOrder()<=0)
			{
				m_pPlayer->setZOrder(1);
			}
		}
		else
		{
			if (m_pPlayer->getZOrder()!=0)
			{
				m_pPlayer->setZOrder(0);
			}
		}
		if (_frontBg)
		{
			_frontBg->addBackgroundBg();
		}
	}
}


void SceneManager::removeNpc(int64 id)
{
	waitAddNpcList.erase(id);
	std::map<int64, tNpcEntity*>::iterator itr = npcDic->find(id);
	if (itr!=npcDic->end())
	{
		removeElement((BaseElement*)itr->second->view);
		CC_SAFE_DELETE(itr->second);
		npcDic->erase(itr);
	}
}

void SceneManager::addToNpcQueue(NpcData* npcData)
{
	switch (npcData->flag)
	{
	case NPC_TYPE_MONSTER:
		{
			break;
		}
	default:
		{
			std::map<int64, tNpcEntity*>::iterator itr = npcDic->find(npcData->entryid);
			if (itr==npcDic->end())
			{
				tNpcEntity* ne = new tNpcEntity(npcData);
				npcDic->insert(std::map<int64, tNpcEntity*>::value_type(npcData->entryid, ne));
				waitAddNpcList[npcData->entryid] = ne;
			}
			else
			{
				if (itr->second->data)
					delete itr->second->data;
				itr->second->data = npcData;
				waitAddNpcList[npcData->entryid] = itr->second;
			}
		}
	}
}

bool SceneManager::init()
{
	
	bool ret = false;

	do 
	{
		_frontBGLayer = CCNode::create();
		_frontBGLayer->setAnchorPoint(ccp(0,1));
		sceneLayer->addChild(_frontBGLayer, scene_zorder_frontBGLayer);

		_mouseLayer = CCSprite::createWithSpriteFrameName(BLANK_SPACE_1_1);
		_mouseLayer->setVisible(false);
		sceneLayer->addChild(_mouseLayer, scene_zorder_mouseLayer);

		_elementLayer = ElementLayer::create();
		_elementLayer->setAnchorPoint(ccp(0,1));
		sceneLayer->addChild(_elementLayer, scene_zorder_elementLayer);

		_oldFocusPos = CCPoint(CCPoint::ZERO);
		WINSIZE;
		roleAOIRect = CCRectMake(0,0,winSize.width, winSize.height);
		_firstFocus = true;
		_step=0;
		_totalTime = 0;
		ret=true;
	}
	while(0);
	return ret;
}

BaseElement* SceneManager::getRandomElementByNearly( int entityType/*=2*/, int npcType/*=2*/, LivingThing* target/*=NULL*/ )
{
	int dx = 0;
	int dy = 0;
	float minDistance = 1000;//最大距离
	BaseElement* nextTarget = NULL;
	srand(time(NULL));
	int maxFindNum = int(rand()%20);//最大寻找20次

	int findNum = 0;
	if (entityType==ENTITY_TYPE_NPC)
	{

		//if (npcType==NPC_TYPE_MONSTER)
		//{
		//	std::map<int64, tMonsterEntity*>::iterator itr = monsterDic->begin();
		//	for (;itr!=monsterDic->end() && itr->second->view;itr++)
		//	{
		//		if (itr->second->data->camp==NPC_KIND_NOT_SELECT || itr->second->data->flag==NPC_KIND_NOT_SELECT)
		//		{
		//			continue;
		//		}
		//		if (itr->second->view->isInPoseState(POSE_STATE_DEAD))
		//		{
		//			continue;
		//		}
		//		if (!itr->second->view->isVisible())
		//		{
		//			continue;
		//		}
		//		dx = abs(m_pPlayer->getTileCoord().x - itr->second->data->tx);
		//		dy = abs(m_pPlayer->getTileCoord().y - itr->second->data->ty);
		//		int elementDistance = 0.8*(dx-dy)*(dx-dy) + 0.2*(dx+dy)*(dx+dy);
		//		if (elementDistance<=minDistance&&itr->second->view!=target)
		//		{
		//			//minDistance = elementDistance;
		//			nextTarget = itr->second->view;
		//			findNum++;
		//			if (findNum>=maxFindNum)
		//			{
		//				break;
		//			}
		//		}
		//	}
		//}
		//else
		{
			std::map<int64, tNpcEntity*>::iterator itr = npcDic->begin();
			for (;itr!=npcDic->end() && itr->second->view;itr++)
			{
				/*if (itr->second->data->camp==NPC_KIND_NOT_SELECT || itr->second->data->flag==NPC_KIND_NOT_SELECT)
				{
				continue;
				}*/
				if (itr->second->view->isInPoseState(POSE_STATE_DEAD))
				{
					continue;
				}
				if (!itr->second->view->isVisible())
				{
					continue;
				}
				dx = abs(m_pPlayer->getTileCoord().x - itr->second->data->tx);
				dy = abs(m_pPlayer->getTileCoord().y - itr->second->data->ty);
				int elementDistance = 0.8*(dx-dy)*(dx-dy) + 0.2*(dx+dy)*(dx+dy);
				if (elementDistance<=minDistance&&itr->second->view!=target)
				{
					//minDistance = elementDistance;
					nextTarget = itr->second->view;
					findNum++;
					if (findNum>=maxFindNum)
					{
						break;
					}
				}
			}
		}
	}
	//else if (entityType==ENTITY_TYPE_OTHER_PLAYER)
	//{
	//	std::map<int64, tOtherPlayerEntity*>::iterator itr = otherPlayerDic->begin();
	//	for (;itr!=otherPlayerDic->end() && itr->second->view;itr++)
	//	{
	//		if (itr->second->data->camp==NPC_KIND_NOT_SELECT || itr->second->data->flag==NPC_KIND_NOT_SELECT)
	//		{
	//			continue;
	//		}
	//		if (itr->second->view->isInPoseState(POSE_STATE_DEAD))
	//		{
	//			continue;
	//		}
	//		if (!itr->second->view->isVisible())
	//		{
	//			continue;
	//		}
	//		dx = abs(m_pPlayer->getTileCoord().x - itr->second->data->tx);
	//		dy = abs(m_pPlayer->getTileCoord().y - itr->second->data->ty);
	//		int elementDistance = 0.8*(dx-dy)*(dx-dy) + 0.2*(dx+dy)*(dx+dy);
	//		if (elementDistance<=minDistance&&itr->second->view!=target)
	//		{
	//			//minDistance = elementDistance;
	//			nextTarget = itr->second->view;
	//			findNum++;
	//			if (findNum>=maxFindNum)
	//			{
	//				break;
	//			}
	//		}
	//	}
	//}
	return nextTarget;
}


BaseElement* SceneManager::getElementByNearly(tPoint targetPos, int entityType, int npcType, std::map<int, bool>* targetEntryIdDic)
{
	int dx = 0;
	int dy = 0;
	int playerDx = abs(targetPos.x - m_pPlayer->getTileCoord().x);
	int playerDy = abs(targetPos.y - m_pPlayer->getTileCoord().y);
	float playerDistance = 0.8*(playerDx-playerDy)*(playerDx-playerDy) + 0.2*(playerDx+playerDy)*(playerDx+playerDy);//玩家和目标点距离
	float minDistance = 10000;//最小距离
	BaseElement* target = NULL;
	if (entityType==ENTITY_TYPE_NPC)
	{

		/*if (npcType==NPC_TYPE_MONSTER)
		{
		std::map<int64, tMonsterEntity*>::iterator itr = monsterDic->begin();
		for (;itr!=monsterDic->end() && itr->second->view;itr++)
		{
		if (itr->second->data->camp==NPC_KIND_NOT_SELECT || itr->second->data->flag==NPC_KIND_NOT_SELECT)
		{
		continue;
		}
		if (itr->second->view->isDead())
		{
		continue;
		}
		if (targetEntryIdDic && targetEntryIdDic->find(itr->second->data->entryid)==targetEntryIdDic->end())
		{
		continue;
		}
		dx = abs(targetPos.x - itr->second->data->tx);
		dy = abs(targetPos.y - itr->second->data->ty);
		int elementDistance = 0.8*(dx-dy)*(dx-dy) + 0.2*(dx+dy)*(dx+dy);
		if (elementDistance>playerDistance && elementDistance<=minDistance)
		{
		minDistance = elementDistance;
		target = itr->second->view;
		}
		}
		}*/
		//else
		{
			std::map<int64, tNpcEntity*>::iterator itr = npcDic->begin();
			for (;itr!=npcDic->end() && itr->second->view;itr++)
			{
				/*if (itr->second->data->camp==NPC_KIND_NOT_SELECT || itr->second->data->flag==NPC_KIND_NOT_SELECT)
				{
				continue;
				}*/
				if (itr->second->view->isDead())
				{
					continue;
				}
				if (targetEntryIdDic && targetEntryIdDic->find(itr->second->data->entryid)==targetEntryIdDic->end())
				{
					continue;
				}
				dx = abs(targetPos.x - itr->second->data->tx);
				dy = abs(targetPos.y - itr->second->data->ty);
				int elementDistance = 0.8*(dx-dy)*(dx-dy) + 0.2*(dx+dy)*(dx+dy);
				if (elementDistance<=minDistance)
				{
					minDistance = elementDistance;
					target = itr->second->view;
				}
			}
		}
	}
	
	return target;
}

void SceneManager::focusPosChange(const cocos2d::CCPoint& rolePos)
{
	WINSIZE;
	roleAOIRect.origin.x = rolePos.x;
	roleAOIRect.origin.y = rolePos.y-winSize.height;
	if (_firstFocus || fabs(rolePos.x-_oldFocusPos.x)>=DataManager::getInstance().getTmx2MapData()->getSliceWidth() || fabs(rolePos.y-_oldFocusPos.y)>=DataManager::getInstance().getTmx2MapData()->getSliceHeight())
	{
		CCRect rect = CCRectMake(rolePos.x,rolePos.y,winSize.width,winSize.height);
		_frontBg->load(rect);
		_oldFocusPos.x = rolePos.x;
		_oldFocusPos.y = rolePos.y;
		_firstFocus = false;
	}
}

bool SceneManager::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	if (m_pPlayer)
	{
		if (m_pPlayer->isDead())//@@temp
		{
			return true;
		}
	}
	BaseElement* _local1 = itemForTouch(pTouch);
	if (_local1)
	{
		return true;
	}
	else
	{
		_mouseLayer->setVisible(false);
		_mouseLayer->stopAllActions();
		return true;
	}
}
BaseElement* SceneManager::itemForTouch(CCTouch *touch)
{
	/*
	CCPoint location = touch->locationInView(touch->view());
	unsigned char pPixelData[4];
	glReadPixels((int)(location.x), (int)(location.y), 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &pPixelData);
	*/
	CCPoint touchLocation = sceneLayer->convertTouchToNodeSpace(touch);
	if (_elementList.size() > 0)
	{
		CCObject* pObject = NULL;
		//npc
		std::map<int64, tNpcEntity*>::iterator npcItr = npcDic->begin();
		for (;npcItr!=npcDic->end();npcItr++)
		{
			if (npcItr->second->view && npcItr->second->view->isVisible()&& npcItr->second->view->itemForTouch(touchLocation))
			{
				return npcItr->second->view;
			}
		}

	}
	return NULL;
}
void SceneManager::roleMove(tPoint end, int dt)
{
	tPoint start = m_pPlayer->getTileCoord();
	std::vector<tPoint> pathList = DataManager::getInstance().getTmx2MapData()->getPathList(start, end, dt);
	if (pathList.size()>0)
	{
		m_pPlayer->movePath(pathList);
	}
}
void SceneManager::roleMoveInScene()
{
	if (playerAutoRunData->targetId==0)
	{
		roleMove(playerAutoRunData->tp, 0);
	}
	else
	{
		LivingThing* target = getElement(playerAutoRunData->targetId);
		if (target)
		{
			clickTarget(target);
		}
		else
		{
			roleMove(playerAutoRunData->tp, 0);
		}
	}
}
void SceneManager::roleMoveCrossScene()
{
	/*if (playerAutoRunData->mapId==((PlayerData*)m_pPlayer->getLivingThingData())->mapId)
	{
	roleMoveInScene();
	}
	else
	{
	std::vector<int> pathList = DataManager::getInstance().getMapConfigManager()->getFindMapPath()->findPath(((PlayerData*)m_pPlayer->getLivingThingData())->mapId, playerAutoRunData->mapId);
	if (pathList.size()>1)
	{
	cExitConfigData* cecd = DataManager::getInstance().getMapConfigManager()->getOneMapExitData(pathList[0], pathList[1]);
	if (cecd)
	{
	tExitEntity* ee = getExitEntity(cecd->id);
	if (ee && ee->view)
	{
	clickTarget(ee->view);
	}
	else
	{
	roleMove(cecd->location, 0);
	}
	}
	}
	}*/
}
void SceneManager::roleMoveToNpc(int entryId)
{
	//NPCMonsterData* npcConfigData = DataManager::getInstance().getNpcConfigManager()->getNpcByEntryId(entryId);
	//if (npcConfigData)
	//{
	//	std::map<int, bool> targetIDDic;
	//	targetIDDic[entryId] = 1;
	//	BaseElement* target = getElementByNearly(m_pPlayer->getTileCoord(), ENTITY_TYPE_NPC, npcConfigData->flag, &targetIDDic);
	//	if (target)//附近有该单位
	//	{
	//		clickTarget(target, false);
	//	}
	//	else
	//	{
	//		roleMoveToNpc(npcConfigData);
	//	}
	//}
}
void SceneManager::roleToCollect(NPC* collect)
{
	if (PlayerController::getInstance().getPlayerAction()->getAction()!=PLAYER_ACTION_COLLECT)
	{
		return;
	}
	setClickTarget(collect);
	tPoint start = m_pPlayer->getTileCoord();
	tPoint end = collect->getTileCoord();
	int distance = PlayerController::getInstance().getPlayerAction()->getStopRange();
	int dx = abs((end.x - start.x));
	int dy = abs((end.y - start.y));
	if ((((dx > distance)) || ((dy > distance))))
	{
		roleMove(end, distance);
	}
	else
	{
		//PlayerController::getInstance().getSkillManager()->useSkill(m_pPlayer->getId(), collect->getId(), SKILL_COLLECT_ID);
		PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_NATURL);
		cancelClickTarget();
		clearPlayerAutoRunData();
	}
}
void SceneManager::roleTalkToNpc(NPC* npc)
{ 
	tPoint start,end;
	start = m_pPlayer->getTileCoord();
	if (!npc)
	{
		return;
	}
	setClickTarget(npc);
	end = npc->getTileCoord();
	int distance = PlayerController::getInstance().getPlayerAction()->getStopRange();
	int dx = abs((end.x - start.x));
	int dy = abs((end.y - start.y));
	if ((dx>distance) || (dy>distance))
	{
		roleMove(end, distance);
	}
	else
	{
		PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_NATURL);
		FunctionNPC *pFun=new FunctionNPC();
		pFun->npcEntryId=npc->getLivingThingData()->entryid;
		TaskInfo* taskInfo = TaskController::getInstance().GetTaskByNPCID(pFun->npcEntryId);
		if (!taskInfo)
		{
			if (DialogController::getInstance().getNpcDialog())//打开npc对话框
			{
				DialogController::getInstance().getNpcDialog()->setBindNPC(npc);
				DialogController::getInstance().getNpcDialog()->setDialogInfo(pFun);
			}
			return;
		}
		if (taskInfo->status!=QUEST_STATUS_INCOMPLETE)//直接打开任务面板
		{
			GameGobal::getInstance().getGameUILayer()->getTaskDialog()->setCurrentTaskInfo(taskInfo);
		}
		else
		{
			if (DialogController::getInstance().getNpcDialog())//打开npc对话框
			{
				DialogController::getInstance().getNpcDialog()->setBindNPC(npc);
				DialogController::getInstance().getNpcDialog()->setDialogInfo(pFun);
			}
		}
		/*
		if( npc!=NULL)
		{
			bool bTask =TaskController::getInstance().ResetTaskDialog(npc->getId());
			if( bTask )
			{
				GameGobal::getInstance().getGameUILayer()->getTaskDialog()->setVisible(true);
				GameGobal::getInstance().getGameUILayer()->getTaskListDlg()->setVisible(false);
			}
		}*/
		//DialogController::getInstance().reqNPCFunctionC2S(npc);
		cancelClickTarget();
		//clearPlayerAutoRunData();
	}

}
void SceneManager::rolePoseChange()
{
	if (m_pPlayer->isInPoseState(POSE_STATE_STAND))
	{
		if (checkPlayerAutoRunData())
		{
			return;
		}
		if (!_clickTarget)
		{
			return;
		}
		int action = PlayerController::getInstance().getPlayerAction()->getAction();
		switch (action)
		{
		case PLAYER_ACTION_NATURL:
			break;
		case PLAYER_ACTION_PK:
			//roleAttackMonster((Monster*)_clickTarget);
			break;
		case PLAYER_ACTION_DIALOG:
			roleTalkToNpc((NPC*)_clickTarget);
			break;
		case PLAYER_ACTION_GATE:
			//roleToExit((Exit*)_clickTarget);
			break;
		case PLAYER_ACTION_FOLLOW:
			break;
		case PLAYER_ACTION_COLLECT:
			roleToCollect((NPC*)_clickTarget);
			break;
		case PLAYER_ACTION_TRAINING:
			break;
		case PLAYER_ACTION_COLLECT_FLAG:
			break;
		case PLAYER_ACTION_HOLD_KING_SITE:
			break;
		case PLAYER_ACTION_COMPANION_SIT_ING:
			break;
		case PLAYER_ACITON_CAT_WALK:
			break;
		}
		clearPlayerAutoRunData();
	}
}

bool SceneManager::checkPlayerAutoRunData()
{
	if (!playerAutoRunData)
	{
		return false;
	}
	if (playerAutoRunData->type==autorun_type_invalid)
	{
		return false;
	}
	if (playerAutoRunData->mapId!=PlayerController::getInstance().getRoleData()->mapId)//不是同一张地图，直接寻路
	{
		roleMoveCrossScene();
		return true;
	}
	if (!_clickTarget)
	{
		std::map<int, bool>* targetEntryIdDic = NULL;
		if (playerAutoRunData->targetId>0)
		{
			targetEntryIdDic = new std::map<int, bool>();
			targetEntryIdDic->insert(std::map<int, bool>::value_type(playerAutoRunData->targetId, true));
		}
		switch (playerAutoRunData->type)
		{
		case autorun_type_npc:
			_clickTarget = getElementByNearly(playerAutoRunData->tp, ENTITY_TYPE_NPC, NPC_TYPE_FUN, targetEntryIdDic);
			break;
		case autorun_type_player:
			_clickTarget = getElementByNearly(playerAutoRunData->tp, ENTITY_TYPE_OTHER_PLAYER, NPC_TYPE_FUN, targetEntryIdDic);
			break;
		case autorun_type_exit:
			_clickTarget = getElementByNearly(playerAutoRunData->tp, ENTITY_TYPE_EXIT, NPC_TYPE_FUN, targetEntryIdDic);
			break;
		case autorun_type_monster:
			_clickTarget = getElementByNearly(playerAutoRunData->tp, ENTITY_TYPE_NPC, NPC_TYPE_MONSTER, targetEntryIdDic);
			break;
		case autorun_type_pet:
			_clickTarget = getElementByNearly(playerAutoRunData->tp, ENTITY_TYPE_PET, NPC_TYPE_FUN, targetEntryIdDic);
			break;
		case autorun_type_tile:
			{
				clearPlayerAutoRunData();
				return true;
			}
			break;
		}
		if (!_clickTarget)//没找到目标
		{
			if (playerAutoRunData->tp.distance(m_pPlayer->getTileCoord())>2)
			{
				roleMoveCrossScene();
			}
		}
		CC_SAFE_DELETE(targetEntryIdDic);
		clickTarget(_clickTarget);
		return true;
	}
	else
	{
		return false;
	}
}

void SceneManager::clearPlayerAutoRunData()
{
	playerAutoRunData->type = autorun_type_invalid;
	playerAutoRunData->tp.x = 0;
	playerAutoRunData->tp.y = 0;
	playerAutoRunData->fp.x = 0;
	playerAutoRunData->fp.y = 0;
	playerAutoRunData->mapId = 0;
	playerAutoRunData->targetId = 0;
	playerAutoRunData->flyShoesMapId = 0;
	//PlayerController::getInstance().getAutoGameManager()->clearAutoRunData();
}

void SceneManager::clickTarget(BaseElement* target, bool isTouch)
{
	if (!target)
	{
		return;
	}
	switch(target->getType())
	{
	case ENTITY_TYPE_OTHER_PLAYER:
		{
			/*int newAction = PlayerController::getInstance().getPlayerAction()->getActionBetweenPlayer(m_pPlayer, (OtherPlayer*)target);
			PlayerController::getInstance().getPlayerAction()->setAction(newAction);
			TargetController::getInstance().setTarget((LivingThing*)target);*/
			break;
		}
	case ENTITY_TYPE_NPC:
		{
			LivingThing* oldTarget = TargetController::getInstance().getTarget();
			TargetController::getInstance().setTarget((LivingThing*)target);
			switch (target->getFlag())
			{
			case NPC_TYPE_COLLECTION:
				{
					PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_COLLECT);
					roleToCollect((NPC*)target);
					break;
				}
			case NPC_TYPE_FUN:
				{
					PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_DIALOG);
					roleTalkToNpc((NPC*)target);
					break;
				}
			case NPC_TYPE_MONSTER:
				{
					/*bool canAttack = true;
					if (PlayerController::getInstance().playerOption->isAttackMonsterTwoClick)
					{
						if (oldTarget && (oldTarget==target || oldTarget->getId()==target->getId()))
						{
							canAttack = true;
						}
						else
						{
							canAttack = false;
						}
					}
					if (canAttack)
					{
						int newAction = PlayerController::getInstance().getPlayerAction()->getActionTypeByWeapon();
						PlayerController::getInstance().getPlayerAction()->setAction(newAction);
						roleAttackMonster((Monster*)target);
					}*/
					break;
				}
			case NPC_TYPE_FIGHT_COLLECTION:
				{
					/*	PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_COLLECT_FLAG);
					roleTalkToNpc((NPC*)target);*/
					break;
				}
			case NPC_TYPE_KING_SITE:
				{
					/*PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_HOLD_KING_SITE);
					roleTalkToNpc((NPC*)target);*/
					break;
				}
			default:
				{
					/*PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_DIALOG);
					roleTalkToNpc((NPC*)target);*/
					break;
				}
			}
			break;
		}
	case ENTITY_TYPE_EXIT:
		{
			/*PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_GATE);
			roleToExit((Exit*)target);*/
			break;
		}
	default:
		{
			/*PlayerController::getInstance().getPlayerAction()->setAction(PLAYER_ACTION_NATURL);*/
			break;
		}
	}
}

tNpcEntity* SceneManager::getNpcEntityByEntryId(int entryId)
{
	std::map<int64, tNpcEntity*>::iterator itr = npcDic->begin();
	for (;itr!=npcDic->end();itr++)
	{
		if (itr->second->data->entryid==entryId)
		{
			return itr->second;
		}
	}
	return NULL;

}
LivingThingData* SceneManager::getElementData(int64 id)
{
	LivingThingData* data = (LivingThingData*)(PlayerController::getInstance().getRoleData());
	if (m_pPlayer && m_pPlayer->getId()==id)
	{
		return data;
	}
	if (data->entryid == id)
	{
		return data;
	}
	std::map<int64, tNpcEntity*>::iterator itr3 = npcDic->find(id);
	if (itr3 != npcDic->end())
	{
		return (LivingThingData*)(itr3->second->data);
	}
	return NULL;
}

LivingThing* SceneManager::getElement(int64 id)
{
	if (m_pPlayer && m_pPlayer->getId()==id)
	{
		return (LivingThing*)m_pPlayer;
	}
	std::map<int64, tNpcEntity*>::iterator itr3 = npcDic->find(id);
	if (itr3 != npcDic->end())
	{
		return (LivingThing*)(itr3->second->view);
	}
	return NULL;
}

tNpcEntity* SceneManager::getNpcEntity(int64 id)
{
	std::map<int64, tNpcEntity*>::iterator itr = npcDic->find(id);
	if (itr!=npcDic->end())
	{
		return itr->second;
	}
	return NULL;
}

void SceneManager::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	if (m_pPlayer->isDead())//@@temp
	{
		return;
	}
	BaseElement* element = itemForTouch(pTouch);
	if (element)
	{
		clickTarget(element);
	}
	else
	{
		CCPoint targetPos = sceneLayer->convertTouchToNodeSpace(pTouch);
		cancelClickTarget();
		SceneController::getInstance().tileCoordForPosition(targetPos, tilePos);
		roleMoveToTile(tilePos.x, tilePos.y, 0);
		_mouseLayer->setPosition(targetPos);
		_mouseLayer->setVisible(true);
		playMouseEffect();
	}
}

void SceneManager::addNpc(tNpcEntity* npcEntity)
{
	switch (npcEntity->data->flag)
	{
	case NPC_TYPE_FUN:
	case NPC_TYPE_KING_SITE:
	case NPC_TYPE_KING_STATUS:
	case NPC_TYPE_COLLECTION:
	default:
		{
			if (!npcEntity->view)
			{
				npcEntity->view = NPC::create();
				addElement((BaseElement *)npcEntity->view);
			}
			npcEntity->data->setDataOwner((LivingThing *)npcEntity->view);
			npcEntity->view->setLivingThingData(npcEntity->data);
			npcEntity->view->addedToScene();
			//checkPlayerAutoRunData(npcEntity->view);
			break;
		}
	}
}

bool SceneManager::checkPlayerAutoRunData( NPC* target )
{
	if (m_pPlayer->isInPoseState(POSE_STATE_STAND))
	{
		if (playerAutoRunData->type==autorun_type_npc)
		{
			if (playerAutoRunData->targetId==-1)
			{
				if (playerAutoRunData->tp==target->getBornPos())
				{
					clickTarget(target);
					return true;
				}
			}
			else if (playerAutoRunData->targetId==target->getLivingThingData()->entryid)
			{
				clickTarget(target);
				return true;
			}
		}
	}
	return false;
}

void SceneManager::roleMoveToTile(int x, int y, int d)
{

	tPoint end = tPoint(x, y);
	tPoint start = m_pPlayer->getTileCoord();
	std::vector<tPoint> pathList = DataManager::getInstance().getTmx2MapData()->getPathList(start, end, d);
	if (pathList.size()>0)
	{
		end = pathList.back();
		/*playerAutoRunData->tp = end;
		playerAutoRunData->targetId = 0;
		playerAutoRunData->mapId = PlayerController::getInstance().getRoleData()->mapId;
		playerAutoRunData->flyShoesMapId = playerAutoRunData->mapId;
		playerAutoRunData->fp = end;
		playerAutoRunData->type = autorun_type_tile;*/
		m_pPlayer->movePath(pathList);
	}
}
void SceneManager::cancelClickTarget()
{
	_clickTarget = NULL;
}
void SceneManager::onTouchCancelle(Touch *pTouch,Event *pEvent)
{

}
void SceneManager::onTouchMoved(Touch *pTouch, Event *pEvent)
{

}
void SceneManager::buildScene()
{
	sceneLayer = SceneLayer::create();
	sceneLayer->setSceneManager(this);
	GameLayer * gameLayer=GameGobal::getInstance().getGameLayer();
	gameLayer->addChild(sceneLayer, 1);
	init();
	//Sprite* mapbg=Sprite::create("01.png");
	//mapbg->setPosition(0,0);
	//mapbg->setAnchorPoint(Vec2(0,0));
	//sceneLayer->addChild(mapbg);
	Tmx2MapData* mapdata= DataManager::getInstance().getTmx2MapData();
	_frontBg = BGMap::create();
	_frontBg->build(Size(mapdata->getWidth(),mapdata->getHeight()), Size(mapdata->getSliceWidth(),mapdata->getSliceHeight()), "map/1001/1001");
	_frontBGLayer->addChild(_frontBg);
	/*Sprite * animal=Sprite::create("01.png");
	animal->setPosition(SceneController::getInstance().positionForTileCoord(33,49));*/
	//animal->setAnchorPoint(Vec2(0,0));
	//TextureManager::getInstance().addImage("teleport.pvr.ccz");
	//AnimateManager::getInstance().parseXML("npc001.xml");
	//CCSequence* seq = AnimateManager::getInstance().getSequence("model/npc/001/npc001.anim", "stand4", NULL);//@@temp
	//CCRepeatForever * rep=CCRepeatForever::create(seq);
	//animal->runAction(rep);
	//sceneLayer->addChild(animal);
	addPlayer();
}
void SceneManager::startGame()
{
	if (_frontBg)
	{
		_frontBg->setTarget(NULL,NULL,NULL,NULL);
	}
}
void SceneManager::refreshPlayerBG()
{
	LoadingLayer * gameLoadingLayer = GameGobal::getInstance().getLoadingLayer();
	_frontBg->setTarget(gameLoadingLayer, callfuncI_selector(LoadingLayer::addTotalSize), callfuncI_selector(LoadingLayer::addCurreSize),\
		callfunc_selector(LoadingLayer::stopGameLoad));

	int tx = PlayerController::getInstance().getRoleData()->getTx();
	int ty = PlayerController::getInstance().getRoleData()->getTy();
	CCPoint playerPixiPos = SceneController::getInstance().positionForTileCoord(tx,ty);
	WINSIZE;
	int x = int(WX_MAX(playerPixiPos.x, winSize.width/2));
	int y = int(WX_MAX(playerPixiPos.y, winSize.height/2));
	x = int(WX_MIN(x, (DataManager::getInstance().getTmx2MapData()->getWidth() - winSize.width/2)));
	y = int(WX_MIN(y, (DataManager::getInstance().getTmx2MapData()->getHeight() - winSize.height/2)));
	CCPoint actualPosition = ccp(x,y);
	CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
	CCRect rect = CCRectMake(actualPosition.x-winSize.width/2,actualPosition.y+winSize.height/2,winSize.width,winSize.height);
	_frontBg->firstLoad(rect);
}
void SceneManager::addPlayer()
{
	m_pPlayer = Player::create();
	m_pPlayer->addedToScene();
	addElement(m_pPlayer);
	refreshPlayerBG();
}

void SceneManager::addElement(BaseElement* baseElement)
{
	_elementLayer->addChild(baseElement);
	_elementList.push_back(baseElement);
}

void SceneManager::removeElement(BaseElement* _arg1)
{
	if (_arg1)
	{
		_arg1->destoryTarget();
	}
	_elementLayer->removeChild(_arg1, true);
	std::vector<BaseElement*>::iterator itr = _elementList.begin();
	while (itr!=_elementList.end())
	{
		if ((*itr)==_arg1)
		{
			_elementList.erase(itr);
			break;
		}
		++itr;
	}
	if (_arg1==_clickTarget)
	{
		cancelClickTarget();
	}
}
void SceneManager::setClickTarget(BaseElement* baseElemet)
{
	_clickTarget = baseElemet;
}
void SceneManager::removeAllEntity()
{
	std::vector<BaseElement*> newElementList;
	_elementList.swap(newElementList);
	m_pPlayer = NULL;

	std::map<int64, tNpcEntity*>::iterator itr2 = npcDic->begin();
	while (itr2!=npcDic->end())
	{
		CC_SAFE_DELETE(itr2->second);
		++itr2;
	}
	std::map<int64, tNpcEntity*> blank2;
	npcDic->swap(blank2);
	std::map<int64, tNpcEntity*> blank22;
	waitAddNpcList.swap(blank22);

}
void SceneManager::playMouseEffect()
{
	if (_mouseLayer)
	{
		CCCallFunc* _local1 = CCCallFunc::create(this, callfunc_selector(SceneManager::mouseEffectFinish));
		const char* cstr = "model/scene/mouseClick/mouseClickEffect.anim";
		_mouseLayer->runAction(AnimateManager::getInstance().getSequence(cstr, DEFAULT_ANIMATE_NAME, _local1));
	}
}

void SceneManager::mouseEffectFinish()
{
	_mouseLayer->setVisible(false);
}

void SceneManager::checkElementOnMask(BaseElement* baseElemet)
{
	tPoint tileCoord = baseElemet->getTileCoord();
	if (DataManager::getInstance().getTmx2MapData()->nodeIsAlpha(tileCoord.x, tileCoord.y))
	{
		baseElemet->setSelfOpacity(128);
	}
	else
	{
		baseElemet->setSelfOpacity(255);
	}
}