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

	virtual void showMessageBox();//显示对话框
	virtual void showMessageBox(const char* str);
	virtual void showMessageBox(const char* str, cocos2d::CCObject* target, SEL_CallFuncDD selector);
	virtual void showMessageBox(const char* str, cocos2d::CCObject* target, SEL_CallFuncDD selector, int type, bool isModal);

	virtual void setType(int type);//对话框类型
	virtual void setBtnString(const char* leftStr, const char* centerStr, const char* rightStr);//设置按钮上现实的字
	virtual void setModal(bool isModal);//是否是模态
	virtual void setString(const char* str);//设置显示文字
	virtual void setTarget(cocos2d::CCObject* target, SEL_CallFuncDD selector);//设置回调
	virtual void setBindData(void* data, int len);//设置banding数据

	bool getModal(){return m_isModal;};

	CC_PROPERTY(cocos2d::CCNode*, m_bgSprite, BGSprite);//背景图
	CC_PROPERTY(WXSimpleButton*, m_leftBtn, LeftBtn);//左按钮
	CC_PROPERTY(WXSimpleButton*, m_centerBtn, CentreBtn);//中按钮
	CC_PROPERTY(WXSimpleButton*, m_rightBtn, RightBtn);//右按钮

	CC_SYNTHESIZE_READONLY(WXMenu*, m_btnMenu, BtnMenu);//挂着所有按钮
	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelTTF*, m_messageLabel, MessageLabel);//提示信息（首次设置文字时才会创建）

	CREATE_FUNC(WXMessageBox);

private:
	void btnCallback(cocos2d::CCObject* pSender);
	void layout();//排版
	void close();

private:
	int m_currentType;//
	bool m_isModal;//是否模态
	cocos2d::CCObject* m_mbtarget;//回调对象
	SEL_CallFuncDD m_mbselector;//回调
	unsigned char* m_bindData;//messageBox绑定数据
};
