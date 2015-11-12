#include "GameLayer.h"

#include "GameGobal.h"
#include "SceneController.h"
#include "PlayerController.h"
#include "DataManager.h"
#include "GameUILayer.h"
USING_NS_CC;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

GameLayer::GameLayer(void)
{
	isInit = true;
	GameGobal::getInstance().setGameLayer(this);
}
GameLayer::~GameLayer(void)
{
	GameGobal::getInstance().setGameLayer(NULL);
}
CCScene* GameLayer::scene()
{
	CCScene* scene = CCScene::create();


	GameLayer* gameLayer = GameLayer::create();
	scene->addChild(gameLayer);

	return scene;
}

bool GameLayer::init()
{
	CCLayer::init();

	
	scheduleUpdate();
	setKeypadEnabled(true);//ÏìÓ¦¼üÅÌ
	return true;
}
void GameLayer::onEnter()
{
	CCLayer::onEnter();
}
void GameLayer::onExit()
{
	CCLayer::onExit();
	this->unscheduleUpdate();
	CCTextureCache::sharedTextureCache()->removeUnusedTextures();
	
}

void GameLayer::menuCloseCallback(CCObject* pSender)
{
	GameGobal::getInstance().exitEXE();
}

void GameLayer::loadGameUI()
{
	if (!GameGobal::getInstance().getGameUILayer())
	{
		GameUILayer* gameUILayer = GameUILayer::create();
		addChild(gameUILayer, 99);
	}
}

void GameLayer::startGame()
{
	unscheduleUpdate();
	scheduleUpdate();
}
void GameLayer::tick(float dt)
{
	if (isInit)
	{
		GameUILayer* gameUILayer = GameGobal::getInstance().getGameUILayer();
		if (gameUILayer && gameUILayer->initTick())
		{
			isInit = false;
		}
	}
	// 	PlayerController::getInstance().tick(dt);
	// 	GameUIController::getInstance().tick(dt);
}
void GameLayer::update(float dt)
{
	SceneController::getInstance().tick(dt);
	PlayerController::getInstance().tick(dt);
}

void GameLayer::sureQuitCallback(void* result, void* bindData)
{
	
}