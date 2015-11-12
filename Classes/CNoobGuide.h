#pragma once

#include "gamecore.h"
#include "UIProtocols.h"
class CNoobGuide: public INoobGuide
{
public:
	CNoobGuide();

	virtual void startGuideStep() = 0;
	virtual void nextGuidStep() = 0;
	virtual void stopGuideStep() = 0;

	virtual void finishGuideStep();

	//��ǰ�������Ĳ���
	CC_SYNTHESIZE(int, m_currGuideStep, CurrGuideStep);
// 	��Ӧ����������
// 		CC_SYNTHESIZE(NoobConfigData*, m_noobConfigData, NoobConfigData);
	//�Ƿ���������
	CC_SYNTHESIZE(bool,isNoobGuiding,NoobGuiding);
};

