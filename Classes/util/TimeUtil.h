#pragma once

#include "basic_types.h"


class TimeUtil
{
public:
	static TimeUtil& getInstance()
	{
		static TimeUtil instance;
		return instance;
	}
	long getTimer();//��ȡϵͳʱ�䣨���룩
	void setServerTime(uint32 serverTime);//���÷�����ʱ��
	uint32 timerFlag();
	int currentTimestamp1();
	float currentTimestamp();
	/*
	std::string getHourMinWithOutString(int _arg1);
	std::string getDateBySecond(int _arg1);
	std::string time2DayString(int _arg1);
	std::string getHourMinString(int _arg1);
	std::string data3String(int _arg1);
	std::string getTimeString(int _arg1, int _arg2=1);
	std::string replenishZero(std::string _arg1);
	std::string data2String(int _arg1);
	std::string getFormatTime(int _arg1);*/

private:
	TimeUtil();
	TimeUtil(const TimeUtil&);
	TimeUtil& operator=(const TimeUtil&);
	~TimeUtil();

private:
	uint32 m_serverTime;
	long m_clientTime;
	uint32 m_lastTimerFlag;
	uint32 m_timerModify;
};
