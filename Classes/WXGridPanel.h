#pragma once

#include "WXGrid.h"


class WXGridPanel: public WXBaseNode
{
public:
	WXGridPanel(void);
	virtual ~WXGridPanel(void);

	//根据位置列表创建grid
	virtual void createGrids(std::vector<cocos2d::CCPoint> tpList, const char* bgName, const char* lockName, const char* cdName,\
		const char* bindingName=NULL, const char* innerName=NULL, const char* outerName=NULL);
	//添加grid
	virtual void appendItem(WXGrid* grid, int tag=-1);

	//更新grid
	virtual void updateGrid(unsigned int pos, tGridData& tgd);
	//是否锁定grid
	virtual void setIsLock(unsigned int pos, bool isLock);
	//更新颜色框颜色
	virtual void setColorRectColor(unsigned int pos, const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//更新icon的opacity值
	virtual void setIconSpriteOpacity(unsigned int pos, int val);

	std::vector<WXGrid*>* getAllGrid() {return m_gridList;}//获取所有grid
	virtual WXGrid* getGrid(unsigned int pos);//取特定位置的grid
	virtual WXGrid* getGridByTag(unsigned int tag);//根据Grid tag获取一个Grid

	virtual bool onTouchBegan(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual bool onTouchEnded(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchCancelled(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);

	//选中指定pos的grid
	virtual void selected(unsigned int pos);
	//设置默认的点击grid
	virtual void setDefaultHitGrid();

	CC_SYNTHESIZE(bool, m_isShowSelectedRect, IsShowSelectedRect);//设置是否显示点中的颜色框
	CC_SYNTHESIZE_READONLY(WXGrid*, m_curHitGrid, CurHitGrid);//当前点击grid
	CC_SYNTHESIZE_READONLY(WXGrid*, m_lastHitGrid, LastHitGrid);//上一次点击grid

	CREATE_FUNC(WXGridPanel);
protected:
	virtual WXGrid* itemForTouch(cocos2d::CCTouch * touch);
protected:
	std::vector<WXGrid*>* m_gridList;
};

