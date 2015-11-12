#include "TaskDetail.h"
#include "tinyxml2/tinyxml2.h"
USING_NS_CC;

#define			TASK_FILE_SBU_NAME		".tsk"
#define			MAX_TASK_SIZE			1024

TaskDetail::TaskDetail(void)
{
	m_isactivity = 0;				
	m_level = 0;					
	mWX_MAXLevel = 0;					
	mWX_MINLevel = 0;					
	m_ramus = 0;					
	m_titlett = "";					
	m_usemoney = 0;					
	m_titledt = "";					
	m_ot_a = 0;						
	m_ot_q  = "";						
	m_et_a = 0;						
	m_et_q  = "";						
	m_it_a = 0;						
	m_it_q  = "";						
	m_goods_id = 0;					
	m_goods_num = 0;				
	m_exp_num = 0;					
	m_money_num = 0;				
	m_money_type = 0;				
	m_detail  = "";					
	m_anwserNPC = 0;				
	m_completeNPC = 0;				
	m_track_tar = "";				
	m_track_comp  = "";				
	m_otype = 0;	
	m_taskId = 0;
}
TaskDetail::~TaskDetail(void)
{
}
void TaskDetail::SetFileName( std::string file  )
{
	m_strFileName = file;

	int iFind = m_strFileName.rfind(".");
	m_strFileName = m_strFileName.substr(0,iFind);
	m_strFileName+=TASK_FILE_SBU_NAME;
}
void TaskDetail::readData(unsigned char* data, unsigned long dataLen)
{
	unsigned long pos = 0;
	while (pos<(dataLen-1))
	{
		pos += readInt(data, m_isactivity);
		pos += readInt(data, m_level);
		pos += readInt(data, mWX_MAXLevel);
		pos += readInt(data, mWX_MINLevel);
		pos += readInt(data, m_ramus);
		pos += readString(data, m_titlett);
		pos += readInt(data, m_usemoney);
		pos += readString(data, m_titledt);
		pos += readInt(data, m_ot_a);
		pos += readString(data, m_ot_q);
		pos += readInt(data, m_et_a);
		pos += readString(data, m_et_q);
		pos += readInt(data, m_it_a);
		pos += readString(data, m_it_q);
		pos += readInt(data, m_goods_id);
		pos += readInt(data, m_goods_num);
		pos += readInt(data, m_exp_num);
		pos += readInt(data, m_money_num);
		pos += readInt(data, m_money_type);
		pos += readString(data, m_detail);
		pos += readInt(data, m_anwserNPC);
		pos += readInt(data, m_completeNPC);
		int len = 0;
		pos += readInt(data, len);
		for (int i=0;i<len;i++)
		{
			TaskTarget ttarget;
			ttarget.encode(data, pos);
			m_target.push_back(ttarget);
		}
		pos += readString(data, m_track_tar);
		pos += readString(data, m_track_comp);
		pos += readInt(data, m_otype);	
	}
}


bool TaskDetail::ReadXmlFile( std::string strFile)
{
	std::string filePath=CCFileUtils::sharedFileUtils()->fullPathForFilename(strFile);
	//std::string filePath = FileUtils::getInstance()->getWritablePath() + fileName;
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	tinyxml2::XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml¸ñÊ½´íÎó
		return false;
	}
	tinyxml2::XMLElement *rootEle = pDoc->RootElement();
	tinyxml2::XMLElement * taskid = rootEle->FirstChildElement("taskid");
	std::string strtaskid=taskid->GetText();
	m_taskId=std::atoi(strtaskid.c_str());
	tinyxml2::XMLElement * isactivity = rootEle->FirstChildElement("isactivity");
	std::string strIsactivity=isactivity->GetText();
	m_isactivity=std::atoi(strIsactivity.c_str())==1;
	tinyxml2::XMLElement * level = rootEle->FirstChildElement("level");
	std::string strLevel=level->GetText();
	m_level=std::atoi(strLevel.c_str());
	
	tinyxml2::XMLElement * WX_MAXLevel = rootEle->FirstChildElement("WX_MAXLevel");
	std::string strWX_MAXLevel=WX_MAXLevel->GetText();
	mWX_MAXLevel=std::atoi(strWX_MAXLevel.c_str());
	tinyxml2::XMLElement * WX_MINLevel = rootEle->FirstChildElement("WX_MINLevel");
	std::string strWX_MINLevel=WX_MINLevel->GetText();
	mWX_MINLevel=std::atoi(strWX_MINLevel.c_str());
	tinyxml2::XMLElement * ramus = rootEle->FirstChildElement("ramus");
	std::string strRamus=ramus->GetText();
	m_ramus=std::atoi(strRamus.c_str());
	tinyxml2::XMLElement * titlett = rootEle->FirstChildElement("titlett");
	m_titlett=titlett->GetText();
	tinyxml2::XMLElement * usemoney = rootEle->FirstChildElement("usemoney");
	std::string strUsemoney=usemoney->GetText();
	m_usemoney=std::atoi(strUsemoney.c_str());
	tinyxml2::XMLElement * titledt = rootEle->FirstChildElement("titledt");
	m_titledt=titledt->GetText();
	tinyxml2::XMLElement * ot_a = rootEle->FirstChildElement("ot_a");
	std::string strOt_a=ot_a->GetText();
	m_ot_a=std::atoi(strOt_a.c_str());
	tinyxml2::XMLElement * ot_q = rootEle->FirstChildElement("ot_q");
	m_ot_q=ot_q->GetText();
	tinyxml2::XMLElement * et_a = rootEle->FirstChildElement("et_a");
	std::string strEt_a=et_a->GetText();
	m_et_a=std::atoi(strEt_a.c_str());
	tinyxml2::XMLElement * et_q = rootEle->FirstChildElement("et_q");
	m_et_q=et_q->GetText();
	tinyxml2::XMLElement * it_a = rootEle->FirstChildElement("it_a");
	std::string strIt_a=it_a->GetText();
	m_it_a=std::atoi(strIt_a.c_str());
	tinyxml2::XMLElement * it_q = rootEle->FirstChildElement("it_q");
	m_it_q=it_q->GetText();
	tinyxml2::XMLElement * goods_id = rootEle->FirstChildElement("goods_id");
	std::string strGoods_id=goods_id->GetText();
	m_goods_id=std::atoi(strGoods_id.c_str());
	tinyxml2::XMLElement * goods_num = rootEle->FirstChildElement("goods_num");
	std::string strGoods_num=goods_num->GetText();
	m_goods_num=std::atoi(strGoods_num.c_str());
	tinyxml2::XMLElement * exp_num = rootEle->FirstChildElement("exp_num");
	std::string strExp_num=exp_num->GetText();
	m_exp_num=std::atoi(strExp_num.c_str());
	tinyxml2::XMLElement * money_num = rootEle->FirstChildElement("money_num");
	std::string strMoney_num=money_num->GetText();
	m_money_num=std::atoi(strMoney_num.c_str());
	tinyxml2::XMLElement * money_type=rootEle->FirstChildElement("money_type");
	std::string strMoney_type=money_type->GetText();
	m_money_type=std::atoi(strMoney_type.c_str());
	tinyxml2::XMLElement * detail=rootEle->FirstChildElement("detail");
	m_detail=detail->GetText();
	tinyxml2::XMLElement * anwserNPC=rootEle->FirstChildElement("anwserNPC");
	std::string strAnwserNPC=anwserNPC->GetText();
	m_anwserNPC=std::atoi(strAnwserNPC.c_str());
	tinyxml2::XMLElement * completeNPC=rootEle->FirstChildElement("completeNPC");
	std::string strCompleteNPC=completeNPC->GetText();
	m_completeNPC=std::atoi(strCompleteNPC.c_str());
	tinyxml2::XMLElement *taskTarget = rootEle->FirstChildElement("taskTarget");
	while ( taskTarget ) {
		TaskTarget taskTargetItem;
		tinyxml2::XMLElement * objsID = taskTarget->FirstChildElement("objsID");
		std::string strObjsID=objsID->GetText();
		tinyxml2::XMLElement * objsCount = taskTarget->FirstChildElement("objsCount");
		tinyxml2::XMLElement * objsName = taskTarget->FirstChildElement("objsName");
		std::string strObjsCount=objsCount->GetText();
		taskTargetItem.m_objsID=std::atoi(strObjsID.c_str());
		taskTargetItem.m_objsCount=std::atoi(strObjsCount.c_str());
		taskTargetItem.m_objsName=objsName->GetText();
		m_target.push_back(taskTargetItem);
		taskTarget = taskTarget->NextSiblingElement();
	}
	tinyxml2::XMLElement * track_tar=rootEle->FirstChildElement("track_tar");
	if (track_tar)
	{
		m_track_tar=track_tar->GetText();
	}
	tinyxml2::XMLElement * track_comp=rootEle->FirstChildElement("track_comp");
	if (track_comp)
	{
		m_track_comp=track_comp->GetText();
	}
	tinyxml2::XMLElement * otype=rootEle->FirstChildElement("otype");
	if (otype)
	{
		std::string strOtype=otype->GetText();
		m_otype=std::atoi(strOtype.c_str());
	}
	tinyxml2::XMLElement * nextTask=rootEle->FirstChildElement("nextTask");
	if (otype)
	{
		std::string m_strnextTask=nextTask->GetText();
		m_nextTask=std::atoi(m_strnextTask.c_str());
	}
	return true;
}

bool TaskDetail::ReadFile( std::string strFile )
{
	unsigned long fileLen = 0;
	unsigned char *fileData = NULL;
	do 
	{
		fileData = CCFileUtils::sharedFileUtils()->getFileData(strFile.c_str(), "rb", (ssize_t *)(&fileLen));
		CC_BREAK_IF(!fileData);
		unsigned char* temp = fileData;
		this->readData(fileData, fileLen);
		CC_SAFE_DELETE_ARRAY(temp);
	} while(0);
	return false;
}