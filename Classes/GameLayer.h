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

	//������������ɣ���ʼ��Ϸ
	void startGame();
	//����ui
	void loadGameUI();
	//δ������Ϸ����ǰ��tick��Ŀǰ��������ui
	void tick(float dt);

	BOOL getInit() {return isInit;}
	CREATE_FUNC(GameLayer);

private:
	void sureQuitCallback(void* result, void* bindData);
private:
	bool isInit;//�Ƿ��ʼ��
};