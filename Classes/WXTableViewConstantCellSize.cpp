#include "WXTableViewConstantCellSize.h"

USING_NS_CC;
USING_NS_CC_EXT;

WXTableViewConstantCellSize* WXTableViewConstantCellSize::create(WXTableViewDataSource* dataSource, Size size)
{
	return WXTableViewConstantCellSize::create(dataSource, size, NULL);
}

WXTableViewConstantCellSize* WXTableViewConstantCellSize::create(WXTableViewDataSource* dataSource, Size size, Node *container)
{
	WXTableViewConstantCellSize *table = new WXTableViewConstantCellSize();
	table->initWithViewSize(size, container);
	table->autorelease();
	table->setDataSource(dataSource);
	table->_updateContentSize();

	table->setMoveDelta(10);
	table->setTouchEnabled(false);

	return table;
}

bool WXTableViewConstantCellSize::initWithViewSize(Size size, Node* container/* = NULL*/)
{
	if (ScrollView::initWithViewSize(size,container))
	{
		m_pIndices        = new std::set<unsigned int>();
		m_eVordering      = TableView::VerticalFillOrder::BOTTOM_UP;
		this->setDirection(ScrollView::Direction::VERTICAL);

		ScrollView::setDelegate(this);
		return true;
	}
	return false;
}

WXTableViewConstantCellSize::WXTableViewConstantCellSize()
	: m_pTouchedCell(NULL)
	, m_pIndices(NULL)
	, m_pDataSource(NULL)
	, m_pTableViewDelegate(NULL)
	, m_eOldDirection(ScrollView::Direction::NONE)
{

}

WXTableViewConstantCellSize::~WXTableViewConstantCellSize()
{
	CC_SAFE_DELETE(m_pIndices);
}

void WXTableViewConstantCellSize::setVerticalFillOrder(TableView::VerticalFillOrder fillOrder)
{
	if (m_eVordering != fillOrder) {
		m_eVordering = fillOrder;
		if (m_cellsUsed.size() > 0) {
			this->reloadData();
		}
	}
}

TableView::VerticalFillOrder WXTableViewConstantCellSize::getVerticalFillOrder()
{
	return m_eVordering;
}

void WXTableViewConstantCellSize::reloadData()
{
	m_eOldDirection = ScrollView::Direction::NONE;
	for(const auto &cell : m_cellsUsed)
	{

		if(m_pTableViewDelegate != NULL) {
			m_pTableViewDelegate->tableCellWillRecycle(this, cell);
		}

		m_cellsFreed.pushBack(cell);
		cell->reset();
		if (cell->getParent() == this->getContainer())
		{
			this->getContainer()->removeChild(cell, true);
		}
	}

	m_pIndices->clear();
	m_cellsUsed.clear();

	this->_updateContentSize();
	if (m_pDataSource->numberOfCellsInTableView(this) > 0)
	{
		this->scrollViewDidScroll(this);
	}
}

TableViewCell *WXTableViewConstantCellSize::cellAtIndex(unsigned int idx)
{
	TableViewCell *found = NULL;

	if (m_pIndices->find(idx) != m_pIndices->end())
	{
		found = m_cellsUsed.at(idx);
	}

	return found;
}

void WXTableViewConstantCellSize::updateCellAtIndex(unsigned int idx)
{
	if (idx == CC_INVALID_INDEX)
	{
		return;
	}
	unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
	if (0 == uCountOfItems || idx > uCountOfItems-1)
	{
		return;
	}

	TableViewCell* cell = this->cellAtIndex(idx);
	if (cell)
	{
		this->_moveCellOutOfSight(cell);
	} 
	cell = m_pDataSource->tableCellAtIndex(this, idx);
	this->_setIndexForCell(idx, cell);
	this->_addCellIfNecessary(cell);
}

void WXTableViewConstantCellSize::insertCellAtIndex(unsigned  int idx)
{
	if (idx == CC_INVALID_INDEX)
	{
		return;
	}

	unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
	if (0 == uCountOfItems || idx > uCountOfItems-1)
	{
		return;
	}

	TableViewCell* cell = NULL;
	int newIdx = 0;

	cell = m_cellsUsed.at(idx);
	if (cell) 
	{
		newIdx = m_cellsUsed.getIndex(cell);
		for (unsigned int i=newIdx; i<m_cellsUsed.size(); i++)
		{
			cell = (TableViewCell*)m_cellsUsed.at(i);
			this->_setIndexForCell(cell->getIdx()+1, cell);
		}
	}

	//   [m_pIndices shiftIndexesStartingAtIndex:idx by:1];

	//insert a new cell
	cell = m_pDataSource->tableCellAtIndex(this, idx);
	this->_setIndexForCell(idx, cell);
	this->_addCellIfNecessary(cell);

	this->_updateContentSize();
}

void WXTableViewConstantCellSize::removeCellAtIndex(unsigned int idx)
{
	if (idx == CC_INVALID_INDEX)
	{
		return;
	}

	unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
	if (0 == uCountOfItems || idx > uCountOfItems-1)
	{
		return;
	}

	unsigned int newIdx = 0;

	TableViewCell* cell = this->cellAtIndex(idx);
	if (!cell) {
		return;
	}

	newIdx = m_cellsUsed.getIndex(cell);

	//remove first
	this->_moveCellOutOfSight(cell);

	m_pIndices->erase(idx);
	//    [m_pIndices shiftIndexesStartingAtIndex:idx+1 by:-1];
	for (unsigned int i=m_cellsUsed.size()-1; i > newIdx; i--) {
		cell = (TableViewCell*)m_cellsUsed.at(i);
		this->_setIndexForCell(cell->getIdx()-1, cell);
	}
}

TableViewCell *WXTableViewConstantCellSize::dequeueCell()
{
	TableViewCell *cell;

	if (m_cellsFreed.size() == 0) {
		cell = NULL;
	} else {
		cell = (TableViewCell*)m_cellsFreed.at(0);
		cell->retain();
		m_cellsFreed.erase(0);
		cell->autorelease();
	}
	return cell;
}

void WXTableViewConstantCellSize::_addCellIfNecessary(TableViewCell * cell)
{
	if (cell->getParent() != this->getContainer())
	{
		this->getContainer()->addChild(cell);
	}
	m_cellsUsed.pushBack(cell);
	m_pIndices->insert(cell->getIdx());
	// [m_pIndices addIndex:cell.idx];
}

void WXTableViewConstantCellSize::_updateContentSize()
{
	Size     size, cellSize;
	unsigned int cellCount;

	cellSize  = m_pDataSource->cellSizeForTable(this);
	cellCount = m_pDataSource->numberOfCellsInTableView(this);

	switch (this->getDirection())
	{
	case ScrollView::Direction::HORIZONTAL:
		size = Size(cellCount * cellSize.width, cellSize.height);
		break;
	default:
		size = Size(cellSize.width, cellCount * cellSize.height);
		break;
	}
	this->setContentSize(size);

	if (m_eOldDirection != _direction)
	{
		if (_direction == ScrollView::Direction::HORIZONTAL)
		{
			this->setContentOffset(Vec2(0,0));
		}
		else
		{
			this->setContentOffset(Vec2(0,this->minContainerOffset().y));
		}
		m_eOldDirection = _direction;
	}

}

Point WXTableViewConstantCellSize::_offsetFromIndex(unsigned int index)
{
	Point offset = this->__offsetFromIndex(index);

	const Size cellSize = m_pDataSource->cellSizeForTable(this);
	if (m_eVordering == TableView::VerticalFillOrder::TOP_DOWN) {
		offset.y = this->getContainer()->getContentSize().height - offset.y - cellSize.height;
	}
	return offset;
}

Point WXTableViewConstantCellSize::__offsetFromIndex(unsigned int index)
{
	Point offset;
	Size  cellSize;

	cellSize = m_pDataSource->cellSizeForTable(this);
	switch (this->getDirection()) {
	case ScrollView::Direction::HORIZONTAL:
		offset = Vec2(cellSize.width * index, 0.0f);
		break;
	default:
		offset = Vec2(0.0f, cellSize.height * index);
		break;
	}

	return offset;
}

unsigned int WXTableViewConstantCellSize::_indexFromOffset(Point offset)
{
	int index = 0;
	const int maxIdx = m_pDataSource->numberOfCellsInTableView(this)-1;

	const Size cellSize = m_pDataSource->cellSizeForTable(this);
	if (m_eVordering == TableView::VerticalFillOrder::TOP_DOWN) {
		offset.y = this->getContainer()->getContentSize().height - offset.y - cellSize.height;
	}
	index = MAX(0, this->__indexFromOffset(offset));
	if (index >maxIdx)
	{
		index = CC_INVALID_INDEX;
	}

	return index;
}

int WXTableViewConstantCellSize::__indexFromOffset(Point offset)
{
	int  index = 0;
	Size     cellSize;

	cellSize = m_pDataSource->cellSizeForTable(this);

	switch (this->getDirection()) {
	case ScrollView::Direction::HORIZONTAL:
		index = offset.x/cellSize.width;
		break;
	default:
		index = offset.y/cellSize.height;
		break;
	}

	return index;
}

void WXTableViewConstantCellSize::_moveCellOutOfSight(TableViewCell *cell)
{
	if(m_pTableViewDelegate != NULL) {
		m_pTableViewDelegate->tableCellWillRecycle(this, cell);
	}

	m_cellsFreed.pushBack(cell);
	m_cellsUsed.eraseObject(cell);
	m_pIndices->erase(cell->getIdx());
	// [m_pIndices removeIndex:cell.idx];
	cell->reset();
	if (cell->getParent() == this->getContainer()) {
		this->getContainer()->removeChild(cell, true);;
	}
}

void WXTableViewConstantCellSize::_setIndexForCell(unsigned int index, TableViewCell *cell)
{
	cell->setAnchorPoint(Vec2(0.0f, 0.0f));
	cell->setPosition(this->_offsetFromIndex(index));
	cell->setIdx(index);
}

void WXTableViewConstantCellSize::scrollViewDidScroll(ScrollView* view)
{
	unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
	if (0 == uCountOfItems)
	{
		return;
	}

	if(m_pTableViewDelegate != NULL) {
		m_pTableViewDelegate->scrollViewDidScroll(this);
	}

	unsigned int startIdx = 0, endIdx = 0, idx = 0, maxIdx = 0;
	Point offset = this->getContentOffset()*-1;
	maxIdx = MAX(uCountOfItems-1, 0);
	const Size cellSize = m_pDataSource->cellSizeForTable(this);

	if (m_eVordering == TableView::VerticalFillOrder::TOP_DOWN)
	{
		offset.y = offset.y + _viewSize.height/this->getContainer()->getScaleY() - cellSize.height;
	}
	startIdx = this->_indexFromOffset(offset);
	if (startIdx == CC_INVALID_INDEX)
	{
		startIdx = uCountOfItems - 1;
	}

	if (m_eVordering == TableView::VerticalFillOrder::TOP_DOWN)
	{
		offset.y -= _viewSize.height/this->getContainer()->getScaleY();
	}
	else 
	{
		offset.y += _viewSize.height/this->getContainer()->getScaleY();
	}
	offset.x += _viewSize.width/this->getContainer()->getScaleX();

	endIdx   = this->_indexFromOffset(offset);   
	if (endIdx == CC_INVALID_INDEX)
	{
		endIdx = uCountOfItems - 1;
	}

#if 0 // For Testing.
	CCObject* pObj;
	int i = 0;
	CCARRAY_FOREACH(m_pCellsUsed, pObj)
	{
		CCTableViewCell* pCell = (CCTableViewCell*)pObj;
		CCLog("cells Used index %d, value = %d", i, pCell->getIdx());
		i++;
	}
	CCLog("---------------------------------------");
	i = 0;
	CCARRAY_FOREACH(m_pCellsFreed, pObj)
	{
		CCTableViewCell* pCell = (CCTableViewCell*)pObj;
		CCLog("cells freed index %d, value = %d", i, pCell->getIdx());
		i++;
	}
	CCLog("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
#endif

	if (m_cellsUsed.size() > 0)
	{
		TableViewCell* cell = (TableViewCell*)m_cellsUsed.at(0);

		idx = cell->getIdx();
		while(idx <startIdx)
		{
			this->_moveCellOutOfSight(cell);
			if (m_cellsUsed.size()> 0)
			{
				cell = (TableViewCell*)m_cellsUsed.at(0);
				idx = cell->getIdx();    
			}
			else
			{
				break;
			}
		}
	}
	if (m_cellsUsed.size() > 0)
	{
		TableViewCell *cell = (TableViewCell*)m_cellsUsed.at(m_cellsUsed.size()-1);
		idx = cell->getIdx();

		while(idx <= maxIdx && idx > endIdx)
		{
			this->_moveCellOutOfSight(cell);
			if (m_cellsUsed.size() > 0)
			{
				cell = (TableViewCell*)m_cellsUsed.at(m_cellsUsed.size()-1);
				idx = cell->getIdx();

			}
			else
			{
				break;
			}
		}
	}

	for (unsigned int i=startIdx; i <= endIdx; i++)
	{
		//if ([m_pIndices containsIndex:i])
		if (m_pIndices->find(i) != m_pIndices->end())
		{
			continue;
		}
		this->updateCellAtIndex(i);
	}
}

void WXTableViewConstantCellSize::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible()) {
		return;
	}

	if (m_pTouchedCell){
		Rect bb = this->boundingBox();
		bb.origin = _parent->convertToWorldSpace(bb.origin);

		if (bb.containsPoint(pTouch->getLocation()) && m_pTableViewDelegate != NULL)
		{
			m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
			m_pTableViewDelegate->tableCellTouched(this, m_pTouchedCell);
		}

		m_pTouchedCell = NULL;
	}

	ScrollView::onTouchEnded(pTouch, pEvent);
}

bool WXTableViewConstantCellSize::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible()) {
		return false;
	}

	bool touchResult = ScrollView::onTouchBegan(pTouch, pEvent);

	if(_touches.size() == 1) {
		unsigned int        index;
		Point           point;

		point = this->getContainer()->convertTouchToNodeSpace(pTouch);

		if (m_eVordering == TableView::VerticalFillOrder::TOP_DOWN) {
			Size cellSize = m_pDataSource->cellSizeForTable(this);
			point.y -= cellSize.height;
		}

		index = this->_indexFromOffset(point);
		if (index == CC_INVALID_INDEX)
		{
			m_pTouchedCell = NULL;
		}
		else
		{
			m_pTouchedCell  = this->cellAtIndex(index);
		}

		if (m_pTouchedCell && m_pTableViewDelegate != NULL) {
			m_pTableViewDelegate->tableCellHighlight(this, m_pTouchedCell);
		}
	}
	else if(m_pTouchedCell) {
		if(m_pTableViewDelegate != NULL) {
			m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
		}

		m_pTouchedCell = NULL;
	}

	m_beginPoint = pTouch->getLocation();

	return touchResult;
}

void WXTableViewConstantCellSize::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	ScrollView::onTouchMoved(pTouch, pEvent);

	m_lastPoint = pTouch->getLocation();
	bool isTouchMove = true;
	float dx = m_beginPoint.x - m_lastPoint.x;
	float dy = m_beginPoint.y - m_lastPoint.y;
	if ((-moveDelta < dx &&  dx < moveDelta) && (-moveDelta < dy && dy < moveDelta))
	{
		isTouchMove = false;
	}
	if (m_pTouchedCell && isTouchMoved() && isTouchMove)
	{
		if(m_pTableViewDelegate != NULL)
		{
			m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
		}

		m_pTouchedCell = NULL;
	}
}

void WXTableViewConstantCellSize::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
	ScrollView::onTouchCancelled(pTouch, pEvent);

	if (m_pTouchedCell) {
		if(m_pTableViewDelegate != NULL) {
			m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
		}

		m_pTouchedCell = NULL;
	}
}