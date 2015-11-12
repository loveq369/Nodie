#include "LoadingLayer.h"
#include "GameGobal.h"
#include "GameDefine.h"
#include "UIDefine.h"
#include "DataManager.h"
#include "GameLayer.h"
#include "SceneController.h"
#include "util/tools.h"
#include "NPCData.h"
LoadingLayer::LoadingLayer(void)
{
	
}
LoadingLayer::~LoadingLayer(void)
{
	GameGobal::getInstance().setLoadingLayer(NULL);
}
CCScene* LoadingLayer::scene()
{
	CCScene * scene = CCScene::create();

	LoadingLayer *layer = LoadingLayer::create();
	GameGobal::getInstance().setLoadingLayer(layer);
	scene->addChild(layer);

	return scene;
}

bool LoadingLayer::init()
{
	CCLayer::init();
	WINSIZE;

	m_pPercent = CCLabelBMFont::create("0/100", "fonts/number.fnt");
	m_pPercent->setPosition(ccp(winSize.width/2, 50));
	addChild(m_pPercent, 1);

	m_pBG = NULL;

	scheduleUpdate();
	setKeypadEnabled(true);//响应键盘

	this->resetProgress();

	return true;
}
void LoadingLayer::onEnter()
{
	CCLayer::onEnter();

	WINSIZE;

	m_pBG = CCSprite::create(LOADING_IMAGE);
	m_pBG->setPosition(ccp(winSize.width/2, winSize.height/2));
	addChild(m_pBG, 0);
	CCTextureCache::sharedTextureCache()->removeTextureForKey(LOADING_IMAGE);
	this->startLoad();
}
void LoadingLayer::stopGameLoad()
{
	GameGobal::getInstance().setCurrentSceneType(scene_type_loading_2_game);
}
void LoadingLayer::stopPreLoad()
{
	SceneController::getInstance().buildScene();
	GameGobal::getInstance().setCurrentSceneType(scene_type_loading_2_game);
}
void LoadingLayer::startLoad()
{
	if (GameGobal::getInstance().getIsFirstLoading())//加载静态数据
	{
		GameGobal::getInstance().getGameLayer()->loadGameUI();
		DataManager::getInstance().loadRes();
	}
	
}

void LoadingLayer::resetProgress()
{
	m_iCurSize = 0;
	m_iTotalSize = 0;
	m_pPercent->setString("0/100");
}
void LoadingLayer::setProgress()
{
	
	int per = m_iCurSize*100/m_iTotalSize;
	char perStr[_MAX_PATH_];
	memset(perStr, 0, sizeof(perStr));
	sprintf(perStr, "%d/100", per);
	m_pPercent->setString(perStr);
}
void LoadingLayer::addCurreSize(int curreSize)
{
	this->m_iCurSize += curreSize;
	setProgress();
}
void LoadingLayer::addTotalSize(int totalSize)
{
	this->m_iTotalSize += totalSize;
	setProgress();
}
void LoadingLayer::update(float dt)
{
	if (GameGobal::getInstance().getIsFirstLoading())//加载静态数据
	{
		if (DataManager::getInstance().loadResTick(dt))
		{
			GameGobal::getInstance().setIsFirstLoading(false);
		}
	}
	else
	{
		if (GameGobal::getInstance().getGameLayer())
		{
			GameGobal::getInstance().getGameLayer()->tick(dt);
			if (!GameGobal::getInstance().getGameLayer()->getInit())
			{
				stopPreLoad();
			}
		}
	}
	
}
