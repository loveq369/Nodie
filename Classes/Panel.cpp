#include "Panel.h"
#include "GameGobal.h"
#include "GameUILayer.h"
USING_NS_CC;

Panel::Panel()
{
	triggerPanel =NULL;
}
Panel::~Panel()
{
}

void Panel::toggle()
{
	if (m_isTweenning)
	{
		return;
	}
	bool isShow = !isVisible();
	GameGobal::getInstance().getGameUILayer()->showPanel(this, isShow);

	if (!isShow && triggerPanel)   //此面板关闭时，打开触发面板（上次关闭的面板）
	{
		if (triggerPanel->getCanTween())
		{
			triggerPanel->toggle();
		}
		else
		{
			triggerPanel->setVisible(true);
		}

	}
	triggerPanel =NULL;
}
