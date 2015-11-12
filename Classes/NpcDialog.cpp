#include "NpcDialog.h"
#include "NPC.h"
#include "GameGobal.h"
#include "DataManager.h"
#include "DialogController.h"
#include "PlayerController.h"
#include "TaskController.h"
#include "PlayerData.h"
#include "UIDefine.h"
#include "SceneController.h"
#include "ui/UIScale9Sprite.h"
#include "util/tools.h"
//#include "TeamManager.h"
USING_NS_CC;
USING_NS_CC_EXT;

#define NPC_DIALOG_TYPE_STORE			1//商店
#define NPC_DIALOG_TYPE_INSTANCE		2//副本
#define NPC_DIALOG_TYPE_TASK			3//任务
#define NPC_DIALOG_TYPE_LEARN_SKILL		4//学习技能
#define NPC_DIALOG_TYPE_BUILD_GUILD		5//建帮会
#define NPC_DIALOG_TYPE_EMAIL			6//邮箱
#define NPC_DIALOG_TYPE_EQUIP_STRENGTH	7//装备强化
#define NPC_DIALOG_TYPE_STORAGE			10//仓库
#define	NPC_DIALOG_TYPE_TOWER_ENTER_SELECT		11//选择进入轮回塔层数
#define NPC_DIALOG_TYPE_BATTLEREPORT	12//战  报
#define NPC_DIALOG_TYPE_EVERQUESTS_ENUM	13//日常任务
#define NPC_DIALOG_TYPE_VIP				14//VIP
#define NPC_DIALOG_TYPE_EXCHANGE_NPC	18//兑换商店
#define NPC_DIALOG_TYPE_CHESS_SPIRIT_REQ_LOG	20//领取奖励
#define NPC_DIALOG_TYPE_ITEM_IDENTITY			21//坐骑鉴定与合成
#define NPC_DIALOG_TYPE_GUILD_TRANSPORTATION	22//开启仙门运镖

#define NPC_DIALOG_TYPE_INSTANCE_HANFENGLING	25//寒风岭副本
#define NPC_DIALOG_TYPE_INSTANCE_FENGXIAOXIA	26//风啸呷副本


#define OPEN_HANFENGLING 10000//队长开启寒风岭副本时用到的id
#define OPEN_FENGXIAOXIA 20000//队长开启风啸呷副本时用到的id
#define HANFENGLING_ENTER 3007001//寒风岭副本的显示id

#define MENU_ZORDER  1

NpcDialog::NpcDialog()
{
	bindNpc = NULL;
	dialogLabel = NULL;
	tableView = NULL;
	linkLabel = NULL;
	dialogInfo = NULL;
	tableViewSize = Size::ZERO;
	this->setVisible(false);
	npcName = NULL;
	touxiang =NULL;
	menu = NULL;
	cell = NULL;
	DialogController::getInstance().setNpcDialog(this);
	setCanTween(false);
}
NpcDialog::~NpcDialog()
{
	CC_SAFE_RELEASE(linkLabel);
	CC_SAFE_RELEASE(dialogLabel);
	DialogController::getInstance().setNpcDialog(NULL);
}
void NpcDialog::initPanel()
{
	WINSIZE;
	int w = 600;
	int h = 350;

	float border=20.0f;//间隙
	float liaotianExtern=30.0f;//聊天框的格外宽度(那个角)
	nameHeight=30.0f;//npc名称高度
	setAnchorPoint(ccp(0.5f,0.5f));
	setContentSize(CCSizeMake(w,h));
	setPosition(ccp(winSize.width/2,winSize.height/2));

	//背景
	Scale9Sprite *bg=Scale9Sprite::createWithSpriteFrameName(DIALOG_BG,DIALOG_BG_CCRect);
	bg->setContentSize(getContentSize());
	bg->setAnchorPoint(Point::ZERO);
	addChild(bg);

	//聊天框
	Scale9Sprite* liaotian=Scale9Sprite::createWithSpriteFrameName(DIALOG_LIAOTIAN,DIALOG_LIAOTIAN_CCRect);
	liaotian->setContentSize(CCSizeMake(w/4*3,h-border*2));
	liaotian->setAnchorPoint(Point::ZERO);
	liaotian->setPosition(getContentSize().width-border-liaotian->getContentSize().width,border);
	addChild(liaotian);

	//头像
	char str[50];
	std::sprintf(str,"%d.png",bindNpc->getLivingThingData()->entryid);

	touxiang=CCSprite::createWithSpriteFrameName(str);
	touxiang->setAnchorPoint(Point::ZERO);
	touxiang->setPosition(ccp(25,200));
	addChild(touxiang);

	//底部按钮
	Scale9Sprite* s9sNormal;
	Scale9Sprite* s9sSelected;
	Size btnSize = Size(100, 45);

	//s9sNormal = CCScale9Sprite::createWithSpriteFrameName(BTN_91_45_NORMAL,BTN_91_45_CCRect);
	//s9sNormal->setContentSize(btnSize);
	//s9sSelected = CCScale9Sprite::createWithSpriteFrameName(BTN_91_45_SELECTED,BTN_91_45_CCRect);
	//s9sSelected->setContentSize(btnSize);
	//WXSimpleButton* leftBtn = WXSimpleButton::createWithNode(s9sNormal, s9sSelected, NULL, "LEFT");
	//leftBtn->setTarget(this, menu_selector(NpcDialog::btnCallback));
	//leftBtn->setTag(1);
	//leftBtn->setVisible(false);

	//离开按钮
	s9sNormal = Scale9Sprite::createWithSpriteFrameName("button.png",Rect(30,8,30,9));
	s9sNormal->setContentSize(btnSize);
	s9sSelected = Scale9Sprite::createWithSpriteFrameName("button.png",Rect(30,8,30,9));
	s9sSelected->setContentSize(btnSize);
	WXSimpleButton* rightBtn = WXSimpleButton::createWithNode(s9sNormal, s9sSelected, NULL, GETSTR("dialog_text_0020"));
	rightBtn->setTarget(this, menu_selector(NpcDialog::btnCallback));
	rightBtn->setPosition(ccp(getContentSize().width-border*3/2-rightBtn->getContentSize().width/2,border*3/2+rightBtn->getContentSize().height/2));
	rightBtn->setTag(2);

	menu = WXMenu::create(rightBtn, NULL);
	menu->setAnchorPoint(Point::ZERO);
	menu->setPosition(Point::ZERO);
	//menu->alignItemsHorizontallyWithPadding(150);
	addChild(menu,MENU_ZORDER);

	tableViewSize = CCSizeMake(liaotian->getContentSize().width-liaotianExtern-border*2, liaotian->getContentSize().height
		-border*2);

	//npc名称
	npcName = CCLabelTTF::create("leenini", FONT_NAME_DEFAULT, 26);
	npcName->setAnchorPoint(Point::ZERO);
	npcName->setColor(CH_GREEN);

	//npc功能
	linkLabel = WXRichLabelEx::create();
	linkLabel->Initialize(FONT_ALIAS_DEFAULT_24, 24,tableViewSize, this, callfuncI_selector(NpcDialog::clickCallback));
	CC_SAFE_RETAIN(linkLabel);

	//分割线
	fengexian=CCSprite::createWithSpriteFrameName("dialog_fengexian.png");

	//npc对话
	dialogLabel = WXRichLabelEx::create();
	dialogLabel->Initialize(FONT_ALIAS_DEFAULT_24,24, tableViewSize, NULL, NULL);
	CC_SAFE_RETAIN(dialogLabel);

	tableView = WXTableView::create(this, tableViewSize);
	tableView->setDirection(ScrollView::Direction::VERTICAL);
	tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	tableView->setDelegate(this);
	//tableView->setVisible(false);
	tableView->setPosition(ccp(liaotian->getPositionX()+liaotianExtern+border,liaotian->getPositionY()+border));
	addChild(tableView);

	if (bindNpc)
	{
		NPC* temp = bindNpc;
		bindNpc = NULL;
		setBindNPC(temp);
	}
	if (dialogInfo)
	{
		FunctionNPC* temp = dialogInfo;
		dialogInfo = NULL;
		setDialogInfo(temp);
	}
}
bool NpcDialog::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return false;
	}
	if (menu->onTouchBegan(pTouch, pEvent))
	{
		return true;
	}
	if (tableView->onTouchBegan(pTouch, pEvent))
	{
		if (linkLabel->onTouchBegan(pTouch, pEvent))
		{
			return true;
		}
		return true;
	}
	return WXPanel::onTouchBegan(pTouch, pEvent);
}
bool NpcDialog::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return false;
	}
	menu->onTouchEnded(pTouch, pEvent);
	linkLabel->onTouchEnded(pTouch, pEvent);
	tableView->onTouchEnded(pTouch, pEvent);
	return WXPanel::onTouchEnded(pTouch, pEvent);
}
void NpcDialog::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return;
	}
	menu->onTouchCancelled(pTouch, pEvent);
	tableView->onTouchCancelled(pTouch, pEvent);
	linkLabel->onTouchCancelled(pTouch, pEvent);
}
void NpcDialog::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return;
	}
	menu->onTouchMoved(pTouch, pEvent);
	tableView->onTouchMoved(pTouch, pEvent);
}
void NpcDialog::setBindNPC(NPC* npc)
{
	if (bindNpc!=npc)
	{
		if(npcName) npcName->setString(npc->getName().c_str());
		bindNpc = npc;
	}
}
NPC* NpcDialog::getBindNPC()
{
	return bindNpc;
}
void NpcDialog::btnCallback(CCObject* pSender)
{
	WXSimpleButton* pTemp=(WXSimpleButton*)pSender;
	int tag = pTemp->getTag();
	switch (tag)
	{
	case 1:
	case 2:
		toggle();
		break;
	}
}
void NpcDialog::clickCallback(int tag)
{
	int size = answers.size();
	tag = tag-50;
	if (tag>=size)
	{
		return;
	}
	std::vector<AnswerVO>::iterator itr = answers.begin()+tag;
	//switch ((*itr).option)
	//{
	//case OPT_DOOR_NORMAL:
	//	{
	//		//tTransmitConfigData* trans = (tTransmitConfigData*)((*itr).optData);
	//		//if (!trans)
	//		//{
	//		//	break;
	//		//}
	//		//SceneController::getInstance().reqTransmitC2S(trans, bindNpc->getId());
	//	}
	//	break;
	//case OPT_DOOR_LOOP_1://特殊副本：风啸呷副本
	//	{			
	//		if(PlayerController::getInstance().getTeamManager()&&PlayerController::getInstance().getTeamManager()->hasTeam())
	//		{
	//			if(PlayerController::getInstance().getTeamManager()->isLeader())//是队长，则可以开启副本
	//			{
	//				PlayerController::getInstance().reqOpenInstanceC2S(OPEN_FENGXIAOXIA);//
	//			}
	//			else//不是队长，提示不能开启副本
	//			{
	//				GameGobal::getInstance().getGameUILayer()->getMsgDisplay();					
	//				GameGobal::getInstance().getGameUILayer()->getMsgDisplay()->msgDisplay(GETSTR("only_leader_can_open_instance"));					
	//			}
	//		}
	//		else//没有队伍，请先组队
	//		{
	//			GameGobal::getInstance().getGameUILayer()->getMsgDisplay();					
	//			GameGobal::getInstance().getGameUILayer()->getMsgDisplay()->msgDisplay(GETSTR("buzaiduiwuzhong_xianzudui"));					
	//		}
	//	}
	//	break;
	//case OPT_DOOR_LOOP://特殊副本：寒风岭副本
	//	{
	//		tTransmitConfigData* trans = (tTransmitConfigData*)((*itr).optData);
	//		if (!trans)
	//		{
	//			break;
	//		}
	//		if(PlayerController::getInstance().getTeamManager()&&PlayerController::getInstance().getTeamManager()->hasTeam())
	//		{
	//			if(PlayerController::getInstance().getTeamManager()->isLeader())//是队长，则可以开启副本
	//			{
	//				PlayerController::getInstance().reqOpenInstanceC2S(OPEN_HANFENGLING);//
	//			}
	//			else//不是队长，提示不能开启副本
	//			{
	//				GameGobal::getInstance().getGameUILayer()->getMsgDisplay();					
	//				GameGobal::getInstance().getGameUILayer()->getMsgDisplay()->msgDisplay(GETSTR("only_leader_can_open_instance"));					
	//			}
	//		}
	//		else//没有队伍，请先组队
	//		{
	//			GameGobal::getInstance().getGameUILayer()->getMsgDisplay();					
	//			GameGobal::getInstance().getGameUILayer()->getMsgDisplay()->msgDisplay(GETSTR("buzaiduiwuzhong_xianzudui"));					
	//		}
	//	}
	//	break;
	//case EVER_QUEST_TASK:
	//case TODAY_TRANSPORTATION:
	//	{
	//		int everId = ((EverQuestConfigData*)((*itr).optData))->id;
	//		DialogController::getInstance().reqNpcEverquestsStartC2S((*itr).optVar, everId);
	//	}
	//	break;
	//case OPT_TASK_RUN:
	//	{
	//		TaskInfo* taskInfo = (TaskInfo*)((*itr).optData);
	//		GameGobal::getInstance().getGameUILayer()->getTaskDialog()->setCurrentTaskInfo(taskInfo);
	//	}
	//	break;
	//}
	tween(false);
}
void NpcDialog::setDialogInfo(FunctionNPC* var)
{
	if (!isShow())
	{
		toggle();
	}
	if (!var)
	{
		return;
	}
	//npc对话描述
	dialogLabel->ResetContent();
	dialogInfo = var;
	//改变头像
	char str[50];
	std::sprintf(str,"%d.png",dialogInfo->npcEntryId);
	touxiang->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
	//固定的npc对话
	std::string npcdialog="欢迎来到大夏世界";
	GBKToUTF8(npcdialog,"gb2312","utf-8");
	//std::string description ="asdadas"; ///DataManager::getInstance().getNpcConfigManager()->GetNPCDialog(dialogInfo->npcEntryId);
	dialogLabel->AddString(npcdialog, CH_WHITE, 0);
	dialogLabel->EnterPos();
	dialogLabel->EnterPos();

	std::vector<AnswerVO> answersBlank;
	answers.swap(answersBlank);
	//npc功能选项
	linkLabel->ResetContent();
	linkLabel->EnterPos();
	int startTag = 50;
	//std::vector<FunctionKey>::iterator itr = dialogInfo->values.begin();
	//for (;itr!=dialogInfo->values.end();itr++)
	{
		switch (startTag)//(*itr).key)
		{
		case NPC_DIALOG_TYPE_STORE://商店
			{
				/*linkLabel->AddString(InternationManager::getInstance().getCharacterText("dialog_text_0310").c_str(),CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_SHOP_NORMAL;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_INSTANCE_FENGXIAOXIA://风啸呷副本
			{
				//char str[_MAX_PATH_];
				//int tag = answers.size()+startTag;
				//linkLabel->AddString(GETSTR("jinrufengxiaoxia"), CH_GREEN, tag);
				////TODO：判断剩余次数
				//if (50>PlayerController::getInstance().getRoleData()->getLevel())
				//{
				//	memset(str, 0, sizeof(str));
				//	sprintf(str, "(%d%s)",50, GETSTR("CanEnter"));
				//	linkLabel->AddString(str, CH_RED, tag);
				//}
				//linkLabel->EnterPos();
				//AnswerVO answer;
				//answer.option = OPT_DOOR_LOOP_1;
				//answer.optVar = dialogInfo->npcEntryId;
				////answer.optData = trans;
				//answers.push_back(answer);
			}
			break;
		case NPC_DIALOG_TYPE_INSTANCE_HANFENGLING://寒风岭副本
			{				
				//char str[_MAX_PATH_];				
				//tTransmitConfigData* trans = DataManager::getInstance().getMapConfigManager()->getTransmitDataById(HANFENGLING_ENTER);
				//if (!trans)
				//{
				//	continue;
				//}
				//int tag = answers.size()+startTag;
				//linkLabel->AddString(trans->mapname, CH_GREEN, tag);
				////TODO：判断剩余次数
				//if (trans->needlevel>PlayerController::getInstance().getRoleData()->getLevel())
				//{
				//	memset(str, 0, sizeof(str));
				//	sprintf(str, "(%d%s)",trans->needlevel, GETSTR("CanEnter"));
				//	linkLabel->AddString(str, CH_RED, tag);
				//}
				//linkLabel->EnterPos();
				//AnswerVO answer;
				//answer.option = OPT_DOOR_LOOP;
				//answer.optVar = dialogInfo->npcEntryId;
				//answer.optData = trans;
				//answers.push_back(answer);
			}
			break;
		case NPC_DIALOG_TYPE_INSTANCE://副本
			{
				//std::vector<int>::iterator intItr = (*itr).value.begin();
				//char str[_MAX_PATH_];
				//int idx = 0;
				//for (;intItr!=(*itr).value.end();intItr++, idx++)
				//{
				//	tTransmitConfigData* trans = DataManager::getInstance().getMapConfigManager()->getTransmitDataById(*intItr);
				//	if (!trans)
				//	{
				//		continue;
				//	}
				//	int tag = answers.size()+startTag;
				//	linkLabel->AddString(trans->mapname, CH_GREEN, tag);
				//	//TODO：判断剩余次数
				//	if (trans->needlevel>PlayerController::getInstance().getRoleData()->getLevel())
				//	{
				//		memset(str, 0, sizeof(str));
				//		sprintf(str, "(%d%s)",trans->needlevel, GETSTR("CanEnter"));
				//		linkLabel->AddString(str, CH_RED, tag);
				//	}
				//	linkLabel->EnterPos();
				//	AnswerVO answer;
				//	answer.option = OPT_DOOR_NORMAL;
				//	answer.optVar = *intItr;
				//	answer.optData = trans;
				//	answers.push_back(answer);
				//}
			}
			break;
		case NPC_DIALOG_TYPE_TASK://任务
			{
				/*linkLabel->AddString(GETSTR("renwu2"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_TASK_LIST;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_LEARN_SKILL://学习技能
			{
				/*linkLabel->AddString(GETSTR("skill_label_0030"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_LEARN_SKILL;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_BUILD_GUILD://建帮会
			{
				/*linkLabel->AddString(GETSTR("buildguild"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_CREATE_GUILD;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_EMAIL://邮箱
			{
				/*linkLabel->AddString(GETSTR("visitorreg_text_0040"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_MAIL;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_EQUIP_STRENGTH://装备强化
			{
				/*linkLabel->AddString(GETSTR("equipqianghua"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_EQUIP_ENCHANT;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_STORAGE://仓库
			{
				/*linkLabel->AddString(GETSTR("cangku"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_STORAGE;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_TOWER_ENTER_SELECT://选择进入轮回塔层数
			{
				/*linkLabel->AddString(GETSTR("dialog_text_0320"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_TOWER_ENTER_SELECT;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_BATTLEREPORT://战  报
			{
				/*linkLabel->AddString(GETSTR("dialog_text_0330"),CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_BATTLEREPORT;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_EVERQUESTS_ENUM://日常任务
			{
				/*linkLabel->AddString(GETSTR("task_tree_0030"),CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = NPC_EVERQUESTS_ENUM;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_VIP://VIP
			{
				/*linkLabel->AddString("VIP", CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = VIP_NPC;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_EXCHANGE_NPC://兑换商店
			{
				/*linkLabel->AddString(GETSTR("dialog_text_0340"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = EXCHANGE_NPC;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_CHESS_SPIRIT_REQ_LOG://领取奖励 
			{
				/*linkLabel->AddString(GETSTR("dialog_text_0350"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = CHESS_SPIRIT_REQ_LOG;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);
				if (PlayerController::getInstance().getRoleData()->getLevel()>=40)
				{
					linkLabel->AddString(GETSTR("dialog_text_0360"), CH_GREEN, answers.size()+startTag);
					linkLabel->EnterPos();
					AnswerVO answer;
					answer.option = CHESS_SPIRIT_REQ_LOG;
					answer.optVar = dialogInfo->npcEntryId;
					answers.push_back(answer);
				}*/
			}
			break;
		case NPC_DIALOG_TYPE_ITEM_IDENTITY://坐骑鉴定与合成
			{
				/*linkLabel->AddString(GETSTR("dialog_text_0370"),CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = OPT_ITEM_IDENTITY;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		case NPC_DIALOG_TYPE_GUILD_TRANSPORTATION://开启仙门运镖
			{
				/*linkLabel->AddString(GETSTR("dialog_text_0380"), CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();
				AnswerVO answer;
				answer.option = GUILD_TRANSPORTATION;
				answer.optVar = dialogInfo->npcEntryId;
				answers.push_back(answer);*/
			}
			break;
		default:
			{
				/*char str[100];
				memset(str, 0, 100);
				sprintf(str, "npc function: %d", (*itr).key);
				linkLabel->AddString(str, CH_GREEN, answers.size()+startTag);
				linkLabel->EnterPos();*/
			}
			break;
		}
	}

	////日常任务选项添加
	//if (dialogInfo->everquests.size()>0)
	//{
	//	EverQuestConfigData* configData;
	//	std::vector<int>::iterator itr = dialogInfo->everquests.begin();
	//	for (;itr!=dialogInfo->everquests.end();itr++)
	//	{
	//		configData = DataManager::getInstance().getEverQuestConfigManager()->getEverQuestById(*itr);
	//		if (configData)
	//		{
	//			switch (configData->special_tag)
	//			{
	//			case EVER_QUEST_TYPE_NOMAL_TYPE://普通日常
	//				{
	//					linkLabel->AddString(configData->name,CH_GREEN, answers.size()+startTag);
	//					linkLabel->EnterPos();
	//					AnswerVO answer;
	//					answer.option = EVER_QUEST_TASK;
	//					answer.optVar = dialogInfo->npcEntryId;
	//					answer.optData = configData;
	//					answers.push_back(answer);
	//				}
	//				break;
	//			case EVER_QUEST_TYPE_TRANSPORTATION_TYPE://押镖
	//				{
	//					linkLabel->AddString(configData->name,CH_GREEN, answers.size()+startTag);
	//					linkLabel->EnterPos();
	//					AnswerVO answer;
	//					answer.option = TODAY_TRANSPORTATION;
	//					answer.optVar = dialogInfo->npcEntryId;
	//					answer.optData = configData;
	//					answers.push_back(answer);
	//				}
	//				break;
	//			case EVER_QUEST_TYPE_SHEN_XING_TYPE:
	//				{
	//					linkLabel->AddString(configData->name,CH_GREEN, answers.size()+startTag);
	//					linkLabel->EnterPos();
	//					AnswerVO answer;
	//					answer.option = EVER_QUEST_TASK;
	//					answer.optVar = dialogInfo->npcEntryId;
	//					answer.optData = configData;
	//					answers.push_back(answer);
	//				}
	//				break;
	//			}
	//		}
	//	}
	//}

	////添加任务的link
	//std::vector<int>::iterator qItr = dialogInfo->quests.begin();
	//for (;qItr!=dialogInfo->quests.end();qItr++)
	//{
	//	TaskInfo* taskInfo = TaskController::getInstance().GetTask(*qItr);
	//	if (taskInfo)
	//	{
	//		AnswerVO answer;
	//		answer.str = taskInfo->m_taskDetail.m_titlett;
	//		answer.option = OPT_TASK_RUN;
	//		answer.optData = taskInfo;
	//		answer.taskState = getTaskStateStrByState(taskInfo->status);

	//		linkLabel->AddString(taskInfo->m_taskDetail.m_titlett, CH_GREEN, answers.size()+startTag);
	//		linkLabel->AddString(answer.taskState, CH_GREEN, answers.size()+startTag);
	//		linkLabel->EnterPos();

	//		answers.push_back(answer);
	//	}
	//}

	//刷新显示位置
	if (tableView)
	{
		int dialogLabelHeight = abs(dialogLabel->GetCurrentHeight());
		int linkLabelHeight = abs(linkLabel->GetCurrentHeight());
		int h = dialogLabelHeight+linkLabelHeight+nameHeight;
		h = h>tableViewSize.height?h:tableViewSize.height;
		npcName->setPosition(ccp(0,h-nameHeight));
		dialogLabel->setPosition(ccp(0, h-nameHeight));
		dialogLabel->setVisible(true);
		fengexian->setPosition(ccp(tableViewSize.width/2,h-dialogLabelHeight-nameHeight));
		linkLabel->setPosition(ccp(0, h-dialogLabelHeight-nameHeight));
		linkLabel->setVisible(true);
		if (tableView)
		{
			tableView->reloadData();
		}
	}
}
FunctionNPC* NpcDialog::getDialogInfo()
{
	return dialogInfo;
}
void NpcDialog::tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
{
}
CCSize NpcDialog::cellSizeForTable(cocos2d::extension::TableView *table)
{
	int h=abs(dialogLabel->GetCurrentHeight())+abs(linkLabel->GetCurrentHeight())+nameHeight;
	int h1=h>tableViewSize.height?h:tableViewSize.height;
	return CCSizeMake(tableViewSize.width,h1);
}
TableViewCell* NpcDialog::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
	cell = table->dequeueCell();
	if (!cell)
	{
		cell = new TableViewCell();
		cell->autorelease();
		if (npcName)cell->addChild(npcName);
		if (dialogLabel) cell->addChild(dialogLabel);
		if (fengexian) cell->addChild(fengexian);
		if (linkLabel) cell->addChild(linkLabel);
	}
	return cell;
}
ssize_t NpcDialog::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
	return 1;
}
void NpcDialog::tableCellHighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
{
	isHighlight = true;
}
void NpcDialog::tableCellUnhighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
{
	linkLabel->onTouchCancelled(NULL, NULL);
	isHighlight = false;
}

void NpcDialog::updateTaskAnswer( int taskId )
{
	/*TaskInfo* taskInfo = TaskController::getInstance().GetTask(taskId);
	if (taskInfo)
	{
	AnswerVO answer;
	answer.str = taskInfo->m_taskDetail.m_strFileName;
	answer.option = OPT_TASK_REQUEST;
	answer.optData = taskInfo;
	answer.taskState = getTaskStateStrByState(taskInfo->status);
	taskAnswers[taskId] = answer;
	}*/
}
