#pragma once

#include "WXGrid.h"


//WXGridPanelEx上面的grid
class GridItem: public WXResponseProtocol
{
public:
	GridItem();
	void show(bool isShow);

	virtual void updateGrid(tGridData& tgd);
	//是否显示数目
	virtual void showNumLabel(bool isShow, const cocos2d::ccColor3B& color=cocos2d::Color3B::WHITE);

	virtual void setIsActive(bool isActive);
	//设置是否锁定
	virtual void setIsLock(bool isLock);
	//是否绑定
	virtual void setIsBinding(bool isBinding);
	//是否显示颜色框（type=GRID_RECT_TYPE_OUTER外框，type=GRID_RECT_TYPE_INNER内框）
	virtual void showColorRect(bool isShow, int type=GRID_RECT_TYPE_OUTER);
	//设置颜色框颜色
	virtual void setColorRectColor(const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//响应
	virtual void selected(bool var);
	virtual void activate();
protected:
	//内框颜色
	cocos2d::ccColor3B m_innerColor;
	//外框颜色
	cocos2d::ccColor3B m_outerColor;
public:
	WXGridBase* m_grid;
	cocos2d::CCSprite* m_bgSprite;//grid背景
	cocos2d::CCSprite* m_lockSprite;//grid锁定
	cocos2d::CCSprite* m_bindingSprite;//grid绑定
	cocos2d::CCSprite* m_innerSprite;//gird内颜色框
	cocos2d::CCSprite* m_outerSprite;//gird外颜色框
};

class WXGridPanelEx: public WXBaseNode
{
public:
	WXGridPanelEx(void);
	~WXGridPanelEx(void);
	bool init();
	//初始化图片信息
	void initRes(const char* bgbatchNodeFilename, const char* bgfilename,\
		const char* lockbatchNodeFilename, const char* lockfilename,\
		const char* bindingbatchNodeFilename, const char* bindingfilename,\
		const char* innnerbatchNodeFilename=NULL, const char* innnerfilename=NULL,\
		const char* outnerbatchNodeFilename=NULL, const char* outnerfilename=NULL);

	virtual void createGrids(std::vector<cocos2d::CCPoint>& tpList, const char* cdName=NULL);//根据位置列表创建grid

	//添加grid，tgd：grid数据，pos：grid位置，tag：grid tag， tag：grid cd文件名
	virtual void appendItem(tGridData& tgd, cocos2d::CCPoint& pos, int tag=-1, const char* cdName=NULL);

	//更新grid
	virtual void updateGrid(unsigned int pos, tGridData& tgd);
	//grid是否绑定
	virtual void setIsBinding(unsigned int pos, bool isBinding);
	//grid是否锁定
	virtual void setIsLock(unsigned int pos, bool isLock);
	//grid颜色框
	virtual void setColorRectColor(unsigned int pos, const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//grid icon的opacity值
	virtual void setIconSpriteOpacity(unsigned int pos, int val);

	//获取所有grid
	std::vector<GridItem>* getAllGrid(){return &m_gridList;}
	virtual GridItem* getGrid(unsigned int pos);//取特定位置的grid

	virtual bool onTouchBegan(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual bool onTouchEnded(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchCancelled(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);

	//选中指定pos的grid
	virtual void selected(unsigned int pos);
	//设置默认的点击grid
	virtual void setDefaultHitGrid();

	//设置图片的路径
	virtual void setBGFilename(const char* batchNodeFilename, const char* filename);
	virtual void setLockFilename(const char* batchNodeFilename, const char* filename);
	virtual void setBindingFilename(const char* batchNodeFilename, const char* filename);
	virtual void setInnerFilename(const char* batchNodeFilename, const char* filename);
	virtual void setOuterFilename(const char* batchNodeFilename, const char* filename);

	CC_SYNTHESIZE(bool, m_isShowSelectedRect, IsShowSelectedRect);//设置是否显示点中的颜色框
	CC_SYNTHESIZE_READONLY(GridItem*, m_curHitGrid, CurHitGrid);//当前点击grid
	CC_SYNTHESIZE_READONLY(GridItem*, m_lastHitGrid, LastHitGrid);//上一次点击grid

	CREATE_FUNC(WXGridPanelEx);
protected:
	virtual GridItem* itemForTouch(cocos2d::CCTouch * touch);
private:
	//所有grid数据
	std::vector<GridItem> m_gridList;
	//batchNode相关
	cocos2d::CCSpriteBatchNode* m_bgBatchNode;
	cocos2d::CCSpriteBatchNode* m_lockBatchNode;
	cocos2d::CCSpriteBatchNode* m_bindingBatchNode;
	cocos2d::CCSpriteBatchNode* m_innerBatchNode;
	cocos2d::CCSpriteBatchNode* m_outerBatchNode;
	std::string m_bgBatchNodeStr;
	std::string m_bgStr;
	std::string m_lockBatchNodeStr;
	std::string m_lockStr;
	std::string m_bindingBatchNodeStr;
	std::string m_bindingStr;
	std::string m_innerBatchNodeStr;
	std::string m_innerStr;
	std::string m_outerBatchNodeStr;
	std::string m_outerStr;
};
