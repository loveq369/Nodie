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
	std::vector<int> quests;//�����б�
	std::vector<int> queststate;//����״̬
	std::vector<int> everquests;//�ճ�����
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

	void reqNPCFunctionC2S(NPC* npc);//���npc     msg_npc_function_c2s
	

	//����npc�ճ�����ʼ
	void reqNpcEverquestsStartC2S(int64& npcId, int& everId);


	
	CC_SYNTHESIZE(NpcDialog*, npcDialog, NpcDialog);

private:
	DialogController();
	DialogController(const DialogController&);
	DialogController& operator=(const DialogController&);
	~DialogController();

private:
	FunctionNPC dialogInfo;//���npc��Ϣ
	NPC* bindNpc;
};

