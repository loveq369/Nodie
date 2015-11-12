#pragma once

#include "BaseElement.h"

//name��
typedef enum
{
	livingthing_name_rolename = 1,
	livingthing_tile=2,
} livingThingName;

class LivingThingData;
class LivingThing: public BaseElement
{
public:
	LivingThing();
	LivingThing(const LivingThing&);
	LivingThing& operator=(const LivingThing&);
	virtual ~LivingThing();

	virtual bool init();
	virtual void onExit();
	//�Ƿ����
	virtual bool itemForTouch(cocos2d::CCPoint& touchLocation);
	//��ӵ�������
	virtual void addedToScene();

	////////////////////////////////һЩ����//////////////////////////////////////////
	//����z���
	virtual int depth()const;
	virtual cocos2d::CCSize getSize();
	virtual cocos2d::Rect   getRect();
	//��������
	virtual void setName(const char* _arg1);
	virtual tPoint getTileCoord();
	virtual void setTileCoord(const tPoint& tp);

	virtual std::string getName();//����
	virtual int getCurrentHP();//��ǰѪ��
	virtual int getTotalHP();//Ѫ������
	virtual int getCurrentMP();//��ǰ��
	virtual int getTotalMP();//������
	virtual int getType();
	virtual int64 getId();
	virtual int getFlag();
	virtual float getBodyHeight();
	virtual cocos2d::CCNode* getNameLayer();

	//����dest��ı��ɫ����
	virtual void facePoint(cocos2d::CCPoint dest);
	//�Ƿ���ʾ����
	virtual void showBody(bool isShow);
	//�Ƿ���ʾ����
	virtual void showName(bool isShow=true);
	//�Ƿ񳬳���Ұ
	virtual void outOfSight(bool isOut);
	//����͸��ֵ
	virtual void setSelfOpacity(GLubyte opacity);


	//////////////////////////////��Ϊ////////////////////////////////////////////
	virtual void dead();
	virtual void reborn();
	virtual void disappear();
	virtual bool isDead();
	virtual void destoryTarget();


	////////////////////////////////�ƶ�//////////////////////////////////////////
	virtual float getMoveSpeed(){ return 0.0f;}
	//�ƶ����У���ʼ�ƶ�
	virtual void movePath(std::vector<tPoint>& pathList);
	//�Ƶ���һ��
	virtual void moveNext();
	//�ƶ�ֹͣ
	virtual void moveStop();
	//��ʼ�ƶ�
	virtual void move();
	//ȡ���ƶ�
	virtual void moveCancel();

	virtual void addFollower(LivingThing* follower);//��Ӹ�����
	virtual void removeFollower(LivingThing* follower=NULL);//�Ƴ�������
	virtual void notifyFollower();//֪ͨ������
	virtual void onFollowTarget(LivingThing* target);//Ŀ���ƶ���

	virtual void setFollowerTarget(LivingThing* followerTarget);//���ø����Ŀ��
	////////////////////////////////poseϵͳ//////////////////////////////////////////
	virtual void setPoseState(int status);//���ĳ������״̬
	virtual void unsetPoseState(int status);//���ĳ������״̬
	virtual bool isInPoseState(int status);//�Ƿ�����������״̬��

	//�Ű����ְ壬x y�����ְ忪ʼλ�ã���������
	virtual void layoutNameLayer(int x, int y);


	CC_SYNTHESIZE(LivingThingData*, livingThingData, LivingThingData);

protected:
	//���ö���ǰ׺
	void setAnimPrefix(std::string animPrefix);
	//���÷���
	void setDirection(int direction);
	//�ͷŶ���
	void releaseSequence();

	cocos2d::CCSequence* getSequence(int type=0, cocos2d::CCCallFunc* callFunc=NULL);
	virtual void playStand();
	virtual void playWalk();
	virtual void playDead();
	virtual void playReborn();
	virtual void playDisappear();
	virtual void playDeadCallback();
	virtual void playRebornCallback();
	virtual void playDisappearCallback();
	//ˢ�¶���
	virtual void refreshAction();
	//������
	virtual void playAction(int action);
	virtual void animCancel();

protected:
	cocos2d::CCSprite* bodyLayer;
	cocos2d::CCSprite* shadowLayer;
	cocos2d::CCNode* nameLayer;
	std::vector<tPoint> pendingPath;//ʵ���ƶ�����
	int poseState;
	int buffState;//
	tPoint nextStepPos;//�õ�λ��һ���ƶ���λ��
	int _direction;//��������
	std::string _animPrefixStr;//��ǰ����ǰ׺
	int oldDir;//��һ������
	std::string oldPrefix;//��һ��ǰ׺
	CC_SYNTHESIZE(tPoint, bornPos, BornPos);
	CC_SYNTHESIZE(std::string, _bodyEqualStr, bodyEqualStr);//��ǰװ���ַ���
	CC_SYNTHESIZE(cocos2d::CCAction*, moveAction, MoveAction);//�ƶ�action
	CC_SYNTHESIZE(cocos2d::CCAction*, animAction, AnimAction);//��ǰ����action
	std::map<LivingThing*, bool> m_mFollowerDic;//������
	LivingThing* m_pFollowerTarget;//�����ڸ����Ŀ��
	int livingThingKind;
};