#pragma once
#include "WXUIDefine.h"
#include "cocos-ext.h"
USING_NS_CC_EXT; 
typedef void (cocos2d::CCObject::*SEL_CallFuncI)(int);

class WXTableView: public TableView
{
public:
	WXTableView();
	bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	static WXTableView* create(cocos2d::extension::TableViewDataSource* dataSource, cocos2d::CCSize size);
	static WXTableView* create(cocos2d::extension::TableViewDataSource* dataSource, cocos2d::CCSize size, cocos2d::CCNode *container);

	void setVerticalFillOrder(cocos2d::extension::TableView::VerticalFillOrder fillOrder);
	//void setVerticalFillOrder(cocos2d::extension::TableViewVerticalFillOrder fillOrder);
	void reloadData();
	//定位到指定cell，idx：指定的idx，delta：指定的idx偏移量
	void navigateCellByIdx(unsigned int idx, cocos2d::CCPoint delta=cocos2d::CCPointZero, bool animated=false);
	//设置翻页后的回调
	void setNextPageTarget(cocos2d::CCObject* target, SEL_CallFuncI selector);
	//获取当前页
	int getCurrentPage();

	CC_SYNTHESIZE(float, m_fMoveDelta, MoveDelta);//移动有效间距（像素）达到该像素才算移动

	CC_SYNTHESIZE(bool, m_bIsNextPage, IsNextPage);//是否是翻页
	CC_SYNTHESIZE(float, m_fNextPageMinScrollDistance, NextPageMinScrollDistance);//最后一帧滚动距离超过该距离才翻页（像素）
	CC_SYNTHESIZE(float, m_fNextPageSpeed, NextPageSpeed);//翻页时的scroll速度
private:
	void checkNeedNextPage();//检查是否需要翻页
	void nextPageDeaccelerateScrolling(float dt);//翻页时的滚动
	void nextpageRelocateContainer(bool animated);//翻页时Relocates container
protected:
	cocos2d::CCPoint m_beginPoint;//touchBegan点击点
	cocos2d::CCPoint m_lastPoint;//touchEnded点击点
	cocos2d::CCPoint m_begin_containerPos_nextPage;//开始翻页时container的位置（只对翻页模式有用）
	cocos2d::CCPoint m_ended_containerPos_nextPage;//结束翻页时container的位置（只对翻页模式有用）
	cocos2d::CCPoint m_desire_containerPos_nextPage;//翻页的container目标位置（只对翻页模式有用）
	cocos2d::CCPoint m_origin_containerPos_nextPage;//开始翻页的container位置（只对翻页模式有用）
	cocos2d::CCObject* m_pTarget;//回调
	SEL_CallFuncI m_pSelector;//回调
};
