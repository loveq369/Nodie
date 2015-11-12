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
	case ROLECONSTCONFIG_ROLE_ATTR_CLASS:  //ְҵ
		{
			updateRoleWork(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRIME_VALUE:  //���ֵ
		{
			updateRoleCrimeValue(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LEVEL:  //����
		{
			updateRoleLevel(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER:  //����
		{
			updateRoleCurSoulPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAXSOULPOWER:  //��������
		{
			updateRoleTotalSoulPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_FIGHTING_FORCE:  //ս��
		{
			updateRoleAttrFightingForce(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POWER:  //ս��
		{
			updateRoleAttrPower(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_IMMUNITY:  //���̼���
		{
			updateRoleAttrMeleeImmunity(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_DEFENCE:  //����
		{
			updateRoleAttrDefendMelee(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_IMMUNITY:  //Զ�̼���
		{
			updateRoleAttrRangeImmunity(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_DEFENCE:  //Զ��
		{
			updateRoleAttrDefendRange(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_IMMUNITY:  //ħ������
		{
			updateRoleAttrMagicImmunity(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_DEFENCE:  //ħ��
		{
			updateRoleAttrDefendMagic(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_IMPRISONMENT_RESIST:  //������
		{
			updateRoleAttrImprisonmentResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STAMINA:  //����
		{
			updateRoleAttrStamina(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_NORMAL_RESIST:  //��Ѫ���ԡ���ͨ�ֿ�
		{
			updateRoleAttrNormalResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STRENGTH:  //����
		{
			updateRoleAttrStrength(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILENCE_RESIST:  //��Ĭ����
		{
			updateRoleAttrSilenceResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_AGILE:  //����
		{
			updateRoleAttrAgile(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DAZE_RESIST:  //���Կ���
		{
			updateRoleAttrDazeResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_INTELLIGENCE:  //����
		{
			updateRoleAttrIntelligence(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POISON_RESIST:  //�������ԡ��ж��ֿ�
		{
			updateRoleAttrPoisonResist(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HITRATE:  //����
		{
			updateRoleAttrHitrate(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DODGE:  //����
		{
			updateRoleAttrDodge(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALATE:  //����
		{
			updateRoleAttrCriticalate(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALDAMAGE:  //�����˺�
		{
			updateRoleAttrCriticaldamage(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TOUGHNESS:  //����
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
	case ROLECONSTCONFIG_ROLE_ATTR_GOLD:  //Ԫ��
		{
			updateRoleGold(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TICKET:  ///��ȯ
		{
			updateRoleTicket(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PACKSIZE:  //��������ʹ�õ�grid����
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
	case ROLECONSTCONFIG_PET_LEVELUP_LEFT_TIME: // ��������ʣ��ʱ��
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
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_NAME:  //��������
		{
			updateRoleGuildName(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_NAME: // �������Ҳ��������
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
	case ROLECONSTCONFIG_ROLE_ATTR_SILVER:  ////��Ϸ��
		{
			updateRoleSilver(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_BOUND_SILVER:  ////����Ϸ��
		{
			updateRoleBoundSilver(value);
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_COMPANION_ROLE:  //// ˫�޵Ķ���
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