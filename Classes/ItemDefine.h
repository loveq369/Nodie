////9miao.com �׷�
//#pragma once
//
//#include "gamecore.h"
//#include "MessageUtil.h"
//
//
//
/////////////classtype(itemclass)////////////////
//
////��Ʒ���� 0����Ʒ��1����2����3ͷ��4����5�ؼ�6����7����8Ь��9����10����11��ָ12����13ѫ��14ʱװ15��ʯ16����17����18���ż���
//#define ITEM_TYPE_CONSUMABLE 0
////�������:1-11 24
//#define ITEM_TYPE_MAINHAND 1     //��������
//#define ITEM_TYPE_OFFHAND 2      //����
//#define ITEM_TYPE_HEAD 3         //ͷ��
//#define ITEM_TYPE_SHOULDER 4     //����
//#define ITEM_TYPE_CHEST 5        //�ؼ�
//#define ITEM_TYPE_BELT 6         //����
//#define ITEM_TYPE_GLOVE 7        //����
//#define ITEM_TYPE_SHOES 8        //Ь��
//#define ITEM_TYPE_NECK 9         //����
//#define ITEM_TYPE_ARMBAND 10     //����
//#define ITEM_TYPE_FINGER 11      //��ָ
//#define ITEM_TYPE_SHIELD 24	     //��
//#define ITEM_TYPE_MANTEAU 12     //����
//#define ITEM_TYPE_AMULET 13      //ѫ��   �����
//#define ITEM_TYPE_FASHION 14	 //	ʱװ	
//#define ITEM_TYPE_RIDE 39	     //����			
//
//#define ITEM_TYPE_GEMSTONE 15	//��ʯ
//#define ITEM_TYPE_PACKAGE 16	//����
//#define ITEM_TYPE_QUEST 17	//����
//#define ITEM_TYPE_GUILD_SPEEDUP 18	//���ż���
//
//
//#define ITEM_TYPE_FLY_SHOES 25						//��Ь
//#define ITEM_TYPE_PET_RENAME 26						//�����������
//#define ITEM_TYPE_UP_GROWTH 28						//����
//#define ITEM_TYPE_UP_STAMINA 29						//�׽�
//#define ITEM_TYPE_UP_GROWTH_PROTECT 31				//���Ǳ�����
//#define ITEM_TYPE_UP_STAMINA_PROTECT 32				//�׽����
//#define ITEM_TYPE_PET_UP_EXP 34						//���ﾭ�鵤
//#define ITEM_TYPE_TREASURE_CHEST 35					//����
//#define ITEM_TYPE_TARGET_USE 36						//ʹ����ҪĿ��ĵ���
//#define ITEM_TYPE_RUBBISH 37							//����
//#define ITEM_TYPE_PET_UP_RIDE 38						//��������
//
//#define ITEM_TYPE_RESAWN 40							//�����
//#define ITEM_TYPE_UPGRADE 42							//װ������ʯ
//#define ITEM_TYPE_GIFT_PACKAGE 43						//���
//#define ITEM_TYPE_VENATION 44							//����������Ʒ����
//#define ITEM_TYPE_ITEM_IDENTIFY 48					//�ɼ�����Ʒ
//#define ITEM_TYPE_SKILL_BOOK 49						//������
////50����������������
//#define ITEM_TYPE_FEED_PET 51							//��������
//#define ITEM_TYPE_PET_SKILL_SOLT_LOCK 52				//���＼����
////
////53�������ʯ 54���ﱦʯ
////
//#define ITEM_TYPE_PET_HEAD 55							//����ͷ��
//#define ITEM_TYPE_PET_NECK 56							//��������
//#define ITEM_TYPE_PET_GIFT 57							//����Ҽ�
//#define ITEM_TYPE_PET_BELT 58							//��������
//#define ITEM_TYPE_PET_SHOES 59						//��������
//
//#define ITEM_TYPE_SPA_SOAP 77							//�������
//#define ITEM_TYPE_TREASURE_TRANSPORT_FRESH 78			//ˢ����
//
//
////
////60�츳�� 61ϴ��ˮ 
////65�����ʷ� 66�����ʷ� 67�����ʷ� 68�����ʷ� 69�����ʷ� 
////70�����ʱ����� 71�����ʱ����� 72�����ʱ����� 73�����ʱ����� 74�����ʱ�����  75���＼���� 79��ѪҩƷ 80����ҩƷ
////
//
//#define ITEM_TYPE_PET_EXPLORE_SPEEDUP 81	//�������̽��
//#define ITEM_TYPE_PET_LUCKY_MEDAL 82		//����̽�� ���˽���
//
//#define ITEM_TYPE_GUILD_RENAME 86			//���Ÿ�����
//#define ITEM_TYPE_ROLE_RENAME 87			//���������
//
//#define ITEM_TYPE_GUILD_IMPEACH 88		//���ŵ�������
//
////���ջ
//#define ITEM_TYPE_CHRISTMAS_BALL 90		//ʥ������
//#define ITEM_TYPE_CHRISTMAS_SOCKS 91		//ʥ������
//
////
////װ�����
//// //
//// #define ITEM_TYPE_EQUIP_JIEFENG_CHUJI 100				//����������
//// #define ITEM_TYPE_EQUIP_JIEFENG_ZHONGJI 101				//�м�������
//// #define ITEM_TYPE_EQUIP_JIEFENG_GAOJI 102				//�߼�������
//// #define ITEM_TYPE_EQUIP_JIEFENG_TEJI 103				//�ؼ�������
//// #define ITEM_TYPE_EQUIP_SOCK_CHUJI 105				//�������ʯ
//// #define ITEM_TYPE_EQUIP_SOCK_ZHONGJI 106				//�м����ʯ
//// #define ITEM_TYPE_EQUIP_SOCK_GAOJI 107				//�߼����ʯ
//
//#define ITEM_TYPE_EQUIP_SEAL 108						//�ɽ���װ��
//
//
//#define ITEM_TYPE_STAR_STONE	19//����ʯ
//#define ITEM_TYPE_STAR_AMULET	20//����ʯ
//#define ITEM_TYPE_PUNCH_PROPS	21//��׵���
//#define ITEM_TYPE_STONE_CLAY	23
//#define ITEM_TYPE_NEED_TARGET	36
//#define ITEM_TYPE_STONE_YSSP	42//��װ����
//#define ITEM_TYPE_STONE_CJ		45//��ʯ�����
//#define ITEM_TYPE_STONE_ENHANT	46//��ħ
//#define ITEM_TYPE_STONE_RECAST	47//����
//#define ITEM_TYPE_JIEFENG_MATERIAL	101//������
//#define ITEM_TYPE_LUCKY_AMULET		102//����ʯ
//#define ITEM_TYPE_FENJIE_MATERIAL	107//�ֽ����
//
//#define ITEM_TYPE_MOUNT_SYNTHESIS_STONE	41//����ϳ�ʯ
//#define ITEM_TYPE_MOUNT_IDENTITY_STONE	38//
//#define ITEM_TYPE_VIP		84//vip
//#define ITEM_TYPE_PUTI		85//����
//#define ITEM_TYPE_XUELIAN	89//ѩ��
//
//
///************************************************************************/
///* tipsClass                                                                     */
///************************************************************************/
//#define   ITEM_TIPSCLASS_SKILL_BOOK   0  // ������   ����̬�ļ���û�У�
//#define   ITEM_TIPSCLASS_MEDICINE   1  // ҩƷ    
//#define   ITEM_TIPSCLASS_EQUIP   2  // װ��    
//#define   ITEM_TIPSCLASS_EQUIP_STRENGTHEN   3  // װ��ǿ��
//#define   ITEM_TIPSCLASS_PET  4  // ����
//#define   ITEM_TIPSCLASS_PET_STRENGTHEN   5  // ����ǿ�� ����̬�ļ���û�У�   
//#define   ITEM_TIPSCLASS_VARIA   6  // ����	    ����̬�ļ���û�У�
//#define   ITEM_TIPSCLASS_CONSUMABLE   7  // ����Ʒ	
//#define   ITEM_TIPSCLASS_TASKPROP   8  // �������
//#define   ITEM_TIPSCLASS_SPECIALPROP   9  // �������
//#define   ITEM_TIPSCLASS_RIDE       10  //����	     ����̬�ļ���û�У�
//#define   ITEM_TIPSCLASS_RIDE_STRENGTHEN 11  //����ǿ��   ����̬�ļ���û�У�
//#define   ITEM_TIPSCLASS_ATTACK_STONE  12  //�����౦ʯ
//#define   ITEM_TIPSCLASS_DEFENSE_STONE  13  //�����౦ʯ
//#define   ITEM_TIPSCLASS_OTHERS  16  //����    ����̬�ļ����У��Ȳ߻�ȷ��Ϊʲô����
///************************************************************************/
///* inventorytype                                                        */
///************************************************************************/
//#define   ITEM_INVENTORY_TYPE_HEND   1  // ͷ��	
//#define   ITEM_INVENTORY_TYPE_SHOULDER   2  // ����	
//#define   ITEM_INVENTORY_TYPE_GLOVE   3  // ����	
//#define   ITEM_INVENTORY_TYPE_BELT   4  // ����	
//#define   ITEM_INVENTORY_TYPE_SHOES   5  // Ь��	
//#define   ITEM_INVENTORY_TYPE_CHEST   6  // �ؼ� 	
//#define   ITEM_INVENTORY_TYPE_MAINHAND   7  // ��������
//#define   ITEM_INVENTORY_TYPE_OFFHAND   8  // ��������
//#define   ITEM_INVENTORY_TYPE_LFINGER   9  // ���ֽ�ָ	
//#define   ITEM_INVENTORY_TYPE_RFINGER  10  //���ֽ�ָ	 ����̬�ļ���û�У�
//#define   ITEM_INVENTORY_TYPE_LARMBAND  11  //��������
//#define   ITEM_INVENTORY_TYPE_RARMBAND  12  //��������  ����̬�ļ���û�У�
//#define   ITEM_INVENTORY_TYPE_NECK  13  //����
//#define   ITEM_INVENTORY_TYPE_FASHION  14  //ʱװ
//#define   ITEM_INVENTORY_TYPE_RIDE  15  //����
//#define   ITEM_INVENTORY_TYPE_MANTEAU  16  //����
//#define   ITEM_INVENTORY_TYPE_17  17  //  ???  
//#define   ITEM_INVENTORY_TYPE_19  19  //  ???
///************************************************************************/
///* inventorytype                                                        */
///************************************************************************/
//#define    ENCHANTMENTS_ITEM_NUM   13    // ���Ǽӳɶ��õ�װ������������ʱװ�����磬������
///************************************************************************/
///* ��������ϵ�slot                                                     */
///************************************************************************/
//#define   ROLE_ITEM_SLOT_HEND   1  // ͷ��	
//#define   ROLE_ITEM_SLOT_SHOULDER   2  // ����	
//#define   ROLE_ITEM_SLOT_GLOVE   3  // ����	
//#define   ROLE_ITEM_SLOT_BELT   4  // ����	
//#define   ROLE_ITEM_SLOT_SHOES   5  // Ь��	
//#define   ROLE_ITEM_SLOT_CHEST   6  // �ؼ� 	
//#define   ROLE_ITEM_SLOT_MAINHAND   7  // ��������
//#define   ROLE_ITEM_SLOT_OFFHAND   8  // ��������
//#define   ROLE_ITEM_SLOT_LFINGER   9  // ���ֽ�ָ	
//#define   ROLE_ITEM_SLOT_RFINGER  10  //���ֽ�ָ	 ����̬�ļ���û�У�
//#define   ROLE_ITEM_SLOT_LARMBAND  11  //��������
//#define   ROLE_ITEM_SLOT_RARMBAND  12  //��������  ����̬�ļ���û�У�
//#define   ROLE_ITEM_SLOT_NECK  13  //����
//#define   ROLE_ITEM_SLOT_FASHION  14  //ʱװ
//#define   ROLE_ITEM_SLOT_RIDE  15  //����
//#define   ROLE_ITEM_SLOT_MANTEAU  16  //����
///************************************************************************/
///* subClass                                                                     */
///************************************************************************/
//#define ITEM_SUBCLASS_OTHER		    0//����
//#define ITEM_SUBCLASS_EQUIP		    1//װ��
//#define ITEM_SUBCLASS_MEDICINE		2//ҩƷ
//#define ITEM_SUBCLASS_STRENGTHEN	3//ǿ��
//#define ITEM_SUBCLASS_ALL		    4//ȫ��
//
///************************************************************************/
///* qualty                                                                     */
///************************************************************************/
//#define ITEM_LANZHUANG		2//��װ
//#define ITEM_ZIZHUANG		3//��װ
//#define ITEM_JINZHUANG		4//��װ
//
//
///*************************************************************************/
///* achieve
///*************************************************************************/
//#define ACHIEVE_PROTO_STATE_FINISHED 1
//#define ACHIEVE_PROTO_STATE_UNFINISHED 0
//#define ACHIEVE_REWARD_STATE_RECEIVEABLE 1//1:����ȡ��2������ȡ��3��δ���
//#define ACHIEVE_REWARD_STATE_RECEIVED 2
//#define ACHIEVE_REWARD_STATE_UNFINISHED 3
//#define ACHIEVE_FUWEN_STATE_UNFINISHED 0//1:�ѻ�ã�0��δ���
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
//typedef struct PlayerAttr//�������
//{
//	std::string name;//������
//	int value;//����ֵ
//}tPlayerAttr;
//
//
//class BaseItemData
//{
//public:
//	int level;//�ȼ�
//	int slot;
//	int maxDurability;
//	int count;//item����
//	int qualty;//Ʒ��
//	int allowableClass;
//	int inventorytype;
//	int sellPrice;
//	int enchantments;//������
//	int spellcooldown;
//	int duration;
//	int spellcategory;
//	int tipsClass;//tips����
//	int canuse;
//	int subclass;
//	int fighting_force;
//	int bonding;
//	int petStudyLevel;
//	int spellid;
//	int itemclass;//��������  classtype
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
//	int entry;//����typeId
//	int maxSocket;//������
//	int overdue_type;
//	int questid;
//	std::vector<int> sockets;//���
//	int caizhuangid;
//	int baserepaired;
//	std::string name;
//	std::string buffDesc;
//	std::string item_from_where;
//	std::string description;
//	tPoint requiredLevel;
//	std::vector<tKV> enchant;//��ħ
//	std::vector<tKV> add_states;
//	std::vector<std::vector<std::string> > states;
//	std::vector<float> damage;
//	std::vector<float> defense;
//	std::vector<std::string> popupWnd;
//	bool isActive;   //��Ӧgrid��� isActive
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
//class ItemConfigData: public BaseItemData//���ñ��������
//{
//public:
//	int equipmentset;
//public:
//	ItemConfigData()
//	{
//		equipmentset = 0;
//	}
//};
//class ItemData: public BaseItemData//��������
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
//class GuildStorageData: public ItemData //���Ųֿ�����
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
//class EnchantmentConfigData//�����������
//{
//public:
//	int id;//�Ǽ�
//	int bonuses;
//	int consum;//����Ǯ��
//	int failure;//ʧ�ܽ����Ǽ�
//	tPoint successrate;//�����ɹ���
//	std::vector<int> riseup;//�������Ǳ�ʯ
//	std::vector<int> protect;//���ñ�����ʯ
//	std::vector<int> lucky;//�������˱�ʯ
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
//class EnchantFenjieConfigData//�ֽ���������
//{
//public:
//	int id;//Ʒ��
//	int money;//���Ľ�Ǯ
//	int productsNum;//�ֽ����Ŀ
//	std::vector<int> products;//�ɷֽ���ĵ���id
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
//class EnchantDakongConfigData//�����������
//{
//public:
//	int id;//�׶�
//	int money;//���Ľ�Ǯ
//	tPoint rate;//�ɹ���
//	std::vector<int> stoneList;//��Ҫ�Ĵ��ʯid
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
//class EnchantFumoColorConfigData//��ħ��ɫ��������
//{
//public:
//	int id;//��ħ����id
//	std::vector<tPoint> colorList;//���п��ܵ���ɫ
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
//	tPoint giveoutLv;//��װ���ĵȼ�����
//	tPoint getLv;//��װ���ĵȼ�����
//	int needmoney;//��Ҫ��Ǯ
//	std::vector<tVector3> needitem;//��Ҫ����
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
//class EnchantJiefengConfigData//װ�������Ϣ
//{
//public:
//	int id;
//	int newItem;//�µ���
//	int needmoney;//��Ҫ��Ǯ
//	tVector3 needitem;//��Ҫ����
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
//class EnchantShengjiConfigData//װ��������Ϣ
//{
//public:
//	int id;
//	int newItem;//�µ���
//	int needmoney;//��Ҫ��Ǯ
//	tVector3 needitem;//��Ҫ����
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
//class RefineItemConfigData//���Ƶ�һ������
//{
//public:
//	int id;
//	int itemId;//���Ƶ���id
//	int money;//����Ǯ��
//	int bindingType;//Ǯ������
//	int serialNumber;
//	std::string successRatio;//�ɹ���
//	std::string des;//����
//	std::vector<tVector3> needItemList;//��Ҫ���ߣ�tVector3.x:����id, tVector3.y:�󶨵���id��tVector3.z:��Ҫ��Ŀ��
//	std::vector<int> showItemList;//Ҫ��ʾ�ĵ���id
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
//			pos += readInt(data, needitem.z);//����
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
////����list����Ϣ
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
////����������Ϣ��tab��
//class RefineConfigData
//{
//public:
//	int id;//tabҳid
//	std::string tabName;//tabҳ����
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
////����¯��������
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
////��ҩ��������
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
////������ͬһ������ĳƷ�ʵ�ĳ�������������������
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
////������ͬһ������ĳƷ�ʵ���������������
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
//cocos2d::ccColor3B getColorByQuality(int quality);//���ݵ���Ʒ�ʻ�ȡ�ִ���ɫ
//cocos2d::ccColor3B getFumoColorByKV(tKV kv);//���ݵ��߸�ħ���Ի�ȡ��ħ�ִ���ɫ
//int getFumoQualityByKV(tKV kv);//���ݸ�ħ���Ի�ȡ����Ʒ��
//EnchantZhuanyiConfigData* getZhuanyiDataByLv(int sencondaryLv, int mainLv);//���ݸ�װ������װ���ȼ���ȡ��������
//
////baseItemData Ϊnull ʱ��grid Ϊ�գ�status = GRID_FREE
//void updateGridItemByBaseItemData(GridItem * gridItem,BaseItemData * baseItemData=NULL); 
////status = GRID_USED��GRID_FREE��GRID_LOCKED,һ�������ã�posΪgrid��gridpanel�е�λ�ã��ڼ�������0��ʼ����������gridpanelʱpos=0��slot һ��ΪBaseItemData�е�slot,����ʱĬ��0��srcΪgrid����Դ�����϶�ʱ��ʹ�á�
//void updateGridItemByBaseItemData(GridItem * gridItem,BaseItemData * baseItemData,int status,int pos=0,int slot=0,int src=0);
//
//void updateWXGridByBaseItemData(WXGrid * grid,BaseItemData * baseItemData=NULL); 
//void updateWXGridByBaseItemData(WXGrid * grid,BaseItemData * baseItemData,int status,int pos=0,int slot=0,int src=0);
//
//
///**********************************************************************/
///*  ������
///************************************************************************/
//
//class BeadsPrayConfigData{
//public:
//	int8 key;
//	std::vector<tKV> items;//����Ʒ
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
//	int32 state;//1������ɣ���1δ���
//	int32 finished;//������ɽ���
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
//	int32 state;//1:����ȡ��2������ȡ��3��δ���
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
//	int32 state;//1:�ѻ�ã�0��δ���
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
//}tVenationPointProto;//��Ϊ��̬������Ϣ
//
//
//typedef struct VenationInfo
//{
//public:
//	std::vector<int>* venation;//��Ϊ8�ֵ����޲���
//	std::vector<int>* venationBone;//����8�ֵ����޲���
//	std::vector<tKV>* attr;//���ӵ����� 
//	int32 remainTime;//����ʣ�����
//	int64 totalexp;//������þ�������
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
//}tVenationInfo;//��Ϊ��������Ϣ�ṹ:��������ɵ���Ϊ����������
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
//}tVenationProficient;//����̬������Ϣ
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
//}tVipLevelConfigData;//VIP��̬������Ϣ
//
//
//typedef struct VipInfo
//{
//public:
//	int32 curVipLevel;//��ǰVIP�ȼ�����Ӧvip_level.txt�е�key
//	int32 type;//���콱���Ƿ���ȡ��0δ��ȡ��1����ȡ
//	int32 type2;//�Ƿ��ڣ�0δ���ڣ�1����
//	int32 gold;//��δ֪������������0��
//	int32 endTime;//vip��ֹ����(��)
//	int32 leftNum;//С��Ьʣ�����
//	int32 totalNum;//С��Ь��������
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
//}tVipInfo;//VIP��Ϣ
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
//}tHotBarItem;//�������Ϣ
//
//typedef struct AnswerQuestionData
//{
//public:
//	int32 id;
//	std::string questionContent;//��Ŀ����
//	std::map<int32,std::string> questionOptions;//ѡ��
//	int32 rightAnswer;//��ȷ��
//	std::vector<int32> awardScore;//������ȷ�÷��б�(δ��)
//	int32 readingTime;//����ʱ��
//public:
//	AnswerQuestionData()
//	{
//
//	}
//}tAnswerQuestionData;//������Ŀ����
//
//typedef struct AnswerQuestionOption
//{
//public:
//	int key;
//	std::map<int,std::string> startTime;//key==1������ʼʱ�䣬key==2���⿪ʼʱ��
//	int32 earlySignupTime;
//	int32 questionNum;
//	int32 gapTime;
//	std::map<int,int> vipAddition;
//	int32 allRightAddition;
//	std::map<int,int> rankAward;
//	std::map<int,int> doubleTimes;//˫�����ִ������ݣ����ݵ�ǰVIP���ͻ�ȡ
//	std::map<int,int> autoTimes;//�Զ�����������ݣ����ݵ�ǰVIP���ͻ�ȡ
//	std::map<int,int> basicExp; //����ÿһ�ֻ�þ����������ݵ�ǰ�û��ȼ���ȡ
//}tAnswerQuestionOption;//question_option.txt����ѡ������
//
//
//
