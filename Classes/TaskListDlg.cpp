//#include "TaskListDlg.h"
//#include "GameGobal.h"
//#include "UIDefine.h"
//#include "TaskController.h"
//#include "SceneController.h"
////#include "NpcConfigManager.h"
//#include "DataManager.h"
//USING_NS_CC;
//USING_NS_CC_EXT;
//
//std::vector<std::string> splitString(std::string str, char splitChar)
//{
//	std::vector<std::string> result;
//	int size = str.size();
//	int pos;
//	for (int i=0;i<size;i++)
//	{
//		pos = str.find(splitChar, i);
//		if (pos<size)
//		{
//			result.push_back(str.substr(i, pos-i));
//			i = pos;
//		}
//		if (pos==str.npos)
//		{
//			break;
//		}
//	}
//	return result;
//}
//void getTrackLinkData(std::vector<tTrackLinkData>& tldList, std::string& str, char frontSplit, char middleSplit, char backSplit, int type)
//{
//	int startPos = 0;
//	int endPos = 0;
//	int lastStartPos = 0;
//	int lastEndPos = 0;
//	std::string value;
//	do //目标npc
//	{
//		startPos = str.find(frontSplit);
//		endPos = str.find(backSplit);
//		if (startPos==str.npos || endPos==str.npos || endPos<startPos)
//		{
//			return;
//		}
//		lastStartPos = startPos;
//		lastEndPos = endPos;
//		value = str.substr(startPos+1, endPos-startPos-1);
//
//		tTrackLinkData tld;
//		std::vector<std::string> splitResult = splitString(value, middleSplit);
//		switch (type)
//		{
//		case 1:
//			{
//				if (splitResult.size()!=2)
//				{
//					break;
//				}
//				std::vector<std::string>::iterator itr = splitResult.begin();
//				tld.type = 1;
//				tld.showStr = (*itr);
//				tld.linkStr = "";
//				tld.value = atoi((*(itr+1)).c_str());
//				tld.value2 = 0;
//				tld.startPos = lastStartPos;
//				tld.endPos = lastEndPos;
//				tldList.push_back(tld);
//			}
//			break;
//		case 2:
//			{
//				if (splitResult.size()!=2)
//				{
//					break;
//				}
//				std::vector<std::string>::iterator itr = splitResult.begin();
//				tld.type = 2;
//				tld.showStr = (*itr);
//				tld.linkStr = "";
//				tld.value = atoi((*(itr+1)).c_str());
//				tld.value2 = 0;
//				tld.startPos = lastStartPos;
//				tld.endPos = lastEndPos;
//				tldList.push_back(tld);
//			}
//			break;
//		case 3:
//			{
//				if (splitResult.size()!=3)
//				{
//					break;
//				}
//				std::vector<std::string>::iterator itr = splitResult.begin();
//				tld.type = 3;
//				tld.showStr = (*itr);
//				tld.linkStr = (*(itr+1));
//				tld.value = atoi((*(itr+2)).c_str());
//				tld.value2 = 0;
//				tld.startPos = lastStartPos;
//				tld.endPos = lastEndPos;
//				tldList.push_back(tld);
//			}
//			break;
//		case 4:
//			{
//				if (splitResult.size()!=4)
//				{
//					break;
//				}
//				std::vector<std::string>::iterator itr = splitResult.begin();
//				tld.type = 4;
//				tld.showStr = (*itr);
//				tld.linkStr = (*(itr+1));
//				tld.value = atoi((*(itr+2)).c_str());
//				tld.value2 = atoi((*(itr+3)).c_str());
//				tld.startPos = lastStartPos;
//				tld.endPos = lastEndPos;
//				tldList.push_back(tld);
//			}
//			break;
//		}
//		str = str.substr(endPos+1);
//	} while (1);
//}
//std::vector<tTrackLinkData> getTrackLinkDataFromStr(std::string str)
//{
//	std::vector<tTrackLinkData> tldList;
//	getTrackLinkData(tldList, str, '{', ',', '}', 2);
//	getTrackLinkData(tldList, str, '<', ',', '>', 3);
//	getTrackLinkData(tldList, str, '[', ',', ']', 4);
//	getTrackLinkData(tldList, str, '(', ',', ')', 1);
//	return tldList;
//}
//
//TaskListDlg::TaskListDlg(void)
//{
//	setCanTween(false);
//	tableViewCellNode = NULL;
//	tableView = NULL;
//	selectedLabel = NULL;
//	TaskController::getInstance().setTaskListDlg(this);
//}
//TaskListDlg::~TaskListDlg(void)
//{
//	CC_SAFE_RELEASE(tableViewCellNode);
//	TaskController::getInstance().setTaskListDlg(NULL);
//}
//bool TaskListDlg::init(int w, int h)
//{
//	setAnchorPoint(CCPointZero);
//	setContentSize(CCSizeMake(w, h));
//	setVisible(false);
//	TaskController::getInstance().initTaskListDlg();
//	return true;
//}
//void TaskListDlg::initPanel()
//{
//	WINSIZE;
//	int w = getContentSize().width;
//	int h = getContentSize().height;
//
//	ramus1Str = GETSTR("ramus1");
//	ramusStr = GETSTR("ramus");
//	ramus2Str = GETSTR("ramus2");
//	taskFinishStr = GETSTR("taskFinish");
//	taskUnFinishStr = GETSTR("taskUnFinish");
//	taskAvailableStr=GETSTR("taskAvailabel");
//	taskVisit=GETSTR("visit");
//
//	tableViewCellNode = Node::create();
//	tableViewCellNode->autorelease();
//	CC_SAFE_RETAIN(tableViewCellNode);
//	tableViewCellNode->setContentSize(CCSizeMake(w, 10));
//
//	tableViewSize = CCSizeMake(w, h);
//	tableView = WXTableView::create(this, tableViewSize);
//	tableView->setDirection(ScrollView::Direction::VERTICAL);
//	tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
//	tableView->setDelegate(this);
//	addChild(tableView);
//}
//void TaskListDlg::onTouchMoved(Touch *pTouch, Event *pEvent)
//{
//	if (!isVisible())
//		return;
//	if (tableView)
//		tableView->onTouchMoved(pTouch, pEvent);
//}
//void TaskListDlg::onTouchCancelled(Touch *pTouch, Event *pEvent)
//{
//	if (!isVisible())
//		return;
//	if (tableView)
//		tableView->onTouchCancelled(pTouch, pEvent);
//}
//bool TaskListDlg::onTouchEnded(Touch *pTouch, Event *pEvent)
//{
//	if (!isVisible())
//		return false;
//	bool bRet = false;
//	if (tableView)
//	{
//		if (isHighlight)
//		{
//			std::vector<tTrackItem>::iterator itr = trackList.begin();
//			for (;itr!=trackList.end();itr++)
//			{
//				if ((*itr).label->onTouchEnded(pTouch, pEvent))
//				{
//					if (selectedLabel==(*itr).label)
//					{
//						clickCallback((*itr).taskId);
//					}
//					bRet = true;
//					break;
//				}
//			}
//		}
//		tableView->onTouchEnded(pTouch, pEvent);
//	}
//	if (selectedLabel)
//	{
//		selectedLabel->showBGColor(false);
//		selectedLabel = NULL;
//	}
//	if (bRet)
//	{
//		return true;
//	}
//	return WXPanel::onTouchEnded(pTouch, pEvent);
//}
//bool TaskListDlg::onTouchBegan(Touch *pTouch, Event *pEvent)
//{
//	if (!this->isVisible())
//		return false;
//	if (tableView && tableView->onTouchBegan(pTouch, pEvent))
//	{
//		if (isHighlight)
//		{
//			std::vector<tTrackItem>::iterator itr = trackList.begin();
//			for (;itr!=trackList.end();itr++)
//			{
//				if ((*itr).label->onTouchBegan(pTouch, pEvent))
//				{
//					selectedLabel = (*itr).label;
//					selectedLabel->showBGColor(true);
//					return true;
//				}
//			}
//		}
//		return true;
//	}
//	return WXPanel::onTouchBegan(pTouch, pEvent);
//}
//void TaskListDlg::tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
//{
//	//CCLOG("cell touched at index: %i", cell->getIdx());
//}
//void TaskListDlg::tableCellHighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
//{
//	isHighlight = true;
//}
//void TaskListDlg::tableCellUnhighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)
//{
//	isHighlight = false;
//}
//CCSize TaskListDlg::cellSizeForTable(cocos2d::extension::TableView *table)
//{
//	int h = tableViewSize.height;
//	int h2 = tableViewCellNode->getContentSize().height;
//	h = h>h2?h:h2;
//	return CCSizeMake(tableViewSize.width, h);
//}
//TableViewCell* TaskListDlg::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
//{
//	TableViewCell *cell = table->dequeueCell();
//	if (!cell)
//	{
//		cell = new TableViewCell();
//		cell->autorelease();
//		cell->addChild(tableViewCellNode);
//	}
//	return cell;
//}
//ssize_t TaskListDlg::numberOfCellsInTableView(cocos2d::extension::TableView *table)
//{
//	return 1;
//}
//void TaskListDlg::updateTaskItem(TaskInfo* taskInfo, tTrackItem& trackItem)
//{
//	if (!taskInfo || !trackItem.label)
//	{
//		return;
//	}
//	trackItem.label->ResetContent();
//	if (taskInfo->m_taskDetail.m_ramus==1)
//	{
//		trackItem.label->AddString(ramus1Str.c_str(), CH_GREEN, 0);
//	}
//	else if(taskInfo->m_taskDetail.m_ramus==2)
//	{
//		trackItem.label->AddString(ramusStr.c_str(), CH_GREEN, 0);
//	}
//	else if (taskInfo->m_taskDetail.m_ramus==3)
//	{
//		trackItem.label->AddString(ramus2Str.c_str(),CH_GREEN,0);
//	}
//	trackItem.label->AddString(taskInfo->m_taskDetail.m_titlett.c_str(), CH_YELLOW, 0);
//	trackItem.label->EnterPos();
//	std::string linkStr;
//	if (taskInfo->status==QUEST_STATUS_COMPLETE)
//	{
//		trackItem.label->AddString(taskFinishStr.c_str(), CH_GREEN, 0);
//		linkStr = taskInfo->m_taskDetail.m_track_comp;
//	}
//	else if(taskInfo->status==QUEST_STATUS_INCOMPLETE)
//	{
//		trackItem.label->AddString(taskUnFinishStr.c_str(), CH_RED, 0);
//		linkStr = taskInfo->m_taskDetail.m_track_tar;
//	}
//	else if (taskInfo->status==QUEST_STATUS_AVAILABLE)
//	{
//		trackItem.label->AddString(taskAvailableStr.c_str(),CH_GREEN,0);
//		int npcEntryID=taskInfo->m_taskDetail.m_anwserNPC;
//		std::string npcName=DataManager::getInstance().getNpcConfigManager()->GetNPCName(npcEntryID);
//		char str[_MAX_PATH_];
//		memset(str,0,sizeof(str));
//		sprintf(str,"%s(%s,%d)",taskVisit.c_str(),npcName.c_str(),npcEntryID);
//		linkStr=str;
//		//linkStr=taskInfo->m_taskDetail.m_track_comp;
//	}
//	trackItem.label->EnterPos();
//
//	std::vector<tTrackLinkData> trackLinkList = getTrackLinkDataFromStr(linkStr);
//	std::vector<tTrackLinkData>::iterator linkItr = trackLinkList.begin();
//	unsigned int startPos = 0;
//	int index = 1;
//	char str[_MAX_PATH_];
//	std::vector<TaskTarget>::iterator ttItr;
//	int targetIndex = 0;//目标怪的索引
//	for (;linkItr!=trackLinkList.end();linkItr++, index++)
//	{
//		trackItem.label->AddString(linkStr.substr(startPos, (*linkItr).startPos).c_str(), ccc3(255,0,255), 0);
//		//int tag = index+taskInfo->questID;
//		//trackItem.label->AddString((*linkItr).showStr, ccc3(0,255,255), tag);
//		trackItem.label->AddString((*linkItr).showStr.c_str(), ccc3(0,255,255), 0);//(不用超链接)
//		if ((linkItr+1)==trackLinkList.end())
//		{
//			trackItem.label->AddString(linkStr.substr(startPos+(*linkItr).endPos+1).c_str(),ccc3(255,0,255),0);
//		}
//		if ((*linkItr).type==1)//怪物
//		{
//			targetIndex = 0;
//			for (ttItr=taskInfo->m_taskDetail.m_target.begin();ttItr!=taskInfo->m_taskDetail.m_target.end();ttItr++, targetIndex++)
//			{
//				if (ttItr->m_objsID==(*linkItr).value)//同样是目标怪
//				{
//					memset(str, 0, sizeof(str));
//					sprintf(str, "(%d/%d)", *(taskInfo->values.begin()+targetIndex), (*ttItr).m_objsCount);
//					trackItem.label->AddString(str, ccc3(255,0,255), 0);
//					break;
//				}
//			}
//		}
//		trackItem.linkDataDic.insert(std::map<int, tTrackLinkData>::value_type(taskInfo->questID, *linkItr));
//		startPos = (*linkItr).endPos+1;
//	}
//}
//void TaskListDlg::updateTaskInfo(TaskInfo* var)
//{
//	if (var->status!=QUEST_STATUS_COMPLETE && var->status!=QUEST_STATUS_INCOMPLETE&&var->status!=QUEST_STATUS_AVAILABLE)
//	{
//		return;
//	}
//	if (!isShow())
//	{
//		toggle();
//	}
//	std::vector<tTrackItem>::iterator itr = trackList.begin();
//	bool hasTask = false;
//	float dy = 0;//移动高度差
//	float oldHeight, newHeight;
//	for (;itr!=trackList.end();itr++)//更新
//	{
//		if ((*itr).taskId==var->questID)
//		{
//			oldHeight = -(*itr).label->GetCurrentHeight();
//			std::map<int, tTrackLinkData> blank;
//			(*itr).linkDataDic.swap(blank);
//			updateTaskItem(var, (*itr));
//			newHeight = -(*itr).label->GetCurrentHeight();
//			dy = newHeight-oldHeight;
//			hasTask = true;
//		}
//		else
//		{
//			if (hasTask)
//			{
//				(*itr).label->setPositionY((*itr).label->getPositionY()-dy);
//			}
//		}
//	}
//	if (hasTask)//更新
//	{
//		CCSize size = tableViewCellNode->getContentSize();
//		size.height += dy;
//		tableViewCellNode->setContentSize(size);
//	}
//	else//添加
//	{
//		tTrackItem tti;
//		tti.label = WXRichLabelEx::create();
//		tti.label->Initialize(FONT_ALIAS_DEFAULT_24,24, tableViewSize, NULL, NULL);
//		//tti.label->setCanListenTouch(true);
//		tti.label->setVisible(true);
//		tti.taskId = var->questID;
//		updateTaskItem(var, tti);
//		CCSize size = tableViewCellNode->getContentSize();
//		tti.label->setPositionY(-size.height);
//		tableViewCellNode->addChild(tti.label);
//		size.height += -tti.label->GetCurrentHeight();
//		tableViewCellNode->setContentSize(size);
//		trackList.push_back(tti);
//	}
//	int h = tableViewCellNode->getContentSize().height;
//	h = h>tableViewSize.height?h:tableViewSize.height;
//	tableViewCellNode->setPosition(ccp(0, h));
//
//	if (tableView)
//	{
//		tableView->reloadData();
//	}
//}
//void TaskListDlg::deleteTaskInfo(TaskInfo* taskInfo)
//{
//	std::vector<tTrackItem>::iterator itr = trackList.begin();
//	bool hasTask = false;
//	float dy = 0;//移动高度差
//	while (itr!=trackList.end())//更新
//	{
//		if ((*itr).taskId==taskInfo->questID)
//		{
//			dy = -(*itr).label->GetCurrentHeight();
//			std::map<int, tTrackLinkData> blank;
//			(*itr).linkDataDic.swap(blank);
//			tableViewCellNode->removeChild((*itr).label, true);
//			itr = trackList.erase(itr);
//			hasTask = true;
//		}
//		else
//		{
//			if (hasTask)
//			{
//				(*itr).label->setPositionY((*itr).label->getPositionY()+dy);
//			}
//			itr++;
//		}
//	}
//	if (hasTask)//删了
//	{
//		CCSize size = tableViewCellNode->getContentSize();
//		size.height -= dy;
//		tableViewCellNode->setContentSize(size);
//		int h = tableViewCellNode->getContentSize().height;
//		h = h>tableViewSize.height?h:tableViewSize.height;
//		tableViewCellNode->setPosition(ccp(0, h));
//		if (tableView)
//		{
//			tableView->reloadData();
//		}
//	}
//}
//void TaskListDlg::clickCallback(int tag)
//{
//	std::vector<tTrackItem>::iterator trackItemItr = trackList.begin();
//	std::map<int, tTrackLinkData>::iterator trackLinkItr;
//	for (;trackItemItr!=trackList.end();trackItemItr++)
//	{
//		trackLinkItr = (*trackItemItr).linkDataDic.find(tag);
//		if (trackLinkItr!=(*trackItemItr).linkDataDic.end())
//		{
//			if (trackLinkItr->second.type==1 || trackLinkItr->second.type==2)//找npc
//			{
//				SceneController::getInstance().getSceneManager()->roleMoveToNpc(trackLinkItr->second.value);
//			}
//			else if (trackLinkItr->second.type==3)//面板
//			{
//				if (trackLinkItr->second.linkStr=="skill")
//				{
//					//SkillPanel* skillPanel = GameGobal::getInstance().getGameUILayer()->getSkillPanel();
//					/*if (!skillPanel->isShow())
//					{
//						skillPanel->toggle();
//					}*/
//					//todo:一些引导
//				}
//				else if (trackLinkItr->second.linkStr=="shop")
//				{
//					/*ShopPanel *shopPanel=GameGobal::getInstance().getGameUILayer()->getShopPanel();
//					if (!shopPanel->isShow())
//					{
//						shopPanel->toggle();
//					}*/
//				}
//				else if (trackLinkItr->second.linkStr=="refine")
//				{
//					/*RefiningPanel *refinePanel=GameGobal::getInstance().getGameUILayer()->getRefiningPanel();
//					if (!refinePanel->isShow())
//					{
//						refinePanel->toggle();
//					}*/
//				}
//				else if (trackLinkItr->second.linkStr=="enchant")
//				{
//					/*MoldPanel *moldPanel=GameGobal::getInstance().getGameUILayer()->getMoldPanel();
//					if (!moldPanel->isShow())
//					{
//						moldPanel->toggle();
//					}*/
//				}
//			}
//		}
//	}
//}