#pragma once


class NPC;
class NpcData;

class tNpcEntity//npc����
{
public:
	NPC* view;
	NpcData* data;
public:
	tNpcEntity(NpcData* npcData);
	~tNpcEntity();
};
