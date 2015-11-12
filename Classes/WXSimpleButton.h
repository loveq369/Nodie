#pragma once

#include "WXBaseNode.h"
#include "WXUIProtocol.h"

	static std::string g_defaultBtnStringTnf = "";//按钮上文字对应的tnf
static int g_defaultBtnFontType = 1;//1:CCLabelTTF, 2:CCLabelBMFont

class WXSimpleButton: public WXBaseNode, public WXResponseProtocol
{
public:
	WXSimpleButton(void);
	~WXSimpleButton(void);

	static void setDefaultBtnStringTnf(std::string var);//设置字体文件（当选用CCLabelBMFont时有用）
	static void setDefaultBtnFontType(int var);//设置字体类型

	//根据noramlNode\selectedNode\disabledNode创建一个checkBtn
	static WXSimpleButton* createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, const char* btnStr="");
	static WXSimpleButton* createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector, const char* btnStr="");

	static WXSimpleButton* create(const char *normalImage, const char *selectedImage, cocos2d::CCObject* target=NULL, cocos2d::SEL_MenuHandler selector=NULL);
	static WXSimpleButton* create(const char *normalImage, const char *selectedImage, const char *disabledImage, cocos2d::CCObject* target=NULL, cocos2d::SEL_MenuHandler selector=NULL);

	static WXSimpleButton* createWithSpriteFrame(cocos2d::CCSpriteFrame *normalSpriteFrame, cocos2d::CCSpriteFrame *selectedSpriteFrame, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
	static WXSimpleButton* createWithSpriteFrameName(const char *normalName, const char *selectedName, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);
	static WXSimpleButton* createWithSpriteFrameName(const char *normalName, const char *selectedName, const char *disabledName,cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);

	bool initWithNode(cocos2d::CCNode* normalNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector, const char* btnStr="");

	/////////////////////////////////字/////////////////////////////////////////
	void setString(const char* str);//设置按钮上的字
	void setFontColor(const cocos2d::ccColor3B& color);//设置字体颜色
	void setFontSize(float fontSize);//设置字体
	void setFontName(const char *fontName);//设置字体大小
	const char* getString();//获取按钮上的字

	/////////////////////////////////响应/////////////////////////////////////////
	virtual void activate();
	virtual void selected(bool var);
	virtual bool isEnabled();
	virtual void setEnabled(bool value);
	virtual bool isSelected();

	////////////////////////////////////消息//////////////////////////////////////
	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	//是否点中
	virtual bool onTouch(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

	CC_PROPERTY(cocos2d::CCNode*, m_pNormalImage, NormalImage);
	CC_PROPERTY(cocos2d::CCNode*, m_pSelectedImage, SelectedImage);
	CC_PROPERTY(cocos2d::CCNode*, m_pDisabledImage, DisabledImage);

	//显示文字
	CC_SYNTHESIZE_READONLY(cocos2d::CCNode*, m_label, Label);
protected:
	virtual void updateImagesVisibility();
protected:
	bool m_bSelected;
	bool m_bEnabled;
};

