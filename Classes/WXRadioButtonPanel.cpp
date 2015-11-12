#include "WXRadioButtonPanel.h"
#include "WXUIDefine.h"
#include "WXRadioButton.h"
USING_NS_CC;


WXRadioButtonPanel::WXRadioButtonPanel(void)
{
	m_oldBtn = NULL;
}
WXRadioButtonPanel::~WXRadioButtonPanel(void)
{
}

bool WXRadioButtonPanel::onTouchEnded(CCTouch*pTouch, CCEvent*pEvent)
{
	WXSimpleButton* currentItem = itemForTouch(pTouch);
	if (currentItem)
	{
		if (m_currentBtn && currentItem==m_currentBtn)
		{
			if (m_currentBtn!=m_oldBtn)
			{
				if (m_oldBtn) m_oldBtn->selected(false);
				if (m_pListener && m_pfnSelector)
				{
					(m_pListener->*m_pfnSelector)(m_currentBtn);
				}
				m_oldBtn = m_currentBtn;
			}
		}
		m_currentBtn = NULL;
		return true;
	}
	return false;
}

void WXRadioButtonPanel::select( WXCheckButton* btn, bool isSelected )
{
	if (btn)
	{
		if (isSelected)
		{
			if (m_currentBtn)
			{
				m_currentBtn->selected(false);
			}
			m_currentBtn = btn;
			m_currentBtn->selected(true);
			m_oldBtn = m_currentBtn;
		}
		else
		{
			btn->selected(false);
			if (m_currentBtn==btn)
			{
				m_currentBtn = NULL;
				m_oldBtn = NULL;
			}
		}
	}
}
