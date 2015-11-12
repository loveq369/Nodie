#pragma once

#include "WXPanel.h"
#include "CNoobGuide.h"

class Panel: public WXPanel, public CNoobGuide
{
public:
	Panel();
	virtual ~Panel();
	virtual void toggle();//在做开关操作时通知GameUILayer，用来互斥等相关操作
	virtual void startGuideStep() {};
	virtual void nextGuidStep() {};
	virtual void stopGuideStep() {};
public:
	CC_SYNTHESIZE(WXPanel* ,triggerPanel,TriggerPanel);  //关闭时触发的面板

};

