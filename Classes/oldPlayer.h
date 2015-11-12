#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
USING_NS_CC;
enum DIRECTION
{
	DIRECTION_STOP=0,
	DIRECTION_UP,
	DIRECTION_DOWN
};
class Player : public cocos2d::Sprite
{
public:
	Player();
	static Player* create(const Vec2& point);
	~Player(){}
	CC_SYNTHESIZE(DIRECTION,m_direction,Direction);
	CC_SYNTHESIZE(float,m_playerSpeed,PlayerSpeed);
};

#endif