#include "CNoobGuide.h"
#include "PlayerController.h"
#include "GameGobal.h"
USING_NS_CC;

CNoobGuide::CNoobGuide()
{
	m_currGuideStep = 0;
	//m_noobConfigData = NULL;
	isNoobGuiding =false;
}

void CNoobGuide::finishGuideStep()
{
	//GameGobal::getInstance().getGameUILayer()->getNoobPanel()->show(false);
	/*if (m_noobConfigData)
	{
	PlayerController::getInstance().getNoobManager()->finishGuide(m_noobConfigData->m_taskID, m_noobConfigData->m_taskState);
	}*/
}
