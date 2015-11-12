#pragma once
//ui响应的接口
class WXResponseProtocol
{
public:
	virtual void selected(bool var) = 0;
	virtual void activate() = 0;
};