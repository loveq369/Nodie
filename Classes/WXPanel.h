#pragma once

#include "WXSimplePanel.h"


	//�ƶ�����
	typedef enum
{
	tween_type_only_start,//ֻ�ӿ�ʼ������tween
	tween_type_only_end,//ֻ�ӽ�������ʼtween
	tween_type_both,//�ӿ�ʼ����������������ʼ��tween
}TweenType;

class WXSimpleButton;
class WXPanel: public WXSimplePanel
{
public:
	WXPanel(void);
	~WXPanel(void);

	virtual void initPanel();
	//�������
	virtual void toggle();
	//����ƶ�
	virtual void tween(bool isShow=true);
	//����һ���رհ�ť
	virtual void createCloseBtn(const char* normalName, const char* selectedName);
	//�رհ�ťtouchBegan
	virtual bool closeBtnTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent *pEvent);
	//�رհ�ťtouchEnded
	virtual bool closeBtnTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent *pEvent);

	CC_SYNTHESIZE(cocos2d::CCPoint, m_startPos, StartPos);//�ƶ���ʼλ��
	CC_SYNTHESIZE(cocos2d::CCPoint, m_endPos, EndPos);//�ƶ�ֹͣλ��
	CC_SYNTHESIZE(float, m_tweenDuration, TweenDuration);//�ƶ���ʱ
	CC_SYNTHESIZE(bool, m_canTween, CanTween);//�ܷ��ƶ�
	CC_SYNTHESIZE(float, m_closeBtnGap, CloseBtnGap);//�رհ�ťƫ��
	CC_SYNTHESIZE(TweenType, m_tweenType, TweenType);//������ʽ

	CREATE_FUNC(WXPanel);

protected:
	//tween�ص�(start->end)
	virtual void tweenCallback();
	//tween�ص�(end->start)
	virtual void tweenBackCallback();
	//�رհ�ť�ص�
	virtual void closeCallback(cocos2d::CCObject* pSender);
protected:
	cocos2d::CCAction* m_tweenAction;//�ƶ���action
	WXSimpleButton* m_closeBtn;
	bool m_isTweenning;//�Ƿ������ƶ�
};
