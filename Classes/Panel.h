#pragma once

#include "WXPanel.h"
#include "CNoobGuide.h"

class Panel: public WXPanel, public CNoobGuide
{
public:
	Panel();
	virtual ~Panel();
	virtual void toggle();//�������ز���ʱ֪ͨGameUILayer�������������ز���
	virtual void startGuideStep() {};
	virtual void nextGuidStep() {};
	virtual void stopGuideStep() {};
public:
	CC_SYNTHESIZE(WXPanel* ,triggerPanel,TriggerPanel);  //�ر�ʱ���������

};

