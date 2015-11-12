#include "TaskDialog.h"
#include "GameDefine.h"
#include "GameGobal.h"
#include "SceneController.h"
#include "TaskController.h"
#include "PlayerController.h"
#include "DataManager.h"
#include "UIDefine.h"
USING_NS_CC;
USING_NS_CC_EXT;

//钱币类型
#define MONEY_BIND_TYPE		1//绑定钱币
#define MONEY_NO_BIND_TYPE	6//钱　　币
#define MONEY_GUILD_DEVOTE	10//门　　贡
#define TASKDIALOG_BG_TAG   123

#define FENGEXIAN_ZORDER    1//分割线的Z
#define MENU_ZORDER         1//按钮的Z

TaskDialog::TaskDialog(void)
{
	tableView = NULL;
	tableViewCellNode = NULL;
	currentTaskInfo = NULL;
	touxiang = NULL;
	setVisible(false);
	setCanTween(false);
	TaskController::getInstance().setTaskDialog(this);
}
TaskDialog::~TaskDialog(void)
{
	CC_SAFE_RELEASE(tableViewCellNode);
	TaskController::getInstance().setTaskDialog(NULL);
}
void TaskDialog::initPanel()
{
	WINSIZE;
	int w = 600;
	int h = 350;

	float border=20.0f;//间隙
	float liaotianExtern=30.0f;//聊天框的格外宽度(那个角)
	nameHeight=30.0f;//名称高度
	setAnchorPoint(ccp(0.5f,0.5f));
	setContentSize(CCSizeMake(w,h));
	setPosition(ccp(winSize.width/2,winSize.height/2));

	//背景
	Scale9Sprite *bg=Scale9Sprite::createWithSpriteFrameName(DIALOG_BG,DIALOG_BG_CCRect);
	bg->setContentSize(getContentSize());
	bg->setAnchorPoint(Point::ZERO);
	bg->setTag(TASKDIALOG_BG_TAG);
	addChild(bg);

	//聊天框
	Scale9Sprite *liaotian=Scale9Sprite::createWithSpriteFrameName(DIALOG_LIAOTIAN,DIALOG_LIAOTIAN_CCRect);
	liaotian->setContentSize(CCSizeMake(w/4*3,h-border*2));
	liaotian->setAnchorPoint(Point::ZERO);
	liaotian->setPosition(getContentSize().width-border-liaotian->getContentSize().width,border);
	addChild(liaotian);

	//头像
	char str[50];
	if (currentTaskInfo->status==QUEST_STATUS_COMPLETE)
	{
		std::sprintf(str,"%d.png",currentTaskInfo->m_taskDetail.m_completeNPC);
	}
	else
	{
        std::sprintf(str,"%d.png",currentTaskInfo->m_taskDetail.m_anwserNPC);
	}

	touxiang=CCSprite::createWithSpriteFrameName(str);
	touxiang->setAnchorPoint(Point::ZERO);
	touxiang->setPosition(ccp(25,200));
	addChild(touxiang);

	taskDetailStr = InternationManager::getInstance().getCharacterText("task_label_0070");
	taskAwardStr = InternationManager::getInstance().getCharacterText("task_label_0100");//任务奖励
	maohaoStr = InternationManager::getInstance().getCharacterText("maohao");
	expStr = InternationManager::getInstance().getCharacterText("general_label_0038");//经验
	finishStr = InternationManager::getInstance().getCharacterText("dialog_text_0030");
	leaveStr = InternationManager::getInstance().getCharacterText("dialog_text_0020");
	acceptStr = InternationManager::getInstance().getCharacterText("dialog_text_0440");

	//显示元素
	tableViewCellNode = Node::create();
	tableViewCellNode->autorelease();
	CC_SAFE_RETAIN(tableViewCellNode);

	//分割线
	fengexian=CCSprite::createWithSpriteFrameName("dialog_fengexian.png");
	tableViewCellNode->addChild(fengexian,FENGEXIAN_ZORDER);

	//任务标题
	cocos2d::CCLabelTTF* taskTitle = cocos2d::CCLabelTTF::create("leenini", FONT_NAME_DEFAULT, 26, Size::ZERO, kCCTextAlignmentLeft);
	taskTitle->setAnchorPoint(ccp(0.5f,0));
	taskTitle->setPosition(ccp(w/2, h-50));
	taskTitle->setTag(10);
	taskTitle->setColor(CH_GREEN);

	Scale9Sprite* s9sNormal;
	Scale9Sprite* s9sSelected;
	CCSize btnSize = CCSize(100, 45);
	CCRect btnRect = Rect(30,8,30,9);
	const char* normalStr = "button.png";
	const char* selectedStr = "button.png";

	//接收任务按钮
	s9sNormal = Scale9Sprite::createWithSpriteFrameName(normalStr, btnRect);
	s9sNormal->setContentSize(btnSize);
	s9sSelected = Scale9Sprite::createWithSpriteFrameName(selectedStr, btnRect);
	s9sSelected->setContentSize(btnSize);
	WXSimpleButton* rightBtn = WXSimpleButton::createWithNode(s9sNormal, s9sSelected, NULL, "RIGHT");
	rightBtn->setTarget(this, menu_selector(TaskDialog::btnCallback));
	rightBtn->setPosition(ccp(getContentSize().width-border*3/2-rightBtn->getContentSize().width/2,rightBtn->getContentSize().height/2+border*3/2));
	rightBtn->setTag(2);

	//关闭按钮
	WXSimpleButton* close_button = WXSimpleButton::createWithSpriteFrameName(CLOSE_BTN_45_45_NORMAL,CLOSE_BTN_45_45_SELECTED,this,menu_selector(TaskDialog::btnCallback));
	close_button->setPosition(w-GAP*2,h-GAP*2);
	close_button->setTag(1);

	WXMenu* menu = WXMenu::create(rightBtn,close_button, NULL);
	menu->setAnchorPoint(Point::ZERO);
	menu->setPosition(Point::ZERO);
	menu->setTag(1000);
	//menu->alignItemsHorizontallyWithPadding(150);
	addChild(menu,MENU_ZORDER);

	tableViewSize = CCSizeMake(liaotian->getContentSize().width-liaotianExtern-border*2, liaotian->getContentSize().height
		-border*2);

	//awardLabel=WXRichLabelEx::create();
	//awardLabel->Initialize(FONT_ALIAS_DEFAULT_20, tableViewSize);
	//awardLabel->setVisible(false);
	//awardLabel->setPosition(liaotian->getPositionX()+liaotianExtern+border,liaotian->getContentSize().height/2+border/2);
	//this->addChild(awardLabel);

	//任务奖励
	bounsGridPanel = WXGridPanel::create();
	std::vector<CCPoint> tplist;
	tplist.push_back(ccp(100, 0));
	tplist.push_back(ccp(200, 0));
	tplist.push_back(ccp(300, 0));
	tplist.push_back(ccp(400, 0));
	bounsGridPanel->createGrids(tplist, GRID_BG, NULL, NULL);
	tableViewCellNode->addChild(bounsGridPanel);

	tableView = WXTableView::create(this, tableViewSize);
	tableView->setDirection(ScrollView::Direction::VERTICAL);
	tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	tableView->setDelegate(this);
	tableView->setPosition(ccp(liaotian->getPositionX()+liaotianExtern+border,liaotian->getPositionY()+border));
	addChild(tableView);
}
void TaskDialog::btnCallback(CCObject* pSender)
{
	if( currentTaskInfo==NULL )
		return;
	WXSimpleButton* btn = dynamic_cast<WXSimpleButton*>(pSender);
	if (btn->getTag()==2)
	{
		if( currentTaskInfo->status == QUEST_STATUS_COMPLETE )
			TaskController::getInstance().taskComplete(currentTaskInfo);		//发送完成
		else if( currentTaskInfo->status == QUEST_STATUS_INCOMPLETE )
			;
		else if( currentTaskInfo->status == QUEST_STATUS_AVAILABLE )
			TaskController::getInstance().taskAccept(currentTaskInfo);			//接任务
		else if( currentTaskInfo->status == QUEST_STATUS_UNAVAILABLE )
			;
		else
			;
		if (isShow())
		{
			toggle();
		}
	}
	else
	{
		if (isShow())
		{
			toggle();
		}
	}
	nextGuidStep();
}
TaskInfo* TaskDialog::getCurrentTaskInfo()
{
	return currentTaskInfo;
}
void TaskDialog::setCurrentTaskInfo( TaskInfo* var )
{
	currentTaskInfo = var;
	if (!isShow())
	{
		toggle();
	}
	if (!var)
	{
		return;
	}
	//cocos2d::CCLabelTTF* taskTitle = dynamic_cast<cocos2d::CCLabelTTF*>(getChildByTag(10));
	//if (taskTitle)
	//{
	//	taskTitle->setString(var->m_taskDetail.m_titlett.c_str());
	//}
	//头像
	char str[50];
	if (currentTaskInfo->status==QUEST_STATUS_COMPLETE)
	{
		std::sprintf(str,"%d.png",currentTaskInfo->m_taskDetail.m_completeNPC);
	}
	else
	{
		std::sprintf(str,"%d.png",currentTaskInfo->m_taskDetail.m_anwserNPC);
	}
	touxiang->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
	WXRichLabelEx* taskLabel = WXRichLabelEx::create();
	taskLabel->Initialize(FONT_ALIAS_DEFAULT_24,24, tableViewSize);
	WXRichLabelEx* oldTaskLabel = dynamic_cast<WXRichLabelEx*>(tableViewCellNode->getChildByTag(50));
	if (oldTaskLabel)
	{
		tableViewCellNode->removeChild(oldTaskLabel, true);
	}
	taskLabel->setTag(50);
	taskLabel->setVisible(true);
	tableViewCellNode->addChild(taskLabel);

	taskLabel->AddString(var->m_taskDetail.m_titlett.c_str(), CH_YELLOW, 0);
	taskLabel->EnterPos();
	if (var->status==QUEST_STATUS_AVAILABLE)
	{
		taskLabel->AddString(var->m_taskDetail.m_ot_q.c_str(), CH_WHITE, 0);
	}
	else if (var->status==QUEST_STATUS_COMPLETE)
	{
		taskLabel->AddString(var->m_taskDetail.m_et_q.c_str(), CH_WHITE, 0);
	}
	else if (var->status==QUEST_STATUS_INCOMPLETE)
	{
		taskLabel->AddString(var->m_taskDetail.m_it_q.c_str(),CH_WHITE,0);
	}
	//taskLabel->AddString(var->m_taskDetail.m_it_q, ccMAGENTA, 0);
	//tableViewCellNode->setContentSize(CCSizeMake(tableViewSize.width, abs(taskLabel->GetCurrentHeight())));
	//awardLabel->ResetContent();
	taskLabel->EnterPos();
	taskLabel->EnterPos();
	int middleHeight=abs(taskLabel->GetCurrentHeight());
	if(var->status!=QUEST_STATUS_INCOMPLETE)//如果任务不是未完成,再提示奖励信息
	{
		taskLabel->EnterPos();
		taskLabel->AddString(taskAwardStr.c_str(), CH_YELLOW, 0);
		taskLabel->EnterPos();

		char str[_MAX_PATH_];
		if (var->m_taskDetail.m_money_num>0)
		{
			switch (var->m_taskDetail.m_money_type)
			{
			case MONEY_BIND_TYPE:
				taskLabel->AddString((GETSTR("general_label_0036")+maohaoStr).c_str(), CH_YELLOW, 0);
				break;
			case MONEY_NO_BIND_TYPE:
				taskLabel->AddString((GETSTR("general_label_0037")+maohaoStr).c_str(), CH_YELLOW, 0);
				break;
			case MONEY_GUILD_DEVOTE:
				taskLabel->AddString((GETSTR("general_label_0039")+maohaoStr).c_str(), CH_YELLOW, 0);
				break;
			}
			memset(str, 0, sizeof(str));
			sprintf(str, "%d", var->m_taskDetail.m_money_num);
			taskLabel->AddString(str, CH_WHITE, 0);
			taskLabel->EnterPos();
		}
		if (var->m_taskDetail.m_exp_num>0)
		{
			taskLabel->AddString(expStr+maohaoStr, CH_YELLOW, 0);
			memset(str, 0, sizeof(str));
			sprintf(str, "%d", var->m_taskDetail.m_exp_num);
			taskLabel->AddString(str, CH_WHITE, 0);
			taskLabel->EnterPos();
			taskLabel->EnterPos();
		}

		std::vector<WXGrid*>::iterator gridItr = bounsGridPanel->getAllGrid()->begin();
		for (;gridItr!=bounsGridPanel->getAllGrid()->end();gridItr++)
		{
			(*gridItr)->setVisible(false);
		}
		gridItr = bounsGridPanel->getAllGrid()->begin();
		/*if (var->m_taskDetail.m_goods_id>0)
		{
		tGridData tgd;
		tgd.isActive = true;
		tgd.num = var->m_taskDetail.m_goods_num;
		tgd.pos = 0;
		tgd.id=var->m_taskDetail.m_goods_id;
		ItemConfigData* cid = DataManager::getInstance().getItemConfigManager()->getOneData(var->m_taskDetail.m_goods_id);
		if (!cid)
		{
		sprintf(str, "%s", GRID_BLANK_FILENAME);
		}
		else
		{
		sprintf(str, "ui/itemimage/%d.pvr.ccz", cid->displayid);
		}
		tgd.url = str;
		(*gridItr)->updateGrid(tgd);
		(*gridItr)->setVisible(true);
		}*/
		int y = abs(taskLabel->GetCurrentHeight());
		fengexian->setPosition(ccp(tableViewSize.width/2,-middleHeight));
		y = y+(*gridItr)->getContentSize().height;
		bounsGridPanel->setPosition(ccp(0,-y+(*gridItr)->getContentSize().height/2));
		tableViewCellNode->setContentSize(CCSizeMake(tableViewSize.width, y));
	}
	else//如果任务是未完成的,不显示
	{
		std::vector<WXGrid*>::iterator gridItr = bounsGridPanel->getAllGrid()->begin();
		for (;gridItr!=bounsGridPanel->getAllGrid()->end();gridItr++)
		{
			(*gridItr)->setVisible(false);
		}
	}
	WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
	if (menu)
	{
		//WXSimpleButton* leftBtn = dynamic_cast<WXSimpleButton*>(menu->getChildByTag(1));
		//if (leftBtn)
		//{
		//	leftBtn->setVisible(false);
		//}
		WXSimpleButton* rightBtn = dynamic_cast<WXSimpleButton*>(menu->getChildByTag(2));
		if (rightBtn)
		{
			//任务状态
			if( var->status == QUEST_STATUS_COMPLETE )
			{
				rightBtn->setString(finishStr.c_str());
			}
			else if( var->status == QUEST_STATUS_INCOMPLETE )
			{
				rightBtn->setString(leaveStr.c_str());
			}
			else if( var->status == QUEST_STATUS_AVAILABLE )
			{
				rightBtn->setString(acceptStr.c_str());
			}
			else
			{
				rightBtn->setString(leaveStr.c_str());
			}
		}
	}
	if (tableView)
	{
		tableView->reloadData();
	}
}
void TaskDialog::show(bool isShow)
{
	WXPanel::show(isShow);
	if (isShow)
	{
		WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
		WXSimpleButton* rightBtn = dynamic_cast<WXSimpleButton*>(menu->getChildByTag(2));
		CCPoint worldPos = rightBtn->convertToWorldSpace(Point::ZERO);
		/*GameGobal::getInstance().getGameUILayer()->getNoobPanel()->getNoobGuidePanel()->setIsShowMask(false);
		PlayerController::getInstance().getNoobManager()->openTaskDialog(CCRectMake(worldPos.x-4,worldPos.y-4,rightBtn->getContentSize().width+8,rightBtn->getContentSize().height+8));*/
	}
	else
	{
		finishGuideStep();
	}
}
//void TaskDialog::tweenCallback()
//{
//	WXPanel::tweenCallback();
//	WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
//	WXSimpleButton* rightBtn = dynamic_cast<WXSimpleButton*>(menu->getChildByTag(2));
//	CCPoint worldPos = rightBtn->convertToWorldSpace(CCPointZero);
//	PlayerController::getInstance().getNoobManager()->openTaskDialog(CCRectMake(worldPos.x-4,worldPos.y-4,rightBtn->getContentSize().width+8,rightBtn->getContentSize().height+8));
//}
// std::string  TaskDialog::GetDialogTitleText(TaskInfo* v)
// {
// 	std::string str,strReturn;
// 	str = v->m_taskDetail.m_titlett;
// 	char buf[_MAX_PATH_];
// 	memset(buf,0,_MAX_PATH_);
// 	//主支线
// 	if( v->m_taskDetail.m_ramus == 1 )
// 		strReturn = InternationManager::getInstance().getCharacterText("ramus1").c_str();
// 	else
// 		strReturn = InternationManager::getInstance().getCharacterText("ramus").c_str();
// 	strReturn=str+strReturn;
// 
// 	return strReturn;
// }
void TaskDialog::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return;
	}
	WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
	if (menu)
	{
		menu->onTouchMoved(pTouch, pEvent);
	}
	tableView->onTouchMoved(pTouch, pEvent);
}
void TaskDialog::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return;
	}
	WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
	if (menu)
	{
		menu->onTouchCancelled(pTouch, pEvent);
	}
	tableView->onTouchCancelled(pTouch, pEvent);
}
bool TaskDialog::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return false;
	}
	if (closeBtnTouchEnded(pTouch,pEvent))
	{
		tween(false);
		return true;
	}
	tableView->onTouchEnded(pTouch, pEvent);
	WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
	if (menu && menu->onTouchEnded(pTouch, pEvent))
	{
		return true;
	}

	CCPoint touchPos=this->convertTouchToNodeSpace(pTouch);
	CCRect bg_rect=getChildByTag(TASKDIALOG_BG_TAG)->boundingBox();
	if (bg_rect.containsPoint(touchPos))
	{
		std::vector<WXGrid*>::iterator itr;
		for (itr=bounsGridPanel->getAllGrid()->begin();itr!=bounsGridPanel->getAllGrid()->end();itr++)
		{
			if ((*itr)->isVisible())
			{
				CCRect goods_rect=(*itr)->boundingBox();
				goods_rect.origin.x=goods_rect.origin.x-(*itr)->getContentSize().width/2;
				goods_rect.origin.y=goods_rect.origin.y-(*itr)->getContentSize().height/2;
				CCPoint goods_point=(*itr)->getParent()->convertTouchToNodeSpace(pTouch);
				if (goods_rect.containsPoint(goods_point))
				{
					hitGrid=*itr;
					touchWorldPoint=this->convertToWorldSpace(convertTouchToNodeSpace(pTouch));
					this->unschedule(schedule_selector(TaskDialog::updateTipsPanel));
					this->schedule(schedule_selector(TaskDialog::updateTipsPanel),0.3f);
					return true;
				}
			}
		}
	}
	return WXPanel::onTouchEnded(pTouch, pEvent);
}
bool TaskDialog::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return false;
	}
	if (closeBtnTouchBegan(pTouch,pEvent))
	{
		return true;
	}
	WXMenu* menu = dynamic_cast<WXMenu*>(getChildByTag(1000));
	if (menu && menu->onTouchBegan(pTouch, pEvent))
	{
		return true;
	}
	if (tableView->onTouchBegan(pTouch, pEvent))
	{
		return true;
	}
	return WXPanel::onTouchBegan(pTouch, pEvent);
}
void TaskDialog::tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
{
}
CCSize TaskDialog::cellSizeForTable(cocos2d::extension::TableView *table)
{
	int h = tableViewSize.height;
	if (tableViewCellNode)
	{
		int h2 = tableViewCellNode->getContentSize().height;
		h = h>h2?h:h2;
	}
	return CCSizeMake(tableViewSize.width, h);
}
TableViewCell* TaskDialog::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
	TableViewCell *cell = table->dequeueCell();
	if (!cell)
	{
		cell = new TableViewCell();
		cell->autorelease();
		if (tableViewCellNode)
		{
			tableViewCellNode->setTag(10);
			int h = tableViewCellNode->getContentSize().height;
			h = h>tableViewSize.height?h:tableViewSize.height;
			tableViewCellNode->setPosition(ccp(0, h));
			cell->addChild(tableViewCellNode);
		}
	}
	else
	{
		int h = tableViewCellNode->getContentSize().height;
		h = h>tableViewSize.height?h:tableViewSize.height;
		tableViewCellNode->setPosition(ccp(0, h));
	}
	return cell;
}
ssize_t TaskDialog::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
	return 1;
}
void TaskDialog::updateTipsPanel(float dt)
{
	//GameGobal::getInstance().getGameUILayer()->getTipsPanel()->showTipByItemId(hitGrid->getGridData().id,touchWorldPoint);
	this->unschedule(schedule_selector(TaskDialog::updateTipsPanel));
}

void TaskDialog::startGuideStep()
{

}	

void TaskDialog::nextGuidStep()
{
	//finishGuideStep();
}
