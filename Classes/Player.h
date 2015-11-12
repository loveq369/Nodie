#pragma once

#include "LivingThing.h"

class Player: public LivingThing
{
public:
	Player();
	Player(const Player&);
	Player& operator=(const Player&);
	virtual ~Player();

	void tick(float dt);
	virtual void addedToScene();


	virtual void dead();
	virtual void reborn();
	virtual bool isDead();
	virtual float getMoveSpeed();
	virtual void movePath(std::vector<tPoint>& pathList);
	virtual void moveNext();
	virtual void resetSendWalkPath(tPoint tp);//�����ƶ����е�������
	virtual void moveStop();

	void moveStartByJoy(int joyDirection);//ͨ��ң�п�ʼ�ƶ�
	void moveStopByJoy();//ң��ͣ����

	void changeCloth();

	virtual void playSitDown();
	std::string getSitDownStr();
	std::string getClothStr();
	CREATE_FUNC(Player);
protected:
	//ͨ��ң�з��򣬻�ȡ��������
	virtual void getAnimDirectByJoyDirect(int& animDirection, int& joyDirection);
private:
private:
	bool isMovingByJoy;//�Ƿ�ͨ��ң�����ƶ�
	int joyDirection;//ң��ң�صķ���
	cocos2d::CCPoint _destPos;
	int range;//��ɫ�ƶ�ֹͣ���
	std::vector<tPoint>* sendedWalkPath;
};