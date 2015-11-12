#include "Tmx2MapData.h"
#include "byte_buffer.h"
#include <iostream>
#include <stdio.h>
Tmx2MapData::Tmx2MapData()
{
	maskArray = NULL;
	fileArray = NULL;
	cellWidth = 20;
	cellHeight = 20;
	xLen = 0;
	yLen = 0;
	width = 3000;
	height = 1500;
	sliceWidth=420;
	sliceHeight=300;
	searchPath = new CDGAME3DSearchPath();
}

Tmx2MapData::~Tmx2MapData(void)
{
	CC_SAFE_DELETE(maskArray);
	CC_SAFE_DELETE(fileArray);
	CC_SAFE_DELETE(searchPath);
}

void Tmx2MapData::readTmxFile(char * tmxurl,char * mapDataurl)
{
	auto map=CCTMXTiledMap::create(tmxurl);
	Size mapsz=map->getMapSize();
	xLen=(int16)mapsz.width;
	yLen=(int16)mapsz.height;
	Size titlesz=map->getTileSize();
	cellHeight=(int16)titlesz .height;
	cellWidth=(int16)titlesz.width;
	Size contentsz=map->getContentSize();
	width=(int16)contentsz.width;
	height=(int16)contentsz.height;
	fileArray =new std::vector<unsigned char>();
	std::vector<unsigned char> * aphaArray=new std::vector<unsigned char>();
	auto maplayer=map->getLayer("route");
	for (int i=0;i<mapsz.width;i++)
	{
		for (int j=0;j<mapsz.height;j++)
		{
			
			UINT gid=maplayer->tileGIDAt(Vec2(i,j));
			if (gid==0)
			{
				fileArray->push_back((unsigned char)0);
			}
			else
			{
				fileArray->push_back((unsigned char)1);
			}
		}
	}
	maplayer=map->getLayer("apha");
	for (int i=0;i<mapsz.width;i++)
	{
		for (int j=0;j<mapsz.height;j++)
		{

			UINT gid=maplayer->tileGIDAt(Vec2(i,j));
			if (gid==0)
			{
				aphaArray->push_back((unsigned char)0);
			}
			else
			{
				aphaArray->push_back((unsigned char)1);
			}
		}
	}
	ByteBuffer buffer;
	buffer<<width;
	buffer<<height;
	buffer<<xLen;
	buffer<<yLen;
	buffer<<cellWidth;
	buffer<<cellHeight;
	buffer<<(int16)0;
	buffer<<(int16)0;
	buffer<<*fileArray;
	buffer<<*aphaArray;
	CC_SAFE_DELETE(maskArray);
	FILE *a = fopen(mapDataurl,"wb");
	fwrite(buffer.contents(),buffer.size(),1,a);
	fclose(a);
}

void Tmx2MapData::readMapData(char * urlmapdata)
{
	unsigned long fileLen = 0;
	unsigned char *fileData = NULL;
	fileData = CCFileUtils::sharedFileUtils()->getFileData(urlmapdata, "rb", (ssize_t*)(&fileLen));
	unsigned char* data = fileData;
	unsigned long pos = 0;
	CC_SAFE_DELETE(maskArray);
	searchPath->UnLoadScene();
	pos += readUint16(data, width,false);
	pos += readUint16(data, height,false);
	pos += readUint16(data, xLen,false);
	pos += readUint16(data, yLen,false);
	pos += readUint16(data, cellWidth,false);
	pos += readUint16(data, cellHeight,false);
	uint16 temp;
	pos += readUint16(data, temp,false);
	pos += readUint16(data, temp,false);
	int vecsize=0;
	pos += readInt(data,vecsize,false);
	searchPath->InitializationMap(xLen, yLen);
	maskArray =new std::vector<unsigned char>();
	for (int i=0;i<vecsize;i++)
	{
		unsigned char uc;
		readUChar(data,uc);
		maskArray->push_back(uc);
		if ((*maskArray)[i]==(unsigned char)1)
		{
			searchPath->SetBlock(i/yLen, i%yLen, false);
		}
	}
	pos += readInt(data,vecsize,false);
	aphaVec =new std::vector<unsigned char>();
	for (int i=0;i<vecsize;i++)
	{
		unsigned char uc;
		readUChar(data,uc);
		aphaVec->push_back(uc);
		if (uc==(unsigned char) 0)
		{
			int x=i/yLen;
			int y=i%yLen;
			int i=0;
		}
	}
	
	CC_SAFE_DELETE(fileData);
}

std::vector<tPoint> Tmx2MapData::getPathList(tPoint start, tPoint end, int distance/* =0 */)
{
	if (!searchPath)
	{
		std::vector<tPoint> pathList;
		return pathList;
	}
	std::vector<tPoint> pathList = searchPath->SearchBlock(start.x, start.y, end.x, end.y);
	int _local10 = 0;
	while (_local10 < distance)
	{
		if (pathList.size() > 0)
		{
			pathList.pop_back();
		};
		_local10++;
	}
	if (pathList.size() == 0)
	{
		return pathList;
	}
	pathList.erase(pathList.begin());
	return pathList;
}

BOOL Tmx2MapData::writeData(char * urlwrite)
{
	return TRUE;
}


bool Tmx2MapData::nodeIsAlpha(int x, int y)
{
	if (aphaVec)
	{
		int flag = (*aphaVec)[(yLen*x)+y];
		return ((flag == 0));
	}
	else
	{
		return 0;
	}
}
bool Tmx2MapData::nodeIsWalk(int x, int y)
{
	int flag = getMapNodeFlag(x, y);
	return (!((flag == 1)));
}

int Tmx2MapData::getMapNodeFlag(int x, int y)
{
	if (maskArray)
	{
		return ((*maskArray)[(xLen*y)+x]);
	}
	return (0);
}
bool Tmx2MapData::canReach(tPoint start, tPoint end, int distance, bool flag/* =true */)
{
	int dx = abs(start.x-end.x);
	int dy = abs(start.y-end.y);
	if (dx<=distance && dy<=distance)
	{
		if (flag)
		{
			std::vector<tPoint> pathList = getPathBetweenTwoPoint(start, end);
			std::vector<tPoint>::iterator itr = pathList.begin();
			while (itr!=pathList.end())
			{
				if (!nodeIsWalk((*itr).x, (*itr).y))
				{
					return false;
				}
				++itr;
			}
		}
		return true;
	}
	return false;
}
std::vector<tPoint> Tmx2MapData::getPathBetweenTwoPoint(tPoint start, tPoint end)
{
	int dx = start.x-end.x;
	int dy = start.y-end.y;
	std::vector<tPoint> pathList;
	int sx = start.x;
	int sy = start.y;
	while (!(sx==end.x)||!(sy==end.y))
	{
		if (sx!=end.x)
		{
			if (dx<0)
			{
				sx++;
			}
			else if (dx>0)
			{
				sx--;
			}
		}
		if (sy!=end.y)
		{
			if (dy<0)
			{
				sy++;
			}
			else if (dy>0)
			{
				sy--;
			}
		}
		tPoint tp;
		tp.x = sx;
		tp.y = sy;
		pathList.push_back(tp);
	}
	return pathList;
}
CCPoint Tmx2MapData::getNearPointCanWalk(int rolex,int roley,int x, int y)
{
	int tx = rolex;
	int ty = roley;
	int maxDist = 10;
	int _local3 = x;
	int _local4 = y;
	int _local5 = (_local3 - tx);
	int _local6 = (_local4 - ty);
	bool _local7 = (_local5 == abs(_local5));
	bool _local8 = (_local6 == abs(_local6));
	int _local9 = x;
	int _local10 = y;
	int _local11 = (_local9 - tx);
	int _local12 = (_local10 - ty);
	int _local13 = y;
	int _local14 = x;
	int _local15 = y;
	int _local16 = (_local14 - tx);
	int _local17 = (_local15 - ty);
	int _local18 = y;
	int _local19 = (((abs(_local5) > abs(_local6))) ? abs(_local5) : abs(_local6));
	int _local20 = 0;
	while (_local20 < _local19)
	{
		if (_local5 != 0)
		{
			if (_local7 == false)
			{
				_local3 = (_local3 + 1);
				_local5 = (_local5 + 1);
			}
			else
			{
				_local3--;
				_local5--;
			};
		};
		if (_local6 != 0)
		{
			if (_local8 == false)
			{
				_local4 = (_local4 + 1);
				_local6 = (_local6 + 1);
			}
			else
			{
				_local4--;
				_local6--;
			};
		};
		if (((((nodeIsWalk(_local3, _local4)) && (!((_local3 == tx))))) && (!((_local4 == ty)))))
		{
			return ccp(_local3,_local4);
		};
		_local20++;
	};
	int _local21 = 0;
	while (_local21 < maxDist)
	{
		if (abs(_local12) != _local12)
		{
			_local10 = (_local10 + 1);
		}
		else
		{
			_local10--;
		};
		if (((((nodeIsWalk(_local9, _local10)) && (!((_local9 == tx))))) && (!((_local10 == ty)))))
		{
			return ccp(_local9,_local10);
		};
		_local21++;
	};
	int _local22 = 0;
	while (_local22 < maxDist)
	{
		if (abs(_local11) != _local11)
		{
			_local9 = (_local9 + 1);
		}
		else
		{
			_local9--;
		};
		if (nodeIsWalk(_local9, _local13))
		{
			return ccp(_local9,_local13);
		};
		_local22++;
	};
	int _local23 = 0;
	while (_local23 < maxDist)
	{
		if (abs(_local17) != _local17)
		{
			_local15--;
		}
		else
		{
			_local15 = (_local15 + 1);
		};
		if (nodeIsWalk(_local14, _local15))
		{
			return ccp(_local14,_local15);
		};
		_local23++;
	};
	int _local24 = 0;
	while (_local24 < maxDist)
	{
		if (abs(_local16) != _local16)
		{
			_local14--;
		}
		else
		{
			_local14 = (_local14 + 1);
		};
		if (nodeIsWalk(_local14, _local18))
		{
			return ccp(_local14,_local18);
		};
		_local24++;
	};
	return ccp(tx,ty);
}