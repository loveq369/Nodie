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

	CC_PROPERTY(TaskInfo*, currentTaskInfo, CurrentTaskInfo);//当前任务信息
	CC_SYNTHESIZE_READONLY(WXTableView*, tableView, TableView);//拉动条
	CC_SYNTHESIZE_READONLY(WXGridPanel*, bounsGridPanel, BounsGridPanel);//显示奖励道具
	CREATE_FUNC(TaskDialog);
private:
	void btnCallback(cocos2d::CCObject* pSender);
	void clickCallback(int tag);//超链接回调
	void updateTipsPanel(float dt);

private:
	cocos2d::CCSize tableViewSize;//tableView大小
	cocos2d::CCSprite * touxiang;
	cocos2d::CCNode* tableViewCellNode;//tableViewCell具体内容
	cocos2d::CCPoint touchWorldPoint;
	WXGrid* hitGrid;
	//WXRichLabelEx *awardLabel;
	float nameHeight;
	cocos2d::CCSprite *fengexian;//分割线

	std::string taskDetailStr;//任务详情
	std::string taskAwardStr;//任务奖励
	std::string maohaoStr;//冒号
	std::string expStr;//经验
	std::string finishStr;//完成任务
	std::string leaveStr;//离开
	std::string goOnStr;//继续
	std::string giveUpStr;//放弃
	std::string acceptStr;//接受任务
};

