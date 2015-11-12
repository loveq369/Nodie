#pragma once
#include "cocos2d.h"
#include "util/ReadUtil.h"
#include "GameDefine.h"

class TaskTarget
{
public:
	int				m_objsID;					//Ŀ��ID
	int				m_objsCount;				//Ŀ�����
	std::string		m_objsName;					//Ŀ������
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
	int				m_isactivity;				//�Ƿ�����
	int				m_level;					//�ڼ�������
	int				mWX_MAXLevel;					//��󼶱�
	int				mWX_MINLevel;					//��С����
	int				m_ramus;					//��֧��
	std::string		m_titlett;					//��Ӧ�أͣ���tt����
	int				m_usemoney;					//���ý�Ǯ
	std::string		m_titledt;					//��Ӧ�أͣ���dt����
	int				m_ot_a;						//��ϸ����
	std::string		m_ot_q;						//��ϸ����
	int				m_et_a;						//��ϸ����,ֻ�õ�ET
	std::string		m_et_q;						//��ϸ����,ֻ�õ�ET
	int				m_it_a;						//��ϸ����
	std::string		m_it_q;						//��ϸ����
	int				m_goods_id;					//��Ʒ�ɣ�
	int				m_goods_num;				//��Ʒ����
	int				m_exp_num;					//�������
	int				m_money_num;				//Ǯ����
	int				m_money_type;				//Ǯ����
	std::string     m_detail;					//��ϸ����
	int				m_anwserNPC;				//ѯ��NPC��ID
	int				m_completeNPC;				//����NPC��ID
	std::string		m_track_tar;				//׷��Ŀ��
	std::string		m_track_comp;				//δ֪
	int				m_otype;					//δ֪
	std::vector<TaskTarget> m_target;//����Ŀ���
	std::string		m_strFileName;
	int             m_nextTask;
	int             m_taskId;
};

