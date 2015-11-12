#include "UrlUtil.h"
#include "DataManager.h"
#include "../GameDefine.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#endif
#define _MAX_PATH_ 260
//////////////////////////////////////////////////////////////////////////
std::string getWritablePath()
{
	std::string writablePath = "";
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	writablePath = "/mnt/sdcard/";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	char full_path[_MAX_PATH + 1];
	::GetModuleFileNameA(NULL, full_path, _MAX_PATH + 1);
	writablePath = (char*)full_path;
	writablePath =  writablePath.substr(0, writablePath.rfind("\\") + 1);
#else
	writablePath = CCFileUtils::sharedFileUtils()->getWritablePath();
#endif
	return writablePath;
}

void checkFolderPath( const char* folderPath )
{
	//文件夹不存在，创建
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	DIR *pDir = NULL;

	pDir = opendir (folderPath);
	if (! pDir)
	{
		mkdir(folderPath, S_IRWXU | S_IRWXG | S_IRWXO);
	}
#else
	if ((GetFileAttributesA(folderPath)) == INVALID_FILE_ATTRIBUTES)
	{
		CreateDirectoryA(folderPath, 0);
	}
#endif
}

std::string getMapDataUrl(int mapSourceId)
{
	char mapFileNameStr[_MAX_PATH_];
	memset(mapFileNameStr, 0, sizeof(mapFileNameStr));
	sprintf(mapFileNameStr, "map/mapData/s%d.mapData", mapSourceId);

	return mapFileNameStr;
}



const char* getPlayerHeadImgUrl( int classes, int gender )
{
	switch (classes)
	{
	case CLASS_MELEE:
		{
			if (gender==1)
			{
				return "headImg/player/nanwu.png";
			}
			return "headImg/player/nvwu.png";
		}
		break;
	case CLASS_RANGE:
		{
			if (gender==1)
			{
				return "headImg/player/nangong.png";
			}
			return "headImg/player/nvgong.png";
		}
		break;
	case CLASS_MAGIC:
		{
			if (gender==1)
			{
				return "headImg/player/nanmo.png";
			}
			return "headImg/player/nvmo.png";
		}
		break;
	}
	return "";
}

const char* getTargetHeadImgUrl( int entity_type, int npc_type )
{
	switch (entity_type)
	{
	case ENTITY_TYPE_NPC:
		{
			switch (npc_type)
			{
			case NPC_TYPE_FUN:// 功能性npc 目前不分男女
				return "headImg/npcman.png";
			case NPC_TYPE_MONSTER:
				return "headImg/monster.png";
			case NPC_BOSS_TYPE:
				return "headImg/BOSS.png";
			}
		}
		break;
	}
	return "";
}
