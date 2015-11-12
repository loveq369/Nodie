#pragma once

#include "cocos2d.h"
#define DEFAULT_ANIMATE_NAME "default"

struct InfoIndex//记录动作相关信息索引
{
	short m_picIndex;//该动作图片路劲索引
	short m_posIndex;//该动作切图数据索引
};

//一个切片信息
class PlistFrame
{
public:
	cocos2d::CCRect m_frame;//切图矩形
	cocos2d::CCPoint m_offset;//偏移
	bool m_rateted;//是否旋转
public:
	PlistFrame(){};
	PlistFrame(cocos2d::CCRect frame,cocos2d::CCPoint offset,bool rateted);
	void encode(unsigned char*& data, unsigned long& pos);
};

//一张图片上所有的plist信息
class ItemPlistData
{
public:
	std::string m_picFilename;//图片名字
	std::vector<PlistFrame> m_plistFrameList;//该图片所有的plist信息
public:
	ItemPlistData(){};
	ItemPlistData(std::string picFilename);
	void pushBack(PlistFrame listFrame);
	void encode(unsigned char*& data, unsigned long& pos);
};

//一个动作
class ItemAnimateData
{
public:
	float m_delay;//动作帧间隔
	bool m_flipX;//是否反转x
	bool m_flipY;//是否反转y
	std::vector<InfoIndex> m_infoIndexList;//该动作文件动作帧用到的所有索引信息
	int m_refernceTimes;//该动作使用次数
public:
	ItemAnimateData(){};
	ItemAnimateData(float delay,bool flipX,bool flipY,int refrernceTimes);
	void pushBack(InfoIndex infoIndex);
	void encode(unsigned char*& data, unsigned long& pos);
};

//一个动作文件的所有动作信息，包含相关plist信息
class ObjectAllAnimations
{
public:
	std::map<std::string, ItemAnimateData> allAnimations;//所有动作信息
	std::vector<ItemPlistData> infoPlistList;//该动作文件用到的所有plist信息
public:
	void pushBackItemAnimateData(std::pair<std::string, ItemAnimateData> pairAniData);
	void pushBackItemPlistData(ItemPlistData itemPlistData);
	void encode(unsigned char*& data, unsigned long& pos);
	void writeToFile(char* file);
};

//动作管理
class AnimateManager
{
public:
	static AnimateManager& getInstance()
	{
		static AnimateManager instance;
		return instance;
	}
	void parseXML(const char *fileName);
	//解析一个动作文件
	void parseObject(const char* filename);
	//根据文件名获取动作文件所有数据（如果不存在，则尝试读取）
	ObjectAllAnimations* getObjectAnimationsByFilename(const char* filename);
	//获取animateName动作的第一帧高度
	int getFrameHeight(const char* filename, const char* animateName);
	//根据动作名获取第一帧spriteFrame，如果新创建，将被放入CCSpriteFrameCache
	cocos2d::CCSpriteFrame* getFirstSpriteFrame(const char* filename, const char* animateName, bool& isFlipX);

	//根据动作名获取动作
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc);
	//根据动作名获取动作，可传入延迟，xy反转（如果delay<0则用AnimateData里的帧间隔）
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, float delay, bool flipX, bool flipY);
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, float delay);
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, bool flipX);

	//创建动作
	cocos2d::CCSequence* createSequence(cocos2d::CCArray* actions);
	//创建动作
	cocos2d::CCSequence* createSequence(cocos2d::CCAnimation* animation, cocos2d::CCCallFunc* callFunc, float delay, bool flipX, bool flipY);

	//根据动作名获取animation
	cocos2d::CCAnimation* getAnimation(const char* filename, const char* animateName, ItemAnimateData*& animateData);
	//某个node不再用该动作了，如果已经没有node使用该动作则施法图片内存
	void releaseSequence(const char* animateName);

	CC_SYNTHESIZE(std::string, m_resFolderStr, ResFolderStr);//资源文件夹路径
	CC_SYNTHESIZE(std::string, m_resTypeStr, ResTypeStr);//资源文件后缀

private:
	AnimateManager();
	AnimateManager(const AnimateManager&);
	AnimateManager& operator=(const AnimateManager&);
	~AnimateManager();
	//解析一个动作文件
	ObjectAllAnimations* __parseObject(const char* filename);
private:
	std::map<std::string, ObjectAllAnimations*> m_animDataDic;//所有动作文件，key：动作文件文件名，value：该动作文件包含所有动作
};
