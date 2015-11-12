#include "LivingThingDefine.h"
#include "NpcData.h"





tNpcEntity::tNpcEntity(NpcData* npcData)
{
	view = NULL;
	data = npcData;
}
tNpcEntity::~tNpcEntity()
{
	CC_SAFE_DELETE(data);
	view = NULL;
}
