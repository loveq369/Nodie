#pragma once

#include "cocos2d.h"
#include "gamecore.h"



///////////////////////字体/////////////////////////////////////
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



//布局方式
#define ALIGN_ITEMS_HORIZONTALLY_TOP	0//水平布局，上
#define ALIGN_ITEMS_VERTICALLY_LEFT		1//垂直布局，左

#define ALIGN_ITEM_HORIZONTALLY_LEFT	0//水平居左
#define ALIGN_ITEM_HORIZONTALLY_CENTER	1//水平居中
#define ALIGN_ITEM_HORIZONTALLY_RIGHT	2//水平居右

#define TEXT_ALIGNMENT_LEFT		1	//文字在图片外部左边
#define TEXT_ALIGNMENT_CENTER	2	//文字在图片内部中间
#define TEXT_ALIGNMENT_RIGHT	3	//文字在图片外部右边
///////////////////////UI显示顺序   ZORDER//////////////////////
enum zorder
{
	UI_ZORDER_INIT					,            //初始化spriteFrame
	UI_ZORDER_EXP					,           //经验条
	UI_ZORDER_ROLE_HEAD			    ,   	      //自己头像
	UI_ZORDER_TARGET_HEAD			,           //目标头像
	UI_ZORDER_MAINUI				,           //主面板
	UI_ZORDER_JOYSTICK				,           //摇杆
	UI_ZORDER_SHORTCUT				,           //快捷栏
	UI_ZORDER_SECONDARYBTN			,           //二级按钮面板
	UI_ZORDER_PROMPT_MSG		    ,   	  //屏幕中上提示信息面板（正在寻路、挂机中等）
	UI_ZORDER_INSTANT_CHAT_PANEL    ,   	  //实时聊天

	UI_ZORDER_LEFT_FLOATER_LIST	    ,   	      //任务列表\队友
	UI_ZORDER_STORE_PANEL           ,           //VIP 商店panel

	UI_ZORDER_STALL_PANEL		    ,           //摆摊panel

	UI_ZORDER_TEMP_BACKPACK		    ,       //临时背包

	UI_ZORDER_SOCIETY				,       //社交
	UI_ZORDER_MYTEAM				,       //我的队伍
	UI_ZORDER_CHAT					,       //聊天

	UI_ZORDER_SKILL				    ,   	  //技能
	UI_ZORDER_EQUIP				    ,   	  //装备
	UI_ZORDER_ROLE					,       //人物 （属性，装备，炼体，炼神，外丹）
	UI_ZORDER_HORN					,       //喇叭
	UI_ZORDER_NPC_DIALOG			,       //NPC对话
	UI_ZORDER_EVERQUEST_DIALOG		,       //日常任务对话
	UI_ZORDER_TASK_DIALOG			,       //任务对话框
	UI_ZORDER_TASK_PANEL            ,       //任务面板

	UI_ZORDER_BACKPACK				,       //背包
	UI_ZORDER_STORAGE 			    ,       //仓库

	UI_ZORDER_SMALLMAP				,       //小地图
	UI_ZORDER_PET					,       //宠物面板
	UI_ZORDER_MOUNT					,       //坐骑面板
	UI_ZORDER_MOUNT_UPGRADE_RANK    ,       //坐骑进阶面板
	UI_ZORDER_MOUNT_HANDBOOK         ,       //坐骑图鉴面板
	UI_ZORDER_REFINE				,       //造物

	UI_ZORDER_GUILD				    ,       //仙门panel
	UI_ZORDER_GUILD_STORAGE		    ,       //仙门仓库panel
	UI_ZORDER_GUILD_MEMBER_OPERATION,      //对仙门成员的操作


	UI_ZORDER_SETTING				,       //设置
	UI_ZORDER_AUTOGAME				,       //自动挂机
	UI_ZORDER_GOALS				    ,       //目标
	UI_ZORDER_MOLD					,       //炼器
	UI_ZORDER_INSTANCETIP			,       //副本提示
	UI_ZORDER_ACTIVITY				,       //活动 由110改為105，以便讓煉器在活動ui之上

	UI_ZORDER_EXPRESSION_PANEL		,       //表情panel

	UI_ZORDER_TARGETPOPUP			,       //点击目标头像弹框
	UI_ZORDER_REBORN				,       //重生框
	UI_ZORDER_DEBUG				    ,       //调试
	UI_ZORDER_SHOPPANEL			    ,       //商城shoplayer
	UI_ZORDER_MAIL_PANEL		    ,       //邮件panel
	UI_ZORDER_RANK_PANEL		    ,       //排行榜panel
	UI_ZORDER_PRAY_PANEL		    ,       //祈福panel 仙缘
	UI_ZORDER_LOG_REWARD_PANEL      ,       //连续登陆panel
	UI_ZORDER_ONLINE_REWARD_PANEL   ,       //在线奖励panel
	UI_ZORDER_ACHIEVE_PANEL         ,       //成就panel
	UI_ZORDER_VIP_PANEL             ,       //VIP panel
	UI_ZORDER_AUTOGAME_MAP_PANEL    ,       //挂机地图Panel
	UI_ZORDER_NPC_BUY_PANEL         ,       //NPC商店购买panel
	UI_ZORDER_ACTIVITY_ANSWER_PANEL ,       //博古通今panel
	UI_ZORDER_BATTLE_FIELD			,		//战场

	UI_ZORDER_INSTANCE_VOTE_PANEL ,         //副本队伍投票panel	
	UI_ZORDER_INSTANCE_SKILL_PANEL,          //特殊副本技能面板
	UI_ZORDER_SEARCH_PLAYER_PANEL   ,       //查找玩家panel

	UI_ZORDER_SHORTCUT_MANAGER_PANEL,       //快捷栏配置panel 
	UI_ZORDER_OFFLINE_EXP_PANEL     ,       //离线挂机面板
	UI_ZORDER_WING_PANEL            ,       //飞剑面板
	UI_ZORDER_DANMEDICINE_PANEL     ,       //丹药
	UI_ZORDER_ZHANXING_PANEL        ,         //占星
	UI_ZORDER_SPA_PANEL             ,              //温泉
	UI_ZORDER_COMPANION_SITDOWN_PANEL  ,              //双修

	UI_ZORDER_SKILL_PT_PANEL		,       //技能施法进度条panel
	UI_ZORDER_SYS_ROLLINGSUBTITLE	,       //系统信息跑马灯
	UI_ZORDER_GAINITEM_PANEL		,       //获得道具提示面板
	UI_ZORDER_QUICKBUY_PANEL        ,       //快速购买面板
	UI_ZORDER_PILIANGHECHENG_PANEL  ,       //批量合成面板
	UI_ZORDER_MOVENODE              ,       //拖动的物品
	UI_ZORDER_COMFIREM				,       //确认框
	UI_ZORDER_TIPS					,       //TIPS
	UI_ZORDER_OPT_TIPS				,       // 带按钮的TIPS
	UI_ZORDER_SKILL_BOOK__TIPS		,       // 技能书tips
	UI_ZORDER_ERRROMSG              ,       //error msg
	UI_ZORDER_NOOB_PANEL			,       //新手引导蒙版
	UI_ZORDER_TOP_LAYER             ,       //某些提示比如:完成任务,接收任务
	UI_ZORDER_SYS_MB				,       //系统提示框
	UI_ZORDER_PERFORMANCE			,		//性能不足提示面板
};

/////////////图片地址/////////////
#define UI_COMMON_1_PLIST			"ui/ui_common_1.plist"         //共通非九宫格图片1
#define UI_COMMON_SUDOKU_1_PLIST	"ui/ui_common_sudoku_1.plist"  //共通九宫格图片1
#define UI_ACHIEVE_PLIST			"ui/ui_achieve.plist"          //成就
#define UI_CHAT_PLIST				"ui/ui_chat.plist"             //聊天
#define UI_DANMEDICINE_PLIST        "ui/ui_danMedicine.plist"      //丹药
#define UI_GUILD_PLIST              "ui/ui_guild.plist"            //仙门
#define UI_HEADIMAGE_PLIST          "ui/ui_headImage.plist"        //人物，npc,怪物等头像信息_headImage
#define UI_HOTBAR_PLIST             "ui/ui_hotbar.plist"           //快捷栏
#define UI_JOYSTICK_PLIST           "ui/ui_joystick.plist"         //摇杆
#define UI_MENUBARBTN_PLIST         "ui/ui_menubarBtn.plist"       //菜单按钮
#define UI_MOLD_PLIST               "ui/ui_mold.plist"             //造物
#define UI_PET_PLIST                "ui/ui_pet.plist"              //宠物
#define UI_ROLE_PLIST               "ui/ui_role.plist"             //人物(属性，装备)_role
#define UI_SMALLMAP_PLIST           "ui/ui_samllmap.plist"         //小地图
#define UI_SHOP_PLIST               "ui/ui_shop.plist"             //商城
#define UI_SKILL_PLIST              "ui/ui_skill.plist"            //技能
#define UI_SOCIETY_PLIST            "ui/ui_society.plist"          //社交（好友队伍）_society
#define UI_VENATION_PLIST           "ui/ui_venation.plist"         //炼体炼神_venation
#define UI_SETTING_PLIST			"ui/ui_setting.plist"          //设置_setting
#define UI_NPC_TITLE_PLIST          "ui/ui_npc_title.plist"         //NPCtitle
#define UI_NPC_TITLE_1_PLIST        "ui/ui_npc_title_1.plist"       //NPCtitle
#define UI_ROLE_TOP_TITLE_PLIST		"ui/roleTopTitle.plist"        //角色称号
#define UI_NEW_NPC_DIALOG          "ui/npcdialog.plist"
#define UI_NPC_HEAD                   "headImg/npchead.plist"         //npc头像
#define UI_NPC_DIALOG_PLIST               "ui/ui_npc_dialog.plist"       //NPC对话框
#define UI_NPC_DIALOG_1_PLIST              "ui/ui_npc_dialog1.plist"

#define UI_COMMON_1		      "ui/ui_common_1.pvr.ccz"         //共通非九宫格图片1
#define UI_COMMON_SUDOKU_1    "ui/ui_common_sudoku_1.pvr.ccz"  //共通九宫格图片1
#define UI_ACHIEVE	          "ui/ui_achieve.pvr.ccz"          //成就
#define UI_CHAT		          "ui/ui_chat.pvr.ccz"             //聊天
#define UI_DANMEDICINE        "ui/ui_danMedicine.pvr.ccz"      //丹药
#define UI_GUILD              "ui/ui_guild.pvr.ccz"            //仙门
#define UI_HEADIMAGE          "ui/ui_headImage.pvr.ccz"        //人物，npc,怪物等头像信息_headImage
#define UI_HOTBAR             "ui/ui_hotbar.pvr.ccz"           //快捷栏
#define UI_JOYSTICK           "ui/ui_joystick.pvr.ccz"         //摇杆
#define UI_MENUBARBTN         "ui/ui_menubarBtn.pvr.ccz"       //菜单按钮
#define UI_MOLD               "ui/ui_mold.pvr.ccz"             //造物
#define UI_PET                "ui/ui_pet.pvr.ccz"              //宠物
#define UI_ROLE               "ui/ui_role.pvr.ccz"             //人物(属性，装备)_role
#define UI_SMALLMAP           "ui/ui_samllmap.pvr.ccz"         //小地图
#define UI_SHOP               "ui/ui_shop.pvr.ccz"             //商城
#define UI_SKILL              "ui/ui_skill.pvr.ccz"            //技能
#define UI_SOCIETY            "ui/ui_society.pvr.ccz"          //社交（好友队伍）_society
#define UI_VENATION           "ui/ui_venation.pvr.ccz"         //炼体炼神_venation
#define UI_SETTING			  "ui/ui_setting.pvr.ccz"          //设置_setting
#define UI_NPC_TITLE          "ui/ui_npc_title.pvr.ccz"         //NPCtitle
#define UI_NPC_TITLE_1        "ui/ui_npc_title_1.pvr.ccz"       //NPCtitle
#define UI_ROLE_TOP_TITLE     "ui/roleTopTitle.pvr.ccz"        //角色称号
#define UI_DIALOG             "ui/ui_npc_dialog.pvr.ccz"
/////////////////////////////////////////////

#define FULL_SCREEN_BG_CCC4  ccc4(40,75,60,100)  //半透明，全背景，防点击穿透
#define NORMAL_TEXT_SCALE    0.75   //  18/24 = 0.75. 普通描述CCLabelBMFont 的缩放
#define FONT_CH											"fonts/font.fnt"   //文字图片
#define TITLE_FONT_CH									"fonts/titleFnt.fnt"   //标题文字图片
#define GRID_BLANK_FILENAME								"ui/itemimage/unknown.pvr.ccz"

////////////////////////////////图片资源/////////////////////////////

//////////一般背景，花纹，边框等图片///////////

///////主背景
#define MAIN_BG_387_164          "main_bg_387_164.png"    
#define MAIN_BG_387_164_CCRect    CCRect(140,90,160,45)

///////一般九宫格背景等元素
#define COMMON_FRAME_37_46 		            "common_frame_37_46.png"    //线框
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

#define BG_TRANSPARENT_42_42  "bg_transparent_42_42.png"   //全透明背景
#define BG_TRANSPARENT_42_42_CCRect  CCRect(5,5,32,32)


#define BG_48_50            "bg_48_50.png"       //第二层背景
#define BG_48_50_RECT		CCRect(10,10,28,30)

#define BG_41_35           "bg_41_35.png"
#define BG_41_35_RECT		CCRect(10,10,21,15)

#define BG_92_31                  "bg_92_31.png"
#define BG_92_31_CCRect            CCRect(5, 5, 82, 21)

#define BG_92_82          "bg_92_82.png"
#define BG_92_82_CCRect   CCRect(10,10,72,62)  

#define TIPS_BG_56_53         "tips_bg_56_53.png"
#define TIPS_BG_56_53_CCRect   CCRect(10,10,36,33)  

///////一般非九宫格背景等元素
#define BLANK_SPACE_1_1   "blank_space_1_1.png"   //空白一个点
#define GOLD_BG		"gold_bg.png"
#define GOLD_IMAGE_15_15      "gold_iamge_15_15.png"     //元宝图片
#define TICKET_IMAGE_15_15    "ticket_iamge_15_15.png"   //礼券图片

#define TITLE_BG_263_52        "title_bg_263_52.png"
#define TITLE_BG_214_70        "title_bg_214_70.png"
#define COMMON_SMALL_BG_281_29    "common_small_bg_281_29.png"
#define COMMON_SMALL_BG_216_44    "common_small_bg_216_44.png"
#define COMMON_SMALL_BG_356_38    "common_small_bg_356_38.png"
#define COMMON_SMALL_BG_214_32    "common_small_bg_214_32.png"
#define COMMON_SMALL_BG_292_52    "common_small_bg_292_52.png"

#define CLASS_MAGIC_UI									"FS.png"//法师
#define CLASS_RANGE_UI									"LS.png"//射手
#define CLASS_MELEE_UI									"WS.png"//战士

//grid相关
#define GRID_BG												"grid_bg.png" 
#define GRID_LOCKED_BG										"grid_locked_bg.png"  
#define LOCK_IMAGE											"lock.png"  
#define CD_IMAGE											"cd.png"  
#define GRID_COLORRECT_INNER								"grid_colorRect_inner.png"
#define GRID_COLORRECT_OUTNER								"grid_colorRect_outner.png"
#define GRID_RESULT_ITEM                                       "grid_result_item_128_128.png"
#define GRID_RESULT_ITEM_CCRect                                 CCRect(0,0,128,128)

//摇杆对应
#define JOYSTICK_1	"joystick1.png"
#define JOYSTICK_2	"joystick2.png"
//丹药对应
#define DAN_LU_JI_HUO     "dan_lu_ji_huo_227_196.png"
#define DAN_LU_WEI_JI_HUO "dan_lu_wei_ji_huo_227_196.png"
#define DAN_YAO_WORKING   "dan_lu_working_227_196.png"
#define DAN_LU_BG_915_186 "dan_lu_bg_915_186.png"
#define FRAME_WITH_GRID_103_103  "frame_with_grid_103_103.png"
//宠物相关
#define PET_BG			        "pet_bg.png"
//快捷栏相关
#define SHORTCUT_BTN			"shortcut.png"
//好友
#define BG_SEND_FLOWER_323_303 "sendFlower.png" 

/////////////////////button/////////////////////

//非九宫格button
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

//九宫格button
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

#define BTN_91_45_NORMAL   "btn_91_45_normal.png"      //普通，一级菜单按钮
#define BTN_91_45_SELECTED "btn_91_45_selected.png"
#define BTN_91_45_DISABLED "btn_91_45_disabled.png"
#define BTN_91_45_CCRect   CCRect(30,15,30,10)

#define M_BTN_91_45_NORMAL   "m_btn_91_45_normal.png"      //普通，一级菜单按钮(着重显示)
#define M_BTN_91_45_SELECTED "m_btn_91_45_selected.png"
#define M_BTN_91_45_DISABLED "m_btn_91_45_disabled.png"
#define M_BTN_91_45_CCRect   CCRect(30,15,30,10)


#define BTN_RADIO_68_53_NORMAL   "btn_radio_68_53_normal.png"   //RADIO_BTN ，一级菜单按钮
#define BTN_RADIO_68_53_SELECTED "btn_radio_68_53_selected.png"
#define BTN_RADIO_68_53_DISABLED "btn_radio_68_53_disabled.png"
#define BTN_RADIO_68_53_CCRect  CCRect(25,25,10,10)


#define BTN_TOUMING_42_42         "btn_touming_42_42.png"   //透明按钮
#define BTN_TOUMING_42_42_CCRect   CCRect(10,10,22,22)

#define BTN_HUISE_164_63		"btn_huise_164_63.png"   //灰色按钮
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

////////////////////////////////////////钱币类型///////////////////////////////////

#define  MONEY_BOUND_SILVER 1   		//绑定游戏币
#define  MONEY_GOLD 2  					//充值元宝
#define  MONEY_TICKET 3 				//礼券
#define  MONEY_CHARGE_INTEGRAL 4	    //充值积分
#define  MONEY_CONSUMPTION_INTEGRAL 5	//消费积分
#define  MONEY_SILVER 6		            //游戏币
#define  MONEY_HONOR  7					//荣誉
#define  TYPE_GUILD_CONTRIBUTION 10     //门贡

//炼制


#define REFINE_SUCCESS            11425     //炼制成功

//商城购买失败
#define ERRNO_NPC_EXCEPTION       10403     //未知错误
#define ERROR_PACKEGE_FULL        10051     //包裹满
#define ERROR_LESS_INTEGRAL       10070     //积分不够
#define ERROR_LESS_GOLD           10071     //元宝不够
#define ERROR_LESS_TICKET         10072     //礼券不够
#define ERROR_LIMIT_COUNT         10073     //限量物品已卖空
#define ERROR_LIMIT_TIME          10074     //限时物品已超时
#define ERROR_PRICE_PREPAIR       10075     //与服务器价格不匹配，请刷新页面
#define ERROR_MALL_ITEM_RESTRICT  10078     //你超过购买个数限制
#define ERROR_SALES_ITEM_SHELVES  10079     //优惠物品已下架


//targetPopup btn
#define TARGETPOPUP_BTN_ADDFRIEND	0x0001//加为好友
#define TARGETPOPUP_BTN_CREATETEAM	0x0002//创建队伍
#define TARGETPOPUP_BTN_FOLLOW		0x0004//跟随
#define TARGETPOPUP_BTN_DELFRIEND	0x0008//删除好友
#define TARGETPOPUP_BTN_WHISPER		0x0010//私聊

////////////人物面板上的子面板/////////////
#define ROLE_SELECT_EQUIP      0
#define ROLE_SELECT_ATTRIBUTE  1
#define ROLE_SELECT_SKILL      2
#define ROLE_SELECT_VENATION   3
#define ROLE_SELECT_VENATION_BONE   4
#define ROLE_SELECT_DANYAO      5
#define ROLE_SELECT_WINGS       6

////////////邮件相关/////////////
#define   MAIL_SELECT_TYPE_ALL     0   //全部
#define   MAIL_SELECT_TYPE_XITONG  1   //系统
#define   MAIL_SELECT_TYPE_SIREN   2   //私人
#define   MAIL_SELECT_TYPE_TANWEI  3   //摊位
#define   MAIL_SELECT_TYPE_WEIDU   4   //未读
#define   MAIL_SELECT_TYPE_YIDU    5   //已读

#define  MAIL_TYPE_XITONG  1   //系统邮件
#define  MAIL_TYPE_SIREN   2    //私人邮件
#define  MAIL_TYPE_TANWEI  3   //摊位邮件

#define  MAIL_REC  0
#define  MAIL_SEND 1

///////////////////////////////

#define INPUTNUMPANEL_SRC_SHOP  1  //inputNumPanel 引用来源

/////////////人物属性面板上属性区分 tag/////////////
#define ROLE_ATTR_FLG_FACTION          1 //职业
#define ROLE_ATTR_FLG_CRIMEVALUE       2 //罪恶
#define ROLE_ATTR_FLG_LEVEL            3 //等级
#define ROLE_ATTR_FLG_GUILDNAME        4 //仙门
#define ROLE_ATTR_FLG_CUR_TOL_HP       5 //生命
#define ROLE_ATTR_FLG_CURWX_MAX_SOUL   6 //灵力
#define ROLE_ATTR_FLG_CUR_TOL_MP       7 //法力
#define ROLE_ATTR_FLG_CUR_UP_EXP       8 //经验
#define ROLE_ATTR_FLG_FIGHTFORCE       9 //战力值
#define ROLE_ATTR_FLG_POWER            10 //近攻、远攻、魔攻
#define ROLE_ATTR_FLG_MELEE_DEF        11 //近防
#define ROLE_ATTR_FLG_RANGE_DEF        12 //远防
#define ROLE_ATTR_FLG_MAGIC_DEF        13 //魔防
#define ROLE_ATTR_FLG_HITRATE          14 //命中
#define ROLE_ATTR_FLG_DODGE            15 //闪避
#define ROLE_ATTR_FLG_CRIT             16 //暴击
#define ROLE_ATTR_FLG_CRIT_DAG         17 //暴伤
#define ROLE_ATTR_FLG_TOUGH            18 //韧性
#define ROLE_ATTR_FLG_AGILE            19 //敏捷
#define ROLE_ATTR_FLG_STRENGTH         20 //力量
#define ROLE_ATTR_FLG_INTELLIGENCE     21 //智力
#define ROLE_ATTR_FLG_STAMINA          22 //体质
#define ROLE_ATTR_FLG_IMU_RESIST     23 // 减免、抗性
#define ROLE_ATTR_FLG_MELEE_IMU      24 //近程减免
#define ROLE_ATTR_FLG_RANGE_IMU      25 //远程减免
#define ROLE_ATTR_FLG_MAGIC_IMU      26 //魔法减免
#define ROLE_ATTR_FLG_IMP_RESIST     27 //定身抗性
#define ROLE_ATTR_FLG_NOR_RESIST     28 //流血抗性
#define ROLE_ATTR_FLG_SLN_RESIST     29 //沉默抗性
#define ROLE_ATTR_FLG_DAZE_RESIST    30 //昏迷抗性
#define ROLE_ATTR_FLG_POISON_RESIST  31 //消弱抗性
//////////////////////////////////////////////////////////////
#define FONT_SIZE_18    18

//////////////////////////////////////////////////////////////
#define GAP  10            //背景到屏幕边空10
#define LEFT_HEIGHT_TOP    75
#define LEFT_HEIGHT_BOTTOM 30 
#define LEFT_WIDTH_RIGHT   25
#define LEFT_WIDTH_LEFT    25
///////////////////////////////////////////////////////////////

//////////////////////根据qualty 设置颜色///////////////////////
#define  QUALTY_CCC3_0   ccc3(255,255,255)
#define  QUALTY_CCC3_1   ccc3(0,255,0)
#define  QUALTY_CCC3_2   ccc3(33,99,255)
#define  QUALTY_CCC3_3   ccc3(255,0,255)
#define  QUALTY_CCC3_4   ccc3(0xff,0xf0,0x00)
#define  QUALTY_CCC3_5   ccc3(89,89,89)
////////////////////////////////////////////////////////////////

#define FONT_ALIAS_DEFAULT_24	"my_font_default_24"//默认字体
#define FONT_ALIAS_DEFAULT_20	"my_font_default_20"
#define FONT_ALIAS_DEFAULT_18	"my_font_default_18"
#define FONT_ALIAS_DEFAULT_16	"my_font_default_16"
#define FONT_ALIAS_ARIAL_24		"my_font_arial_24"


////////////////////////// MainUI上的btn tag //////////////////////////////////////
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
/////////////////////////字体颜色//////////////////////////////////////
//#define  CH_WHITE   ccc3(0xff,0xff,0xfb)
//#define  CH_YELLOW   ccc3(0xff,0xe6,0x00)
//#define  CH_PURPLE   ccc3(0xaa,0x2d,0xef)
//#define  CH_BLUE   ccc3(0x1a,0x5d,0xe5)
//#define  CH_GREEN   ccc3(0xb2,0xd2,0x35)
//#define  CH_RED   ccc3(0xe5,0x19,0x07)

static const cocos2d::ccColor3B CH_WHITE (0xff,0xff,0xfb);//白色
static const cocos2d::ccColor3B CH_YELLOW (0xff,0xe6,0x00);//黄色
static const cocos2d::ccColor3B CH_PURPLE (0xaa,0x2d,0xef);//紫色
static const cocos2d::ccColor3B CH_BLUE (0x1a,0x5d,0xe5);//蓝色
static const cocos2d::ccColor3B CH_GREEN (0xb2,0xd2,0x35);//绿色
static const cocos2d::ccColor3B CH_RED (0xe5,0x19,0x07);//红色

//////////////////////////关闭按钮的位置//////////////////////////////////////////
#define  CLOSE_BTN_POS_X  bgWidth-45/2-GAP+3
#define  CLOSE_BTN_POS_Y  bgHeight-45/2-GAP
////////////////////////////////////////////////////////////////////

extern "C"
{
	//初始化字体文件
	void initDFont();
};

//
class tLinkDataEx: public tLinkData
{
public:
	int position;//在list中的位置
	cocos2d::ccColor3B color;//颜色值
	int type;//类型（0：普通，不打开任何东西 1：寻路到副本npc  2：打开某面板）
};