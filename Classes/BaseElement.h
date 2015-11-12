#pragma once
#include "cocos2d.h"
#include "EffectNode.h"
#include "util/basic_types.h"
class BaseElement: public EffectNode
{
public:
	virtual cocos2d::CCSize getSize()=0;//��ȡelement��С
	virtual int getType()=0;
	virtual int getFlag()=0;
	virtual int64 getId()=0;
	virtual int depth() const =0;
	virtual void setSelfOpacity(GLubyte _arg1)=0;
	virtual tPoint getTileCoord()=0;
	virtual bool itemForTouch(cocos2d::CCPoint& touchLocation)=0;//�Ƿ����
	//�Ƿ񳬳���Ұ
	virtual void outOfSight(bool isOut)=0;
	//
	virtual void destoryTarget()=0;
};