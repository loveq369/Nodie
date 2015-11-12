#pragma once

class Player;
class PlayerAction
{
public:
	PlayerAction(void);
	~PlayerAction(void);

	void setAction(int action);
	int getAction();
	int getActionTypeByWeapon();//����������ȡ��ϵ
	int getStopRange();//��ȡ��ɫ�ƶ�ֹͣ���
private:
	int action;//��ϵ
public:
	bool isBattle;
	bool isCampBattle;
	bool isInYhzqBattle;
	bool isInSpa;
	bool isWorldCup;
	bool isTraining;
};

