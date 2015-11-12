#pragma once

#include "cocos2d.h"
#include "gamecore.h"



///////////////////////����/////////////////////////////////////
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define FONT_NAME_DEFAULT	"msyh"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define FONT_NAME_DEFAULT	"_H_Helvetica"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#define FONT_NAME_DEFAULT	"Helvetica"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define FONT_NAME_DEFAULT	"DroidSansFallback"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
#define FONT_NAME_DEFAULT	"FreeSerif"
#else
#define FONT_NAME_DEFAULT	""
#endif

#define FONT_SIZE_24	24
#define FONT_SIZE_20	20
#define FONT_SIZE_16	16
#define FONT_SIZE_14	14
#define FONT_SIZE_12	12
#define FONT_SIZE_9		9



//���ַ�ʽ
#define ALIGN_ITEMS_HORIZONTALLY_TOP	0//ˮƽ���֣���
#define ALIGN_ITEMS_VERTICALLY_LEFT		1//��ֱ���֣���

#define ALIGN_ITEM_HORIZONTALLY_LEFT	0//ˮƽ����
#define ALIGN_ITEM_HORIZONTALLY_CENTER	1//ˮƽ����
#define ALIGN_ITEM_HORIZONTALLY_RIGHT	2//ˮƽ����

#define TEXT_ALIGNMENT_LEFT		1	//������ͼƬ�ⲿ���
#define TEXT_ALIGNMENT_CENTER	2	//������ͼƬ�ڲ��м�
#define TEXT_ALIGNMENT_RIGHT	3	//������ͼƬ�ⲿ�ұ�
///////////////////////UI��ʾ˳��   ZORDER//////////////////////
enum zorder
{
	UI_ZORDER_INIT					,            //��ʼ��spriteFrame
	UI_ZORDER_EXP					,           //������
	UI_ZORDER_ROLE_HEAD			    ,   	      //�Լ�ͷ��
	UI_ZORDER_TARGET_HEAD			,           //Ŀ��ͷ��
	UI_ZORDER_MAINUI				,           //�����
	UI_ZORDER_JOYSTICK				,           //ҡ��
	UI_ZORDER_SHORTCUT				,           //�����
	UI_ZORDER_SECONDARYBTN			,           //������ť���
	UI_ZORDER_PROMPT_MSG		    ,   	  //��Ļ������ʾ��Ϣ��壨����Ѱ·���һ��еȣ�
	UI_ZORDER_INSTANT_CHAT_PANEL    ,   	  //ʵʱ����

	UI_ZORDER_LEFT_FLOATER_LIST	    ,   	      //�����б�\����
	UI_ZORDER_STORE_PANEL           ,           //VIP �̵�panel

	UI_ZORDER_STALL_PANEL		    ,           //��̯panel

	UI_ZORDER_TEMP_BACKPACK		    ,       //��ʱ����

	UI_ZORDER_SOCIETY				,       //�罻
	UI_ZORDER_MYTEAM				,       //�ҵĶ���
	UI_ZORDER_CHAT					,       //����

	UI_ZORDER_SKILL				    ,   	  //����
	UI_ZORDER_EQUIP				    ,   	  //װ��
	UI_ZORDER_ROLE					,       //���� �����ԣ�װ�������壬�����ⵤ��
	UI_ZORDER_HORN					,       //����
	UI_ZORDER_NPC_DIALOG			,       //NPC�Ի�
	UI_ZORDER_EVERQUEST_DIALOG		,       //�ճ�����Ի�
	UI_ZORDER_TASK_DIALOG			,       //����Ի���
	UI_ZORDER_TASK_PANEL            ,       //�������

	UI_ZORDER_BACKPACK				,       //����
	UI_ZORDER_STORAGE 			    ,       //�ֿ�

	UI_ZORDER_SMALLMAP				,       //С��ͼ
	UI_ZORDER_PET					,       //�������
	UI_ZORDER_MOUNT					,       //�������
	UI_ZORDER_MOUNT_UPGRADE_RANK    ,       //����������
	UI_ZORDER_MOUNT_HANDBOOK         ,       //����ͼ�����
	UI_ZORDER_REFINE				,       //����

	UI_ZORDER_GUILD				    ,       //����panel
	UI_ZORDER_GUILD_STORAGE		    ,       //���Ųֿ�panel
	UI_ZORDER_GUILD_MEMBER_OPERATION,      //�����ų�Ա�Ĳ���


	UI_ZORDER_SETTING				,       //����
	UI_ZORDER_AUTOGAME				,       //�Զ��һ�
	UI_ZORDER_GOALS				    ,       //Ŀ��
	UI_ZORDER_MOLD					,       //����
	UI_ZORDER_INSTANCETIP			,       //������ʾ
	UI_ZORDER_ACTIVITY				,       //� ��110�Ğ�105���Ա�׌�����ڻ��ui֮��

	UI_ZORDER_EXPRESSION_PANEL		,       //����panel

	UI_ZORDER_TARGETPOPUP			,       //���Ŀ��ͷ�񵯿�
	UI_ZORDER_REBORN				,       //������
	UI_ZORDER_DEBUG				    ,       //����
	UI_ZORDER_SHOPPANEL			    ,       //�̳�shoplayer
	UI_ZORDER_MAIL_PANEL		    ,       //�ʼ�panel
	UI_ZORDER_RANK_PANEL		    ,       //���а�panel
	UI_ZORDER_PRAY_PANEL		    ,       //��panel ��Ե
	UI_ZORDER_LOG_REWARD_PANEL      ,       //������½panel
	UI_ZORDER_ONLINE_REWARD_PANEL   ,       //���߽���panel
	UI_ZORDER_ACHIEVE_PANEL         ,       //�ɾ�panel
	UI_ZORDER_VIP_PANEL             ,       //VIP panel
	UI_ZORDER_AUTOGAME_MAP_PANEL    ,       //�һ���ͼPanel
	UI_ZORDER_NPC_BUY_PANEL         ,       //NPC�̵깺��panel
	UI_ZORDER_ACTIVITY_ANSWER_PANEL ,       //����ͨ��panel
	UI_ZORDER_BATTLE_FIELD			,		//ս��

	UI_ZORDER_INSTANCE_VOTE_PANEL ,         //��������ͶƱpanel	
	UI_ZORDER_INSTANCE_SKILL_PANEL,          //���⸱���������
	UI_ZORDER_SEARCH_PLAYER_PANEL   ,       //�������panel

	UI_ZORDER_SHORTCUT_MANAGER_PANEL,       //���������panel 
	UI_ZORDER_OFFLINE_EXP_PANEL     ,       //���߹һ����
	UI_ZORDER_WING_PANEL            ,       //�ɽ����
	UI_ZORDER_DANMEDICINE_PANEL     ,       //��ҩ
	UI_ZORDER_ZHANXING_PANEL        ,         //ռ��
	UI_ZORDER_SPA_PANEL             ,              //��Ȫ
	UI_ZORDER_COMPANION_SITDOWN_PANEL  ,              //˫��

	UI_ZORDER_SKILL_PT_PANEL		,       //����ʩ��������panel
	UI_ZORDER_SYS_ROLLINGSUBTITLE	,       //ϵͳ��Ϣ�����
	UI_ZORDER_GAINITEM_PANEL		,       //��õ�����ʾ���
	UI_ZORDER_QUICKBUY_PANEL        ,       //���ٹ������
	UI_ZORDER_PILIANGHECHENG_PANEL  ,       //�����ϳ����
	UI_ZORDER_MOVENODE              ,       //�϶�����Ʒ
	UI_ZORDER_COMFIREM				,       //ȷ�Ͽ�
	UI_ZORDER_TIPS					,       //TIPS
	UI_ZORDER_OPT_TIPS				,       // ����ť��TIPS
	UI_ZORDER_SKILL_BOOK__TIPS		,       // ������tips
	UI_ZORDER_ERRROMSG              ,       //error msg
	UI_ZORDER_NOOB_PANEL			,       //���������ɰ�
	UI_ZORDER_TOP_LAYER             ,       //ĳЩ��ʾ����:�������,��������
	UI_ZORDER_SYS_MB				,       //ϵͳ��ʾ��
	UI_ZORDER_PERFORMANCE			,		//���ܲ�����ʾ���
};

/////////////ͼƬ��ַ/////////////
#define UI_COMMON_1_PLIST			"ui/ui_common_1.plist"         //��ͨ�ǾŹ���ͼƬ1
#define UI_COMMON_SUDOKU_1_PLIST	"ui/ui_common_sudoku_1.plist"  //��ͨ�Ź���ͼƬ1
#define UI_ACHIEVE_PLIST			"ui/ui_achieve.plist"          //�ɾ�
#define UI_CHAT_PLIST				"ui/ui_chat.plist"             //����
#define UI_DANMEDICINE_PLIST        "ui/ui_danMedicine.plist"      //��ҩ
#define UI_GUILD_PLIST              "ui/ui_guild.plist"            //����
#define UI_HEADIMAGE_PLIST          "ui/ui_headImage.plist"        //���npc,�����ͷ����Ϣ_headImage
#define UI_HOTBAR_PLIST             "ui/ui_hotbar.plist"           //�����
#define UI_JOYSTICK_PLIST           "ui/ui_joystick.plist"         //ҡ��
#define UI_MENUBARBTN_PLIST         "ui/ui_menubarBtn.plist"       //�˵���ť
#define UI_MOLD_PLIST               "ui/ui_mold.plist"             //����
#define UI_PET_PLIST                "ui/ui_pet.plist"              //����
#define UI_ROLE_PLIST               "ui/ui_role.plist"             //����(���ԣ�װ��)_role
#define UI_SMALLMAP_PLIST           "ui/ui_samllmap.plist"         //С��ͼ
#define UI_SHOP_PLIST               "ui/ui_shop.plist"             //�̳�
#define UI_SKILL_PLIST              "ui/ui_skill.plist"            //����
#define UI_SOCIETY_PLIST            "ui/ui_society.plist"          //�罻�����Ѷ��飩_society
#define UI_VENATION_PLIST           "ui/ui_venation.plist"         //��������_venation
#define UI_SETTING_PLIST			"ui/ui_setting.plist"          //����_setting
#define UI_NPC_TITLE_PLIST          "ui/ui_npc_title.plist"         //NPCtitle
#define UI_NPC_TITLE_1_PLIST        "ui/ui_npc_title_1.plist"       //NPCtitle
#define UI_ROLE_TOP_TITLE_PLIST		"ui/roleTopTitle.plist"        //��ɫ�ƺ�
#define UI_NEW_NPC_DIALOG          "ui/npcdialog.plist"
#define UI_NPC_HEAD                   "headImg/npchead.plist"         //npcͷ��
#define UI_NPC_DIALOG_PLIST               "ui/ui_npc_dialog.plist"       //NPC�Ի���
#define UI_NPC_DIALOG_1_PLIST              "ui/ui_npc_dialog1.plist"

#define UI_COMMON_1		      "ui/ui_common_1.pvr.ccz"         //��ͨ�ǾŹ���ͼƬ1
#define UI_COMMON_SUDOKU_1    "ui/ui_common_sudoku_1.pvr.ccz"  //��ͨ�Ź���ͼƬ1
#define UI_ACHIEVE	          "ui/ui_achieve.pvr.ccz"          //�ɾ�
#define UI_CHAT		          "ui/ui_chat.pvr.ccz"             //����
#define UI_DANMEDICINE        "ui/ui_danMedicine.pvr.ccz"      //��ҩ
#define UI_GUILD              "ui/ui_guild.pvr.ccz"            //����
#define UI_HEADIMAGE          "ui/ui_headImage.pvr.ccz"        //���npc,�����ͷ����Ϣ_headImage
#define UI_HOTBAR             "ui/ui_hotbar.pvr.ccz"           //�����
#define UI_JOYSTICK           "ui/ui_joystick.pvr.ccz"         //ҡ��
#define UI_MENUBARBTN         "ui/ui_menubarBtn.pvr.ccz"       //�˵���ť
#define UI_MOLD               "ui/ui_mold.pvr.ccz"             //����
#define UI_PET                "ui/ui_pet.pvr.ccz"              //����
#define UI_ROLE               "ui/ui_role.pvr.ccz"             //����(���ԣ�װ��)_role
#define UI_SMALLMAP           "ui/ui_samllmap.pvr.ccz"         //С��ͼ
#define UI_SHOP               "ui/ui_shop.pvr.ccz"             //�̳�
#define UI_SKILL              "ui/ui_skill.pvr.ccz"            //����
#define UI_SOCIETY            "ui/ui_society.pvr.ccz"          //�罻�����Ѷ��飩_society
#define UI_VENATION           "ui/ui_venation.pvr.ccz"         //��������_venation
#define UI_SETTING			  "ui/ui_setting.pvr.ccz"          //����_setting
#define UI_NPC_TITLE          "ui/ui_npc_title.pvr.ccz"         //NPCtitle
#define UI_NPC_TITLE_1        "ui/ui_npc_title_1.pvr.ccz"       //NPCtitle
#define UI_ROLE_TOP_TITLE     "ui/roleTopTitle.pvr.ccz"        //��ɫ�ƺ�
#define UI_DIALOG             "ui/ui_npc_dialog.pvr.ccz"
/////////////////////////////////////////////

#define FULL_SCREEN_BG_CCC4  ccc4(40,75,60,100)  //��͸����ȫ�������������͸
#define NORMAL_TEXT_SCALE    0.75   //  18/24 = 0.75. ��ͨ����CCLabelBMFont ������
#define FONT_CH											"fonts/font.fnt"   //����ͼƬ
#define TITLE_FONT_CH									"fonts/titleFnt.fnt"   //��������ͼƬ
#define GRID_BLANK_FILENAME								"ui/itemimage/unknown.pvr.ccz"

////////////////////////////////ͼƬ��Դ/////////////////////////////

//////////һ�㱳�������ƣ��߿��ͼƬ///////////

///////������
#define MAIN_BG_387_164          "main_bg_387_164.png"    
#define MAIN_BG_387_164_CCRect    CCRect(140,90,160,45)

///////һ��Ź��񱳾���Ԫ��
#define COMMON_FRAME_37_46 		            "common_frame_37_46.png"    //�߿�
#define COMMON_FRAME_37_46_RECT				 CCRect(6, 6, 25, 34)

#define BAR_BG_127_18                        "bar_bg_127_18.png"
#define BAR_117_8                            "bar_117_8.png"

#define BG_204_43							"bg_204_43.png"
#define BG_204_43_RECT						CCRect(10,10,184,23)	

#define BG_209_79							"bg_209_79.png"
#define BG_209_79_RECT						CCRect(20,15,169,49)

#define BG_65_65                            "bg_65_65.png"
#define BG_65_65_CCRect                      CCRect(10,10,45,45)

#define DIALOG_BG                           "npcdlg.png"
#define DIALOG_BG_CCRect                     CCRect(50,50,324,352)

#define DIALOG_LIAOTIAN                     "dialog_liaotian.png"
#define DIALOG_LIAOTIAN_CCRect               CCRect(50,60,40,30)

#define BG_143_143        "bg_143_143.png"
#define BG_143_143_CCRect  CCRect(25,60,50,50)

#define BG_138_118         "bg_138_118.png"
#define BG_138_118_CCRect  CCRect(55,45,35,35)

#define BG_100_40         "bg_100_40.png"
#define BG_100_40_CCRect   CCRect(10,10,80,20)

#define BG_196_53			"bg_196_53.png"
#define BG_196_53_CCRect     CCRect(10,10,176,33)

#define BG_89_42			"bg_89_42.png"
#define BG_89_42_CCRect     CCRect(10,10,69,22)

#define SPLIT_2_38_HORIZ       "splitline_horiz_2_38.png"
#define SPLIT_2_38_HORIZ_CCRect   CCRect(0,0,2,38)

#define SPLIT_400_3_VERTICAL     "splitline_vertical_400_3.png"
#define SPLIT_400_3_VERTICAL_CCRect     CCRect(0,0,400,3)

#define BG_117_102				"bg_117_102.png"
#define BG_117_102_RECT        CCRect(10,10,97,82)

#define BG_106_81			"bg_106_81.png"
#define BG_106_81_CCRect    CCRect(10,10,86,61)

#define BG_TRANSPARENT_42_42  "bg_transparent_42_42.png"   //ȫ͸������
#define BG_TRANSPARENT_42_42_CCRect  CCRect(5,5,32,32)


#define BG_48_50            "bg_48_50.png"       //�ڶ��㱳��
#define BG_48_50_RECT		CCRect(10,10,28,30)

#define BG_41_35           "bg_41_35.png"
#define BG_41_35_RECT		CCRect(10,10,21,15)

#define BG_92_31                  "bg_92_31.png"
#define BG_92_31_CCRect            CCRect(5, 5, 82, 21)

#define BG_92_82          "bg_92_82.png"
#define BG_92_82_CCRect   CCRect(10,10,72,62)  

#define TIPS_BG_56_53         "tips_bg_56_53.png"
#define TIPS_BG_56_53_CCRect   CCRect(10,10,36,33)  

///////һ��ǾŹ��񱳾���Ԫ��
#define BLANK_SPACE_1_1   "blank_space_1_1.png"   //�հ�һ����
#define GOLD_BG		"gold_bg.png"
#define GOLD_IMAGE_15_15      "gold_iamge_15_15.png"     //Ԫ��ͼƬ
#define TICKET_IMAGE_15_15    "ticket_iamge_15_15.png"   //��ȯͼƬ

#define TITLE_BG_263_52        "title_bg_263_52.png"
#define TITLE_BG_214_70        "title_bg_214_70.png"
#define COMMON_SMALL_BG_281_29    "common_small_bg_281_29.png"
#define COMMON_SMALL_BG_216_44    "common_small_bg_216_44.png"
#define COMMON_SMALL_BG_356_38    "common_small_bg_356_38.png"
#define COMMON_SMALL_BG_214_32    "common_small_bg_214_32.png"
#define COMMON_SMALL_BG_292_52    "common_small_bg_292_52.png"

#define CLASS_MAGIC_UI									"FS.png"//��ʦ
#define CLASS_RANGE_UI									"LS.png"//����
#define CLASS_MELEE_UI									"WS.png"//սʿ

//grid���
#define GRID_BG												"grid_bg.png" 
#define GRID_LOCKED_BG										"grid_locked_bg.png"  
#define LOCK_IMAGE											"lock.png"  
#define CD_IMAGE											"cd.png"  
#define GRID_COLORRECT_INNER								"grid_colorRect_inner.png"
#define GRID_COLORRECT_OUTNER								"grid_colorRect_outner.png"
#define GRID_RESULT_ITEM                                       "grid_result_item_128_128.png"
#define GRID_RESULT_ITEM_CCRect                                 CCRect(0,0,128,128)

//ҡ�˶�Ӧ
#define JOYSTICK_1	"joystick1.png"
#define JOYSTICK_2	"joystick2.png"
//��ҩ��Ӧ
#define DAN_LU_JI_HUO     "dan_lu_ji_huo_227_196.png"
#define DAN_LU_WEI_JI_HUO "dan_lu_wei_ji_huo_227_196.png"
#define DAN_YAO_WORKING   "dan_lu_working_227_196.png"
#define DAN_LU_BG_915_186 "dan_lu_bg_915_186.png"
#define FRAME_WITH_GRID_103_103  "frame_with_grid_103_103.png"
//�������
#define PET_BG			        "pet_bg.png"
//��������
#define SHORTCUT_BTN			"shortcut.png"
//����
#define BG_SEND_FLOWER_323_303 "sendFlower.png" 

/////////////////////button/////////////////////

//�ǾŹ���button
#define  CLOSE_BTN_45_45_NORMAL						 "closeBtn_45_45_normal.png"
#define  CLOSE_BTN_45_45_SELECTED					 "closeBtn_45_45_selected.png"

#define BTN_TURN_LEFT_31_26_NORMAL				 "btn_turn_left_31_26_normal.png"
#define BTN_TURN_LEFT_31_26_SELECTED			 "btn_turn_left_31_26_selected.png"
#define BTN_TURN_RIGHT_31_26_NORMAL				 "btn_turn_right_31_26_normal.png"
#define BTN_TURN_RIGHT_31_26_SELECTED			 "btn_turn_right_31_26_selected.png"

#define ARROW_LEFT_ENABLE									"arrow_left_enable.png"
#define ARROW_LEFT_UNENABLE									"arrow_left_unenable.png"
#define ARROW_RIGHT_ENABLE									"arrow_right_enable.png"
#define ARROW_RIGHT_UNENABLE								"arrow_right_unenable.png"

#define BTN_64_25_NORMAL      								"btn_64_25_normal.png"  
#define BTN_64_25_SELECTED									"btn_64_25_selected.png"

#define BTN_170_50_NORMAL								   "btn_170_50_normal.png"
#define BTN_170_50_SELECT								   "btn_170_50_select.png"

#define BUTTON_88_29_NORMAL									     "button_88_29_normal.png"   
#define BUTTON_88_29_DISPALY								     "button_88_29_display.png"  
#define BUTTON_88_29_SELECT									     "button_88_29_select.png" 

#define BTN_TOGGLE_LEFT_NORMAL		"btn_left_55_57_normal.png"
#define BTN_TOGGLE_LEFT_SELECTED	"btn_left_55_57_selected.png"
#define BTN_TOGGLE_RIGHT_NORMAL		"btn_right_55_57_normal.png"
#define BTN_TOGGLE_RIGHT_SELECTED	"btn_right_55_57_selected.png"

#define BTN_205_56_NORMAL    "btn_205_56_normal.png"
#define BTN_205_56_SELECETED "btn_205_56_selected.png"

#define BTN_129_47_NORMAL    "btn_129_47_normal.png"
#define BTN_129_47_SELECTED  "btn_129_47_selected.png"

#define BTN_147_44_NORMAL    "btn_147_44_normal.png"
#define BTN_147_44_SELECTED  "btn_147_44_selected.png"

//�Ź���button
#define BTN_45_45_NORMAL				  "btn_45_45_normal.png"   
#define BTN_45_45_SELECT				  "btn_45_45_select.png" 
#define BTN_45_45_CCRect                  CCRect(10,10,25,25)

#define BTN_PLUS_48_47_NORMAL				    "btn_plus_48_47_normal.png"   
#define BTN_PLUS_48_47_SELECT			        "btn_plus_48_47_selected.png" 
#define BTN_PLUS_48_47_CCRect                 CCRect(0, 0, 35, 35)

#define BTN_SUBSTRACT_47_47_NORMAL				"btn_substract_47_47_normal.png"   
#define BTN_SUBSTRACT_47_47_SELECT				"btn_substract_47_47_selected.png" 
#define BTN_SUBSTRACT_47_47_CCRect               CCRect(0, 0, 35, 35)

#define BTN_PULL_DOWN_NORMAL		"btn_pull_down_normal.png" 
#define BTN_PULL_DOWN_SELECT		"btn_pull_down_select.png" 
#define BTN_PULL_DOWN_CCRect		CCRect(10, 10, 64, 25) 

#define BTN_91_45_NORMAL   "btn_91_45_normal.png"      //��ͨ��һ���˵���ť
#define BTN_91_45_SELECTED "btn_91_45_selected.png"
#define BTN_91_45_DISABLED "btn_91_45_disabled.png"
#define BTN_91_45_CCRect   CCRect(30,15,30,10)

#define M_BTN_91_45_NORMAL   "m_btn_91_45_normal.png"      //��ͨ��һ���˵���ť(������ʾ)
#define M_BTN_91_45_SELECTED "m_btn_91_45_selected.png"
#define M_BTN_91_45_DISABLED "m_btn_91_45_disabled.png"
#define M_BTN_91_45_CCRect   CCRect(30,15,30,10)


#define BTN_RADIO_68_53_NORMAL   "btn_radio_68_53_normal.png"   //RADIO_BTN ��һ���˵���ť
#define BTN_RADIO_68_53_SELECTED "btn_radio_68_53_selected.png"
#define BTN_RADIO_68_53_DISABLED "btn_radio_68_53_disabled.png"
#define BTN_RADIO_68_53_CCRect  CCRect(25,25,10,10)


#define BTN_TOUMING_42_42         "btn_touming_42_42.png"   //͸����ť
#define BTN_TOUMING_42_42_CCRect   CCRect(10,10,22,22)

#define BTN_HUISE_164_63		"btn_huise_164_63.png"   //��ɫ��ť
#define BTN_HUISE_164_63_CCRect		CCRect(10,10,144,43) 

#define BTN_FLOWER_212_45_NORMAL       "btn_flower_212_45_normal.png"
#define BTN_FLOWER_212_45_SELECT       "btn_flower_212_45_selected.png"
#define BTN_FLOWER_212_45_NORMAL_RECT    CCRect(60,10,92,25)


//CHECK BTN
#define BTN_CHECK_16_16_NORMAL             "btn_check_16_16_normal.png"
#define BTN_CHECK_16_16_SELECTED           "btn_check_16_16_selected.png"

#define BTN_CHECKBOX_16_16_NORMAL	       "btn_checkBox_16_16_normal.png"
#define BTN_CHECKBOX_16_16_SELECTED        "btn_checkBox_16_16_selected.png"

#define BTN_CHECK_30_30_NORMAL				"btn_check_30_30_normal.png"
#define BTN_CHECK_30_30_SELECTED			"btn_check_30_30_selected.png"

#define BTN_CHECK_33_33_NORMAL              "btn_check_33_33_normal.png"
#define BTN_CHECK_33_33_SELECTED            "btn_check_33_33_selected.png"

////////////////////////////////////////Ǯ������///////////////////////////////////

#define  MONEY_BOUND_SILVER 1   		//����Ϸ��
#define  MONEY_GOLD 2  					//��ֵԪ��
#define  MONEY_TICKET 3 				//��ȯ
#define  MONEY_CHARGE_INTEGRAL 4	    //��ֵ����
#define  MONEY_CONSUMPTION_INTEGRAL 5	//���ѻ���
#define  MONEY_SILVER 6		            //��Ϸ��
#define  MONEY_HONOR  7					//����
#define  TYPE_GUILD_CONTRIBUTION 10     //�Ź�

//����


#define REFINE_SUCCESS            11425     //���Ƴɹ�

//�̳ǹ���ʧ��
#define ERRNO_NPC_EXCEPTION       10403     //δ֪����
#define ERROR_PACKEGE_FULL        10051     //������
#define ERROR_LESS_INTEGRAL       10070     //���ֲ���
#define ERROR_LESS_GOLD           10071     //Ԫ������
#define ERROR_LESS_TICKET         10072     //��ȯ����
#define ERROR_LIMIT_COUNT         10073     //������Ʒ������
#define ERROR_LIMIT_TIME          10074     //��ʱ��Ʒ�ѳ�ʱ
#define ERROR_PRICE_PREPAIR       10075     //��������۸�ƥ�䣬��ˢ��ҳ��
#define ERROR_MALL_ITEM_RESTRICT  10078     //�㳬�������������
#define ERROR_SALES_ITEM_SHELVES  10079     //�Ż���Ʒ���¼�


//targetPopup btn
#define TARGETPOPUP_BTN_ADDFRIEND	0x0001//��Ϊ����
#define TARGETPOPUP_BTN_CREATETEAM	0x0002//��������
#define TARGETPOPUP_BTN_FOLLOW		0x0004//����
#define TARGETPOPUP_BTN_DELFRIEND	0x0008//ɾ������
#define TARGETPOPUP_BTN_WHISPER		0x0010//˽��

////////////��������ϵ������/////////////
#define ROLE_SELECT_EQUIP      0
#define ROLE_SELECT_ATTRIBUTE  1
#define ROLE_SELECT_SKILL      2
#define ROLE_SELECT_VENATION   3
#define ROLE_SELECT_VENATION_BONE   4
#define ROLE_SELECT_DANYAO      5
#define ROLE_SELECT_WINGS       6

////////////�ʼ����/////////////
#define   MAIL_SELECT_TYPE_ALL     0   //ȫ��
#define   MAIL_SELECT_TYPE_XITONG  1   //ϵͳ
#define   MAIL_SELECT_TYPE_SIREN   2   //˽��
#define   MAIL_SELECT_TYPE_TANWEI  3   //̯λ
#define   MAIL_SELECT_TYPE_WEIDU   4   //δ��
#define   MAIL_SELECT_TYPE_YIDU    5   //�Ѷ�

#define  MAIL_TYPE_XITONG  1   //ϵͳ�ʼ�
#define  MAIL_TYPE_SIREN   2    //˽���ʼ�
#define  MAIL_TYPE_TANWEI  3   //̯λ�ʼ�

#define  MAIL_REC  0
#define  MAIL_SEND 1

///////////////////////////////

#define INPUTNUMPANEL_SRC_SHOP  1  //inputNumPanel ������Դ

/////////////��������������������� tag/////////////
#define ROLE_ATTR_FLG_FACTION          1 //ְҵ
#define ROLE_ATTR_FLG_CRIMEVALUE       2 //���
#define ROLE_ATTR_FLG_LEVEL            3 //�ȼ�
#define ROLE_ATTR_FLG_GUILDNAME        4 //����
#define ROLE_ATTR_FLG_CUR_TOL_HP       5 //����
#define ROLE_ATTR_FLG_CURWX_MAX_SOUL   6 //����
#define ROLE_ATTR_FLG_CUR_TOL_MP       7 //����
#define ROLE_ATTR_FLG_CUR_UP_EXP       8 //����
#define ROLE_ATTR_FLG_FIGHTFORCE       9 //ս��ֵ
#define ROLE_ATTR_FLG_POWER            10 //������Զ����ħ��
#define ROLE_ATTR_FLG_MELEE_DEF        11 //����
#define ROLE_ATTR_FLG_RANGE_DEF        12 //Զ��
#define ROLE_ATTR_FLG_MAGIC_DEF        13 //ħ��
#define ROLE_ATTR_FLG_HITRATE          14 //����
#define ROLE_ATTR_FLG_DODGE            15 //����
#define ROLE_ATTR_FLG_CRIT             16 //����
#define ROLE_ATTR_FLG_CRIT_DAG         17 //����
#define ROLE_ATTR_FLG_TOUGH            18 //����
#define ROLE_ATTR_FLG_AGILE            19 //����
#define ROLE_ATTR_FLG_STRENGTH         20 //����
#define ROLE_ATTR_FLG_INTELLIGENCE     21 //����
#define ROLE_ATTR_FLG_STAMINA          22 //����
#define ROLE_ATTR_FLG_IMU_RESIST     23 // ���⡢����
#define ROLE_ATTR_FLG_MELEE_IMU      24 //���̼���
#define ROLE_ATTR_FLG_RANGE_IMU      25 //Զ�̼���
#define ROLE_ATTR_FLG_MAGIC_IMU      26 //ħ������
#define ROLE_ATTR_FLG_IMP_RESIST     27 //������
#define ROLE_ATTR_FLG_NOR_RESIST     28 //��Ѫ����
#define ROLE_ATTR_FLG_SLN_RESIST     29 //��Ĭ����
#define ROLE_ATTR_FLG_DAZE_RESIST    30 //���Կ���
#define ROLE_ATTR_FLG_POISON_RESIST  31 //��������
//////////////////////////////////////////////////////////////
#define FONT_SIZE_18    18

//////////////////////////////////////////////////////////////
#define GAP  10            //��������Ļ�߿�10
#define LEFT_HEIGHT_TOP    75
#define LEFT_HEIGHT_BOTTOM 30 
#define LEFT_WIDTH_RIGHT   25
#define LEFT_WIDTH_LEFT    25
///////////////////////////////////////////////////////////////

//////////////////////����qualty ������ɫ///////////////////////
#define  QUALTY_CCC3_0   ccc3(255,255,255)
#define  QUALTY_CCC3_1   ccc3(0,255,0)
#define  QUALTY_CCC3_2   ccc3(33,99,255)
#define  QUALTY_CCC3_3   ccc3(255,0,255)
#define  QUALTY_CCC3_4   ccc3(0xff,0xf0,0x00)
#define  QUALTY_CCC3_5   ccc3(89,89,89)
////////////////////////////////////////////////////////////////

#define FONT_ALIAS_DEFAULT_24	"my_font_default_24"//Ĭ������
#define FONT_ALIAS_DEFAULT_20	"my_font_default_20"
#define FONT_ALIAS_DEFAULT_18	"my_font_default_18"
#define FONT_ALIAS_DEFAULT_16	"my_font_default_16"
#define FONT_ALIAS_ARIAL_24		"my_font_arial_24"


////////////////////////// MainUI�ϵ�btn tag //////////////////////////////////////
#define BTN_LIANQI		1
#define BTN_QIANKUN		2
#define BTN_RENWU		3
#define BTN_TAOBAO		4
#define BTN_XIANCHONG	5
#define BTN_XIANMEN		6
#define BTN_XIANSHU		7
#define BTN_XIANYOU		8
#define BTN_XIANYUAN	9
#define BTN_ZAOWU		10
#define BTN_MOUNT       11
#define BTN_SETTING     12
/////////////////////////������ɫ//////////////////////////////////////
//#define  CH_WHITE   ccc3(0xff,0xff,0xfb)
//#define  CH_YELLOW   ccc3(0xff,0xe6,0x00)
//#define  CH_PURPLE   ccc3(0xaa,0x2d,0xef)
//#define  CH_BLUE   ccc3(0x1a,0x5d,0xe5)
//#define  CH_GREEN   ccc3(0xb2,0xd2,0x35)
//#define  CH_RED   ccc3(0xe5,0x19,0x07)

static const cocos2d::ccColor3B CH_WHITE (0xff,0xff,0xfb);//��ɫ
static const cocos2d::ccColor3B CH_YELLOW (0xff,0xe6,0x00);//��ɫ
static const cocos2d::ccColor3B CH_PURPLE (0xaa,0x2d,0xef);//��ɫ
static const cocos2d::ccColor3B CH_BLUE (0x1a,0x5d,0xe5);//��ɫ
static const cocos2d::ccColor3B CH_GREEN (0xb2,0xd2,0x35);//��ɫ
static const cocos2d::ccColor3B CH_RED (0xe5,0x19,0x07);//��ɫ

//////////////////////////�رհ�ť��λ��//////////////////////////////////////////
#define  CLOSE_BTN_POS_X  bgWidth-45/2-GAP+3
#define  CLOSE_BTN_POS_Y  bgHeight-45/2-GAP
////////////////////////////////////////////////////////////////////

extern "C"
{
	//��ʼ�������ļ�
	void initDFont();
};

//
class tLinkDataEx: public tLinkData
{
public:
	int position;//��list�е�λ��
	cocos2d::ccColor3B color;//��ɫֵ
	int type;//���ͣ�0����ͨ�������κζ��� 1��Ѱ·������npc  2����ĳ��壩
};