#include "WXGridPanelEx.h"
#include "WXUIDefine.h"
USING_NS_CC;


WXGridPanelEx::WXGridPanelEx(void)
{
	m_curHitGrid = NULL;
	m_lastHitGrid = NULL;

	m_bgBatchNode = NULL;
	m_lockBatchNode = NULL;
	m_bindingBatchNode = NULL;
	m_innerBatchNode = NULL;

	m_bgBatchNodeStr = "";
	m_bgStr = "";
	m_lockBatchNodeStr = "";
	m_lockStr = "";
	m_bindingBatchNodeStr = "";
	m_bindingStr = "";
	m_innerBatchNodeStr = "";
	m_innerStr = "";

	m_isShowSelectedRect = true;
}
WXGridPanelEx::~WXGridPanelEx(void)
{
}
bool WXGridPanelEx::init()
{
	return true;
}
void WXGridPanelEx::createGrids(std::vector<CCPoint>& tpList, const char* cdName)
{
	std::vector<CCPoint>::iterator itr = tpList.begin();
	int index = 0;
	for (;itr!=tpList.end();itr++,index++)
	{
		tGridData tgd;
		appendItem(tgd, *itr, index, cdName);
	}
}
void WXGridPanelEx::appendItem(tGridData& tgd, cocos2d::CCPoint& pos, int tag, const char* cdName)
{
	GridItem item;
	item.m_grid = WXGridBase::createWithSpriteFrameName(cdName);
	item.m_grid->setPosition(pos);
	addChild(item.m_grid, grid_zorder_icon);
	if (tag==-1)
	{
		item.m_grid->setTag(m_gridList.size());
	}
	else
	{
		item.m_grid->setTag(tag);
	}
	if (m_bgBatchNode && m_bgStr!="")
	{
		item.m_bgSprite = CCSprite::createWithSpriteFrameName(m_bgStr.c_str());
		item.m_bgSprite->setPosition(pos);
		m_bgBatchNode->addChild(item.m_bgSprite);
	}
	if (m_lockBatchNode && m_lockStr!="")
	{
		item.m_lockSprite = CCSprite::createWithSpriteFrameName(m_lockStr.c_str());
		item.m_lockSprite->setPosition(pos);
		m_lockBatchNode->addChild(item.m_lockSprite);
	}
	if (m_bindingBatchNode && m_bindingStr!="")
	{
		item.m_bindingSprite = CCSprite::createWithSpriteFrameName(m_bindingStr.c_str());
		CCSize iconSize = item.m_grid->getIconSize();
		CCSize bindingSize = item.m_bindingSprite->getContentSize();
		CCPoint newPos = ccpAdd(pos, ccp((bindingSize.width-iconSize.width)/2, (iconSize.height-bindingSize.height)/2));
		item.m_bindingSprite->setPosition(newPos);
		m_bindingBatchNode->addChild(item.m_bindingSprite);
	}
	if (m_innerBatchNode && m_innerStr!="")
	{
		item.m_innerSprite = CCSprite::createWithSpriteFrameName(m_innerStr.c_str());
		item.m_innerSprite->setPosition(pos);
		m_innerBatchNode->addChild(item.m_innerSprite);
	}
	if (m_outerBatchNode && m_outerStr!="")
	{
		item.m_outerSprite = CCSprite::createWithSpriteFrameName(m_outerStr.c_str());
		item.m_outerSprite->setPosition(pos);
		m_innerBatchNode->addChild(item.m_outerSprite);
	}

	m_gridList.push_back(item);
}
void WXGridPanelEx::updateGrid(unsigned int pos, tGridData& tgd)
{
	if (pos<m_gridList.size())
	{
		GridItem* item = &(*(m_gridList.begin()+pos));
		tgd.pos = pos;
		item->setIsBinding(tgd.isBinding);
		item->updateGrid(tgd);
	}
}
void WXGridPanelEx::setIsLock(unsigned int pos, bool isLock)
{
	if (pos<m_gridList.size())
	{
		GridItem* item = &(*(m_gridList.begin()+pos));
		item->setIsLock(isLock);
	}
}
void WXGridPanelEx::setIsBinding( unsigned int pos, bool isBinding )
{
	if (pos<m_gridList.size())
	{
		GridItem* item = &(*(m_gridList.begin()+pos));
		item->setIsBinding(isBinding);
	}
}
void WXGridPanelEx::setColorRectColor(unsigned int pos, const ccColor3B& color, int type)
{
	if (pos<m_gridList.size())
	{
		GridItem* item = &(*(m_gridList.begin()+pos));
		item->setColorRectColor(color, type);
	}
}
GridItem* WXGridPanelEx::getGrid(unsigned int pos)
{
	if (pos<m_gridList.size())
	{
		return &(*(m_gridList.begin()+pos));
	}
	else
	{
		return NULL;
	}
}
void WXGridPanelEx::setIconSpriteOpacity(unsigned int pos,int val)
{
	if (pos<m_gridList.size())
	{
		GridItem* item = &(*(m_gridList.begin()+pos));
		item->m_grid->setIconSpriteOpacity(val);
	}
}
void WXGridPanelEx::setDefaultHitGrid()
{
	if (m_gridList.size()>0)
	{
		m_lastHitGrid = m_curHitGrid;
		if (m_lastHitGrid)
		{
			m_lastHitGrid->selected(false);
		}
		m_curHitGrid = &(*m_gridList.begin());
		if (m_isShowSelectedRect)
		{
			m_curHitGrid->selected(true);
		}
	}
}
void WXGridPanelEx::selected(unsigned int pos)
{
	if (pos>=0 && pos <m_gridList.size())
	{
		GridItem* item = &(*(m_gridList.begin()+pos));
		m_lastHitGrid = m_curHitGrid;
		if (m_curHitGrid)
		{
			m_curHitGrid->selected(false);
		}
		m_curHitGrid = item;
		if (m_isShowSelectedRect)
		{
			m_curHitGrid->selected(true);
		}
	}
}
bool WXGridPanelEx::onTouchBegan(CCTouch* pTouch, CCEvent *pEvent)
{
	if (!isShow())
	{
		return false;
	}
	GridItem* currentItem = itemForTouch(pTouch);
	if (currentItem)
	{
		if (m_curHitGrid)
			m_curHitGrid->selected(false);
		m_curHitGrid = currentItem;
		if (m_isShowSelectedRect)
			m_curHitGrid->selected(true);
		return true;
	}
	return false;
}
bool WXGridPanelEx::onTouchEnded(CCTouch* pTouch, CCEvent *pEvent)
{
	GridItem* currentItem = itemForTouch(pTouch);
	if (currentItem)
	{
		if (m_curHitGrid)
		{
			m_curHitGrid->selected(false);
			if (currentItem==m_curHitGrid)
			{
				m_lastHitGrid = m_curHitGrid;
				if (m_pListener && m_pfnSelector)
				{
					(m_pListener->*m_pfnSelector)(m_curHitGrid->m_grid);
				}
			}
		}
		return true;
	}
	else
	{
		if (m_curHitGrid)
			m_curHitGrid->selected(false);
		return false;
	}
}
void WXGridPanelEx::onTouchMoved(CCTouch* pTouch, CCEvent *pEvent)
{

}
void WXGridPanelEx::onTouchCancelled(CCTouch* pTouch, CCEvent *pEvent)
{
	if (m_curHitGrid)
		m_curHitGrid->selected(false);
}

void WXGridPanelEx::setBGFilename( const char* batchNodeFilename, const char* filename )
{
	if (batchNodeFilename && batchNodeFilename!=m_bgBatchNodeStr)
	{
		m_bgBatchNodeStr = batchNodeFilename;
		if (m_bgBatchNode)
		{
			removeChild(m_bgBatchNode, true);
			m_bgBatchNode = NULL;
		}
		m_bgBatchNode = CCSpriteBatchNode::create(batchNodeFilename);
		addChild(m_bgBatchNode, grid_zorder_bg, -1);

		m_bgStr = filename;
	}
}

void WXGridPanelEx::setLockFilename( const char* batchNodeFilename, const char* filename )
{
	if (batchNodeFilename && batchNodeFilename!=m_lockBatchNodeStr)
	{
		m_lockBatchNodeStr = batchNodeFilename;
		if (m_lockBatchNode)
		{
			removeChild(m_lockBatchNode, true);
			m_lockBatchNode = NULL;
		}
		m_lockBatchNode = CCSpriteBatchNode::create(batchNodeFilename);
		addChild(m_lockBatchNode, grid_zorder_lock, -1);

		m_lockStr = filename;
	}
}

void WXGridPanelEx::setBindingFilename( const char* batchNodeFilename, const char* filename )
{
	if (batchNodeFilename && batchNodeFilename!=m_bindingBatchNodeStr)
	{
		m_bindingBatchNodeStr = batchNodeFilename;
		if (m_bindingBatchNode)
		{
			removeChild(m_bindingBatchNode, true);
			m_bindingBatchNode = NULL;
		}
		m_bindingBatchNode = CCSpriteBatchNode::create(batchNodeFilename);
		addChild(m_bindingBatchNode, grid_zorder_binding, -1);

		m_bindingStr = filename;
	}
}

void WXGridPanelEx::setInnerFilename( const char* batchNodeFilename, const char* filename )
{
	if (batchNodeFilename && batchNodeFilename!=m_innerBatchNodeStr)
	{
		m_innerBatchNodeStr = batchNodeFilename;
		if (m_innerBatchNode)
		{
			removeChild(m_innerBatchNode, true);
			m_innerBatchNode = NULL;
		}
		m_innerBatchNode = CCSpriteBatchNode::create(batchNodeFilename);
		addChild(m_innerBatchNode, grid_zorder_inner, -1);

		m_innerStr = filename;
	}
}

void WXGridPanelEx::setOuterFilename( const char* batchNodeFilename, const char* filename )
{
	if (batchNodeFilename && batchNodeFilename!=m_outerBatchNodeStr)
	{
		m_outerBatchNodeStr = batchNodeFilename;
		if (m_outerBatchNode)
		{
			removeChild(m_outerBatchNode, true);
			m_outerBatchNode = NULL;
		}
		m_outerBatchNode = CCSpriteBatchNode::create(batchNodeFilename);
		addChild(m_outerBatchNode, grid_zorder_outer, -1);

		m_outerStr = filename;
	}
}

void WXGridPanelEx::initRes( const char* bgbatchNodeFilename, const char* bgfilename,\
	const char* lockbatchNodeFilename, const char* lockfilename,\
	const char* bindingbatchNodeFilename, const char* bindingfilename,\
	const char* innnerbatchNodeFilename, const char* innnerfilename,\
	const char* outnerbatchNodeFilename, const char* outnerfilename )
{
	setBGFilename(bgbatchNodeFilename, bgfilename);
	setLockFilename(lockbatchNodeFilename, lockfilename);
	setBindingFilename(bindingbatchNodeFilename, bindingfilename);
	setInnerFilename(innnerbatchNodeFilename, innnerfilename);
	setOuterFilename(outnerbatchNodeFilename, outnerfilename);
}

GridItem* WXGridPanelEx::itemForTouch( cocos2d::CCTouch * touch )
{
	CCPoint touchLocation = touch->getLocation();
	std::vector<GridItem>::iterator itr = m_gridList.begin();
	for (;itr!=m_gridList.end();itr++)
	{
		if ((*itr).m_grid && (*itr).m_grid->isVisible())
		{
			CCPoint local = (*itr).m_grid->convertToNodeSpace(touchLocation);
			CCRect r = (*itr).m_grid->rect();
			r.origin = CCPoint::ZERO;

			if (r.containsPoint(local))
			{
				return &(*itr);
			}
		}
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////
void GridItem::updateGrid( tGridData& tgd )
{
	if (m_grid) m_grid->updateGrid(tgd);
}

void GridItem::show( bool isShow )
{
	if (m_grid) m_grid->setVisible(isShow);
	if (m_bgSprite) m_bgSprite->setVisible(isShow);
	if (m_lockSprite) m_lockSprite->setVisible(isShow);
	if (m_bindingSprite) m_bindingSprite->setVisible(isShow);
	if (m_innerSprite) m_innerSprite->setVisible(isShow);
	if (m_outerSprite) m_outerSprite->setVisible(isShow);
}

GridItem::GridItem()
{
	m_grid = NULL;
	m_bgSprite = NULL;
	m_lockSprite = NULL;
	m_bindingSprite = NULL;
	m_innerSprite = NULL;
	m_outerSprite = NULL;
}

void GridItem::setIsBinding( bool isBinding )
{
	if (m_bindingSprite) m_bindingSprite->setVisible(isBinding);
}

void GridItem::showColorRect( bool isShow, int type )
{
	switch (type)
	{
	case 0:
		{
			if (m_outerSprite) m_outerSprite->setVisible(isShow);
		}
		break;
	case 1:
		{
			if (m_innerSprite) m_innerSprite->setVisible(isShow);
		}
		break;
	}
}

void GridItem::setColorRectColor( const cocos2d::ccColor3B& color, int type )
{
	switch (type)
	{
	case 0:
		{
			m_outerColor = color;
			if (m_outerSprite)
				m_outerSprite->setColor(color);
		}
		break;
	case 1:
		{
			m_innerColor = color;
			if (m_innerSprite)
				m_innerSprite->setColor(color);
		}
		break;
	}
}

void GridItem::setIsActive( bool isActive )
{
	if (m_grid) m_grid->setIsActive(isActive);
}

void GridItem::showNumLabel( bool isShow, const cocos2d::ccColor3B& color/*=cocos2d::ccWHITE*/ )
{
	if (m_grid) m_grid->showNumLabel(isShow, color);
}

void GridItem::setIsLock( bool isLock )
{
	if (m_lockSprite) m_lockSprite->setVisible(isLock);
}

void GridItem::selected(bool var)
{
	showColorRect(var);
}

void GridItem::activate()
{

}

