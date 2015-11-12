#pragma once

#include "WXGrid.h"


class WXGridPanel: public WXBaseNode
{
public:
	WXGridPanel(void);
	virtual ~WXGridPanel(void);

	//����λ���б���grid
	virtual void createGrids(std::vector<cocos2d::CCPoint> tpList, const char* bgName, const char* lockName, const char* cdName,\
		const char* bindingName=NULL, const char* innerName=NULL, const char* outerName=NULL);
	//���grid
	virtual void appendItem(WXGrid* grid, int tag=-1);

	//����grid
	virtual void updateGrid(unsigned int pos, tGridData& tgd);
	//�Ƿ�����grid
	virtual void setIsLock(unsigned int pos, bool isLock);
	//������ɫ����ɫ
	virtual void setColorRectColor(unsigned int pos, const cocos2d::ccColor3B& color, int type=GRID_RECT_TYPE_OUTER);
	//����icon��opacityֵ
	virtual void setIconSpriteOpacity(unsigned int pos, int val);

	std::vector<WXGrid*>* getAllGrid() {return m_gridList;}//��ȡ����grid
	virtual WXGrid* getGrid(unsigned int pos);//ȡ�ض�λ�õ�grid
	virtual WXGrid* getGridByTag(unsigned int tag);//����Grid tag��ȡһ��Grid

	virtual bool onTouchBegan(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual bool onTouchEnded(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);
	virtual void onTouchCancelled(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent);

	//ѡ��ָ��pos��grid
	virtual void selected(unsigned int pos);
	//����Ĭ�ϵĵ��grid
	virtual void setDefaultHitGrid();

	CC_SYNTHESIZE(bool, m_isShowSelectedRect, IsShowSelectedRect);//�����Ƿ���ʾ���е���ɫ��
	CC_SYNTHESIZE_READONLY(WXGrid*, m_curHitGrid, CurHitGrid);//��ǰ���grid
	CC_SYNTHESIZE_READONLY(WXGrid*, m_lastHitGrid, LastHitGrid);//��һ�ε��grid

	CREATE_FUNC(WXGridPanel);
protected:
	virtual WXGrid* itemForTouch(cocos2d::CCTouch * touch);
protected:
	std::vector<WXGrid*>* m_gridList;
};

