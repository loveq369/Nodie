#pragma once

//���������õĽ����
class INoobGuide
{
public:
	virtual void startGuideStep() = 0;//��ʼ����
	virtual void nextGuidStep() = 0;//��һ������
	virtual void finishGuideStep() = 0;//�������
	virtual void stopGuideStep() = 0;//ֹͣ����
};
