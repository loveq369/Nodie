#include "SceneController.h"
#include "SceneManager.h"
#include "DataManager.h"
#include "PlayerController.h"
SceneController::SceneController()
{
	sceneManager = new SceneManager();
}
SceneController::~SceneController()
{
	CC_SAFE_DELETE(sceneManager);
}
void SceneController::startGame()
{
	if (sceneManager)
		sceneManager->startGame();

}
void SceneController::buildScene()
{
	DataManager::getInstance().getTmx2MapData()->readTmxFile("s001.tmx","D://001.mapdata");
	DataManager::getInstance().getTmx2MapData()->readMapData("001.mapData");
	sceneManager->buildScene();
}

void SceneController::tick(float dt)
{
	if (sceneManager)
		sceneManager->tick(dt);
	Player* player = PlayerController::getInstance().getRole();
	if (player)
		setRolePos(player->getPosition());
}


void SceneController::clean()
{
	_rolePos = CCPoint::ZERO;
	_focusPos = CCPoint::ZERO;
}
void SceneController::setRolePos(const CCPoint& rolePos)
{
	if (_rolePos.equals(rolePos))
	{
		return;
	}
	_rolePos.x = rolePos.x;
	_rolePos.y = rolePos.y;

	WINSIZE;
	int x = int(MAX(rolePos.x, winSize.width/2));
	int y = int(MAX(rolePos.y, winSize.height/2));
	x = int(MIN(x, (DataManager::getInstance().getTmx2MapData()->getWidth() - winSize.width/2)));
	y = int(MIN(y, (DataManager::getInstance().getTmx2MapData()->getHeight() - winSize.height/2)));
	CCPoint actualPosition = ccp(x,y);
	CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
	_focusPos = ccpSub(centerOfView, actualPosition);

	sceneManager->getSceneLayer()->setPosition(_focusPos);
	sceneManager->focusPosChange(ccp(actualPosition.x-winSize.width/2,actualPosition.y+winSize.height/2));
}

tPoint SceneController::tileCoordForPosition(int x, int y)
{
	Tmx2MapData* mapData = DataManager::getInstance().getTmx2MapData();
	float cellWidth = mapData->getCellWidth();
	float cellHeight = mapData->getCellHeight();
	int yLen = mapData->getYLen();
	tPoint tp;
	tp.x = x/cellWidth;
	tp.y = (yLen*cellHeight-y)/cellHeight;

	return tp;
}
void SceneController::tileCoordForPosition(const cocos2d::CCPoint& pixelPos, tPoint& tilePos)
{
	Tmx2MapData* mapData = DataManager::getInstance().getTmx2MapData();
	float cellWidth = mapData->getCellWidth();
	float cellHeight = mapData->getCellHeight();
	int yLen = mapData->getYLen();
	tilePos.x = pixelPos.x/cellWidth;
	tilePos.y = (yLen*cellHeight-pixelPos.y)/cellHeight;
}

CCPoint SceneController::positionForTileCoord(int x, int y)
{
	Tmx2MapData* mapData = DataManager::getInstance().getTmx2MapData();

	int cellWidth = DataManager::getInstance().getTmx2MapData()->getCellWidth();
	int cellHeight = DataManager::getInstance().getTmx2MapData()->getCellHeight();
	int yLen = DataManager::getInstance().getTmx2MapData()->getYLen();

	int xp = (x*cellWidth) + cellWidth/2;
	int yp = (yLen*cellHeight)-(y*cellHeight)-cellHeight/2;

	return ccp(xp, yp);
}
void SceneController::positionForTileCoord(const tPoint& tilePos, cocos2d::CCPoint& pixelPos)
{

	Tmx2MapData* mapData = DataManager::getInstance().getTmx2MapData();
	int cellWidth = mapData->getCellWidth();
	int cellHeight = mapData->getCellHeight();
	int yLen = mapData->getYLen();

	pixelPos.x = (tilePos.x*cellWidth) + cellWidth/2.0f;
	pixelPos.y = (yLen*cellHeight)-(tilePos.y*cellHeight)-cellHeight/2.0f;

}