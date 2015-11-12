#pragma once
#include "cocos2d.h"
#include "util/ReadUtil.h"
#include "GameDefine.h"

class TaskTarget
{
public:
	int				m_objsID;					//目标ID
	int				m_objsCount;				//目标个数
	std::string		m_objsName;					//目标名字
	void encode(unsigned char*& data, unsigned long& pos)
	{
		pos += readInt(data, m_objsID);
		pos += readInt(data, m_objsCount);
		pos += readString(data, m_objsName);
	}
};
class TaskDetail
{
public:
	TaskDetail(void);
	~TaskDetail(void);

public:
	void SetFileName( std::string file  );
	bool ReadXmlFile( std::string strFile);
	bool ReadFile( std::string strFile );
	void readData(unsigned char* data, unsigned long dataLen);
public:
	int				m_isactivity;				//是否活动任务
	int				m_level;					//第几级任务
	int				mWX_MAXLevel;					//最大级别
	int				mWX_MINLevel;					//最小级别
	int				m_ramus;					//主支线
	std::string		m_titlett;					//对应ＸＭＬ中tt标题
	int				m_usemoney;					//适用金钱
	std::string		m_titledt;					//对应ＸＭＬ中dt标题
	int				m_ot_a;						//详细描述
	std::string		m_ot_q;						//详细描述
	int				m_et_a;						//详细描述,只用到ET
	std::string		m_et_q;						//详细描述,只用到ET
	int				m_it_a;						//详细描述
	std::string		m_it_q;						//详细描述
	int				m_goods_id;					//奖品ＩＤ
	int				m_goods_num;				//奖品个数
	int				m_exp_num;					//经验个数
	int				m_money_num;				//钱个数
	int				m_money_type;				//钱类型
	std::string     m_detail;					//详细描述
	int				m_anwserNPC;				//询问NPC的ID
	int				m_completeNPC;				//结束NPC的ID
	std::string		m_track_tar;				//追踪目标
	std::string		m_track_comp;				//未知
	int				m_otype;					//未知
	std::vector<TaskTarget> m_target;//任务目标怪
	std::string		m_strFileName;
	int             m_nextTask;
	int             m_taskId;
};

