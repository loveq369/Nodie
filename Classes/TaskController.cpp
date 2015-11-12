#include "TaskController.h"
#include "SceneController.h"
#include "NPC.h"
#include "tinyxml2/tinyxml2.h"
#define  TASK_INIT   "task/ini.xml"
#define TASK_PATH_1  "task/"
#define TASK_PATH_1_NUM  2
bool TaskController::checkIsTaskNpcStatue(int npcEntryId, int& status)
{
	std::map<int, TaskInfo>::iterator itr = m_taskDic.begin();
	for (;itr!=m_taskDic.end();itr++)
	{
		if( itr->second.m_taskDetail.m_completeNPC==npcEntryId && itr->second.status==QUEST_STATUS_COMPLETE)
		{
			status = itr->second.status;
			return true;
		}
		if( itr->second.m_taskDetail.m_anwserNPC==npcEntryId && itr->second.status==QUEST_STATUS_AVAILABLE)
		{
			status = itr->second.status;
			return true;
		}
	}
	return false;
}

bool TaskController::ResetTaskDialog( int id )
{
	TaskInfo* v = GetTaskByNPCID(id);
	if( v==NULL )
		return false;

	m_taskDialog->setCurrentTaskInfo(v);

	return true;
}
void TaskController::RecTaskToDo()
{
	if (!currTaskInfo)
	{
		return;
	}
	if (currTaskInfo->status==QUEST_STATUS_AVAILABLE)
	{
		if (m_taskDialog&&isSetTaskDialog)
		{
			m_taskDialog->setCurrentTaskInfo(currTaskInfo);
		}
	}
	else if (currTaskInfo->status==QUEST_STATUS_COMPLETE||currTaskInfo->status==QUEST_STATUS_INCOMPLETE)
	{
		int npcEntryId = getAutoRunTargetId(currTaskInfo);
		if (npcEntryId)
		{
			//SceneController::getInstance().removeAttackData(PlayerController::getInstance().getRoleData()->id);
			SceneController::getInstance().getSceneManager()->roleMoveToNpc(npcEntryId);
		}
	}

}
void TaskController::taskComplete(TaskInfo* pInfo)
{
	int nextTaskId=pInfo->m_taskDetail.m_nextTask;
	std::vector<TaskDetail*>::iterator it=allTask.begin();
	bool hasnextTask=false;
	for (;it!=allTask.end();it++)
	{
		if (nextTaskId==(*it)->m_taskId)
		{
			TaskInfo nextTask;
			nextTask.leftTime=0;
			nextTask.questID=nextTaskId;
			nextTask.status=QUEST_STATUS_AVAILABLE;
			nextTask.m_taskDetail=*(*it);
			m_taskDic.insert(std::map<int,TaskInfo>::value_type(nextTaskId,nextTask));
			hasnextTask=true;
			break;
		}
	}
	if (hasnextTask)
	{
		tNpcEntity* npcAEntity = SceneController::getInstance().getSceneManager()->getNpcEntity(pInfo->m_taskDetail.m_completeNPC);
		DeleteTask(pInfo->questID);
		if (npcAEntity)
		{
			npcAEntity->view->updateTaskStatus(QUEST_STATUS_AVAILABLE);
		}
	}
	else
	{
		tNpcEntity* npcAEntity = SceneController::getInstance().getSceneManager()->getNpcEntity(pInfo->m_taskDetail.m_completeNPC);
		DeleteTask(pInfo->questID);
		if (npcAEntity)
		{
			npcAEntity->view->updateTaskStatus(-100);
		}
	}
}
	

void TaskController::taskAccept(TaskInfo* pInfo)
{
	TaskInfo * taskInfo=GetTask(pInfo->questID);
	if (taskInfo)
	{
		if (taskInfo->values.size()==0)
		{
			taskInfo->status=QUEST_STATUS_COMPLETE;
			tNpcEntity* npcAEntity = SceneController::getInstance().getSceneManager()->getNpcEntity(pInfo->m_taskDetail.m_anwserNPC);
			if (npcAEntity)
			{
				npcAEntity->view->updateTaskStatus(-100);
			}
			tNpcEntity* npcCEntity = SceneController::getInstance().getSceneManager()->getNpcEntity(pInfo->m_taskDetail.m_completeNPC);
			if (npcCEntity)
			{
				npcCEntity->view->updateTaskStatus(QUEST_STATUS_COMPLETE);
			}
		}
		else
		{
			taskInfo->status=QUEST_STATUS_INCOMPLETE;
			tNpcEntity* npcAEntity = SceneController::getInstance().getSceneManager()->getNpcEntity(pInfo->m_taskDetail.m_anwserNPC);
			if (npcAEntity)
			{
				npcAEntity->view->updateTaskStatus(-100);
			}
		}
	}
}
int TaskController::getAutoRunTargetId(TaskInfo* taskInfo)
{
	int npcEntryId = 0;
	if (taskInfo->status==QUEST_STATUS_COMPLETE)
	{
		npcEntryId = taskInfo->m_taskDetail.m_completeNPC;
	}
	else
	{
		std::vector<TaskTarget>::iterator itr = taskInfo->m_taskDetail.m_target.begin();
		std::vector<int>::iterator intItr = taskInfo->values.begin();
		unsigned int index = 0;
		for (;itr!=taskInfo->m_taskDetail.m_target.end();itr++,index++)
		{
			if ((*(intItr+index))<(*itr).m_objsCount)
			{
				npcEntryId = (*itr).m_objsID;
				break;
			}
		}
		//if (npcEntryId==0)
		//{
		//	npcEntryId = taskInfo->m_taskDetail.m_anwserNPC;
		//}
	}
	return npcEntryId;
}

TaskInfo * TaskController::GetTask( int id )
{
	std::map<int, TaskInfo>::iterator itr = m_taskDic.find(id);
	if( itr != m_taskDic.end() )
	{
		return &(itr->second);
	}
	return NULL;
}

TaskController::TaskController(void)
{
	isSetTaskDialog=false;
	currTaskInfo=NULL;
}

TaskController::~TaskController(void)
{
	std::vector<TaskDetail *>::iterator it=allTask.begin();
	for (;it!=allTask.end();it++)
	{
		if(*it != NULL)
		{
			delete *it;
			*it = NULL;
		}  
	}
	allTask.clear();
	currTaskInfo=NULL;
}

void TaskController::DeleteTask( int questID )
{
	std::map<int, TaskInfo>::iterator itr = m_taskDic.find(questID);
	if( itr != m_taskDic.end() )
	{
		//删除npc任务状态动画
		currTaskInfo=&(itr->second);
		int npcEntryId = itr->second.m_taskDetail.m_completeNPC;
		tNpcEntity* npcEntity = SceneController::getInstance().getSceneManager()->getNpcEntityByEntryId(npcEntryId);
		if (npcEntity)
		{
			npcEntity->view->updateTaskStatus(-100);
		}
		m_taskDic.erase(itr);
	}
}

TaskInfo * TaskController::GetTaskByNPCID( int id )
{
	std::map<int, TaskInfo>::iterator itr = m_taskDic.begin();
	for (;itr!=m_taskDic.end();itr++)
	{
		if( (itr->second.m_taskDetail.m_completeNPC == id&&itr->second.status==QUEST_STATUS_COMPLETE)||(itr->second.m_taskDetail.m_anwserNPC == id&&itr->second.status==QUEST_STATUS_AVAILABLE) )
		{
			return &(itr->second);
		}
	}
	return NULL;
}
void  TaskController::init()
{
	for (int i=0;i<TASK_PATH_1_NUM;i++)
	{
		TaskDetail * pDetail=new TaskDetail();
		int aa = i+10001;
	    char c[12]; 
		int length = sprintf(c, "%d.xml", aa);
		char filePath[240];
		sprintf(filePath, "%s%s",TASK_PATH_1,c);
		pDetail->ReadXmlFile(filePath);
		allTask.push_back(pDetail);
	}	
	std::string filePath=cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename("task/ini.xml");
	//std::string filePath = FileUtils::getInstance()->getWritablePath() + fileName;
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	tinyxml2::XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml格式错误
		return ;
	}
	tinyxml2::XMLElement *rootEle = pDoc->RootElement();
	tinyxml2::XMLElement * taskInfo = rootEle->FirstChildElement("taskInfo");
	while (taskInfo)
	{
		TaskInfo info;
		tinyxml2::XMLElement * questID = taskInfo->FirstChildElement("questID");
		if (questID)
		{
			std::string strquestID=questID->GetText();
			info.questID=std::atoi(strquestID.c_str());
		}
		
		tinyxml2::XMLElement * status = taskInfo->FirstChildElement("status");
		if (status)
		{
			std::string strstatus=status->GetText();
			info.status=std::atoi(strstatus.c_str());
		}
		tinyxml2::XMLElement * leftTime = taskInfo->FirstChildElement("leftTime");
		if (leftTime)
		{
			std::string strleftTime=leftTime->GetText();
			info.leftTime=std::atoi(strleftTime.c_str());
		}
		tinyxml2::XMLElement * value = taskInfo->FirstChildElement("value");
		while (value)
		{
			std::string strvalue=value->GetText();
			info.values.push_back(std::atoi(strvalue.c_str()));
			value=value->NextSiblingElement("taskInfo");
		}
		std::vector<TaskDetail *>::iterator it=allTask.begin();
		for(;it!=allTask.end();it++)
		{
			if (info.questID==(*it)->m_taskId)
			{
				info.m_taskDetail=*(*it);
			}
		}
		m_taskDic.insert(std::map<int,TaskInfo>::value_type(info.questID,info));
		taskInfo=taskInfo->NextSiblingElement("taskInfo");
	}
}

void TaskController::save()
{

}
std::string TaskController::GetDir( int questID )
{
	std::string strDir="";
	char buffer[_MAX_PATH_];
	memset( buffer,0,_MAX_PATH_ );
	sprintf( buffer,"%d",questID );
	strDir=strDir+"task"+"/"+buffer+".xml";
	return strDir;
}