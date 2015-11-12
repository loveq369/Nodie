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
	bool loadResTick(float dt);//������Դ��tick�������Ƿ�������
	void loadAllUITexture();//����UI��Դ
	void readText();
	CC_SYNTHESIZE_READONLY(Tmx2MapData*, _mapData, Tmx2MapData);
	
	void initPlayerAttrStr();
	std::string getPlayerAttrStr(int key);//��ȡ������Ժ���
private:
	DataManager();
	DataManager(const DataManager&);
	DataManager& operator=(const DataManager&);
	~DataManager();
private:
	std::map<int, std::string> playerAttrStr;//������Ժ���
	std::queue<int> waitInitDataQueue;//�ȴ����ص�����
};