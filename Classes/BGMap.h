#pragma once

#include "MacrosDefine.h"


class BGMap:public cocos2d::CCNode
{
public:
	BGMap();
	BGMap(const BGMap&);
	BGMap& operator=(const BGMap&);
	virtual ~BGMap();

	void build(cocos2d::CCSize& mapSize, cocos2d::CCSize& sliceSize, char* mapPath);//��ʼ��������ͼ��mapSize����ͼ��С��sliceSize���п��С��mapPath����ͼ��Դ·����
	void firstLoad(cocos2d::CCRect& rect);//�״ν��볡�����ص�ͼ�����������ػص���������������ص���
	void load(cocos2d::CCRect& rect);//���ӷ�Χ�����仯���������ص�ͼ
	bool addUrgencyBg(int num=2);//��������ͼƬ������ֵ���Ƿ���Ҫ�������أ�
	bool addBackgroundBg();//��̨����ͼƬ������ֵ���Ƿ���Ҫ��̨���أ�
	void clearAll();//�Ƴ�����ͼƬ
	void setTarget(cocos2d::CCNode* target, SEL_CallFuncI startLoadFunc, SEL_CallFuncI loadingFunc, cocos2d::SEL_CallFunc stopLoadFunc);//�����������ػص�����

	CC_SYNTHESIZE_READONLY(int, m_totalNum, TotalNum);//������Ҫ���ص�ͼƬ��Ŀ
	CC_SYNTHESIZE_READONLY(int, m_currentNum, CurrentNum);//��ǰ�����˵�ͼƬ��Ŀ
	CREATE_FUNC(BGMap);
private:
	void loadTextureCallback(cocos2d::Texture2D* texture);//�״μ���ͼƬ�ص�
	void bgLoadTextureCallback(cocos2d::Texture2D* texture);//��̨����ͼƬ�ص�
private:
	std::map<std::string, cocos2d::CCSprite*> m_bg;//���б���tileͼƬ
	std::map<std::string, cocos2d::CCPoint> m_posDic;//ͼƬ��λ����Ϣ
	std::map<std::string, char> m_visibleFileNameDic;//��ǰ��ʾ��ͼƬ����
	std::map<std::string, char> m_unvisibleFileNameDic;//��ǰ����ʾ��ͼƬ����
	std::vector<std::string> m_urgencyWaitLoad;//��Ҫ�������ص�
	std::vector<std::string> m_backgroundWaitLoad;//��̨���ص�
	int m_width;//����ͼ��
	int m_height;//����ͼ��
	int m_sliceWidth;//����tile��
	int m_sliceHeight;//����tile��
	std::string m_folder;//����ͼ����Ŀ¼

	cocos2d::CCNode* m_target;//�ص�����
	SEL_CallFuncI m_loadingFunc;//���ڼ��ػص�������int������������ͼƬ��Ŀ��
	SEL_CallFuncI m_startLoadFunc;//��ʼ���ػص�������int����������Ҫ����ͼƬ��Ŀ��
	cocos2d::SEL_CallFunc m_stopLoadFunc;//ֹͣ���ػص�
};
