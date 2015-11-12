#pragma once
#include <queue>
#include <map>
#include "util/Tmx2MapData.h"
class DataManager
{   
public:
	static DataManager& getInstance()
	{
		static DataManager instance;
		return instance;
	}
	void loadRes();
	bool loadResTick(float dt);//加载资源的tick，返回是否加载完成
	void loadAllUITexture();//加载UI资源
	void readText();
	CC_SYNTHESIZE_READONLY(Tmx2MapData*, _mapData, Tmx2MapData);
	
	void initPlayerAttrStr();
	std::string getPlayerAttrStr(int key);//获取玩家属性汉字
private:
	DataManager();
	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);
	~DataManager();
private:
	std::map<int, std::string> playerAttrStr;//玩家属性汉字
	std::queue<int> waitInitDataQueue;//等待加载的数据
};