#include "SimplePanel.h"
#include "GameGobal.h"
#include "GameUILayer.h"
USING_NS_CC;

void SimplePanel::toggle()
{
	bool isShow = !isVisible();
	//GameGobal::getInstance().getGameUILayer()->showPanel(this, isShow);
}