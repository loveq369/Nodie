#pragma once

#include <vector>
#include "../util/basic_types.h"


	// 寻路操作类
class CDGAME3DSearchPath
{
public:
	struct PATH_LINK
	{
		unsigned char dire;						// 这步的方向
		int fPosX;							// x 坐标
		int fPosZ;							// z 坐标
		PATH_LINK *next_path_ptr;				// 下一个寻路节点
	};
	std::vector< tPoint > m_vecPathRet;
private:
	unsigned char *m_pRawBlock;				// 保存数据节点 buffer，为了内部二次寻路使用
	unsigned char *m_bHeightDataCanReach;	// 从文件读取的地图黑白数据（0/1）
	int width;// 地图宽度
	int height;// 地图高度

	void DeletePathLink(PATH_LINK **ppPathLink);
private:
	CDGAME3DSearchPath::PATH_LINK * _SearchPath( unsigned char *block_buf, int width, int height, int sx, int sy, int dx, int dy, bool research = false );
public:
	CDGAME3DSearchPath();
	~CDGAME3DSearchPath();

	void UnLoadScene();
	// 设置是否可达，在默认情况下只有0为可达，非0为不可达，可以设置非0的ID是否可达，0不可设置
	void SetCanReach( bool bCan , unsigned char nID );
	void RestoreCanReachToDefault();

	void InitializationMap( int mapWidth , int mapHeight );//初始化地图
	void SetBlock( int x , int y , bool bCan );//设置x,y位置是否阻挡
	const std::vector< tPoint > &SearchBlock( int start_x, int start_z, int end_x, int end_z );
};