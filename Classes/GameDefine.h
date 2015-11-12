//9miao.com �׷�
#pragma once




#define LOGIN_IMAGE		"logo1.png"
#define LOADING_IMAGE	"logo1.png"
#define PLACEHOLDER_IMAGE		"placeholder.png"

/************************************************************************/
/* ʵ�����                                                                     */
/************************************************************************/
#define ENTITY_TYPE_NULL			-1		//entity����
#define ENTITY_TYPE_PLAYER			0
#define ENTITY_TYPE_OTHER_PLAYER	1
#define ENTITY_TYPE_NPC				2
#define ENTITY_TYPE_PET				3
#define ENTITY_TYPE_EXIT			5

#define ROLE_MONSTER        0
#define ROLE_NPC            1
#define REMOVEEFFECT_DISTANCE  10

#define POSE_STATE_NULL		0xffff0000
#define POSE_STATE_STAND	0x00000001	//element״̬
#define POSE_STATE_MOVE		0x00000002
#define POSE_STATE_ATTACK	0x00000004
#define POSE_STATE_DEAD		0x00000010
#define POSE_STATE_BEHIT	0x00000020
#define POSE_STATE_REBORN	0x00000040

#define ACTION_STAND 0
#define ACTION_STAND2 10
#define ACTION_RUN 1
#define ACTION_ATTACK1 2
#define ACTION_ATTACK2 20
#define ACTION_ATTACK3 200
#define ACTION_ATTACKED 3
#define ACTION_DIE 4
#define ACTION_SIT 5
#define ACTION_WALK 11
#define ACTION_WEDDINGS 12
#define ACTION_NOTMOVE 1
#define ACTION_NOTATTACK 2
#define ACTION_NOT_MOVE_ATTACK 3

//��Ӧ roledata �е� state
#define  CREATURE_STATE_DEAD 0            //����
#define  CREATURE_STATE_GAME 1            //����
#define  CREATURE_STATE_BLOCK_TRAINING 2  //���޴���
#define  CREATURE_STATE_SITDOWN 3         //����

//livingThing��Ⱦ˳��
typedef enum
{
	livingthing_zorder_bottom = 1,
	livingthing_zorder_shadow,
	livingthing_zorder_body,
	livingthing_zorder_weapon,
	livingthing_zorder_nameboard,
	livingthing_zorder_top
} livingThingZOrder;
//livingThing��Ⱦ˳��
typedef enum
{
	scene_zorder_bottom = 1,
	scene_zorder_frontBGLayer,
	scene_zorder_faceLayer,
	scene_zorder_mouseLayer,
	scene_zorder_elementLayer,
	scene_zorder_top
} sceneLayerZOrder;

/************************************************************************/
/* buff                                                                     */
/************************************************************************/
#define BUFF_STATE_NULL				0xffff0000//BUFF״̬
#define BUFF_STATE_NOTMOVE			0x00000001
#define BUFF_STATE_NOTATTACK		0x00000002
#define BUFF_STATE_NOT_MOVE_ATTACK	0x00000004

/************************************************************************/
/* AI                                                                     */
/************************************************************************/
#define AI_CHASE	0x0001//ai����
#define AI_ATTACK	0x0002
#define AI_FLEE		0x0004
#define AI_WALK		0x0008
#define AI_STAND	0x0010
#define AI_REBORN	0x0020

/************************************************************************/
/* npc���                                                                     */
/************************************************************************/
#define NPC_TYPE_FUN 1
#define NPC_TYPE_MONSTER 2
#define NPC_TYPE_COLLECTION 3
#define NPC_TYPE_GATE 4
#define NPC_TYPE_FIGHT_COLLECTION 5
#define NPC_TYPE_BIAOCHE 6
#define NPC_TYPE_KING_SITE 6
#define NPC_TYPE_KING_STATUS 7
#define NPC_KIND_NOT_SELECT 9
#define NPC_BEIDONG_TYPE 1
#define NPC_ZHUDONG_TYPE 2
#define NPC_BOSS_TYPE 3

#define TimerManagerTag		1
#define EffectManagerTag	2

/************************************************************************/
/* ��ͼ���                                                                     */
/************************************************************************/
#define MAP_TAG_NORMAL 0//��ͼ����
#define MAP_TAG_LITTLE_GARDEN 1
#define MAP_TAG_BLOCK_TRAINING 2
#define MAP_TAG_TANGLE_BATTLE 3
#define MAP_TAG_LOOP_TOWER 4
#define MAP_TAG_PRISON 5
#define MAP_TAG_SPA 6

#define CHAT_WIN_HEIGHT   600;

/************************************************************************/
/* ս�����                                                                     */
/************************************************************************/
#define ATT_MISS	1//������ʧ
#define ATT_CRIT	2//����
#define ATT_NORMAL	0//��ͨ
#define ATT_ATTRIBUIT	4//

/************************************************************************/
/* grid                                                                     */
/************************************************************************/
#define GRID_USED    2  //�Ѿ�ʹ��
#define GRID_FREE    1  //����
#define GRID_LOCKED  0  //�����ã�δ����
/************************************************************************/
/* ����type                                                                   */
/************************************************************************/
#define BAG_ARRANGE  1    //����
#define STORAGE_ARRANGE  2    //�ֿ�
/************************************************************************/
/* ����                                                                     */
/************************************************************************/
#define SKILL_TYPE_INITIATIVIE 1
#define SKILL_TYPE_INITIATIVIE_9 9
#define SKILL_TYPE_PRASSIVE 2
#define SKILL_TARTYPE_SELF 3
#define SKILL_TARTYPE_SELFANDTEAMMER 1
#define SKILL_TARTYPE_SELFANDENEMY 2
#define SKILL_TARTYPE_ENEMY 4
#define SKILL_ATTRANGETYPE_SINGLE 0
#define SKILL_ATTRANGETYPE_GROUP 1
#define SKILL_CHONG_FENG_SKILL_ID 530000003
#define SKILL_TENG_YUE_SKILL_ID 803000001

#define SKILL_TYPE_POINT_ON_SELF 1//����Ŀ������
#define SKILL_TYPE_POINT_TO_OTHER 2
#define SKILL_TYPE_SCOPE_ON_SELF 3
#define SKILL_TYPE_SCOPE_TO_OTHER 4

#define SKILL_NUM	11//������Ŀ

#define SKILL_COLLECT_ID	740000002//�ɼ�����

/************************************************************************/
/* �����                                                                     */
/************************************************************************/
#define SHORTCUT_TYPE_SKILL 1		//�������������
#define SHORTCUT_TYPE_GOODS 2
#define SHORTCUT_TYPE_PET 3
#define SHORTCUT_TYPE_MOUNT 4

/************************************************************************/
/* ��ɫ����                                                                     */
/************************************************************************/
#define RESPAWN_INPOINT					1//�ص����������ͨ����(�������)
#define RESPAWN_WITH_CHTHEAL_INSITU		2//��.����֮�ӻ�->��Ѫ����ԭ�ظ���(�������):Ҫ����
#define RESPAWN_WITH_CHTHEAL_INPOINT	3//�ص�������,��Ѫ����(PK����)
#define RESPAWN_NONEED_LEVEL			20//��Ѹ����

/************************************************************************/
/* ��Ч                                                                     */
/************************************************************************/

/*
#define EFFECT_PART_L_T		0//����	//��Ч����λ��
#define EFFECT_PART_M_T		1//����
#define EFFECT_PART_R_T		2//����
#define EFFECT_PART_L_M		3//����
#define EFFECT_PART_M_M		4//����
#define EFFECT_PART_R_M		5//����
#define EFFECT_PART_L_B		6//����
#define EFFECT_PART_M_B		7//����
#define EFFECT_PART_R_B		8//����*/

//const ��Ч
#define CONST_EFFECT_SELECT_YELLOW	"monsterClick"//ѡ�л�ɫ��Ч
#define CONST_EFFECT_PLAYER_LEVELUP	"levelup"//���������Ч
#define CONST_EFFECT_DEAD			"deadEffect"//������Ч

//һЩ�ر��id
#define COLLECT_FLAG_ID	740000001
#define COLLECT_ID		740000002
#define HOLD_KING_SITE	740000003
#define PRISON_MAPID	339//����

/************************************************************************/
/* ��Ϸ������                                                                     */
/************************************************************************/
static const int GAMECONFIGCONST_USER_PAY_STATUS = 1;
static const int GAMECONFIGCONST_IS_ORI_BLOOD = 2;
static const int GAMECONFIGCONST_USER_SHOP_WND_STATUS = 3;
static const int GAMECONFIGCONST_USER_CHAT_STATUS = 4;
static const int GAMECONFIGCONST_USER_FAGITUE_STATUS = 5;
static const int GAMECONFIGCONST_USER_REFRESH_GAME_DATA_STATUS = 6;
static const int GAMECONFIGCONST_USER_LOCALCONNECTION_STATUS = 7;
static const int GAMECONFIGCONST_USER_RANK_STATUS = 8;
static const int GAMECONFIGCONST_USER_PET_STATUS = 9;
static const int GAMECONFIGCONST_USER_TREASURE_CHEST_STATUS = 10;
static const int GAMECONFIGCONST_USER_BITMAP = 11;
static const int GAMECONFIGCONST_HEAD_BLOOD = 12;
static const int GAMECONFIGCONST_FULL_SCREEN = 14;
static const int GAMECONFIGCONST_SHOPPE_DATA_CLEAR = 15;
static const int GAMECONFIGCONST_VENATION_SYSTEM = 16;
static const int GAMECONFIGCONST_ENCHANT_SYSTEM = 17;
static const int GAMECONFIGCONST_ENHANCE_SYSTEM = 18;
static const int GAMECONFIGCONST_MONEYGAME_SYSTEM = 19;
static const int GAMECONFIGCONST_ZULONG_SYSTEM = 20;
static const int GAMECONFIGCONST_CHESSSPIRIT_SYSTEM = 21;
static const int GAMECONFIGCONST_VENATION_PROFICIENT = 22;
static const int GAMECONFIGCONST_ACTIVITY_POP_GUID_WND = 23;
static const int GAMECONFIGCONST_REFINE_SYSTEM_WND = 24;

/************************************************************************/
/* ��ɫ����                                                                     */
/************************************************************************/

//ְҵ
#define CLASS_MAGIC 1//��ʦ  ����
#define CLASS_RANGE 2//����  ����
#define CLASS_MELEE 3//��ʿ  ���

#define WALK_SPEED_BASE		22.36f	//�����ƶ��ٶ�	sqrt(5) * 10
#define WALK_SEND_SPEED		3//�ƶ����з����ٶ�
#define WALK_SEND_COUNT		4//�ƶ����з�����Ŀ

//action
#define PLAYER_ACTION_NATURL 0
#define PLAYER_ACTION_PK 1
#define PLAYER_ACTION_FOLLOW 2
#define PLAYER_ACTION_DIALOG 3
#define PLAYER_ACTION_GATE 4
#define PLAYER_ACTION_AUTOPATH 5
#define PLAYER_ACTION_COLLECT 6
#define PLAYER_ACTION_TRAINING 7
#define PLAYER_ACTION_COLLECT_FLAG 8
#define PLAYER_ACTION_COMPANION_SIT_ING 9
#define PLAYER_ACTION_HOLD_KING_SITE 10
#define PLAYER_ACITON_CAT_WALK 11
#define PLAYER_ACTION_PRACTICE 12

//PK
#define PK_IN_PEACE 0
#define PK_IN_PUNISH 1
#define PK_IN_GUILD 2
#define PK_IN_TEAM 3
#define PK_IN_ALL 4
#define PK_IN_COMPARE 100

////��������keyvalue��Ӧ///////
#define ROLECONSTCONFIG_ROLE_ATTR_CLASS 0  //ְҵ
#define ROLECONSTCONFIG_ROLE_ATTR_LEVEL 1  //����
#define ROLECONSTCONFIG_ROLE_ATTR_POSX 3  //λ��x
#define ROLECONSTCONFIG_ROLE_ATTR_POSY 4 //λ��y
#define ROLECONSTCONFIG_ROLE_ATTR_GENDER 5      //�Ա�
#define ROLECONSTCONFIG_ROLE_ATTR_STATE 6       //״̬
#define ROLECONSTCONFIG_ROLE_ATTR_ENCHANT 7   //������
#define ROLECONSTCONFIG_ROLE_ATTR_HP 11  //HP
#define ROLECONSTCONFIG_ROLE_ATTR_MP 12  //MP
#define ROLECONSTCONFIG_ROLE_ATTR_MPMAX 13      //���ħ��
#define ROLECONSTCONFIG_ROLE_ATTR_HPMAX 14      //���Ѫ��
#define ROLECONSTCONFIG_ROLE_ATTR_GOLD  17   //Ԫ��
#define ROLECONSTCONFIG_ROLE_ATTR_TICKET  18   //��ȯ
#define ROLECONSTCONFIG_ROLE_ATTR_GUILDTYPE  19   //������� 	1Ϊ������� ����������

#define ROLECONSTCONFIG_ROLE_ATTR_WEDDING_STATE 30  //�ǲ��ǽ��

#define ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER 50    //����
#define ROLECONSTCONFIG_ROLE_ATTR_MAXSOULPOWER 51    //�������
#define ROLECONSTCONFIG_ROLE_ATTR_SPIRITSPOWER 52    //�����
#define ROLECONSTCONFIG_ROLE_ATTR_MAXSPIRITSPOWER 53     //��������
#define ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER_VIP_ADD_ID 54   //
#define ROLECONSTCONFIG_ROLE_ATTR_SOULPOWER_NO_VIP_ADD 55    //
#define ROLECONSTCONFIG_ROLE_ATTR_SOUL_WEAPON_EFFECT_KEY 56  //

#define ROLECONSTCONFIG_ROLE_ATTR_HPRECOVER  201   //Ѫ���ظ�
#define ROLECONSTCONFIG_ROLE_ATTR_CRITICALDAMAGE 202      //�����˺�
#define ROLECONSTCONFIG_ROLE_ATTR_MPRECOVER 203      //ħ���ظ�
#define ROLECONSTCONFIG_ROLE_ATTR_MOVESPEED 204   //�ƶ��ٶ�
#define ROLECONSTCONFIG_ROLE_ATTR_MELEE_IMMUNITY  205 //���̼���
#define ROLECONSTCONFIG_ROLE_ATTR_RANGE_IMMUNITY 206 //Զ�̼���
#define ROLECONSTCONFIG_ROLE_ATTR_MAGIC_IMMUNITY 207 //ħ������
#define ROLECONSTCONFIG_ROLE_ATTR_HPMAX_PERCENT 208 //Ѫ���ٷֱ�
#define ROLECONSTCONFIG_ROLE_ATTR_MELEEPOWER_PERCENT 209 //�����ٷֱ�
#define ROLECONSTCONFIG_ROLE_ATTR_RANGEPOWER_PERCENT 210 //Զ���ٷֱ�
#define ROLECONSTCONFIG_ROLE_ATTR_MAGICPOWER_PERCENT 211 //ħ���ٷֱ�
#define ROLECONSTCONFIG_ROLE_ATTR_MOVESPEED_PERCENT 212 //�ƶ��ٶȰٷֱ�

#define ROLECONSTCONFIG_ROLE_ATTR_STAMINA 301 //����
#define ROLECONSTCONFIG_ROLE_ATTR_STRENGTH 302  //����
#define ROLECONSTCONFIG_ROLE_ATTR_INTELLIGENCE 303 //����
#define ROLECONSTCONFIG_ROLE_ATTR_AGILE 304  //����
#define ROLECONSTCONFIG_ROLE_ATTR_MAGIC_POWER 305 //ħ��
#define ROLECONSTCONFIG_ROLE_ATTR_MELEE_POWER 306 //����
#define ROLECONSTCONFIG_ROLE_ATTR_RANGE_POWER 307 //Զ��
#define ROLECONSTCONFIG_ROLE_ATTR_MELEE_DEFENCE 308 //����
#define ROLECONSTCONFIG_ROLE_ATTR_RANGE_DEFENCE 309 //Զ��
#define ROLECONSTCONFIG_ROLE_ATTR_MAGIC_DEFENCE 310 //ħ��
#define ROLECONSTCONFIG_ROLE_ATTR_HITRATE 311   //����
#define ROLECONSTCONFIG_ROLE_ATTR_DODGE 312     //����
#define ROLECONSTCONFIG_ROLE_ATTR_CRITICALATE 313      //����
#define ROLECONSTCONFIG_ROLE_ATTR_TOUGHNESS 314            //����
#define ROLECONSTCONFIG_ROLE_ATTR_POWER 315               //����

#define ROLECONSTCONFIG_ROLE_ATTR_PACKSIZE 401    //������С
#define ROLECONSTCONFIG_ROLE_ATTR_STORAGESIZE 402  //�ֿ��С

#define ROLECONSTCONFIG_ROLE_ATTR_IMPRISONMENT_RESIST 601 //������
#define ROLECONSTCONFIG_ROLE_ATTR_SILENCE_RESIST  602 //��Ĭ����
#define ROLECONSTCONFIG_ROLE_ATTR_DAZE_RESIST  603 //���Կ���
#define ROLECONSTCONFIG_ROLE_ATTR_POISON_RESIST  604 //�������ԡ��ж��ֿ�
#define ROLECONSTCONFIG_ROLE_ATTR_NORMAL_RESIST  605 //��Ѫ���ԡ���ͨ�ֿ�
#define ROLECONSTCONFIG_ROLE_ATTR_PK_MODEL 606     //pk��־
#define ROLECONSTCONFIG_ROLE_ATTR_CRIME_VALUE 607  //���ֵ

#define ROLECONSTCONFIG_ROLE_ATTR_CREATURE_FLAG 700    //�����־
#define ROLECONSTCONFIG_ROLE_ATTR_DISPLAYID 702   //��Դid
#define ROLECONSTCONFIG_ROLE_ATTR_PROTOID 703    //ģ��id

#define ROLECONSTCONFIG_ROLE_ATTR_GUILD_POSTING 805   //���ְλ
#define ROLECONSTCONFIG_ROLE_ATTR_LOOKS_CLOTH 907    //�·���ʾ
#define ROLECONSTCONFIG_ROLE_ATTR_LOOKS_ARM 908      //������ʾ
#define ROLECONSTCONFIG_ROLE_ATTR_VIPTAG 909       //Vip��־
#define ROLECONSTCONFIG_ROLE_ATTR_CAMP_ID 910  //��Ӫ��Ϣ 0Ϊ����Ӫ 1Ϊ��  2Ϊ�� (Ŀǰֻ��ս��������)
#define ROLECONSTCONFIG_ROLE_ATTR_RIDEDISPLAY 911    //������Դ
#define ROLECONSTCONFIG_ROLE_ATTR_SERVERID 912    //������id
#define ROLECONSTCONFIG_ROLE_ATTR_TREASURE_TRANSPORT 913    //�ڳ�
#define ROLECONSTCONFIG_ROLE_ATTR_FIGHTING_FORCE 914   //ս����
#define ROLECONSTCONFIG_ROLE_ATTR_HONOR 915   //����ֵ

#define ROLECONSTCONFIG_ROLE_ATTR_QQ_VIP_TYPE 919
#define ROLECONSTCONFIG_ROLE_ATTR_YELLOW_VIP_LEVEL 920
#define ROLECONSTCONFIG_ROLE_ATTR_IS_SUPER_QQ_VIP 926
#define ROLECONSTCONFIG_ROLE_ATTR_GUILD_TITLE_ICON_ID 924
#define ROLECONSTCONFIG_ROLE_ATTR_AIRCRAFT_PHASE 925

#define ROLECONSTCONFIG_ROLE_ATTR_NAME 1002  //����
#define ROLECONSTCONFIG_ROLE_ATTR_GUILD_NAME 1004     //�����
#define ROLECONSTCONFIG_ROLE_ATTR_PET_NAME 1005    //��������
#define ROLECONSTCONFIG_ROLE_ATTR_MARRY_TITLE_NAME 1006 //��������

#define ROLECONSTCONFIG_ROLE_ATTR_EXPR 2010   //����
#define ROLECONSTCONFIG_ROLE_ATTR_COMPANION_ROLE 2011      //���޶���
#define ROLECONSTCONFIG_ROLE_ATTR_EXP_VIP_ADD_ID 2012    //
#define ROLECONSTCONFIG_ROLE_ATTR_EXP_NO_VIP_ADD 2013    //
#define ROLECONSTCONFIG_ROLE_ATTR_LEVELUPEXP 2015    //�������辭��
#define ROLECONSTCONFIG_ROLE_ATTR_BOUND_SILVER  2016   //����Ϸ��
#define ROLECONSTCONFIG_ROLE_ATTR_SILVER  2017   //��Ϸ��

#define ROLECONSTCONFIG_ROLE_ATTR_MARRY_TITLE_ID 2030   //����id

#define ROLECONSTCONFIG_ROLE_ATTR_TOUCHRED 2701    //Ⱦ��
#define ROLECONSTCONFIG_ROLE_ATTR_TARGETID 2702    //Ŀ��

#define ROLECONSTCONFIG_ROLE_ATTR_ID 2800       //����ID		bigint
#define ROLECONSTCONFIG_ROLE_ATTR_PET_ID 2801   //����id	

#define ROLECONSTCONFIG_ROLE_ATTR_HONOUR 3005         //����ͷ��
#define ROLECONSTCONFIG_ROLE_ATTR_BODY_BUFFER 3006    //��������buffer
#define ROLECONSTCONFIG_ROLE_ATTR_BODY_BUFF_LEVEL 3007   //buffer�ȼ�

#define ROLECONSTCONFIG_ROLE_ATTR_PATH_X 3108   //�ƶ�·��x����
#define ROLECONSTCONFIG_ROLE_ATTR_PATH_Y 3109   //�ƶ�·��y����
#define ROLECONSTCONFIG_ROLE_ATTR_INSTANCE_TITLE_ICON_ID 3111  // �ƺ�

#define ROLECONSTCONFIG_PET_ATTR_HONOUR 5005   //����ͷ��


/////////////��Ʒ����keyvalue��Ӧ///////////
#define ROLECONSTCONFIG_ITEM_ATTR_ENCH 501
#define ROLECONSTCONFIG_ITEM_ATTR_COUNT 502
#define ROLECONSTCONFIG_ITEM_ATTR_SLOT 503
#define ROLECONSTCONFIG_ITEM_ATTR_ISBONDED 504
#define ROLECONSTCONFIG_ITEM_ATTR_DURATION 506
#define ROLECONSTCONFIG_ITEM_ATTR_OWNERID 507
#define ROLECONSTCONFIG_ITEM_ATTR_TEMPLATE_ID 508
#define ROLECONSTCONFIG_ITEM_ATTR_LEFTTIME 509
#define ROLECONSTCONFIG_ITEM_ATTR_SOCKETS 3509

/////////////����//////////////////
#define ROLECONSTCONFIG_PET_QUALITY 551   //��������
#define ROLECONSTCONFIG_PET_GROWTH 552   //����ɳ�ֵ
#define ROLECONSTCONFIG_PET_PROTO 553   //����ģ��
#define ROLECONSTCONFIG_PET_QUALITY_VALUE 554     //
#define ROLECONSTCONFIG_PET_LEARN_SKILL_NUM 555   //
#define ROLECONSTCONFIG_PET_TRANSFORM 556 //
#define ROLECONSTCONFIG_PET_LEVELUP_LEFT_TIME 557 //
#define ROLECONSTCONFIG_PET_HAPPINESS 560 //
#define ROLECONSTCONFIG_PET_LIFE_WASH 561 //
#define ROLECONSTCONFIG_PET_MAGIC_ATTATCK_WASH 562 //
#define ROLECONSTCONFIG_PET_FAR_ATTACK_WASH 563 //
#define ROLECONSTCONFIG_PET_NEAR_ATTACK_WASH 564 //
#define ROLECONSTCONFIG_PET_MAGIC_ANTI_WASH 565 //
#define ROLECONSTCONFIG_PET_FAR_ANTI_WASH 566 //
#define ROLECONSTCONFIG_PET_NEAR_ANTI_WASH 567 //
#define ROLECONSTCONFIG_PET_POINT_HIT 568 //
#define ROLECONSTCONFIG_PET_POINT_CRIT 569 //
#define ROLECONSTCONFIG_PET_POINT_STAMINA 570 //
#define ROLECONSTCONFIG_PET_POINT_REMAIN 571 //
#define ROLECONSTCONFIG_PET_QUALITYWX_MAX 573 //
#define ROLECONSTCONFIG_PET_TRADE_STATE 574 //
#define ROLECONSTCONFIG_PET_MASTER 2020  //��������
#define ROLECONSTCONFIG_PET_TALENTS 3008  //�����츳
/************************************************************************/
/* ����                                                                     */
/************************************************************************/
#define FRIEND_TYPE_MY_FRIEND 0
#define FRIEND_TYPE_ENEMY 1
#define FRIEND_TYPE_BLACK 2
#define FRIEND_TYPE_RECENT 3
#define HAOYOUDU_LEVEL 801000500
#define FRIEND_PANEL_ADD 0
#define FRIEND_PANEL_INVEITE 1
/************************************************************************/
/* grid���                                                                     */
/************************************************************************/
#define GRID_TYPE_NULL	0	//ʲô������
#define GRID_TYPE_SKILL	1	//����
#define GRID_TYPE_ITEM	2	//����
/************************************************************************/
/* grid��Դ                                                                     */
/************************************************************************/
#define GRID_SRC_BAG	1	//����
#define GRID_SRC_EQUIP	2	//����
#define GRID_SRC_SKILL	3	//����
#define GRID_SRC_AUTOGAME_SKILL	4	//�һ�����
#define GRID_SRC_SHORTCUT		5	//�����
#define GRID_SRC_MAIL		6	//����
#define GRID_SRC_STORE   7 //�̵�
#define GRID_SRC_GUILD_STORAGE   8 //���Ųֿ�
#define GRID_SRC_NPC_STORAGE   9 //���Ųֿ�
#define GRID_SRC_SHORTCUT_CFG 9  //�������������

/************************************************************************/
/* ��Ϸ������ݽṹ                                                                     */
/************************************************************************/

class tRoleInfo
{
public:
	int64 roleid;
	std::string name;
	int lastmapid;
	int classType;
	int gender;
	int level;
public:
	tRoleInfo()
	{
		roleid = 0;
		name = "";
		lastmapid = 0;
		classType = 0;
		gender = 0;
		level = 0;
	}
};
class tLineInfo
{
public:
	int lineId;
	int roleCount;
public:
	tLineInfo()
	{
		lineId = -1;
		roleCount = 0;
	}
};

//������������(���ñ�)
typedef struct LivingThingConfigData
{
	int typeId;
	std::string name;
	std::string resPath;
	LivingThingConfigData()
	{
		typeId = -1;
		resPath = "";
		name = "";
	}
}cLivingThingData;
//������������(���ñ�)
typedef struct MonsterConfigData: public cLivingThingData
{
	float moveSpeed;
	MonsterConfigData()
	{
		moveSpeed = 0.0f;
	}
}cMonsterData;
//npc��������(���ñ�)
typedef struct NpcConfigData: public cLivingThingData
{
}cNpcData;
//������������
typedef struct SkillLevelConfigData
{
	int8 level;
	int8 learnLv;
	int damageMp;
	std::string desc;
	int money;
	int soulPowerCost;
	std::vector<int> foreSkill;
	std::vector<int> petSkillOrder;
	SkillLevelConfigData()
	{
		level = 0;
		learnLv = 0;
		damageMp = 0;
		desc = "";
		money = 0;
		soulPowerCost = 0;
	}
}cSkillLevelConfigData;
class cSkillData//���ܾ�̬����
{
public:
	int id;//����id
	int distance;//ʩ������
	int coldTimer;//��ȴʱ��
	int delayTimer;//ʩ��ʱ��
	int classType;//ְҵ
	int pos;//ͼ��UIλ��
	int act;//���ö���
	std::string selfEff;//������Ч
	int selfIndex;//
	std::string targetEff;//Ŀ����Ч
	int targetIndex;//
	std::string flyEff;//������Ч
	int flySpeed;//������Ч�ٶ�
	int8 targetHitPoint;//Ŀ����е�
	int soundId;//��������
	int targetSoundId;//Ŀ������
	std::string name;//��������
	int8 skillType;//��������
	int8 targetType;//Ŀ������
	int8 attRangeType;//
	std::string descs;//��������
	int spellTime;//
	std::string url;//ͼƬicon
	std::vector<int> protoids;//
	std::vector<cSkillLevelConfigData> levels;//
public:
	cSkillData()
	{
		id = -1;
		distance = 0;
		coldTimer = 0;
		delayTimer = 0;
		classType = 0;
		pos = -1;
		act = 0;
		selfEff = "";
		selfIndex = 0;
		targetEff = "";
		targetIndex = 0;
		flyEff = "";
		flySpeed = 0;
		targetHitPoint = 0;
		soundId = 0;
		targetSoundId = 0;
		name = "";
		skillType = 0;
		targetType = 0;
		attRangeType = 0;
		descs = "";
		spellTime = 0;
		url = "";
	}
};
class tSkillData//���ѧϰ�˵ļ�������
{
public:
	int id;
	int level;
	int leftTime;
	int typeByInstance;//�ڸ����еļ�������
	cSkillData* configData;
public:
	tSkillData()
	{
		id = 0;
		level = 0;
		leftTime = 0;
		typeByInstance=0;
		configData = NULL;
	}
};
//
typedef struct GAMECONFIG
{
	int use_pay;
	int use_pk;
	int use_shop;
	int use_chat;
	int use_fagitue;
	int use_localconnection;
	int use_rank_refresh;
	int user_pet;
	int use_treasure_chest;
	int use_user_bitmap;
	int show_head_blood;
	int is_ori_blood;
	int is_venation_system;
	int is_venation_proficient_system;
	int is_enchant_system;
	int is_enhance_system;
	int is_moneygame_system;
	int is_zulong_system;
	int is_chessspirit_system;
	int is_pop_activity_guid;
	int is_refine;
	std::string userOpLogUrl;
	GAMECONFIG()
	{
		use_pay = 0;
		use_pk = 0;
		use_shop = 0;
		use_chat = 1;
		use_fagitue = 0;
		use_localconnection = 0;
		use_rank_refresh = 0;
		user_pet = 0;
		use_treasure_chest = 0;
		use_user_bitmap = 0;
		show_head_blood = 0;
		is_ori_blood = 1;
		is_venation_system = 1;
		is_venation_proficient_system = 1;
		is_enchant_system = 1;
		is_enhance_system = 1;
		is_moneygame_system = 1;
		is_zulong_system = 1;
		is_chessspirit_system = 1;
		is_pop_activity_guid = 0;
		is_refine = 1;
		userOpLogUrl = "";
	}
}tGameConfig;


class StarUnitAttData
{
public:
	int slot;//ss:slot(������ߺ��ұ߰���λ��)       
	int level;//level(���ǵȼ�)
	int status;// status(int)
	int id; //id(����id)          
	int exp;// exp(���Ǿ��飬������)     
	int quality;// quality������Ʒ�ʣ�
public:
	StarUnitAttData()
	{
		slot = 0;
		level = 0;
		status = 0;		
		id = 0;
		exp = 0;
		quality = 0;
	}
};
//typedef struct StarPanelUnitData
//{
//	int money;
//	int position;
//	int startTime;
//	std::vector<tStarUnitAttData> starInfos;
//	StarPanelUnitData()
//	{
//		money = 0;
//		position = 0;
//		startTime=0;
//	}
//}tStarPanelUnitData;

typedef struct DanMedicineQueueData
{
	int id;
	int num;
	int state;
	int danMedicineId;
	int queueRemainedTime;
	int createPillRemainedtime;
	DanMedicineQueueData()
	{
		id = 0;
		num = 0;
		state = 0;
		danMedicineId = 0;
		queueRemainedTime = 0;
		createPillRemainedtime = 0;
	}

}tDanMedicineQueueData;
typedef struct DanMedicineAttribData
{
	int attribValue;
	int pillID;
	DanMedicineAttribData()
	{
		attribValue = 0;
		pillID = 0;
	}
}tDanMedicineAttribData;

typedef struct UnitData
{
	int64 id;// ������������ID
	int32 damageType;// �˺�����
	int32 damage;// �˺�ֵ
	UnitData()
	{
		id = 0;
		damageType = 0;
		damage = 0;
	}
}tUnitData;
class tBeAttackData
{
public:
	int64 enemyId;// ��������ŵ�ID
	int skillId;
	std::vector<tUnitData> units;
	int flyTime;
public:
	tBeAttackData()
	{
		enemyId = 0;
		skillId = 0;
		flyTime = 0;
	}
};
class tBeKillData
{
public:
	int64 id;// ��KILL������ID
	std::string murderer;// KILL���������������
	int32 deadType;//������ʽ:1����,2pk
	tPoint tp;// ����λ��
	int32 seriesKills;//��ն��
public:
	tBeKillData()
	{
		id = 0;
		murderer = "";
		deadType = 1;
		tp.x = 0;
		tp.y = 0;
		seriesKills = 0;
	}
};
class tAttackData
{
public:
	int flyTime;
	int damageType;
	int skillId;
	int delayTime;
	int64 target;
	int64 attacker;
public:
	tAttackData()
	{
		flyTime = 0;
		damageType = 0;
		skillId = 0;
		delayTime = 0;
		target = 0;
		attacker = 0;
	}
};


