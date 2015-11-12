//#pragma once
//
//#include "gamecore.h"
//
//typedef struct TrackLinkData: public tLinkData//任务超链接目标数据
//{
//	int type;//链接类型，1：目标npc，2：目标地图，3：面板，4：商品
//	int value2;//数据二
//}tTrackLinkData;
//typedef struct TrackItem//任务追踪项
//{
//	int taskId;//任务id
//	WXRichLabelEx* label;//任务显示文字
//	std::map<int, tTrackLinkData> linkDataDic;//连接数据
//}tTrackItem;
//
//class NPC;
//class TaskInfo;
//std::vector<tTrackLinkData> getTrackLinkDataFromStr(std::string str);
//void getTrackLinkData(std::vector<tTrackLinkData>& tldList, std::string& str, char frontSplit, char middleSplit, char backSplit, int type);
//std::vector<std::string> splitString(std::string str, char splitChar=',');
//class TaskListDlg : public WXPanel, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
//{
//public:
//	TaskListDlg(void);
//	~TaskListDlg(void);
//	bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
//	bool onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
//	void onTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
//	void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
//
//	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
//	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {}
//	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
//	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::TableView *table);
//	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
//	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
//	virtual void tableCellHighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
//	virtual void tableCellUnhighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
//
//	bool init(int w, int h);
//	void initPanel();
//	void deleteTaskInfo(TaskInfo* taskInfo);//删除一个任务信息
//	void updateTaskInfo(TaskInfo* taskInfo);//更新一个任务信息
//	void updateTaskItem(TaskInfo* taskInfo, tTrackItem& trackItem);
//
//	CC_SYNTHESIZE_READONLY(WXTableView*, tableView, TableView);//拉动条
//
//	CREATE_W_H_FUNC(TaskListDlg);
//private:
//	void clickCallback(int tag);//超链接回调
//private:
//	cocos2d::CCSize tableViewSize;//tableView大小
//	cocos2d::CCNode* tableViewCellNode;//tableViewCell具体内容
//	std::vector<tTrackItem> trackList;//
//
//	WXRichLabelEx* selectedLabel;//当前点中的label
//	std::string ramus1Str;
//	std::string ramusStr;
//	std::string ramus2Str;
//	std::string taskFinishStr;
//	std::string taskUnFinishStr;
//	std::string taskAvailableStr;
//	std::string taskVisit;
//	bool isHighlight;
//};