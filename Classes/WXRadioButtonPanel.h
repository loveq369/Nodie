#pragma once

#include "WXCheckButtonPanel.h"


class WXRadioButton;
class WXRadioButtonPanel: public WXCheckButtonPanel
{
public:
	WXRadioButtonPanel(void);
	virtual ~WXRadioButtonPanel(void);
	
	virtual bool onTouchEnded(cocos2d::CCTouch*pTouch, cocos2d::CCEvent*pEvent); 

	CREATE_FUNC(WXRadioButtonPanel);
protected:
	virtual void select(WXCheckButton* btn, bool isSelected);
protected:
	WXCheckButton* m_oldBtn;//之前点中的按钮
};

