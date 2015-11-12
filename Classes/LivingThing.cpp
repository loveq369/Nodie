#include "LivingThing.h"
#include "Frame.h"
#include "util/MapUtil.h"
#include "SceneController.h"
#include "GameDefine.h"
#include "UIDefine.h"
#include "TargetController.h"
USING_NS_CC;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#define SHADOW_FILENAME	"shadow.png"

LivingThing::LivingThing()
{
	bornPos.x = 0;
	bornPos.y = 0;
	nextStepPos.x = 0;
	nextStepPos.y = 0;
	poseState = POSE_STATE_NULL;
	moveAction = NULL;
	animAction = NULL;
	oldDir = -1;
	oldPrefix = "";
	buffState = BUFF_STATE_NULL;
	bodyLayer = NULL;
	nameLayer = NULL;
	livingThingKind = ENTITY_TYPE_NULL;
	livingThingData = NULL;
	m_pFollowerTarget = NULL;
	setDirection(DIRECTION_DOWN);
}

LivingThing::~LivingThing()
{
	destoryTarget();
	releaseSequence();
}

void LivingThing::onExit()
{
	BaseElement::onExit();
	stopAllActions();
	bodyLayer->stopAllActions();
}

bool LivingThing::init()
{
	shadowLayer = CCSprite::createWithSpriteFrameName(SHADOW_FILENAME);
	addChild(shadowLayer, livingthing_zorder_shadow);

	bodyLayer = CCSprite::create();
	addChild(bodyLayer, livingthing_zorder_body);

	nameLayer = CCNode::create();
	nameLayer->setAnchorPoint(ccp(0.5, 0));
	nameLayer->setPosition(ccp(0, bodyLayer->getContentSize().height+10));
	addChild(nameLayer, livingthing_zorder_nameboard);

 	ccFontDefinition strokeTextDef;
 	strokeTextDef._fontSize = 26;
 	strokeTextDef._fontName = std::string("Marker Felt");
 	strokeTextDef._stroke._strokeEnabled = true;
 	strokeTextDef._stroke._strokeColor   = Color3B::BLACK;
 	strokeTextDef._stroke._strokeSize    = 0.2f;
 	strokeTextDef._fontFillColor   = CH_WHITE;
 
 	//CCLabelTTF* nameLabel = CCLabelTTF::createWithFontDefinition("123", strokeTextDef);
	CCLabelTTF* nameLabel = CCLabelTTF::create("123", FONT_NAME_DEFAULT,26);
	nameLabel->setColor(CH_WHITE);

	nameLayer->addChild(nameLabel,livingthing_name_rolename,livingthing_name_rolename);

	setContentSize(bodyLayer->getContentSize());

	return true;
}

int LivingThing::depth()const
{
	return getPositionY();
}
void LivingThing::addFollower(LivingThing* follower)
{
	m_mFollowerDic[follower] = true;
}
void LivingThing::removeFollower(LivingThing* follower)
{
	if (!follower)
	{
		std::map<LivingThing*, bool>::iterator itr = m_mFollowerDic.begin();
		for (;itr!=m_mFollowerDic.end();itr++)
		{
			itr->first->setFollowerTarget(NULL);
		}
		std::map<LivingThing*, bool> blank;
		m_mFollowerDic.swap(blank);
	}
	else
	{
		std::map<LivingThing*, bool>::iterator itr = m_mFollowerDic.find(follower);
		if (itr!=m_mFollowerDic.end())
		{
			itr->first->setFollowerTarget(NULL);
			m_mFollowerDic.erase(itr);
		}
	}
}
void LivingThing::notifyFollower()
{
	std::map<LivingThing*, bool>::iterator itr = m_mFollowerDic.begin();
	while (itr!=m_mFollowerDic.end())
	{
		itr->first->onFollowTarget(this);
		++itr;
	}
}
void LivingThing::onFollowTarget(LivingThing* target)
{

}

void LivingThing::setFollowerTarget(LivingThing* followerTarget)
{
	m_pFollowerTarget = followerTarget;
}

void LivingThing::destoryTarget()
{
	if (m_pFollowerTarget)
	{
		m_pFollowerTarget->removeFollower(this);
	}
	//通知跟随我的我消失了
	removeFollower(NULL);

	/*if (buffDataDic)
	{
		std::map<int, tBuffData*>::iterator itr = buffDataDic->begin();
		while (itr!=buffDataDic->end())
		{
			CC_SAFE_DELETE(itr->second);
			++itr;
		}
		CC_SAFE_DELETE(buffDataDic);
	}*/
	if (TargetController::getInstance().checkTarget(this))
	{
		TargetController::getInstance().setTarget(NULL);
	}
	//PlayerController::getInstance().getAutoGameManager()->checkIsDisappearTarget(this);
}

CCSize LivingThing::getSize()
{
	return this->bodyLayer->getContentSize();
}

Rect LivingThing::getRect()
{
	return Rect(_position.x,_position.y,getSize().width,getSize().height);
}

float LivingThing::getBodyHeight()
{
	return this->bodyLayer->getContentSize().height;
}
CCNode* LivingThing::getNameLayer()
{
	return nameLayer;
}


void LivingThing::setName(const char* rolename)
{
	((CCLabelTTF*)(nameLayer->getChildByTag(livingthing_name_rolename)))->setString(rolename);
}
void LivingThing::outOfSight(bool isOut)
{
	setVisible(!isOut);
}
void LivingThing::showBody(bool isShow)
{
	setVisible(isShow);
}
void LivingThing::showName(bool isShow/* =true */)
{
	nameLayer->setVisible(isShow);
}
std::string LivingThing::getName()
{
	return "";
}
int LivingThing::getCurrentHP()
{
	return 0;
}
int LivingThing::getTotalHP()
{
	return 0;
}
int LivingThing::getCurrentMP()
{
	return 0;
}
int LivingThing::getTotalMP()
{
	return 0;
}
void LivingThing::setDirection(int direction)
{
	if (_direction == direction)
	{
		return;
	}
	oldDir = _direction;
	_direction = direction;
}

void LivingThing::setAnimPrefix(std::string animPrefix)
{
	if (_animPrefixStr == animPrefix)
	{

	}
	else
	{
		oldPrefix = _animPrefixStr;
		_animPrefixStr = animPrefix;
	}
}
void LivingThing::releaseSequence()
{
}
CCSequence* LivingThing::getSequence(int type, CCCallFunc* callFunc)
{
	CCSequence* seq = NULL;
	if (type==0)//body
	{
		char str[10];
		memset(str, 0, sizeof(str));
		sprintf(str, "%s%d", _animPrefixStr.c_str(), _direction);
		seq = AnimateManager::getInstance().getSequence(_bodyEqualStr.c_str(), str, callFunc);
	}
	return seq;
}

void LivingThing::movePath(std::vector<tPoint>& pathList)
{
	moveCancel();
	std::vector<tPoint> blankPath;
	pendingPath.swap(blankPath);
	pendingPath = pathList;
	nextStepPos = getTileCoord();
	moveNext();
}
void LivingThing::moveNext()
{
	setTileCoord(nextStepPos);
	if(pendingPath.size()>0)
	{
		nextStepPos = pendingPath.front();
		pendingPath.erase(pendingPath.begin());
		move();
	}
	else
	{
		moveStop();
	}
}
void LivingThing::moveStop()
{
	moveCancel();
	playStand();
}
void LivingThing::moveCancel()
{
	if (moveAction)
	{
		this->stopAction(moveAction);
		moveAction = NULL;
	}
}
void LivingThing::move()
{
	tPoint start = this->getTileCoord();
	CCPoint startPos = this->getPosition();
	CCPoint endPos = SceneController::getInstance().positionForTileCoord(nextStepPos.x,nextStepPos.y);
	int direction = MapUtil::judgeDir(startPos.x,startPos.y,endPos.x,endPos.y);
	if (_direction!=direction || _animPrefixStr!=ANIMPREFIX_WALK)
	{
		setDirection(direction);
		playWalk();
	}
	float duration = ccpDistance(startPos, endPos)/(WALK_SPEED_BASE*getMoveSpeed());
	CCMoveTo* moveTo = CCMoveTo::create(duration, endPos);
	CCCallFunc* moveCallback = CCCallFunc::create(this, callfunc_selector(LivingThing::moveNext));
	moveAction = this->runAction(CCSequence::create(moveTo, moveCallback, NULL));
}

void LivingThing::facePoint(CCPoint dest)
{
	int direction = MapUtil::judgeDir(this->getPosition().x,this->getPosition().y,dest.x,dest.y);
	if(direction != _direction)
	{
		setDirection(direction);
	}
}

void LivingThing::playStand()
{
	setAnimPrefix(ANIMPREFIX_STAND);
	if (oldDir!=_direction || oldPrefix!=_animPrefixStr)
	{
		animCancel();
		CCSequence* seq;
		if (bodyLayer->isVisible())
		{
			seq = getSequence();
			if (seq)
			{
				animAction = bodyLayer->runAction(CCRepeatForever::create(seq));
				bodyLayer->setPositionY(0);
			}
			else
			{
				CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PLACEHOLDER_IMAGE);
				if (spriteFrame)
				{
					bodyLayer->setDisplayFrame(spriteFrame);
					bodyLayer->setPositionY(bodyLayer->getContentSize().height/2);
				}
				layoutNameLayer(0, bodyLayer->getContentSize().height+10);
			}
		}
	}
	setPoseState(POSE_STATE_STAND);
}
void LivingThing::playWalk()
{
	setAnimPrefix(ANIMPREFIX_WALK);
	if (oldDir!=_direction || oldPrefix!=_animPrefixStr)
	{
		animCancel();
		CCSequence* seq;
		if (bodyLayer->isVisible())
		{
			seq = getSequence();
			if (seq)
			{
				animAction = bodyLayer->runAction(CCRepeatForever::create(seq));
			}
		}
	}
	setPoseState(POSE_STATE_MOVE);
}
void LivingThing::playDead()
{
	setAnimPrefix(ANIMPREFIX_DEAD);
	if (oldDir!=_direction || oldPrefix!=_animPrefixStr)
	{
		if (bodyLayer->isVisible())
		{
			CCCallFunc* callback = CCCallFunc::create(this, callfunc_selector(LivingThing::playDeadCallback));
			CCSequence* seq = getSequence(0, callback);
			if (seq)
			{
				animAction = bodyLayer->runAction(seq);
			}
		}
	}
	setPoseState(POSE_STATE_DEAD);
}
void LivingThing::playDeadCallback()
{
	animCancel();
}
void LivingThing::playReborn()
{
	this->setVisible(true);
	playStand();
}
void LivingThing::playRebornCallback()
{
}
void LivingThing::playDisappear()
{
	this->setVisible(false);
}
void LivingThing::playDisappearCallback()
{
}
void LivingThing::playAction(int action)
{
	switch (action)
	{
	case ACTION_STAND:
	case ACTION_STAND2:
		{
			playStand();
			break;
		}
	case ACTION_RUN:
	case ACTION_WALK:
		{
			playWalk();
			break;
		}
	case ACTION_ATTACK1:
	case ACTION_ATTACK2:
	case ACTION_ATTACK3:
		{
			//playAttack();
			break;
		}
	case ACTION_DIE:
		{
			playDead();
			break;
		}
	default:
		{
			break;
		}
	}
}
void LivingThing::refreshAction()
{
	animCancel();
	CCSequence* seq;
	if (bodyLayer->isVisible())
	{
		seq = getSequence();
		if (seq)
		{
			if (_animPrefixStr==ANIMPREFIX_ATTACK)
			{
				//playAttack();
			}
			else
			{
				animAction = bodyLayer->runAction(CCRepeatForever::create(seq));
			}
		}
	}
}



void LivingThing::dead()
{
	animCancel();
	moveCancel();
	playDead();
}
void LivingThing::reborn()
{
	playReborn();
}
void LivingThing::disappear()
{
	bodyLayer->stopAllActions();
	stopAllActions();
	playDisappear();
}

void LivingThing::setSelfOpacity(GLubyte opacity)
{
	if (this->bodyLayer->getOpacity()!=opacity)
	{
		this->bodyLayer->setOpacity(opacity);
	}
}
tPoint LivingThing::getTileCoord()
{
	return SceneController::getInstance().tileCoordForPosition((int)this->getPosition().x,(int)this->getPosition().y);
}
void LivingThing::setTileCoord(const tPoint& tp)
{

}
void LivingThing::addedToScene()
{
	stopAllActions();
	bodyLayer->stopAllActions();
	setVisible(true);
}
void LivingThing::animCancel()
{
	if (animAction)
	{
		bodyLayer->stopAction(animAction);
		animAction = NULL;
	}
}


void LivingThing::setPoseState(int status)
{
	if (isInPoseState(status))
	{
		
	}
	else
	{
		if (status<=(~POSE_STATE_NULL))
		{
			poseState = poseState&POSE_STATE_NULL;
			poseState = poseState|status;
		}
	}
}
void LivingThing::unsetPoseState(int status)
{
	poseState = poseState&(~status);
}
bool LivingThing::isInPoseState(int status)
{
	if (status<=(~POSE_STATE_NULL))
	{
		return ((~POSE_STATE_NULL)&poseState&status)>0?true:false;
	}
	else
	{
		return (POSE_STATE_NULL&poseState&status)>0?true:false;
	}
}
int LivingThing::getType()
{
	return ENTITY_TYPE_NULL;
}
int64 LivingThing::getId()
{
	return 0;
}
int LivingThing::getFlag()
{
	return 0;
}
bool LivingThing::isDead()
{
	return (isInPoseState(POSE_STATE_DEAD)||!this->isVisible());
}
bool LivingThing::itemForTouch(cocos2d::CCPoint& touchLocation)
{
	CCRect rect;
	rect.size = bodyLayer->getContentSize();
	rect.origin = ccp(getPositionX()-rect.size.width/2, getPositionY());
	if (rect.containsPoint(touchLocation))
	{
		return true;
	}
	return false;
}

void LivingThing::layoutNameLayer(int x, int y)
{
	nameLayer->setPosition(ccp(x, y));
}
