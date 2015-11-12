#pragma once

#include "WXBaseNode.h"


class WXSimplePanel: public WXBaseNode
{
public:
	WXSimplePanel(void);
	virtual ~WXSimplePanel(void);

	//���״���ʾ����ú���
	virtual void initPanel();
	//����Ƿ�initPanel��û�еĻ���ֱ�ӵ���
	virtual void checkInitPanel();
	//�������״̬��Ĭ�Ϲر���壩
	virtual void resetPanelState();
	//��ʾ
	virtual void show(bool isShow);
	//����
	virtual void toggle();
	//����ƶ�
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
