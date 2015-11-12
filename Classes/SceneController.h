#pragma once

#include "SceneManager.h"

class SceneController: public cocos2d::CCObject
{
public:
	static SceneController& getInstance()
	{
		static SceneController instance;
		return instance;
	}
	//加载完成
	void startGame();
	//构建场景
	void buildScene();
	//定时器
	void tick(float dt);
	//游戏场景管理
	CC_SYNTHESIZE(SceneManager*, sceneManager, SceneManager);
	//像素坐标->地砖坐标
	tPoint tileCoordForPosition(int x, int y);
	//地砖坐标->像素坐标
	cocos2d::CCPoint positionForTileCoord(int x, int y);
	//像素坐标->地砖坐标
	void tileCoordForPosition(const cocos2d::CCPoint& pixelPos, tPoint& tilePos);
	//地砖坐标->像素坐标
	void positionForTileCoord(const tPoint& tilePos, cocos2d::CCPoint& pixelPos);


	//清除玩家位置/focus位置等初始化信息
	void clean();
private:
	cocos2d::CCPoint _rolePos;
	cocos2d::CCPoint _focusPos;
	cocos2d::CCRect roleAOIRect;
	SceneController();
	SceneController(const SceneController&);
	SceneController& operator=(const SceneController&);
	~SceneController();
	void setRolePos(const cocos2d::CCPoint& rolePos);
};