#pragma once
#include "cocos2d.h"
#include "EffectNode.h"
#include "SceneLayer.h"
#include "Player.h"
#include "gamecore.h"
#include "LivingThingDefine.h"
typedef	std::map<int64, tNpcEntity*>			npc_entity_map_t;

//Ѱ·Ŀ������
typedef enum
{
	autorun_type_invalid = 0,//��Ч
	autorun_type_npc,//npc
	autorun_type_player,//���
	autorun_type_tile,//��ש����
	autorun_type_exit,//���͵�
	autorun_type_monster,//����
	autorun_type_pet,//����
	break_type_click,
	break_type_move
} autoRunType;
//�Զ�Ѱ·����
class tAutoRunData
{
public:
	tPoint tp;//Ѱ·��
	tPoint fp;//С��ЬĿ���
	int mapId;
	int64 targetId;
	int flyShoesMapId;
	autoRunType type;//Ѱ·Ŀ������
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

	//��ʼ��Ϸ
	void startGame();
	//��������
	void buildScene();
	//�������λ��ˢ��bg
	void refreshPlayerBG();
	//����ͷfocusλ�øı�
	void focusPosChange(const cocos2d::CCPoint& rolePos);
	///////////////////////////////element����///////////////////////////////////////////
	void addPlayer();
	void removeAllEntity();
	void addElement(BaseElement* baseElemet);
	std::vector<BaseElement*>* getAllElement(){return &_elementList;};
	CC_SYNTHESIZE(SceneLayer*, sceneLayer, SceneLayer);
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //������ʼ�¼�  
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //�����ƶ��¼�  
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //���������¼�  
	void onTouchCancelle(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	//////////////////////////////////////////////////////////////////////////
	//���Ŀ�괦��, isTouch:�Ƿ�����ҵ����Ļ����
	void clickTarget(BaseElement* target, bool isTouch=false);
	//����ƶ�����ש���꣨��ǰ��ͼ����d��ֹͣ���룩
	void roleMoveToTile(int x, int y, int d=0);
	//����element��
	BaseElement* itemForTouch(cocos2d::CCTouch *touch);
	//ȡ��clicktarget
	void cancelClickTarget();
	//��ȡ���aoi
	const cocos2d::CCRect& getRoleAOIRect(){return roleAOIRect;};
	npc_entity_map_t* getAllNpcEntity(){return npcDic;};
	void setClickTarget(BaseElement* baseElemet);
	void addToNpcQueue(NpcData* npcData);
	void removeNpc(int64 id);
	void addNpc(tNpcEntity* npcEntity);
	tNpcEntity* getNpcEntity(int64 id);//��ȡnpcʵ��
	tNpcEntity* getNpcEntityByEntryId(int entryId);//����entryId��ȡnpcʵ��
	LivingThingData* getElementData(int64 id);
	LivingThing* getElement(int64 id);
	BaseElement* getElementByNearly(tPoint targetPos, int entityType=2, int npcType=2,\
	  std::map<int, bool>* targetEntryIdDic=NULL);//��ȡһ��ָ��λ�ø�����ָ�����͵�livingThing
	BaseElement* getRandomElementByNearly(int entityType=2, int npcType=2, LivingThing* target=NULL);//��ȡһ����Ҹ�����ָ�����͵�livingThing(����target��ͬ��)
	//���npcʱ����Ѱ·����
	bool checkPlayerAutoRunData(NPC* target);
	//���pose���͸ı�
	void rolePoseChange();
	void roleTalkToNpc(NPC* npc);
	void roleToCollect(NPC* collect);
	///////////////////////////////�ƶ�///////////////////////////////////////////
	//�ƶ���ָ��λ��
	void roleMove(tPoint end, int _arg2=0);
	//������Ѱ·
	void roleMoveInScene();
	//�糡��Ѱ·
	void roleMoveCrossScene();
	//����npc entryid,��ɫ�ƶ���npc��
	void roleMoveToNpc(int entryId);
	//���Ѱ·���ݣ��Ƿ����Ѱ·
	bool checkPlayerAutoRunData();
	//��ȡѰ·����
	tAutoRunData* getPlayerAutoRunData();
	//���Ѱ·����
	void clearPlayerAutoRunData();
private:
	void removeElement(BaseElement* baseElemet);
	void playMouseEffect();
	void mouseEffectFinish();
	void checkElementOnMask(BaseElement* baseElemet);
private:
	bool _firstFocus;
	tPoint tilePos;//��ש����
	cocos2d::CCPoint _oldFocusPos;
	cocos2d::CCRect roleAOIRect;
	BaseElement* _clickTarget;
	Player* m_pPlayer;//���
	cocos2d::CCNode* _frontBGLayer;
	ElementLayer* _elementLayer;
	cocos2d::CCSprite* _mouseLayer;
	std::vector<BaseElement*> _elementList;
	npc_entity_map_t* npcDic;
	npc_entity_map_t waitAddNpcList;
	tAutoRunData* playerAutoRunData;//����Զ�Ѱ·����
	int _step;
	float _totalTime;
	BGMap* _frontBg;
};