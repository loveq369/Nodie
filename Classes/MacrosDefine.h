#pragma once

#include "cocos2d.h"
#include "util/basic_types.h"


#define _MAX_PATH_ 260

#define WINSIZE		cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize()
#define VEIWSIZE	cocos2d::CCSize viewSize = cocos2d::CCEGLView::sharedOpenGLView()->getViewSize()

#define WX_MAX(a,b)            (((a) > (b)) ? (a) : (b))
#define WX_MIN(a,b)            (((a) < (b)) ? (a) : (b))

#define WX_SYNTHESIZE(varType, varName, funName)\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }
#define WX_PROPERTY(varType, varName, funName)\
public: virtual varType get##funName(void);\
public: virtual void set##funName(varType var);
#define WX_PROPERTY_READ(varType, varName, funName)\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var);
#define WX_PROPERTY_WRITE(varType, varName, funName)\
public: virtual varType get##funName(void);\
public: virtual void set##funName(varType var){ varName = var; }

	//һЩ����ָ��
	typedef void (cocos2d::CCObject::*SEL_CallFuncD)(void*);
#define callfuncD_selector(_SELECTOR) (SEL_CallFuncD)(&_SELECTOR)
typedef void (cocos2d::CCObject::*SEL_CallFuncDD)(void*, void*);
#define callfuncDD_selector(_SELECTOR) (SEL_CallFuncDD)(&_SELECTOR)
typedef void (cocos2d::CCObject::*SEL_CallFuncI)(int);
#define callfuncI_selector(_SELECTOR) (SEL_CallFuncI)(&_SELECTOR)

//��ָ����ߴ�������
#define CREATE_W_H_FUNC(__TYPE__) \
	static __TYPE__* create(int w, int h) \
{ \
	__TYPE__ *pRet = new __TYPE__(); \
	if (pRet && pRet->init(w, h)) \
{ \
	pRet->autorelease(); \
	return pRet; \
} \
	else \
{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
} \
}

//ɾ��ָ��map
#define CLEAR_UP_MAP_POINTER(m, it) it = m->begin(); \
	while(it != m->end()) \
{ \
	if(it->second) \
{ \
	delete (it++)->second; \
} \
else \
{ \
	++it; \
} \
} \
	m->clear(); \
	CC_SAFE_DELETE(m); \
	m = NULL;


//���map
#define CLEAR_UP_MAP(m, it) it = m.begin(); \
	while(it != m.end()) \
{ \
	if(it->second) \
{ \
	delete (it++)->second; \
} \
else \
{ \
	++it; \
} \
} \
	m.clear();


//ɾ��ָ��vector
#define CLEAR_UP_VECTOR_POINTER(v, itr) itr = v->begin();\
	while (itr!=v->end())\
{\
	if(*itr)\
{\
	delete *(itr++);\
}\
		else\
{\
	itr++;\
}\
}\
	v.clear();\
	CC_SAFE_DELETE(v);\
	v = NULL;


//���vector
#define CLEAR_UP_VECTOR(v, itr) itr = v.begin();\
	while (itr!=v.end())\
{\
	if(*itr)\
{\
	delete *(itr++);\
}\
		else\
{\
	itr++;\
}\
}\
	v.clear();
