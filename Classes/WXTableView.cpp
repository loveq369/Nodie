#include "WXTableView.h"
USING_NS_CC;


WXTableView::WXTableView()
{
	m_fMoveDelta = 10;
	m_bIsNextPage = false;
	m_fNextPageMinScrollDistance = 10;
	m_fNextPageSpeed = 200;
	m_pTarget = NULL;
	m_pSelector = NULL;
}
WXTableView* WXTableView::create(TableViewDataSource* dataSource, CCSize size)
{
	return WXTableView::create(dataSource, size, NULL);
}
WXTableView* WXTableView::create(TableViewDataSource* dataSource, CCSize size, CCNode *container)
{
	WXTableView *table = new WXTableView();
	table->initWithViewSize(size, container);
	table->autorelease();
	table->setDataSource(dataSource);
	table->_updateCellPositions();
	table->_updateContentSize();

	table->setTouchEnabled(false);

	return table;
}
bool WXTableView::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	m_beginPoint = pTouch->getLocation();
	if (m_bIsNextPage)
	{
		m_begin_containerPos_nextPage = getContainer()->getPosition();
	}
	return TableView::onTouchBegan(pTouch, pEvent);
}
void WXTableView::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!this->isVisible()) 
	{
		return;
	}
	ScrollView::onTouchMoved(pTouch, pEvent);
	m_lastPoint = pTouch->getLocation();
	float dx = m_beginPoint.x - m_lastPoint.x;
	float dy = m_beginPoint.y - m_lastPoint.y;
	if ((-m_fMoveDelta < dx &&  dx < m_fMoveDelta) && (-m_fMoveDelta < dy && dy < m_fMoveDelta))
	{
		_touchMoved = false;
	}
	if (_touchedCell && isTouchMoved())
	{
		if(_tableViewDelegate != NULL)
		{
			_tableViewDelegate->tableCellUnhighlight(this, _touchedCell);
		}
		_touchedCell = NULL;
	}
}
void WXTableView::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!this->isVisible()) {
		return;
	}

	if (_touchedCell){
		CCRect bb = this->boundingBox();
		bb.origin = _parent->convertToWorldSpace(bb.origin);

		if (bb.containsPoint(pTouch->getLocation()) && _tableViewDelegate != NULL)
		{
			_tableViewDelegate->tableCellUnhighlight(this, _touchedCell);
			_tableViewDelegate->tableCellTouched(this, _touchedCell);
		}

		_touchedCell = NULL;
	}

	if (m_bIsNextPage)
	{
		m_ended_containerPos_nextPage = _container->getPosition();

		if (std::find(_touches.begin(), _touches.end(), pTouch) == _touches.end())
		{
			if (_touches.size() == 1)
			{
				checkNeedNextPage();
				this->schedule(schedule_selector(WXTableView::nextPageDeaccelerateScrolling));
			}
			auto touchIter = std::find(_touches.begin(), _touches.end(), pTouch);
			_touches.erase(touchIter);
			//m_pTouches->removeObject(pTouch);
		} 

		if (_touches.size()== 0)
		{
			_dragging = false;    
			_touchMoved = false;
		}
	}
	else
	{
		ScrollView::onTouchEnded(pTouch, pEvent);
	}
}

void WXTableView::reloadData()
{
	TableView::reloadData();
	m_desire_containerPos_nextPage = _container->getPosition();
	m_origin_containerPos_nextPage = m_desire_containerPos_nextPage;
}
void WXTableView::checkNeedNextPage()
{
	CCPoint maxInset, minInset;
	if (_bounceable)
	{
		maxInset = _maxInset;
		minInset = _minInset;
	}
	else
	{
		maxInset = this->maxContainerOffset();
		minInset = this->minContainerOffset();
	}
	switch (this->getDirection())
	{
	case ScrollView::Direction::HORIZONTAL:
		{
			//检查手势
			if (m_fNextPageMinScrollDistance<_scrollDistance.x)//左翻页
			{
				m_desire_containerPos_nextPage.x += getViewSize().width;
			}
			else if (-m_fNextPageMinScrollDistance>_scrollDistance.x)//右翻页
			{
				m_desire_containerPos_nextPage.x -= getViewSize().width;
			}
			else
			{
				float dx = m_ended_containerPos_nextPage.x-m_begin_containerPos_nextPage.x;
				if (dx>getViewSize().width/2)//左翻页
				{
					m_desire_containerPos_nextPage.x += getViewSize().width;
				}
				else if (dx<-getViewSize().width/2)//右翻页
				{
					m_desire_containerPos_nextPage.x -= getViewSize().width;
				}
				else//回到最开始样子
				{
				}
			}
			if (m_desire_containerPos_nextPage.x<minInset.x)
			{
				m_desire_containerPos_nextPage.x += getViewSize().width;
			}
			if (m_desire_containerPos_nextPage.x>maxInset.x)
			{
				m_desire_containerPos_nextPage.x -= getViewSize().width;
			}
		}
		break;
	default:
		{
			//检查手势
			if (m_fNextPageMinScrollDistance<_scrollDistance.y)//上翻页
			{
				m_desire_containerPos_nextPage.y += getViewSize().height;
			}
			else if (-m_fNextPageMinScrollDistance>_scrollDistance.y)//下翻页
			{
				m_desire_containerPos_nextPage.y -= getViewSize().height;
			}
			else
			{
				float dy = m_ended_containerPos_nextPage.y-m_begin_containerPos_nextPage.y;
				if (dy>getViewSize().height/2)//上翻页
				{
					m_desire_containerPos_nextPage.y += getViewSize().height;
				}
				else if (dy<-getViewSize().height/2)//下翻页
				{
					m_desire_containerPos_nextPage.y -= getViewSize().height;
				}
				else//回到最开始样子
				{
				}
			}
			if (m_desire_containerPos_nextPage.y<minInset.y)
			{
				m_desire_containerPos_nextPage.y += getViewSize().width;
			}
			if (m_desire_containerPos_nextPage.y>maxInset.y)
			{
				m_desire_containerPos_nextPage.y -= getViewSize().width;
			}
		}
		break;
	}
}
void WXTableView::nextPageDeaccelerateScrolling(float dt)
{
	if (_dragging)
	{
		this->unschedule(schedule_selector(WXTableView::nextPageDeaccelerateScrolling));
		return;
	}
	CCPoint scrollDistance = CCPoint::ZERO;
	CCPoint oldContainerPos = _container->getPosition();
	CCPoint newContainerPos;
	bool isUnschedule = false;
	switch (this->getDirection())
	{
	case ScrollView::Direction::HORIZONTAL:
		{
			scrollDistance.x = m_fNextPageSpeed*dt;
			if (m_desire_containerPos_nextPage.x-oldContainerPos.x<0)
			{
				scrollDistance.x = -scrollDistance.x;
			}
			newContainerPos = ccpAdd(oldContainerPos, scrollDistance);
			if ((oldContainerPos.x<=m_desire_containerPos_nextPage.x && newContainerPos.x>=m_desire_containerPos_nextPage.x)\
				|| (oldContainerPos.x>=m_desire_containerPos_nextPage.x && newContainerPos.x<=m_desire_containerPos_nextPage.x))
			{
				isUnschedule = true;
			}
		}
		break;
	default:
		{
			scrollDistance.y = m_fNextPageSpeed*dt;
			if (m_desire_containerPos_nextPage.y-oldContainerPos.y<0)
			{
				scrollDistance.y = -scrollDistance.y;
			}
			newContainerPos = ccpAdd(oldContainerPos, scrollDistance);
			if ((oldContainerPos.y<=m_desire_containerPos_nextPage.y && newContainerPos.y>=m_desire_containerPos_nextPage.y)\
				|| (oldContainerPos.y>=m_desire_containerPos_nextPage.y && newContainerPos.y<=m_desire_containerPos_nextPage.y))
			{
				isUnschedule = true;
			}
		}
		break;
	}
	if (isUnschedule)
	{
		this->unschedule(schedule_selector(WXTableView::nextPageDeaccelerateScrolling));
		this->nextpageRelocateContainer(false);
	}
	else
	{
		CCPoint maxInset, minInset;
		if (_bounceable)
		{
			maxInset = _maxInset;
			minInset = _minInset;
		}
		else
		{
			maxInset = this->maxContainerOffset();
			minInset = this->minContainerOffset();
		}

		float newX, newY;
		newX     = MIN(newContainerPos.x, maxInset.x);
		newX     = MAX(newX, minInset.x);
		newY     = MIN(newContainerPos.y, maxInset.y);
		newY     = MAX(newY, minInset.y);
		_container->setPosition(newContainerPos);
		setContentOffset(ccp(newX, newY));
	}
}

void WXTableView::setVerticalFillOrder(TableView::VerticalFillOrder fillOrder)
{
	if (_vordering != fillOrder) {
		_vordering = fillOrder;
		if (_cellsUsed.size() > 0) {
			this->reloadData();
		}
	}
}

void WXTableView::nextpageRelocateContainer(bool animated)
{
	CCPoint oldPoint, min, max;
	float newX, newY;

	min = this->minContainerOffset();
	max = this->maxContainerOffset();

	oldPoint = m_desire_containerPos_nextPage;

	newX     = oldPoint.x;
	newY     = oldPoint.y;
	if (_direction ==  ScrollView::Direction::BOTH || _direction == ScrollView::Direction::HORIZONTAL)
	{
		newX     = MAX(newX, min.x);
		newX     = MIN(newX, max.x);
	}

	if (_direction == ScrollView::Direction::BOTH || _direction ==ScrollView::Direction::VERTICAL)
	{
		newY     = MIN(newY, max.y);
		newY     = MAX(newY, min.y);
	}

	this->setContentOffset(ccp(newX, newY), animated);

	int currentPage = getCurrentPage();
	if (m_pTarget && m_pSelector)
	{
		(m_pTarget->*m_pSelector)(currentPage);
	}
}
int WXTableView::getCurrentPage()
{
	unsigned int cellsCount = _dataSource->numberOfCellsInTableView(this);
	CCSize cellSize = _dataSource->tableCellSizeForIndex(this, 0);//先cell固定大小吧
	int currentLen = 0;
	int currentPage = 0;
	switch (this->getDirection())
	{
	case ScrollView::Direction::HORIZONTAL:
		{
			currentLen = m_desire_containerPos_nextPage.x - m_origin_containerPos_nextPage.x;
			currentPage = fabsf(currentLen)/getViewSize().width;
		}
		break;
	default:
		{
			currentLen = m_desire_containerPos_nextPage.y - m_origin_containerPos_nextPage.y;
			currentPage = fabsf(currentLen)/getViewSize().height;
		}
		break;
	}
	return currentPage;
}
void WXTableView::navigateCellByIdx(unsigned int idx, CCPoint delta, bool animated)
{
	unsigned int cellsCount = _dataSource->numberOfCellsInTableView(this);
	if (idx<0 || idx>=cellsCount)
	{
		return;
	}
	CCSize cellSize = _dataSource->tableCellSizeForIndex(this, 0);//先cell固定大小吧
	CCSize viewSize = getViewSize();
	int offsetX = 0;
	int offsetY = 0;
	CCPoint maxInset, minInset;
	maxInset = this->maxContainerOffset();
	minInset = this->minContainerOffset();
	switch (this->getDirection())
	{
	case ScrollView::Direction::HORIZONTAL:
		{
			offsetX =  minInset.x + idx * cellSize.width + delta.x;
			offsetX = MAX(offsetX, minInset.x);
			offsetX = MIN(offsetX, maxInset.x);
		}
		break;
	default://最底下的cell所在位置为（0,0）
		{
			offsetY = minInset.y + idx * cellSize.height + delta.y;
			offsetY = MAX(offsetY, minInset.y);
			offsetY = MIN(offsetY, maxInset.y);
		}
		break;
	}
	setContentOffset(ccp(offsetX, offsetY), animated);
}
void WXTableView::setNextPageTarget(cocos2d::CCObject* target, SEL_CallFuncI selector)
{
	m_pTarget = target;
	m_pSelector = selector;
}
