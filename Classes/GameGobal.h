//9miao.com �׷�
#pragma once

#include "SceneLayer.h"
#include "GameLayer.h"
#include "GameUILayer.h"
#include "LoadingLayer.h"
typedef enum
{
	scene_type_start = 1,

	scene_type_run_loading,//���м���
	scene_type_run_download,//�������س���
	scene_type_download_2_loading,//���س���2���س���
	scene_type_login_2_loading,//��½����2���س���
	scene_type_loading_2_login,//���س���2��½����
	scene_type_loading_2_game,//���س���2��Ϸ����
	scene_type_game_2_loading,//��Ϸ����2���س���
	scene_type_game_2_login,//��Ϸ����2��½����

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

	//retain��Ϸ����
	void retainGameScene();
	//release��Ϸ����
	void releaseGameScene();
	//��ֹ��Ϸ���˳�exe
	void exitEXE();

	CC_SYNTHESIZE(cocos2d::CCScene*, gameScene, GameScene);//��Ϸscene



	CC_SYNTHESIZE(bool, isFirstLoading, IsFirstLoading); //�Ƿ����״μ���
	CC_SYNTHESIZE(bool, isFirstEnter, IsFirstEnter); //�Ƿ����״ν��볡��
	CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);//��Ϸ��������
	CC_SYNTHESIZE(GameUILayer*, _gameUILayer, GameUILayer);//��Ϸ�����
	CC_SYNTHESIZE(LoadingLayer*, _loadingLayer, LoadingLayer);//��Ϸ���ز�
	CC_PROPERTY(int, currentSceneType, CurrentSceneType); //��ǰ���г�������
	CC_SYNTHESIZE_READONLY(cocos2d::CCScene*, m_pCurrentScene, CurrentScene); //��ǰ���г���

public:
	
private:
	GameGobal();
	GameGobal(const GameGobal&);
	GameGobal& operator=(const GameGobal&);
	~GameGobal();
private:
	//��Ϸ�����Ƿ�retain
	bool m_bIsGameSceneRetain;
};