#pragma once

#include "EffectNode.h"


#define EFFECT_TYPE_GROUND	1//地面
#define EFFECT_TYPE_FLY		2//飞行
#define EFFECT_TYPE_TARGET	3//目标

#define EFFECT_PARTICLE_TYPE_PARTICLE	1//粒子特效
#define EFFECT_PARTICLE_TYPE_ANIM		2//动画特效

#define EFFECT_PART_HEAD	1//头部（身高）
#define EFFECT_PART_HEART	2//胸部（身高*2/3）
#define EFFECT_PART_TOP		3//顶部（身高）
#define EFFECT_PART_BUTTOM	4//底部（0）
#define EFFECT_PART_HAND	5//手部（身高*1/2）
#define EFFECT_PART_LEG		6//腿部（身高*1/3）

class EffectConfigData
{
public:
	std::string m_effectName;//特效名字
	std::string m_particleName;//所用到相关效果名字（如果是动作，则是动作名，如果是粒子就是粒子名）
	int8 m_particleType;//特效类型（粒子、动作）
	float m_startTime;//开始播放时间
	float m_duration;//持续时间
public:
	void encode(unsigned char*& data, unsigned long& pos);
};

class EffectInfo//当前特效信息
{
public:
	cocos2d::CCPoint m_startPixelPos;//特效起始点像素位置
	cocos2d::CCPoint m_endPixelPos;//特效结束点像素位置
	tPoint m_startTileCoord;//特效起始点tile位置
	tPoint m_endTileCoord;//特效结束点tile位置
	int m_flySpeed;//速度
	bool m_isFlyRepeat;//飞行特效是否重复
	int8 m_type;//特效作用目标类型
	int8 m_part;//命中点
	int m_zorder;//渲染的zorder
	cocos2d::CCSize m_ownerSize;//特效发起方大小
	cocos2d::CCSize m_targetSize;//目标单位大小
	EffectNode* m_effectParent;//特效挂接点
	EffectConfigData m_configData;//配置数据
public:
	EffectInfo()
	{
		m_isFlyRepeat = false;
		m_zorder = 65535;
		m_ownerSize.width = 0.0f;
		m_ownerSize.height = 0.0f;
		m_targetSize.width = 0.0f;
		m_targetSize.height = 0.0f;
	}
};

class Effect: public cocos2d::CCObject
{
public:
	Effect(void);
	~Effect(void);

	void tick(float dt);//tick特效（控制播放和停止）
	void init();//初始化粒子特效/动画特效
	void clear();//释放粒子特效/动画特效
	bool isDead();//特效是否播放结束
	void stop();//停止特效播放
	void removeParticle();//从目标身上移除特效
	void addParticle();//给目标添加特效
	void reset();//重设一些数据
	void setFlySpeed(int flySpeed);//设置飞行特效速度
	void setPart(int8 part);//设置特效播放的目标位置

	void setEffectInfo(EffectInfo& ei);//设置特效信息

	CC_SYNTHESIZE(bool, m_isPlaying, IsPlaying);//是否正在播放
	CC_SYNTHESIZE_READONLY(cocos2d::CCNode*, m_displayNode, DisplayNode);//特效表现点

private:
	void startFly();//开始飞行
	void flyOverCallback();//飞行结束
private:
	EffectInfo m_effectInfo;//特效信息
	float m_sElapsed;//开始时间间隔
	float m_dElapsed;//持续时间间隔
};
