#include "WXCheckButton.h"
#include "WXUIDefine.h"
//#include "cocos-ext.h"
USING_NS_CC;

WXCheckButton::WXCheckButton(void)
{
	m_textHorizontalAlignment = TEXT_ALIGNMENT_RIGHT;
	m_normalTextColor = Color3B::WHITE;
	m_selectedTextColor = Color3B::YELLOW;
	m_padding = 10;
}
WXCheckButton::~WXCheckButton(void)
{
}
bool WXCheckButton::initWithNode(CCNode* noramlNode, CCNode* selectedNode, CCNode* disabledNode, CCObject* target, SEL_CallFuncO selector, const char* str)
{
	setTarget(target, selector);
	setNormalImage(noramlNode);
	setSelectedImage(selectedNode);
	setDisabledImage(disabledNode);
	if (g_defaultCheckBtnFontType==2)
	{
		m_label = CCLabelBMFont::create(str, g_defaultCheckBtnStringTnf.c_str());
	}
	else
	{
		m_label = CCLabelTTF::create(str, FONT_NAME_HELVETICA, FONT_SIZE_24);
	}
	setFontColor(m_normalTextColor);
	setAnchorPoint(CCPoint::ZERO);
	addChild(m_label,100);

	return true;
}
WXCheckButton* WXCheckButton::createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target/* =NULL */, cocos2d::SEL_CallFuncO selector/* =NULL */, const char* str/* = */)
{
	WXCheckButton* pRet = new WXCheckButton();
	if (pRet)
	{
		if (pRet->initWithNode(noramlNode, selectedNode, disabledNode, target, selector, str))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXCheckButton* WXCheckButton::createWithSpriteFrame(CCSpriteFrame *normalSpriteFrame, CCSpriteFrame *selectedSpriteFrame, CCSpriteFrame* disabledSpriteFrame, CCObject* target, SEL_CallFuncO selector, const char* str)
{
	WXCheckButton* pRet = new WXCheckButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrame(normalSpriteFrame);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrame(selectedSpriteFrame);
		CCSprite* disabledSprite = NULL;
		if (disabledSpriteFrame)
		{
			disabledSprite = CCSprite::createWithSpriteFrame(disabledSpriteFrame);
		}
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector, str))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXCheckButton* WXCheckButton::createWithSpriteFrameName(const char *normalName, const char *selectedName, const char* disabledName, CCObject* target, SEL_CallFuncO selector, const char* str)
{
	WXCheckButton *pRet = new WXCheckButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrameName(normalName);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrameName(selectedName);
		CCSprite* disabledSprite = NULL;
		if (disabledName)
		{
			disabledSprite = CCSprite::createWithSpriteFrameName(disabledName);
		}
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector, str))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
void WXCheckButton::setNormalImage(CCNode* pImage)
{
	if (pImage != m_pNormalImage)
	{
		if (pImage)
		{
			addChild(pImage);
			pImage->setAnchorPoint(ccp(0, 0));
		}
		if (m_pNormalImage)
		{
			removeChild(m_pNormalImage, true);
		}
		m_pNormalImage = pImage;
		layout();
		updateImagesVisibility();
	}
}
void WXCheckButton::setSelectedImage(CCNode* pImage)
{
	if (pImage != m_pSelectedImage)
	{
		if (pImage)
		{
			addChild(pImage);
			pImage->setAnchorPoint(ccp(0, 0));
		}
		if (m_pSelectedImage)
		{
			removeChild(m_pSelectedImage, true);
		}
		m_pSelectedImage = pImage;
		updateImagesVisibility();
	}
}
void WXCheckButton::setDisabledImage(CCNode* pImage)
{
	if (pImage != m_pDisabledImage)
	{
		if (pImage)
		{
			addChild(pImage);
			pImage->setAnchorPoint(ccp(0, 0));
		}
		if (m_pDisabledImage)
		{
			removeChild(m_pDisabledImage, true);
		}
		m_pDisabledImage = pImage;
		updateImagesVisibility();
	}
}
void WXCheckButton::updateImagesVisibility()
{
	if (m_bEnabled)
	{
		if (m_bSelected)
		{
			if (m_pSelectedImage) m_pSelectedImage->setVisible(true);
			if (m_pNormalImage) m_pNormalImage->setVisible(false);
			if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
			if (m_label) setFontColor(m_selectedTextColor);
		}
		else
		{
			if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
			if (m_pNormalImage) m_pNormalImage->setVisible(true);
			if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
			if (m_label) setFontColor(m_normalTextColor);
		}
	}
	else
	{
		if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
		if (m_pNormalImage) m_pNormalImage->setVisible(false);
		if (m_pDisabledImage) m_pDisabledImage->setVisible(true);
		if (m_label) setFontColor(m_normalTextColor);
	}
}
bool WXCheckButton::onTouchBegan(Touch* pTouch, Event *pEvent)
{
	if (!m_bEnabled || !isShow())
	{
		return false;
	}
	if (onTouch(pTouch, pEvent))
	{
		return true;
	}
	return false;
}
void WXCheckButton::onTouchMoved(Touch*pTouch, Event*pEvent)
{

}
bool WXCheckButton::onTouchEnded(Touch*pTouch, Event*pEvent)
{
	if (m_bEnabled && isShow())
	{
		if (onTouch(pTouch, pEvent))
		{
			m_bSelected = !m_bSelected;
			selected(m_bSelected);
			activate();
			return true;
		}
	}
	return false;
}
void WXCheckButton::onTouchCancelled(Touch*pTouch, Event*pEvent)
{

}
void WXCheckButton::setTextHorizontalAlignment(int var)
{
	if (m_textHorizontalAlignment==var)
	{
		return;
	}
	m_textHorizontalAlignment = var;
	layout();	
}
int WXCheckButton::getTextHorizontalAlignment()
{
	return m_textHorizontalAlignment;
}
void WXCheckButton::layout()
{
	switch (m_textHorizontalAlignment)
	{
	case TEXT_ALIGNMENT_LEFT:
		{
			if (m_pNormalImage && m_label)
			{
				m_pNormalImage->setPositionX(m_label->getContentSize().width+m_padding);
				if (m_pSelectedImage)
				{
					m_pSelectedImage->setPositionX(m_pNormalImage->getPositionX());
				}
				if (m_pDisabledImage)
				{
					m_pDisabledImage->setPositionX(m_pNormalImage->getPositionX());
				}
				int y = m_pNormalImage->getContentSize().height/2;
				m_label->setAnchorPoint(ccp(0,0.5));
				m_label->setPosition(ccp(0, y));
				int height = m_pNormalImage->getContentSize().height>m_label->getContentSize().height?m_pNormalImage->getContentSize().height:m_label->getContentSize().height;
				setContentSize(CCSizeMake(m_pNormalImage->getContentSize().width+m_label->getContentSize().width+m_padding,\
					height));
			}
			break;
		}
	case TEXT_ALIGNMENT_CENTER:
		{
			if (m_pNormalImage && m_label)
			{
				m_pNormalImage->setPositionX(0);
				if (m_pSelectedImage)
				{
					m_pSelectedImage->setPositionX(m_pNormalImage->getPositionX());
				}
				if (m_pDisabledImage)
				{
					m_pDisabledImage->setPositionX(m_pNormalImage->getPositionX());
				}
				int x = m_pNormalImage->getContentSize().width/2;
				int y = m_pNormalImage->getContentSize().height/2;
				m_label->setAnchorPoint(ccp(0.5,0.5));
				m_label->setPosition(ccp(x, y));
				setContentSize(m_pNormalImage->getContentSize());
			}
			break;
		}
	case TEXT_ALIGNMENT_RIGHT:
		{
			if (m_pNormalImage && m_label)
			{
				m_pNormalImage->setPositionX(0);
				if (m_pSelectedImage)
				{
					m_pSelectedImage->setPositionX(m_pNormalImage->getPositionX());
				}
				if (m_pDisabledImage)
				{
					m_pDisabledImage->setPositionX(m_pNormalImage->getPositionX());
				}
				int y = m_pNormalImage->getContentSize().height/2;
				m_label->setAnchorPoint(ccp(0,0.5));
				m_label->setPosition(ccp(m_pNormalImage->getContentSize().width+m_padding, y));
				int height = m_pNormalImage->getContentSize().height>m_label->getContentSize().height?m_pNormalImage->getContentSize().height:m_label->getContentSize().height;
				setContentSize(CCSizeMake(m_pNormalImage->getContentSize().width+m_label->getContentSize().width+m_padding,height));
			}
			break;
		}
	}
}

void WXCheckButton::setNormalTextColor(ccColor3B var)
{
	if (m_normalTextColor.r==var.r && m_normalTextColor.g==var.g && m_normalTextColor.b==var.b)
	{
		return;
	}
	m_normalTextColor = var;
	updateImagesVisibility();
}

ccColor3B WXCheckButton::getNormalTextColor()
{
	return m_normalTextColor;
}

void WXCheckButton::setSelectedTextColor(ccColor3B var)
{
	if (m_selectedTextColor.r==var.r && m_selectedTextColor.g==var.g && m_selectedTextColor.b==var.b)
	{
		return;
	}
	m_selectedTextColor = var;
	updateImagesVisibility();
}

ccColor3B WXCheckButton::getSelectedTextColor()
{
	return m_selectedTextColor;
}

void WXCheckButton::setPadding(float var)
{
	if (m_padding!=var)
	{
		m_padding = var;
		layout();
	}
}
float WXCheckButton::getPadding()
{
	return m_padding;
}
void WXCheckButton::setDefaultCheckBtnStringTnf(std::string var)
{
	g_defaultCheckBtnStringTnf = var;
}
void WXCheckButton::setDefaultCheckBtnFontType(int var)
{
	g_defaultCheckBtnFontType = var;
}

