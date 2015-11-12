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
	virtual void resetSendWalkPath(tPoint tp);//发送移动队列到服务器
	virtual void moveStop();

	void moveStartByJoy(int joyDirection);//通过遥感开始移动
	void moveStopByJoy();//遥感停下来

	void changeCloth();

	virtual void playSitDown();
	std::string getSitDownStr();
	std::string getClothStr();
	CREATE_FUNC(Player);
protected:
	//通过遥感方向，获取动作方向
	virtual void getAnimDirectByJoyDirect(int& animDirection, int& joyDirection);
private:
private:
	bool isMovingByJoy;//是否通过遥感在移动
	int joyDirection;//遥感遥控的方向
	cocos2d::CCPoint _destPos;
	int range;//角色移动停止间距
	std::vector<tPoint>* sendedWalkPath;
};