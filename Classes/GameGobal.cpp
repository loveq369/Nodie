#include "GameGobal.h"
#include "cocos2d.h"
using namespace cocos2d;
GameGobal::GameGobal()
{

	isFirstLoading = true;
	isFirstEnter = true;
	gameScene = NULL;
	m_bIsGameSceneRetain = false;
	m_pCurrentScene = NULL;
	_gameLayer=NULL;
	_loadingLayer=NULL;
	_gameUILayer=NULL;
}
GameGobal::~GameGobal()
{

	releaseGameScene();
}
void GameGobal::retainGameScene()
{
	if (gameScene)
	{
		if (!m_bIsGameSceneRetain)
		{
			m_bIsGameSceneRetain = true;
			gameScene->retain();
		}
	}
}
void GameGobal::releaseGameScene()
{
	if (gameScene)
	{
		if (m_bIsGameSceneRetain)
		{
			m_bIsGameSceneRetain = false;
			gameScene->release();
		}
	}
}
int GameGobal::getCurrentSceneType()
{
	return currentSceneType;
}
void GameGobal::setCurrentSceneType(int var)
{
	if (currentSceneType!=var)
	{
		currentSceneType = var;
		switch (var)
		{
		case scene_type_run_loading:
			{
				CCScene *pScene = LoadingLayer::scene();
				m_pCurrentScene = pScene;
				CCDirector::sharedDirector()->runWithScene(pScene);
				if (!gameScene)
				{
					CCScene* gameScene = GameLayer::scene();
					setGameScene(gameScene);
				}
				retainGameScene();
				break;
			}
		case scene_type_run_download:
			{
				
				break;
			}
		case scene_type_loading_2_login:
		case scene_type_game_2_login:
			{
				
				break;
			}
		case scene_type_download_2_loading:
			{
				
				break;
			}
		case scene_type_game_2_loading:
		case scene_type_login_2_loading:
			{
				
				break;
			}
		case scene_type_loading_2_game:
			{
				m_pCurrentScene = gameScene;
				CCDirector::sharedDirector()->replaceScene(gameScene);
				releaseGameScene();
				break;
			}
		}
	}
}
void GameGobal::exitEXE()
{
	releaseGameScene();
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
