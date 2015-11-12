#include "PlayerController.h"
#include "SceneController.h"
#include "GameDefine.h"
#include "GameGobal.h"
#include "DataManager.h"
#include "Player.h"
#include "PlayerData.h"
#include "UIDefine.h"

PlayerController::PlayerController()
{
	role = NULL;
	playerAction = new PlayerAction();
	roleData = new PlayerData();
	isInGame = false;
}

PlayerController::~PlayerController()
{
	CC_SAFE_DELETE(playerAction);
	CC_SAFE_DELETE(roleData);
}
void PlayerController::setRolePos(CCPoint rolePos)
{
}
void PlayerController::tick(float dt)
{
	if (role)
	{
		role->tick(dt);
	}
	
}
/************************************************************************/
/* 移动                                                                     */
/************************************************************************/
void PlayerController::reqRoleMoveC2S(std::vector<tPoint> pathList)
{
	
}
void PlayerController::reqRoleMoveC2S(tPoint startTP, tPoint endTP)
{

}
void PlayerController::reqStopMoveC2S()
{
	
}
void PlayerController::enterGame()
{
	
	isInGame = 1;
}

/****************************************/
/*  xxxxxx
/****************************************/

void PlayerController::reqDebugC2S(std::string message)   // 调试消息 msg_debug_c2s  38
{
	
}






































