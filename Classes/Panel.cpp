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

	if (!isShow && triggerPanel)   //�����ر�ʱ���򿪴�����壨�ϴιرյ���壩
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
