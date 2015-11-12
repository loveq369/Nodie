#pragma once

#include "SceneManager.h"

class SceneController: public cocos2d::CCObject
{
public:
	static SceneController& getInstance()
	{
		static SceneController instance;
		return instance;
	}
	//�������
	void startGame();
	//��������
	void buildScene();
	//��ʱ��
	void tick(float dt);
	//��Ϸ��������
	CC_SYNTHESIZE(SceneManager*, sceneManager, SceneManager);
	//��������->��ש����
	tPoint tileCoordForPosition(int x, int y);
	//��ש����->��������
	cocos2d::CCPoint positionForTileCoord(int x, int y);
	//��������->��ש����
	void tileCoordForPosition(const cocos2d::CCPoint& pixelPos, tPoint& tilePos);
	//��ש����->��������
	void positionForTileCoord(const tPoint& tilePos, cocos2d::CCPoint& pixelPos);


	//������λ��/focusλ�õȳ�ʼ����Ϣ
	void clean();
private:
	cocos2d::CCPoint _rolePos;
	cocos2d::CCPoint _focusPos;
	cocos2d::CCRect roleAOIRect;
	SceneController();
	SceneController(const SceneController&);
	SceneController& operator=(const SceneController&);
	~SceneController();
	void setRolePos(const cocos2d::CCPoint& rolePos);
};