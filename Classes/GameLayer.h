#pragma once

#include "cocos2d.h"
class GameLayer:public cocos2d::CCLayer
{
public:
	GameLayer(void);
	~GameLayer(void);

	virtual bool init();
	static cocos2d::CCScene* scene();
	virtual void onExit();
	virtual void onEnter();
	virtual void update(float dt);


	virtual void menuCloseCallback(cocos2d::CCObject* pSender);

	//进度条加载完成，开始游戏
	void startGame();
	//加载ui
	void loadGameUI();
	//未进入游戏场景前的tick，目前用来加载ui
	void tick(float dt);

	BOOL getInit() {return isInit;}
	CREATE_FUNC(GameLayer);

private:
	void sureQuitCallback(void* result, void* bindData);
private:
	bool isInit;//是否初始化
};