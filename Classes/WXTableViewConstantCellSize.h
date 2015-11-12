#pragma once

#include "cocos-ext.h"




class WXTableViewConstantCellSize;

class WXTableViewDelegate : public cocos2d::extension::ScrollViewDelegate
{
public:
    /**
     * Delegate to respond touch event
     *
     * @param table table contains the given cell
     * @param cell  cell that is touched
     */
    virtual void tableCellTouched(WXTableViewConstantCellSize* table, cocos2d::extension::TableViewCell* cell) = 0;

    /**
     * Delegate to respond a table cell press event.
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void tableCellHighlight(WXTableViewConstantCellSize* table, cocos2d::extension::TableViewCell* cell){};

    /**
     * Delegate to respond a table cell release event
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void tableCellUnhighlight(WXTableViewConstantCellSize* table, cocos2d::extension::TableViewCell* cell){};

    /**
     * Delegate called when the cell is about to be recycled. Immediately
     * after this call the cell will be removed from the scene graph and
     * recycled.
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void tableCellWillRecycle(WXTableViewConstantCellSize* table, cocos2d::extension::TableViewCell* cell){};

};
class WXTableViewDataSource
{
public:
    virtual ~WXTableViewDataSource() {}
    /**
     * cell height for a given table.
     *
     * @param table table to hold the instances of Class
     * @return cell size
     */
	virtual cocos2d::Size cellSizeForTable(WXTableViewConstantCellSize *table) {
		return cocos2d::Size::ZERO;
	};
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(WXTableViewConstantCellSize *table, unsigned int idx) = 0;
    /**
     * Returns number of cells in a given table view.
     * 
     * @return number of cells
     */
    virtual unsigned int numberOfCellsInTableView(WXTableViewConstantCellSize *table) = 0;

};

class WXTableViewConstantCellSize : public cocos2d::extension::ScrollView, public cocos2d::extension::ScrollViewDelegate
{
public:
    WXTableViewConstantCellSize();
    virtual ~WXTableViewConstantCellSize();

    /**
     * An intialized table view object
     *
     * @param dataSource data source
     * @param size view size
     * @return table view
     */
    static WXTableViewConstantCellSize* create(WXTableViewDataSource* dataSource, cocos2d::Size size);
    /**
     * An initialized table view object
     *
     * @param dataSource data source;
     * @param size view size
     * @param container parent object for cells
     * @return table view
     */
    static WXTableViewConstantCellSize* create(WXTableViewDataSource* dataSource, cocos2d::Size size, cocos2d::Node *container);
    
    /**
     * data source
     */
    WXTableViewDataSource* getDataSource() { return m_pDataSource; }
    void setDataSource(WXTableViewDataSource* source) { m_pDataSource = source; }
    /**
     * delegate
     */
    WXTableViewDelegate* getDelegate() { return m_pTableViewDelegate; } 
    void setDelegate(WXTableViewDelegate* pDelegate) { m_pTableViewDelegate = pDelegate; }

    /**
     * determines how cell is ordered and filled in the view.
     */
    void setVerticalFillOrder(cocos2d::extension::TableView::VerticalFillOrder order);
    cocos2d::extension::TableView::VerticalFillOrder getVerticalFillOrder();


    bool initWithViewSize(cocos2d::Size size, cocos2d::Node* container = NULL);
    /**
     * Updates the content of the cell at a given index.
     *
     * @param idx index to find a cell
     */
    void updateCellAtIndex(unsigned int idx);
    /**
     * Inserts a new cell at a given index
     *
     * @param idx location to insert
     */
    void insertCellAtIndex(unsigned int idx);
    /**
     * Removes a cell at a given index
     *
     * @param idx index to find a cell
     */
    void removeCellAtIndex(unsigned int idx);
    /**
     * reloads data from data source.  the view will be refreshed.
     */
    void reloadData();
    /**
     * Dequeues a free cell if available. nil if not.
     *
     * @return free cell
     */
    cocos2d::extension::TableViewCell *dequeueCell();

    /**
     * Returns an existing cell at a given index. Returns nil if a cell is nonexistent at the moment of query.
     *
     * @param idx index
     * @return a cell at a given index
     */
    cocos2d::extension::TableViewCell *cellAtIndex(unsigned int idx);


    virtual void scrollViewDidScroll(ScrollView* view);
    virtual void scrollViewDidZoom(ScrollView* view) {}
    
    virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);

protected:
    
    cocos2d::extension::TableViewCell *m_pTouchedCell;
    /**
     * vertical direction of cell filling
     */
    cocos2d::extension::TableView::VerticalFillOrder m_eVordering;
    
    /**
     * index set to query the indexes of the cells used.
     */
    std::set<unsigned int>* m_pIndices;
    //NSMutableIndexSet *indices_;
    /**
     * cells that are currently in the table
     */
    cocos2d::Vector<cocos2d::extension::TableViewCell*> m_cellsUsed;
    /**
     * free list of cells
     */
   cocos2d::Vector<cocos2d::extension::TableViewCell*>  m_cellsFreed;
    /**
     * weak link to the data source object
     */
    WXTableViewDataSource* m_pDataSource;
    /**
     * weak link to the delegate object
     */
    WXTableViewDelegate* m_pTableViewDelegate;

	cocos2d::extension::ScrollView::Direction m_eOldDirection;

    int __indexFromOffset(cocos2d::Point offset);
    unsigned int _indexFromOffset(cocos2d::Point offset);
    cocos2d::Point __offsetFromIndex(unsigned int index);
    cocos2d::Point _offsetFromIndex(unsigned int index);
    

    void _moveCellOutOfSight(cocos2d::extension::TableViewCell *cell);
    void _setIndexForCell(unsigned int index, cocos2d::extension::TableViewCell *cell);
    void _addCellIfNecessary(cocos2d::extension::TableViewCell * cell);
    
public:
	void _updateContentSize();
	CC_SYNTHESIZE(int, moveDelta, MoveDelta);//移动有效间距（像素）
protected:
	cocos2d::Point m_beginPoint;//touchBegan点击点
	cocos2d::Point m_lastPoint;//touchEnded点击点

};
