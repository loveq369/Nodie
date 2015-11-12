#include "WXGridPanel.h"
#include "WXUIDefine.h"
USING_NS_CC;


WXGridPanel::WXGridPanel(void)
{
	m_curHitGrid = NULL;
	m_lastHitGrid = NULL;
	m_isShowSelectedRect = true;
	m_gridList = new std::vector<WXGrid*>();
}
WXGridPanel::~WXGridPanel(void)
{
	CC_SAFE_DELETE(m_gridList);
}
void WXGridPanel::createGrids(std::vector<CCPoint> tpList, const char* bgName,\
	const char* lockName, const char* cdName, const char* bindingName, \
	const char* innerName, const char* outerName)
{
	std::vector<CCPoint>::iterator itr = tpList.begin();
	int index = 0;
	for (;itr!=tpList.end();itr++,index++)
	{
		WXGrid* grid = WXGrid::createWithSpriteFrameName(bgName, lockName, cdName, bindingName, innerName, outerName);
		grid->setIcon("");
		grid->setGridPos(index);
		grid->setPosition(*itr);
		addChild(grid);
		m_gridList->push_back(grid);
	}
}
void WXGridPanel::appendItem(WXGrid* grid, int tag)
{
	if (!grid)
	{
		return;
	}
	if (tag==-1)
	{
		grid->setTag(m_gridList->size());
	}
	else
	{
		grid->setTag(tag);
	}
	addChild(grid);
	m_gridList->push_back(grid);
}
void WXGridPanel::updateGrid(unsigned int pos, tGridData& tgd)
{
	if (pos>=m_gridList->size())
	{
		return;
	}
	std::vector<WXGrid*>::iterator itr = m_gridList->begin();
	itr += pos;
	tgd.pos = pos;
	(*itr)->updateGrid(tgd);
}
void WXGridPanel::setIsLock(unsigned int pos,bool isLock)
{
	if (pos>=m_gridList->size())
	{
		return;
	}
	std::vector<WXGrid*>::iterator itr = m_gridList->begin();
	itr += pos;
	(*itr)->setIsLock(isLock);
}
void WXGridPanel::setColorRectColor(unsigned int pos, const ccColor3B& color, int type)
{
	if (pos>=m_gridList->size())
	{
		return;
	}
	std::vector<WXGrid*>::iterator itr = m_gridList->begin();
	itr += pos;
	(*itr)->setColorRectColor(color, type);
}

void WXGridPanel::selected(unsigned int pos)
{
	if (pos>=0 && pos <m_gridList->size())
	{
		std::vector<WXGrid*>::iterator itr = m_gridList->begin();
		itr += pos;
		m_lastHitGrid = m_curHitGrid;
		if (m_curHitGrid)
		{
			m_curHitGrid->unselected();
		}
		m_curHitGrid = *itr;
		if (m_isShowSelectedRect)
		{
			m_curHitGrid->selected();
		}
	}
}

void WXGridPanel::setDefaultHitGrid()
{
	if (m_gridList->size()>0)
	{
		m_lastHitGrid = m_curHitGrid;
		if (m_lastHitGrid)
		{
			m_curHitGrid->unselected();
		}
		m_curHitGrid = m_gridList->front();
		if (m_isShowSelectedRect)
		{
			m_curHitGrid->selected();
		}
	}
}
bool WXGridPanel::onTouchBegan(CCTouch* pTouch, CCEvent *pEvent)
{
	if (!isShow())
	{
		return false;
	}
	WXGrid* currentItem = itemForTouch(pTouch);
	if (currentItem)
	{
		if (m_curHitGrid)
			m_curHitGrid->unselected();
		m_curHitGrid = currentItem;
		if (m_isShowSelectedRect)
			m_curHitGrid->selected();
		return true;
	}
	return false;
}
bool WXGridPanel::onTouchEnded(CCTouch* pTouch, CCEvent *pEvent)
{
	WXGrid* currentItem = itemForTouch(pTouch);
	if (currentItem)
	{
		if (m_curHitGrid)
		{
			m_curHitGrid->unselected();
			if (currentItem==m_curHitGrid)
			{
				m_lastHitGrid = m_curHitGrid;
				if (m_pListener && m_pfnSelector)
				{
					(m_pListener->*m_pfnSelector)(m_curHitGrid);
				}
			}
		}
		return true;
	}
	else
	{
		if (m_curHitGrid)
			m_curHitGrid->unselected();
		return false;
	}
}
void WXGridPanel::onTouchMoved(CCTouch* pTouch, CCEvent *pEvent)
{

}
void WXGridPanel::onTouchCancelled(CCTouch* pTouch, CCEvent *pEvent)
{
	if (m_curHitGrid)
		m_curHitGrid->unselected();
}
WXGrid* WXGridPanel::getGrid(unsigned int pos)
{
	if (pos <m_gridList->size())
	{
		std::vector<WXGrid*>::iterator itr = m_gridList->begin();
		itr += pos;
		return *itr;
	}
	else
	{
		return NULL;
	}
}
WXGrid* WXGridPanel::getGridByTag(unsigned int tag)
{
	return (WXGrid*)(getChildByTag(tag));
}
void WXGridPanel::setIconSpriteOpacity(unsigned int pos,int val)
{
	if (pos>=m_gridList->size())
	{
		return;
	}
	std::vector<WXGrid*>::iterator itr = m_gridList->begin();
	itr += pos;
	(*itr)->setIconSpriteOpacity(val);
}

WXGrid* WXGridPanel::itemForTouch( cocos2d::CCTouch * touch )
{
	CCPoint touchLocation = touch->getLocation();
	std::vector<WXGrid*>::iterator itr = m_gridList->begin();
	for (;itr!=m_gridList->end();itr++)
	{
		if (*itr && (*itr)->isVisible())
		{
			CCPoint local = (*itr)->convertToNodeSpace(touchLocation);
			CCRect r = (*itr)->rect();
			r.origin = CCPoint::ZERO;

			if (r.containsPoint(local))
			{
				return (*itr);
			}
		}
	}
	return NULL;
}
