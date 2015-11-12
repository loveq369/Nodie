#pragma once

#include "cocos2d.h"


class WXLine: public cocos2d::CCNode
{
public:
	virtual bool init();
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);

	CC_SYNTHESIZE(cocos2d::ccColor4B, m_cLineColor, LineColor);//����ɫֵ
	CC_SYNTHESIZE(int, m_iLineThickness, LineThickness);//�ߴ�ϸ
	CC_SYNTHESIZE(int, m_iLineWidth, LineWidth);//�߿�
	CC_SYNTHESIZE(bool, m_bDrawLine, DrawLine);//�Ƿ���

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

	void setLinePosition(const cocos2d::CCPoint& var);//�����»��ߵ�λ��
	void setLineColor(const cocos2d::ccColor3B& var);//�»�����ɫֵ
	void setLineWidth(int var);//�»��߿�
	void setUnderLine(bool var);//�Ƿ��»���
private:
	WXLine* m_pLine;//�»���
};
