//9miao.com �׷�
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
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //������ʼ�¼�  
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //�����ƶ��¼�  
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //���������¼�  
	void onTouchCancelle(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	CC_SYNTHESIZE(SceneManager*, sceneManager, SceneManager);
	CREATE_FUNC(SceneLayer);
};