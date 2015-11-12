#include "HeadImage.h"
#include "UIDefine.h"
#include "GameDefine.h"
#include "GameGobal.h"
#include "PlayerController.h"
#include "PlayerData.h"
#include "Player.h"
#include "util/tools.h"

USING_NS_CC;

#define HEAD_UI			"roleHead.png"
#define ROLE_HP			"hp.png"
#define ROLE_MP			"mp.png"

HeadImage::HeadImage()
{
	setCanTween(false);
	playerLv = NULL;
}
HeadImage::~HeadImage()
{
}
bool HeadImage::init()
{
	nameStr = "";
	headURLStr = "";
	_roleName = NULL;
	_hpSprite = NULL;
	_mpSprite = NULL;
	_roleSprite = NULL;
	_bg = NULL;
	classTypeSprite = NULL;

	setVisible(false);
	return true;
}
void HeadImage::initPanel()
{
	_bg = CCSprite::createWithSpriteFrameName("newheadbk.png");
	_bg->setAnchorPoint(CCPoint::ZERO);
	addChild(_bg, 0);

	setContentSize(_bg->getContentSize());
	setAnchorPoint(CCPoint::ZERO);
	WINSIZE;
	setPosition(ccp(0,winSize.height-getContentSize().height));

	playerLv = CCLabelBMFont::create("", "fonts/font.fnt");
	playerLv->setScale(0.7f);
	playerLv->setColor(Color3B::YELLOW);
	playerLv->setPosition(ccp(180,68));
	_bg->addChild(playerLv, 3);

	_roleName = CCLabelTTF::create("leenini", FONT_NAME_DEFAULT, 20);
	_roleName->setPosition(ccp(120,70));
	_bg->addChild(_roleName);

	_hpSprite = CCProgressTimer::create(CCSprite::createWithSpriteFrameName("newhp.png"));
	_hpSprite->setType(kCCProgressTimerTypeBar);
	_hpSprite->setBarChangeRate(ccp(1,0));
	_hpSprite->setMidpoint(ccp(0,0.5));
	_hpSprite->setAnchorPoint(ccp(0.0f,0.5f));
	_hpSprite->setPosition(ccp(85,47));
	_bg->addChild(_hpSprite, 1);

	_mpSprite = CCProgressTimer::create(CCSprite::createWithSpriteFrameName("newmp.png"));
	_mpSprite->setType(kCCProgressTimerTypeBar);
	_mpSprite->setBarChangeRate(ccp(1,0));
	_mpSprite->setMidpoint(ccp(0,0.5));
	_mpSprite->setAnchorPoint(ccp(0.0f,0.5f));
	_mpSprite->setPosition(ccp(80,30));
	_bg->addChild(_mpSprite, 2);

	//statePanel = StatePanel::create(100, 34);
	//statePanel->setPosition(ccp(130, 28));
	//_bg->addChild(statePanel);

	

// 	LivingThingData* livingThingData = PlayerController::getInstance().getRoleData();
// 	updateName((livingThingData->name).c_str());
// 	updatePlayerLv(livingThingData->level);
// 	updateClassType(livingThingData->faction);
// 	updateHPMP();

	/*Player* player = PlayerController::getInstance().getRole();
	if (player)
	{
	std::map<int, tBuffData*>* buffDataDic = player->getAllBuffData();
	std::map<int, tBuffData*>::iterator itr = buffDataDic->begin();
	for (;itr!=buffDataDic->end();itr++)
	{
	statePanel->addIcon(itr->first, getBuffUrl(itr->second).c_str());
	}
	}*/
}
void HeadImage::resetPanelState()
{
	show(true);
}
void HeadImage::updateName(const char* name)
{
	nameStr = name;
	if (_roleName)
	{
		_roleName->setString(name);
	}
}
void HeadImage::updateClassType(int classType)
{
	return;
	this->classType = classType;
	if (_bg && !classTypeSprite)
	{
		if (classType==CLASS_MAGIC)
		{
			classTypeSprite = CCSprite::createWithSpriteFrameName(CLASS_MAGIC_UI);
		}
		else if (classType==CLASS_RANGE)
		{
			classTypeSprite = CCSprite::createWithSpriteFrameName(CLASS_RANGE_UI);
		}
		else if (classType==CLASS_MELEE)
		{
			classTypeSprite = CCSprite::createWithSpriteFrameName(CLASS_MELEE_UI);
		}
		if (classTypeSprite)
		{
			classTypeSprite->setAnchorPoint(ccp(0.0f,1.0f));
			classTypeSprite->setPosition(ccp(202,75));
			_bg->addChild(classTypeSprite);
		}
	}
}
void HeadImage::updateHPMP()
{
	if (_hpSprite && _mpSprite)
	{
		int currentHP = PlayerController::getInstance().getRoleData()->getCurrentHP();
		int totalHP = PlayerController::getInstance().getRoleData()->getTotalHP();
		_hpSprite->setPercentage(currentHP*100.0f/totalHP);

		int currentMP = PlayerController::getInstance().getRoleData()->getCurrentMP();
		int totalMP = PlayerController::getInstance().getRoleData()->getTotalMP();
		_mpSprite->setPercentage(currentMP*100.0f/totalMP);
	}
}
void HeadImage::updatePlayerLv(int level)
{
	if (playerLv)
	{
		char str[_MAX_PATH_];
		memset(str, 0, sizeof(str));
		sprintf(str, "%d", level);
		std::string lv="µÈ¼¶";
		GBKToUTF8(lv,"gb2312","utf-8");
		lv.append(str);
		playerLv->setString(lv);
	}
}
bool HeadImage::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return false;
	}
	CCPoint convertedLocation = this->convertTouchToNodeSpace(pTouch);
	if (_bg->boundingBox().containsPoint(convertedLocation))
	{
		return true;
	}
	return false;
}
bool HeadImage::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return false;
	}
	CCPoint convertedLocation = this->convertTouchToNodeSpace(pTouch);
	if (_bg->boundingBox().containsPoint(convertedLocation))
	{
		/*GameGobal::getInstance().getGameUILayer()->getMainUI()->toggle();
		GameGobal::getInstance().getGameUILayer()->getInstantChatPanel()->toggle();
		GameGobal::getInstance().getGameUILayer()->getSecondaryBtnPanel()->tweeningBtnCallback();*/
		return true;
	}
	return false;
	
}
void HeadImage::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
}
void HeadImage::onTouchMoved(Touch *pTouch, Event *pEvent)
{
}

void HeadImage::updateRoleHeadImage( const char* umage )
{
	if (umage && strcmp(umage,"")!=0)
	{
		CCTextureCache::sharedTextureCache()->addImageAsync(umage, CC_CALLBACK_1(HeadImage::loadHeadImgCallback,this));
	}
}

void HeadImage::loadHeadImgCallback( CCTexture2D* texture )
{
	if (texture)
	{

		if (_roleSprite)
		{
			_bg->removeChild(_roleSprite, true);
			_roleSprite = NULL;
		}
		_roleSprite = CCSprite::createWithTexture(texture);
		if (_roleSprite)
		{
			_roleSprite->setPosition(ccp(51,18));
			_roleSprite->setScale(0.7);
			_roleSprite->setAnchorPoint(ccp(.5f,0));
			_bg->addChild(_roleSprite);
		}
		CCTextureCache::sharedTextureCache()->removeTexture(texture);
			/*const char* filenameStr = (const char*)texture->;
			CCTextureCache::sharedTextureCache()->removeTextureForKey(filenameStr);*/
	}
}
