#include "WXCheckButtonPanel.h"
#include "WXUIDefine.h"
#include "WXCheckButton.h"
USING_NS_CC;


WXCheckButtonPanel::WXCheckButtonPanel(void)
{
	m_btnList = new std::vector<WXCheckButton*>();
	m_currentBtn = NULL;
	m_padding = 5;
	m_alignType = ALIGN_ITEMS_VERTICALLY_LEFT;
	m_btnTextHorizontalAlignment = TEXT_ALIGNMENT_RIGHT;
}
WXCheckButtonPanel::~WXCheckButtonPanel(void)
{
	CC_SAFE_DELETE(m_btnList);
}
bool WXCheckButtonPanel::init()
{
	setAnchorPoint(CCPoint::ZERO);
	setPosition(CCPoint::ZERO);
	return true;
}
void WXCheckButtonPanel::appendItem(WXCheckButton* button, int tag)
{
	if (!button)
	{
		return;
	}
	if (tag==-1)
	{
		button->setTag(m_btnList->size());
	}
	else
	{
		button->setTag(tag);
	}
	addChild(button);
	m_btnList->push_back(button);
}
void WXCheckButtonPanel::appendItem(const char* btnNormalSpriteFrameName, const char* btnSelectedSpriteFrameName, const char* btnDisabledSpriteFrameName, std::string btnStr, int tag)
{
	if (!m_btnList)
	{
		return;
	}
	WXCheckButton* btn = WXCheckButton::createWithSpriteFrameName(btnNormalSpriteFrameName, btnSelectedSpriteFrameName,btnDisabledSpriteFrameName, NULL, NULL, btnStr.c_str());
	appendItem(btn, tag);
}
void WXCheckButtonPanel::layout()
{
	switch (m_alignType)
	{
	case ALIGN_ITEMS_HORIZONTALLY_TOP:
		{
			std::vector<WXCheckButton*>::iterator itr = m_btnList->begin();
			int width = 0;
			int h = 0;
			while (itr!=m_btnList->end() && (*itr)->isVisible())
			{
				h = h>=(*itr)->getContentSize().height?h:(*itr)->getContentSize().height;
				(*itr)->setPositionX(width);
				width += (*itr)->getContentSize().width*(*itr)->getScaleX() + m_padding;
				++itr;
			}
			setContentSize(CCSizeMake(width, h));
			break;
		}
	case ALIGN_ITEMS_VERTICALLY_LEFT:
		{
			int w = 0;
			std::vector<WXCheckButton*>::iterator itr = m_btnList->begin();
			int height = 0;
			while (itr!=m_btnList->end() && (*itr)->isVisible())
			{
				w = w>=(*itr)->getContentSize().width?w:(*itr)->getContentSize().width;
				height += (*itr)->getContentSize().height+m_padding;
				++itr;
			}
			setContentSize(CCSizeMake(w, height));
			itr = m_btnList->begin();
			height -= m_padding;
			while (itr!=m_btnList->end() && (*itr)->isVisible())
			{
				height -= (*itr)->getContentSize().height+m_padding;
				(*itr)->setPositionY(height);
				++itr;
			}
			break;
		}
	}
}
bool WXCheckButtonPanel::onTouchBegan(Touch* pTouch, Event *pEvent)
{
	if (!isShow())
	{
		return false;
	}
	m_currentBtn = itemForTouch(pTouch);
	if (m_currentBtn)
	{
		return true;
	}
	return false;
}
void WXCheckButtonPanel::onTouchMoved(Touch*pTouch, Event*pEvent)
{

}
bool WXCheckButtonPanel::onTouchEnded(Touch*pTouch, Event*pEvent)
{
	WXSimpleButton* currentItem = itemForTouch(pTouch);
	if (currentItem)
	{
		if (m_currentBtn && currentItem==m_currentBtn)
		{
			m_currentBtn->selected(!m_currentBtn->isSelected());
			if (m_pListener && m_pfnSelector)
			{
				(m_pListener->*m_pfnSelector)(m_currentBtn);
			}
		}
		m_currentBtn = NULL;
		return true;
	}
	return false;
}
void WXCheckButtonPanel::onTouchCancelled(Touch*pTouch, Event*pEvent)
{

}
void WXCheckButtonPanel::selectItemByIndex(unsigned int index, bool isSelected)
{
	select(getItemByIndex(index), isSelected);
}
void WXCheckButtonPanel::selectItemByTag(unsigned int tag, bool isSelected/* =true */)
{
	select(getItemByTag(tag), isSelected);
}
WXCheckButton* WXCheckButtonPanel::getItemByIndex(unsigned int index/* =0 */)
{
	if (!m_btnList || index>=m_btnList->size())
	{
		return NULL;
	}
	std::vector<WXCheckButton*>::iterator itr = m_btnList->begin()+index;
	return *itr;
}
WXCheckButton* WXCheckButtonPanel::getItemByTag(unsigned int tag)
{
	return dynamic_cast<WXCheckButton*>(getChildByTag(tag));
}
int WXCheckButtonPanel::getBtnTextHorizontalAlignment()
{
	return m_btnTextHorizontalAlignment;
}
void WXCheckButtonPanel::setBtnTextHorizontalAlignment(int var)
{
	if (m_btnTextHorizontalAlignment==var)
	{
		return;
	}
	m_btnTextHorizontalAlignment = var;
	std::vector<WXCheckButton*>::iterator itr = m_btnList->begin();
	for (;itr!=m_btnList->end();itr++)
	{
		(*itr)->setTextHorizontalAlignment(m_btnTextHorizontalAlignment);
	}
}

WXCheckButton* WXCheckButtonPanel::itemForTouch( cocos2d::Touch * touch )
{
	CCPoint touchLocation = touch->getLocation();
	std::vector<WXCheckButton*>::iterator itr = m_btnList->begin();
	for (;itr!=m_btnList->end();itr++)
	{
		if (*itr && (*itr)->isVisible() && (*itr)->isEnabled())
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

void WXCheckButtonPanel::select( WXCheckButton* btn, bool isSelected )
{
	if (btn)
	{
		if (isSelected)
		{
			m_currentBtn = btn;
			m_currentBtn->selected(true);
		}
		else
		{
			btn->selected(false);
			if (m_currentBtn==btn)
			{
				m_currentBtn = NULL;
			}
		}
	}
}