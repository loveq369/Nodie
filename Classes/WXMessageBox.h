#pragma once

#include "WXSimplePanel.h"


class WXMenu;
class WXSimpleButton;
 typedef void (cocos2d::CCObject:: *SEL_CallFuncDD)(void *, void*);
class WXMessageBox: public WXSimplePanel
{
public:
	WXMessageBox(void);
	virtual ~WXMessageBox(void);

	static WXMessageBox* createWithItem(cocos2d::CCNode* bg, WXSimpleButton* leftBtn, WXSimpleButton* centerBtn, WXSimpleButton* rightBtn);

	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual bool onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void onTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	virtual bool init();
	virtual bool initWithItem(cocos2d::CCNode* bg, WXSimpleButton* leftBtn, WXSimpleButton* centerBtn, WXSimpleButton* rightBtn);

	virtual void showMessageBox();//��ʾ�Ի���
	virtual void showMessageBox(const char* str);
	virtual void showMessageBox(const char* str, cocos2d::CCObject* target, SEL_CallFuncDD selector);
	virtual void showMessageBox(const char* str, cocos2d::CCObject* target, SEL_CallFuncDD selector, int type, bool isModal);

	virtual void setType(int type);//�Ի�������
	virtual void setBtnString(const char* leftStr, const char* centerStr, const char* rightStr);//���ð�ť����ʵ����
	virtual void setModal(bool isModal);//�Ƿ���ģ̬
	virtual void setString(const char* str);//������ʾ����
	virtual void setTarget(cocos2d::CCObject* target, SEL_CallFuncDD selector);//���ûص�
	virtual void setBindData(void* data, int len);//����banding����

	bool getModal(){return m_isModal;};

	CC_PROPERTY(cocos2d::CCNode*, m_bgSprite, BGSprite);//����ͼ
	CC_PROPERTY(WXSimpleButton*, m_leftBtn, LeftBtn);//��ť
	CC_PROPERTY(WXSimpleButton*, m_centerBtn, CentreBtn);//�а�ť
	CC_PROPERTY(WXSimpleButton*, m_rightBtn, RightBtn);//�Ұ�ť

	CC_SYNTHESIZE_READONLY(WXMenu*, m_btnMenu, BtnMenu);//�������а�ť
	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, m_messageLabel, MessageLabel);//��ʾ��Ϣ���״���������ʱ�Żᴴ����

	CREATE_FUNC(WXMessageBox);

private:
	void btnCallback(cocos2d::CCObject* pSender);
	void layout();//�Ű�
	void close();

private:
	int m_currentType;//
	bool m_isModal;//�Ƿ�ģ̬
	cocos2d::CCObject* m_mbtarget;//�ص�����
	SEL_CallFuncDD m_mbselector;//�ص�
	unsigned char* m_bindData;//messageBox������
};
