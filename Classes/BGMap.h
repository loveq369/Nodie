#pragma once

#include "MacrosDefine.h"


class BGMap:public cocos2d::CCNode
{
public:
	BGMap();
	BGMap(const BGMap&);
	BGMap& operator=(const BGMap&);
	virtual ~BGMap();

	void build(cocos2d::CCSize& mapSize, cocos2d::CCSize& sliceSize, char* mapPath);//初始化构建地图（mapSize：地图大小，sliceSize：切块大小，mapPath：地图资源路径）
	void firstLoad(cocos2d::CCRect& rect);//首次进入场景加载地图（如果设置相关回调函数，则会引发回调）
	void load(cocos2d::CCRect& rect);//可视范围发生变化，引发加载地图
	bool addUrgencyBg(int num=2);//紧急加载图片（返回值：是否需要紧急加载）
	bool addBackgroundBg();//后台加载图片（返回值：是否需要后台加载）
	void clearAll();//移除所有图片
	void setTarget(cocos2d::CCNode* target, SEL_CallFuncI startLoadFunc, SEL_CallFuncI loadingFunc, cocos2d::SEL_CallFunc stopLoadFunc);//设置三个加载回调函数

	CC_SYNTHESIZE_READONLY(int, m_totalNum, TotalNum);//所有需要加载的图片数目
	CC_SYNTHESIZE_READONLY(int, m_currentNum, CurrentNum);//当前加载了的图片数目
	CREATE_FUNC(BGMap);
private:
	void loadTextureCallback(cocos2d::Texture2D* texture);//首次加载图片回调
	void bgLoadTextureCallback(cocos2d::Texture2D* texture);//后台加载图片回调
private:
	std::map<std::string, cocos2d::CCSprite*> m_bg;//所有背景tile图片
	std::map<std::string, cocos2d::CCPoint> m_posDic;//图片的位置信息
	std::map<std::string, char> m_visibleFileNameDic;//当前显示的图片名字
	std::map<std::string, char> m_unvisibleFileNameDic;//当前不显示的图片名字
	std::vector<std::string> m_urgencyWaitLoad;//需要紧急加载的
	std::vector<std::string> m_backgroundWaitLoad;//后台加载的
	int m_width;//背景图宽
	int m_height;//背景图高
	int m_sliceWidth;//背景tile宽
	int m_sliceHeight;//背景tile高
	std::string m_folder;//背景图所在目录

	cocos2d::CCNode* m_target;//回调函数
	SEL_CallFuncI m_loadingFunc;//正在加载回调（函数int参数：加载了图片数目）
	SEL_CallFuncI m_startLoadFunc;//开始加载回调（函数int参数：所有要加载图片数目）
	cocos2d::SEL_CallFunc m_stopLoadFunc;//停止加载回调
};
