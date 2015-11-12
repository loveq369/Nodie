//9miao.com 首发
#pragma once

#include "EffectNode.h"

class SceneManager;
class SceneLayer: public EffectNode
{
public:
	SceneLayer();
	~SceneLayer();

	virtual bool init();
	virtual void onExit();
	cocos2d::CCSize getSize();
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸开始事件  
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸移动事件  
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸结束事件  
	void onTouchCancelle(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	CC_SYNTHESIZE(SceneManager*, sceneManager, SceneManager);
	CREATE_FUNC(SceneLayer);
};