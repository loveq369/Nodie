#pragma once

#include "cocos2d.h"


class WXLine: public cocos2d::CCNode
{
public:
	virtual bool init();
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);

	CC_SYNTHESIZE(cocos2d::ccColor4B, m_cLineColor, LineColor);//线颜色值
	CC_SYNTHESIZE(int, m_iLineThickness, LineThickness);//线粗细
	CC_SYNTHESIZE(int, m_iLineWidth, LineWidth);//线宽
	CC_SYNTHESIZE(bool, m_bDrawLine, DrawLine);//是否画线

	CREATE_FUNC(WXLine);
};

class WXLinkLabel: public cocos2d::CCLabelTTF
{
public:
	WXLinkLabel();
	virtual bool init();

    static WXLinkLabel* create(const char *string, const char *fontName, float fontSize);
    static WXLinkLabel* create(const char *string, const char *fontName, float fontSize,
                               const cocos2d::CCSize& dimensions, cocos2d::CCTextAlignment hAlignment);
    static WXLinkLabel* create(const char *string, const char *fontName, float fontSize,
                               const cocos2d::CCSize& dimensions, cocos2d::CCTextAlignment hAlignment, 
							   cocos2d::CCVerticalTextAlignment vAlignment);

	virtual void setString(const char *label);
	virtual void setColor(const cocos2d::ccColor3B& color3);

	void setLinePosition(const cocos2d::CCPoint& var);//设置下划线的位置
	void setLineColor(const cocos2d::ccColor3B& var);//下划线颜色值
	void setLineWidth(int var);//下划线宽
	void setUnderLine(bool var);//是否下划线
private:
	WXLine* m_pLine;//下划线
};
