#include "WXSimpleButton.h"
#include "WXUIDefine.h"
USING_NS_CC;


	WXSimpleButton::WXSimpleButton(void)
{
	m_pNormalImage = NULL;
	m_pSelectedImage = NULL;
	m_pDisabledImage = NULL;
	m_pListener = NULL;
	m_pfnSelector = NULL;
	setAnchorPoint(ccp(.5f,.5f));
}
WXSimpleButton::~WXSimpleButton(void)
{
}

WXSimpleButton* WXSimpleButton::createWithNode(cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, CCObject* target, SEL_CallFuncO selector, const char* btnStr/* = */)
{
	WXSimpleButton *pRet = new WXSimpleButton();
	if (pRet && pRet->initWithNode(noramlNode, selectedNode, disabledNode, target, selector, btnStr))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

WXSimpleButton* WXSimpleButton::createWithNode( cocos2d::CCNode* noramlNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, const char* btnStr/*=""*/ )
{
	return WXSimpleButton::createWithNode(noramlNode, selectedNode, disabledNode, NULL, NULL, btnStr);
}

WXSimpleButton * WXSimpleButton::create(const char *normalImage, const char *selectedImage, CCObject* target, SEL_CallFuncO selector)
{
	return WXSimpleButton::create(normalImage, selectedImage, NULL, target, selector);
}
WXSimpleButton * WXSimpleButton::create(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject* target, SEL_CallFuncO selector)
{
	WXSimpleButton *pRet = new WXSimpleButton();
	CCNode *normalSprite = NULL;
	CCNode *selectedSprite = NULL;
	CCNode *disabledSprite = NULL;

	if (normalImage)
	{
		normalSprite = CCSprite::create(normalImage);
	}
	if (selectedImage)
	{
		selectedSprite = CCSprite::create(selectedImage);
	}
	if(disabledImage)
	{
		disabledSprite = CCSprite::create(disabledImage);
	}
	if (pRet && pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXSimpleButton* WXSimpleButton::createWithSpriteFrame(CCSpriteFrame *normalSpriteFrame, CCSpriteFrame *selectedSpriteFrame, CCObject* target, SEL_CallFuncO selector)
{
	WXSimpleButton *pRet = new WXSimpleButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrame(normalSpriteFrame);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrame(selectedSpriteFrame);
		CCSprite* disabledSprite = NULL;
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXSimpleButton* WXSimpleButton::createWithSpriteFrameName(const char *normalName, const char *selectedName, CCObject* target, SEL_CallFuncO selector)
{
	WXSimpleButton *pRet = new WXSimpleButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrameName(normalName);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrameName(selectedName);
		CCSprite* disabledSprite = NULL;
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
WXSimpleButton* WXSimpleButton::createWithSpriteFrameName(const char *normalName, const char *selectedName,const char *disabledName, CCObject* target, SEL_CallFuncO selector)
{
	WXSimpleButton *pRet = new WXSimpleButton();
	if (pRet)
	{
		CCSprite* normalSprite = CCSprite::createWithSpriteFrameName(normalName);
		CCSprite* selectedSprite = CCSprite::createWithSpriteFrameName(selectedName);
		CCSprite* disabledSprite = CCSprite::createWithSpriteFrameName(disabledName);;
		if (pRet->initWithNode(normalSprite, selectedSprite, disabledSprite, target, selector))
		{
			pRet->autorelease();
			return pRet;
		}
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool WXSimpleButton::initWithNode(cocos2d::CCNode* normalNode, cocos2d::CCNode* selectedNode, cocos2d::CCNode* disabledNode, cocos2d::CCObject* target, cocos2d::SEL_CallFuncO selector, const char* btnStr/* = */)
{
	setTarget(target, selector);
	m_bEnabled = true;
	m_bSelected = false;
	setNormalImage(normalNode);
	setSelectedImage(selectedNode);
	setDisabledImage(disabledNode);

	if (g_defaultBtnFontType==2)
	{
		m_label = CCLabelBMFont::create(btnStr, g_defaultBtnStringTnf.c_str());
	}
	else
	{
		m_label = CCLabelTTF::create(btnStr, FONT_NAME_HELVETICA, FONT_SIZE_24);
	}
	m_label->setPosition(ccp(getContentSize().width/2, getContentSize().height/2));
	setFontColor(Color3B::WHITE);
	addChild(m_label, 100);

	return true;
}
void WXSimpleButton::setString(const char* str)
{
	if (m_label)
	{
		CCLabelBMFont* bmFont = dynamic_cast<CCLabelBMFont*>(m_label);
		if (bmFont)
		{
			bmFont->setString(str);
		}
		else
		{
			CCLabelTTF* ttf = dynamic_cast<CCLabelTTF*>(m_label);
			if (ttf)
			{
				ttf->setString(str);
			}
		}
		if (0==strcmp(str, ""))
		{
			m_label->setVisible(false);
		}
		else
		{
			m_label->setVisible(true);
		}
	}
}
void WXSimpleButton::setFontColor(const ccColor3B& color)
{
	CCLabelBMFont* bmFont = dynamic_cast<CCLabelBMFont*>(m_label);
	if (bmFont)
	{
		bmFont->setColor(color);
	}
	else
	{
		CCLabelTTF* ttf = dynamic_cast<CCLabelTTF*>(m_label);
		if (ttf)
		{
			ttf->setColor(color);
		}
	}
}
void WXSimpleButton::setFontSize(float fontSize)
{
	CCLabelBMFont* bmFont = dynamic_cast<CCLabelBMFont*>(m_label);
	if (bmFont)
	{
		float scale = fontSize/24;
		bmFont->setScale(scale);
	}
	else
	{
		CCLabelTTF* ttf = dynamic_cast<CCLabelTTF*>(m_label);
		if (ttf)
		{
			ttf->setFontSize(fontSize);
		}
	}
}
void WXSimpleButton::setFontName(const char* fontName)
{
	CCLabelTTF* ttf = dynamic_cast<CCLabelTTF*>(m_label);
	if (ttf)
	{
		ttf->setFontName(fontName);
	}
}
const char* WXSimpleButton::getString()
{
	CCLabelBMFont* bmFont = dynamic_cast<CCLabelBMFont*>(m_label);
	if (bmFont)
	{
		return bmFont->getString().c_str();
	}
	else
	{
		CCLabelTTF* ttf = dynamic_cast<CCLabelTTF*>(m_label);
		if (ttf)
		{
			return ttf->getString().c_str();
		}
	}
	return "";
}

CCNode * WXSimpleButton::getNormalImage()
{
	return m_pNormalImage;
}

void WXSimpleButton::setNormalImage(CCNode* pImage)
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
		this->setContentSize(m_pNormalImage->getContentSize());
		this->updateImagesVisibility();
	}
}

CCNode * WXSimpleButton::getSelectedImage()
{
	return m_pSelectedImage;
}

void WXSimpleButton::setSelectedImage(CCNode* pImage)
{
	if (pImage != m_pNormalImage)
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
		this->updateImagesVisibility();
	}
}

CCNode * WXSimpleButton::getDisabledImage()
{
	return m_pDisabledImage;
}

void WXSimpleButton::setDisabledImage(CCNode* pImage)
{
	if (pImage != m_pNormalImage)
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
		this->updateImagesVisibility();
	}
}

void WXSimpleButton::setDefaultBtnStringTnf(std::string var)
{
	g_defaultBtnStringTnf = var;
}
void WXSimpleButton::setDefaultBtnFontType(int var)
{
	g_defaultBtnFontType = var;
}

void WXSimpleButton::updateImagesVisibility()
{
	if (m_bEnabled)
	{
		if (m_bSelected)
		{
			if (m_pNormalImage)   m_pNormalImage->setVisible(false);
			if (m_pSelectedImage) m_pSelectedImage->setVisible(true);
			if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
		}
		else
		{
			if (m_pNormalImage)   m_pNormalImage->setVisible(true);
			if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
			if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
		}
	}
	else
	{
		if (m_pDisabledImage)
		{
			if (m_pNormalImage)   m_pNormalImage->setVisible(false);
			if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
			if (m_pDisabledImage) m_pDisabledImage->setVisible(true);
		}
		else
		{
			if (m_pNormalImage)   m_pNormalImage->setVisible(true);
			if (m_pSelectedImage) m_pSelectedImage->setVisible(false);
			if (m_pDisabledImage) m_pDisabledImage->setVisible(false);
		}
	}
}


void WXSimpleButton::activate()
{
	if (m_bEnabled)
	{
		if (m_pListener && m_pfnSelector)
		{
			(m_pListener->*m_pfnSelector)(this);
		}
	}
}

void WXSimpleButton::setEnabled(bool enabled)
{
	if (m_bEnabled!=enabled)
	{
		m_bEnabled = enabled;
		updateImagesVisibility();
	}
}

bool WXSimpleButton::isEnabled()
{
	return m_bEnabled;
}

bool WXSimpleButton::isSelected()
{
	return m_bSelected;
}

void WXSimpleButton::selected(bool var)
{
	m_bSelected = var;
	updateImagesVisibility();
}

bool WXSimpleButton::onTouchBegan( cocos2d::Touch* pTouch, cocos2d::Event *pEvent )
{
	if (!isEnabled() || !isShow())
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

void WXSimpleButton::onTouchMoved( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{

}

bool WXSimpleButton::onTouchEnded( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{
	if (m_bEnabled && isShow())
	{
		selected(false);
		if (onTouch(pTouch, pEvent))
		{
			activate();
			return true;
		}
	}
	return false;
}

void WXSimpleButton::onTouchCancelled( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{
	if (isShow())
	{
		selected(false);
	}
}

bool WXSimpleButton::onTouch( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{
	CCPoint local = convertTouchToNodeSpace(pTouch);
	CCRect r = rect();
	r.origin = CCPoint::ZERO;
	if (r.containsPoint(local))
	{
		return true;
	}
	return false;
}

