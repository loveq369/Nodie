#include "NpcData.h"
#include "GameDefine.h"
#include "TargetController.h"
USING_NS_CC;

NpcData::NpcData(void)
{
	belonger = NULL;
}
NpcData::~NpcData(void)
{
}
void NpcData::attributeInit(int attriId, int& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_POSX:
		{
			tx = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POSY:
		{
			ty = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GENDER:
		{
			gender = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MOVESPEED:
		{
			moveSpeed = (float)value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LEVEL://等级
		{
			level = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CREATURE_FLAG:
		{
			flag = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LOOKS_CLOTH:
		{
			clothId = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DISPLAYID: //资源id
		{
			res_bodyId = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STATE:
		{
			state = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HP:
		{
			currentHP = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MP:
		{
			currentMP = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HPMAX:
		{
			totalHP = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MPMAX:
		{
			totalMP = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PROTOID:
		{
			entryid = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CLASS:
		{
			faction = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LOOKS_ARM:
		{
			//weaponId = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_ENCHANT:  //升星套
		{
			//suitValue = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER:
		{
			//soulpower = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAXSOULPOWER:
		{
			//soulpowerMax = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CAMP_ID: //阵营信息 0为无阵营 1为红  2为蓝 (目前只在战场内有用)
		{
			//camp = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_TITLE_ICON_ID:
		{
			//guildTitle = value;
			break;
		}
	default:
		{
			CCLOG("unknown npc int attr: %d", attriId);
			break;
		}
	}
}
void NpcData::attributeInit(int attriId, std::string& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_NAME:
		{
			name = value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_NAME:
		{
			//guildName = value;
			break;
		}
	default:
		{
			CCLOG("unknown npc string attr: %d", attriId);
			break;
		}
	}
}
void NpcData::attributeInit(int attriId, int64& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_TOUCHRED:
		{
			//owner = value;
			break;
		}
	default:
		{
			CCLOG("unknown npc int64 attr: %d", attriId);
			break;
		}
	}
}
void NpcData::attributeInit(int attriId, std::vector<int>& value)
{
	std::vector<int>* pathX = NULL;
	std::vector<int>* pathY = NULL;
	std::vector<int>* buffList = NULL;
	std::vector<int>* buffLevelList = NULL;
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_BODY_BUFFER:
		{
			buffList = &value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_BODY_BUFF_LEVEL:
		{
			buffLevelList = &value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PATH_X:
		{
			pathX = &value;
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PATH_Y:
		{
			pathY = &value;
			break;
		}
	default:
		{
			CCLOG("unknown npc std::vector<int> attr: %d", attriId);
			break;
		}
	}
	//if (buffList && buffLevelList)//buff
	//{
	//	std::vector<int>::iterator itr = buffList->begin();
	//	std::vector<int>::iterator itr2 = buffLevelList->begin();
	//	while (itr!=buffList->end() && itr2!=buffLevelList->end())
	//	{
	//		buffDic.insert(std::map<int,int>::value_type(*itr, *itr2));
	//		++itr;
	//		++itr2;
	//	}
	//}
	if (pathX && pathY)
	{
		std::vector<int>::iterator itr = pathX->begin();
		std::vector<int>::iterator itr2 = pathY->begin();
		while (itr!=pathX->end() && itr2!=pathY->end())
		{
			tPoint tp;
			tp.x = *itr;
			tp.y = *itr2;
			movePath.push_back(tp);
			++itr;
			++itr2;
		}
	}
}
void NpcData::attributeInit(int attriId, std::vector<std::string>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown npc std::vector<std::string> attr: %d", attriId);
			break;
		}
	}
}
void NpcData::attributeInit(int attriId, std::vector<int64>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown npc std::vector<int64> attr: %d", attriId);
			break;
		}
	}
}
void NpcData::updateRoleBackpackSize(int value)
{
}
void NpcData::updateRoleStorageSize(int value)
{
}
void NpcData::updateRoleMoveSpeed(int value)
{
	moveSpeed = (float)value;
	if(!dataOwner)
		return;
	if (dataOwner->isInPoseState(POSE_STATE_MOVE))
	{
	   dataOwner->moveCancel();
	   dataOwner->move();
	}
}
void NpcData::updateRoleState(int value)
{
	if (state==0 && value==1)
	{
	dataOwner->reborn();
	}
	if (state != value)
	{
		state = value;
	}
}
void NpcData::updateRoleDispaly(int value)
{
}
void NpcData::updateRoleName(std::string value)
{
	name = value;
	TargetController::getInstance().updateTarget(dataOwner);
	//TODO:更新目标头像
}
void NpcData::updateRolePosX(int value)
{
	tx = value;
}
void NpcData::updateRolePosY(int value)
{
	ty = value;
}
void NpcData::updateRoleTotalHP(int value)
{
	totalHP = value;
	TargetController::getInstance().updateTarget(dataOwner);
	//TODO:更新目标头像
}
void NpcData::updateRoleCurHP(int value)
{
	currentHP = value;
	TargetController::getInstance().updateTarget(dataOwner);
	//TODO:更新目标头像
}
void NpcData::updateRoleTotalMP(int value)
{
	totalMP = value;
	TargetController::getInstance().updateTarget(dataOwner);
	//TODO:更新目标头像
}
void NpcData::updateRoleCurMP(int value)
{
	currentMP = value;
	TargetController::getInstance().updateTarget(dataOwner);
	//TODO:更新目标头像
}
void NpcData::updateRoleWork(int value)
{
}
void NpcData::updateRoleLevel(int value)
{
}
void NpcData::updateRoleGender(int value)
{
}
void NpcData::updateRoleCurExp(int64 value)
{
}
void NpcData::vipAddRoleExp(int value)
{
}
void NpcData::noVipAddExp(int value)
{
}
void NpcData::updateRoleTotalExp(int64 value)
{
}
void NpcData::updateRoleBoundSilver(int64 value)
{
}
void NpcData::updateRoleSilver(int64 value)
{
}
void NpcData::updateRoleTicket(int32 value)
{
}
void NpcData::updateRoleGold(int32 value)
{
}
void NpcData::updateRoleGuildName(std::string value)
{
}
void NpcData::updateRoleGuildPosition(int value)
{
}
void NpcData::updateRoleClothe(int value)
{
}
void NpcData::updateRoleWeapon(int value)
{
}
void NpcData::updateRoleSuitStar(int value)
{
}
void NpcData::updateRoleCrimeValue(int value)
{
}
void NpcData::updateRolePKSign(int value)
{
}
void NpcData::updateRoleAttrHonour(int value)
{
}
void NpcData::updateRoleCompanion(int64 value)
{
}
void NpcData::updateRoleTotalSoulPower(int value)
{
}
void NpcData::updateRoleCurSoulPower(int value)
{
}
void NpcData::vipAddSoulPower(int value)
{
}
void NpcData::noVipAddSoulPower(int value)
{
}
void NpcData::updateRoleVip(int value)
{
}
void NpcData::updateRoleCamp(int value)
{
}
void NpcData::updateRoleMount(int value)
{
}
void NpcData::updateRoleInstanceTitle(int value)
{
}
void NpcData::updateRoleTransport(int value)
{
}
void NpcData::updateGuildNameColor(int value)
{
}
void NpcData::updateSpiritePower(int value)
{
}
void NpcData::updateSpiritePowerMax(int value)
{
}
void NpcData::updateHonorData(int value)
{
}
void NpcData::updateSoulWeaponEffect(int value)
{
}
void NpcData::updataGuildTitleIcon(int value)
{
}
void NpcData::updateAirCraft(int value)
{
}
void NpcData::updateFereId(int value)
{
}
void NpcData::updataFereName(int value)
{
}
void NpcData::updateWedding(int value)
{
}

void NpcData::updateRoleAttrFightingForce(int value)
{
}
void NpcData::updateRoleAttrPower(int value)
{
}
void NpcData::updateRoleAttrMeleeImmunity(int value)
{
}
void NpcData::updateRoleAttrDefendMelee(int value)
{
}
void NpcData::updateRoleAttrRangeImmunity(int value)
{
}
void NpcData::updateRoleAttrDefendRange(int value)
{
}
void NpcData::updateRoleAttrMagicImmunity(int value)
{
}
void NpcData::updateRoleAttrDefendMagic(int value)
{
}
void NpcData::updateRoleAttrImprisonmentResist(int value)
{
}
void NpcData::updateRoleAttrStamina(int value)
{
}
void NpcData::updateRoleAttrNormalResist(int value)
{
}
void NpcData::updateRoleAttrStrength(int value)
{
}
void NpcData::updateRoleAttrSilenceResist(int value)
{
}
void NpcData::updateRoleAttrAgile(int value)
{
}
void NpcData::updateRoleAttrDazeResist(int value)
{
}
void NpcData::updateRoleAttrIntelligence(int value)
{
}
void NpcData::updateRoleAttrPoisonResist(int value)
{
}
void NpcData::updateRoleAttrHitrate(int value)
{
}
void NpcData::updateRoleAttrDodge(int value)
{
}
void NpcData::updateRoleAttrCriticalate(int value)
{
}
void NpcData::updateRoleAttrCriticaldamage(int value)
{
}
void NpcData::updateRoleAttrToughness(int value)
{
}
