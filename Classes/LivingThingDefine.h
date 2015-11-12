#pragma once


class NPC;
class NpcData;

class tNpcEntity//npc∂‘œÛ
{
public:
	NPC* view;
	NpcData* data;
public:
	tNpcEntity(NpcData* npcData);
	~tNpcEntity();
};
