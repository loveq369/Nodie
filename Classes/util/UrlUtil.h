#pragma once

#include <string>

//////////////////////////////////////////////////////////////////////////
//获取可用的一个路径
std::string getWritablePath();
//检查一下文件夹路径，如果不存在就创建
void checkFolderPath( const char* folderPath );


//获取地图寻路数据
std::string getMapDataUrl(int mapSourceId);



//获取头像
const char* getPlayerHeadImgUrl(int classes, int gender);
//获取目标头像
const char* getTargetHeadImgUrl(int entity_type, int npc_type);