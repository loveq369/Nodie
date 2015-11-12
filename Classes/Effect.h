#pragma once

#include "EffectNode.h"


#define EFFECT_TYPE_GROUND	1//����
#define EFFECT_TYPE_FLY		2//����
#define EFFECT_TYPE_TARGET	3//Ŀ��

#define EFFECT_PARTICLE_TYPE_PARTICLE	1//������Ч
#define EFFECT_PARTICLE_TYPE_ANIM		2//������Ч

#define EFFECT_PART_HEAD	1//ͷ������ߣ�
#define EFFECT_PART_HEART	2//�ز������*2/3��
#define EFFECT_PART_TOP		3//��������ߣ�
#define EFFECT_PART_BUTTOM	4//�ײ���0��
#define EFFECT_PART_HAND	5//�ֲ������*1/2��
#define EFFECT_PART_LEG		6//�Ȳ������*1/3��

class EffectConfigData
{
public:
	std::string m_effectName;//��Ч����
	std::string m_particleName;//���õ����Ч�����֣�����Ƕ��������Ƕ���������������Ӿ�����������
	int8 m_particleType;//��Ч���ͣ����ӡ�������
	float m_startTime;//��ʼ����ʱ��
	float m_duration;//����ʱ��
public:
	void encode(unsigned char*& data, unsigned long& pos);
};

class EffectInfo//��ǰ��Ч��Ϣ
{
public:
	cocos2d::CCPoint m_startPixelPos;//��Ч��ʼ������λ��
	cocos2d::CCPoint m_endPixelPos;//��Ч����������λ��
	tPoint m_startTileCoord;//��Ч��ʼ��tileλ��
	tPoint m_endTileCoord;//��Ч������tileλ��
	int m_flySpeed;//�ٶ�
	bool m_isFlyRepeat;//������Ч�Ƿ��ظ�
	int8 m_type;//��Ч����Ŀ������
	int8 m_part;//���е�
	int m_zorder;//��Ⱦ��zorder
	cocos2d::CCSize m_ownerSize;//��Ч���𷽴�С
	cocos2d::CCSize m_targetSize;//Ŀ�굥λ��С
	EffectNode* m_effectParent;//��Ч�ҽӵ�
	EffectConfigData m_configData;//��������
public:
	EffectInfo()
	{
		m_isFlyRepeat = false;
		m_zorder = 65535;
		m_ownerSize.width = 0.0f;
		m_ownerSize.height = 0.0f;
		m_targetSize.width = 0.0f;
		m_targetSize.height = 0.0f;
	}
};

class Effect: public cocos2d::CCObject
{
public:
	Effect(void);
	~Effect(void);

	void tick(float dt);//tick��Ч�����Ʋ��ź�ֹͣ��
	void init();//��ʼ��������Ч/������Ч
	void clear();//�ͷ�������Ч/������Ч
	bool isDead();//��Ч�Ƿ񲥷Ž���
	void stop();//ֹͣ��Ч����
	void removeParticle();//��Ŀ�������Ƴ���Ч
	void addParticle();//��Ŀ�������Ч
	void reset();//����һЩ����
	void setFlySpeed(int flySpeed);//���÷�����Ч�ٶ�
	void setPart(int8 part);//������Ч���ŵ�Ŀ��λ��

	void setEffectInfo(EffectInfo& ei);//������Ч��Ϣ

	CC_SYNTHESIZE(bool, m_isPlaying, IsPlaying);//�Ƿ����ڲ���
	CC_SYNTHESIZE_READONLY(cocos2d::CCNode*, m_displayNode, DisplayNode);//��Ч���ֵ�

private:
	void startFly();//��ʼ����
	void flyOverCallback();//���н���
private:
	EffectInfo m_effectInfo;//��Ч��Ϣ
	float m_sElapsed;//��ʼʱ����
	float m_dElapsed;//����ʱ����
};
