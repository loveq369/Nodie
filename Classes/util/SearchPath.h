#pragma once

#include <vector>
#include "../util/basic_types.h"


	// Ѱ·������
class CDGAME3DSearchPath
{
public:
	struct PATH_LINK
	{
		unsigned char dire;						// �ⲽ�ķ���
		int fPosX;							// x ����
		int fPosZ;							// z ����
		PATH_LINK *next_path_ptr;				// ��һ��Ѱ·�ڵ�
	};
	std::vector< tPoint > m_vecPathRet;
private:
	unsigned char *m_pRawBlock;				// �������ݽڵ� buffer��Ϊ���ڲ�����Ѱ·ʹ��
	unsigned char *m_bHeightDataCanReach;	// ���ļ���ȡ�ĵ�ͼ�ڰ����ݣ�0/1��
	int width;// ��ͼ���
	int height;// ��ͼ�߶�

	void DeletePathLink(PATH_LINK **ppPathLink);
private:
	CDGAME3DSearchPath::PATH_LINK * _SearchPath( unsigned char *block_buf, int width, int height, int sx, int sy, int dx, int dy, bool research = false );
public:
	CDGAME3DSearchPath();
	~CDGAME3DSearchPath();

	void UnLoadScene();
	// �����Ƿ�ɴ��Ĭ�������ֻ��0Ϊ�ɴ��0Ϊ���ɴ�������÷�0��ID�Ƿ�ɴ0��������
	void SetCanReach( bool bCan , unsigned char nID );
	void RestoreCanReachToDefault();

	void InitializationMap( int mapWidth , int mapHeight );//��ʼ����ͼ
	void SetBlock( int x , int y , bool bCan );//����x,yλ���Ƿ��赲
	const std::vector< tPoint > &SearchBlock( int start_x, int start_z, int end_x, int end_z );
};