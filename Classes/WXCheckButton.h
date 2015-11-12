#pragma once

#include "WXSimpleButton.h"

static std::string g_defaultCheckBtnStringTnf = "";//check��ť�����ֶ�Ӧ��tnf
static int g_defaultCheckBtnFontType = 1;//1:CCLabelTTF, 2:CCLabelBMFont


class WXCheckButton: public WXSimpleButton
{
public:
	WXCheckButton(void);
	virtual ~WXCheckButton(void);

	static void setDefaultCheckBtnStringTnf(std::string var);//���������ļ�����ѡ��CCLabelBMFontʱ���ã�
	static void setDefaultCheckBtnFontType(int var);//������������

	//����noramlNode\selectedNode\disabledNode����һ��checkBtn
	static WXCheckButton* createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");
	static WXCheckButton* createWithSpriteFrame(cocos2d::CCSpriteFrame *normalSpriteFrame, cocos2d::CCSpriteFrame *selectedSpriteFrame, cocos2d::CCSpriteFrame* disabledSpriteFrame=NULL, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");
	static WXCheckButton* createWithSpriteFrameName(const char *normalName, const char *selectedName, const char *disabledName=NULL, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");

	virtual bool initWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");
	
	////////////////////////////////////��Ϣ//////////////////////////////////////
	virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent);
	virtual void onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);
	virtual bool onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent); 
	virtual void onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent);

	//�Ű�
	virtual void layout();

	CC_PROPERTY(float, m_padding, Padding);//ͼƬ�����ֵļ�϶
	CC_PROPERTY(int, m_textHorizontalAlignment, TextHorizontalAlignment);//���������ͼƬ��ˮƽ��λ
	CC_PROPERTY(cocos2d::ccColor3B, m_selectedTextColor, SelectedTextColor);//����ѡ����ɫ
	CC_PROPERTY(cocos2d::ccColor3B, m_normalTextColor, NormalTextColor);//���ֲ�ѡ����ɫ
protected:
	virtual void setNormalImage(cocos2d::CCNode* var);
	virtual void setSelectedImage(cocos2d::CCNode* var);
	virtual void setDisabledImage(cocos2d::CCNode* var);
	virtual void updateImagesVisibility();
};
