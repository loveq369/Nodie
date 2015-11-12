#pragma once

#include "cocos2d.h"

class WXColorRect: public cocos2d::CCLayer
{
public:
	virtual bool init();
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);

	CREATE_FUNC(WXColorRect);
	CC_SYNTHESIZE(cocos2d::ccColor4B, rectColor, RectColor);//颜色值
	CC_SYNTHESIZE(cocos2d::CCPoint, origin, Origin);//开始画的点
	CC_SYNTHESIZE(cocos2d::CCPoint, destination, Destination);//结束画的点
	CC_SYNTHESIZE(int, lineWidth, LineWidth);//线条宽
};