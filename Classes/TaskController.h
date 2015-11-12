#pragma once
#include "gamecore.h"
#include "TaskDetail.h"
#include "TaskDialog.h"
#define QUEST_STATUS_COMPLETE		1//��ɣ��ѽӣ���û���ύ��
#define QUEST_STATUS_INCOMPLETE		2//δ���
#define QUEST_STATUS_AVAILABLE		3//�ɽ�
#define QUEST_STATUS_UNAVAILABLE	4//���ɽ�
#define QUEST_STATUS_SUBMIT		    5//�ύ���
class TaskInfo
{
public:
	int		 questID;				//����ID
	int 	 status;				//����״̬
	std::vector<int> values;		//�Ѿ����˼�ֻ��
	int      leftTime;				//ʣ��ʱ��
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

	//����״̬�ֶ�
	static std::string finishTaskStr;//���
	static std::string acceptTaskStr;//�ɽ�
	static std::string unfinishTaskStr;//δ���
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
	//����Ҫ��������:1.Ѱ���¸�NPC 2.��������Ի���
	void RecTaskToDo();
	void taskComplete(TaskInfo* pInfo);
	void taskAccept(TaskInfo* pInfo);
	
	//����Ի���
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