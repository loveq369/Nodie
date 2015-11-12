#pragma once

#include "WXSimplePanel.h"


class WXCheckButton;
class WXCheckButtonPanel: public WXSimplePanel
{
public:
	WXCheckButtonPanel(void);
	virtual ~WXCheckButtonPanel(void);
	
	virtual bool init();
	virtual void layout();//排版各个按钮位置

	virtual void appendItem(WXCheckButton* button, int tag=-1);//添加一个checkBtn
	virtual void appendItem(const char* btnNormalSpriteFrameName, const char* btnSelectedSpriteFrameName, const char* btnDisabledSpriteFrameName, std::string btnStr, int tag=-1);
	virtual void selectItemByIndex(unsigned int index=0, bool isSelected=true);//选中item
	virtual void selectItemByTag(unsigned int tag, bool isSelected=true);//根据按钮tag选中一个按钮
	WXCheckButton* getItemByIndex(unsigned int index=0);//根据index获取一个按钮
	WXCheckButton* getItemByTag(unsigned int tag);//根据按钮tag获取一个按钮
	std::vector<WXCheckButton*>* getAllItem(){return m_btnList;};//获取所有按钮

	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

	CC_PROPERTY(int, m_btnTextHorizontalAlignment, BtnTextHorizontalAlignment);//设置按钮上面文字align方式
	CC_SYNTHESIZE(int, m_padding, Padding);//按钮间隔
	CC_SYNTHESIZE(int, m_alignType, AlignType);//按钮排版方式

	CREATE_FUNC(WXCheckButtonPanel);
protected:
	WXCheckButton* itemForTouch(cocos2d::Touch * touch);
	virtual void select(WXCheckButton* btn, bool isSelected);
protected:
	std::vector<WXCheckButton*>* m_btnList;
	WXCheckButton* m_currentBtn;
};