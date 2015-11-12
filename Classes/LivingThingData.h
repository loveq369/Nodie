#pragma once
#include "gamecore.h"
class LivingThing;
class LivingThingData
{
public:
	LivingThingData(void);
	~LivingThingData(void);

	virtual void attributeInit(int attriId, int& value);
	virtual void attributeInit(int attriId, std::string& value);
	virtual void attributeInit(int attriId, int64& value);
	virtual void attributeInit(int attriId, std::vector<int>& value);
	virtual void attributeInit(int attriId, std::vector<std::string>& value);
	virtual void attributeInit(int attriId, std::vector<int64>& value);

	virtual void attributeChange(int attriId, int& value);
	virtual void attributeChange(int attriId, std::string& value);
	virtual void attributeChange(int attriId, int64& value);
	virtual void attributeChange(int attriId, std::vector<int>& value);
	virtual void attributeChange(int attriId, std::vector<std::string>& value);
	virtual void attributeChange(int attriId, std::vector<int64>& value);


	virtual void updateRoleBackpackSize(int value){};//ROLECONSTCONFIG_ROLE_ATTR_PACKSIZE 
	virtual void updateRoleStorageSize(int value){};//ROLECONSTCONFIG_ROLE_ATTR_STORAGESIZE
	virtual void updateRoleMoveSpeed(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MOVESPEED 
	virtual void updateRoleState(int value){};//ROLECONSTCONFIG_ROLE_ATTR_STATE 
	virtual void updateRoleDispaly(int value){};//ROLECONSTCONFIG_ROLE_ATTR_DISPLAYID 
	virtual void updateRoleName(std::string value){};//ROLECONSTCONFIG_ROLE_ATTR_NAME
	virtual void updateRolePosX(int value){};//ROLECONSTCONFIG_ROLE_ATTR_POSX
	virtual void updateRolePosY(int value){};//ROLECONSTCONFIG_ROLE_ATTR_POSY
	virtual void updateRoleTotalHP(int value){};//ROLECONSTCONFIG_ROLE_ATTR_HPMAX 
	virtual void updateRoleCurHP(int value){};//ROLECONSTCONFIG_ROLE_ATTR_HP
	virtual void updateRoleTotalMP(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MPMAX 
	virtual void updateRoleCurMP(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MP
	virtual void updateRoleWork(int value){};//ROLECONSTCONFIG_ROLE_ATTR_CLASS 
	virtual void updateRoleLevel(int value){};//ROLECONSTCONFIG_ROLE_ATTR_LEVEL
	virtual void updateRoleGender(int value){};//ROLECONSTCONFIG_ROLE_ATTR_GENDER
	virtual void updateRoleCurExp(int64 value){};//ROLECONSTCONFIG_ROLE_ATTR_EXPR
	virtual void vipAddRoleExp(int value){};//ROLECONSTCONFIG_ROLE_ATTR_EXP_VIP_ADD_ID
	virtual void noVipAddExp(int value){};//ROLECONSTCONFIG_ROLE_ATTR_EXP_NO_VIP_ADD
	virtual void updateRoleTotalExp(int64 value){};//ROLECONSTCONFIG_ROLE_ATTR_LEVELUPEXP
	virtual void updateRoleBoundSilver(int64 value){};//ROLECONSTCONFIG_ROLE_ATTR_BOUND_SILVER 
	virtual void updateRoleSilver(int64 value){};//ROLECONSTCONFIG_ROLE_ATTR_SILVER 
	virtual void updateRoleTicket(int32 value){};//ROLECONSTCONFIG_ROLE_ATTR_TICKET
	virtual void updateRoleGold(int32 value){};//ROLECONSTCONFIG_ROLE_ATTR_GOLD 
	virtual void updateRoleGuildName(std::string value){};//ROLECONSTCONFIG_ROLE_ATTR_GUILD_NAME 
	virtual void updateRoleGuildPosition(int value){};//ROLECONSTCONFIG_ROLE_ATTR_GUILD_POSTING 
	virtual void updateRoleClothe(int value){};//ROLECONSTCONFIG_ROLE_ATTR_LOOKS_CLOTH
	virtual void updateRoleWeapon(int value){};//ROLECONSTCONFIG_ROLE_ATTR_LOOKS_ARM
	virtual void updateRoleSuitStar(int value){};//ROLECONSTCONFIG_ROLE_ATTR_ENCHANT
	virtual void updateRoleCrimeValue(int value){};//ROLECONSTCONFIG_ROLE_ATTR_CRIME_VALUE
	virtual void updateRolePKSign(int value){};//ROLECONSTCONFIG_ROLE_ATTR_PK_MODEL 
	virtual void updateRoleAttrHonour(int value){};//ROLECONSTCONFIG_ROLE_ATTR_HONOUR
	virtual void updateRoleCompanion(int64 value){};//ROLECONSTCONFIG_ROLE_ATTR_COMPANION_ROLE
	virtual void updateRoleTotalSoulPower(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MAXSOULPOWER 
	virtual void updateRoleCurSoulPower(int value){};//ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER
	virtual void vipAddSoulPower(int value){};//ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER_VIP_ADD_ID 
	virtual void noVipAddSoulPower(int value){};//ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER_NO_VIP_ADD 
	virtual void updateRoleVip(int value){};//ROLECONSTCONFIG_ROLE_ATTR_VIPTAG
	virtual void updateRoleCamp(int value){};//ROLECONSTCONFIG_ROLE_ATTR_CAMP_ID 
	virtual void updateRoleMount(int value){};//ROLECONSTCONFIG_ROLE_ATTR_RIDEDISPLAY
	virtual void updateRoleInstanceTitle(int value){};//ROLECONSTCONFIG_ROLE_ATTR_INSTANCE_TITLE_ICON_ID
	virtual void updateRoleTransport(int value){};//ROLECONSTCONFIG_ROLE_ATTR_TREASURE_TRANSPORT
	virtual void updateGuildNameColor(int value){};//ROLECONSTCONFIG_ROLE_ATTR_GUILDTYPE 
	virtual void updateSpiritePower(int value){};//ROLECONSTCONFIG_ROLE_ATTR_SPIRITSPOWER 
	virtual void updateSpiritePowerMax(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MAXSPIRITSPOWER 
	virtual void updateHonorData(int value){};//ROLECONSTCONFIG_ROLE_ATTR_HONOR 
	virtual void updateSoulWeaponEffect(int value){};//ROLECONSTCONFIG_ROLE_ATTR_SOUL_WEAPON_EFFECT_KEY
	virtual void updataGuildTitleIcon(int value){};//ROLECONSTCONFIG_ROLE_ATTR_GUILD_TITLE_ICON_ID
	virtual void updateAirCraft(int value){};//ROLECONSTCONFIG_ROLE_ATTR_AIRCRAFT_PHASE
	virtual void updateFereId(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MARRY_TITLE_ID
	virtual void updataFereName(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MARRY_TITLE_NAME
	virtual void updateWedding(int value){};//ROLECONSTCONFIG_ROLE_ATTR_WEDDING_STATE
	virtual void updateRoleAttrFightingForce(int value){};//ROLECONSTCONFIG_ROLE_ATTR_FIGHTING_FORCE
	virtual void updateRoleAttrPower(int value){};//ROLECONSTCONFIG_ROLE_ATTR_POWER
	virtual void updateRoleAttrMeleeImmunity(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MELEE_IMMUNITY
	virtual void updateRoleAttrDefendMelee(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MELEE_DEFENCE
	virtual void updateRoleAttrRangeImmunity(int value){};//ROLECONSTCONFIG_ROLE_ATTR_RANGE_IMMUNITY
	virtual void updateRoleAttrDefendRange(int value){};//ROLECONSTCONFIG_ROLE_ATTR_RANGE_DEFENCE
	virtual void updateRoleAttrMagicImmunity(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MAGIC_IMMUNITY
	virtual void updateRoleAttrDefendMagic(int value){};//ROLECONSTCONFIG_ROLE_ATTR_MAGIC_DEFENCE
	virtual void updateRoleAttrImprisonmentResist(int value){};//ROLECONSTCONFIG_ROLE_ATTR_IMPRISONMENT_RESIST
	virtual void updateRoleAttrStamina(int value){};//ROLECONSTCONFIG_ROLE_ATTR_STAMINA
	virtual void updateRoleAttrNormalResist(int value){};//ROLECONSTCONFIG_ROLE_ATTR_NORMAL_RESIST
	virtual void updateRoleAttrStrength(int value){};//ROLECONSTCONFIG_ROLE_ATTR_STRENGTH
	virtual void updateRoleAttrSilenceResist(int value){};//ROLECONSTCONFIG_ROLE_ATTR_SILENCE_RESIST
	virtual void updateRoleAttrAgile(int value){};//ROLECONSTCONFIG_ROLE_ATTR_AGILE
	virtual void updateRoleAttrDazeResist(int value){};//ROLECONSTCONFIG_ROLE_ATTR_DAZE_RESIST
	virtual void updateRoleAttrIntelligence(int value){};//ROLECONSTCONFIG_ROLE_ATTR_INTELLIGENCE
	virtual void updateRoleAttrPoisonResist(int value){};//ROLECONSTCONFIG_ROLE_ATTR_POISON_RESIST
	virtual void updateRoleAttrHitrate(int value){};//ROLECONSTCONFIG_ROLE_ATTR_HITRATE
	virtual void updateRoleAttrDodge(int value){};//ROLECONSTCONFIG_ROLE_ATTR_DODGE
	virtual void updateRoleAttrCriticalate(int value){};//ROLECONSTCONFIG_ROLE_ATTR_CRITICALATE
	virtual void updateRoleAttrCriticaldamage(int value){};//ROLECONSTCONFIG_ROLE_ATTR_CRITICALDAMAGE
	virtual void updateRoleAttrToughness(int value){};//ROLECONSTCONFIG_ROLE_ATTR_TOUGHNESS

	CC_SYNTHESIZE(std::vector<int>*, pathX, PathX);
	CC_SYNTHESIZE(std::vector<int>*, pathY, PathY);

	CC_SYNTHESIZE(LivingThing*, dataOwner, DataOwner);//数据所属entity
public:
	int tx;
	int ty;
	int res_bodyId;  //资源id
	float moveSpeed;  //速度
	std::string name; //名字
	int gender;       //性别
	int kind;         //npc类型
	int level;        //级别
	int currentHP;  //生命
	int currentMP;  //法力
	int totalHP;    //生命上限
	int totalMP;    //法力上限
	int dir;         //方向
	int state;       //状态
	int faction;     //职业
	int flag;       //生物标志
	int clothId;    //衣服ID
	int entryid;     //模板id
	int direction;  //初始动作方向
	std::vector<tPoint> movePath;  //移动路径
};