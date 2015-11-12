#include "WXPanel.h"
#include "WXUIDefine.h"
#include "WXSimpleButton.h"
#include "WXMenu.h"
USING_NS_CC;


	WXPanel::WXPanel(void)
{
	m_startPos = CCPoint::ZERO;
	m_endPos = CCPoint::ZERO;
	m_tweenAction = NULL;
	m_closeBtn = NULL;
	m_isTweenning = false;
	m_canTween = true;
	m_tweenDuration = 0.2f;
	m_closeBtnGap = 10.0f;
	m_tweenType = tween_type_only_start;
}
WXPanel::~WXPanel(void)
{
}
void WXPanel::initPanel()
{
	setAnchorPoint(CCPoint::ZERO);
}
void WXPanel::toggle()
{
	if (!m_isTweenning)
	{
		bool isShow = !isVisible();
		tween(isShow);
	}
}
void WXPanel::tween(bool isShow/* =true */)
{
	if (!m_canTween)
	{
		show(isShow);
		return;
	}
	if (m_tweenAction)
	{
		stopAction(m_tweenAction);
	}
	if (isShow)
	{
		if (m_tweenType==tween_type_only_start || m_tweenType==tween_type_both)
		{
			CCMoveTo* moveTo;
			CCCallFunc* tweenCb = CCCallFunc::create(this, callfunc_selector(WXPanel::tweenCallback));
			show(true);
			moveTo = CCMoveTo::create(m_tweenDuration, m_endPos);
			m_tweenAction = runAction(CCSequence::create(moveTo, tweenCb, NULL));
			m_isTweenning = true;
		}
		else if (m_tweenType==tween_type_only_end)
		{
			show(true);
			m_isTweenning = false;
			m_tweenAction = NULL;
			setPosition(m_endPos);
		}
	}
	else
	{
		if (m_tweenType==tween_type_only_start)
		{
			show(false);
			m_isTweenning = false;
			m_tweenAction = NULL;
			setPosition(m_startPos);
		}
		else if (m_tweenType==tween_type_both || m_tweenType==tween_type_only_end)
		{
			CCMoveTo* moveTo;
			CCCallFunc* tweenCb = CCCallFunc::create(this, callfunc_selector(WXPanel::tweenBackCallback));
			moveTo = CCMoveTo::create(m_tweenDuration, m_startPos);
			m_tweenAction = runAction(CCSequence::create(moveTo, tweenCb, NULL));
			m_isTweenning = true;
		}
	}
}

void WXPanel::tweenCallback()
{
	m_isTweenning = false;
	m_tweenAction = NULL;
}

void WXPanel::tweenBackCallback()
{
	show(false);
	m_isTweenning = false;
	m_tweenAction = NULL;
}

void WXPanel::closeCallback(CCObject* pSender)
{
	toggle();
}

void WXPanel::createCloseBtn(const char* normalName, const char* selectedName)
{
	m_closeBtn = WXSimpleButton::createWithSpriteFrameName(normalName, selectedName, this, callfuncO_selector(WXPanel::closeCallback));
	m_closeBtn->setPosition(ccp(getContentSize().width-m_closeBtn->getContentSize().width/2-m_closeBtnGap, getContentSize().height-m_closeBtn->getContentSize().height/2-m_closeBtnGap));
	addChild(m_closeBtn, 99);
}

bool WXPanel::closeBtnTouchBegan( cocos2d::CCTouch* pTouch, cocos2d::CCEvent *pEvent )
{
	if (m_closeBtn && m_closeBtn->onTouchBegan(pTouch,pEvent))
	{
		return true;
	}
	return false;
}

bool WXPanel::closeBtnTouchEnded( cocos2d::CCTouch* pTouch, cocos2d::CCEvent *pEvent )
{
	if (m_closeBtn && m_closeBtn->onTouchEnded(pTouch,pEvent))
	{
		return true;
	}
	return false;
}
