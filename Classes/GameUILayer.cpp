#include "GameUILayer.h"
#include "UIDefine.h"
#include "GameGobal.h"
#include "SceneController.h"
USING_NS_CC;

GameUILayer::GameUILayer(void)
{
	m_pCurrentTouch=NULL;
	currentHitPanel = NULL;
	GameGobal::getInstance().setGameUILayer(this);
}
GameUILayer::~GameUILayer(void)
{
	m_touches.clear();
	GameGobal::getInstance().setGameLayer(NULL);
}

bool GameUILayer::init()
{
	CCLayer::init();
	waitInitUIQueue.push(UI_ZORDER_INIT);
	waitInitUIQueue.push(UI_ZORDER_ROLE_HEAD);
	waitInitUIQueue.push(UI_ZORDER_NPC_DIALOG);
	waitInitUIQueue.push(UI_ZORDER_TASK_DIALOG);
	//初始化面板关系
	int panelIdx[] = {UI_ZORDER_ROLE,UI_ZORDER_SOCIETY,UI_ZORDER_MYTEAM,UI_ZORDER_BACKPACK,UI_ZORDER_SMALLMAP,UI_ZORDER_PET,\
		UI_ZORDER_REFINE,UI_ZORDER_GUILD,UI_ZORDER_SETTING,UI_ZORDER_AUTOGAME,UI_ZORDER_GOALS,UI_ZORDER_MOLD,UI_ZORDER_REBORN,\
		UI_ZORDER_SHOPPANEL,UI_ZORDER_MAIL_PANEL,/*UI_ZORDER_INSTANCETIP*/UI_ZORDER_TASK_PANEL,UI_ZORDER_CHAT,UI_ZORDER_SKILL,\
		UI_ZORDER_STALL_PANEL,UI_ZORDER_PRAY_PANEL,UI_ZORDER_ACTIVITY,UI_ZORDER_RANK_PANEL,UI_ZORDER_DANMEDICINE_PANEL,UI_ZORDER_BATTLE_FIELD,\
		UI_ZORDER_OFFLINE_EXP_PANEL,UI_ZORDER_TASK_DIALOG,UI_ZORDER_MOUNT};
	int counter = sizeof(panelIdx)/sizeof(panelIdx[0]);
	char relation[sizeof(panelIdx)/sizeof(panelIdx[0])][sizeof(panelIdx)/sizeof(panelIdx[0])] = {//0:自己,1:互斥,2:共存
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
	};
	for (int i=0;i<counter;i++)
	{
		std::map<int, char> relationDic;
		for (int j=0;j<counter;j++)
		{
			relationDic.insert(std::map<int,char>::value_type(panelIdx[j], relation[i][j]));
		}
		relationshipBetweenPanel.insert(std::map<int, std::map<int,char> >::value_type(panelIdx[i], relationDic));
	}
	GameGobal::getInstance().getLoadingLayer()->addTotalSize(waitInitUIQueue.size());
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); 
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	auto oneTouch = EventListenerTouchOneByOne::create();  
	oneTouch->onTouchBegan = CC_CALLBACK_2(GameUILayer::onTouchBegan,this);  
	oneTouch->onTouchMoved = CC_CALLBACK_2(GameUILayer::onTouchMoved,this);  
	oneTouch->onTouchEnded = CC_CALLBACK_2(GameUILayer::onTouchEnded,this);  
	oneTouch->onTouchCancelled = CC_CALLBACK_2(GameUILayer::onTouchCancelled,this); 
	oneTouch->setSwallowTouches(true);//不向下传递触摸
	eventDispatcher->addEventListenerWithSceneGraphPriority(oneTouch,this); 
	 
	return true;
}
bool GameUILayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	if (!m_touches.contains(pTouch))
	{
		m_touches.pushBack(pTouch);
	}
	bool bRet = false;
	if (!m_pCurrentTouch)//单点触摸
	{
		m_pCurrentTouch = pTouch;
		if (getChildren().size()>0)
		{
			_reorderChildDirty=true;
			reverseOrderAllChildren();
			auto& children = getChildren();
			for(const auto &child : children)
			{
				WXSimplePanel* pChild = dynamic_cast<WXSimplePanel*>(child);
				if (pChild && pChild->isVisible())
				{
					if (pChild->onTouchBegan(pTouch, pEvent))
					{
						currentHitPanel = pChild;
						bRet = true;
						break;
					}
				}
			}
			
			_reorderChildDirty=true;
			this->sortAllChildren();
		}
		if (!bRet)
		{
			bRet = SceneController::getInstance().getSceneManager()->getSceneLayer()->onTouchBegan(pTouch, pEvent);
		}
	}
	return bRet;
}
void GameUILayer::onTouchMoved(Touch* pTouch, Event* pEvent)  
{
	if (m_touches.contains(pTouch) && m_pCurrentTouch==pTouch)
	{
		if (currentHitPanel)
		{
			currentHitPanel->onTouchMoved(pTouch, pEvent);
		}
	}

}

void GameUILayer::showPanel(WXSimplePanel* panel, bool isShow/* =true */)
{
	if (!panel)
	{
		return;
	}
	if (isShow)
	{
		int zorder = panel->getTag();
		std::map<int, std::map<int,char> >::iterator itr = relationshipBetweenPanel.find(zorder);
		if (itr!=relationshipBetweenPanel.end())
		{
			WXSimplePanel* simplePanel = NULL;
			std::map<int,char>::iterator relationItr = itr->second.begin();
			for (;relationItr!=itr->second.end();relationItr++)
			{
				if (relationItr->second==1)//互斥
				{
					simplePanel = dynamic_cast<WXSimplePanel*>(getChildByTag(relationItr->first));
					if (simplePanel && simplePanel->isShow())
					{
						simplePanel->tween(false);
					}
				}
			}
		}
	}
	panel->tween(isShow);
}

void GameUILayer::onTouchEnded(Touch* pTouch, Event* pEvent)  
{
	if (m_touches.contains(pTouch) && m_pCurrentTouch==pTouch)
	{
		if (currentHitPanel)
		{
			currentHitPanel->onTouchEnded(pTouch, pEvent);
		}
		else
		{ 
			//todo:要做ui遍历，不能穿过ui
			SceneController::getInstance().getSceneManager()->getSceneLayer()->onTouchEnded(pTouch, pEvent);
		}

		//_moveNode->emptyMoveNode();
		currentHitPanel = NULL;

		m_pCurrentTouch = NULL;
	}
	m_touches.eraseObject(pTouch);
}

void GameUILayer::reverseOrderAllChildren()
{
	//if (_reorderChildDirty)
	//{
	//	int i,j,length = getChildren().size();;
	//	CCNode ** x = (CCNode**)getChildren().;
	//	CCNode *tempItem;

	//	// insertion sort
	//	for(i=1; i<length; i++)
	//	{
	//		tempItem = x[i];
	//		j = i-1;

	//		//continue moving element downwards while zOrder is smaller or when zOrder is the same but mutatedIndex is smaller
	//		while(j>=0 && ( tempItem->getZOrder() > x[j]->getZOrder() || ( tempItem->getZOrder()== x[j]->getZOrder() && tempItem->getOrderOfArrival() > x[j]->getOrderOfArrival() ) ) )
	//		{
	//			x[j+1] = x[j];
	//			j = j-1;
	//		}
	//		x[j+1] = tempItem;
	//	}

	//	//don't need to check children recursively, that's done in visit of each child

	//	_reorderChildDirty = false;
	//}
}

void GameUILayer::onTouchCancelle(Touch* pTouch, Event* pEvent)
{
	if (m_touches.contains(pTouch) && m_pCurrentTouch==pTouch)
	{
		m_pCurrentTouch = NULL;
		
	}
	m_touches.eraseObject(pTouch);
}

bool GameUILayer::initTick()
{
	if (waitInitUIQueue.size()==0)
	{
		GameGobal::getInstance().getLoadingLayer()->stopGameLoad();
		return true;//init结束
	}
	long startTime = TimeUtil::getInstance().getTimer();//@@temp
	WINSIZE;
	int zorder = waitInitUIQueue.front();
	switch (zorder)
	{
	case UI_ZORDER_INIT:
		{
			break;
		}
	case UI_ZORDER_ROLE_HEAD:
		{
			_roleHead = HeadImage::create();
			_roleHead->setAnchorPoint(ccp(0.0f,1.0f));
			_roleHead->setPosition(0.0f, winSize.height);
			_roleHead->toggle();
			addChild(_roleHead, UI_ZORDER_ROLE_HEAD, UI_ZORDER_ROLE_HEAD);
			break;
		}
	case UI_ZORDER_NPC_DIALOG:
		{
			_npcDialog = NpcDialog::create();
			addChild(_npcDialog, UI_ZORDER_NPC_DIALOG, UI_ZORDER_NPC_DIALOG);
			break;
		}
	case UI_ZORDER_TASK_DIALOG:  //任务对话框
		{
			_taskDialog = TaskDialog::create();
			_taskDialog->setPosition(650, 420);
			addChild(_taskDialog, UI_ZORDER_TASK_DIALOG, UI_ZORDER_TASK_DIALOG);
			_taskDialog->setVisible(false);
			break;
		}
	}
	long endTime = TimeUtil::getInstance().getTimer();//@@temp
	CCLOG("create UI(zorder:%d) consume time: %d", zorder, endTime-startTime);//@@temp

	GameGobal::getInstance().getLoadingLayer()->addCurreSize(1);
	waitInitUIQueue.pop();
	return false;
}

static int step = 0;
void GameUILayer::startGame()
{
	step = 0;
	schedule(schedule_selector(GameUILayer::startGameTick));
}

void GameUILayer::startGameTick(float dt)
{
	step++;
	switch (step)
	{
	case 5:
		{
			unschedule(schedule_selector(GameUILayer::startGameTick));
			break;	
		}
	case 10:
		{
			
			break;
		}
	case 20:
		{
			
			break;
		}
	case 30://最后要关闭tick
		{
			break;
		}
	}
}

