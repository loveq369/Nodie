#pragma once

#include "gamecore.h"
#include "Panel.h"

class TaskInfo;
class TaskDialog: public Panel, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
{
public:
	TaskDialog(void);
	~TaskDialog(void);

	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	bool onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	void initPanel();
	void show(bool isShow);
	//void tweenCallback();

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {}
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::TableView *table);
	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

	virtual void startGuideStep();
	virtual void nextGuidStep();

	//std::string  GetDialogTitleText(TaskInfo* v);

	CC_PROPERTY(TaskInfo*, currentTaskInfo, CurrentTaskInfo);//��ǰ������Ϣ
	CC_SYNTHESIZE_READONLY(WXTableView*, tableView, TableView);//������
	CC_SYNTHESIZE_READONLY(WXGridPanel*, bounsGridPanel, BounsGridPanel);//��ʾ��������
	CREATE_FUNC(TaskDialog);
private:
	void btnCallback(cocos2d::CCObject* pSender);
	void clickCallback(int tag);//�����ӻص�
	void updateTipsPanel(float dt);

private:
	cocos2d::CCSize tableViewSize;//tableView��С
	cocos2d::CCSprite * touxiang;
	cocos2d::CCNode* tableViewCellNode;//tableViewCell��������
	cocos2d::CCPoint touchWorldPoint;
	WXGrid* hitGrid;
	//WXRichLabelEx *awardLabel;
	float nameHeight;
	cocos2d::CCSprite *fengexian;//�ָ���

	std::string taskDetailStr;//��������
	std::string taskAwardStr;//������
	std::string maohaoStr;//ð��
	std::string expStr;//����
	std::string finishStr;//�������
	std::string leaveStr;//�뿪
	std::string goOnStr;//����
	std::string giveUpStr;//����
	std::string acceptStr;//��������
};

