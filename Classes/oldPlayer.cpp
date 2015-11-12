#include "Player.h"

Player::Player()
	:m_direction(DIRECTION_STOP)
	,m_playerSpeed(0.0f)
{
	
}

Player* Player::create(const Vec2& point)
{
	Player* player = NULL;
	player = new Player();
	player->init();
	player->setTag(101);
	player->setAnchorPoint(Vec2(0.0f,0.0f));
	player->setPosition(point);
	player->autorelease();
	return player;
}