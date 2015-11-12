#pragma once

#include "WXBaseNode.h"
#include "WXUIProtocol.h"


//grid child��zorder
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
//grid����
class tGridData
{
public:
	int id;//��Ӧ���ߵ�id
	int pos;//�������λ��
	int slot;//���ڰ�����λ��
	int num;//����
	std::string idStr;
	std::string url;//icon·��
	int type;//grid����
	int status;// used = 2 /unlocked =1 /locked =0
	int src;  //grid ��Դλ�� ����=1����������=2
	bool isActive;//�Ƿ񼤻δ����һ���
	bool isBinding;//�Ƿ��ǰ󶨣������������Ͻ�lock��
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
//grid��ɫ������
#define GRID_RECT_TYPE_OUTER	0//�ڿ�
#define GRID_RECT_TYPE_INNER	1//���
//grid�õ���Դ����
#define GRID_RES_ITEM_TYPE_CD 1//cd
#define GRID_RES_ITEM_TYPE_BG 2//����
#define GRID_RES_ITEM_TYPE_LOCK 3//��ס
#define GRID_RES_ITEM_TYPE_BINDING 4//��
#define GRID_RES_ITEM_TYPE_INNER 5//�ڿ�
#define GRID_RES_ITEM_TYPE_OUTTER 6//���
//grid�õ�����Դ
struct GridResItem
{
	bool m_isFrameName;//�Ƿ���frameName
	std::string m_filename;//�ļ���
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

	virtual void updateGrid(tGridData& gridData);//����grid����
	virtual void clearGrid();

	//�Ƿ����ڹ�cd
	virtual bool isCDing();
	//��ʼcd���� cdTotal��cd�ܳ���cdCount���ۼƹ�����
	virtual void startCD(int cdTotal, int cdCount);
	//�Ƿ���ʾ��Ŀ
	virtual void showNumLabel(bool isShow, const cocos2d::ccColor3B& color=cocos2d::Color3B::WHITE);
	//�����м������
	virtual void setCenterLabel(const char* str, const cocos2d::ccColor3B& color);
	//����ص�
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

	virtual void setIsDrag(bool isDrag);//�����ܷ���ק
	virtual void setIcon(const char* fileName=NULL);//����iconͼƬ
	virtual void setIcon(cocos2d::CCTexture2D* texture);//����iconͼƬ
	virtual void setIconSpriteOpacity(int val);//����icon��opacity
	virtual void setGridStatus(int status);
	virtual void setGridType(int gridType);
	virtual void setGridNum(int gridNum);
	virtual void setGridPos(int pos);
	virtual void setGridSlot(int slot);
	virtual void setGridSrc(int src);
	virtual void setIsActive(bool isActive);

	//����cdͼƬ
	virtual void setCDSprite(const char* filename, bool isFrameName);

	CC_PROPERTY(cocos2d::CCSize, m_bgSize, BgSize);//������С
	CC_PROPERTY(cocos2d::CCSize, m_iconSize, IconSize);//ͼƬ��С
protected:
	virtual void cdOverCallback();//cd�����ص�
	virtual bool onTouch(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
protected:
	//iconͼƬ
	cocos2d::CCSprite* m_iconSprite;
	//cd����
	cocos2d::CCProgressTimer* m_coldTimer;
	//cd��action
	cocos2d::CCAction* m_cdAction;
	//grid���������
	tGridData*  m_gridData;
	//grid�м���ʾ�����֣���setCenterLabel���״δ�����
	cocos2d::CCLabelTTF* m_centerLabel;
	//������������showNumLabel���״δ�����
	cocos2d::CCLabelTTF* m_numLabel;
	//grid�Ƿ����ק
	bool m_isDrag;
	//gird���õ���Դ
	std::map<int, GridResItem> m_resItems;
};

class WXGrid: public WXGridBase
{
public:
	WXGrid(void);
	~WXGrid(void);

public://�Ƚϳ��õĽӿ�
	//bgName:����ͼ��lockName:����ͼ��cdName:cd����ͼ��bindingName:��ͼ
	static WXGrid* createWithSpriteFrameName(const char* bgName=NULL, const char* lockName=NULL, const char* cdName=NULL, const char* bindingName=NULL, const char* innerName=NULL, const char* outerName=NULL);
	static WXGrid* createWithSpriteName(const char* bgName=NULL, const char* lockName=NULL, const char* cdName=NULL, const char* bindingName=NULL, const char* innerName=NULL, const char* outerName=NULL);

	//����grid����
	virtual void updateGrid(tGridData& gridData);
	//���grid
	virtual void clearGrid();

	//�����Ƿ�����
	virtual void setIsLock(bool isLock);
	//�Ƿ��
	virtual void setIsBinding(bool isBinding);
	//�Ƿ���ʾ��ɫ��type=GRID_RECT_TYPE_OUTER���type=GRID_RECT_TYPE_INNER�ڿ�
	virtual void showColorRect(bool isShow, int type=GRID_RECT_TYPE_OUTER);
	//������ɫ����ɫ
	virtual void setColorRectColor(const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//������ɫ���С
	virtual void setColorRectSize(const cocos2d::CCSize& size, int type=GRID_RECT_TYPE_OUTER);
public:
	bool initWithSpriteName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName);
	bool initWithSpriteFrameName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName);

	virtual void setBgSize(cocos2d::CCSize var);//������С
	virtual void setBGSprite(const char* filename, bool isFrameName);//���ñ���ͼƬ�� isFrameName���Ƿ���spriteFrameName
	virtual void setLockSprite(const char* filename, bool isFrameName);//��������ͼƬ
	virtual void setBindingSprite(const char* filename, bool isFrameName);//���ð�ͼƬ

	//��Ӧ
	virtual void selected();
	virtual void unselected();
protected:
	//grid�Ƿ����ŵ�(�����Ƿ����)
	bool m_isLock;
	//����С
	cocos2d::CCSize m_outerSize;
	//�ڿ��С
	cocos2d::CCSize m_innerSize;
	//�����ɫ
	cocos2d::ccColor3B m_outerColor;
	//�ڿ���ɫ
	cocos2d::ccColor3B m_innerColor;
	//����ɫ����showColorRect���״δ�����
	cocos2d::CCSprite* m_innerSprite;
	//����ɫ����showColorRect���״δ�����
	cocos2d::CCSprite* m_outerSprite;
	//����ͼƬ����setIsLock����Ϊfalseʱ�״δ�����
	cocos2d::CCSprite* m_bgSprite;
	//�Ƿ�������ͼƬ����setIsLock����Ϊtrueʱ�״δ�����
	cocos2d::CCSprite* m_lockSprite;
	//�Ƿ�󶨵�ͼƬ����setIsBinding����Ϊtrueʱ�״δ�����
	cocos2d::CCSprite* m_bindingSprite;
};

