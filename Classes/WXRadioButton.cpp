#include "WXRadioButton.h"
USING_NS_CC;


WXRadioButton* WXRadioButton::createWithSpriteFrame(CCSpriteFrame *normalSpriteFrame, CCSpriteFrame *selectedSpriteFrame, CCSpriteFrame* disabledSpriteFrame, CCObject* target, SEL_CallFuncO selector, const char* str)
{
	WXRadioButton* pRet = new WXRadioButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrame(normalSpriteFrame);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrame(selectedSpriteFrame);
		CCSprite* disabledSprite = NULL;
		if (disabledSpriteFrame)
			disabledSprite = CCSprite::createWithSpriteFrame(disabledSpriteFrame);
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector, str))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXRadioButton* WXRadioButton::createWithSpriteFrameName(const char *normalName, const char *selectedName, const char* disabledName, CCObject* target, SEL_CallFuncO selector, const char* str)
{
	WXRadioButton *pRet = new WXRadioButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrameName(normalName);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrameName(selectedName);
		CCSprite* disabledSprite = NULL;
		if (disabledName)
			disabledSprite = CCSprite::createWithSpriteFrameName(disabledName);
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector, str))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXRadioButton* WXRadioButton::createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target/* =NULL */, cocos2d::SEL_CallFuncO selector/* =NULL */, const char* str/* = */)
{
	WXRadioButton* pRet = new WXRadioButton();
	if (pRet)
	{
		if (pRet->initWithNode(noramlNode, selectedNode, disabledNode, target, selector, str))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool WXRadioButton::ccTouchEnded(CCTouch*pTouch, CCEvent*pEvent)
{
	if (m_bEnabled && isShow())
	{
		if (onTouch(pTouch, pEvent))
		{
			m_bSelected = !m_bSelected;
			if (m_bSelected)
			{
				selected(true);
				activate();
			}
			else
			{
				selected(false);
			}
			return true;
		}
	}
	return false;
}
