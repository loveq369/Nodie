#include "HelloWorldScene.h"
#include "Player.h"
#include "util/Tmx2MapData.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg=Sprite::create("bg.png");
	bg->setPosition(visibleSize/2);
	this->addChild(bg);

	auto map=CCTMXTiledMap::create("map.tmx");
	Tmx2MapData mapdata;
	mapdata.readMapData("001.mapData");
	//mapdata.readTmxFile("s001.tmx","D://001.mapData");
	map->setTag(102);
	this->addChild(map,0);

	auto player=Player::create(Vec2(48,769));
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("player.plist");
	Vector<SpriteFrame*> allf;
	for (int i=1;i<9;i++)
	{
		SpriteFrame * pFrame=SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("npc_5407-%d.png",i));
		allf.pushBack(pFrame);
	}
	Animation * animation=Animation::createWithSpriteFrames(allf);
	animation->setDelayPerUnit(0.1f);
	Animate* animate=Animate::create(animation);
	player->runAction(RepeatForever::create(animate));
	setPlayer( player);
	this->addChild(player,5);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	//listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	scheduleUpdate();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::update( float dt)
{
	float mapSpeed=2.5f;
	float playerV=1.0f;
	auto map=this->getChildByTag(102);
	Player * player=(Player *)this->getChildByTag(101);
	map->setPositionX(map->getPositionX()-mapSpeed);
	if (map->getPositionX()<=-640*9)
	{
		map->setPositionX(0);
		player->setPosition(Vec2(48,768));
		return;
	}
	checkDown();
	if (m_pPlayer->getDirection()==DIRECTION_UP)
	{
		if (m_pPlayer->getPlayerSpeed()-playerV>=0)
		{
			m_pPlayer->setPlayerSpeed(m_pPlayer->getPlayerSpeed()-playerV);
			m_pPlayer->setPositionY(m_pPlayer->getPositionY()+m_pPlayer->getPlayerSpeed());
		}
		else
		{
			m_pPlayer->setPlayerSpeed(0);
			m_pPlayer->setDirection(DIRECTION_DOWN);
		}
	}
	else if (m_pPlayer->getDirection()==DIRECTION_DOWN)
	{
		
		m_pPlayer->setPlayerSpeed(m_pPlayer->getPlayerSpeed()+playerV);
		m_pPlayer->setPositionY(m_pPlayer->getPositionY()-m_pPlayer->getPlayerSpeed());
	}
	checkDie();
	
}

void  HelloWorld::checkDie()
{
	CCTMXTiledMap* map=(CCTMXTiledMap*)getChildByTag(102);
	CCPoint posionInTmx=ccp(m_pPlayer->getPositionX()-map->getPositionX(),1136-m_pPlayer->getPositionY());
	Vec2 posionInMap=posionInTmx/16;
	posionInMap=ccp(floor(posionInMap.x),floor(posionInMap.y));
	auto maplayer=map->getLayer("groud");
	UINT gid1=maplayer->tileGIDAt(posionInMap+Vec2(3,-1));
	UINT gid2=maplayer->tileGIDAt(posionInMap+Vec2(3,-2));
	UINT gid3=maplayer->tileGIDAt(posionInMap+Vec2(3,-3));
	UINT gid4=maplayer->tileGIDAt(posionInMap+Vec2(3,-4));
	UINT gid5=maplayer->tileGIDAt(posionInMap+Vec2(3,-5));
	if (gid1==1||gid2==1||gid3==1||gid4==1||gid5==1)
	{
		map->setPositionX(0);
		m_pPlayer->setPosition(Vec2(48,768));
	}
}
void HelloWorld::checkDown()
{
	CCTMXTiledMap* map=(CCTMXTiledMap*)getChildByTag(102);
	CCPoint posionInTmx=ccp(m_pPlayer->getPositionX()-map->getPositionX(),1136-m_pPlayer->getPositionY());
	Vec2 posionInMap=posionInTmx/16;
	posionInMap=ccp(floor(posionInMap.x),floor(posionInMap.y));
	auto maplayer=map->getLayer("groud");
	if (posionInMap.y>=70)
	{
		map->setPositionX(0);
		m_pPlayer->setDirection(DIRECTION_STOP);
		m_pPlayer->setPosition(Vec2(48,768));
		m_pPlayer->setDirection(DIRECTION_STOP);
		return;
	}
	
	UINT gid1=maplayer->tileGIDAt(posionInMap);
	UINT gid2=maplayer->tileGIDAt(posionInMap+Vec2(1,0));
	UINT gid3=maplayer->tileGIDAt(posionInMap+Vec2(1,1));
	UINT gid4=maplayer->tileGIDAt(posionInMap+Vec2(0,1));
	if (gid1==1||gid2==1)
	{
		m_pPlayer->setPlayerSpeed(0.0f);
		m_pPlayer->setPositionY(1136-posionInMap.y*16+1);
		m_pPlayer->setDirection(DIRECTION_STOP);
	}
	else if(gid3==0&&gid4==0&&m_pPlayer->getDirection()==DIRECTION_STOP)
	{
		m_pPlayer->setDirection(DIRECTION_DOWN);
	}
}

bool HelloWorld::onTouchBegan(Touch * pTouche,CCEvent * pEvent)
{	
	CCPoint  postion=pTouche->getLocationInView();
	postion=CCDirector::sharedDirector()->convertToGL(postion);
	if (postion.y>768&&m_pPlayer->getDirection()==DIRECTION_STOP)
	{
		m_pPlayer->setDirection(DIRECTION_UP);
		m_pPlayer->setPlayerSpeed(15.0f);
	}
	return true;
}
