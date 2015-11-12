#pragma once

//新手引导用的借口类
class INoobGuide
{
public:
	virtual void startGuideStep() = 0;//开始引导
	virtual void nextGuidStep() = 0;//下一步引导
	virtual void finishGuideStep() = 0;//完成引导
	virtual void stopGuideStep() = 0;//停止引导
};
