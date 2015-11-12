#include "PlayerData.h"
#include "GameGobal.h"
#include "DataManager.h"
#include "Frame.h"
#include "LivingThing.h"
#include "UIDefine.h"
#include "SceneController.h"
#include "GameDefine.h"

PlayerData::PlayerData(void)
{
	rolePos = ccp(0.0f,0.0f);
	tx = 93;
	ty = 54;
	moveSpeed = 7;
	mapId = -100;
}
PlayerData::~PlayerData(void)
{
}
void PlayerData::attributeInit(int attriId, int& value)
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
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LOOKS_ARM:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PK_MODEL:  //pk标志
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRIME_VALUE:  //罪恶值
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PACKSIZE: //包裹大小
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STORAGESIZE: //仓库大小
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_ENCHANT:  //升星套
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAXSOULPOWER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_VIPTAG: //Vip标志
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_POSTING:   //仙门职位
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILDTYPE: //仙门类型 	1为王国仙门 其他无意义
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SPIRITSPOWER: //灵魂力
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAXSPIRITSPOWER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CAMP_ID: //阵营信息 0为无阵营 1为红  2为蓝 (目前只在战场内有用)
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RIDEDISPLAY: //坐骑资源
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SERVERID: //服务器id		
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TREASURE_TRANSPORT: //镖车
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SOUL_WEAPON_EFFECT_KEY:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_TITLE_ICON_ID:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_AIRCRAFT_PHASE:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_WEDDING_STATE:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_POWER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_POWER:
		{

			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_POWER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_DEFENCE:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_DEFENCE:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_DEFENCE:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_FIGHTING_FORCE://战力
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POWER: //攻击
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HITRATE://命中
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DODGE://闪避
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALATE://暴击
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALDAMAGE://暴击伤害
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TOUGHNESS://韧性
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_AGILE://敏捷
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STRENGTH://力量*
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_INTELLIGENCE://智力
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STAMINA://体质
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_IMMUNITY://近程减免
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_IMMUNITY://远程减免
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_IMMUNITY://魔法减免
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_IMPRISONMENT_RESIST://定身抗性
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILENCE_RESIST://沉默抗性
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DAZE_RESIST://昏迷抗性
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POISON_RESIST://消弱抗性、中毒抵抗
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_NORMAL_RESIST://流血抗性、普通抵抗
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GOLD:   //元宝
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TICKET:   //礼券
		{
			break;
		}
	default:
		{
			CCLOG("unknown player int attr: %d", attriId);
			break;
		}
	}
}
void PlayerData::attributeInit(int attriId, std::string& value)
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
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MARRY_TITLE_NAME:
		{
			break;
		}
	default:
		{
			CCLOG("unknown player string attr: %d", attriId);
			break;
		}
	}
}
void PlayerData::attributeInit(int attriId, int64& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_EXPR:  //经验
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LEVELUPEXP:  //升级所需经验
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TOUCHRED:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MARRY_TITLE_ID:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_COMPANION_ROLE: //密修对象
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILVER:  //游戏币
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_BOUND_SILVER:  //游戏币
		{
			break;
		}
	default:
		{
			CCLOG("unknown player int64 attr: %d", attriId);
			break;
		}
	}
}
void PlayerData::attributeInit(int attriId, std::vector<int>& value)
{
	switch (attriId)
	{
	case ROLECONSTCONFIG_ROLE_ATTR_BODY_BUFFER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_BODY_BUFF_LEVEL:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HONOUR: //人物头衔
		{
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
	case ROLECONSTCONFIG_ROLE_ATTR_INSTANCE_TITLE_ICON_ID: //称号
		{
			break;
		}
	default:
		{
			CCLOG("unknown otherPlayer std::vector<int> attr: %d", attriId);
			break;
		}
	}
	
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
void PlayerData::attributeInit(int attriId, std::vector<std::string>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown player std::vector<std::string> attr: %d", attriId);
			break;
		}
	}
}
void PlayerData::attributeInit(int attriId, std::vector<int64>& value)
{
	switch (attriId)
	{
	default:
		{
			CCLOG("unknown player std::vector<int64> attr: %d", attriId);
			break;
		}
	}
}

void PlayerData::updateRoleBackpackSize(int value)
{
	

}
void PlayerData::updateRoleStorageSize(int value)
{
}
void PlayerData::updateRoleMoveSpeed(int value)
{
}
void PlayerData::updateRoleState(int value)
{


}
void PlayerData::updateRoleDispaly(int value)
{
}
void PlayerData::updateRoleName(std::string value)
{
	name = value;
}
void PlayerData::updateRolePosX(int value)
{
	tx = value;
}
void PlayerData::updateRolePosY(int value)
{
	ty = value;
}
void PlayerData::updateRoleTotalHP(int value)  //生命总值
{ 
	totalHP = value;

}
void PlayerData::updateRoleCurHP(int value)  //当前生命值
{
	currentHP = value;

}
void PlayerData::updateRoleTotalMP(int value)   //总法力值
{
	totalMP = value;

}
void PlayerData::updateRoleCurMP(int value) //当前法力值
{
	currentMP = value;
}
void PlayerData::updateRoleWork(int value)  //职业
{
}
void PlayerData::updateRoleLevel(int value)   //等级
{
	level = value;

}
void PlayerData::updateRoleGender(int value)
{
}
void PlayerData::updateRoleCurExp(int64 value)  //当前经验值
{
}
void PlayerData::vipAddRoleExp(int value)
{
}
void PlayerData::noVipAddExp(int value)
{
}
void PlayerData::updateRoleTotalExp(int64 value)  //总经验值
{
}
void PlayerData::updateRoleBoundSilver(int64 value)
{
}
void PlayerData::updateRoleSilver(int64 value)
{

}
void PlayerData::updateRoleTicket(int32 value)
{
}
void PlayerData::updateRoleGold(int32 value)
{
	
}
void PlayerData::updateRoleGuildName(std::string value)  //仙门
{
	
}
void PlayerData::updateRoleGuildPosition(int value)
{
	
}
void PlayerData::updateRoleClothe(int value)
{
	
}
void PlayerData::updateRoleWeapon(int value)
{
	
}
void PlayerData::updateRoleSuitStar(int value)
{
}
void PlayerData::updateRoleCrimeValue(int value)  //罪恶值
{
}
void PlayerData::updateRolePKSign(int value)
{
}
void PlayerData::updateRoleAttrHonour(int value)
{
}
void PlayerData::updateRoleCompanion(int64 value)
{
}
void PlayerData::updateRoleTotalSoulPower(int value)   //总灵力
{
}
void PlayerData::updateRoleCurSoulPower(int value)  //当前灵力
{
}
void PlayerData::vipAddSoulPower(int value)
{
}
void PlayerData::noVipAddSoulPower(int value)
{
}
void PlayerData::updateRoleVip(int value)
{
	
}
void PlayerData::updateRoleCamp(int value)
{
}
void PlayerData::updateRoleMount(int value)
{
	
}
void PlayerData::updateRoleInstanceTitle(int value)
{
}
void PlayerData::updateRoleTransport(int value)
{
	
}
void PlayerData::updateGuildNameColor(int value)
{
}
void PlayerData::updateSpiritePower(int value)
{
}
void PlayerData::updateSpiritePowerMax(int value)
{
}
void PlayerData::updateHonorData(int value)
{
}
void PlayerData::updateSoulWeaponEffect(int value)
{
}
void PlayerData::updataGuildTitleIcon(int value)
{
}
void PlayerData::updateAirCraft(int value)
{
}
void PlayerData::updateFereId(int value)
{
}
void PlayerData::updataFereName(int value)
{
}
void PlayerData::updateWedding(int value)
{
}

void PlayerData::updateRoleAttrFightingForce(int value)
{
	

}
void PlayerData::updateRoleAttrPower(int value)
{
	

}
void PlayerData::updateRoleAttrMeleeImmunity(int value) //近程减免
{
	

}
void PlayerData::updateRoleAttrDefendMelee(int value)   //近防
{
	

}
void PlayerData::updateRoleAttrRangeImmunity(int value)//远程减免
{
	

}
void PlayerData::updateRoleAttrDefendRange(int value) //远防
{
	

}
void PlayerData::updateRoleAttrMagicImmunity(int value)//魔法减免
{
	

}
void PlayerData::updateRoleAttrDefendMagic(int value)   //魔防
{
	
}
void PlayerData::updateRoleAttrImprisonmentResist(int value)  //定身抗性
{
	
}
void PlayerData::updateRoleAttrStamina(int value)//体质
{
	
}
void PlayerData::updateRoleAttrNormalResist(int value) //流血抗性
{
	

}
void PlayerData::updateRoleAttrStrength(int value)//力量
{
	

}
void PlayerData::updateRoleAttrSilenceResist(int value)//沉默抗性
{
	
}
void PlayerData::updateRoleAttrAgile(int value)//敏捷
{
	


}
void PlayerData::updateRoleAttrDazeResist(int value)//昏迷抗性
{
	

}
void PlayerData::updateRoleAttrIntelligence(int value)//智力
{
	

}
void PlayerData::updateRoleAttrPoisonResist(int value) //消弱抗性
{
	

}
void PlayerData::updateRoleAttrHitrate(int value)  //命中
{
	
}
void PlayerData::updateRoleAttrDodge(int value)//闪避
{
	

}
void PlayerData::updateRoleAttrCriticalate(int value) //暴击
{
	

}
void PlayerData::updateRoleAttrCriticaldamage(int value)  //暴伤
{
	

}
void PlayerData::updateRoleAttrToughness(int value)//韧性
{
}