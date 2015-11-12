//9miao.com 首发
#pragma once

#include "SceneLayer.h"
#include "GameLayer.h"
#include "GameUILayer.h"
#include "LoadingLayer.h"
typedef enum
{
	scene_type_start = 1,

	scene_type_run_loading,//运行加载
	scene_type_run_download,//运行下载场景
	scene_type_download_2_loading,//下载场景2加载场景
	scene_type_login_2_loading,//登陆场景2加载场景
	scene_type_loading_2_login,//加载场景2登陆场景
	scene_type_loading_2_game,//加载场景2游戏场景
	scene_type_game_2_loading,//游戏场景2加载场景
	scene_type_game_2_login,//游戏场景2登陆场景

	scene_type_end
} SceneType;

class GameGobal: public cocos2d::CCObject
{
public:
	static GameGobal& getInstance()
	{
		static GameGobal instance;
		return instance;
	}

	//retain游戏场景
	void retainGameScene();
	//release游戏场景
	void releaseGameScene();
	//终止游戏，退出exe
	void exitEXE();

	CC_SYNTHESIZE(cocos2d::CCScene*, gameScene, GameScene);//游戏scene



	CC_SYNTHESIZE(bool, isFirstLoading, IsFirstLoading); //是否是首次加载
	CC_SYNTHESIZE(bool, isFirstEnter, IsFirstEnter); //是否是首次进入场景
	CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);//游戏主场景层
	CC_SYNTHESIZE(GameUILayer*, _gameUILayer, GameUILayer);//游戏界面层
	CC_SYNTHESIZE(LoadingLayer*, _loadingLayer, LoadingLayer);//游戏加载层
	CC_PROPERTY(int, currentSceneType, CurrentSceneType); //当前运行场景类型
	CC_SYNTHESIZE_READONLY(cocos2d::CCScene*, m_pCurrentScene, CurrentScene); //当前运行场景

public:
	
private:
	GameGobal();
	GameGobal(const GameGobal&);
	GameGobal& operator=(const GameGobal&);
	~GameGobal();
private:
	//游戏场景是否retain
	bool m_bIsGameSceneRetain;
};