#include "WXBaseNode.h"

USING_NS_CC;

WXBaseNode::WXBaseNode( void )
{

}

WXBaseNode::~WXBaseNode( void )
{

}

void WXBaseNode::show( bool isShow )
{
	setVisible(isShow);
}

bool WXBaseNode::isShow()
{
	if (isVisible())
	{
		return hasVisibleParents();
	}
	return false;
}

bool WXBaseNode::onTouchBegan( cocos2d::Touch* pTouch, cocos2d::Event *pEvent )
{
	return false;
}

void WXBaseNode::onTouchMoved( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{

}

bool WXBaseNode::onTouchEnded( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{
	return false;
}

void WXBaseNode::onTouchCancelled( cocos2d::Touch*pTouch, cocos2d::Event*pEvent )
{

}

bool WXBaseNode::hasVisibleParents()
{
	CCNode* pParent = this->getParent();
	for( CCNode *c = pParent; c != NULL; c = c->getParent() )
	{
		if( !c->isVisible() )
		{
			return false;
		}
	}
	return true;
}

CCRect WXBaseNode::rect()
{
	return CCRectMake( _position.x - _contentSize.width * _anchorPoint.x,
		_position.y - _contentSize.height * _anchorPoint.y,
		_contentSize.width, _contentSize.height);
}

void WXBaseNode::setTarget( cocos2d::CCObject *rec, cocos2d::SEL_CallFuncO selector )
{
	m_pListener = rec;
	m_pfnSelector = selector;
}