//9miao.com �׷�
#pragma once

#include "gamecore.h"

struct TaskVo
{
	int id;
	int8 level;
	int8 type;
	std::string taskName;
};

struct FindVo
{
	int sceneId;
	int8 type;
	int npcId;
	int x;
	int y;
};

struct DialogNodeVo
{
	int8 type;
	std::string text;
	FindVo findVo;
};

struct TaskNodeVo
{
	int id;
	int8 state;//״̬
	int8 type;//����
	std::string name;
};


struct NPCDialogVo
{
	int taskId;
	int npcId;
	TaskVo award;
	std::vector<TaskNodeVo> taskList;
	std::vector<DialogNodeVo> dialogList;
};

struct DefaultDialog
{
	int npcId;
	int dialogListId;
	std::vector<TaskNodeVo> taskList;
};