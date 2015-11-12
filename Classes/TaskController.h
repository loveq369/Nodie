#pragma once
#include "gamecore.h"
#include "TaskDetail.h"
#include "TaskDialog.h"
#define QUEST_STATUS_COMPLETE		1//完成（已接，但没有提交）
#define QUEST_STATUS_INCOMPLETE		2//未完成
#define QUEST_STATUS_AVAILABLE		3//可接
#define QUEST_STATUS_UNAVAILABLE	4//不可接
#define QUEST_STATUS_SUBMIT		    5//提交完成
class TaskInfo
{
public:
	int		 questID;				//任务ID
	int 	 status;				//任务状态
	std::vector<int> values;		//已经打了几只怪
	int      leftTime;				//剩余时间
	TaskDetail				m_taskDetail;
public:
	TaskInfo()
	{
		questID = 0;
		status = -1;
		leftTime = 0;
	}
};

class TaskController
{
public:
	static TaskController& getInstance()
	{
		static TaskController instance;
		return instance;
	}

	//任务状态字段
	static std::string finishTaskStr;//完成
	static std::string acceptTaskStr;//可接
	static std::string unfinishTaskStr;//未完成
	bool checkIsTaskNpcStatue(int npcEntryId, int& status);
	void DeleteTask( int questID );
	void init();
	void save();
	TaskInfo * GetTask( int id );
	TaskInfo * GetTaskByNPCID( int id );
	std::string GetDir( int questID );
	std::map<int, TaskInfo> m_taskDic;


	int getAutoRunTargetId(TaskInfo* taskInfo);
	bool ResetTaskDialog( int id );
	//任务要是做的事:1.寻找下个NPC 2.弹出任务对话框
	void RecTaskToDo();
	void taskComplete(TaskInfo* pInfo);
	void taskAccept(TaskInfo* pInfo);
	
	//任务对话框
	CC_SYNTHESIZE(TaskDialog*, m_taskDialog, TaskDialog);
private:
	~TaskController();
	TaskController();
	TaskController(const TaskController&);
	TaskController& operator=(const TaskController&);
	TaskInfo*   currTaskInfo;
	std::vector<TaskDetail *>  allTask;
	bool isSetTaskDialog;
};