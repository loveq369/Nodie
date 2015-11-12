#pragma once

#include "WXBaseNode.h"


class WXSimplePanel: public WXBaseNode
{
public:
	WXSimplePanel(void);
	virtual ~WXSimplePanel(void);

	//在首次显示会调该函数
	virtual void initPanel();
	//检查是否initPanel，没有的话就直接调用
	virtual void checkInitPanel();
	//重设面板状态（默认关闭面板）
	virtual void resetPanelState();
	//显示
	virtual void show(bool isShow);
	//开关
	virtual void toggle();
	//面板移动
	virtual void tween(bool isShow=true);
	//
	virtual void refreshPanel(){};

	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

	CREATE_FUNC(WXSimplePanel);
protected:
	bool m_isInit;
};
