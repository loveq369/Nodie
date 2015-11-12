#pragma once

#include "cocos2d.h"

class WXColorRect: public cocos2d::CCLayer
{
public:
	virtual bool init();
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);

	CREATE_FUNC(WXColorRect);
	CC_SYNTHESIZE(cocos2d::ccColor4B, rectColor, RectColor);//��ɫֵ
	CC_SYNTHESIZE(cocos2d::CCPoint, origin, Origin);//��ʼ���ĵ�
	CC_SYNTHESIZE(cocos2d::CCPoint, destination, Destination);//�������ĵ�
	CC_SYNTHESIZE(int, lineWidth, LineWidth);//������
};