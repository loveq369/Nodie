//9miao.com 首发
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
	int8 state;//状态
	int8 type;//类型
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