//#pragma once
//
//#include "gamecore.h"
//
//typedef struct TrackLinkData: public tLinkData//��������Ŀ������
//{
//	int type;//�������ͣ�1��Ŀ��npc��2��Ŀ���ͼ��3����壬4����Ʒ
//	int value2;//���ݶ�
//}tTrackLinkData;
//typedef struct TrackItem//����׷����
//{
//	int taskId;//����id
//	WXRichLabelEx* label;//������ʾ����
//	std::map<int, tTrackLinkData> linkDataDic;//��������
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
//	void deleteTaskInfo(TaskInfo* taskInfo);//ɾ��һ��������Ϣ
//	void updateTaskInfo(TaskInfo* taskInfo);//����һ��������Ϣ
//	void updateTaskItem(TaskInfo* taskInfo, tTrackItem& trackItem);
//
//	CC_SYNTHESIZE_READONLY(WXTableView*, tableView, TableView);//������
//
//	CREATE_W_H_FUNC(TaskListDlg);
//private:
//	void clickCallback(int tag);//�����ӻص�
//private:
//	cocos2d::CCSize tableViewSize;//tableView��С
//	cocos2d::CCNode* tableViewCellNode;//tableViewCell��������
//	std::vector<tTrackItem> trackList;//
//
//	WXRichLabelEx* selectedLabel;//��ǰ���е�label
//	std::string ramus1Str;
//	std::string ramusStr;
//	std::string ramus2Str;
//	std::string taskFinishStr;
//	std::string taskUnFinishStr;
//	std::string taskAvailableStr;
//	std::string taskVisit;
//	bool isHighlight;
//};