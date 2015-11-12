#pragma once

#include "cocos2d.h"
#define DEFAULT_ANIMATE_NAME "default"

struct InfoIndex//��¼���������Ϣ����
{
	short m_picIndex;//�ö���ͼƬ·������
	short m_posIndex;//�ö�����ͼ��������
};

//һ����Ƭ��Ϣ
class PlistFrame
{
public:
	cocos2d::CCRect m_frame;//��ͼ����
	cocos2d::CCPoint m_offset;//ƫ��
	bool m_rateted;//�Ƿ���ת
public:
	PlistFrame(){};
	PlistFrame(cocos2d::CCRect frame,cocos2d::CCPoint offset,bool rateted);
	void encode(unsigned char*& data, unsigned long& pos);
};

//һ��ͼƬ�����е�plist��Ϣ
class ItemPlistData
{
public:
	std::string m_picFilename;//ͼƬ����
	std::vector<PlistFrame> m_plistFrameList;//��ͼƬ���е�plist��Ϣ
public:
	ItemPlistData(){};
	ItemPlistData(std::string picFilename);
	void pushBack(PlistFrame listFrame);
	void encode(unsigned char*& data, unsigned long& pos);
};

//һ������
class ItemAnimateData
{
public:
	float m_delay;//����֡���
	bool m_flipX;//�Ƿ�תx
	bool m_flipY;//�Ƿ�תy
	std::vector<InfoIndex> m_infoIndexList;//�ö����ļ�����֡�õ�������������Ϣ
	int m_refernceTimes;//�ö���ʹ�ô���
public:
	ItemAnimateData(){};
	ItemAnimateData(float delay,bool flipX,bool flipY,int refrernceTimes);
	void pushBack(InfoIndex infoIndex);
	void encode(unsigned char*& data, unsigned long& pos);
};

//һ�������ļ������ж�����Ϣ���������plist��Ϣ
class ObjectAllAnimations
{
public:
	std::map<std::string, ItemAnimateData> allAnimations;//���ж�����Ϣ
	std::vector<ItemPlistData> infoPlistList;//�ö����ļ��õ�������plist��Ϣ
public:
	void pushBackItemAnimateData(std::pair<std::string, ItemAnimateData> pairAniData);
	void pushBackItemPlistData(ItemPlistData itemPlistData);
	void encode(unsigned char*& data, unsigned long& pos);
	void writeToFile(char* file);
};

//��������
class AnimateManager
{
public:
	static AnimateManager& getInstance()
	{
		static AnimateManager instance;
		return instance;
	}
	void parseXML(const char *fileName);
	//����һ�������ļ�
	void parseObject(const char* filename);
	//�����ļ�����ȡ�����ļ��������ݣ���������ڣ����Զ�ȡ��
	ObjectAllAnimations* getObjectAnimationsByFilename(const char* filename);
	//��ȡanimateName�����ĵ�һ֡�߶�
	int getFrameHeight(const char* filename, const char* animateName);
	//���ݶ�������ȡ��һ֡spriteFrame������´�������������CCSpriteFrameCache
	cocos2d::CCSpriteFrame* getFirstSpriteFrame(const char* filename, const char* animateName, bool& isFlipX);

	//���ݶ�������ȡ����
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc);
	//���ݶ�������ȡ�������ɴ����ӳ٣�xy��ת�����delay<0����AnimateData���֡�����
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, float delay, bool flipX, bool flipY);
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, float delay);
	cocos2d::CCSequence* getSequence(const char* filename, const char* animateName, cocos2d::CCCallFunc* callFunc, bool flipX);

	//��������
	cocos2d::CCSequence* createSequence(cocos2d::CCArray* actions);
	//��������
	cocos2d::CCSequence* createSequence(cocos2d::CCAnimation* animation, cocos2d::CCCallFunc* callFunc, float delay, bool flipX, bool flipY);

	//���ݶ�������ȡanimation
	cocos2d::CCAnimation* getAnimation(const char* filename, const char* animateName, ItemAnimateData*& animateData);
	//ĳ��node�����øö����ˣ�����Ѿ�û��nodeʹ�øö�����ʩ��ͼƬ�ڴ�
	void releaseSequence(const char* animateName);

	CC_SYNTHESIZE(std::string, m_resFolderStr, ResFolderStr);//��Դ�ļ���·��
	CC_SYNTHESIZE(std::string, m_resTypeStr, ResTypeStr);//��Դ�ļ���׺

private:
	AnimateManager();
	AnimateManager(const AnimateManager&);
	AnimateManager& operator=(const AnimateManager&);
	~AnimateManager();
	//����һ�������ļ�
	ObjectAllAnimations* __parseObject(const char* filename);
private:
	std::map<std::string, ObjectAllAnimations*> m_animDataDic;//���ж����ļ���key�������ļ��ļ�����value���ö����ļ��������ж���
};
