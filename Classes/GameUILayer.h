#pragma once

#include "cocos2d.h"
#include "HeadImage.h"
#include "NpcDialog.h"
#include "TaskDialog.h"
class GameUILayer:public cocos2d::CCLayer
{
public:
	GameUILayer(void);
	~GameUILayer(void);

	virtual bool init();
	//��ʼ��Ϸ��tick
	void startGameTick(float dt);
	bool initTick();
	//������������ɣ���ʼ��Ϸ
	void startGame();
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //������ʼ�¼�  
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //�����ƶ��¼�  
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //���������¼�  
	void onTouchCancelle(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void reverseOrderAllChildren();
	void showPanel(WXSimplePanel* panel, bool isShow=true);//ĳ�������ʾ��ر���
	CREATE_FUNC(GameUILayer);
	CC_SYNTHESIZE_READONLY(HeadImage*, _roleHead, RoleHeadImage);
	/*CC_SYNTHESIZE_READONLY(MyTeamPanel*, myTeamPanel, MyTeamPanel);*/
	CC_SYNTHESIZE_READONLY(WXSimplePanel*, currentHitPanel, CurrentHitPanel);//��ǰ�������
	CC_SYNTHESIZE_READONLY(NpcDialog*, _npcDialog, NpcDialog);
	CC_SYNTHESIZE_READONLY(TaskDialog*, _taskDialog, TaskDialog);
private:
	cocos2d::Vector<cocos2d::Touch*> m_touches;//����¼�
	cocos2d::CCTouch* m_pCurrentTouch;//��ǰ���
	std::queue<int> waitInitUIQueue;
	std::map<int, std::map<int, char> > relationshipBetweenPanel;//����ϵ
};