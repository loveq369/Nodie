#pragma once

#include "WXSimplePanel.h"


class WXCheckButton;
class WXCheckButtonPanel: public WXSimplePanel
{
public:
	WXCheckButtonPanel(void);
	virtual ~WXCheckButtonPanel(void);
	
	virtual bool init();
	virtual void layout();//�Ű������ťλ��

	virtual void appendItem(WXCheckButton* button, int tag=-1);//���һ��checkBtn
	virtual void appendItem(const char* btnNormalSpriteFrameName, const char* btnSelectedSpriteFrameName, const char* btnDisabledSpriteFrameName, std::string btnStr, int tag=-1);
	virtual void selectItemByIndex(unsigned int index=0, bool isSelected=true);//ѡ��item
	virtual void selectItemByTag(unsigned int tag, bool isSelected=true);//���ݰ�ťtagѡ��һ����ť
	WXCheckButton* getItemByIndex(unsigned int index=0);//����index��ȡһ����ť
	WXCheckButton* getItemByTag(unsigned int tag);//���ݰ�ťtag��ȡһ����ť
	std::vector<WXCheckButton*>* getAllItem(){return m_btnList;};//��ȡ���а�ť

	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

	CC_PROPERTY(int, m_btnTextHorizontalAlignment, BtnTextHorizontalAlignment);//���ð�ť��������align��ʽ
	CC_SYNTHESIZE(int, m_padding, Padding);//��ť���
	CC_SYNTHESIZE(int, m_alignType, AlignType);//��ť�Ű淽ʽ

	CREATE_FUNC(WXCheckButtonPanel);
protected:
	WXCheckButton* itemForTouch(cocos2d::Touch * touch);
	virtual void select(WXCheckButton* btn, bool isSelected);
protected:
	std::vector<WXCheckButton*>* m_btnList;
	WXCheckButton* m_currentBtn;
};