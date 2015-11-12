#pragma once
#include "cocos2d.h"
#include "ReadUtil.h"
#include "SearchPath.h"
USING_NS_CC;

class Tmx2MapData :public Ref
{
public:
	Tmx2MapData();
	~Tmx2MapData();
	void readTmxFile(char * tmxurl,char * mapDataurl);
	void readMapData(char * urlmapdata);
	BOOL writeData(char * urlwrite);


	bool nodeIsAlpha(int x, int y);
	bool nodeIsWalk(int x, int y);
	int getMapNodeFlag(int x, int y);
	cocos2d::CCPoint getNearPointCanWalk(int rolex,int roley,int x, int y);
	bool canReach(tPoint start, tPoint end, int distance, bool flag=true);//能否直接到达目标点
	std::vector<tPoint> getPathList(tPoint start, tPoint end, int distance=0);//获取寻路路径
	std::vector<tPoint> getPathBetweenTwoPoint(tPoint start, tPoint end);//获取两点间路径

	CC_SYNTHESIZE(uint16, cellWidth, CellWidth);
	CC_SYNTHESIZE(uint16, cellHeight, CellHeight);
	CC_SYNTHESIZE(uint16, xLen, XLen);
	CC_SYNTHESIZE(uint16, yLen, YLen);
	CC_SYNTHESIZE(uint16, width, Width);
	CC_SYNTHESIZE(uint16, height, Height);
	CC_SYNTHESIZE(uint16, connectedPointY, ConnectedPointY);
	CC_SYNTHESIZE(uint16, sliceWidth, SliceWidth);
	CC_SYNTHESIZE(uint16, sliceHeight, SliceHeight);

	CC_SYNTHESIZE_READONLY( std::vector<unsigned char>* , maskArray, MaskArray);
	CC_SYNTHESIZE_READONLY( std::vector<unsigned char>* , aphaVec, AphaVec);
	CC_SYNTHESIZE_READONLY( std::vector<unsigned char>* , fileArray, FileArray);
	CC_SYNTHESIZE_READONLY(CDGAME3DSearchPath*, searchPath, SearchPath);
};