#pragma once

#include "WXPanel.h"

class HeadImage: public WXPanel
{
public:
	HeadImage();
	~HeadImage();

	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	bool onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

	bool init();
	void initPanel();
	void resetPanelState();

	void updateName(const char* name);
	void updateClassType(int classType);
	void updatePlayerLv(int level);
	void updateHPMP();
	void updateRoleHeadImage(const char* umage);

	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelBMFont*, playerLv, PlayerLv);//角色等级

	CREATE_FUNC(HeadImage);
private:
	//头像load回调
	void loadHeadImgCallback(cocos2d::CCTexture2D* texture);
private:
	cocos2d::CCLabelTTF* _roleName;
	cocos2d::CCProgressTimer* _hpSprite;
	cocos2d::CCProgressTimer* _mpSprite;
	cocos2d::CCSprite* _bg;
	cocos2d::CCSprite* classTypeSprite;
	cocos2d::CCSprite* _roleSprite;

	std::string nameStr;
	std::string headURLStr;
	int classType;
};