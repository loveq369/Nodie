#include "PlayerAction.h"
#include "GameGobal.h"
#include "PlayerController.h"
#include "DataManager.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerData.h"

PlayerAction::PlayerAction(void)
{
	action = PLAYER_ACTION_NATURL;
	isBattle = false;
	isCampBattle = false;
	isInYhzqBattle = false;
	isInSpa = false;
	isWorldCup = false;
	isTraining = false;
}
PlayerAction::~PlayerAction(void)
{
}
void PlayerAction::setAction(int action)
{
	this->action = action;
}
int PlayerAction::getAction()
{
	return action;
}

int PlayerAction::getActionTypeByWeapon()
{
	return PLAYER_ACTION_PK;
}

int PlayerAction::getStopRange()
{
	switch (action)
	{
	case PLAYER_ACTION_DIALOG:
		return (5);
	case PLAYER_ACTION_GATE:
		return (1);
	case PLAYER_ACTION_PK:
		{
			/*tSkillData* currentSkill = PlayerController::getInstance().getSkillManager()->getCurrentSkill();
			if (currentSkill && currentSkill->configData)
			{
				int range = currentSkill->configData->distance-1;
				return range>0?range:0;
			}*/
			return 0;
		}
	case PLAYER_ACTION_FOLLOW:
		return (3);
	case PLAYER_ACTION_COLLECT:
		return (3);
	case PLAYER_ACTION_TRAINING:
		return (0);
	case PLAYER_ACTION_PRACTICE:
		return(0);
	};
	return (3);
}