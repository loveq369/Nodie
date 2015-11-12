#pragma once

#include "gamecore.h"

class NpcDialog;

class FunctionKey
{
public:
	int key;
	std::vector<int> value;
};
class FunctionNPC
{
public:
	int64 npcEntryId;
	std::vector<FunctionKey> values;
	std::vector<int> quests;//任务列表
	std::vector<int> queststate;//任务状态
	std::vector<int> everquests;//日常任务
};
class NPC;
class DialogController
{
public:
	static DialogController& getInstance()
	{
		static DialogController instance;
		return instance;
	}

	void reqNPCFunctionC2S(NPC* npc);//点击npc     msg_npc_function_c2s
	

	//请求npc日常任务开始
	void reqNpcEverquestsStartC2S(int64& npcId, int& everId);


	
	CC_SYNTHESIZE(NpcDialog*, npcDialog, NpcDialog);

private:
	DialogController();
	DialogController(const DialogController&);
	DialogController& operator=(const DialogController&);
	~DialogController();

private:
	FunctionNPC dialogInfo;//点击npc信息
	NPC* bindNpc;
};

