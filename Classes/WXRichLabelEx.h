#pragma once
#include "WXSimplePanel.h"


typedef void (cocos2d::CCObject::*SEL_CallFuncI)(int);
#define		LABEL_CACHE_STEP_SIZE		30
#define		LABEL_CACHE_INIT_SIZE		100

static std::string g_defaultFaceFilename = "face.anim";//Ĭ�ϱ��������ļ�

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

	static void setDefaultFaceFilename(std::string var);//����Ĭ�ϱ��������ļ�

	bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	bool onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void onTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	CREATE_FUNC(WXRichLabelEx);

	void ResetContent();//���ԭ���������֡�ͼƬ��
	void Initialize(std::string fontName, float fontSize,cocos2d::CCSize dimension,cocos2d::CCObject* target=NULL, SEL_CallFuncI callBack=NULL);//��ʼ��
	void AddString( std::string string, cocos2d::ccColor3B color ,int id, bool isUnderLine=false);//���һ�����֣�id����0ʱ��ʾ�����ӣ��ص�ʱid��
	void AddFace( int id );//���һ������
	void AddPic( std::string pic );//���һ��ͼƬ
	void EnterPos( );//�س�
	void XMove(int move);//��ǰ����x�������ƶ�move

	void showBGColor(bool isShow);//��ʾ������ɫ��
	void setBGColor(cocos2d::ccColor4B color);//���ñ�����ɫ����ɫ

	void setTarget(cocos2d::CCObject* target, SEL_CallFuncI callBack);//���ûص�
	int GetCurrentHeight( );//��ȡ��ǰ�и߶�
	virtual cocos2d::CCRect rect();
	CC_SYNTHESIZE(bool, m_bCrossLabel, CanCrossLabel);//��Ϣ�Ƿ񴩹�label��Ĭ��ֱ�Ӵ���
private:
	void LabelAdd(std::string string, cocos2d::ccColor3B color,int id,bool isUnderLine=false);

private:
	SEL_CallFuncI		m_pCallBack;
	cocos2d::CCObject*	m_pTarget;
	std::string			m_fontName;								//������
	float			    m_fontSize;								//����ߴ�
	cocos2d::CCPoint	m_currentPos;							//��ǰλ��
	cocos2d::CCPoint	m_startPos;								//��ʼλ��
	int					m_leftWidth;							//��ǰ��ʣ�����

	int					m_oneCcharWidth;						//һ��Ӣ�ĵĿ��
	int					m_fontHeight;							//�м��

	cocos2d::CCLabelTTF*			m_labelCal;								//������LABEL.
	//cocos2d::CCLabelTTF*			m_labelCache[LABEL_CACHE_INIT_SIZE];	//label����
	cocos2d::CCLabelTTF*			m_labelCache;	//label����
	int					m_curLabelIndex;
	int					m_DimensionWidth;						//���ֺ᷽������

	cocos2d::CCLayer				*m_manageLayer;
	cocos2d::CCLayerColor *mask;
	cocos2d::CCSprite*			 m_faceSpirit;
	cocos2d::CCSprite*			 m_picSpirit;
	cocos2d::CCLayerColor*	m_bg;//����
	cocos2d::ccColor4B		m_bgColor;

	std::vector<ClinkData> m_data;
};
