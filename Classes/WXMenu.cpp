#include "WXMenu.h"
#include "WXUIDefine.h"
#include "WXSimpleButton.h"
USING_NS_CC;

	static std::vector<unsigned int> ccarray_to_std_vector(CCArray* pArray)
{
	std::vector<unsigned int> ret;
	CCObject* pObj;
	CCARRAY_FOREACH(pArray, pObj)
	{
		CCInteger* pInteger = (CCInteger*)pObj;
		ret.push_back((unsigned int)pInteger->getValue());
	}
	return ret;
}

#define kDefaultPadding	5


WXMenu* WXMenu::create()
{
	return WXMenu::create(NULL, NULL);
}

WXMenu* WXMenu::create(WXSimpleButton* item, ...)
{
	va_list args;
	va_start(args,item);

	WXMenu *pRet = WXMenu::createWithItems(item, args);

	va_end(args);
	return pRet;
}

WXMenu* WXMenu::createWithArray(CCArray* pArrayOfItems)
{
	WXMenu *pRet = new WXMenu();
	if (pRet && pRet->initWithArray(pArrayOfItems))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

WXMenu* WXMenu::createWithItems(WXSimpleButton* item, va_list args)
{
	CCArray* pArray = NULL;
	if( item ) 
	{
		pArray = CCArray::create(item, NULL);
		WXSimpleButton *i = va_arg(args, WXSimpleButton*);
		while(i) 
		{
			pArray->addObject(i);
			i = va_arg(args, WXSimpleButton*);
		}
	}

	return WXMenu::createWithArray(pArray);
}

WXMenu* WXMenu::createWithItem(WXSimpleButton* item)
{
	return WXMenu::create(item, NULL);
}

bool WXMenu::init()
{
	return initWithArray(NULL);
}

bool WXMenu::initWithArray(CCArray* pArrayOfItems)
{
	m_bEnabled = true;
	// menu in the center of the screen
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	this->ignoreAnchorPointForPosition(true);
	setAnchorPoint(ccp(0.5f, 0.5f));
	this->setContentSize(s);

	setPosition(ccp(s.width/2, s.height/2));

	m_horizontallyAlignType = ALIGN_ITEM_HORIZONTALLY_CENTER;

	if (pArrayOfItems != NULL)
	{
		int z=0;
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(pArrayOfItems, pObj)
		{
			WXSimpleButton* item = (WXSimpleButton*)pObj;
			this->addChild(item, z);
			z++;
		}
	}

	//    [self alignItemsVertically];
	m_pSelectedItem = NULL;
	// enable cascade color and opacity on menus
	setCascadeColorEnabled(true);
	setCascadeOpacityEnabled(true);

	return true;
}

/*
* override add:
*/
void WXMenu::addChild(CCNode * child)
{
	CCNode::addChild(child);
}

void WXMenu::addChild(CCNode * child, int zOrder)
{
	CCNode::addChild(child, zOrder);
}

void WXMenu::addChild(CCNode * child, int zOrder, int tag)
{
	CCAssert( dynamic_cast<WXSimpleButton*>(child) != NULL, "Menu only supports MenuItem objects as children");
	CCNode::addChild(child, zOrder, tag);
}

void WXMenu::onExit()
{
	if (m_pSelectedItem)
	{
		m_pSelectedItem->selected(false);
		m_pSelectedItem = NULL;
	}
	CCNode::onExit();
}

void WXMenu::removeChild(CCNode* child, bool cleanup)
{
	WXSimpleButton *pMenuItem = dynamic_cast<WXSimpleButton*>(child);
	CCAssert(pMenuItem != NULL, "Menu only supports MenuItem objects as children");

	if (m_pSelectedItem == pMenuItem)
	{
		m_pSelectedItem = NULL;
	}

	CCNode::removeChild(child, cleanup);
}
bool WXMenu::onTouchBegan(Touch* touch, Event* event)
{
	CC_UNUSED_PARAM(event);
	if (!m_bEnabled || ! isShow())
	{
		return false;
	}

	m_pSelectedItem = this->itemForTouch(touch);
	if (m_pSelectedItem)
	{
		m_pSelectedItem->selected(true);
		return true;
	}
	return false;
}

bool WXMenu::onTouchEnded(Touch *touch, Event* event)
{
	bool bRet = false;
	CC_UNUSED_PARAM(touch);
	CC_UNUSED_PARAM(event);
	WXSimpleButton* currentItem = itemForTouch(touch);
	if (currentItem)
	{
		if (m_pSelectedItem)
		{
			m_pSelectedItem->selected(false);
			if (m_pSelectedItem==currentItem)
			{
				m_pSelectedItem->activate();
			}
			m_pSelectedItem = NULL;
		}
		return true;
	}
	if (m_pSelectedItem)
	{
		m_pSelectedItem->selected(false);
		m_pSelectedItem = NULL;
	}
	return false;
}

void WXMenu::onTouchCancelled(Touch *touch, Event* event)
{
	CC_UNUSED_PARAM(touch);
	CC_UNUSED_PARAM(event);
	if (m_pSelectedItem)
	{
		m_pSelectedItem->selected(false);
		m_pSelectedItem = NULL;
	}
}

void WXMenu::onTouchMoved(Touch* touch, Event* event)
{
	CC_UNUSED_PARAM(event);
}

//Menu - Alignment
void WXMenu::alignItemsVertically()
{
	this->alignItemsVerticallyWithPadding(kDefaultPadding);
}

void WXMenu::alignItemsVerticallyWithPadding(float padding)
{
	float height = -padding;
	if ( getChildren().size() > 0)
	{
		auto& children = getChildren();
		for(const auto &child : children)
		{
			CCNode* pChild = dynamic_cast<CCNode*>(child);
			if (pChild)
			{
				height += pChild->getContentSize().height * pChild->getScaleY() + padding;
			}
		}
	}

	float y = height / 2.0f;
	if (getChildren().size() > 0)
	{
		CCObject* pObject = NULL;
		auto& children = getChildren();
		for(const auto &child : children)
		{
			CCNode* pChild = dynamic_cast<CCNode*>(pObject);
			if (pChild)
			{
				pChild->setPosition(ccp(0, y - pChild->getContentSize().height * pChild->getScaleY() / 2.0f));
				y -= pChild->getContentSize().height * pChild->getScaleY() + padding;
			}
		}
	}
}

void WXMenu::alignItemsHorizontally(void)
{
	this->alignItemsHorizontallyWithPadding(kDefaultPadding);
}

void WXMenu::alignItemsHorizontallyWithPadding(float padding)
{
	float width = 0;
	switch (m_horizontallyAlignType)
	{
	case ALIGN_ITEM_HORIZONTALLY_CENTER:
		{
			width = -padding;
			if (getChildren().size() > 0)
			{
				auto& children = getChildren();
				for(const auto &child : children)
				{
					CCNode* pChild = dynamic_cast<CCNode*>(child);
					if (pChild && pChild->isVisible())
					{
						width += pChild->getContentSize().width * pChild->getScaleX() + padding;
					}
				}
			}
			float x = -width / 2.0f;
			if (getChildren().size() > 0)
			{
				CCObject* pObject = NULL;
				auto& children = getChildren();
				for(const auto &child : children)
				{
					CCNode* pChild = dynamic_cast<CCNode*>(pObject);
					if (pChild && pChild->isVisible())
					{
						pChild->setPosition(ccp(x + pChild->getContentSize().width*pChild->getScaleX() / 2.0f, pChild->getContentSize().height*pChild->getScaleY() / 2.0f));
						x += pChild->getContentSize().width * pChild->getScaleX() + padding;
					}
				}
			}
		}
		break;
	case ALIGN_ITEM_HORIZONTALLY_LEFT:
		{
			if (getChildren().size() > 0)
			{
				auto& children = getChildren();
				for(const auto &child : children)
				{
					CCNode* pChild = dynamic_cast<CCNode*>(child);
					if (pChild && pChild->isVisible())
					{
						pChild->setPosition(ccp(width + pChild->getContentSize().width*pChild->getScaleX() / 2.0f, pChild->getContentSize().height*pChild->getScaleY() / 2.0f));
						width += pChild->getContentSize().width * pChild->getScaleX() + padding;
					}
				}
			}
		}
		break;
	case ALIGN_ITEM_HORIZONTALLY_RIGHT:
		{
			if (getChildren().size() > 0)
			{
				auto& children = getChildren();
				for(const auto &child : children)
				{
					CCNode* pChild = dynamic_cast<CCNode*>(child);
					if (pChild && pChild->isVisible())
					{
						width += pChild->getContentSize().width * pChild->getScaleX() + padding;
					}
				}
			}
			float x = -width;
			if (getChildren().size() > 0)
			{
				auto& children = getChildren();
				for(const auto &child : children)
				{
					CCNode* pChild = dynamic_cast<CCNode*>(child);
					if (pChild && pChild->isVisible())
					{
						pChild->setPosition(ccp(x + pChild->getContentSize().width*pChild->getScaleX() / 2.0f, pChild->getContentSize().height*pChild->getScaleY() / 2.0f));
						x += pChild->getContentSize().width * pChild->getScaleX() + padding;
					}
				}
			}
		}
		break;
	}
}

WXSimpleButton* WXMenu::itemForTouch(CCTouch *touch)
{
	CCPoint touchLocation = touch->getLocation();

	if (getChildren().size() > 0)
	{
		auto& children = getChildren();
		for(const auto &child : children)
		{
			WXSimpleButton* pChild = dynamic_cast<WXSimpleButton*>(child);
			if (pChild && pChild->isVisible() && pChild->isEnabled())
			{
				CCPoint local = pChild->convertToNodeSpace(touchLocation);
				CCRect r = pChild->rect();
				r.origin = CCPoint::ZERO;

				if (r.containsPoint(local))
				{
					return pChild;
				}
			}
		}
	}

	return NULL;
}

