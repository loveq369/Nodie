#pragma once

#include <string>

//////////////////////////////////////////////////////////////////////////
//��ȡ���õ�һ��·��
std::string getWritablePath();
//���һ���ļ���·������������ھʹ���
void checkFolderPath( const char* folderPath );


//��ȡ��ͼѰ·����
std::string getMapDataUrl(int mapSourceId);



//��ȡͷ��
const char* getPlayerHeadImgUrl(int classes, int gender);
//��ȡĿ��ͷ��
const char* getTargetHeadImgUrl(int entity_type, int npc_type);