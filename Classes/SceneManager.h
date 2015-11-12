#pragma once
#include "cocos2d.h"
#include "EffectNode.h"
#include "SceneLayer.h"
#include "Player.h"
#include "gamecore.h"
#include "LivingThingDefine.h"
typedef	std::map<int64, tNpcEntity*>			npc_entity_map_t;

//寻路目标类型
typedef enum
{
	autorun_type_invalid = 0,//无效
	autorun_type_npc,//npc
	autorun_type_player,//玩家
	autorun_type_tile,//地砖坐标
	autorun_type_exit,//传送点
	autorun_type_monster,//怪物
	autorun_type_pet,//宠物
	break_type_click,
	break_type_move
} autoRunType;
//自动寻路数据
class tAutoRunData
{
public:
	tPoint tp;//寻路点
	tPoint fp;//小飞鞋目标点
	int mapId;
	int64 targetId;
	int flyShoesMapId;
	autoRunType type;//寻路目标类型
public:
	tAutoRunData()
	{
		tp.x=0;
		tp.y=0;
		fp.x=0;
		fp.y=0;
		mapId = 0;
		targetId = 0;
		flyShoesMapId = 0;
		type=autorun_type_invalid;
	}
};
class ElementLayer: public EffectNode
{
public:
	CREATE_FUNC(ElementLayer);
};

class SceneManager: public cocos2d::CCObject
{
public:
	SceneManager();
	SceneManager(const SceneManager&);
	SceneManager& operator=(const SceneManager&);
	~SceneManager();

	virtual bool init();
	virtual void tick(float dt);

	//开始游戏
	void startGame();
	//构建场景
	void buildScene();
	//根据玩家位置刷新bg
	void refreshPlayerBG();
	//摄像头focus位置改变
	void focusPosChange(const cocos2d::CCPoint& rolePos);
	///////////////////////////////element操作///////////////////////////////////////////
	void addPlayer();
	void removeAllEntity();
	void addElement(BaseElement* baseElemet);
	std::vector<BaseElement*>* getAllElement(){return &_elementList;};
	CC_SYNTHESIZE(SceneLayer*, sceneLayer, SceneLayer);
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸开始事件  
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸移动事件  
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //触摸结束事件  
	void onTouchCancelle(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	//////////////////////////////////////////////////////////////////////////
	//点击目标处理, isTouch:是否是玩家点击屏幕触发
	void clickTarget(BaseElement* target, bool isTouch=false);
	//玩家移动到地砖坐标（当前地图）（d：停止距离）
	void roleMoveToTile(int x, int y, int d=0);
	//点中element？
	BaseElement* itemForTouch(cocos2d::CCTouch *touch);
	//取消clicktarget
	void cancelClickTarget();
	//获取玩家aoi
	const cocos2d::CCRect& getRoleAOIRect(){return roleAOIRect;};
	npc_entity_map_t* getAllNpcEntity(){return npcDic;};
	void setClickTarget(BaseElement* baseElemet);
	void addToNpcQueue(NpcData* npcData);
	void removeNpc(int64 id);
	void addNpc(tNpcEntity* npcEntity);
	tNpcEntity* getNpcEntity(int64 id);//获取npc实体
	tNpcEntity* getNpcEntityByEntryId(int entryId);//根据entryId获取npc实体
	LivingThingData* getElementData(int64 id);
	LivingThing* getElement(int64 id);
	BaseElement* getElementByNearly(tPoint targetPos, int entityType=2, int npcType=2,\
	  std::map<int, bool>* targetEntryIdDic=NULL);//获取一个指定位置附近、指定类型的livingThing
	BaseElement* getRandomElementByNearly(int entityType=2, int npcType=2, LivingThing* target=NULL);//获取一个玩家附近、指定类型的livingThing(且与target不同的)
	//添加npc时候检查寻路数据
	bool checkPlayerAutoRunData(NPC* target);
	//玩家pose发送改变
	void rolePoseChange();
	void roleTalkToNpc(NPC* npc);
	void roleToCollect(NPC* collect);
	///////////////////////////////移动///////////////////////////////////////////
	//移动到指定位置
	void roleMove(tPoint end, int _arg2=0);
	//场景内寻路
	void roleMoveInScene();
	//跨场景寻路
	void roleMoveCrossScene();
	//根据npc entryid,角色移动到npc处
	void roleMoveToNpc(int entryId);
	//检查寻路数据，是否继续寻路
	bool checkPlayerAutoRunData();
	//获取寻路数据
	tAutoRunData* getPlayerAutoRunData();
	//清空寻路数据
	void clearPlayerAutoRunData();
private:
	void removeElement(BaseElement* baseElemet);
	void playMouseEffect();
	void mouseEffectFinish();
	void checkElementOnMask(BaseElement* baseElemet);
private:
	bool _firstFocus;
	tPoint tilePos;//地砖坐标
	cocos2d::CCPoint _oldFocusPos;
	cocos2d::CCRect roleAOIRect;
	BaseElement* _clickTarget;
	Player* m_pPlayer;//玩家
	cocos2d::CCNode* _frontBGLayer;
	ElementLayer* _elementLayer;
	cocos2d::CCSprite* _mouseLayer;
	std::vector<BaseElement*> _elementList;
	npc_entity_map_t* npcDic;
	npc_entity_map_t waitAddNpcList;
	tAutoRunData* playerAutoRunData;//玩家自动寻路数据
	int _step;
	float _totalTime;
	BGMap* _frontBg;
};