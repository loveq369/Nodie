#pragma once

#include "gamecore.h"
#include "GameDefine.h"
#include "PlayerData.h"
#include "Player.h"
#include "PlayerAction.h"
class PlayerController
{
public:
	static PlayerController& getInstance()
	{
		static PlayerController instance;
		return instance;
	}

	void setRolePos(cocos2d::CCPoint rolePos);
	void enterGame();

	void tick(float dt);

	void reqRoleMoveC2S(std::vector<tPoint> pathList);  // 角色移动
	void reqRoleMoveC2S(tPoint startTP, tPoint endTP);
	void reqStopMoveC2S();

	void reqDebugC2S(std::string msg);   // 调试消息 msg_debug_c2s  38



	CC_SYNTHESIZE(Player*, role, Role);
	CC_SYNTHESIZE(PlayerData*, roleData, RoleData);
	CC_SYNTHESIZE(bool, isInGame, IsInGame);	
	CC_SYNTHESIZE_READONLY(PlayerAction*, playerAction, PlayerAction);
private:
	PlayerController();
	PlayerController(const PlayerController&);
	PlayerController& operator=(const PlayerController&);
	~PlayerController();
public:
	int offlineHour;
	int offlineTotalExp;
};