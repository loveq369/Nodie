////9miao.com 首发
//#pragma once
//
//#include "gamecore.h"
//#include "MessageUtil.h"
//
//
//
/////////////classtype(itemclass)////////////////
//
////物品类型 0消耗品，1武器2副手3头盔4护肩5胸甲6腰带7护手8鞋子9项链10手镯11戒指12披风13勋章14时装15宝石16包裹17任务18仙门加速
//#define ITEM_TYPE_CONSUMABLE 0
////可修理的:1-11 24
//#define ITEM_TYPE_MAINHAND 1     //主手武器
//#define ITEM_TYPE_OFFHAND 2      //副手
//#define ITEM_TYPE_HEAD 3         //头盔
//#define ITEM_TYPE_SHOULDER 4     //护肩
//#define ITEM_TYPE_CHEST 5        //胸甲
//#define ITEM_TYPE_BELT 6         //腰带
//#define ITEM_TYPE_GLOVE 7        //护手
//#define ITEM_TYPE_SHOES 8        //鞋子
//#define ITEM_TYPE_NECK 9         //项链
//#define ITEM_TYPE_ARMBAND 10     //手镯
//#define ITEM_TYPE_FINGER 11      //戒指
//#define ITEM_TYPE_SHIELD 24	     //盾
//#define ITEM_TYPE_MANTEAU 12     //披风
//#define ITEM_TYPE_AMULET 13      //勋章   护身符
//#define ITEM_TYPE_FASHION 14	 //	时装	
//#define ITEM_TYPE_RIDE 39	     //坐骑			
//
//#define ITEM_TYPE_GEMSTONE 15	//宝石
//#define ITEM_TYPE_PACKAGE 16	//包裹
//#define ITEM_TYPE_QUEST 17	//任务
//#define ITEM_TYPE_GUILD_SPEEDUP 18	//仙门加速
//
//
//#define ITEM_TYPE_FLY_SHOES 25						//飞鞋
//#define ITEM_TYPE_PET_RENAME 26						//宠物改名道具
//#define ITEM_TYPE_UP_GROWTH 28						//练骨
//#define ITEM_TYPE_UP_STAMINA 29						//易筋
//#define ITEM_TYPE_UP_GROWTH_PROTECT 31				//练骨保护符
//#define ITEM_TYPE_UP_STAMINA_PROTECT 32				//易筋保护符
//#define ITEM_TYPE_PET_UP_EXP 34						//宠物经验丹
//#define ITEM_TYPE_TREASURE_CHEST 35					//天珠
//#define ITEM_TYPE_TARGET_USE 36						//使用需要目标的道具
//#define ITEM_TYPE_RUBBISH 37							//垃圾
//#define ITEM_TYPE_PET_UP_RIDE 38						//坐骑升星
//
//#define ITEM_TYPE_RESAWN 40							//复活卷
//#define ITEM_TYPE_UPGRADE 42							//装备升阶石
//#define ITEM_TYPE_GIFT_PACKAGE 43						//礼包
//#define ITEM_TYPE_VENATION 44							//经脉道具物品类型
//#define ITEM_TYPE_ITEM_IDENTIFY 48					//可鉴定物品
//#define ITEM_TYPE_SKILL_BOOK 49						//技能书
////50资质上限提升道具
//#define ITEM_TYPE_FEED_PET 51							//宠物饲料
//#define ITEM_TYPE_PET_SKILL_SOLT_LOCK 52				//宠物技能锁
////
////53宠物进化石 54宠物宝石
////
//#define ITEM_TYPE_PET_HEAD 55							//宠物头盔
//#define ITEM_TYPE_PET_NECK 56							//宠物项链
//#define ITEM_TYPE_PET_GIFT 57							//宠物挂件
//#define ITEM_TYPE_PET_BELT 58							//宠物腰带
//#define ITEM_TYPE_PET_SHOES 59						//宠物足链
//
//#define ITEM_TYPE_SPA_SOAP 77							//搓澡肥皂
//#define ITEM_TYPE_TREASURE_TRANSPORT_FRESH 78			//刷镖令
//
//
////
////60天赋符 61洗点水 
////65白资质符 66绿资质符 67蓝资质符 68紫资质符 69金资质符 
////70白资质保护符 71绿资质保护符 72蓝资质保护符 73紫资质保护符 74金资质保护符  75宠物技能锁 79加血药品 80加蓝药品
////
//
//#define ITEM_TYPE_PET_EXPLORE_SPEEDUP 81	//宠物加速探险
//#define ITEM_TYPE_PET_LUCKY_MEDAL 82		//宠物探险 幸运奖章
//
//#define ITEM_TYPE_GUILD_RENAME 86			//仙门改名卡
//#define ITEM_TYPE_ROLE_RENAME 87			//人物改名卡
//
//#define ITEM_TYPE_GUILD_IMPEACH 88		//仙门弹劾道具
//
////节日活动
//#define ITEM_TYPE_CHRISTMAS_BALL 90		//圣诞彩球
//#define ITEM_TYPE_CHRISTMAS_SOCKS 91		//圣诞袜子
//
////
////装备相关
//// //
//// #define ITEM_TYPE_EQUIP_JIEFENG_CHUJI 100				//初级解封材料
//// #define ITEM_TYPE_EQUIP_JIEFENG_ZHONGJI 101				//中级解封材料
//// #define ITEM_TYPE_EQUIP_JIEFENG_GAOJI 102				//高级解封材料
//// #define ITEM_TYPE_EQUIP_JIEFENG_TEJI 103				//特级解封材料
//// #define ITEM_TYPE_EQUIP_SOCK_CHUJI 105				//初级打孔石
//// #define ITEM_TYPE_EQUIP_SOCK_ZHONGJI 106				//中级打孔石
//// #define ITEM_TYPE_EQUIP_SOCK_GAOJI 107				//高级打孔石
//
//#define ITEM_TYPE_EQUIP_SEAL 108						//可解封的装备
//
//
//#define ITEM_TYPE_STAR_STONE	19//升星石
//#define ITEM_TYPE_STAR_AMULET	20//保护石
//#define ITEM_TYPE_PUNCH_PROPS	21//打孔道具
//#define ITEM_TYPE_STONE_CLAY	23
//#define ITEM_TYPE_NEED_TARGET	36
//#define ITEM_TYPE_STONE_YSSP	42//套装升级
//#define ITEM_TYPE_STONE_CJ		45//宝石拆解凿
//#define ITEM_TYPE_STONE_ENHANT	46//附魔
//#define ITEM_TYPE_STONE_RECAST	47//重铸
//#define ITEM_TYPE_JIEFENG_MATERIAL	101//解封材料
//#define ITEM_TYPE_LUCKY_AMULET		102//幸运石
//#define ITEM_TYPE_FENJIE_MATERIAL	107//分解材料
//
//#define ITEM_TYPE_MOUNT_SYNTHESIS_STONE	41//坐骑合成石
//#define ITEM_TYPE_MOUNT_IDENTITY_STONE	38//
//#define ITEM_TYPE_VIP		84//vip
//#define ITEM_TYPE_PUTI		85//菩提
//#define ITEM_TYPE_XUELIAN	89//雪莲
//
//
///************************************************************************/
///* tipsClass                                                                     */
///************************************************************************/
//#define   ITEM_TIPSCLASS_SKILL_BOOK   0  // 技能书   （静态文件里没有）
//#define   ITEM_TIPSCLASS_MEDICINE   1  // 药品    
//#define   ITEM_TIPSCLASS_EQUIP   2  // 装备    
//#define   ITEM_TIPSCLASS_EQUIP_STRENGTHEN   3  // 装备强化
//#define   ITEM_TIPSCLASS_PET  4  // 宠物
//#define   ITEM_TIPSCLASS_PET_STRENGTHEN   5  // 宠物强化 （静态文件里没有）   
//#define   ITEM_TIPSCLASS_VARIA   6  // 杂物	    （静态文件里没有）
//#define   ITEM_TIPSCLASS_CONSUMABLE   7  // 消耗品	
//#define   ITEM_TIPSCLASS_TASKPROP   8  // 任务道具
//#define   ITEM_TIPSCLASS_SPECIALPROP   9  // 特殊道具
//#define   ITEM_TIPSCLASS_RIDE       10  //坐骑	     （静态文件里没有）
//#define   ITEM_TIPSCLASS_RIDE_STRENGTHEN 11  //坐骑强化   （静态文件里没有）
//#define   ITEM_TIPSCLASS_ATTACK_STONE  12  //攻击类宝石
//#define   ITEM_TIPSCLASS_DEFENSE_STONE  13  //防御类宝石
//#define   ITEM_TIPSCLASS_OTHERS  16  //杂物    （静态文件里有，等策划确定为什么？）
///************************************************************************/
///* inventorytype                                                        */
///************************************************************************/
//#define   ITEM_INVENTORY_TYPE_HEND   1  // 头盔	
//#define   ITEM_INVENTORY_TYPE_SHOULDER   2  // 护肩	
//#define   ITEM_INVENTORY_TYPE_GLOVE   3  // 护手	
//#define   ITEM_INVENTORY_TYPE_BELT   4  // 腰带	
//#define   ITEM_INVENTORY_TYPE_SHOES   5  // 鞋子	
//#define   ITEM_INVENTORY_TYPE_CHEST   6  // 胸甲 	
//#define   ITEM_INVENTORY_TYPE_MAINHAND   7  // 主手武器
//#define   ITEM_INVENTORY_TYPE_OFFHAND   8  // 副手武器
//#define   ITEM_INVENTORY_TYPE_LFINGER   9  // 左手戒指	
//#define   ITEM_INVENTORY_TYPE_RFINGER  10  //右手戒指	 （静态文件里没有）
//#define   ITEM_INVENTORY_TYPE_LARMBAND  11  //左手手镯
//#define   ITEM_INVENTORY_TYPE_RARMBAND  12  //右手手镯  （静态文件里没有）
//#define   ITEM_INVENTORY_TYPE_NECK  13  //项链
//#define   ITEM_INVENTORY_TYPE_FASHION  14  //时装
//#define   ITEM_INVENTORY_TYPE_RIDE  15  //坐骑
//#define   ITEM_INVENTORY_TYPE_MANTEAU  16  //披风
//#define   ITEM_INVENTORY_TYPE_17  17  //  ???  
//#define   ITEM_INVENTORY_TYPE_19  19  //  ???
///************************************************************************/
///* inventorytype                                                        */
///************************************************************************/
//#define    ENCHANTMENTS_ITEM_NUM   13    // 升星加成对用的装备数，不包括时装，披风，和坐骑
///************************************************************************/
///* 属性面板上的slot                                                     */
///************************************************************************/
//#define   ROLE_ITEM_SLOT_HEND   1  // 头盔	
//#define   ROLE_ITEM_SLOT_SHOULDER   2  // 护肩	
//#define   ROLE_ITEM_SLOT_GLOVE   3  // 护手	
//#define   ROLE_ITEM_SLOT_BELT   4  // 腰带	
//#define   ROLE_ITEM_SLOT_SHOES   5  // 鞋子	
//#define   ROLE_ITEM_SLOT_CHEST   6  // 胸甲 	
//#define   ROLE_ITEM_SLOT_MAINHAND   7  // 主手武器
//#define   ROLE_ITEM_SLOT_OFFHAND   8  // 副手武器
//#define   ROLE_ITEM_SLOT_LFINGER   9  // 左手戒指	
//#define   ROLE_ITEM_SLOT_RFINGER  10  //右手戒指	 （静态文件里没有）
//#define   ROLE_ITEM_SLOT_LARMBAND  11  //左手手镯
//#define   ROLE_ITEM_SLOT_RARMBAND  12  //右手手镯  （静态文件里没有）
//#define   ROLE_ITEM_SLOT_NECK  13  //项链
//#define   ROLE_ITEM_SLOT_FASHION  14  //时装
//#define   ROLE_ITEM_SLOT_RIDE  15  //坐骑
//#define   ROLE_ITEM_SLOT_MANTEAU  16  //披风
///************************************************************************/
///* subClass                                                                     */
///************************************************************************/
//#define ITEM_SUBCLASS_OTHER		    0//其他
//#define ITEM_SUBCLASS_EQUIP		    1//装备
//#define ITEM_SUBCLASS_MEDICINE		2//药品
//#define ITEM_SUBCLASS_STRENGTHEN	3//强化
//#define ITEM_SUBCLASS_ALL		    4//全部
//
///************************************************************************/
///* qualty                                                                     */
///************************************************************************/
//#define ITEM_LANZHUANG		2//蓝装
//#define ITEM_ZIZHUANG		3//紫装
//#define ITEM_JINZHUANG		4//金装
//
//
///*************************************************************************/
///* achieve
///*************************************************************************/
//#define ACHIEVE_PROTO_STATE_FINISHED 1
//#define ACHIEVE_PROTO_STATE_UNFINISHED 0
//#define ACHIEVE_REWARD_STATE_RECEIVEABLE 1//1:可领取，2：已领取，3：未完成
//#define ACHIEVE_REWARD_STATE_RECEIVED 2
//#define ACHIEVE_REWARD_STATE_UNFINISHED 3
//#define ACHIEVE_FUWEN_STATE_UNFINISHED 0//1:已获得，0：未完成
//#define ACHIEVE_FUWEN_STATE_FINISHED 1
//
//
//static const cocos2d::ccColor3B ITEM_COLOR_1 = {255,255,255};
//static const cocos2d::ccColor3B ITEM_COLOR_2 = {0,255,0};
//static const cocos2d::ccColor3B ITEM_COLOR_3 = {51,153,255};
//static const cocos2d::ccColor3B ITEM_COLOR_4 = {255,0,255};
//static const cocos2d::ccColor3B ITEM_COLOR_5 = {255,255,0};
//static const cocos2d::ccColor3B ITEM_COLOR_6 = {137,137,137};
//
//typedef struct PlayerAttr//玩家属性
//{
//	std::string name;//属性名
//	int value;//属性值
//}tPlayerAttr;
//
//
//class BaseItemData
//{
//public:
//	int level;//等级
//	int slot;
//	int maxDurability;
//	int count;//item数量
//	int qualty;//品质
//	int allowableClass;
//	int inventorytype;
//	int sellPrice;
//	int enchantments;//升星数
//	int spellcooldown;
//	int duration;
//	int spellcategory;
//	int tipsClass;//tips分类
//	int canuse;
//	int subclass;
//	int fighting_force;
//	int bonding;
//	int petStudyLevel;
//	int spellid;
//	int itemclass;//道具类型  classtype
//	int lefttime_s;
//	int receiveTime;
//	int socketType;
//	int high_id;
//	int isbonded;
//	int displayid;
//	int useable;
//	int stackable;
//	int low_id;
//	int ownerFaction;
//	int entry;//道具typeId
//	int maxSocket;//最大孔数
//	int overdue_type;
//	int questid;
//	std::vector<int> sockets;//打孔
//	int caizhuangid;
//	int baserepaired;
//	std::string name;
//	std::string buffDesc;
//	std::string item_from_where;
//	std::string description;
//	tPoint requiredLevel;
//	std::vector<tKV> enchant;//附魔
//	std::vector<tKV> add_states;
//	std::vector<std::vector<std::string> > states;
//	std::vector<float> damage;
//	std::vector<float> defense;
//	std::vector<std::string> popupWnd;
//	bool isActive;   //对应grid里的 isActive
//	BaseItemData()
//	{
//		level = 0;
//		slot = 0;
//		maxDurability = 0;
//		count = 0;
//		qualty = 0;
//		allowableClass = 0;
//		inventorytype = 0;
//		sellPrice = 0;
//		enchantments = 0;
//		spellcooldown = 0;
//		duration = 0;
//		spellcategory = 0;
//		tipsClass = 0;
//		canuse = 0;
//		subclass = 0;
//		fighting_force = 0;
//		bonding = 0;
//		petStudyLevel = 0;
//		spellid = 0;
//		itemclass = 0;
//		lefttime_s = 0;
//		receiveTime = 0;
//		socketType = 0;
//		high_id = 0;
//		isbonded = 0;
//		displayid = 0;
//		useable = 0;
//		stackable = 0;
//		low_id = 0;
//		ownerFaction = 0;
//		entry = 0;
//		maxSocket = 0;
//		overdue_type = 0;
//		questid = 0;
//		//sockets = 0;
//		baserepaired = 0.0f;
//		name = "";
//		buffDesc = "";
//		item_from_where = "";
//		description = "";
//		isActive =true;
//	}
//};
//class ItemConfigData: public BaseItemData//配置表道具数据
//{
//public:
//	int equipmentset;
//public:
//	ItemConfigData()
//	{
//		equipmentset = 0;
//	}
//};
//class ItemData: public BaseItemData//道具数据
//{
//public:
//
//public:
//	ItemData()
//	{
//
//	}
//};
//
//class GuildStorageData: public ItemData //仙门仓库数据
//{
//public:
//	int32 idle_state;
//	int32 idle;
//
//public:
//	GuildStorageData()
//	{
//		idle_state=0;
//		idle=0;  
//	}
//};
//
//
//
//class EnchantmentConfigData//升星相关数据
//{
//public:
//	int id;//星级
//	int bonuses;
//	int consum;//消耗钱币
//	int failure;//失败降到星级
//	tPoint successrate;//基础成功率
//	std::vector<int> riseup;//可用升星宝石
//	std::vector<int> protect;//可用保护宝石
//	std::vector<int> lucky;//可用幸运宝石
//	std::vector<tPlayerAttr> setAttrList;//
//	std::map<int, std::vector<tPlayerAttr> > addAttrDic;//
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, bonuses);
//		pos += readInt(data, consum);
//		pos += readInt(data, failure);
//		pos += readInt(data, successrate.x);
//		pos += readInt(data, successrate.y);
//		int16 len = 0;
//		int16 i = 0;
//		pos += readShort(data, len);
//		for (i=0;i<len;i++)
//		{
//			int temp;
//			pos += readInt(data, temp);
//			riseup.push_back(temp);
//		}
//		len = 0;
//		pos += readShort(data, len);
//		for (i=0;i<len;i++)
//		{
//			int temp;
//			pos += readInt(data, temp);
//			protect.push_back(temp);
//		}
//		len = 0;
//		pos += readShort(data, len);
//		for (i=0;i<len;i++)
//		{
//			int temp;
//			pos += readInt(data, temp);
//			lucky.push_back(temp);
//		}
//		len = 0;
//		pos += readShort(data, len);
//		for (i=0;i<len;i++)
//		{
//			tPlayerAttr temp;
//			pos += readString(data, temp.name);
//			pos += readInt(data, temp.value);
//			setAttrList.push_back(temp);
//		}
//		int16 len2 = 0;
//		int16 j = 0;
//		len = 0;
//		pos += readShort(data, len);
//		for (i=0;i<len;i++)
//		{
//			int itemClass = 0;
//			pos += readInt(data, itemClass);
//			len2 = 0;
//			pos += readShort(data, len2);
//			std::vector<tPlayerAttr> tempList;
//			for (j=0;j<len2;j++)
//			{
//				tPlayerAttr temp;
//				pos += readString(data, temp.name);
//				pos += readInt(data, temp.value);
//				tempList.push_back(temp);
//			}
//			addAttrDic.insert(std::map<int, std::vector<tPlayerAttr> >::value_type(itemClass, tempList));
//		}
//	}
//};
//
//class EnchantFenjieConfigData//分解配置数据
//{
//public:
//	int id;//品质
//	int money;//消耗金钱
//	int productsNum;//分解出数目
//	std::vector<int> products;//可分解出的道具id
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, money);
//		pos += readInt(data, productsNum);
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			int productId = 0;
//			pos += readInt(data, productId);
//			products.push_back(productId);
//		}
//	}
//};
//
//class EnchantDakongConfigData//打孔配置数据
//{
//public:
//	int id;//孔洞
//	int money;//消耗金钱
//	tPoint rate;//成功率
//	std::vector<int> stoneList;//需要的打孔石id
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, money);
//		pos += readInt(data, rate.x);
//		pos += readInt(data, rate.y);
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			int stoneId = 0;
//			pos += readInt(data, stoneId);
//			stoneList.push_back(stoneId);
//		}
//	}
//};
//
//
//class EnchantFumoColorConfigData//附魔颜色配置数据
//{
//public:
//	int id;//附魔属性id
//	std::vector<tPoint> colorList;//所有可能的颜色
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			tPoint tp;
//			pos += readInt(data, tp.x);
//			pos += readInt(data, tp.y);
//			colorList.push_back(tp);
//		}
//	}
//};
//
//typedef struct Vector3
//{
//	int x;
//	int y;
//	int z;
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, x);
//		pos += readInt(data, y);
//		pos += readInt(data, z);
//	}
//}tVector3;
//
//class EnchantZhuanyiConfigData
//{
//public:
//	int id;
//	tPoint giveoutLv;//副装备的等级限制
//	tPoint getLv;//主装备的等级限制
//	int needmoney;//需要金钱
//	std::vector<tVector3> needitem;//需要道具
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, giveoutLv.x);
//		pos += readInt(data, giveoutLv.y);
//		pos += readInt(data, getLv.x);
//		pos += readInt(data, getLv.y);
//		pos += readInt(data, needmoney);
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			tVector3 tv;
//			pos += readInt(data, tv.x);
//			pos += readInt(data, tv.y);
//			pos += readInt(data, tv.z);
//			needitem.push_back(tv);
//		}
//	}
//};
//
//class EnchantJiefengConfigData//装备解封信息
//{
//public:
//	int id;
//	int newItem;//新道具
//	int needmoney;//需要金钱
//	tVector3 needitem;//需要道具
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, newItem);
//		pos += readInt(data, needmoney);
//		pos += readInt(data, needitem.x);
//		pos += readInt(data, needitem.y);
//		pos += readInt(data, needitem.z);
//	}
//};
//
//class EnchantShengjiConfigData//装备升级信息
//{
//public:
//	int id;
//	int newItem;//新道具
//	int needmoney;//需要金钱
//	tVector3 needitem;//需要道具
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, newItem);
//		pos += readInt(data, needmoney);
//		pos += readInt(data, needitem.x);
//		pos += readInt(data, needitem.y);
//		pos += readInt(data, needitem.z);
//	}
//};
//
//class RefineItemConfigData//炼制的一个道具
//{
//public:
//	int id;
//	int itemId;//炼制道具id
//	int money;//消耗钱币
//	int bindingType;//钱币类型
//	int serialNumber;
//	std::string successRatio;//成功率
//	std::string des;//描述
//	std::vector<tVector3> needItemList;//需要道具（tVector3.x:道具id, tVector3.y:绑定道具id，tVector3.z:需要数目）
//	std::vector<int> showItemList;//要显示的道具id
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, itemId);
//		pos += readInt(data, money);
//		pos += readInt(data, bindingType);
//		pos += readInt(data, serialNumber);
//		pos += readString(data, successRatio);
//		pos += readString(data, des);
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			tVector3 needitem;
//			pos += readInt(data, needitem.x);
//			pos += readInt(data, needitem.y);
//			pos += readInt(data, needitem.z);//数量
//			needItemList.push_back(needitem);
//		}
//		pos += readShort(data, len);
//		int id;
//		for (int16 i=0;i<len;i++)
//		{
//			pos += readInt(data, id);
//			showItemList.push_back(id);
//		}
//	}
//};
////炼制list的信息
//class RefineListConfigData
//{
//public:
//	std::string listName;
//	std::vector<RefineItemConfigData*> refineItemList;
//public:
//	~RefineListConfigData()
//	{
//		std::vector<RefineItemConfigData*>::iterator itr = refineItemList.begin();
//		for (;itr!=refineItemList.end();itr++)
//		{
//			if (*itr)
//			{
//				delete *itr;
//			}
//		}
//		std::vector<RefineItemConfigData*> blank;
//		refineItemList.swap(blank);
//	}
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readString(data, listName);		
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			RefineItemConfigData* ricd = new RefineItemConfigData();
//			ricd->encode(data, pos);
//			refineItemList.push_back(ricd);
//		}
//	}
//};
////炼制配置信息（tab）
//class RefineConfigData
//{
//public:
//	int id;//tab页id
//	std::string tabName;//tab页名字
//	std::vector<RefineListConfigData*> refineListList;
//public:
//	~RefineConfigData()
//	{
//		std::vector<RefineListConfigData*>::iterator itr = refineListList.begin();
//		for (;itr!=refineListList.end();itr++)
//		{
//			if (*itr)
//			{
//				delete *itr;
//			}
//		}
//		std::vector<RefineListConfigData*> blank;
//		refineListList.swap(blank);
//	}
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readString(data, tabName);
//		int16 len = 0;
//		pos += readShort(data, len);
//		for (int16 i=0;i<len;i++)
//		{
//			RefineListConfigData* rlcd = new RefineListConfigData();
//			rlcd->encode(data, pos);
//			refineListList.push_back(rlcd);
//		}
//	}
//};
////炼丹炉配置数据
//class DanLuConfigData
//{
//public:
//	int id;
//	std::string name;
//	std::string smallIcon;
//	std::string largeIcon;
//	std::string des;
//	int propNum;
//	float lianTime;
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, propNum);
//		pos += readString(data, largeIcon);
//		pos += readFloat(data, lianTime);
//		pos += readString(data, des);
//		pos += readString(data, name);
//		pos += readString(data, smallIcon);		
//	}
//
//};
////丹药配置数据
//class DanMedicineConfigData
//{
//public:
//	int id;
//	int propID;
//	std::string attributeDes;
//	int attribute;
//	int topLimit;
//	int levelLimit;
//	std::map<int,int>* needPropList;
//	int needTime;
//	int needMoney;
//public:
//	DanMedicineConfigData()
//	{
//		needPropList = new std::map<int,int>();
//		id = 0;
//		propID = 0;
//		attributeDes = "";
//		attribute = 0;
//		topLimit = 0;
//		levelLimit = 0;
//		needTime = 0;
//		needMoney = 0;
//	}
//	~DanMedicineConfigData()
//	{
//		CC_SAFE_DELETE(needPropList);	
//	}
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//		pos += readInt(data, propID);
//		int arraySize = 0;
//		pos += readInt(data,arraySize);
//		for(int i = 0; i < arraySize; i++)
//		{
//			tPoint item;
//			pos += readInt(data,item.x);
//			pos += readInt(data,item.y);
//			needPropList->insert(std::map<int, int>::value_type(item.x, item.y));
//		}
//		pos += readInt(data, needTime);
//		pos += readInt(data, needMoney);
//		pos += readInt(data, topLimit);
//		pos += readInt(data, levelLimit);
//		pos += readString(data, attributeDes);
//		pos += readInt(data, attribute);	
//
//	}
//	void split(std::string src, const char* token, std::vector<std::string>& vect)
//	{
//
//		int nend=0;
//		int nbegin=0;
//		while(nend != -1)
//		{
//			nend = src.find(token, nbegin);
//			if(nend == -1)
//				vect.push_back(src.substr(nbegin, src.length()-nbegin));
//			else
//				vect.push_back(src.substr(nbegin, nend-nbegin));
//			nbegin = nend + strlen(token);
//		}
//	}
//};
//
////星象中同一星座的某品质的某级别的星座的配置数据
//class AstrologyTypeLevelConfigData
//{
//public:
//	int id;
//	std::string describe;	
//	int key;
//	int level;
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);
//
//		//int arraySize = 0;
//		std::string itemType = "";
//		int itemValue = 0;
//		//pos += readInt(data,arraySize);
//		pos += readString(data,itemType);
//		pos += readInt(data,itemValue);
//
//		pos += readString(data, describe);
//		key=id/10;
//		level=id%10;
//	}
//};
////星象中同一星座的某品质的星座的配置数据
//class AstrologyTypeConfigData
//{
//public:
//	int id;
//	std::string desc;
//	int displayid;
//	int isshow;
//	std::string name;	
//	int price;
//	int quality;
//	int type;
//	std::vector<AstrologyTypeLevelConfigData*> astrologyTypeLevelConfigDataList;
//public:
//	~AstrologyTypeConfigData()
//	{
//		std::vector<AstrologyTypeLevelConfigData*>::iterator itr = astrologyTypeLevelConfigDataList.begin();
//		for (;itr!=astrologyTypeLevelConfigDataList.end();itr++)
//		{
//			if (*itr)
//			{
//				delete *itr;
//			}
//		}
//		std::vector<AstrologyTypeLevelConfigData*> blank;
//		astrologyTypeLevelConfigDataList.swap(blank);
//	}
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, id);	
//		pos += readString(data, desc);	
//		pos += readInt(data, displayid);
//		pos += readInt(data, isshow);
//		pos += readString(data, name);		
//		pos += readInt(data, price);
//		pos += readInt(data, quality);
//		pos += readInt(data, type);	
//	}
//};
///************************************************************************/
///* function                                                                     */
///************************************************************************/
//cocos2d::ccColor3B getColorByQuality(int quality);//根据道具品质获取字串颜色
//cocos2d::ccColor3B getFumoColorByKV(tKV kv);//根据道具附魔属性获取附魔字串颜色
//int getFumoQualityByKV(tKV kv);//根据附魔属性获取属性品质
//EnchantZhuanyiConfigData* getZhuanyiDataByLv(int sencondaryLv, int mainLv);//根据副装备和主装备等级获取配置数据
//
////baseItemData 为null 时，grid 为空，status = GRID_FREE
//void updateGridItemByBaseItemData(GridItem * gridItem,BaseItemData * baseItemData=NULL); 
////status = GRID_USED、GRID_FREE、GRID_LOCKED,一定得设置；pos为grid在gridpanel中的位置（第几个。从0开始），不属于gridpanel时pos=0；slot 一般为BaseItemData中的slot,不用时默认0；src为grid的来源，有拖动时才使用。
//void updateGridItemByBaseItemData(GridItem * gridItem,BaseItemData * baseItemData,int status,int pos=0,int slot=0,int src=0);
//
//void updateWXGridByBaseItemData(WXGrid * grid,BaseItemData * baseItemData=NULL); 
//void updateWXGridByBaseItemData(WXGrid * grid,BaseItemData * baseItemData,int status,int pos=0,int slot=0,int src=0);
//
//
///**********************************************************************/
///*  祈福部分
///************************************************************************/
//
//class BeadsPrayConfigData{
//public:
//	int8 key;
//	std::vector<tKV> items;//祈福商品
//public:
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		int8 itemSize=0;
//		tKV kv;
//		pos += readInt8(data, key);
//		pos += readInt8(data,itemSize);
//		for(int8 i=0; i<itemSize; i++)
//		{
//			pos += readInt(data, kv.key);
//			pos += readInt(data, kv.intValue);
//			items.push_back(kv);
//		}
//	}
//};
//
//typedef struct LogRewardConfigData
//{
//public:
//	int32 goods1Id;
//	int32 goods1Num;
//	int32 goods2Id;
//	int32 goods2Num;
//}tLogRewardConfigData;
//
//typedef struct AchieveProtoConfigData
//{
//public:
//	int32 key;
//	int32 achieveHp;
//	int32 achieveNum;
//	int32 achieveValue;
//	std::string des;
//	std::string name;
//	std::vector<AchieveProtoConfigData*>* childs;
//	int32 state;//1（已完成）非1未完成
//	int32 finished;//任务完成进度
//public:
//	AchieveProtoConfigData()
//	{
//		childs = NULL;
//		state = ACHIEVE_PROTO_STATE_UNFINISHED;
//		finished = 0;
//	}
//
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt(data, key);
//		pos += readInt(data, achieveHp);
//		pos += readInt(data, achieveNum);
//		pos += readInt(data,achieveValue);
//		pos += readString(data,des);
//		pos += readString(data,name);
//	}
//	void addChild(AchieveProtoConfigData* child)
//	{
//		if (!childs)
//		{
//			childs = new std::vector<AchieveProtoConfigData*>();
//		}
//		childs->push_back(child);
//	}
//
//	bool operator <   (const AchieveProtoConfigData& acd )   const
//	{
//		return key < acd.key;
//	}
//	bool operator >   (const AchieveProtoConfigData& acd )   const
//	{
//		return key > acd.key;
//	}
//
//}tAchieveProtoConfigData;
//
//typedef struct AchieveAwardConfigData
//{
//public:
//	int8 key;
//	int32 awardId;
//	int32 awardNum;
//	std::string des;
//	std::string name;
//	int32 state;//1:可领取，2：已领取，3：未完成
//public:
//	AchieveAwardConfigData()
//	{
//		state = ACHIEVE_REWARD_STATE_UNFINISHED;
//	}
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt8(data, key);
//		pos += readInt(data, awardId);
//		pos += readInt(data, awardNum);
//		pos += readString(data,des);
//		pos += readString(data,name);
//	}
//}tAchieveAwardConfigData;
//
//typedef struct AchieveFuwenConfigData
//{
//public:
//	int8 key;
//	std::string eff;
//	int32 level;
//	std::string name;
//	std::string needAchieve;
//	int32 type;
//	int32 state;//1:已获得，0：未完成
//public:
//	AchieveFuwenConfigData()
//	{
//		state = ACHIEVE_FUWEN_STATE_UNFINISHED;
//	}
//	void encode(unsigned char*& data, unsigned long& pos)
//	{
//		pos += readInt8(data, key);
//		pos += readString(data, eff);
//		pos += readInt(data, level);
//		pos += readString(data,name);
//		pos += readString(data,needAchieve);
//		pos += readInt(data,type);
//	}
//}tAchieveFuwenConfigData;
//
//typedef struct  AchieveId
//{
//public:
//	int32 type;
//	int32 part;
//}tAchieveId;
//
//typedef struct VenationPointProto
//{
//public:
//	//int32 key;
//	std::string attr;
//	int32 limitLevel;
//	int32 money;
//	std::string name;
//	int32 rate;
//	int32 soulpower;
//}tVenationPointProto;//修为静态配置信息
//
//
//typedef struct VenationInfo
//{
//public:
//	std::vector<int>* venation;//修为8种的已修层数
//	std::vector<int>* venationBone;//顿悟8种的已修层数
//	std::vector<tKV>* attr;//增加的属性 
//	int32 remainTime;//分享剩余次数
//	int64 totalexp;//提升获得经验总数
//
//public:
//	VenationInfo()
//	{
//		venation = new std::vector<int>(8,0);
//		venationBone = new std::vector<int>(8,0);
//		attr = new std::vector<tKV>();
//		remainTime = 0;
//		totalexp = 0;
//	}
//
//	~VenationInfo()
//	{
//		CC_SAFE_DELETE(venation);
//		CC_SAFE_DELETE(venationBone);
//		CC_SAFE_DELETE(attr);
//	}
//}tVenationInfo;//修为、顿悟消息结构:已修炼完成的修为、顿悟数据
//
//
//typedef struct VenationProficient
//{
//public:
//	int32 addAttrNum;//addattrNum
//	std::string addAttrStr;//addAttrStr+addattrNum
//	int32 costMoney;
//	int32 needItemId1;
//	int32 needItemId2;
//	int32 protectItem1;
//	int32 protectItem2;
//	int32 succRate;
//}tVenationProficient;//顿悟静态配置信息
//
//typedef struct VipLevelConfigData
//{
//public:
//	VipLevelConfigData()
//	{
//		desc = new std::vector<std::string>();
//		reward = new std::vector<tKV>();
//		trainingExpAdd = 0;
//		vipenchantments = 0;
//	}
//	~VipLevelConfigData()
//	{
//		CC_SAFE_DELETE(desc);
//		CC_SAFE_DELETE(reward);
//	}
//public:
//	int32 key;
//	std::vector<std::string>* desc;
//	int32 gold;
//	std::vector<tKV>* reward;
//	int32 trainingExpAdd;
//	int32 vipenchantments;
//}tVipLevelConfigData;//VIP静态配置信息
//
//
//typedef struct VipInfo
//{
//public:
//	int32 curVipLevel;//当前VIP等级：对应vip_level.txt中的key
//	int32 type;//今天奖励是否领取，0未领取，1已领取
//	int32 type2;//是否到期，0未到期，1到期
//	int32 gold;//暂未知（服务器都发0）
//	int32 endTime;//vip截止日期(秒)
//	int32 leftNum;//小飞鞋剩余次数
//	int32 totalNum;//小飞鞋总数次数
//public:
//	VipInfo()
//	{
//		curVipLevel = 0;
//		type = 1;
//		type2 = 1;
//		gold = 0;
//		endTime = 0;
//		leftNum = 0;
//		totalNum = 0;
//	}
//
//}tVipInfo;//VIP信息
//
//typedef struct HotbarItem
//{
//public:
//	HotbarItem()
//	{
//		clsId = 0;
//		entryId = 0;
//		pos = 0;
//	}
//	int32 clsId;
//	int64 entryId;
//	int32 pos;
//}tHotBarItem;//快捷栏信息
//
//typedef struct AnswerQuestionData
//{
//public:
//	int32 id;
//	std::string questionContent;//题目内容
//	std::map<int32,std::string> questionOptions;//选项
//	int32 rightAnswer;//正确答案
//	std::vector<int32> awardScore;//答题正确得分列表(未用)
//	int32 readingTime;//做题时间
//public:
//	AnswerQuestionData()
//	{
//
//	}
//}tAnswerQuestionData;//答题题目数据
//
//typedef struct AnswerQuestionOption
//{
//public:
//	int key;
//	std::map<int,std::string> startTime;//key==1报名开始时间，key==2答题开始时间
//	int32 earlySignupTime;
//	int32 questionNum;
//	int32 gapTime;
//	std::map<int,int> vipAddition;
//	int32 allRightAddition;
//	std::map<int,int> rankAward;
//	std::map<int,int> doubleTimes;//双倍积分次数数据，根据当前VIP类型获取
//	std::map<int,int> autoTimes;//自动答题次数数据，根据当前VIP类型获取
//	std::map<int,int> basicExp; //答题每一分获得经验数，根据当前用户等级获取
//}tAnswerQuestionOption;//question_option.txt答题选项数据
//
//
//
