#include "Player.h"
#include "Frame.h"
#include "SceneController.h"
#include "GameDefine.h"
#include "DataManager.h"
#include "GameGobal.h"
#include "gamecore.h"
#include "LivingThingData.h"
#include "PlayerController.h"
#include "HeadImage.h"
#include "util/UrlUtil.h"
Player::Player()
{
	isMovingByJoy = false;
	range = 0;
	sendedWalkPath = new std::vector<tPoint>();
	livingThingKind = ENTITY_TYPE_PLAYER;
	PlayerController::getInstance().setRole(this);
}

Player::~Player()
{
	CC_SAFE_DELETE(sendedWalkPath);
}
void Player::addedToScene()
{
	livingThingData = (LivingThingData*)PlayerController::getInstance().getRoleData();
	livingThingData->setDataOwner(this);

	LivingThing::addedToScene();

	HeadImage* headImg = GameGobal::getInstance().getGameUILayer()->getRoleHeadImage();
	headImg->updateName((livingThingData->name).c_str());
	headImg->updatePlayerLv(livingThingData->level);
	headImg->updateClassType(livingThingData->faction);
	headImg->updateRoleHeadImage(getPlayerHeadImgUrl(livingThingData->faction, livingThingData->gender));
	headImg->updateHPMP();

	setDirection(DIRECTION_DOWN);
	setName(livingThingData->name.c_str());
	setPosition(SceneController::getInstance().positionForTileCoord(livingThingData->tx,livingThingData->ty));//livingThingData->tx,livingThingData->ty));
	changeCloth();
	if (livingThingData->state==CREATURE_STATE_SITDOWN)
	{
		playSitDown();
	}
	else
	{
		playStand();
	}
}

void Player::changeCloth()
{
	if (livingThingData)
	{
		setbodyEqualStr(getClothStr());
		int height = AnimateManager::getInstance().getFrameHeight(_bodyEqualStr.c_str(), "stand2");
		if (height>0)
		{
			bodyLayer->setPositionY(0.0f);
			height += 10;
			layoutNameLayer(0, height);
		}
		refreshAction();
	}
}

std::string Player::getClothStr()
{
	int equipment = 0;
	int lastEquipment = ((100000000 + (livingThingData->faction * 10000000)) + 2000000) + (livingThingData->gender * 100000) + equipment;
	char str[_MAX_PATH_];
	memset(str, 0, sizeof(str));
	sprintf(str, "%s%d/%d.anim", MODEL_FOLDER_PLAYER, lastEquipment, lastEquipment);
	return str;
}

std::string Player::getSitDownStr()
{
	char cstr[_MAX_PATH_];
	memset(cstr,0,sizeof(cstr));
	sprintf(cstr,"%d%d",livingThingData->faction,livingThingData->gender);
	std::string str=MODEL_FOLDER_SITDOWN;
	str+=cstr;
	str+="/";
	str+=cstr;
	str+=".anim";
	return str;
}

void Player::playSitDown()
{
	std::string display=getSitDownStr();
	bool isFlipX = false;
	CCSpriteFrame* spriteFrame = AnimateManager::getInstance().getFirstSpriteFrame(display.c_str(), DEFAULT_ANIMATE_NAME, isFlipX);
	if (spriteFrame)
	{
		bodyLayer->setPositionY(0.0f);
		bodyLayer->setDisplayFrame(spriteFrame);
		bodyLayer->setFlipX(isFlipX);
		layoutNameLayer(0, bodyLayer->getContentSize().height+10);
	}
	else
	{
		spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PLACEHOLDER_IMAGE);
		if (spriteFrame)
		{
			bodyLayer->setDisplayFrame(spriteFrame);
			bodyLayer->setPositionY(bodyLayer->getContentSize().height/2);
		}
		layoutNameLayer(0, bodyLayer->getContentSize().height+10);
	}
}
static int step = 0;
void Player::tick(float dt)
{
	if (isMovingByJoy)
	{
		tPoint oldTp = getTileCoord();
		float _local1 = (float)(WALK_SPEED_BASE*getMoveSpeed())*dt;
		float _local2 = _local1;
		float x = 0.0f;
		float y = 0.0f;
		float w = (float)(DataManager::getInstance().getTmx2MapData()->getWidth());
		float h = (float)(DataManager::getInstance().getTmx2MapData()->getHeight())-150;
		switch(joyDirection)
		{
		case DIRECTION_RIGHT_DOWN:
			{
				x = getPositionX()+_local2;
				y = getPositionY()-_local2;
				break;
			}
		case DIRECTION_LEFT_DOWN:
			{
				x = getPositionX()-_local2;
				y = getPositionY()-_local2;
				break;
			}
		case DIRECTION_LEFT_UP:
			{
				x = getPositionX()-_local2;
				y = getPositionY()+_local2;
				break;
			}
		case DIRECTION_RIGHT_UP:
			{
				x = getPositionX()+_local2;
				y = getPositionY()+_local2;
				break;
			}
		case DIRECTION_DOWN:
			{
				x = getPositionX();
				y = getPositionY()-_local1;
				break;
			}
		case DIRECTION_LEFT:
			{
				x = getPositionX()-_local1;
				y = getPositionY();
				break;
			}
		case DIRECTION_UP:
			{
				x = getPositionX();
				y = getPositionY()+_local1;
				break;
			}
		case DIRECTION_RIGHT:
			{
				x = getPositionX()+_local1;
				y = getPositionY();
				break;
			}
		}
		x = WX_MIN(w, x);
		x = WX_MAX(0.0f, x);
		y = WX_MIN(h, y);
		y = WX_MAX(0.0f, y);
		tPoint tp = SceneController::getInstance().tileCoordForPosition((float)x, (float)y);
		if (DataManager::getInstance().getTmx2MapData()->nodeIsWalk(tp.x, tp.y))
		{
			setPosition(ccp(x, y));
			if ((tp.x-oldTp.x)!=0 || (tp.y-oldTp.y)!=0)
			{
				
			}
		}
	}
	else
	{
		step++;
		if (step%10==0)
		{
			
		}
	}
}

void Player::getAnimDirectByJoyDirect(int& animDirection, int& joyDirection)
{
	switch (joyDirection)
	{
	case DIRECTION_RIGHT:
	case DIRECTION_RIGHT_UP:
	case DIRECTION_RIGHT_DOWN:
		animDirection = DIRECTION_RIGHT;
		break;
	case DIRECTION_LEFT:
	case DIRECTION_LEFT_UP:
	case DIRECTION_LEFT_DOWN:
		animDirection = DIRECTION_LEFT;
		break;
	case DIRECTION_DOWN:
		animDirection = DIRECTION_DOWN;
		break;
	case DIRECTION_UP:
		animDirection = DIRECTION_UP;
		break;
	}
}
void Player::moveStartByJoy(int joyDirection)
{
	isMovingByJoy = true;
	moveCancel();
	this->joyDirection = joyDirection;
	int animateDirection;
	getAnimDirectByJoyDirect(animateDirection, joyDirection);
	if (_direction!=animateDirection || _animPrefixStr!=ANIMPREFIX_WALK)
	{
		setDirection(animateDirection);
		playWalk();
	}
}
void Player::moveStopByJoy()
{
	isMovingByJoy = false;
	playStand();
}

void Player::resetSendWalkPath(tPoint tp)
{
	std::vector<tPoint> blank;
	sendedWalkPath->swap(blank);
	if (pendingPath.size()>0)
	{
		int len = 0;
		len = WALK_SEND_SPEED*(WALK_SEND_COUNT-1);
		std::vector<tPoint>::iterator itr = pendingPath.begin();
		while (len>0 && itr!=pendingPath.end())
		{
			sendedWalkPath->push_back(*itr);
			--len;
			++itr;
		}
		std::vector<tPoint> finalPathList;
		finalPathList.push_back(tp);
		len = sendedWalkPath->size();
		itr = sendedWalkPath->begin();
		int index = 1;
		while (itr!=sendedWalkPath->end())
		{
			if (index%3==0)
			{
				finalPathList.push_back(*itr);
			}
			if ((index==len) && (index<WALK_SEND_SPEED*WALK_SEND_COUNT) && !(len%WALK_SEND_SPEED==0))
			{
				finalPathList.push_back(sendedWalkPath->back());
			}
			++index;
			++itr;
		}
		if (finalPathList.size()<2)
		{
			return;
		}
	}
}
void Player::moveNext()
{
	if (sendedWalkPath->size()>0)
	{
		if (sendedWalkPath->front()==nextStepPos)
		{
			if (sendedWalkPath->size()==WALK_SEND_SPEED)
			{
				resetSendWalkPath(nextStepPos);
			}
			if (!sendedWalkPath->empty())
			{
				sendedWalkPath->erase(sendedWalkPath->begin());
			}
		}
		else
		{
			resetSendWalkPath(nextStepPos);
			if (!sendedWalkPath->empty())
			{
				sendedWalkPath->erase(sendedWalkPath->begin());
			}
		}
	}
	else
	{
		resetSendWalkPath(nextStepPos);
		if (!sendedWalkPath->empty())
		{
			sendedWalkPath->erase(sendedWalkPath->begin());
		}
	}
	LivingThing::moveNext();
}

float Player::getMoveSpeed()
{
	return livingThingData->moveSpeed;
}

void Player::movePath(std::vector<tPoint>& pathList)
{
	LivingThing::movePath(pathList);
	if (pathList.size()>30)
	{
		
	}
}
void Player::moveStop()
{
	LivingThing::moveStop();
}

bool Player::isDead()
{
	return (livingThingData->currentHP<=0||LivingThing::isDead());
}

void Player::dead()
{
	LivingThing::dead();
}
void Player::reborn()
{
	LivingThing::reborn();;
}



