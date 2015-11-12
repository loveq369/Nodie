#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#include "LoadingLayer.h"
#include "DataManager.h"
#include "GameGobal.h"
#include "SceneController.h"
#include "SceneLayer.h"
#include "util/UrlUtil.h"

#define FACE_ANIM		"model/ui/face/face.anim"//���鶯��
#define GAME_CONFIGS	"configs/config-game.conf"//��ϷGPU����
#define RES_PATH_1		"wuxian_resource"//��Դ·��

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
	//////////////////////////һЩĬ������////////////////////////////////////////////////
	WXRichLabelEx::setDefaultFaceFilename(FACE_ANIM);//���ñ��鶯��Ĭ��·��

	//���һ����Դ·��
	std::string res_path = getWritablePath();
	res_path.append(RES_PATH_1);
	checkFolderPath(res_path.c_str());
	CCFileUtils::sharedFileUtils()->addSearchPath(res_path.c_str());

	// 	FNTConfigLoadFile("fonts/font.fnt");//������ͼƬ(��ע�͵�)
	//WXSimpleButton::setDefaultBtnFontType(2);
	//WXSimpleButton::setDefaultBtnStringTnf("fonts/font.fnt");
//#if (CC_TARGET_PLATFORM!=CC_PLATFORM_ANDROID)
//	WXSimpleButton::setDefaultBtnStroke(true);
//#endif
	TextureManager::getInstance().setMaxInterval(30);//ÿ��30����һ����Ҫ�ͷŵ�ͼƬ
	TextureManager::getInstance().setMaxLifecycle(300);//ÿ��ͼƬ������ڴ��д���300��

	///////////////////////////�Ӵ���һЩ����///////////////////////////////////////////////
	CCConfiguration::sharedConfiguration()->loadConfigFile(GAME_CONFIGS);

	CCDirector *pDirector = CCDirector::sharedDirector();
	auto pEGLView = pDirector->getOpenGLView();
	if(!pEGLView) {
		pEGLView = GLViewImpl::create("My Game");
		//glview->setDesignResolutionSize(640,1162,kResolutionNoBorder);
	}
	pDirector->setDefaultValues();
	pDirector->setOpenGLView(pEGLView);

//#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
//	pDirector->setDisplayStats(true);
//#endif

	CCSize winSize = pDirector->getWinSize();
	float designWidth = 960;
	float designHeight = 600;
	float tempWidth = winSize.width*designHeight/winSize.height;
	float tempHeight = winSize.height*designWidth/winSize.width;
	float width = designWidth>tempWidth?designWidth:tempWidth;
	float height = designHeight>tempHeight?designHeight:tempHeight;

	pEGLView->setDesignResolutionSize(width, height, kResolutionExactFit);

	////////////////////////////���г���//////////////////////////////////////////////
#ifdef RES_DEBUG
	GameGobal::getInstance().setCurrentSceneType(scene_type_run_loading);
#else
	GameGobal::getInstance().setCurrentSceneType(scene_type_run_loading);
#endif

	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	CCDirector::sharedDirector()->stopAnimation();
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

void AppDelegate::applicationWillEnterForeground()
{
	CCDirector::sharedDirector()->startAnimation();
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
