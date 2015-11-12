//9miao.com �׷�
#pragma once

#include "gamecore.h"
#include "Panel.h"

#define OPT_STEP_NEXT 0
#define OPT_STEP_QUIT -1
#define OPT_TASK_REQUEST 3
#define OPT_TASK_COMPLETE 1
#define OPT_TASK_GIRVEUP 2
#define OPT_TASK_RUN 7//�������ʱ
#define OPT_DOOR_NORMAL 4//npc���͵㣨������ڣ�
#define OPT_SHOP_NORMAL 5//�̵�
#define OPT_TASK_LIST 6//�����б�
#define OPT_LEARN_SKILL 8//ѧϰ����
#define OPT_CREATE_GUILD 9//�����
#define OPT_EQUIP_ENCHANT 10//װ��ǿ��
#define OPT_MAIL 11//����
#define OPT_STORAGE 14//�ֿ�
#define OPT_BATTLEREPORT 15//ս  ��
#define OPT_TOWER_ENTER 16
#define OPT_TOWER_ENTER_SELECT 17//ѡ������ֻ�������
#define OPT_TOWER_MSG 18
#define SIMPLE_PERSON_INSTANCE_GETIN 19
#define EVER_QUEST_TASK 20//�ճ�����
#define NPC_EVERQUESTS_ENUM 21//�ճ�����
#define DIALOG_QUESTION_TASK 22
#define VIP_NPC 23//VIP
#define EXCHANGE_NPC 24//�һ��̵�
#define PET_RESET 25
#define PET_GROWH 26
#define CHESS_SPIRIT_REQ_LOG 27//��ȡ���� 
#define OPT_ITEM_IDENTITY 28//���������ϳ�
#define OPT_STATIC_DIALOG 100
#define GUILD_TRANSPORTATION 29//������������
#define TODAY_TRANSPORTATION 30//�ճ�Ѻ��
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
#define OPT_DOOR_LOOP 45//�����븱�����
#define OPT_DOOR_LOOP_1 46//��Х�ȸ������
class AnswerVO//����������
{
public:
	int sortFlag;
	std::string taskState;//����״̬
	std::string str;//
	int64 optVar;//banding��һЩ���ݣ������Ͼ���npc id��
	int option;//����������
	void* optData;//banding������
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

	//��ȡ��������answers
	std::map<int, AnswerVO>* getTaskAnswers()
	{
		return &taskAnswers;
	}
	//����һ������answers
	void updateTaskAnswer(int taskId);

	CC_PROPERTY(FunctionNPC*, dialogInfo, DialogInfo);//����npc�Ի���Ϣ�����npc������
	CC_PROPERTY(NPC*, bindNpc, BindNPC);//banding��npc
	CC_SYNTHESIZE_READONLY(WXTableView*, tableView, TableView);//������
	CC_SYNTHESIZE_READONLY(WXRichLabelEx*, dialogLabel, DialogLabel);//�Ի���Ϣ
	CC_SYNTHESIZE_READONLY(WXRichLabelEx*, linkLabel, LinkLabel);//npc��������

	CREATE_FUNC(NpcDialog);

private:
	void btnCallback(cocos2d::CCObject* pSender);
	void clickCallback(int tag);//�����ӻص�
private:
	//��ǰnpc���ܳ�����
	std::vector<AnswerVO> answers;
	//������ص�answer
	std::map<int, AnswerVO> taskAnswers;
	cocos2d::Size tableViewSize;//tableView��С
	WXMenu* menu;//�������İ�ť
	//CCScale9Sprite *liaotian;//�����
	cocos2d::CCSprite *fengexian;//�ָ���
	float nameHeight;
	cocos2d::CCSprite *touxiang;//��Ů
	cocos2d::CCLabelTTF* npcName;//npc����
	cocos2d::extension::TableViewCell* cell;//��ʾ�İ�ť
	bool isHighlight;//�Ƿ����tableView
};