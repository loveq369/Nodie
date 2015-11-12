#include "WXLinkLabel.h"
USING_NS_CC;


WXLinkLabel * WXLinkLabel::create(const char *string, const char *fontName, float fontSize)
{
	return WXLinkLabel::create(string, fontName, fontSize,
		CCSize::ZERO, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
}
WXLinkLabel * WXLinkLabel::create(const char *string, const char *fontName, float fontSize,
	const CCSize& dimensions, CCTextAlignment hAlignment)
{
	return WXLinkLabel::create(string, fontName, fontSize, dimensions, hAlignment, kCCVerticalTextAlignmentTop);
}
WXLinkLabel* WXLinkLabel::create(const char *string, const char *fontName, float fontSize,
	const CCSize &dimensions, CCTextAlignment hAlignment, 
	CCVerticalTextAlignment vAlignment)
{
	WXLinkLabel *pRet = new WXLinkLabel();
	if(pRet && pRet->initWithString(string, fontName, fontSize, dimensions, hAlignment, vAlignment)\
		&& pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool WXLinkLabel::init()
{
	m_pLine = WXLine::create();
	m_pLine->setLineWidth(getContentSize().width);
	ccColor3B color3 = getColor();
	m_pLine->setLineColor(ccc4(color3.r,color3.g,color3.b, 255));
	addChild(m_pLine);

	return true;
}

void WXLinkLabel::setLineColor( const cocos2d::ccColor3B& var )
{
	m_pLine->setLineColor(ccc4(var.r,var.g,var.b,255));
}

void WXLinkLabel::setLineWidth( int var )
{
	m_pLine->setLineWidth(var);
}

void WXLinkLabel::setUnderLine( bool var )
{
	m_pLine->setDrawLine(var);
}

void WXLinkLabel::setString( const char *label )
{
	CCLabelTTF::setString(label);
	if (m_pLine) m_pLine->setLineWidth(getContentSize().width);
}

void WXLinkLabel::setColor( const ccColor3B& color3 )
{
	CCLabelTTF::setColor(color3);
	if (m_pLine) m_pLine->setLineColor(ccc4(color3.r,color3.g,color3.b, 255));
}

WXLinkLabel::WXLinkLabel()
{
	m_pLine = NULL;
}

void WXLinkLabel::setLinePosition( const cocos2d::CCPoint& var )
{
	if (m_pLine)
	{
		m_pLine->setPosition(var);
	}
}

bool WXLine::init()
{
	m_iLineThickness = 2;
	m_iLineWidth = 10;
	m_bDrawLine = true;
	m_cLineColor.r = 255;
	m_cLineColor.g = 255;
	m_cLineColor.b = 0;
	m_cLineColor.a = 255;

	return true;
}

void WXLine::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	if (m_bDrawLine)
	{
		ccDrawColor4B(m_cLineColor.r, m_cLineColor.g, m_cLineColor.b, m_cLineColor.a);
		glLineWidth(m_iLineThickness);
		CCPoint origin = ccp(0, 0);
		CCPoint destination = ccp(m_iLineWidth, 0);
		ccDrawLine(origin, destination);
	}
}

