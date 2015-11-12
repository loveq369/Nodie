#include "WXGrid.h"
#include "WXUIDefine.h"
USING_NS_CC;

#define  _MAX_PATH_ 260
//////////////////////////////////////////////////////////////////////////

WXGridBase::WXGridBase(void)
{
	m_iconSprite = NULL;
	m_centerLabel = NULL;
	m_numLabel = NULL;
	m_coldTimer = NULL;
	m_cdAction = NULL;
	m_pListener = NULL;
	m_pfnSelector = NULL;
	m_gridData = new tGridData();
	m_isDrag = true;
	m_iconSize = CCSizeMake(64, 64);
	m_bgSize = CCSizeMake(70, 70);
	GridResItem item;
	m_resItems[GRID_RES_ITEM_TYPE_CD] = item;
}
WXGridBase::~WXGridBase(void)
{
	CC_SAFE_DELETE(m_gridData);
}
WXGridBase* WXGridBase::createWithSpriteFrameName(const char* cdName)
{
	WXGridBase *pRet = new WXGridBase();
	if (pRet)
	{
		if (pRet->initWithSpriteFrameName(cdName))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXGridBase* WXGridBase::createWithSpriteName(const char* cdName)
{
	WXGridBase *pRet = new WXGridBase();
	if (pRet)
	{
		if (pRet->initWithSpriteName(cdName))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool WXGridBase::initWithSpriteName(const char* cdName)
{
	setContentSize(m_bgSize);
	m_resItems[GRID_RES_ITEM_TYPE_CD].m_isFrameName = false;
	if (cdName) m_resItems[GRID_RES_ITEM_TYPE_CD].m_filename = cdName;

	return true;
}
bool WXGridBase::initWithSpriteFrameName(const char* cdName)
{
	setContentSize(m_bgSize);
	m_resItems[GRID_RES_ITEM_TYPE_CD].m_isFrameName = true;
	if (cdName) m_resItems[GRID_RES_ITEM_TYPE_CD].m_filename = cdName;

	return true;
}
void WXGridBase::updateGrid(tGridData& gridData)
{
	this->m_gridData->id = gridData.id;
	m_gridData->idStr = gridData.idStr;
	setIcon(gridData.url.c_str());
	setGridNum(gridData.num);
	setGridPos(gridData.pos);
	setGridType(gridData.type);
	setGridSlot(gridData.slot);
	setGridStatus(gridData.status);
	setIsActive(gridData.isActive);
	setGridSrc(gridData.src);
}
void WXGridBase::clearGrid()
{
	m_gridData->id = 0;
	setIcon();
	setGridNum(0);
	setGridPos(0);
	setGridType(0);
	setGridSlot(0);
	setGridStatus(0);
	setIsActive(true);
	setGridSrc(0);
}
void WXGridBase::showNumLabel(bool isShow, const cocos2d::ccColor3B& color)
{
	if (!m_numLabel && isShow)
	{
		m_numLabel = CCLabelTTF::create(
			"0", 
			FONT_NAME_HELVETICA, 
			FONT_SIZE_20);
		m_numLabel->setAnchorPoint(ccp(1,0));
		m_numLabel->setColor(color);
		m_numLabel->setPosition(ccp(getContentSize().width/2, -getContentSize().height/2));
		addChild(m_numLabel, grid_zorder_num);
	}
	if (m_numLabel) m_numLabel->setVisible(isShow);
}
void WXGridBase::startCD(int cdTotal, int cdCount)
{
	if (!m_coldTimer)
	{
		setCDSprite(m_resItems[GRID_RES_ITEM_TYPE_CD].m_filename.c_str(), m_resItems[GRID_RES_ITEM_TYPE_CD].m_isFrameName);
	}
	if (m_coldTimer)
	{
		m_coldTimer->setVisible(true);
		m_coldTimer->stopAllActions();
		CCProgressFromTo* cdTo = CCProgressFromTo::create(cdTotal/1000.0f, (cdTotal-cdCount)*100.0f/cdTotal, 0);
		CCCallFunc* cdCallback = CCCallFunc::create(this, callfunc_selector(WXGridBase::cdOverCallback));
		m_cdAction = m_coldTimer->runAction(CCSequence::create(cdTo, cdCallback, NULL));
	}
}
void WXGridBase::cdOverCallback()
{
	m_coldTimer->setVisible(false);
	m_coldTimer->stopAllActions();
	m_cdAction = NULL;
}
tGridData& WXGridBase::getGridData()
{
	return *m_gridData;
}
void WXGridBase::setIcon(const char* fileName)
{
	if (fileName==NULL || 0==strcmp(fileName,""))
	{
		m_gridData->url = "";
		if (m_iconSprite) m_iconSprite->setVisible(false);
		return;
	}
	m_gridData->url = fileName;
	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(fileName);
	if (!texture)
	{
		if (m_iconSprite) m_iconSprite->setVisible(false);
		return;
	}
	setIcon(texture);
}
void WXGridBase::setIcon(CCTexture2D* texture)
{
	if (!texture)
	{
		if (m_iconSprite) m_iconSprite->setVisible(false);
		return;
	}
	if (!m_iconSprite)
	{
		m_iconSprite = CCSprite::createWithTexture(texture);
		addChild(m_iconSprite, grid_zorder_icon);
	}
	else
	{
		m_iconSprite->setTexture(texture);
	}
	m_iconSprite->setScaleX(m_iconSize.width/m_iconSprite->getContentSize().width);
	m_iconSprite->setScaleY(m_iconSize.height/m_iconSprite->getContentSize().height);

	m_iconSprite->setVisible(true);
}
CCSprite* WXGridBase::getIcon()
{
	return m_iconSprite;
}
void WXGridBase::setGridType(int gridType)
{
	m_gridData->type = gridType;
}
void WXGridBase::setGridSrc(int gridSrc)
{
	m_gridData->src = gridSrc;
}
void WXGridBase::setGridNum(int gridNum)
{
	if (m_gridData->num!=gridNum)
	{
		m_gridData->num = gridNum;
		if (gridNum>0)
		{
			showNumLabel(true);
			char str[_MAX_PATH_];
			memset(str, 0, sizeof(str));
			sprintf(str, "%d", m_gridData->num);
			m_numLabel->setString(str);
		}
		else
		{
			showNumLabel(false);
		}
	}
}
void WXGridBase::setGridPos(int pos)
{
	m_gridData->pos = pos;
}

void WXGridBase::setGridSlot(int slot)
{
	m_gridData->slot = slot;

}
void WXGridBase::setGridStatus(int status)
{
	m_gridData->status = status;
}

void WXGridBase::setIsDrag(bool isDrag)
{
	this->m_isDrag = isDrag;
}
void WXGridBase::setIsActive(bool isActive)
{
	if (m_gridData->isActive!=isActive)
	{
		m_gridData->isActive = isActive;
		if (!m_iconSprite)
		{
			return;
		}
		if (isActive)
		{
			m_iconSprite->setColor(ccc3(0xff, 0xff, 0xff));
		}
		else
		{
			m_iconSprite->setColor(ccc3(0x50, 0x50, 0x50));
		}
	}
}
void WXGridBase::setIconSpriteOpacity(int val)
{
	if (m_iconSprite)
	{
		m_iconSprite->setOpacity(val);
	}
}
void WXGridBase::setCenterLabel(const char* str, const ccColor3B& color)
{
	if (str==NULL || std::string(str)=="")
	{
		if (m_centerLabel) m_centerLabel->setVisible(false);
	}
	else
	{
		if (!m_centerLabel)
		{
			m_centerLabel = CCLabelTTF::create("", FONT_NAME_HELVETICA, FONT_SIZE_20, CCSize::ZERO, kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter);
			addChild(m_centerLabel, grid_zorder_center);
		}
		m_centerLabel->setString(str);
		m_centerLabel->setColor(color);
		m_centerLabel->setVisible(true);
	}
}
bool WXGridBase::onTouchBegan(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent)
{
	if (!isShow())
	{
		return false;
	}
	if (onTouch(pTouch, pEvent))
	{
		selected(true);
		return true;
	}
	return false;
}
void WXGridBase::onTouchMoved(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent)
{
}
bool WXGridBase::onTouchEnded(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent)
{
	if (!isShow())
	{
		return false;
	}
	if (onTouch(pTouch, pEvent))
	{
		selected(false);
		activate();
		return true;
	}
	return false;
}
void WXGridBase::onTouchCancelled(cocos2d::CCTouch*pTouch,cocos2d::CCEvent*pEvent)
{
	selected(false);
}
void WXGridBase::setCDSprite(const char* filename, bool isFrameName)
{
	m_resItems[GRID_RES_ITEM_TYPE_CD].m_filename = filename;
	m_resItems[GRID_RES_ITEM_TYPE_CD].m_isFrameName = isFrameName;
	CCSprite* newSprite = NULL;
	if (filename && m_resItems[GRID_RES_ITEM_TYPE_CD].m_filename!="")
	{
		if (isFrameName)
			newSprite = CCSprite::createWithSpriteFrameName(filename);
		else
			newSprite = CCSprite::create(filename);
	}
	if (newSprite)
	{
		if (!m_coldTimer)
		{
			m_coldTimer = CCProgressTimer::create(newSprite);
			m_coldTimer->setType(kCCProgressTimerTypeRadial);
			m_coldTimer->setReverseProgress(true);
			addChild(m_coldTimer, grid_zorder_cd);
		}
		else
		{
			m_coldTimer->setSprite(newSprite);
		}
	}
}
void WXGridBase::setBgSize(cocos2d::CCSize var)
{
	if (var.width==m_bgSize.width && var.height==m_bgSize.height)
	{
		return;
	}
	m_bgSize = var;
	setContentSize(var);
}
void WXGridBase::setIconSize(cocos2d::CCSize var)
{
	if (var.width==m_iconSize.width && var.height==m_iconSize.height)
	{
		return;
	}
	m_iconSize = var;
	if (m_iconSprite)
	{
		m_iconSprite->setScaleX(var.width/m_iconSprite->getContentSize().width);
		m_iconSprite->setScaleY(var.height/m_iconSprite->getContentSize().height);
	}
	if (m_coldTimer)
	{
		m_coldTimer->setScaleX(var.width/m_coldTimer->getContentSize().width);
		m_coldTimer->setScaleY(var.height/m_coldTimer->getContentSize().height);
	}
}
CCSize WXGridBase::getBgSize()
{
	return m_bgSize;
}
CCSize WXGridBase::getIconSize()
{
	return m_iconSize;
}

bool WXGridBase::isCDing()
{
	if (m_cdAction)
	{
		return true;
	}
	return false;
}

void WXGridBase::activate()
{
	if (m_pListener && m_pfnSelector)
	{
		(m_pListener->*m_pfnSelector)(this);
	}
}

void WXGridBase::selected( bool var )
{

}

bool WXGridBase::onTouch( cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent )
{
	CCPoint convertedLocation = convertTouchToNodeSpace(pTouch);
	CCRect r = rect();
	r.origin = CCPoint::ZERO;
	if (r.containsPoint(convertedLocation))
	{
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
WXGrid::WXGrid(void)
{
	m_innerSprite = NULL;
	m_innerColor = ccc3(255, 255, 0);
	m_innerSize = CCSize::ZERO;
	m_outerSprite = NULL;
	m_outerColor = ccc3(255, 255, 0);
	m_outerSize = CCSize::ZERO;
	m_isLock = false;
	m_bgSprite = NULL;
	m_lockSprite = NULL;
	m_bindingSprite = NULL;
	GridResItem resItem;
	m_resItems[GRID_RES_ITEM_TYPE_BG] = resItem;
	m_resItems[GRID_RES_ITEM_TYPE_LOCK] = resItem;
	m_resItems[GRID_RES_ITEM_TYPE_BINDING] = resItem;
	m_resItems[GRID_RES_ITEM_TYPE_INNER] = resItem;
	m_resItems[GRID_RES_ITEM_TYPE_OUTTER] = resItem;
}
WXGrid::~WXGrid(void)
{
}
WXGrid* WXGrid::createWithSpriteFrameName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName)
{
	WXGrid *pRet = new WXGrid();
	if (pRet)
	{
		if (pRet->initWithSpriteFrameName(bgName, lockName, cdName, bindingName, innerName, outerName))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXGrid* WXGrid::createWithSpriteName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName)
{
	WXGrid *pRet = new WXGrid();
	if (pRet)
	{
		if (pRet->initWithSpriteName(bgName, lockName, cdName, bindingName, innerName, outerName))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool WXGrid::initWithSpriteName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName)
{
	WXGridBase::initWithSpriteName(cdName);

	m_resItems[GRID_RES_ITEM_TYPE_BG].m_isFrameName = false;
	m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_isFrameName = false;
	m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_isFrameName = false;
	m_resItems[GRID_RES_ITEM_TYPE_INNER].m_isFrameName = false;
	m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_isFrameName = false;

	if (bgName) m_resItems[GRID_RES_ITEM_TYPE_BG].m_filename = bgName;
	if (lockName) m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_filename = lockName;
	if (bindingName) m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_filename = bindingName;
	if (innerName) m_resItems[GRID_RES_ITEM_TYPE_INNER].m_filename = innerName;
	if (outerName) m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_filename = outerName;

	setIsLock(false);
		
	return true;
}
bool WXGrid::initWithSpriteFrameName(const char* bgName, const char* lockName, const char* cdName, const char* bindingName, const char* innerName, const char* outerName)
{
	WXGridBase::initWithSpriteFrameName(cdName);

	m_resItems[GRID_RES_ITEM_TYPE_BG].m_isFrameName = true;
	m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_isFrameName = true;
	m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_isFrameName = true;
	m_resItems[GRID_RES_ITEM_TYPE_INNER].m_isFrameName = true;
	m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_isFrameName = true;

	if (bgName) m_resItems[GRID_RES_ITEM_TYPE_BG].m_filename = bgName;
	if (lockName) m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_filename = lockName;
	if (bindingName) m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_filename = bindingName;
	if (innerName) m_resItems[GRID_RES_ITEM_TYPE_INNER].m_filename = innerName;
	if (outerName) m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_filename = outerName;

	setIsLock(false);

	return true;
}
void WXGrid::updateGrid(tGridData& gridData)
{
	WXGridBase::updateGrid(gridData);
	setIsBinding(gridData.isBinding);
}
void WXGrid::clearGrid()
{
	WXGridBase::clearGrid();
	setIsBinding(false);
}
void WXGrid::showColorRect(bool isShow, int type)
{
	switch (type)
	{
	case GRID_RECT_TYPE_OUTER:
		{
			if (!m_outerSprite && isShow && m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_filename!="")
			{
				if (m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_isFrameName)
					m_outerSprite = CCSprite::createWithSpriteFrameName(m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_filename.c_str());
				else
					m_outerSprite = CCSprite::create(m_resItems[GRID_RES_ITEM_TYPE_OUTTER].m_filename.c_str());
				m_outerSprite->setColor(m_outerColor);
				addChild(m_outerSprite, grid_zorder_outer);

				if (m_outerSize.equals(CCSize::ZERO))
					m_outerSize = CCSizeMake(m_bgSize.width, m_bgSize.height);
				setColorRectSize(m_outerSize, type);
			}
			if (m_outerSprite) m_outerSprite->setVisible(isShow);
		}
		break;
	case GRID_RECT_TYPE_INNER:
		{
			if (!m_innerSprite && isShow && m_resItems[GRID_RES_ITEM_TYPE_INNER].m_filename!="")
			{
				if (m_resItems[GRID_RES_ITEM_TYPE_INNER].m_isFrameName)
					m_innerSprite = CCSprite::createWithSpriteFrameName(m_resItems[GRID_RES_ITEM_TYPE_INNER].m_filename.c_str());
				else
					m_innerSprite = CCSprite::create(m_resItems[GRID_RES_ITEM_TYPE_INNER].m_filename.c_str());
				m_innerSprite->setColor(m_innerColor);
				addChild(m_innerSprite, grid_zorder_inner);

				if (m_innerSize.equals(CCSize::ZERO))
					m_innerSize = CCSizeMake(m_iconSize.width, m_iconSize.height);
				setColorRectSize(m_innerSize, type);
			}
			if (m_innerSprite) m_innerSprite->setVisible(isShow);
		}
		break;
	}
}
void WXGrid::setColorRectSize(const cocos2d::CCSize& size, int type)
{
	switch (type)
	{
	case GRID_RECT_TYPE_OUTER:
		{
			m_outerSize = size;
			if (m_outerSprite)
			{
				CCSize content = m_outerSprite->getContentSize();
				m_outerSprite->setScaleX(size.width/content.width);
				m_outerSprite->setScaleY(size.height/content.height);
			}
		}
		break;
	case GRID_RECT_TYPE_INNER:
		{
			m_innerSize = size;
			if (m_innerSprite)
			{
				CCSize content = m_innerSprite->getContentSize();
				m_innerSprite->setScaleX(size.width/content.width);
				m_innerSprite->setScaleY(size.height/content.height);
			}
		}
		break;
	}
}
void WXGrid::setColorRectColor(const ccColor3B& color, int type)
{
	switch (type)
	{
	case GRID_RECT_TYPE_OUTER:
		{
			m_outerColor = color;
			if (m_outerSprite) m_outerSprite->setColor(color);
		}
		break;
	case GRID_RECT_TYPE_INNER:
		{
			m_innerColor = color;
			if (m_innerSprite) m_innerSprite->setColor(color);
		}
		break;
	}
}
void WXGrid::setIsLock(bool isLock)
{
	this->m_isLock = isLock;
	if (this->m_isLock)
	{
		setLockSprite(m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_filename.c_str(), m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_isFrameName);
		if (m_lockSprite)m_lockSprite->setVisible(true);
		if (m_bgSprite) m_bgSprite->setVisible(false);
		if (m_iconSprite) m_iconSprite->setVisible(false);
	}
	else
	{
		setBGSprite(m_resItems[GRID_RES_ITEM_TYPE_BG].m_filename.c_str(), m_resItems[GRID_RES_ITEM_TYPE_BG].m_isFrameName);
		if (m_lockSprite) m_lockSprite->setVisible(false);
		if (m_bgSprite) m_bgSprite->setVisible(true);
		if (m_iconSprite) m_iconSprite->setVisible(true);
	}
}
void WXGrid::setIsBinding(bool isBinding)
{
	if (m_gridData->isBinding!=isBinding)
	{
		m_gridData->isBinding = isBinding;
		if (isBinding)
		{
			if (!m_bindingSprite)
			{
				setBindingSprite(m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_filename.c_str(), m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_isFrameName);
			}
			if (m_bindingSprite) m_bindingSprite->setVisible(true);
		}
		else
		{
			if (m_bindingSprite) m_bindingSprite->setVisible(false);
		}
	}
}
void WXGrid::setBGSprite(const char* filename, bool isFrameName)
{
	m_resItems[GRID_RES_ITEM_TYPE_BG].m_filename = filename;
	m_resItems[GRID_RES_ITEM_TYPE_BG].m_isFrameName = isFrameName;
	CCSprite* newSprite = NULL;
	if (filename && filename!="")
	{
		if (isFrameName)
			newSprite = CCSprite::createWithSpriteFrameName(filename);
		else
			newSprite = CCSprite::create(filename);
		if (newSprite)
		{
			newSprite->setScaleX(m_bgSize.width/newSprite->getContentSize().width);
			newSprite->setScaleY(m_bgSize.height/newSprite->getContentSize().height);
			addChild(newSprite, grid_zorder_bg);
		}
	}
	if (m_bgSprite)
	{
		removeChild(m_bgSprite, true);
	}
	m_bgSprite = newSprite;
}
void WXGrid::setLockSprite(const char* filename, bool isFrameName)
{
	m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_filename = filename;
	m_resItems[GRID_RES_ITEM_TYPE_LOCK].m_isFrameName = isFrameName;
	CCSprite* newSprite = NULL;
	if (filename && filename!="")
	{
		if (isFrameName)
			newSprite = CCSprite::createWithSpriteFrameName(filename);
		else
			newSprite = CCSprite::create(filename);
		if (newSprite)
		{
			newSprite->setScaleX(m_bgSize.width/newSprite->getContentSize().width);
			newSprite->setScaleY(m_bgSize.height/newSprite->getContentSize().height);
			addChild(newSprite, grid_zorder_lock);
		}
	}
	if (m_lockSprite)
	{
		removeChild(m_lockSprite, true);
	}
	m_lockSprite = newSprite;
}
void WXGrid::setBindingSprite(const char* filename, bool isFrameName)
{
	m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_filename = filename;
	m_resItems[GRID_RES_ITEM_TYPE_BINDING].m_isFrameName = isFrameName;
	CCSprite* newSprite = NULL;
	if (filename && filename!="")
	{
		if (isFrameName)
			newSprite = CCSprite::createWithSpriteFrameName(filename);
		else
			newSprite = CCSprite::create(filename);
		if (newSprite)
		{
			newSprite->setPosition(ccp((newSprite->getContentSize().width-m_iconSize.width)/2, (m_iconSize.height-newSprite->getContentSize().height)/2));
			addChild(newSprite, grid_zorder_binding);
		}
	}
	if (m_bindingSprite)
	{
		removeChild(m_bindingSprite, true);
	}
	m_bindingSprite = newSprite;
}
void WXGrid::setBgSize(cocos2d::CCSize var)
{
	if (var.width==m_bgSize.width && var.height==m_bgSize.height)
	{
		return;
	}
	m_bgSize = var;
	setContentSize(var);
	if (m_bgSprite)
	{
		m_bgSprite->setScaleX(var.width/m_bgSprite->getContentSize().width);
		m_bgSprite->setScaleY(var.height/m_bgSprite->getContentSize().height);
	}
	if (m_lockSprite)
	{
		m_lockSprite->setScaleX(var.width/m_lockSprite->getContentSize().width);
		m_lockSprite->setScaleY(var.height/m_lockSprite->getContentSize().height);
	}
}

void WXGrid::selected()
{
	showColorRect(true);
}

void WXGrid::unselected()
{
	showColorRect(false);
}

