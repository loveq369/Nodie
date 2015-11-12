//9miao.com 首发
#pragma once

#include "gamecore.h"
#include "Panel.h"

#define OPT_STEP_NEXT 0
#define OPT_STEP_QUIT -1
#define OPT_TASK_REQUEST 3
#define OPT_TASK_COMPLETE 1
#define OPT_TASK_GIRVEUP 2
#define OPT_TASK_RUN 7//任务进行时
#define OPT_DOOR_NORMAL 4//npc传送点（副本入口）
#define OPT_SHOP_NORMAL 5//商店
#define OPT_TASK_LIST 6//任务列表
#define OPT_LEARN_SKILL 8//学习技能
#define OPT_CREATE_GUILD 9//建帮会
#define OPT_EQUIP_ENCHANT 10//装备强化
#define OPT_MAIL 11//邮箱
#define OPT_STORAGE 14//仓库
#define OPT_BATTLEREPORT 15//战  报
#define OPT_TOWER_ENTER 16
#define OPT_TOWER_ENTER_SELECT 17//选择进入轮回塔层数
#define OPT_TOWER_MSG 18
#define SIMPLE_PERSON_INSTANCE_GETIN 19
#define EVER_QUEST_TASK 20//日常任务
#define NPC_EVERQUESTS_ENUM 21//日常任务
#define DIALOG_QUESTION_TASK 22
#define VIP_NPC 23//VIP
#define EXCHANGE_NPC 24//兑换商店
#define PET_RESET 25
#define PET_GROWH 26
#define CHESS_SPIRIT_REQ_LOG 27//领取奖励 
#define OPT_ITEM_IDENTITY 28//坐骑鉴定与合成
#define OPT_STATIC_DIALOG 100
#define GUILD_TRANSPORTATION 29//开启仙门运镖
#define TODAY_TRANSPORTATION 30//日常押镖
#define GUILD_FIGHT_SIGN 31
#define GUILD_IMPEACH 32
#define YOUNG_CHRISTMAS_TREE 33
#define FLORID_CHRISTMAS_TREE 34
#define FLORID_CHRISTMAS_TREE_1 3401
#define FLORID_CHRISTMAS_TREE_2 3402
#define FLORID_CHRISTMAS_TREE_3 3403
#define NEW_INSTANCE_ENTRY 25
#define NEW_INSTANCE_TYPE 10000
#define XUE_YU_GU_JI 35
#define XUE_YU_GU_JI_TYPE 20000
#define TIANSHAN_BATTLE_ENTRY 37
#define QIXI_LOTTERY_NIU 38
#define QIXI_LOTTERY_ZHINV 39
#define MAIN_LINE_ENTRY 40
#define OPT_WADDING 41
#define OPT_DIVORCE 42
#define OPT_ACTIVITY 43
#define OPT_FORCE_DIVORCE 44
#define GUILD_TRANS_KEY 36
#define GUILD_TRANS_LEAVE 0
#define GUILD_TRANS_JOIN 1
#define OPT_DOOR_LOOP 45//寒风岭副本入口
#define OPT_DOOR_LOOP_1 46//风啸呷副本入口
class AnswerVO//超链接数据
{
public:
	int sortFlag;
	std::string taskState;//任务状态
	std::string str;//
	int64 optVar;//banding的一些数据（基本上就是npc id）
	int option;//超链接类型
	void* optData;//banding的数据
	int taskAction;
};

class FunctionNPC;
class NPC;
class NpcDialog: public Panel, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
{
public:
	NpcDialog();
	~NpcDialog();

	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	bool onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {}
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	virtual void tableCellHighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	virtual void tableCellUnhighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::TableView *table);
	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

	void initPanel();

	//获取所有任务answers
	std::map<int, AnswerVO>* getTaskAnswers()
	{
		return &taskAnswers;
	}
	//更新一个任务answers
	void updateTaskAnswer(int taskId);

	CC_PROPERTY(FunctionNPC*, dialogInfo, DialogInfo);//功能npc对话信息（点击npc回来）
	CC_PROPERTY(NPC*, bindNpc, BindNPC);//banding的npc
	CC_SYNTHESIZE_READONLY(WXTableView*, tableView, TableView);//拉动条
	CC_SYNTHESIZE_READONLY(WXRichLabelEx*, dialogLabel, DialogLabel);//对话信息
	CC_SYNTHESIZE_READONLY(WXRichLabelEx*, linkLabel, LinkLabel);//npc功能连接

	CREATE_FUNC(NpcDialog);

private:
	void btnCallback(cocos2d::CCObject* pSender);
	void clickCallback(int tag);//超链接回调
private:
	//当前npc功能超链接
	std::vector<AnswerVO> answers;
	//任务相关的answer
	std::map<int, AnswerVO> taskAnswers;
	cocos2d::Size tableViewSize;//tableView大小
	WXMenu* menu;//下面点击的按钮
	//CCScale9Sprite *liaotian;//聊天框
	cocos2d::CCSprite *fengexian;//分割线
	float nameHeight;
	cocos2d::CCSprite *touxiang;//美女
	cocos2d::CCLabelTTF* npcName;//npc名字
	cocos2d::extension::TableViewCell* cell;//显示的按钮
	bool isHighlight;//是否点中tableView
};