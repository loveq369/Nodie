#pragma once

#include "WXGrid.h"


//WXGridPanelEx�����grid
class GridItem: public WXResponseProtocol
{
public:
	GridItem();
	void show(bool isShow);

	virtual void updateGrid(tGridData& tgd);
	//�Ƿ���ʾ��Ŀ
	virtual void showNumLabel(bool isShow, const cocos2d::ccColor3B& color=cocos2d::Color3B::WHITE);

	virtual void setIsActive(bool isActive);
	//�����Ƿ�����
	virtual void setIsLock(bool isLock);
	//�Ƿ��
	virtual void setIsBinding(bool isBinding);
	//�Ƿ���ʾ��ɫ��type=GRID_RECT_TYPE_OUTER���type=GRID_RECT_TYPE_INNER�ڿ�
	virtual void showColorRect(bool isShow, int type=GRID_RECT_TYPE_OUTER);
	//������ɫ����ɫ
	virtual void setColorRectColor(const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//��Ӧ
	virtual void selected(bool var);
	virtual void activate();
protected:
	//�ڿ���ɫ
	cocos2d::ccColor3B m_innerColor;
	//�����ɫ
	cocos2d::ccColor3B m_outerColor;
public:
	WXGridBase* m_grid;
	cocos2d::CCSprite* m_bgSprite;//grid����
	cocos2d::CCSprite* m_lockSprite;//grid����
	cocos2d::CCSprite* m_bindingSprite;//grid��
	cocos2d::CCSprite* m_innerSprite;//gird����ɫ��
	cocos2d::CCSprite* m_outerSprite;//gird����ɫ��
};

class WXGridPanelEx: public WXBaseNode
{
public:
	WXGridPanelEx(void);
	~WXGridPanelEx(void);
	bool init();
	//��ʼ��ͼƬ��Ϣ
	void initRes(const char* bgbatchNodeFilename, const char* bgfilename,\
		const char* lockbatchNodeFilename, const char* lockfilename,\
		const char* bindingbatchNodeFilename, const char* bindingfilename,\
		const char* innnerbatchNodeFilename=NULL, const char* innnerfilename=NULL,\
		const char* outnerbatchNodeFilename=NULL, const char* outnerfilename=NULL);

	virtual void createGrids(std::vector<cocos2d::CCPoint>& tpList, const char* cdName=NULL);//����λ���б���grid

	//���grid��tgd��grid���ݣ�pos��gridλ�ã�tag��grid tag�� tag��grid cd�ļ���
	virtual void appendItem(tGridData& tgd, cocos2d::CCPoint& pos, int tag=-1, const char* cdName=NULL);

	//����grid
	virtual void updateGrid(unsigned int pos, tGridData& tgd);
	//grid�Ƿ��
	virtual void setIsBinding(unsigned int pos, bool isBinding);
	//grid�Ƿ�����
	virtual void setIsLock(unsigned int pos, bool isLock);
	//grid��ɫ��
	virtual void setColorRectColor(unsigned int pos, const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//grid icon��opacityֵ
	virtual void setIconSpriteOpacity(unsigned int pos, int val);

	//��ȡ����grid
	std::vector<GridItem>* getAllGrid(){return &m_gridList;}
	virtual GridItem* getGrid(unsigned int pos);//ȡ�ض�λ�õ�grid

	virtual bool onTouchBegan(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual bool onTouchEnded(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchCancelled(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);

	//ѡ��ָ��pos��grid
	virtual void selected(unsigned int pos);
	//����Ĭ�ϵĵ��grid
	virtual void setDefaultHitGrid();

	//����ͼƬ��·��
	virtual void setBGFilename(const char* batchNodeFilename, const char* filename);
	virtual void setLockFilename(const char* batchNodeFilename, const char* filename);
	virtual void setBindingFilename(const char* batchNodeFilename, const char* filename);
	virtual void setInnerFilename(const char* batchNodeFilename, const char* filename);
	virtual void setOuterFilename(const char* batchNodeFilename, const char* filename);

	CC_SYNTHESIZE(bool, m_isShowSelectedRect, IsShowSelectedRect);//�����Ƿ���ʾ���е���ɫ��
	CC_SYNTHESIZE_READONLY(GridItem*, m_curHitGrid, CurHitGrid);//��ǰ���grid
	CC_SYNTHESIZE_READONLY(GridItem*, m_lastHitGrid, LastHitGrid);//��һ�ε��grid

	CREATE_FUNC(WXGridPanelEx);
protected:
	virtual GridItem* itemForTouch(cocos2d::CCTouch * touch);
private:
	//����grid����
	std::vector<GridItem> m_gridList;
	//batchNode���
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
