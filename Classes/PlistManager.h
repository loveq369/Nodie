#pragma once

#include "MacrosDefine.h"

class UIPlistFrame
{
public:
	cocos2d::CCRect m_frame;//��ͼ����
	cocos2d::CCPoint m_offset;//ƫ��
	bool m_rateted;//�Ƿ���ת
	cocos2d::CCSize m_sourceSize;//ԭʼ�ߴ�
public:
	UIPlistFrame();
	void encode(unsigned char*& data, unsigned long& pos);
};

class PlistManager
{
public:
	static PlistManager& getInstance()
	{
		static PlistManager instance;
		return instance;
	}

	void addUISpriteFrames(const char* plistPath);//���UI��spriteFrame��plistPath��plist·��
	void removeUISpirteFrames(const char* plistPath);//�Ƴ�UI��spriteFrame

private:
	PlistManager();
	PlistManager(const PlistManager&);
	PlistManager& operator=(const PlistManager&);
	~PlistManager();

private:
	std::map<std::string, std::vector<std::string> > m_mUIPlistDic;//�Ѿ������˵�ui plist
};
