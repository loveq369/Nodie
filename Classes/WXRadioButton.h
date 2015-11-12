#pragma once

#include "WXCheckButton.h"


class WXRadioButton: public WXCheckButton
{
public:
	static WXRadioButton* createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");
	static WXRadioButton* createWithSpriteFrame(cocos2d::CCSpriteFrame *normalSpriteFrame, cocos2d::CCSpriteFrame *selectedSpriteFrame, cocos2d::CCSpriteFrame* disabledSpriteFrame=NULL, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");
	static WXRadioButton* createWithSpriteFrameName(const char *normalName, const char *selectedName, const char *disabledName=NULL, cocos2d::CCObject* target=NULL, cocos2d::SEL_CallFuncO selector=NULL, const char* str="");

	virtual bool ccTouchEnded(cocos2d::CCTouch*pTouch, cocos2d::CCEvent*pEvent);
};
