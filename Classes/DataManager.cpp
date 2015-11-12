#include "DataManager.h"
#include "GameDefine.h"
#include "GameGobal.h"
#include <fstream>
#include "SceneController.h"
#include "UIDefine.h"
#include "PlistManager.h"
#include "PlayerController.h"
#include "NPCData.h"
#include "TaskController.h"
USING_NS_CC;

//初始化字体文件
void initDFont()
{
	
}


/************************************************************************/
/*  静态数据                                                                    */
/************************************************************************/

#define NPC_PROTO_DATA_PATH "data/create_proto.bin"
#define SKILL_DATA_PATH		"data/skill.bin"
#define PLIST_PATH			"data/animation.pbin"
#define ANIM_PATH			"data/animation.abin"
#define PARTICLE_PATH		"data/particle.bin"
#define EFFECT_PATH			"data/effect.bin"
#define ITEM_DATA_PATH		"data/item_template.bin"
#define BUFF_DATA_PATH		"data/buff.bin"
#define GOALS_DATA_PATH		"data/goals.bin"
#define GUILD_FACILITIES_DATA_PATH		"data/guild_facilities.bin"
#define GUILD_TREASURE_CONFIG_DATA_PATH		"data/guild_treasure_items.bin"
#define SCENE_MUSIC_DATA_PAHT            "data/sceneMusic.bin" 
#define DISPLAY_EFFECT_DATA_PATH	"data/display_effect.bin"
#define NOOB_DATA_PATH	"data/noob_guide.bin"


enum tag
{
	DATA_TAG_INTERNATE     ,//国际化
	DATA_TAG_ANIM_PLIST    ,//动画plist
	DATA_TAG_UI_PLIST      ,//ui plist
	DATA_TAG_ANIM_DATA     ,//动画数据
	DATA_TAG_PARTICLE	   ,//粒子特效
	DATA_TAG_EFFECT		   ,//特效数据
	DATA_TAG_NPC		   ,//npc怪物数
	DATA_TAG_SKILL		   ,//技能数据
	DATA_TAG_ITEM		   ,//道具数据
	DATA_TAG_ITEM_A		   ,//道具数据
	DATA_TAG_ITEM_B		   ,//道具数据
	DATA_TAG_ITEM_C		   ,//道具数据
	DATA_TAG_ITEM_D		   ,//道具数据
	DATA_TAG_ITEM_E		   ,//道具数据
	DATA_TAG_ITEM_F		   ,//道具数据
	DATA_TAG_BUFF		   ,//buff
	DATA_TAG_GOALS		   ,//目标
	DATA_TAG_MAP		   ,//地图数据
	DATA_TAG_GUILD_FACI	   ,//帮会faci
	DATA_TAG_GUILD_TREA	   ,//帮会trea
	DATA_TAG_INSTANCE	   ,//副本
	DATA_TAG_ACHIEVE	   ,//achieve
	DATA_TAG_PET		   ,//宠物
	DATA_TAG_VENATION	   ,//venatio
	DATA_TAG_FULI		   ,//活动福利
	DATA_TAG_OPEN_SERVER   ,//开服活
	DATA_TAG_SCENE_EFFECT  ,//场景
	DATA_TAG_EVERQUEST	   ,//日常任务
	DATA_TAG_SCENEMUSIC    ,//背景音乐
	DATA_TAG_DANMEDICINE   ,//丹药
	DATA_TAG_DANLU         ,//丹炉
	DATA_TAG_ZHANXING      ,//占星
	DATA_TAG_ANSWER        ,//答题
	DATA_TAG_BATTLE_FIELD  ,//战场
	DATA_TAG_NOOB,			//新手
	DATA_TAG_FONT,			//字体
	DATA_TAG_FONT_FILE,		//字体文件 
	DATA_TAG_PLAYER,        //玩家数据
	DATA_TAG_TASK,

	DATA_TAG_UI_COMMON_1		           ,//
	DATA_TAG_UI_COMMON_SUDOKU_1            ,//
	DATA_TAG_UI_ACHIEVE	                   ,//
	DATA_TAG_UI_CHAT		                ,//
	DATA_TAG_UI_DANMEDICINE                 ,//
	DATA_TAG_UI_GUILD                       ,//
	DATA_TAG_UI_HEADIMAGE                   ,//
	DATA_TAG_UI_MENUBARBTN                  ,//
	DATA_TAG_UI_MOLD                        ,//
	DATA_TAG_UI_PET                         ,//
	DATA_TAG_UI_ROLE                        ,//
	DATA_TAG_UI_SMALLMAP                    ,//
	DATA_TAG_UI_SHOP                        ,//
	DATA_TAG_UI_SKILL                       ,//
	DATA_TAG_UI_SOCIETY                     ,//
	DATA_TAG_UI_VENATION                    ,//
	DATA_TAG_UI_NPC_TITLE                   ,//
	DATA_TAG_UI_NPC_TITLE_1                 ,//
	DATA_TAG_UI_ROLE_TOP_TITLE              ,//
	DATA_TAG_UI_NPC_DIALOG                  ,//
	DATA_TAG_UI_NPC_DIALOG_1                ,//
	DATA_TAG_UI_NPC_HEAD              ,//

	DATA_TAG_ERROR         ,//错误信息
	DATA_TAG_DISPLAYEFFECT	,//模型特效数据
};

DataManager::DataManager()
{
	_mapData = NULL;
	_mapData=new Tmx2MapData();
}

DataManager::~DataManager()
{
	CC_SAFE_DELETE(_mapData);
}

void DataManager::loadRes()
{
	waitInitDataQueue.push(DATA_TAG_INTERNATE);
	waitInitDataQueue.push(DATA_TAG_UI_COMMON_1);
	waitInitDataQueue.push(DATA_TAG_UI_COMMON_SUDOKU_1);
	waitInitDataQueue.push(DATA_TAG_UI_ACHIEVE);
	waitInitDataQueue.push(DATA_TAG_UI_DANMEDICINE);
	waitInitDataQueue.push(DATA_TAG_UI_HEADIMAGE);
	waitInitDataQueue.push(DATA_TAG_UI_MENUBARBTN);
	waitInitDataQueue.push(DATA_TAG_UI_MOLD);
	waitInitDataQueue.push(DATA_TAG_UI_PET);
	waitInitDataQueue.push(DATA_TAG_UI_ROLE);
	waitInitDataQueue.push(DATA_TAG_UI_SMALLMAP);
	waitInitDataQueue.push(DATA_TAG_UI_SHOP);
	waitInitDataQueue.push(DATA_TAG_UI_SKILL);
	waitInitDataQueue.push(DATA_TAG_UI_SOCIETY);
	waitInitDataQueue.push(DATA_TAG_UI_VENATION);
	waitInitDataQueue.push( DATA_TAG_UI_NPC_TITLE);	
	waitInitDataQueue.push( DATA_TAG_UI_NPC_TITLE_1);	
	waitInitDataQueue.push( DATA_TAG_UI_NPC_DIALOG);	
	waitInitDataQueue.push( DATA_TAG_UI_NPC_DIALOG_1);	
	waitInitDataQueue.push( DATA_TAG_UI_ROLE_TOP_TITLE);
	waitInitDataQueue.push(DATA_TAG_PLAYER);
	waitInitDataQueue.push(DATA_TAG_NPC);
	waitInitDataQueue.push(DATA_TAG_TASK);
	waitInitDataQueue.push(DATA_TAG_UI_NPC_HEAD);
	waitInitDataQueue.push(DATA_TAG_EFFECT);
	GameGobal::getInstance().getLoadingLayer()->addTotalSize(waitInitDataQueue.size());
		
}
static int step = 0;//数据加载step
static int step2 = 0;
bool DataManager::loadResTick(float dt)
{
	if (waitInitDataQueue.size()==0)
	{
		step2++;
		if (step2>5)
		{
			step2 = 0;
			return true;//加载结束
		}
		return false;
	}
	long startTime = TimeUtil::getInstance().getTimer();//@@temp
	int tag = waitInitDataQueue.front();

	step++;
	// 	if (step < 10)
	// 	{
	// 		return false;
	// 	}

	if (step<2)//2帧加一个
	{
		return false;
	}
	step = 0;
	switch (tag)
	{
	case DATA_TAG_INTERNATE:
		{
			InternationManager::getInstance().readData("locale/zh_CN.properties");
			initPlayerAttrStr();
			break;
		}
	case DATA_TAG_UI_COMMON_1:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_COMMON_1_PLIST);
			break;
		}
	case DATA_TAG_UI_COMMON_SUDOKU_1:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_COMMON_SUDOKU_1_PLIST);
			break;
		}
	case DATA_TAG_UI_ACHIEVE:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_ACHIEVE_PLIST);
			break;
		}
	case DATA_TAG_UI_CHAT:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_CHAT_PLIST);
			break;
		}
	case DATA_TAG_UI_DANMEDICINE:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_DANMEDICINE_PLIST);
			break;
		}
	case DATA_TAG_UI_GUILD:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_GUILD_PLIST);
			break;
		}
	case DATA_TAG_UI_HEADIMAGE:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_HEADIMAGE_PLIST);
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("head.plist");
			break;
		}
	case DATA_TAG_UI_MENUBARBTN:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_MENUBARBTN_PLIST);
			break;
		}
	case DATA_TAG_UI_MOLD:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_MOLD_PLIST);
			break;
		}
	case DATA_TAG_UI_PET:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_PET_PLIST);
			break;
		}
	case DATA_TAG_UI_ROLE:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_ROLE_PLIST);
			break;
		}
	case DATA_TAG_UI_SMALLMAP:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_SMALLMAP_PLIST);
			break;
		}
	case DATA_TAG_UI_SHOP:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_SHOP_PLIST);
			break;
		}
	case DATA_TAG_UI_SKILL:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_SKILL_PLIST);
			break;
		}
	case DATA_TAG_UI_SOCIETY:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_SOCIETY_PLIST);
			break;
		}
	case DATA_TAG_UI_VENATION:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_VENATION_PLIST);
			break;
		}
	case DATA_TAG_UI_NPC_TITLE:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_NPC_TITLE_PLIST);
			break;
		}
	case DATA_TAG_UI_NPC_TITLE_1:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_NPC_TITLE_1_PLIST);
			break;
		}
	case DATA_TAG_UI_NPC_DIALOG:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_NPC_DIALOG_PLIST);
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(UI_NEW_NPC_DIALOG);
			break;
		}
	case DATA_TAG_UI_NPC_HEAD:
		{
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(UI_NPC_HEAD);
			break;
		}
	case DATA_TAG_UI_NPC_DIALOG_1:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_NPC_DIALOG_1_PLIST);
			break;
		}
	case DATA_TAG_UI_ROLE_TOP_TITLE:
		{
			PlistManager::getInstance().addUISpriteFrames(UI_ROLE_TOP_TITLE_PLIST);
			break;
		}
	case DATA_TAG_PLAYER:
		{
			PlayerController::getInstance().getRoleData()->setid(0);
			PlayerController::getInstance().getRoleData()->setTx(19);
			PlayerController::getInstance().getRoleData()->setTy(52);
			PlayerController::getInstance().getRoleData()->setCurrentHP(100);
			PlayerController::getInstance().getRoleData()->setTotalHP(150);
			PlayerController::getInstance().getRoleData()->setCurrentMP(100);
			PlayerController::getInstance().getRoleData()->setTotalMP(100);;
			PlayerController::getInstance().getRoleData()->setGender(1);
			PlayerController::getInstance().getRoleData()->setFaction(1);
			PlayerController::getInstance().getRoleData()->setLevel(1);
			PlayerController::getInstance().getRoleData()->setMoveSpeed(7);
			PlayerController::getInstance().getRoleData()->setKind(0);
			std::string name="纪宁";
			GBKToUTF8(name,"gb2312","utf-8");
			PlayerController::getInstance().getRoleData()->setName(name);
			break;
		}
	case DATA_TAG_NPC:
		{
			NpcData * npc1001=new NpcData();
			npc1001->entryid=132100000;
			npc1001->res_bodyId=132100000;
			npc1001->currentHP=50;
			npc1001->totalHP=100;
			npc1001->currentMP=100;
			npc1001->totalMP=100;
			npc1001->flag=NPC_TYPE_FUN;
			npc1001->kind=ENTITY_TYPE_NPC;
			npc1001->tx=33;
			npc1001->ty=48;
			npc1001->direction=4;
			std::string nameNpc001="李敬南";
			GBKToUTF8(nameNpc001,"gb2312","utf-8");
			npc1001->name=nameNpc001;

			NpcData * npc112000000=new NpcData();
			npc112000000->entryid=112000000;
			npc112000000->res_bodyId=112000000;
			npc112000000->currentHP=50;
			npc112000000->totalHP=100;
			npc112000000->currentMP=100;
			npc112000000->totalMP=100;
			npc112000000->flag=NPC_TYPE_FUN;
			npc112000000->kind=ENTITY_TYPE_NPC;
			npc112000000->tx=18;
			npc112000000->ty=70;
			npc112000000->direction=8;
			std::string nameNpc112000000="王雪";
			GBKToUTF8(nameNpc112000000,"gb2312","utf-8");
			npc112000000->name=nameNpc112000000;
			SceneController::getInstance().getSceneManager()->addToNpcQueue(npc112000000);
			SceneController::getInstance().getSceneManager()->addToNpcQueue(npc1001);
			break;
		}
	case DATA_TAG_TASK:
		{
			TaskController::getInstance().init();
			break;
		}
	case DATA_TAG_EFFECT:
		{
			EffectManager::getInstance().readData(EFFECT_PATH);
			break;
		}
	}
	long endTime = TimeUtil::getInstance().getTimer();//@@temp
	CCLOG("load data(data tag:%d) consume time: %d", tag, endTime-startTime);//@@temp
	GameGobal::getInstance().getLoadingLayer()->addCurreSize(1);
	waitInitDataQueue.pop();
	return false;
}
void DataManager::initPlayerAttrStr()
{
	std::map<int, std::string> keyDic;
	keyDic.insert(std::map<int, std::string>::value_type(0, "general_label_0005"));
	keyDic.insert(std::map<int, std::string>::value_type(1, "general_label_0003"));
	keyDic.insert(std::map<int, std::string>::value_type(10, "role_label_0330"));
	keyDic.insert(std::map<int, std::string>::value_type(14, "role_label_0010"));
	keyDic.insert(std::map<int, std::string>::value_type(13, "role_label_0060"));
	keyDic.insert(std::map<int, std::string>::value_type(11, "role_label_0360"));
	keyDic.insert(std::map<int, std::string>::value_type(12, "role_label_0370"));
	keyDic.insert(std::map<int, std::string>::value_type(100, "role_label_0380"));
	keyDic.insert(std::map<int, std::string>::value_type(101, "role_label_0390"));
	keyDic.insert(std::map<int, std::string>::value_type(102, "role_label_0400"));
	keyDic.insert(std::map<int, std::string>::value_type(201, "role_label_0410"));
	keyDic.insert(std::map<int, std::string>::value_type(202, "role_label_0420"));
	keyDic.insert(std::map<int, std::string>::value_type(203, "role_label_0430"));
	keyDic.insert(std::map<int, std::string>::value_type(204, "role_label_0440"));
	keyDic.insert(std::map<int, std::string>::value_type(205, "role_label_0200"));
	keyDic.insert(std::map<int, std::string>::value_type(206, "role_label_0206"));
	keyDic.insert(std::map<int, std::string>::value_type(207, "role_label_0220"));
	keyDic.insert(std::map<int, std::string>::value_type(301, "role_label_0110"));
	keyDic.insert(std::map<int, std::string>::value_type(302, "role_label_0120"));
	keyDic.insert(std::map<int, std::string>::value_type(304, "role_label_0140"));
	keyDic.insert(std::map<int, std::string>::value_type(303, "role_label_0130"));
	keyDic.insert(std::map<int, std::string>::value_type(1301, "role_label_0110"));
	keyDic.insert(std::map<int, std::string>::value_type(1302, "role_label_0120"));
	keyDic.insert(std::map<int, std::string>::value_type(1304, "role_label_0140"));
	keyDic.insert(std::map<int, std::string>::value_type(1303, "role_label_0130"));
	keyDic.insert(std::map<int, std::string>::value_type(2301, "role_label_0110"));
	keyDic.insert(std::map<int, std::string>::value_type(2302, "role_label_0120"));
	keyDic.insert(std::map<int, std::string>::value_type(2304, "role_label_0140"));
	keyDic.insert(std::map<int, std::string>::value_type(2303, "role_label_0130"));
	keyDic.insert(std::map<int, std::string>::value_type(3301, "role_label_0110"));
	keyDic.insert(std::map<int, std::string>::value_type(3302, "role_label_0120"));
	keyDic.insert(std::map<int, std::string>::value_type(3304, "role_label_0140"));
	keyDic.insert(std::map<int, std::string>::value_type(3303, "role_label_0130"));
	keyDic.insert(std::map<int, std::string>::value_type(305, "role_label_0070"));
	keyDic.insert(std::map<int, std::string>::value_type(306, "role_label_0050"));
	keyDic.insert(std::map<int, std::string>::value_type(307, "role_label_0030"));
	keyDic.insert(std::map<int, std::string>::value_type(308, "role_label_0080"));
	keyDic.insert(std::map<int, std::string>::value_type(309, "role_label_0090"));
	keyDic.insert(std::map<int, std::string>::value_type(310, "role_label_0100"));
	keyDic.insert(std::map<int, std::string>::value_type(311, "role_label_0150"));
	keyDic.insert(std::map<int, std::string>::value_type(312, "role_label_0180"));
	keyDic.insert(std::map<int, std::string>::value_type(313, "role_label_0160"));
	keyDic.insert(std::map<int, std::string>::value_type(314, "role_label_0190"));
	keyDic.insert(std::map<int, std::string>::value_type(556, "role_label_0450"));
	keyDic.insert(std::map<int, std::string>::value_type(601, "role_label_0230"));
	keyDic.insert(std::map<int, std::string>::value_type(602, "role_label_0240"));
	keyDic.insert(std::map<int, std::string>::value_type(603, "role_label_0250"));
	keyDic.insert(std::map<int, std::string>::value_type(604, "role_label_0260"));
	keyDic.insert(std::map<int, std::string>::value_type(605, "role_label_0270"));
	keyDic.insert(std::map<int, std::string>::value_type(1004, "role_label_0280"));
	keyDic.insert(std::map<int, std::string>::value_type(805, "role_label_0290"));
	keyDic.insert(std::map<int, std::string>::value_type(315, "role_label_0580"));
	keyDic.insert(std::map<int, std::string>::value_type(914, "role_label_0570"));
	keyDic.insert(std::map<int, std::string>::value_type(208, "role_label_0208"));
	keyDic.insert(std::map<int, std::string>::value_type(209, "role_label_0209"));
	keyDic.insert(std::map<int, std::string>::value_type(210, "role_label_0210"));
	keyDic.insert(std::map<int, std::string>::value_type(211, "role_label_0211"));
	keyDic.insert(std::map<int, std::string>::value_type(212, "role_label_0212"));
	keyDic.insert(std::map<int, std::string>::value_type(170, "role_label_0170"));
	keyDic.insert(std::map<int, std::string>::value_type(171, "role_label_0171"));
	keyDic.insert(std::map<int, std::string>::value_type(100001, "role_label_0590"));

	std::map<std::string,std::string>* characterDic = InternationManager::getInstance().getAllCharacterText();
	std::map<std::string,std::string>::iterator charItr;
	std::map<int, std::string>::iterator itr = keyDic.begin();
	for (;itr!=keyDic.end();itr++)
	{
		charItr = characterDic->find(itr->second);
		if (charItr!=characterDic->end())
		{
			playerAttrStr.insert(std::map<int, std::string>::value_type(itr->first, charItr->second));
		}
	}
}
std::string DataManager::getPlayerAttrStr(int key)
{
	std::map<int, std::string>::iterator itr = playerAttrStr.find(key);
	if (itr!=playerAttrStr.end())
	{
		return itr->second;
	}
	return "";
}
void DataManager::loadAllUITexture()
{
	// 	CCTextureCache::sharedTextureCache()->addImageAsync(UI_1, this, callfuncOD_selector(TextureManager::loadTextureCallback));
	// 	CCTextureCache::sharedTextureCache()->addImageAsync(UI_2, this, callfuncOD_selector(TextureManager::loadTextureCallback));
	// 	CCTextureCache::sharedTextureCache()->addImageAsync(UI_3, this, callfuncOD_selector(TextureManager::loadTextureCallback));
	// 	CCTextureCache::sharedTextureCache()->addImageAsync(UI_4, this, callfuncOD_selector(TextureManager::loadTextureCallback));
	// 	CCTextureCache::sharedTextureCache()->addImageAsync(UI_5, this, callfuncOD_selector(TextureManager::loadTextureCallback));
}