#pragma once

#include "cocos2d.h"


class TextureLifecycle//������������
{
public:
	cocos2d::CCTexture2D* texture;//��Ӧ����
	long lastReferenceTime;//���һ���õ�ʱ��
	int count;//�ù��Ĵ���
};

class TextureManager: public cocos2d::CCObject
{
public:
	static TextureManager& getInstance()
	{
		static TextureManager instance;
		return instance;
	}
	void tick(float dt);//�ж��Ƿ���Ҫ����ڴ�
	cocos2d::CCTexture2D* addImage(const char* filename);//���һ��ͼƬ����ͼƬ������������������ڣ������������Զ��ͷţ��Զ��ͷţ�
	cocos2d::CCTexture2D* addStaticImage(const char* filename);//���һ��ͼƬ����ͼƬֻ�����˳���Ϸ�Ż��ͷ�
	void addStaticImageAsync(const char* filename, cocos2d::CCObject *target, cocos2d::SEL_CallFuncO selector);
	void removeStaticImage(const char* filename);//����̬ͼƬ���ڴ����Ƴ�

	CC_SYNTHESIZE(long, m_maxLifecycle, MaxLifecycle);//ÿ��ͼ������ʱ��
	CC_SYNTHESIZE(float, m_maxInterval, MaxInterval);//����ڴ�����

private:
	TextureManager();
	TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);
	~TextureManager();

	bool checkNeedRelease(TextureLifecycle& tlc);//����Ƿ���Ҫ�ͷ�
	void loadTextureCallback(cocos2d::CCTexture2D* texture);
private:
	std::map<std::string, TextureLifecycle> m_textureLifecycleDic;//�Զ��ͷŵ�
	std::map<std::string, cocos2d::CCTexture2D*> m_staticTextureDic;//��̬���ͷŵ�
	cocos2d::CCObject* m_target;//�ص�
	cocos2d::SEL_CallFuncO m_selector;//�ص�����
	float m_currInterval;//��ǰ�ڴ�����
	bool m_isTicking;//�Ƿ�����tick
};

