#pragma once

#include "cocos2d.h"

class WXBaseNode: public cocos2d::CCNode
{
public:
	WXBaseNode(void);
	virtual ~WXBaseNode(void);

	//��ʾ
	virtual void show(bool isShow);
	//�Ƿ���ʾ(������ڵ�unvisible����unvisible��false)
	virtual bool isShow();
	//�ռ�����rect
	virtual cocos2d::CCRect rect();
	//���ûص�Ŀ��
	void setTarget(cocos2d::CCObject *rec, cocos2d::SEL_CallFuncO selector);

	/////////////////////////////////��Ϣ/////////////////////////////////////////
	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

protected:
	//�Ƿ�����ʾ��parent
	bool hasVisibleParents();
	//�ص�
	cocos2d::CCObject *       m_pListener;
	cocos2d::SEL_CallFuncO    m_pfnSelector;
};