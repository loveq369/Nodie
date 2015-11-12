#include "LivingThingData.h"
#include "GameDefine.h"

LivingThingData::LivingThingData(void)
{
	tx = 0;
	ty = 0;
	moveSpeed = 0.0f;
	name = "";
	gender = -1;
	kind = 1;
	level = 0;
	currentHP = 0;
	currentMP = 0;
	totalHP = 0;
	totalMP = 0;
	dir = 0;
	state = 1;
	faction = 0;
	pathX = NULL;
	pathY = NULL;
	dataOwner = NULL;
	res_bodyId = -1;
	clothId = 0;
	entryid = 0;
	direction = 0;
}
LivingThingData::~LivingThingData(void)
{
}
void LivingThingData::attributeInit(int attriId, int& value)
{

}
void LivingThingData::attributeInit(int attriId, std::string& value)
{

}
void LivingThingData::attributeInit(int attriId, int64& value)
{

}
void LivingThingData::attributeInit(int attriId, std::vector<int>& value)
{

}
void LivingThingData::attributeInit(int attriId, std::vector<std::string>& value)
{

}
void LivingThingData::attributeInit(int attriId, std::vector<int64>& value)
{

}
void LivingThingData::attributeChange(int attriId, int& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_POSX:
		{
			updateRolePosX(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POSY:
		{
			updateRolePosY(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HP:
		{
			updateRoleCurHP(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HPMAX:
		{
			updateRoleTotalHP(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MPMAX:
		{
			updateRoleTotalMP(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MP:
		{
			updateRoleCurMP(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STATE:
		{
			updateRoleState(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MOVESPEED:
		{
			updateRoleMoveSpeed(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LOOKS_ARM:
		{
			updateRoleWeapon(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CLASS:  //职业
		{
			updateRoleWork(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRIME_VALUE:  //罪恶值
		{
			updateRoleCrimeValue(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LEVEL:  //级别
		{
			updateRoleLevel(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER:  //灵力
		{
			updateRoleCurSoulPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAXSOULPOWER:  //灵力上限
		{
			updateRoleTotalSoulPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_FIGHTING_FORCE:  //战力
		{
			updateRoleAttrFightingForce(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POWER:  //战力
		{
			updateRoleAttrPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_IMMUNITY:  //近程减免
		{
			updateRoleAttrMeleeImmunity(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_DEFENCE:  //近防
		{
			updateRoleAttrDefendMelee(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_IMMUNITY:  //远程减免
		{
			updateRoleAttrRangeImmunity(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_DEFENCE:  //远防
		{
			updateRoleAttrDefendRange(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_IMMUNITY:  //魔法减免
		{
			updateRoleAttrMagicImmunity(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_DEFENCE:  //魔防
		{
			updateRoleAttrDefendMagic(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_IMPRISONMENT_RESIST:  //定身抗性
		{
			updateRoleAttrImprisonmentResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STAMINA:  //体质
		{
			updateRoleAttrStamina(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_NORMAL_RESIST:  //流血抗性、普通抵抗
		{
			updateRoleAttrNormalResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STRENGTH:  //力量
		{
			updateRoleAttrStrength(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILENCE_RESIST:  //沉默抗性
		{
			updateRoleAttrSilenceResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_AGILE:  //敏捷
		{
			updateRoleAttrAgile(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DAZE_RESIST:  //昏迷抗性
		{
			updateRoleAttrDazeResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_INTELLIGENCE:  //智力
		{
			updateRoleAttrIntelligence(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POISON_RESIST:  //消弱抗性、中毒抵抗
		{
			updateRoleAttrPoisonResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HITRATE:  //命中
		{
			updateRoleAttrHitrate(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DODGE:  //闪避
		{
			updateRoleAttrDodge(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALATE:  //暴击
		{
			updateRoleAttrCriticalate(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALDAMAGE:  //暴击伤害
		{
			updateRoleAttrCriticaldamage(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TOUGHNESS:  //韧性
		{
			updateRoleAttrToughness(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LOOKS_CLOTH:
		{
			updateRoleClothe(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RIDEDISPLAY:
		{
			updateRoleMount(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_POSTING:
		{
			updateRoleGuildPosition(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GOLD:  //元宝
		{
			updateRoleGold(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TICKET:  ///礼券
		{
			updateRoleTicket(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PACKSIZE:  //背包可以使用的grid个数
		{
			updateRoleBackpackSize(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STORAGESIZE:  ///
		{
			updateRoleStorageSize(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_VIPTAG:
		{
			updateRoleVip(value);
			break;
		}
	case ROLECONSTCONFIG_PET_HAPPINESS:
		{
			updateRoleAttrPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TREASURE_TRANSPORT:
		{
			updateRoleTransport(value);
			break;
		}
	case ROLECONSTCONFIG_PET_LEVELUP_LEFT_TIME: // 宠物升级剩余时间
		{
			updateRoleGold(value);
			break;
		}
	default:
		{
			CCLOG("unknown attributeChange int: %d", attriId);
			break;
		}
	}
}
void LivingThingData::attributeChange(int attriId, std::string& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_NAME:  //仙门名字
		{
			updateRoleGuildName(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_NAME: // 宠物改名也会走这里
		{
			updateRoleName(value);
			break;
		}
	default:
		{
			CCLOG("unknown attributeChange string: %d", attriId);
			break;

		}
	}
}
void LivingThingData::attributeChange(int attriId, int64& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_EXPR:
		{
			updateRoleCurExp(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LEVELUPEXP:
		{
			updateRoleTotalExp(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILVER:  ////游戏币
		{
			updateRoleSilver(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_BOUND_SILVER:  ////绑定游戏币
		{
			updateRoleBoundSilver(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_COMPANION_ROLE:  //// 双修的对象
		{
			updateRoleCompanion(value);
			break;
		}
	default:
		{
			CCLOG("unknown attributeChange int64: %d", attriId);
			break;
		}
	}
}
void LivingThingData::attributeChange(int attriId, std::vector<int>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown attributeChange std::vector<int>: %d", attriId);
			break;
		}
	}
}
void LivingThingData::attributeChange(int attriId, std::vector<std::string>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown attributeChange std::vector<std::string>: %d", attriId);
			break;
		}
	}
}
void LivingThingData::attributeChange(int attriId, std::vector<int64>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown attributeChange std::vector<int64>: %d", attriId);
			break;
		}
	}
}