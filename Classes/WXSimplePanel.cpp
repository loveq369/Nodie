#include "WXSimplePanel.h"
USING_NS_CC;

WXSimplePanel::WXSimplePanel(void)
{
	m_isInit = true;
	m_pListener = NULL;
}
WXSimplePanel::~WXSimplePanel(void)
{
}
void WXSimplePanel::show(bool isShow/* =true */)
{
	if (isShow)
	{
		checkInitPanel();
	}
	setVisible(isShow);
}
void WXSimplePanel::toggle()
{
	bool isShow = !isVisible();
	tween(isShow);
}
void WXSimplePanel::tween(bool isShow)
{
	show(isShow);
}
void WXSimplePanel::initPanel()
{
}
void WXSimplePanel::resetPanelState()
{
	setVisible(false);
}
bool WXSimplePanel::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event *pEvent)
{
	if (!isShow())
	{
		return false;
	}
	CCPoint convertedLocation = this->convertTouchToNodeSpace(pTouch);
	CCRect r = this->rect();
	r.origin = CCPoint::ZERO;
	if (r.containsPoint(convertedLocation))
	{
		return true;
	}
	return false;
}
void WXSimplePanel::onTouchMoved(cocos2d::Touch*pTouch, cocos2d::Event*pEvent)
{

}
bool WXSimplePanel::onTouchEnded(cocos2d::Touch*pTouch, cocos2d::Event*pEvent)
{
	CCPoint convertedLocation = this->convertTouchToNodeSpace(pTouch);
	CCRect r = this->rect();
	r.origin = CCPoint::ZERO;
	if (r.containsPoint(convertedLocation))
	{
		if (m_pListener && m_pfnSelector)
		{
			(m_pListener->*m_pfnSelector)(this);
			return true;
		}
	}
	return false;
}
void WXSimplePanel::onTouchCancelled(cocos2d::Touch*pTouch, cocos2d::Event*pEvent)
{

}

void WXSimplePanel::checkInitPanel()
{
	if (m_isInit)
	{
		initPanel();
		m_isInit = false;
	}
}
