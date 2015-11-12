#include "SceneLayer.h"
#include "GameDefine.h"
#include "SceneManager.h"
#include "SceneController.h"
#include "DataManager.h"
USING_NS_CC;

SceneLayer::SceneLayer()
{
	sceneManager = NULL;
}
SceneLayer::~SceneLayer()
{
	if (sceneManager)
	{
		sceneManager->setSceneLayer(NULL);
	}
}
void SceneLayer::onExit()
{
	EffectNode::onExit();
	stopAllActions();
	CCDirector::sharedDirector()->purgeCachedData();
}
CCSize SceneLayer::getSize()
{
	return CCSizeMake(DataManager::getInstance().getTmx2MapData()->getWidth(), DataManager::getInstance().getTmx2MapData()->getHeight());
}
bool SceneLayer::init()
{
	bool bRet = false;
	do 
	{
		setAnchorPoint(ccp(0,1));
		bRet = true;
	} while (0);
	return bRet;
}

bool SceneLayer::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return SceneController::getInstance().getSceneManager()->onTouchBegan(pTouch, pEvent);
}
void SceneLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	SceneController::getInstance().getSceneManager()->onTouchEnded(pTouch, pEvent);
}
void SceneLayer::onTouchCancelle(Touch *pTouch, Event *pEvent)
{
	SceneController::getInstance().getSceneManager()->onTouchCancelle(pTouch, pEvent);
}
void SceneLayer::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	SceneController::getInstance().getSceneManager()->onTouchMoved(pTouch, pEvent);
}