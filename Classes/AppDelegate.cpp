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

#define FACE_ANIM		"model/ui/face/face.anim"//表情动画
#define GAME_CONFIGS	"configs/config-game.conf"//游戏GPU配置
#define RES_PATH_1		"wuxian_resource"//资源路径

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
	//////////////////////////一些默认设置////////////////////////////////////////////////
	WXRichLabelEx::setDefaultFaceFilename(FACE_ANIM);//设置表情动画默认路径

	//添加一个资源路径
	std::string res_path = getWritablePath();
	res_path.append(RES_PATH_1);
	checkFolderPath(res_path.c_str());
	CCFileUtils::sharedFileUtils()->addSearchPath(res_path.c_str());

	// 	FNTConfigLoadFile("fonts/font.fnt");//加字体图片(先注释掉)
	//WXSimpleButton::setDefaultBtnFontType(2);
	//WXSimpleButton::setDefaultBtnStringTnf("fonts/font.fnt");
//#if (CC_TARGET_PLATFORM!=CC_PLATFORM_ANDROID)
//	WXSimpleButton::setDefaultBtnStroke(true);
//#endif
	TextureManager::getInstance().setMaxInterval(30);//每隔30秒检测一次需要释放的图片
	TextureManager::getInstance().setMaxLifecycle(300);//每张图片最多在内存中存在300秒

	///////////////////////////视窗的一些设置///////////////////////////////////////////////
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

	////////////////////////////运行场景//////////////////////////////////////////////
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
