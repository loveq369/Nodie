#pragma once

#include "WXSimplePanel.h"


	//移动类型
	typedef enum
{
	tween_type_only_start,//只从开始到结束tween
	tween_type_only_end,//只从结束到开始tween
	tween_type_both,//从开始到结束，结束到开始都tween
}TweenType;

class WXSimpleButton;
class WXPanel: public WXSimplePanel
{
public:
	WXPanel(void);
	~WXPanel(void);

	virtual void initPanel();
	//开关面板
	virtual void toggle();
	//面板移动
	virtual void tween(bool isShow=true);
	//创建一个关闭按钮
	virtual void createCloseBtn(const char* normalName, const char* selectedName);
	//关闭按钮touchBegan
	virtual bool closeBtnTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent *pEvent);
	//关闭按钮touchEnded
	virtual bool closeBtnTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent *pEvent);

	CC_SYNTHESIZE(cocos2d::CCPoint, m_startPos, StartPos);//移动开始位置
	CC_SYNTHESIZE(cocos2d::CCPoint, m_endPos, EndPos);//移动停止位置
	CC_SYNTHESIZE(float, m_tweenDuration, TweenDuration);//移动耗时
	CC_SYNTHESIZE(bool, m_canTween, CanTween);//能否移动
	CC_SYNTHESIZE(float, m_closeBtnGap, CloseBtnGap);//关闭按钮偏移
	CC_SYNTHESIZE(TweenType, m_tweenType, TweenType);//滚动方式

	CREATE_FUNC(WXPanel);

protected:
	//tween回调(start->end)
	virtual void tweenCallback();
	//tween回调(end->start)
	virtual void tweenBackCallback();
	//关闭按钮回调
	virtual void closeCallback(cocos2d::CCObject* pSender);
protected:
	cocos2d::CCAction* m_tweenAction;//移动的action
	WXSimpleButton* m_closeBtn;
	bool m_isTweenning;//是否正在移动
};
