#pragma once

#include "cocos2d.h"

class WXBaseNode: public cocos2d::CCNode
{
public:
	WXBaseNode(void);
	virtual ~WXBaseNode(void);

	//显示
	virtual void show(bool isShow);
	//是否显示(如果父节点unvisible或本身unvisible则false)
	virtual bool isShow();
	//空间所在rect
	virtual cocos2d::CCRect rect();
	//设置回调目标
	void setTarget(cocos2d::CCObject *rec, cocos2d::SEL_CallFuncO selector);

	/////////////////////////////////消息/////////////////////////////////////////
	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

protected:
	//是否有显示的parent
	bool hasVisibleParents();
	//回调
	cocos2d::CCObject *       m_pListener;
	cocos2d::SEL_CallFuncO    m_pfnSelector;
};