#include "DialogController.h"
#include "TaskController.h"
#include "NpcDialog.h"
#include "GameGobal.h"
#include "NPC.h"
#include "LivingThingData.h"
#include "NpcDialog.h"
#include "DataManager.h"

DialogController::DialogController(void)
{
	bindNpc = NULL;
	npcDialog = NULL;
}
DialogController::~DialogController(void)
{
}
void DialogController::reqNPCFunctionC2S(NPC* npc)
{
	bindNpc = npc;
	if (!npc)
	{
		return;
	}
}

void DialogController::reqNpcEverquestsStartC2S( int64& npcId, int& everId )
{
	
}

