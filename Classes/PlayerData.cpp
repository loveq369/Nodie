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
	case ROLECONSTCONFIG_ROLE_ATTR_LEVEL://�ȼ�
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
	case ROLECONSTCONFIG_ROLE_ATTR_DISPLAYID: //��Դid
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
	case ROLECONSTCONFIG_ROLE_ATTR_PK_MODEL:  //pk��־
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRIME_VALUE:  //���ֵ
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_PACKSIZE: //������С
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STORAGESIZE: //�ֿ��С
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_ENCHANT:  //������
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
	case ROLECONSTCONFIG_ROLE_ATTR_VIPTAG: //Vip��־
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILD_POSTING:   //����ְλ
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GUILDTYPE: //�������� 	1Ϊ�������� ����������
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SPIRITSPOWER: //�����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAXSPIRITSPOWER:
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CAMP_ID: //��Ӫ��Ϣ 0Ϊ����Ӫ 1Ϊ��  2Ϊ�� (Ŀǰֻ��ս��������)
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RIDEDISPLAY: //������Դ
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SERVERID: //������id		
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TREASURE_TRANSPORT: //�ڳ�
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
	case ROLECONSTCONFIG_ROLE_ATTR_FIGHTING_FORCE://ս��
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POWER: //����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_HITRATE://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DODGE://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALATE://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_CRITICALDAMAGE://�����˺�
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TOUGHNESS://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_AGILE://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STRENGTH://����*
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_INTELLIGENCE://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_STAMINA://����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MELEE_IMMUNITY://���̼���
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_RANGE_IMMUNITY://Զ�̼���
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_MAGIC_IMMUNITY://ħ������
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_IMPRISONMENT_RESIST://������
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILENCE_RESIST://��Ĭ����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_DAZE_RESIST://���Կ���
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_POISON_RESIST://�������ԡ��ж��ֿ�
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_NORMAL_RESIST://��Ѫ���ԡ���ͨ�ֿ�
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_GOLD:   //Ԫ��
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_TICKET:   //��ȯ
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
	case ROLECONSTCONFIG_ROLE_ATTR_EXPR:  //����
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_LEVELUPEXP:  //�������辭��
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
	case ROLECONSTCONFIG_ROLE_ATTR_COMPANION_ROLE: //���޶���
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_SILVER:  //��Ϸ��
		{
			break;
		}
	case ROLECONSTCONFIG_ROLE_ATTR_BOUND_SILVER:  //��Ϸ��
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
	case ROLECONSTCONFIG_ROLE_ATTR_HONOUR: //����ͷ��
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
	case ROLECONSTCONFIG_ROLE_ATTR_INSTANCE_TITLE_ICON_ID: //�ƺ�
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
void PlayerData::updateRoleTotalHP(int value)  //������ֵ
{ 
	totalHP = value;

}
void PlayerData::updateRoleCurHP(int value)  //��ǰ����ֵ
{
	currentHP = value;

}
void PlayerData::updateRoleTotalMP(int value)   //�ܷ���ֵ
{
	totalMP = value;

}
void PlayerData::updateRoleCurMP(int value) //��ǰ����ֵ
{
	currentMP = value;
}
void PlayerData::updateRoleWork(int value)  //ְҵ
{
}
void PlayerData::updateRoleLevel(int value)   //�ȼ�
{
	level = value;

}
void PlayerData::updateRoleGender(int value)
{
}
void PlayerData::updateRoleCurExp(int64 value)  //��ǰ����ֵ
{
}
void PlayerData::vipAddRoleExp(int value)
{
}
void PlayerData::noVipAddExp(int value)
{
}
void PlayerData::updateRoleTotalExp(int64 value)  //�ܾ���ֵ
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
void PlayerData::updateRoleGuildName(std::string value)  //����
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
void PlayerData::updateRoleCrimeValue(int value)  //���ֵ
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
void PlayerData::updateRoleTotalSoulPower(int value)   //������
{
}
void PlayerData::updateRoleCurSoulPower(int value)  //��ǰ����
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
void PlayerData::updateRoleAttrMeleeImmunity(int value) //���̼���
{
	

}
void PlayerData::updateRoleAttrDefendMelee(int value)   //����
{
	

}
void PlayerData::updateRoleAttrRangeImmunity(int value)//Զ�̼���
{
	

}
void PlayerData::updateRoleAttrDefendRange(int value) //Զ��
{
	

}
void PlayerData::updateRoleAttrMagicImmunity(int value)//ħ������
{
	

}
void PlayerData::updateRoleAttrDefendMagic(int value)   //ħ��
{
	
}
void PlayerData::updateRoleAttrImprisonmentResist(int value)  //������
{
	
}
void PlayerData::updateRoleAttrStamina(int value)//����
{
	
}
void PlayerData::updateRoleAttrNormalResist(int value) //��Ѫ����
{
	

}
void PlayerData::updateRoleAttrStrength(int value)//����
{
	

}
void PlayerData::updateRoleAttrSilenceResist(int value)//��Ĭ����
{
	
}
void PlayerData::updateRoleAttrAgile(int value)//����
{
	


}
void PlayerData::updateRoleAttrDazeResist(int value)//���Կ���
{
	

}
void PlayerData::updateRoleAttrIntelligence(int value)//����
{
	

}
void PlayerData::updateRoleAttrPoisonResist(int value) //��������
{
	

}
void PlayerData::updateRoleAttrHitrate(int value)  //����
{
	
}
void PlayerData::updateRoleAttrDodge(int value)//����
{
	

}
void PlayerData::updateRoleAttrCriticalate(int value) //����
{
	

}
void PlayerData::updateRoleAttrCriticaldamage(int value)  //����
{
	

}
void PlayerData::updateRoleAttrToughness(int value)//����
{
}