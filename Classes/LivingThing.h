#pragma once

#include "BaseElement.h"

//name板
typedef enum
{
	livingthing_name_rolename = 1,
	livingthing_tile=2,
} livingThingName;

class LivingThingData;
class LivingThing: public BaseElement
{
public:
	LivingThing();
	LivingThing(const LivingThing&);
	LivingThing& operator=(const LivingThing&);
	virtual ~LivingThing();

	virtual bool init();
	virtual void onExit();
	//是否点中
	virtual bool itemForTouch(cocos2d::CCPoint& touchLocation);
	//添加到场景中
	virtual void addedToScene();

	////////////////////////////////一些属性//////////////////////////////////////////
	//所在z深度
	virtual int depth()const;
	virtual cocos2d::CCSize getSize();
	virtual cocos2d::Rect   getRect();
	//设置名字
	virtual void setName(const char* _arg1);
	virtual tPoint getTileCoord();
	virtual void setTileCoord(const tPoint& tp);

	virtual std::string getName();//名字
	virtual int getCurrentHP();//当前血量
	virtual int getTotalHP();//血量上限
	virtual int getCurrentMP();//当前蓝
	virtual int getTotalMP();//蓝上限
	virtual int getType();
	virtual int64 getId();
	virtual int getFlag();
	virtual float getBodyHeight();
	virtual cocos2d::CCNode* getNameLayer();

	//根据dest点改变角色方向
	virtual void facePoint(cocos2d::CCPoint dest);
	//是否显示身体
	virtual void showBody(bool isShow);
	//是否显示名字
	virtual void showName(bool isShow=true);
	//是否超出视野
	virtual void outOfSight(bool isOut);
	//设置透明值
	virtual void setSelfOpacity(GLubyte opacity);


	//////////////////////////////行为////////////////////////////////////////////
	virtual void dead();
	virtual void reborn();
	virtual void disappear();
	virtual bool isDead();
	virtual void destoryTarget();


	////////////////////////////////移动//////////////////////////////////////////
	virtual float getMoveSpeed(){ return 0.0f;}
	//移动队列，开始移动
	virtual void movePath(std::vector<tPoint>& pathList);
	//移到下一点
	virtual void moveNext();
	//移动停止
	virtual void moveStop();
	//开始移动
	virtual void move();
	//取消移动
	virtual void moveCancel();

	virtual void addFollower(LivingThing* follower);//添加跟随者
	virtual void removeFollower(LivingThing* follower=NULL);//移除跟随者
	virtual void notifyFollower();//通知跟随者
	virtual void onFollowTarget(LivingThing* target);//目标移动了

	virtual void setFollowerTarget(LivingThing* followerTarget);//设置跟随的目标
	////////////////////////////////pose系统//////////////////////////////////////////
	virtual void setPoseState(int status);//添加某个动作状态
	virtual void unsetPoseState(int status);//解除某个动作状态
	virtual bool isInPoseState(int status);//是否在摸个动作状态中

	//排版名字板，x y：名字板开始位置，从下往上
	virtual void layoutNameLayer(int x, int y);


	CC_SYNTHESIZE(LivingThingData*, livingThingData, LivingThingData);

protected:
	//设置动作前缀
	void setAnimPrefix(std::string animPrefix);
	//设置方向
	void setDirection(int direction);
	//释放动作
	void releaseSequence();

	cocos2d::CCSequence* getSequence(int type=0, cocos2d::CCCallFunc* callFunc=NULL);
	virtual void playStand();
	virtual void playWalk();
	virtual void playDead();
	virtual void playReborn();
	virtual void playDisappear();
	virtual void playDeadCallback();
	virtual void playRebornCallback();
	virtual void playDisappearCallback();
	//刷新动作
	virtual void refreshAction();
	//播动画
	virtual void playAction(int action);
	virtual void animCancel();

protected:
	cocos2d::CCSprite* bodyLayer;
	cocos2d::CCSprite* shadowLayer;
	cocos2d::CCNode* nameLayer;
	std::vector<tPoint> pendingPath;//实体移动队列
	int poseState;
	int buffState;//
	tPoint nextStepPos;//该单位下一步移动到位置
	int _direction;//动作方向
	std::string _animPrefixStr;//当前动作前缀
	int oldDir;//上一个方向
	std::string oldPrefix;//上一个前缀
	CC_SYNTHESIZE(tPoint, bornPos, BornPos);
	CC_SYNTHESIZE(std::string, _bodyEqualStr, bodyEqualStr);//当前装备字符串
	CC_SYNTHESIZE(cocos2d::CCAction*, moveAction, MoveAction);//移动action
	CC_SYNTHESIZE(cocos2d::CCAction*, animAction, AnimAction);//当前动画action
	std::map<LivingThing*, bool> m_mFollowerDic;//跟随者
	LivingThing* m_pFollowerTarget;//我正在跟随的目标
	int livingThingKind;
};