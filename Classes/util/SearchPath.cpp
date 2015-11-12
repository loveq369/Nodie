
#include "SearchPath.h"
#include <stdlib.h>

// 定义寻路范围宽和高
#define WIDTH	3000
#define HEIGHT	3000

// 最大寻路步数
#define STEP_LIMIT WIDTH * HEIGHT

//寻路时公用的路径信息 
struct NODE_SHARED   
{
	unsigned char *buf_ptr;			// 指向 node_list 中的节点
	unsigned char dire;				// 指示方向
	NODE_SHARED *last_node_ptr;		// 上一个节点记录
};

// 寻路节点数组，保存了所有 0 可达节点
NODE_SHARED node_list[STEP_LIMIT];

// *** CDGAME3DSearchPath

CDGAME3DSearchPath::CDGAME3DSearchPath()
{
	m_bHeightDataCanReach = NULL;
}

CDGAME3DSearchPath::~CDGAME3DSearchPath()
{
	//delete m_pRawBlock;
	UnLoadScene();
}


void CDGAME3DSearchPath::SetCanReach( bool bCan , unsigned char nID )
{
	if( nID <= 0 || nID >= 16 )
		return;
	for ( int j = 0; j < height; j += 1 )
	{
		for ( int i = 0; i < width; i += 1 )
		{
			unsigned char t = m_bHeightDataCanReach[j * width + i];
			if( (t & 0x0F) == nID )
			{
				if( bCan )
					t &= ~0x80;
				else
					t |= 0x80;
				m_bHeightDataCanReach[j * width + i] = t;
			}
		}
	}
}
void CDGAME3DSearchPath::RestoreCanReachToDefault()
{
	for ( int j = 0; j < height; j += 1 )
	{
		for ( int i = 0; i < width; i += 1 )
		{
			unsigned char t = m_bHeightDataCanReach[j * width + i];
			if( t != 0 )
				t |= 0x80;
			m_bHeightDataCanReach[j * width + i] = t;
		}
	}
}

// 清除读入数据内存
void CDGAME3DSearchPath::UnLoadScene()
{
	if (m_bHeightDataCanReach)
	{
		delete[] m_bHeightDataCanReach;
		m_bHeightDataCanReach = NULL;
	}
}

/*==========================================================
* Description	: 寻路基础算法函数
* Return	    : 寻路生成节点链表
* Parament		: block_buf - 节点 buffer
				: width height - 寻路范围宽高
				: sx sy - 寻路开始点坐标
				: tx ty - 寻路终止点坐标
				: research - 是否重新搜索
*==========================================================*/
CDGAME3DSearchPath::PATH_LINK *CDGAME3DSearchPath::_SearchPath( unsigned char *block_buf, int width, int height, int sx, int sy, int dx, int dy, bool research )
{
	if ( NULL == block_buf ) return NULL;

	// tx, ty 有可能为负或超出寻路极限大小（点的太远），将其值适应为边界
	if ( dx < 0 ) dx = 0;
	if ( dy < 0 ) dy = 0;
	if ( dx >= width ) dx = width - 1;
	if ( dy >= height ) dy = height - 1;

	// 保存原始地图数据为了重新搜索用
	//memcpy(m_pRawBlock, block_buf, width * height);

	// 设置每个方向的偏移量
	short off[8];
	off[0] = width * (-1);
	off[1] = width;
	off[2] = -1;   
	off[3] = 1;   
	off[4] = (width - 1) * (-1);  
	off[5] = width + 1;
	off[6] = width - 1;  
	off[7] = (width + 1) * -1;

	unsigned char prior[8]; 
	prior[0] = 0;
	prior[1] = 4;
	prior[2] = 6;
	prior[3] = 2;
	prior[4] = 1; 
	prior[5] = 3;
	prior[6] = 5;
	prior[7] = 7;

RESEARCH:
	// 恢复保存的地图数据
	//memcpy(block_buf, m_pRawBlock, width * height);

	unsigned int node_count   = 0;
	unsigned int current_node = 0;

	unsigned char *target_ptr = block_buf + dy * width + dx;

	// 设置初始的开始寻路点 buffer 到 node_list 第一个元素
	node_list[0].buf_ptr       = block_buf + sy * width + sx;
	node_list[0].last_node_ptr = NULL;

	unsigned char *last_buf_ptr, *new_buf_ptr;

	PATH_LINK *path_link_ptr = NULL;
	bool found_flag = false;

	long lMaxStep = (width - 1) * (height - 1);
 
	// 限制最大步数
	if ( lMaxStep > STEP_LIMIT ) lMaxStep = STEP_LIMIT;

	bool bNeedRestore = false;
	if( ((*( block_buf + dy * width + dx ))&0xC0) == 0 )
	{
		while ( !found_flag )
		{
			// 对最大节点数进行限制
			if ( node_count > lMaxStep ) break;
			if ( current_node > node_count ) break;
			
			// 一个节点一个节点处理，交给关键处理指针 last_buf_ptr（current_node 将每一个 0 可达节点每个都进行迭带）
			last_buf_ptr = node_list[current_node].buf_ptr;

			// 将该节点的 8 个方向都查找一遍
			for ( int d = 0 ; d < 8 ; d++ )
			{	 
				new_buf_ptr = last_buf_ptr + off[d];

				// by rongjie 修正源程序中对左右、上下边界的错误继续处理
				if ( new_buf_ptr < block_buf || new_buf_ptr > block_buf + width * height)
					continue;

				if ( 0 == (last_buf_ptr - block_buf) % width )
				{
					  switch (d)
					  {
					  case 2:
					  case 6:
					  case 7:
						  continue;
					  }
				}
	  
				if ( width - 1 == (last_buf_ptr - block_buf) % width )
				{
					switch (d)
					{
					case 3:
					case 4:
					case 5:
					  continue;
					}
				}
				//////////////////////////////////////////////////////

				// 只有这个节点可达才进入
				//if ( *new_buf_ptr == 0 )
				if( ((*new_buf_ptr) & 0xC0) == 0 )
				{
					// 将这个节点设为 1 不可达，防止之后再被算进来
					(*new_buf_ptr) |= 0x40;
					bNeedRestore = true;
					node_count ++;
					// 记录这个节点相对于关键节点的信息，包括方向
					node_list[node_count].buf_ptr       = new_buf_ptr;
					node_list[node_count].dire          = d;
					node_list[node_count].last_node_ptr = &node_list[current_node];

					// 找找目标节点
					if ( new_buf_ptr == target_ptr )
					{   
						// 由最后的节点反向用 last_node_ptr 一级级找到上面的节点
						NODE_SHARED *node_ptr = &node_list[node_count];
						while ( node_ptr->last_node_ptr )   
						{
						   PATH_LINK *new_path =	new PATH_LINK;
						   new_path->dire          = prior[node_ptr->dire];
						   new_path->next_path_ptr = path_link_ptr;
						   path_link_ptr           = new_path;
						   node_ptr                = node_ptr->last_node_ptr;
						}
						found_flag = true; 
						break; 
					}	
				}
			}
			current_node ++;
		}
	}
	// 恢复
	if( bNeedRestore )
	{
		for( int i = 0 ; i < width * height ; i ++ )
		{
			block_buf[i] &= ~0x40;
		}
	}
	if ( found_flag )
	{ 
		return path_link_ptr;
	}
	else if ( research ) // 如果没有找到则将目的点向出发点靠拢，重新搜索
	{
		if ( dx - sx > 0 )
			dx --;
		else if ( dx - sx < 0 )
			dx ++;

		if ( dy - sy > 0 )
			dy --;
		else if ( dy - sy < 0 )
			dy ++;
		
		if ( dx == sx && dy == sy ) return NULL;
		goto RESEARCH;
	}

	return NULL;
}

// 删除寻路链表
void CDGAME3DSearchPath::DeletePathLink(PATH_LINK **ppPathLink)
{
	PATH_LINK *pPathLink = *ppPathLink;
	while ( pPathLink )
	{
		PATH_LINK *pNextPath = pPathLink->next_path_ptr;
		delete pPathLink;  
		pPathLink = pNextPath;
	}
	*ppPathLink = NULL;
}

void CDGAME3DSearchPath::InitializationMap( int mapWidth , int mapHeight )
{
	width = mapWidth;
	height = mapHeight;
	m_bHeightDataCanReach = new unsigned char[width * height];
	memset( m_bHeightDataCanReach , 0 , width * height );
}

void CDGAME3DSearchPath::SetBlock( int x , int y , bool bCan )
{
	m_bHeightDataCanReach[ y*width + x ] = bCan?0:0x80;
}
const std::vector< tPoint > &CDGAME3DSearchPath::SearchBlock( int start_x, int start_z, int end_x, int end_z )
{
	// 寻路，能寻的范围是 WIDTH 米， HEIGHT 米
	PATH_LINK *p = _SearchPath( m_bHeightDataCanReach, width, height, start_x, start_z,
		end_x , end_z , true );

	m_vecPathRet.clear();
	// 如果没有路，则反回
	if ( !p ) return m_vecPathRet;
	// 变换到世界坐标，生成新的链表。这里 start_z 向上为负增长，是因为三维世界里，z 向上为正，向下为负
	PATH_LINK *p2 = p;

	tPoint tp;
	tp.x = start_x;
	tp.y = start_z;
	m_vecPathRet.push_back(tp);
	while ( p2 )
	{
		switch ( p2->dire )
		{
		case 0:
			start_z -= 1;
			break;
		case 1:
			start_z -= 1;
			start_x += 1;
			break;
		case 2:
			start_x += 1;
			break;
		case 3:
			start_x += 1;
			start_z += 1;
			break;
		case 4:
			start_z += 1;
			break;
		case 5:
			start_x -= 1;
			start_z += 1;
			break;
		case 6:
			start_x -= 1;
			break;
		case 7:
			start_x -= 1;
			start_z -= 1;
			break;
		}
		p2->fPosX = start_x;
		p2->fPosZ = start_z;
		tPoint tp;
		tp.x = p2->fPosX;
		tp.y = p2->fPosZ;
		m_vecPathRet.push_back(tp);
		p2 = p2->next_path_ptr;
	}
	DeletePathLink( &p );
	return m_vecPathRet;
}
