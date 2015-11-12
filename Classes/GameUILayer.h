#pragma once

#include "cocos2d.h"
#include "HeadImage.h"
#include "NpcDialog.h"
#include "TaskDialog.h"
class GameUILayer:public cocos2d::CCLayer
{
public:
	GameUILayer(void);
	~GameUILayer(void);

	virtual bool init();
	//开始游戏的tick
	void startGameTick(float dt);
	bool initTick();
	//进度条加载完成，开始游戏
	void startGame();
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸开始事件  
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸移动事件  
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸结束事件  
	void onTouchCancelle(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void reverseOrderAllChildren();
	void showPanel(WXSimplePanel* panel, bool isShow=true);//某个面板显示或关闭了
	CREATE_FUNC(GameUILayer);
	CC_SYNTHESIZE_READONLY(HeadImage*, _roleHead, RoleHeadImage);
	/*CC_SYNTHESIZE_READONLY(MyTeamPanel*, myTeamPanel, MyTeamPanel);*/
	CC_SYNTHESIZE_READONLY(WXSimplePanel*, currentHitPanel, CurrentHitPanel);//当前点中面板
	CC_SYNTHESIZE_READONLY(NpcDialog*, _npcDialog, NpcDialog);
	CC_SYNTHESIZE_READONLY(TaskDialog*, _taskDialog, TaskDialog);
private:
	cocos2d::Vector<cocos2d::Touch*> m_touches;//点击事件
	cocos2d::CCTouch* m_pCurrentTouch;//当前点击
	std::queue<int> waitInitUIQueue;
	std::map<int, std::map<int, char> > relationshipBetweenPanel;//面板关系
};