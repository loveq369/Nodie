
#include "SearchPath.h"
#include <stdlib.h>

// ����Ѱ·��Χ��͸�
#define WIDTH	3000
#define HEIGHT	3000

// ���Ѱ·����
#define STEP_LIMIT WIDTH * HEIGHT

//Ѱ·ʱ���õ�·����Ϣ 
struct NODE_SHARED   
{
	unsigned char *buf_ptr;			// ָ�� node_list �еĽڵ�
	unsigned char dire;				// ָʾ����
	NODE_SHARED *last_node_ptr;		// ��һ���ڵ��¼
};

// Ѱ·�ڵ����飬���������� 0 �ɴ�ڵ�
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

// ������������ڴ�
void CDGAME3DSearchPath::UnLoadScene()
{
	if (m_bHeightDataCanReach)
	{
		delete[] m_bHeightDataCanReach;
		m_bHeightDataCanReach = NULL;
	}
}

/*==========================================================
* Description	: Ѱ·�����㷨����
* Return	    : Ѱ·���ɽڵ�����
* Parament		: block_buf - �ڵ� buffer
				: width height - Ѱ·��Χ���
				: sx sy - Ѱ·��ʼ������
				: tx ty - Ѱ·��ֹ������
				: research - �Ƿ���������
*==========================================================*/
CDGAME3DSearchPath::PATH_LINK *CDGAME3DSearchPath::_SearchPath( unsigned char *block_buf, int width, int height, int sx, int sy, int dx, int dy, bool research )
{
	if ( NULL == block_buf ) return NULL;

	// tx, ty �п���Ϊ���򳬳�Ѱ·���޴�С�����̫Զ��������ֵ��ӦΪ�߽�
	if ( dx < 0 ) dx = 0;
	if ( dy < 0 ) dy = 0;
	if ( dx >= width ) dx = width - 1;
	if ( dy >= height ) dy = height - 1;

	// ����ԭʼ��ͼ����Ϊ������������
	//memcpy(m_pRawBlock, block_buf, width * height);

	// ����ÿ�������ƫ����
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
	// �ָ�����ĵ�ͼ����
	//memcpy(block_buf, m_pRawBlock, width * height);

	unsigned int node_count   = 0;
	unsigned int current_node = 0;

	unsigned char *target_ptr = block_buf + dy * width + dx;

	// ���ó�ʼ�Ŀ�ʼѰ·�� buffer �� node_list ��һ��Ԫ��
	node_list[0].buf_ptr       = block_buf + sy * width + sx;
	node_list[0].last_node_ptr = NULL;

	unsigned char *last_buf_ptr, *new_buf_ptr;

	PATH_LINK *path_link_ptr = NULL;
	bool found_flag = false;

	long lMaxStep = (width - 1) * (height - 1);
 
	// ���������
	if ( lMaxStep > STEP_LIMIT ) lMaxStep = STEP_LIMIT;

	bool bNeedRestore = false;
	if( ((*( block_buf + dy * width + dx ))&0xC0) == 0 )
	{
		while ( !found_flag )
		{
			// �����ڵ�����������
			if ( node_count > lMaxStep ) break;
			if ( current_node > node_count ) break;
			
			// һ���ڵ�һ���ڵ㴦�������ؼ�����ָ�� last_buf_ptr��current_node ��ÿһ�� 0 �ɴ�ڵ�ÿ�������е�����
			last_buf_ptr = node_list[current_node].buf_ptr;

			// ���ýڵ�� 8 �����򶼲���һ��
			for ( int d = 0 ; d < 8 ; d++ )
			{	 
				new_buf_ptr = last_buf_ptr + off[d];

				// by rongjie ����Դ�����ж����ҡ����±߽�Ĵ����������
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

				// ֻ������ڵ�ɴ�Ž���
				//if ( *new_buf_ptr == 0 )
				if( ((*new_buf_ptr) & 0xC0) == 0 )
				{
					// ������ڵ���Ϊ 1 ���ɴ��ֹ֮���ٱ������
					(*new_buf_ptr) |= 0x40;
					bNeedRestore = true;
					node_count ++;
					// ��¼����ڵ�����ڹؼ��ڵ����Ϣ����������
					node_list[node_count].buf_ptr       = new_buf_ptr;
					node_list[node_count].dire          = d;
					node_list[node_count].last_node_ptr = &node_list[current_node];

					// ����Ŀ��ڵ�
					if ( new_buf_ptr == target_ptr )
					{   
						// �����Ľڵ㷴���� last_node_ptr һ�����ҵ�����Ľڵ�
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
	// �ָ�
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
	else if ( research ) // ���û���ҵ���Ŀ�ĵ�������㿿£����������
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

// ɾ��Ѱ·����
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
	// Ѱ·����Ѱ�ķ�Χ�� WIDTH �ף� HEIGHT ��
	PATH_LINK *p = _SearchPath( m_bHeightDataCanReach, width, height, start_x, start_z,
		end_x , end_z , true );

	m_vecPathRet.clear();
	// ���û��·���򷴻�
	if ( !p ) return m_vecPathRet;
	// �任���������꣬�����µ��������� start_z ����Ϊ������������Ϊ��ά�����z ����Ϊ��������Ϊ��
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
