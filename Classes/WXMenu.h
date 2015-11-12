#pragma once

#include "WXBaseNode.h"


class WXSimpleButton;
class WXMenu : public WXBaseNode
{
	bool m_bEnabled;
public:
	WXMenu() : m_pSelectedItem(NULL){}
	virtual ~WXMenu(){}

	static WXMenu* create();
	static WXMenu* create(WXSimpleButton* item, ...);
	static WXMenu* createWithItem(WXSimpleButton* item);
	static WXMenu* createWithArray(cocos2d::CCArray* pArrayOfItems);
	static WXMenu* createWithItems(WXSimpleButton *firstItem, va_list args);

	bool init();
	bool initWithArray(cocos2d::CCArray* pArrayOfItems);

	void alignItemsVertically();
	void alignItemsVerticallyWithPadding(float padding);
	void alignItemsHorizontally();
	void alignItemsHorizontallyWithPadding(float padding);

	virtual void addChild(cocos2d::CCNode * child);
	virtual void addChild(cocos2d::CCNode * child, int zOrder);
	virtual void addChild(cocos2d::CCNode * child, int zOrder, int tag);
	virtual void removeChild(cocos2d::CCNode* child, bool cleanup);

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	virtual void onExit();

	virtual void setOpacityModifyRGB(bool bValue) {CC_UNUSED_PARAM(bValue);}
	virtual bool isOpacityModifyRGB(void) { return false;}

	virtual bool isEnabled() { return m_bEnabled; }
	virtual void setEnabled(bool value) { m_bEnabled = value; };

	CC_SYNTHESIZE(int, m_horizontallyAlignType, HorizontallyAlignType);//水平排版时align方式（居中、居左、居右）

protected:
	WXSimpleButton* itemForTouch(cocos2d::CCTouch * touch);
protected:
	WXSimpleButton *m_pSelectedItem;
};
