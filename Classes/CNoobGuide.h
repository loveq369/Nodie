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

	//当前引导到的步数
	CC_SYNTHESIZE(int, m_currGuideStep, CurrGuideStep);
// 	对应引导的数据
// 		CC_SYNTHESIZE(NoobConfigData*, m_noobConfigData, NoobConfigData);
	//是否在引导中
	CC_SYNTHESIZE(bool,isNoobGuiding,NoobGuiding);
};

