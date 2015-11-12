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
	//��λ��ָ��cell��idx��ָ����idx��delta��ָ����idxƫ����
	void navigateCellByIdx(unsigned int idx, cocos2d::CCPoint delta=cocos2d::CCPointZero, bool animated=false);
	//���÷�ҳ��Ļص�
	void setNextPageTarget(cocos2d::CCObject* target, SEL_CallFuncI selector);
	//��ȡ��ǰҳ
	int getCurrentPage();

	CC_SYNTHESIZE(float, m_fMoveDelta, MoveDelta);//�ƶ���Ч��ࣨ���أ��ﵽ�����ز����ƶ�

	CC_SYNTHESIZE(bool, m_bIsNextPage, IsNextPage);//�Ƿ��Ƿ�ҳ
	CC_SYNTHESIZE(float, m_fNextPageMinScrollDistance, NextPageMinScrollDistance);//���һ֡�������볬���þ���ŷ�ҳ�����أ�
	CC_SYNTHESIZE(float, m_fNextPageSpeed, NextPageSpeed);//��ҳʱ��scroll�ٶ�
private:
	void checkNeedNextPage();//����Ƿ���Ҫ��ҳ
	void nextPageDeaccelerateScrolling(float dt);//��ҳʱ�Ĺ���
	void nextpageRelocateContainer(bool animated);//��ҳʱRelocates container
protected:
	cocos2d::CCPoint m_beginPoint;//touchBegan�����
	cocos2d::CCPoint m_lastPoint;//touchEnded�����
	cocos2d::CCPoint m_begin_containerPos_nextPage;//��ʼ��ҳʱcontainer��λ�ã�ֻ�Է�ҳģʽ���ã�
	cocos2d::CCPoint m_ended_containerPos_nextPage;//������ҳʱcontainer��λ�ã�ֻ�Է�ҳģʽ���ã�
	cocos2d::CCPoint m_desire_containerPos_nextPage;//��ҳ��containerĿ��λ�ã�ֻ�Է�ҳģʽ���ã�
	cocos2d::CCPoint m_origin_containerPos_nextPage;//��ʼ��ҳ��containerλ�ã�ֻ�Է�ҳģʽ���ã�
	cocos2d::CCObject* m_pTarget;//�ص�
	SEL_CallFuncI m_pSelector;//�ص�
};
