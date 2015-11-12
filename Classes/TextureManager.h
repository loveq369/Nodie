#pragma once

#include "cocos2d.h"


class TextureLifecycle//纹理生命周期
{
public:
	cocos2d::CCTexture2D* texture;//对应纹理
	long lastReferenceTime;//最后一次用的时间
	int count;//用过的次数
};

class TextureManager: public cocos2d::CCObject
{
public:
	static TextureManager& getInstance()
	{
		static TextureManager instance;
		return instance;
	}
	void tick(float dt);//判断是否需要清除内存
	cocos2d::CCTexture2D* addImage(const char* filename);//获得一张图片（该图片加入管理，存在生命周期，满足条件将自动释放，自动释放）
	cocos2d::CCTexture2D* addStaticImage(const char* filename);//获得一张图片，该图片只有在退出游戏才会释放
	void addStaticImageAsync(const char* filename, cocos2d::CCObject *target, cocos2d::SEL_CallFuncO selector);
	void removeStaticImage(const char* filename);//将静态图片从内存中移除

	CC_SYNTHESIZE(long, m_maxLifecycle, MaxLifecycle);//每张图最多持续时间
	CC_SYNTHESIZE(float, m_maxInterval, MaxInterval);//清除内存检查间隔

private:
	TextureManager();
	TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);
	~TextureManager();

	bool checkNeedRelease(TextureLifecycle& tlc);//检查是否需要释放
	void loadTextureCallback(cocos2d::CCTexture2D* texture);
private:
	std::map<std::string, TextureLifecycle> m_textureLifecycleDic;//自动释放的
	std::map<std::string, cocos2d::CCTexture2D*> m_staticTextureDic;//静态不释放的
	cocos2d::CCObject* m_target;//回调
	cocos2d::SEL_CallFuncO m_selector;//回调函数
	float m_currInterval;//当前内存检查间隔
	bool m_isTicking;//是否正在tick
};

