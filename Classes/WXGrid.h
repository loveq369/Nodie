#pragma once

#include "WXBaseNode.h"
#include "WXUIProtocol.h"


//grid child的zorder
typedef enum
{
	grid_zorder_bg,
	grid_zorder_lock,
	grid_zorder_icon,
	grid_zorder_binding,
	grid_zorder_num,
	grid_zorder_center,
	grid_zorder_cd,
	grid_zorder_inner,
	grid_zorder_outer
}wxGridZorder;
//grid数据
class tGridData
{
public:
	int id;//对应道具的id
	int pos;//所在面板位置
	int slot;//所在包裹的位置
	int num;//数量
	std::string idStr;
	std::string url;//icon路径
	int type;//grid类型
	int status;// used = 2 /unlocked =1 /locked =0
	int src;  //grid 来源位置 背包=1，人物属性=2
	bool isActive;//是否激活（未激活灰化）
	bool isBinding;//是否是绑定（绑定则增加左上角lock）
public:
	tGridData()
	{
		id = 0;
		pos = 0;
		num = 1;
		idStr = "";
		url = "";
		type = 0;
		slot =0;
		status=0;
		src=0;
		isActive = true;
		isBinding = false;
	}
};
//grid颜色框类型
#define GRID_RECT_TYPE_OUTER	0//内框
#define GRID_RECT_TYPE_INNER	1//外框
//grid用的资源类型
#define GRID_RES_ITEM_TYPE_CD 1//cd
#define GRID_RES_ITEM_TYPE_BG 2//背景
#define GRID_RES_ITEM_TYPE_LOCK 3//锁住
#define GRID_RES_ITEM_TYPE_BINDING 4//绑定
#define GRID_RES_ITEM_TYPE_INNER 5//内框
#define GRID_RES_ITEM_TYPE_OUTTER 6//外框
//grid用到的资源
struct GridResItem
{
	bool m_isFrameName;//是否是frameName
	std::string m_filename;//文件名
	GridResItem()
	{
		m_isFrameName = true;
		m_filename = "";
	}
};

class WXGridBase: public WXBaseNode, public WXResponseProtocol
{
public:
	WXGridBase(void);
	~WXGridBase(void);
public:
	static WXGridBase* createWithSpriteFrameName(const char* cdName=NULL);
	static WXGridBase* createWithSpriteName(const char* cdName=NULL);

	virtual void updateGrid(tGridData& gridData);//更新grid数据
	virtual void clearGrid();

	//是否正在滚cd
	virtual bool isCDing();
	//开始cd滚动 cdTotal：cd总长，cdCount：累计滚动长
	virtual void startCD(int cdTotal, int cdCount);
	//是否显示数目
	virtual void showNumLabel(bool isShow, const cocos2d::ccColor3B& color=cocos2d::Color3B::WHITE);
	//设置中间的文字
	virtual void setCenterLabel(const char* str, const cocos2d::ccColor3B& color);
	//激活回调
	virtual void activate();
	virtual void selected(bool var);
public:
	bool initWithSpriteName(const char* cdName);
	bool initWithSpriteFrameName(const char* cdName);

	virtual bool onTouchBegan(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual bool onTouchEnded(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchCancelled(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);

	virtual tGridData& getGridData();
	virtual cocos2d::CCSprite* getIcon();

	virtual void setIsDrag(bool isDrag);//设置能否拖拽
	virtual void setIcon(const char* fileName=NULL);//设置icon图片
	virtual void setIcon(cocos2d::CCTexture2D* texture);//设置icon图片
	virtual void setIconSpriteOpacity(int val);//设置icon的opacity
	virtual void setGridStatus(int status);
	virtual void setGridType(int gridType);
	virtual void setGridNum(int gridNum);
	virtual void setGridPos(int pos);
	virtual void setGridSlot(int slot);
	virtual void setGridSrc(int src);
	virtual void setIsActive(bool isActive);

	//设置cd图片
	virtual void setCDSprite(const char* filename, bool isFrameName);

	CC_PROPERTY(cocos2d::CCSize, m_bgSize, BgSize);//背景大小
	CC_PROPERTY(cocos2d::CCSize, m_iconSize, IconSize);//图片大小
protected:
	virtual void cdOverCallback();//cd结束回调
	virtual bool onTouch(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
protected:
	//icon图片
	cocos2d::CCSprite* m_iconSprite;
	//cd滚动
	cocos2d::CCProgressTimer* m_coldTimer;
	//cd的action
	cocos2d::CCAction* m_cdAction;
	//grid上面的数据
	tGridData*  m_gridData;
	//grid中间显示的文字（在setCenterLabel中首次创建）
	cocos2d::CCLabelTTF* m_centerLabel;
	//叠加数量（在showNumLabel中首次创建）
	cocos2d::CCLabelTTF* m_numLabel;
	//grid是否可拖拽
	bool m_isDrag;
	//gird所用的资源
	std::map<int, GridResItem> m_resItems;
};

class WXGrid: public WXGridBase
{
public:
	WXGrid(void);
	~WXGrid(void);

public://比较常用的接口
	//bgName:背景图，lockName:锁定图，cdName:cd滚动图，bindingName:绑定图
	static WXGrid* createWithSpriteFrameName(const char* bgName=NULL, const char* lockName=NULL, const char* cdName=NULL, const char* bindingName=NULL, const char* innerName=NULL, const char* outerName=NULL);
	static WXGrid* createWithSpriteName(const char* bgName=NULL, const char* lockName=NULL, const char* cdName=NULL, const char* bindingName=NULL, const char* innerName=NULL, const char* outerName=NULL);

	//更新grid数据
	virtual void updateGrid(tGridData& gridData);
	//清空grid
	virtual void clearGrid();

	//设置是否锁定
	virtual void setIsLock(bool isLock);
	//是否绑定
	virtual void setIsBinding(bool isBinding);
	//是否显示颜色框（type=GRID_RECT_TYPE_OUTER外框，type=GRID_RECT_TYPE_INNER内框）
	virtual void showColorRect(bool isShow, int type=GRID_RECT_TYPE_OUTER);
	//设置颜色框颜色
	virtual void setColorRectColor(const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//设置颜色框大小
	virtual void setColorRectSize(const cocos2d::CCSize& size, int type=GRID_RECT_TYPE_OUTER);
public:
	bool initWithSpriteName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName);
	bool initWithSpriteFrameName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName);

	virtual void setBgSize(cocos2d::CCSize var);//背景大小
	virtual void setBGSprite(const char* filename, bool isFrameName);//设置背景图片， isFrameName：是否是spriteFrameName
	virtual void setLockSprite(const char* filename, bool isFrameName);//设置锁定图片
	virtual void setBindingSprite(const char* filename, bool isFrameName);//设置绑定图片

	//响应
	virtual void selected();
	virtual void unselected();
protected:
	//grid是否锁着的(决定是否可用)
	bool m_isLock;
	//外框大小
	cocos2d::CCSize m_outerSize;
	//内框大小
	cocos2d::CCSize m_innerSize;
	//外框颜色
	cocos2d::ccColor3B m_outerColor;
	//内框颜色
	cocos2d::ccColor3B m_innerColor;
	//内颜色框（在showColorRect中首次创建）
	cocos2d::CCSprite* m_innerSprite;
	//外颜色框（在showColorRect中首次创建）
	cocos2d::CCSprite* m_outerSprite;
	//背景图片（在setIsLock参数为false时首次创建）
	cocos2d::CCSprite* m_bgSprite;
	//是否锁定的图片（在setIsLock参数为true时首次创建）
	cocos2d::CCSprite* m_lockSprite;
	//是否绑定的图片（在setIsBinding参数为true时首次创建）
	cocos2d::CCSprite* m_bindingSprite;
};

