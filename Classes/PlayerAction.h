#pragma once

class Player;
class PlayerAction
{
public:
	PlayerAction(void);
	~PlayerAction(void);

	void setAction(int action);
	int getAction();
	int getActionTypeByWeapon();//根据武器获取关系
	int getStopRange();//获取角色移动停止间距
private:
	int action;//关系
public:
	bool isBattle;
	bool isCampBattle;
	bool isInYhzqBattle;
	bool isInSpa;
	bool isWorldCup;
	bool isTraining;
};

