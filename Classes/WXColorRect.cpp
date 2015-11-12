#include "WXColorRect.h"
USING_NS_CC;

bool WXColorRect::init()
{
	rectColor.r = 255;
	rectColor.g = 255;
	rectColor.b = 0;
	rectColor.a = 255;
	origin = ccp(-18, -18);
	destination = ccp(18, 18);
	lineWidth = 4;
	return CCLayer::init();
}
void WXColorRect::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	CHECK_GL_ERROR_DEBUG();
	ccDrawColor4B(rectColor.r, rectColor.g, rectColor.b, rectColor.a);
	glLineWidth(lineWidth);
	ccDrawRect(origin, destination);
}