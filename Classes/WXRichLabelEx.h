#pragma once
#include "WXSimplePanel.h"


typedef void (cocos2d::CCObject::*SEL_CallFuncI)(int);
#define		LABEL_CACHE_STEP_SIZE		30
#define		LABEL_CACHE_INIT_SIZE		100

static std::string g_defaultFaceFilename = "face.anim";//默认表情所在文件

typedef struct _ClinkData
{
	int type;
	cocos2d::CCRect rect;
	int id;
}ClinkData;

class WXRichLabelEx : public WXSimplePanel
{
public:
	WXRichLabelEx(void);
	~WXRichLabelEx(void);

	static void setDefaultFaceFilename(std::string var);//设置默认表情所在文件

	bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	bool onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void onTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	CREATE_FUNC(WXRichLabelEx);

	void ResetContent();//清除原来所有文字、图片等
	void Initialize(std::string fontName, float fontSize,cocos2d::CCSize dimension,cocos2d::CCObject* target=NULL, SEL_CallFuncI callBack=NULL);//初始化
	void AddString( std::string string, cocos2d::ccColor3B color ,int id, bool isUnderLine=false);//添加一个文字（id：非0时表示超链接，回调时id）
	void AddFace( int id );//添加一个表情
	void AddPic( std::string pic );//添加一张图片
	void EnterPos( );//回车
	void XMove(int move);//当前行在x方向上移动move

	void showBGColor(bool isShow);//显示背景颜色层
	void setBGColor(cocos2d::ccColor4B color);//设置背景颜色层颜色

	void setTarget(cocos2d::CCObject* target, SEL_CallFuncI callBack);//设置回调
	int GetCurrentHeight( );//获取当前行高度
	virtual cocos2d::CCRect rect();
	CC_SYNTHESIZE(bool, m_bCrossLabel, CanCrossLabel);//消息是否穿过label，默认直接穿过
private:
	void LabelAdd(std::string string, cocos2d::ccColor3B color,int id,bool isUnderLine=false);

private:
	SEL_CallFuncI		m_pCallBack;
	cocos2d::CCObject*	m_pTarget;
	std::string			m_fontName;								//字体名
	float			    m_fontSize;								//字体尺寸
	cocos2d::CCPoint	m_currentPos;							//当前位置
	cocos2d::CCPoint	m_startPos;								//起始位置
	int					m_leftWidth;							//当前行剩余距离

	int					m_oneCcharWidth;						//一个英文的宽度
	int					m_fontHeight;							//行间距

	cocos2d::CCLabelTTF*			m_labelCal;								//计算用LABEL.
	//cocos2d::CCLabelTTF*			m_labelCache[LABEL_CACHE_INIT_SIZE];	//label缓冲
	cocos2d::CCLabelTTF*			m_labelCache;	//label缓冲
	int					m_curLabelIndex;
	int					m_DimensionWidth;						//文字横方向限制

	cocos2d::CCLayer				*m_manageLayer;
	cocos2d::CCLayerColor *mask;
	cocos2d::CCSprite*			 m_faceSpirit;
	cocos2d::CCSprite*			 m_picSpirit;
	cocos2d::CCLayerColor*	m_bg;//背景
	cocos2d::ccColor4B		m_bgColor;

	std::vector<ClinkData> m_data;
};
