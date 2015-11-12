#pragma once

#include "cocos2d.h"

class LoadingLayer:public cocos2d::CCLayer
{
public:
	LoadingLayer(void);
	~LoadingLayer(void);

	virtual bool init();
	virtual void onEnter();
	virtual void update(float dt);
	static cocos2d::CCScene* scene();

	void addTotalSize(int totalSize);
	void addCurreSize(int curreSize);
	void stopGameLoad();
	void stopPreLoad();

	CREATE_FUNC(LoadingLayer);
private:
	void startLoad();
	void setProgress();
	void resetProgress();

private:
	cocos2d::CCLabelBMFont* m_pPercent;
	cocos2d::CCSprite* m_pBG;
	int m_iCurSize;//当前加载数目
	int m_iTotalSize;//加载上限
};