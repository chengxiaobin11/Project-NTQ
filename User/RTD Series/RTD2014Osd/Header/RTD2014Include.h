/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RTD2014Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "RTD2014Project.h"
#include "RTD2014NVRamOsd.h"
#include "RTD2014OsdTextTableDefine.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

extern BYTE Cross_flag ;

#ifndef _CT_DEFAULT
#define _CT_DEFAULT                               _CT_6500
#endif

#if 1//
#define _PAGE_MAX_LANGUAGE_COUNT   9
#else
#define _PAGE_MAX_LANGUAGE_COUNT    9
#endif

typedef enum //menuitem
{
	
    _MENU_NONE,
#if(_NAVIGAT_MENU_SURPPORT)
	_MENU_NAVIGAT_NONE,
#endif
	_OSD_MAIN_SOURCE,
	_OSD_MAIN_BRI_CON,
	_OSD_MAIN_COLOR_SETTING,
	_OSD_MAIN_PQ_SETTING,
	_OSD_MAIN_DISPLAY,  //7

#if(_OSD_7PAGE || _DEF_PAGE8)
     _OSD_MAIN_AUDIO,
#endif
	_OSD_MAIN_OSD,
	_OSD_MAIN_OTHER,
	_OSD_MAIN_FACTORY,   //11


    _MENU_PICTURE_TATE0,
	_MENU_PICTURE_TATE1,
	_MENU_PICTURE_TATE2,
	_MENU_PICTURE_TATE3,
	_MENU_PICTURE_TATE4,
	_MENU_PICTURE_TATE5, //17
#if(_DEF_PAGE8)
	_MENU_PICTURE_TATE6, //17
#endif

    _MENU_DISPLAY_TATE0,
	_MENU_DISPLAY_TATE1,
	_MENU_DISPLAY_TATE2,
	_MENU_DISPLAY_TATE3,
	_MENU_DISPLAY_TATE4,
	_MENU_DISPLAY_TATE5,  //23	
#if(_DEF_PAGE8)
	_MENU_DISPLAY_TATE6, //17
#endif

    _MENU_COLORTEMP_TATE0,
	_MENU_COLORTEMP_TATE1,
	_MENU_COLORTEMP_TATE2,
	_MENU_COLORTEMP_TATE3,
	_MENU_COLORTEMP_TATE4,
	_MENU_COLORTEMP_TATE5,  //29
#if(_DEF_PAGE8)
	_MENU_COLORTEMP_TATE6, //17
#endif

    _MENU_OSDSETTING_TATE0,
	_MENU_OSDSETTING_TATE1,
	_MENU_OSDSETTING_TATE2,
	_MENU_OSDSETTING_TATE3,
	_MENU_OSDSETTING_TATE4,
	_MENU_OSDSETTING_TATE5,  //35
#if(_DEF_PAGE8)
	_MENU_OSDSETTING_TATE6, //17
#endif

#if(_OSD_7PAGE)

    _MENU_AUDIO_TATE0,
    _MENU_AUDIO_TATE1,
    _MENU_AUDIO_TATE2,
    _MENU_AUDIO_TATE3,
    _MENU_AUDIO_TATE4,
    _MENU_AUDIO_TATE5,  //41
#elif(_DEF_PAGE8)
	_MENU_AUDIO_TATE0,
    _MENU_AUDIO_TATE1,
    _MENU_AUDIO_TATE2,
    _MENU_AUDIO_TATE3,
    _MENU_AUDIO_TATE4,
    _MENU_AUDIO_TATE5,  //41
    _MENU_AUDIO_TATE6,  //41
#endif

    _MENU_RESET_TATE0,
	_MENU_RESET_TATE1,
	_MENU_RESET_TATE2,
	_MENU_RESET_TATE3,
	_MENU_RESET_TATE4,
	_MENU_RESET_TATE5,   //47
#if(_DEF_PAGE8)
	_MENU_RESET_TATE6,	 //47
#endif

    _MENU_MISC_TATE0,
	_MENU_MISC_TATE1,
	_MENU_MISC_TATE2,
	_MENU_MISC_TATE3,
	_MENU_MISC_TATE4,
	_MENU_MISC_TATE5,  //53
#if(_DEF_PAGE8)
	_MENU_MISC_TATE6,  //53
#endif

	_MENU_FUN_BACKLIGHT,	
	_MENU_FUN_CONTRAST,
	_MENU_FUN_BRIGHTNESS,
	_MENU_FUN_SHARPNESS,
	_MENU_FUN_ECO,
	_MENU_FUN_DCR,
	_MENU_FUN_HDR,   //60
	
	_MENU_FUN_VGA_HPOSITON,	
	_MENU_FUN_VGA_VPOSITON,	
	_MENU_FUN_VGA_CLK, 
	_MENU_FUN_VGA_PHASE,
	_MENU_FUN_ASPECT,  //65

	
	_MENU_FUN_COLORTEMP,	
	_MENU_FUN_R,	
	_MENU_FUN_G,	
	_MENU_FUN_B,	//69

	_MENU_FUN_LANGUAGE,	
	_MENU_FUN_OSD_HPOSITON, 
	_MENU_FUN_OSD_VPOSITON, 
	_MENU_FUN_OSD_TIME, 
	_MENU_FUN_OSD_TRANS, //74
	
	_MENU_FUN_AUTO_ADJUST,	
	_MENU_FUN_AUTO_COLOR,	
	_MENU_FUN_RESET,	//77

	_MENU_FUN_SIGNAL,	
	_MENU_FUN_LOWBLUE,		
	_MENU_FUN_AUDOIMUTE,
	_MENU_FUN_AUDOIVOLUME, //81
    #if _FREESYNC_SUPPORT
	_MENU_FUN_FREESYNC,
    #endif
	_MENU_FUN_OD,
	_MENU_FUN_POWER_OFF,
	_MENU_FUN_LED,	//85
	_MENU_FUN_FLICKER_FREE,
	_MENU_FUN_MPRT,
	_MENU_FUN_GAMMA,
	_MENU_FUN_COLORGAMUT, 
	_MENU_FUN_SATURATION,	//���Ͷ�
	_MENU_FUN_OVERCLOCK,  //91
	_MENU_FUN_HUE,
    _MENU_FUN_DCC,

	_MENU_FUN_FV_INFORMATION,	//Ƶ����ʾ
	_MENU_FUN_DDCCI,

    _MENU_FUN_DP_VER,	//DP�汾   //96
    _MENU_FUN_OSD_RORATE,	//��ת
    _MENU_FUN_VIVID,//������  Super Resolution //vivid
	_MENU_FUN_AUDIO_SOURCE,	//��Ƶѡ��
	_MENU_FUN_CHAOPING_TISHI,	//��Ƶ��ʾ
	_MENU_FUN_KVM,
	_MENU_FUN_HDR_COLOR,	//HDRɫ����ǿ
    _MENU_FUN_CROSS, //new add
	_MENU_FUN_SAVING_MODE, //hh

#if(_DEF_HOTKEY_REPLACE)
	_MENU_FUN_HOT_REPLACE_LEFT,	//��ݼ�ģʽ�л�	//102
	_MENU_FUN_HOT_REPLACE_RIGHT,	//��ݼ�ģʽ�л�  ��
	_MENU_FUN_HOT_REPLACE_EXIT,	//��ݼ�ģʽ�л�  ����
#endif

#if(_DEF_STA_SIX_COLOR)
	_MENU_FUN_SAT_STATE,	//���Ͷ���ɫ
	_MENU_FUN_HUE_STATE,	//ɫ�����Ͷ���ɫ

	_MENU_FUN_SAT_RED,
	_MENU_FUN_SAT_GREEN,
	_MENU_FUN_SAT_BLUE,
	_MENU_FUN_SAT_CYAN,
	_MENU_FUN_SAT_MAGENTA,
	_MENU_FUN_SAT_YELLOW,
	
	_MENU_FUN_HUE_RED,
	_MENU_FUN_HUE_GREEN,
	_MENU_FUN_HUE_BLUE,
	_MENU_FUN_HUE_CYAN,
	_MENU_FUN_HUE_MAGENTA,
	_MENU_FUN_HUE_YELLOW,
#endif

#if(_DEF_OPPOSITE_DCR)
	_MENU_FUN_DCR_OPPOSITE, //����ģʽ   //����DCR	
#endif
#if(_LED_EFFECT_TJMODE14)
        _MENU_FUN_LIGHTMODE,
        _MENU_FUN_COLOR,
#endif

	_MENU_FUN_HOTLEFT,
	_MENU_FUN_HOTRIGHT,  //102
	
    _MENU_FUN_RGB,//add for press enter RGB while colortemp is user 
	_MENU_NULL,
/***_**********Spacil Hotkey Func************/
	_HOT_KEY_LOS_TYPE1,	
	_HOT_KEY_LOS_TYPE2,  //106
	_MENU_FUN_SOURCE_HOTKEY,

#if _ENABLE_ENERGE_NOTICE_MENU
	_MENU_FUN_SHOW_ENERGE_MENU,
#endif

#if 1//_LONG_PRESS_MENU_LOCK_OSD_ENABLE
	_MENU_FUN_LOCK_MENU,
#endif

#if 1//_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
	_MENU_FUN_POWERKEY_LOCK_MENU,
#endif

/*******************************************/
	
	_MENU_MESSAGE,  //111
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
	   _MENU_ENGER_CONSUMPTION,	 //Enger Consumption
#endif
	_MENU_HOT_KEY_FUNC,  //123
	
	_MENU_END ,
	
	_OSD_MSG_MENU = _MENU_END,
   
}EnumOsdMenuState;



#define OsdDisplayDetOverRangeSelect       OsdDisplayDetOverRangeRotation// OsdDisplayDetOverRange


#if(_OSD_7PAGE||_DEF_PAGE8)
#define _OSD_MAIN_MENU_COUNT  7
#else
#define _OSD_MAIN_MENU_COUNT  6
#endif



extern BYTE g_flag_Nosignal;

#if(_DEF_PAGE8)
extern BYTE idata OsdStateDefine[_OSD_MAIN_MENU_COUNT][7];
#else
extern BYTE idata OsdStateDefine[_OSD_MAIN_MENU_COUNT][6];
#endif

extern BYTE idata OSD_MASK[_OSD_MAIN_MENU_COUNT];  
extern int SwapRotateValue(int value);

extern BYTE idata OSD_MAIN_MENU_ITEM;
extern BYTE idata OSD_SubMenuCur;

#if(_PROJECT == _RL6463_PROJECT)
extern BYTE idata OSD_ITEM_BASE[_MENU_NULL - _MENU_FUN_BACKLIGHT];
#else
extern BYTE xdata OSD_ITEM_BASE[_MENU_NULL - _MENU_FUN_BACKLIGHT];
#endif

extern BYTE idata OSD_ITEM_MASK[10];

extern BYTE xdata g_ucOsdRorateState;
#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))
extern WORD BackUpTempVFreq;
#endif


// OSD_ITEM_MASK��ʱֻ��hotkeyʹ��,����λ��������ʡ�ռ�,6λ������֧��48�ֹ���

/****************************OSD_MASK[]��һЩ����********************************/
#define OSD_ITEM_MASK_SET(x)  (OSD_ITEM_MASK[(x - _MENU_FUN_BACKLIGHT)/8] |= (0x01<<((x - _MENU_FUN_BACKLIGHT)%8)))
#define OSD_ITEM_MASK_CLR(x)  (OSD_ITEM_MASK[(x - _MENU_FUN_BACKLIGHT)/8] &= ~(0x01<<((x - _MENU_FUN_BACKLIGHT)%8)))
#define OSD_ITEM_MASK_GET(x)  (OSD_ITEM_MASK[(x - _MENU_FUN_BACKLIGHT)/8]&(0x01<<((x - _MENU_FUN_BACKLIGHT)%8)))

/****************************OSD_ITEM_BASE[]��һЩ����****************************/
#define OSD_ITEM(x)       OSD_ITEM_BASE[x - _MENU_FUN_BACKLIGHT]
#define OSD_MASK_SET(x)  (OSD_MASK[OSD_ITEM(x)>>4] |= (0x01<<(OSD_ITEM(x)&0x0f))); (OSD_ITEM(x) == 0xff)?0: OSD_ITEM_MASK_SET(x)
#define OSD_MASK_CLR(x)  (OSD_MASK[OSD_ITEM(x)>>4] &= ~(0x01<<(OSD_ITEM(x)&0x0f)));(OSD_ITEM(x) == 0xff)?0: OSD_ITEM_MASK_CLR(x)
#define OSD_MASK_GET(x)  (OSD_MASK[OSD_ITEM(x)>>4] & (0x01<<(OSD_ITEM(x)&0x0f)))
#define OSD_MASK(x,y)  		(OSD_MASK[x] &  (0x01<<y))
#define OSD_MASKSET(x,y)    (OSD_MASK[x] |= (0x01<<y))
/*OSD_MASK_SET �� OSD_MASK ����������:
* OSD_MASK_SET�������Ĳ����ǹ��ܣ�����_MENU_FUN_BACKLIGHT
* OSD_MASK�������Ĳ�����OSD���λ�ã������һ������ĵ�һ��
*/


//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
#define _A0_INPUT_TYPE                              (_INPUT_VGA)
#else
#define _A0_INPUT_TYPE                              (_INPUT_NO_PORT)
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
#define _D0_INPUT_TYPE                              (_INPUT_DVI)
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
#define _D0_INPUT_TYPE                              (_INPUT_HDMI)
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
#define _D0_INPUT_TYPE                              (_INPUT_DP)
#elif(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#define _D0_INPUT_TYPE                              (_INPUT_MHL)
#else
#define _D0_INPUT_TYPE                              (_INPUT_NO_PORT)
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
#define _D1_INPUT_TYPE                              (_INPUT_DVI)
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
#define _D1_INPUT_TYPE                              (_INPUT_HDMI)
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#define _D1_INPUT_TYPE                              (_INPUT_DP)
#elif(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#define _D1_INPUT_TYPE                              (_INPUT_MHL)
#else
#define _D1_INPUT_TYPE                              (_INPUT_NO_PORT)
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
#define _D2_INPUT_TYPE                              (_INPUT_DVI)
#elif(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
#define _D2_INPUT_TYPE                              (_INPUT_HDMI)
#elif(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
#define _D2_INPUT_TYPE                              (_INPUT_DP)
#elif(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#define _D2_INPUT_TYPE                              (_INPUT_MHL)
#else
#define _D2_INPUT_TYPE                              (_INPUT_NO_PORT)
#endif


#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
#define _D3_INPUT_TYPE                              (_INPUT_DVI)
#elif(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
#define _D3_INPUT_TYPE                              (_INPUT_HDMI)
#elif(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
#define _D3_INPUT_TYPE                              (_INPUT_MHL)
#else
#define _D3_INPUT_TYPE                              (_INPUT_NO_PORT)
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
#define _D4_INPUT_TYPE                              ( _INPUT_DVI)
#elif(_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)
#define _D4_INPUT_TYPE                              (_INPUT_HDMI)
#elif(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define _D4_INPUT_TYPE                              ( _INPUT_MHL)
#else
#define _D4_INPUT_TYPE                              ( _INPUT_NO_PORT)
#endif


#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
#define _D5_INPUT_TYPE                              ( _INPUT_DVI)
#elif(_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)
#define _D5_INPUT_TYPE                              (_INPUT_HDMI)
#elif(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define _D5_INPUT_TYPE                              ( _INPUT_MHL)
#else
#define _D5_INPUT_TYPE                              ( _INPUT_NO_PORT)
#endif



#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
#define _D6_INPUT_TYPE                              ( _INPUT_DP)
#else
#define _D6_INPUT_TYPE                              ( _INPUT_NO_PORT)
#endif

#define _OSD_NAVIGAT_MENU_WIDTH                     19
#define _OSD_NAVIGAT_MENU_HEIGHT                    3


#if(_OSD_BLACK_WHITE_TYPE)
#define		_COLOR_BG_0								_CP_BLACK	
#define		_COLOR_BG_1								_CP_WHITE	
#define		_COLOR_BG_2								_CP_WHITE	
#define		_COLOR_BG_3								_CP_BLACK	

#define		_COLOR_MENU_FONT						_CP_WHITE	
#define		_COLOR_MENU_FONT_SELECT					_CP_DARKBLUE	


#define    _ICON_SELECT_BACK_COLOR0                 _CP_LIGHTBLUE
#define    _ICON_UNSELECT_BACK_COLOR0               _CP_BLACK_1

#else
#define		_COLOR_BG_0								_CP_BLUE	
#define		_COLOR_BG_1								_CP_DARKBLUE	
#define		_COLOR_BG_2								_CP_WHITE //DISPLAY MESSAGE	
#define		_COLOR_BG_3								_CP_LIGHTGRAY	



#define    _ICON_SELECT_BACK_COLOR0                 _CP_DARKBLUE
#define    _ICON_UNSELECT_BACK_COLOR0               _CP_LIGHTBLUE


#define		_COLOR_MENU_FONT						_CP_WHITE	
#if (_OSD_BLUE_TYPE==_ON)
#define		_COLOR_MENU_FONT_SELECT					_CP_BLUE
#elif 0//
#define		_COLOR_MENU_FONT_SELECT					_CP_BLACK
#else		
#define		_COLOR_MENU_FONT_SELECT					_CP_RED	
#endif
#if 1
#define		_COLOR_WINDOW_BG						 _CP_BG	
#else
#define		_COLOR_WINDOW_BG						 _CP_GRAY	

#endif
#define		_COLOR_MENU_FONT_MASK					_CP_LIGHTGRAY 	


#endif
#define _OSD_ITEM_ROW_START                         4
#define _OSD_ITEM_COL_START                         7
#define _OSD_ITEM_COL_SLIDER                        23
#define _OSD_ITEM_COL_END                           40

#define _OSD_WINDOW_X_START							(12*_ITEM_2_COL)//84
#define _OSD_WINDOW_X_END1							(12*36)//276
#define _OSD_WINDOW_X_END2							480

#define _OSD_WINDOW_X_LANG_LEN						204


#define _OSD_WINDOW_Y_START							72
#define _OSD_WINDOW_Y_END							96

#define _ITEM_1_COL                                 1
#define _ITEM_2_COL                                 19
#define _ITEM_3_COL                                 37

#define _ITEM_COL_LENGTH                            17

#define _ITEM_SLIDER_OFFSET                         6


#define _ITEM_1_ROW                                 3
#define _ITEM_2_ROW                                 5
#define _ITEM_3_ROW                                 7
#define _ITEM_4_ROW                                 9
#define _ITEM_5_ROW                                 11
#define _ITEM_6_ROW                                 13
#define _ITEM_7_ROW                                 15
#define _ITEM_8_ROW                                 17

#define _HOTKEY_ROW_START                           4
#define _HOTKEY_COL_START                            1
#define _HOTKEY_SLIDER_COL                           22
#define _HOTKEY_SILDER_START                         8


#define _HOTKEY_ITEM_1_ROW                          3
#define _HOTKEY_ITEM_2_ROW                          5
#define _HOTKEY_ITEM_3_ROW                          7
#define _HOTKEY_ITEM_4_ROW                          9
#define _HOTKEY_ITEM_5_ROW                          11

#define _INFORMATION_ROW                            15
#define _INFORMATION_COL                            8

#define _TITLE_ROW_START                            1
#define _TITLE_COL_START                            0
#define _TITLE_COL_END                              39
#define _TITLE_PIXEL_OFFSET                         0

#define _OSD_MESSAGE_PIXEL_OFFSET                   0

#define _NOSIGNAL_MSG                               	0
#define _NOCABLE_MSG                                	1
#define _NOSUPPORT_MSG                              	2
#define _FAIL_SAFE_MODE_MSG                         3
#define _AUTO_CONFIG_MSG                            	4
#define _INPUT_SIGNAL_MSG                           	5
#define _SHOW_SOURCE_SELECT_MSG			6

#define _SHOW_SMALL_MESSAGE_WINDOW					0
#define _SHOW_MIDDLE_MESSAGE_WINDOW				1
#define _SHOW_BIG_MESSAGE_WINDOW					2

#if 1
#define _DDCCI_BACKLIGHT_MAX					  100
#define _DDCCI_BACKLIGHT_CENTER				 50
#define _DDCCI_BACKLIGHT_MIN					 0

#define _DDCCI_CONTRAST_MAX					  100
#define _DDCCI_CONTRAST_CENTER				 50
#define _DDCCI_CONTRAST_MIN					 0
#endif

//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
#if(Project_ID == ID_TJZG_TMDTMD2822_HK2775E01_2P2H_UHD60HZ_20231217||\
    Project_ID == ID_TJZG_HK2775E05_M270KCAD8B_EDP4LANHBR2_MD2769_QHD180HZ_20240313||\
    Project_ID == ID_TJZG_HK2775E05_SN245ES01_2_EDP4LANHBR2_MD2569_QHD180HZ_20240528||\
    Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_20240426||\
    Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_G27L61QK_20240509||\
    Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_F2761QK_QHD180HZ_20240416||\
    Project_ID == ID_NTQ_CO27AL_HK2775E01_1P1H_MV270QUM_N10_UHD60HZ)
#define _CONTRAST_MAX                        		2464
#else
#define _CONTRAST_MAX                               2848
#endif

#define _CONTRAST_MIN                               1248

#else
#define _CONTRAST_MAX                               178
#define _CONTRAST_MIN                               78
#endif



#ifndef _CONTRAST_CENTER
#define _CONTRAST_CENTER                           2048// (((_CONTRAST_MAX - _CONTRAST_MIN) / 2) + _CONTRAST_MIN)
#endif
#define _BACKLIGHT_CENTER                           (((_BACKLIGHT_MAX - _BACKLIGHT_MIN) / 2) + _BACKLIGHT_MIN)

//--------------------------------------------------
// Definitions of Brightness Range
//--------------------------------------------------
#if(_BRI_TYPE == _BRI_GEN_1_10BIT)

#define _BRIGHTNESS_MAX                             712
#define _BRIGHTNESS_MIN                             312

#else
#define _BRIGHTNESS_MAX                             178
#define _BRIGHTNESS_MIN                             78
#endif

#define _BRIGHTNESS_CENTER                          (((_BRIGHTNESS_MAX - _BRIGHTNESS_MIN) / 2) + _BRIGHTNESS_MIN)
//--------------------------------------------------
// Definitions of Sharpness Range
//--------------------------------------------------
#define _SHARPNESS_MAX                              4
#define _SHARPNESS_MIN                              0
#define _SHARPNESS_CENTER                           (((_SHARPNESS_MAX - _SHARPNESS_MIN) / 2) + _SHARPNESS_MIN)
//--------------------------------------------------
// Definitions of Phase Range
//--------------------------------------------------
#define _OSD_PHASE_MAX                              100
#define _OSD_PHASE_MIN                              0

//--------------------------------------------------
// Definitions of Colortemp User RGB
//--------------------------------------------------
#define _USER_RGB_MAX                               255
#define _USER_RGB_MIN                               0
#define _USER_RGB_CENTER                            (((_USER_RGB_MAX - _USER_RGB_MIN) / 2) + _USER_RGB_MIN)

//--------------------------------------------------
// Definitions of OD Gain Range
//--------------------------------------------------
#define _OD_GAIN_MAX                                127
#define _OD_GAIN_MIN                                0
#define _OD_GAIN_CENTER                             (((_OD_GAIN_MAX - _OD_GAIN_MIN) / 2) + _OD_GAIN_MIN)

#define _OD_GAIN_DEF                                _OD_GAIN_CENTER
//--------------------------------------------------
// Definitions of 3D EFFECT
//--------------------------------------------------
#define _3D_EFFECT_MAX                              0x10
#define _3D_EFFECT_MIN                              0x00

//--------------------------------------------------
// Definitions of 2DTO3D EFFECT
//--------------------------------------------------
#define _2DTO3D_H_EFFECT_MAX                        0x30
#define _2DTO3D_H_EFFECT_MIN                        0x00

#define _2DTO3D_H_V_EFFECT_MAX                      0xFF
#define _2DTO3D_H_V_EFFECT_MIN                      0x00

//--------------------------------------------------
// Definitions of Menu Time Range
//--------------------------------------------------
#define _OSD_TIMEOUT_MAX                            60
#define _OSD_TIMEOUT_MIN                            10
#define _OSD_TIMEOUT_CENTER                         (((_OSD_TIMEOUT_MAX - _OSD_TIMEOUT_MIN) / 2) + _OSD_TIMEOUT_MIN)
//--------------------------------------------------
// Definitions of Transparency Range
//--------------------------------------------------
#define _OSD_TRANSPARENCY_MAX                       255
#define _OSD_TRANSPARENCY_MIN                       0
#define _OSD_TRANSPARENCY_CENTER                    (((_OSD_TRANSPARENCY_MAX - _OSD_TRANSPARENCY_MIN) / 2) + _OSD_TRANSPARENCY_MIN)
//--------------------------------------------------
// Definitions of OSD H Position Range
//--------------------------------------------------
#define _OSD_H_POS_MAX                              100
#define _OSD_H_POS_MIN                              0
#define _OSD_H_POS_CENTER                           (((_OSD_H_POS_MAX - _OSD_H_POS_MIN) / 2) + _OSD_H_POS_MIN)

//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_V_POS_MAX                              100
#define _OSD_V_POS_MIN                              0
#define _OSD_V_POS_CENTER                           (((_OSD_V_POS_MAX - _OSD_V_POS_MIN) / 2) + _OSD_V_POS_MIN)

//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_ASPECT_ORIGINAL_RATIO_MAX              100
#define _OSD_ASPECT_ORIGINAL_RATIO_MIN              0
#define _OSD_ASPECT_ORIGINAL_RATIO_CENTER           ((_OSD_ASPECT_ORIGINAL_RATIO_MAX - _OSD_ASPECT_ORIGINAL_RATIO_MIN) / 2)

//--------------------------------------------------
// Definitions of Hue Saturation Range
// Allowed Hue = 0 ~ 360, Sat = 0 ~ 330
//--------------------------------------------------
#define _DEFAULT_HUE                                _HUE_CENTER


#if(Project_ID == TEXTF_ID_KAITENG_2795E04_8LANEHBR2)||(Project_ID == _ID_SANSE_2795QR_2K180_NF0_)

#define _DEFAULT_SATURATION                         120


#else

#define _DEFAULT_SATURATION                         _SATURATION_CENTER

#endif
//--------------------------------------------------
// Definitions of OSD Volume Range
//--------------------------------------------------
#define _OSD_VOLUME_MAX                             100
#define _OSD_VOLUME_MIN                             0
#define _OSD_VOLUME_CENTER                          (((_OSD_VOLUME_MAX - _OSD_VOLUME_MIN) / 2) + _OSD_VOLUME_MIN)

//--------------------------------------------------
// Definitions of Hue Saturation Range
//--------------------------------------------------
#define _SIX_COLOR_SATURATION_MAX                   200
#define _SIX_COLOR_SATURATION_MIN                   0
#define _SIX_COLOR_SATURATION_CENTER                100

#define _SIX_COLOR_HUE_MAX                          100
#define _SIX_COLOR_HUE_MIN                          0
#define _SIX_COLOR_HUE_CENTER                       50

//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_KEYSCANSTART()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT1))
#define SET_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT1)
#define CLR_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT1)

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_KEYSCANREADY()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT0))
#define SET_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT0)
#define CLR_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT0)

//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_KEYREPEATSTART()                        (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT2)
#define SET_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl |= _BIT2)
#define CLR_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_KEYREPEATENABLE()                       (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT3)
#define SET_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl |= _BIT3)
#define CLR_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl &= ~_BIT3)

//--------------------------------------------------
// Macro of Key Hold Start
//--------------------------------------------------
#define GET_KEY_HOLD()                              (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT4)
#define SET_KEY_HOLD()                              (g_stOsdInfo.ucOsdKeyControl |= _BIT4)
#define CLR_KEY_HOLD()                              (g_stOsdInfo.ucOsdKeyControl &= ~_BIT4)

#if(_FREESYNC_SUPPORT == _ON)
#define GET_FREESYNC_OSD_ADDRESS()                  (g_stOsdInfo.ucOsdFREESYNCInforOsdAddress)
#define SET_FREESYNC_OSD_ADDRESS(x)                 (g_stOsdInfo.ucOsdFREESYNCInforOsdAddress = (x))
#endif

//--------------------------------------------------
// Macro of Key Message
//--------------------------------------------------
#define GET_KEYMESSAGE()                            (g_stOsdInfo.ucOsdKeyMessage)
#define SET_KEYMESSAGE(x)                           (g_stOsdInfo.ucOsdKeyMessage = (x))

//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
#define _MENU_KEY_MESSAGE                           0
#define _RIGHT_KEY_MESSAGE                          1
#define _LEFT_KEY_MESSAGE                           2
#define _EXIT_KEY_MESSAGE                           3
#define _UP_KEY_MESSAGE                             4
#define _DOWN_KEY_MESSAGE                           5
#define _7_KEY_MESSAGE                              6
#define _HOLD_KEY_MESSAGE                           7
#define _NONE_KEY_MESSAGE                           8
#define _POWER_KEY_MESSAGE							9

#if(_KEY_IR_HUIXIONG_CROOSSOVER)
#define _KEY_AMOUNT                                 7
#else
#define _KEY_AMOUNT                                 5
#endif

//--------------------------------------------------
// Definitions of LED indicction
//--------------------------------------------------
typedef enum
{
    _LED_ALL_OFF = _LED_SYSTEM_END,
} EnumUserLedIndication;

//--------------------------------------------------
// Macro of OSD
//--------------------------------------------------
#define FONTBYTE0(x)                                HIBYTE(0x1000 | (x)), LOBYTE(0x1000 | (x))
#define FONTBYTE1(x)                                HIBYTE(0x5000 | (x)), LOBYTE(0x5000 | (x))
#define FONTBYTE2(x)                                HIBYTE(0x9000 | (x)), LOBYTE(0x9000 | (x))
#define FONTALLBYTE(x)                              HIBYTE(0xD000 | (x)), LOBYTE(0xD000 | (x))
#define WINDOWBYTE0(x)                              HIBYTE(0x0000 | (x)), LOBYTE(0x0000 | (x))
#define WINDOWBYTE1(x)                              HIBYTE(0x4000 | (x)), LOBYTE(0x4000 | (x))
#define WINDOWBYTE2(x)                              HIBYTE(0x8000 | (x)), LOBYTE(0x8000 | (x))
#define WINDOWALLBYTE(x)                            HIBYTE(0xC000 | (x)), LOBYTE(0xC000 | (x))
#define FRAMEBYTE0(x)                               WINDOWBYTE0(x)
#define FRAMEBYTE1(x)                               WINDOWBYTE1(x)
#define FRAMEBYTE2(x)                               WINDOWBYTE2(x)
#define FRAMEALLBYTE(x)                             WINDOWALLBYTE(x)
#define WINNO(x)                                    (x)
#define ROW(x)                                      (x)
#define COL(x)                                      (x)
#define WIDTH(x)                                    (x)
#define HEIGHT(x)                                   (x)
#define LENGTH(x)                                   (x)
#define FGCOLOR(x)                                  (x)
#define BGCOLOR(x)                                  (x)
#define COLOR00(x)                                  (x)
#define COLOR01(x)                                  (x)
#define COLOR10(x)                                  (x)
#define COLOR11(x)                                  (x)
#define XSTART(x)                                   (x)
#define YSTART(x)                                   (x)
#define XEND(x)                                     (x)
#define YEND(x)                                     (x)
#define PIXELROW(x)                                 ((x) * 18)
#define PIXELCOL(x)                                 ((x) * 12)

//--------------------------------------------------
// Definitions of Checking Max or Min Value Used by OsdDisplayDetOverRange()
//--------------------------------------------------
#define _DET_OVERRANGE_MAX                          (0)
#define _DET_OVERRANGE_MIN                          (1)

//--------------------------------------------------
// Definations of OSD Function
//--------------------------------------------------
//flag    0xfb 0x01  0x0c
#define _PAGE_                                      0xFE

#define _SPACE_                                     0xfc
#define _EXT_                                       0xfc
#define _REPEAT_                                    0xfd
#define _NEXT_                                      0xfe
#define _END_                                       0xff


//--------------------------------------------------
// Definations of Write Byte
//--------------------------------------------------
#define _WRITE_BYTE0                                0
#define _WRITE_BYTE1                                1
#define _WRITE_BYTE2                                2
#define _WRITE_BYTEALL                              3


#if(_LED_EFFECT_TJMODE14)
typedef enum
{
	LightMode_OFF=0,
	LightMode_Static,//�ȶ�
	LightMode_Breathe,//����
	LightMode_MarqueeIn,//�������м������˷��⣩
	LightMode_MarqueeOut,//�������������м䷢�⣩
	LightMode_END=LightMode_MarqueeOut,


}EnumLightModeType;



typedef enum
{
	LightColorMode_Spectrum=0,//�Ų� 0
	LightColorMode_Red,//�� 1
	LightColorMode_Green,//�� 2
	LightColorMode_Blue,//�� 3
	LightColorMode_Gyan, // ��ɫ 4
	LightColorMode_Purple, //��ɫ  5
	LightColorMode_Yellow, //��ɫ  6
	LightColorMode_END=LightColorMode_Yellow,//6



}EnumLightCOLORModeType;

#endif

//--------------------------------------------------
// Macro of Osd Put String Mode
//--------------------------------------------------
typedef enum
{
    _PUT_STRING_LEFT = 0,
    _PUT_STRING_CENTER,
    _PUT_STRING_RIGHT,

} EnumOsdPutStringMode;

//--------------------------------------------------
// MACRO for OSD Logo Status
//--------------------------------------------------
#define GET_OSD_LOGO_ON()                           (g_stOsdInfo.b1OsdLogo)
#define SET_OSD_LOGO_ON(x)                          (g_stOsdInfo.b1OsdLogo = (x))

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_WAKE_UP_SWITCH_DDCCI_PORT()         (g_stOsdInfo.b1OsdWakeUpSwitchDdcciPort)
#define SET_OSD_WAKE_UP_SWITCH_DDCCI_PORT(x)        (g_stOsdInfo.b1OsdWakeUpSwitchDdcciPort = (x))
#if(_DP_DEBUG_MSG == _ON)
//--------------------------------------------------
// MACRO for Power Saving Show DP Info
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_DP_INFO()         (g_stOsdInfo.b1OsdWakeUpShowDpINFO)
#define SET_OSD_POWER_SAVING_SHOW_DP_INFO(x)        (g_stOsdInfo.b1OsdWakeUpShowDpINFO = (x))
#define GET_OSD_POWER_SAVING_SHOW_DP_INFO_PORT()    (g_stOsdInfo.b4OsdWakeUpShowDpINFOPort)
#define SET_OSD_POWER_SAVING_SHOW_DP_INFO_PORT(x)   (g_stOsdInfo.b4OsdWakeUpShowDpINFOPort = (x))


#endif

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_SOURCE()          (g_stOsdInfo.b1OsdWakeUpShowSource)
#define SET_OSD_POWER_SAVING_SHOW_SOURCE(x)         (g_stOsdInfo.b1OsdWakeUpShowSource = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
#define GET_OSD_IN_FACTORY_MENU_STATUS()            (g_stOsdInfo.b1OsdFactoryModeStatus)
#define SET_OSD_IN_FACTORY_MENU_STATUS(x)           (g_stOsdInfo.b1OsdFactoryModeStatus = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
#define GET_OSD_DO_ASPECT_RATIO()                   (g_stOsdInfo.b1OsdDoAspectRatio)
#define SET_OSD_DO_ASPECT_RATIO(x)                  (g_stOsdInfo.b1OsdDoAspectRatio = (x))

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_COLOR_FORMAT()                      (g_stOsdInfo.b3OsdColorFormat)
#define SET_OSD_COLOR_FORMAT(x)                     (g_stOsdInfo.b3OsdColorFormat = (x))

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_STATE_PREVIOUS()                    (g_stOsdInfo.ucOsdStatePrevious)
#define SET_OSD_STATE_PREVIOUS(x)                   (g_stOsdInfo.ucOsdStatePrevious = (x))


//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_STATE()                             (g_stOsdInfo.usOsdState)
#define SET_OSD_STATE(x)                            (g_stOsdInfo.usOsdState = (x))

//--------------------------------------------------
// MACRO for Osd Evevt Message
//--------------------------------------------------
#define GET_OSD_EVENT_MESSAGE()                     (g_stOsdInfo.ucOsdEventMsg)
#define SET_OSD_EVENT_MESSAGE(x)                    (g_stOsdInfo.ucOsdEventMsg = (x))

//--------------------------------------------------
// MACRO for Six Color
//--------------------------------------------------
#define GET_OSD_SIX_COLOR()                         (g_stOsdInfo.b3OsdsixColor)
#define SET_OSD_SIX_COLOR(x)                        (g_stOsdInfo.b3OsdsixColor = (x))

//--------------------------------------------------
// MACRO for Six Color Hue
//--------------------------------------------------
#define GET_OSD_SIX_COLOR_HUE()                     (g_stOsdInfo.b3OsdsixColorHue)
#define SET_OSD_SIX_COLOR_HUE(x)                    (g_stOsdInfo.b3OsdsixColorHue = (x))

//--------------------------------------------------
// MACRO for Six Color Saturation
//--------------------------------------------------
#define GET_OSD_SIX_COLOR_SATURATION()              (g_stOsdInfo.b3OsdsixColorSaturation)
#define SET_OSD_SIX_COLOR_SATURATION(x)             (g_stOsdInfo.b3OsdsixColorSaturation = (x))

//--------------------------------------------------
// MACRO for OSD double size
//--------------------------------------------------
#define GET_OSD_DOUBLE_SIZE()                       (g_stOsdInfo.b1OsdDoubleSizeStatus)
#define SET_OSD_DOUBLE_SIZE(x)                      (g_stOsdInfo.b1OsdDoubleSizeStatus = (x))

//--------------------------------------------------
// MACRO for Freeze Status
//--------------------------------------------------
#define GET_OSD_FREEZE_STATUS()                     (g_stOsdInfo.b1FreezeStatus)
#define SET_OSD_FREEZE_STATUS(x)                    (g_stOsdInfo.b1FreezeStatus = (x))

#if((_URGENT_EVENT_CHECK_MODE == _OFF) && (_FREEZE_SUPPORT == _ON))
#define GET_FREEZE_DISABLE_MSG_STATE()              (g_stOsdInfo.b1FreezeDisableOsdStatus)
#define SET_FREEZE_DISABLE_MSG_STATE(x)             (g_stOsdInfo.b1FreezeDisableOsdStatus = (x))
#endif

#define GET_OSD_ITEM_INDEX()                        (g_stOsdInfo.ucOsdItemIndex)
#define SET_OSD_ITEM_INDEX(x)                       (g_stOsdInfo.ucOsdItemIndex = (x))


#define GET_OSD_INFO_STRING_MODE()                  (g_stOsdInfo.b2StringMode)
#define SET_OSD_INFO_STRING_MODE(x)                 (g_stOsdInfo.b2StringMode = x)
#define CLR_OSD_INFO_STRING_MODE()                  (g_stOsdInfo.b2StringMode = _PUT_STRING_LEFT)

//--------------------------------------------------
// Macro of Osd Put String Center Length
//--------------------------------------------------
#define GET_OSD_INFO_STRING_MODE_LENGTH()           (g_stOsdInfo.ucStringModeLength)
#define SET_OSD_INFO_STRING_MODE_LENGTH(x)          (g_stOsdInfo.ucStringModeLength = x)
#define CLR_OSD_INFO_STRING_MODE_LENGTH()           (g_stOsdInfo.ucStringModeLength = 0)

//--------------------------------------------------
// Macro of Osd Put String Blank Pixel
//--------------------------------------------------
#define GET_OSD_INFO_STRING_BLANK_PIXEL()           (g_stOsdInfo.ucStringBlankPixel)
#define SET_OSD_INFO_STRING_BLANK_PIXEL(x)          (g_stOsdInfo.ucStringBlankPixel = x)
#define CLR_OSD_INFO_STRING_BLANK_PIXEL()           (g_stOsdInfo.ucStringBlankPixel = 0)

//==========================================================================================================
// Macro of NVRam BriCon Data
//==========================================================================================================
//--------------------------------------------------
// MACRO for Contrast
//--------------------------------------------------
#define GET_OSD_CONTRAST()                          (g_stBriConData.usContrast)
#define SET_OSD_CONTRAST(x)                         (g_stBriConData.usContrast = (x))

//--------------------------------------------------
// MACRO for Contrast
//--------------------------------------------------
#define GET_OSD_BRIGHTNESS()                        (g_stBriConData.usBrightness)
#define SET_OSD_BRIGHTNESS(x)                       (g_stBriConData.usBrightness = (x))

//==========================================================================================================
// Macro of NVRam User Data
//==========================================================================================================
//--------------------------------------------------
// MACRO for Rotation Status
//--------------------------------------------------
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#define GET_OSD_DISP_ROTATION_SIZE_TYPE()           (g_stOSDUserData.b2DispRotationSizeType)
#define SET_OSD_DISP_ROTATION_SIZE_TYPE(x)          (g_stOSDUserData.b2DispRotationSizeType = (x))
#endif


//--------------------------------------------------
// MACRO for DP Port Version
//--------------------------------------------------
#define GET_OSD_DP_D0_VERSION()                     (g_stOSDUserData.b2OsdDpD0PortVersion)
#define SET_OSD_DP_D0_VERSION(x)                    (g_stOSDUserData.b2OsdDpD0PortVersion = (x))

#define GET_OSD_DP_D1_VERSION()                     (g_stOSDUserData.b2OsdDpD1PortVersion)
#define SET_OSD_DP_D1_VERSION(x)                    (g_stOSDUserData.b2OsdDpD1PortVersion = (x))

#define GET_OSD_DP_D2_VERSION()                     (g_stOSDUserData.b2OsdDpD2PortVersion)
#define SET_OSD_DP_D2_VERSION(x)                    (g_stOSDUserData.b2OsdDpD2PortVersion = (x))

#define GET_OSD_DP_D6_VERSION()                     (g_stOSDUserData.b2OsdDpD6PortVersion)
#define SET_OSD_DP_D6_VERSION(x)                    (g_stOSDUserData.b2OsdDpD6PortVersion = (x))

#define GET_OSD_DP_MST()                            (g_stOSDUserData.b2OsdDpMST)
#define SET_OSD_DP_MST(x)                           (g_stOSDUserData.b2OsdDpMST = (x))

//--------------------------------------------------
// MACRO for Display Rotate
//--------------------------------------------------
#define GET_OSD_DISP_ROTATE()                       (g_stOSDUserData.b3OsdDispRotate)
#define SET_OSD_DISP_ROTATE(x)                      (g_stOSDUserData.b3OsdDispRotate = (x))

//--------------------------------------------------
// MACRO for Latency
//--------------------------------------------------
#define GET_OSD_LATENCY()                           (g_stOSDUserData.b2LatencyStatus)
#define SET_OSD_LATENCY(x)                          (g_stOSDUserData.b2LatencyStatus = (x))


#if(_LED_EFFECT_TJMODE14)


#define GET_OSD_LED_LIGHTMODE()                      	 (g_stOSDUserData.b1LightMode)
#define SET_OSD_LED_LIGHTMODE(x)                     	 (g_stOSDUserData.b1LightMode = (x))



#define GET_OSD_LED_COLOR()                      	 (g_stOSDUserData.b1Color)
#define SET_OSD_LED_COLOR(x)                     	 (g_stOSDUserData.b1Color = (x))




#define GET_OSD_LED_PRE_LIGHTMODE()                      	 (g_stOSDUserData.b1PreLightMode)
#define SET_OSD_LED_PRE_LIGHTMODE(x)                     	 (g_stOSDUserData.b1PreLightMode = (x))



#define GET_OSD_LED_PRE_COLOR()                      	 (g_stOSDUserData.b1PreColor)
#define SET_OSD_LED_PRE_COLOR(x)                     	 (g_stOSDUserData.b1PreColor = (x))

#endif

//--------------------------------------------------
// MACRO for Display Rotate
//--------------------------------------------------
#define GET_OSD_DP_VERSION_HOTKEY_DISP()            (g_stOSDUserData.b1OsdDpVersionHotKeyDisp)
#define SET_OSD_DP_VERSION_HOTKEY_DISP(x)           (g_stOSDUserData.b1OsdDpVersionHotKeyDisp = (x))

//--------------------------------------------------
// MACRO for Display
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_DP_OPTION()       (g_stOSDUserData.b1PreShowDpHotKeyVersion)
#define SET_OSD_POWER_SAVING_SHOW_DP_OPTION(x)      (g_stOSDUserData.b1PreShowDpHotKeyVersion = (x))

//--------------------------------------------------
// MACRO for Panel Uniformity
//--------------------------------------------------
#define GET_OSD_PANEL_UNIFORMITY()                  (g_stOSDUserData.b1PanelUniformity)
#define SET_OSD_PANEL_UNIFORMITY(x)                 (g_stOSDUserData.b1PanelUniformity = (x))

//--------------------------------------------------
// MACRO for Panel Uniformity
//--------------------------------------------------
#define GET_OSD_PANEL_UNIFORMITY_TYPE()             (g_stOSDUserData.b3PanelUniformityType)
#define SET_OSD_PANEL_UNIFORMITY_TYPE(x)            (g_stOSDUserData.b3PanelUniformityType = (x))

//--------------------------------------------------
// MACRO for PCM Soft Proft
//--------------------------------------------------

#define GET_OSD_PCM_SOFT_PROFT_MODE()               (g_stOSDUserData.b1PCMSoftProftMode)
#define SET_OSD_PCM_SOFT_PROFT_MODE(x)              (g_stOSDUserData.b1PCMSoftProftMode = (x))

//--------------------------------------------------
// MACRO for OSD Input Port Value
//--------------------------------------------------
#define GET_OSD_INPUT_PORT_OSD_ITEM()               (g_stOSDUserData.ucOsdInputPort)
#define SET_OSD_INPUT_PORT_OSD_ITEM(x)              (g_stOSDUserData.ucOsdInputPort = (x))


//--------------------------------------------------
// MACRO for OSD Rotate
//--------------------------------------------------
#define GET_OSD_ROTATE_STATUS()                     (g_stOSDUserData.b2OsdRotate)
#define SET_OSD_ROTATE_STATUS(x)                    (g_stOSDUserData.b2OsdRotate = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_3DOSD_STATUS()                      (g_stOSDUserData.b1Osd3DOSD)
#define SET_OSD_3DOSD_STATUS(x)                     (g_stOSDUserData.b1Osd3DOSD = (x))

//--------------------------------------------------
// Macro of BackLight
//--------------------------------------------------
#define GET_OSD_BACKLIGHT()                         (g_stOSDUserData.ucBackLight)
#define SET_OSD_BACKLIGHT(x)                        (g_stOSDUserData.ucBackLight = (x))

//�ܺ����ѱ�ֵ
#define GET_OSD_ENERGE_NOTICE_FLAG()                (g_stOSDUserData.b1EnergeNoticeflag)
#define SET_OSD_ENERGE_NOTICE_FLAG(x)               (g_stOSDUserData.b1EnergeNoticeflag = (x))

// MACRO for OSD Lock		�˵���
//--------------------------------------------------
#define GET_OSD_LOCK()                        		(g_stOSDUserData.b1OsdLock)
#define SET_OSD_LOCK(x)                       		(g_stOSDUserData.b1OsdLock = (x))


//---------------------------��Դ��-----------------------
#define GET_POWER_KEY_LOCK()                        (g_stOSDUserData.b1PowerkerLock)
#define SET_POWER_KEY_LOCK(x)                       (g_stOSDUserData.b1PowerkerLock = (x))


//--------------------------------------------------
// Real-time update frequency
//--------------------------------------------------
#define GET_OSD_FV_INFORMATION()					(g_stOSDUserData.b1FvInformation)	
#define SET_OSD_FV_INFORMATION(x)					(g_stOSDUserData.b1FvInformation = (x))

//DCR�رջ�ԭECOģʽ
#define GET_OSD_DCROFF_ECO()						(g_stOSDUserData.b3DcrOffEco)	
#define SET_OSD_DCROFF_ECO(x)						(g_stOSDUserData.b3DcrOffEco = (x))

//--------------------------------------------------
// HZ display status
//--------------------------------------------------
#define GET_OSD_HZ_DISPLAYSTATUS()					(g_stOSDUserData.byHzzhuangtai)	
#define SET_OSD_HZ_DISPLAYSTATUS(x)					(g_stOSDUserData.byHzzhuangtai = (x))


#define GET_OSD_HZ_XZ()								(g_stOSDUserData.b1xzHZ)	
#define SET_OSD_HZ_XZ(x)							(g_stOSDUserData.b1xzHZ = (x))

//--------------------------------------------------
// Macro of Aspect Origin Ratio
//--------------------------------------------------
#define GET_OSD_ASPECT_ORIGIN_RATIO()               (g_stOSDUserData.ucAspectOriginRatio)
#define SET_OSD_ASPECT_ORIGIN_RATIO(x)              (g_stOSDUserData.ucAspectOriginRatio = (x))

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()                       (g_stOSDUserData.b4ColorTempType)
#define SET_COLOR_TEMP_TYPE(x)                      (g_stOSDUserData.b4ColorTempType = (x))

#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_R()                (g_stColorProcData.usColorTempR >> 4)
#define SET_COLOR_TEMP_TYPE_USER_R(x)               (g_stColorProcData.usColorTempR = ((x) << 4))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_G()                (g_stColorProcData.usColorTempG >> 4)
#define SET_COLOR_TEMP_TYPE_USER_G(x)               (g_stColorProcData.usColorTempG = ((x) << 4))
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_B()                (g_stColorProcData.usColorTempB >> 4)
#define SET_COLOR_TEMP_TYPE_USER_B(x)               (g_stColorProcData.usColorTempB = ((x) << 4))
#else
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_R()                (g_stColorProcData.usColorTempR)
#define SET_COLOR_TEMP_TYPE_USER_R(x)               (g_stColorProcData.usColorTempR = ((x)))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_G()                (g_stColorProcData.usColorTempG)
#define SET_COLOR_TEMP_TYPE_USER_G(x)               (g_stColorProcData.usColorTempG = ((x)))
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_B()                (g_stColorProcData.usColorTempB)
#define SET_COLOR_TEMP_TYPE_USER_B(x)               (g_stColorProcData.usColorTempB = ((x)))



#endif
//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_ASPECT_RATIO_TYPE()                 (g_stOSDUserData.b3AspectRatio)
#define SET_OSD_ASPECT_RATIO_TYPE(x)                (g_stOSDUserData.b3AspectRatio = (x))

//--------------------------------------------------
// MACRO for VGA Color Format Status
//--------------------------------------------------
#define GET_VGA_COLOR_FORMAT_STATUS()               (g_stOSDUserData.b3VGARGBYUV)
#define SET_VGA_COLOR_FORMAT_STATUS(x)              (g_stOSDUserData.b3VGARGBYUV = (x))

//--------------------------------------------------
// MACRO for VGA Color Format Status
//--------------------------------------------------
#define GET_DVI_COLOR_FORMAT_STATUS()               (g_stOSDUserData.b3DVIRGBYUV)
#define SET_DVI_COLOR_FORMAT_STATUS(x)              (g_stOSDUserData.b3DVIRGBYUV = (x))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_DDCCI_STATUS()                      (g_stOSDUserData.b1DDCCIStatus)
#define SET_OSD_DDCCI_STATUS(x)                     (g_stOSDUserData.b1DDCCIStatus = (x))

//--------------------------------------------------
// MACRO for Ultra Vivid Status
//--------------------------------------------------
#define GET_OSD_ULTRA_VIVID_STATUS()                (g_stOSDUserData.b2UltraVividStatus)
#define SET_OSD_ULTRA_VIVID_STATUS(x)               (g_stOSDUserData.b2UltraVividStatus = (x))

//--------------------------------------------------
// Control audio selection output
//--------------------------------------------------
#define GET_FUN_AUDIO_SOURCE()                (g_stOSDUserData.b2AudioSource)
#define SET_FUN_AUDIO_SOURCE(x)               (g_stOSDUserData.b2AudioSource = (x))

//_MENU_FUN_CHAOPING_TISHI
#define GET_FUN_OVERCLOCK_HINT()                (g_stOSDUserData.b1OverClockHint)
#define SET_FUN_OVERCLOCK_HINT(x)               (g_stOSDUserData.b1OverClockHint = (x))


//_MENU_FUN_KVM
#define GET_FUN_KVM()								(g_stOSDUserData.b2Kvm)
#define SET_FUN_KVM(x)								(g_stOSDUserData.b2Kvm = (x))

#define GET_MEMORY_DATA()								(g_stOSDUserData.b3MemoryData)
#define SET_MEMORY_DATA(x)								(g_stOSDUserData.b3MemoryData = (x))

#if(_DEF_COLORFUL)
#define GET_FUN_COLORFUL()						(g_stOSDUserData.usContrastColorful)
#define SET_FUN_COLORFUL(x)						(g_stOSDUserData.usContrastColorful = (x))
#endif

#if(_DEF_STA_SIX_COLOR)

//_MENU_FUN_SAT_STATE
#define GET_SAT_STATE()								(g_stOSDUserData.b3StaState)
#define SET_SAT_STATE(x)							(g_stOSDUserData.b3StaState = (x))


#define GET_SIX_COLOR_SAT_R()						(g_stSixColorData.ucSixColorSaturationR)
#define SET_SIX_COLOR_SAT_R(x)						(g_stSixColorData.ucSixColorSaturationR = (x))

#define GET_SIX_COLOR_SAT_Y()						(g_stSixColorData.ucSixColorSaturationY)
#define SET_SIX_COLOR_SAT_Y(x)						(g_stSixColorData.ucSixColorSaturationY = (x))

#define GET_SIX_COLOR_SAT_G()						(g_stSixColorData.ucSixColorSaturationG)
#define SET_SIX_COLOR_SAT_G(x)						(g_stSixColorData.ucSixColorSaturationG = (x))

#define GET_SIX_COLOR_SAT_C()						(g_stSixColorData.ucSixColorSaturationC)
#define SET_SIX_COLOR_SAT_C(x)						(g_stSixColorData.ucSixColorSaturationC = (x))

#define GET_SIX_COLOR_SAT_B()						(g_stSixColorData.ucSixColorSaturationB)
#define SET_SIX_COLOR_SAT_B(x)						(g_stSixColorData.ucSixColorSaturationB = (x))

#define GET_SIX_COLOR_SAT_M()						(g_stSixColorData.ucSixColorSaturationM)
#define SET_SIX_COLOR_SAT_M(x)						(g_stSixColorData.ucSixColorSaturationM = (x))

//_MENU_FUN_HUE_STATE
#define GET_HUE_STATE()								(g_stOSDUserData.b3HueState)
#define SET_HUE_STATE(x)							(g_stOSDUserData.b3HueState = (x))


#define GET_SIX_COLOR_HUE_R()						(g_stSixColorData.ucSixColorHueR)
#define SET_SIX_COLOR_HUE_R(x)						(g_stSixColorData.ucSixColorHueR = (x))

#define GET_SIX_COLOR_HUE_Y()						(g_stSixColorData.ucSixColorHueY)
#define SET_SIX_COLOR_HUE_Y(x)						(g_stSixColorData.ucSixColorHueY = (x))

#define GET_SIX_COLOR_HUE_G()						(g_stSixColorData.ucSixColorHueG)
#define SET_SIX_COLOR_HUE_G(x)						(g_stSixColorData.ucSixColorHueG = (x))

#define GET_SIX_COLOR_HUE_C()						(g_stSixColorData.ucSixColorHueC)
#define SET_SIX_COLOR_HUE_C(x)						(g_stSixColorData.ucSixColorHueC = (x))

#define GET_SIX_COLOR_HUE_B()						(g_stSixColorData.ucSixColorHueB)
#define SET_SIX_COLOR_HUE_B(x)						(g_stSixColorData.ucSixColorHueB = (x))

#define GET_SIX_COLOR_HUE_M()						(g_stSixColorData.ucSixColorHueM)
#define SET_SIX_COLOR_HUE_M(x)						(g_stSixColorData.ucSixColorHueM = (x))


#endif


//--------------------------------------------------
// MACRO for Sharpness
//--------------------------------------------------
#define GET_OSD_SHARPNESS()                         (g_stOSDUserData.b3Sharpness)
#define SET_OSD_SHARPNESS(x)                        (g_stOSDUserData.b3Sharpness = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_TRANSPARENCY_STATUS()               (g_stOSDUserData.ucTransparency)
#define SET_OSD_TRANSPARENCY_STATUS(x)              (g_stOSDUserData.ucTransparency = (x))

//--------------------------------------------------
// MACRO for Language
//--------------------------------------------------
#define GET_OSD_LANGUAGE()                          (g_stOSDUserData.b4Language)
#define SET_OSD_LANGUAGE(x)                         (g_stOSDUserData.b4Language = (x))

//--------------------------------------------------
// MACRO for OsdTimeout
//--------------------------------------------------
#define GET_OSD_TIME_OUT()                          (g_stOSDUserData.ucOsdTimeout)
#define SET_OSD_TIME_OUT(x)                         (g_stOSDUserData.ucOsdTimeout = (x))

//--------------------------------------------------
// MACRO for OsdTimeout
//--------------------------------------------------
#define GET_OSD_SAVING_MODE()                          (g_stOSDUserData.ucOsdSavingMode)
#define SET_OSD_SAVING_MODE(x)                         (g_stOSDUserData.ucOsdSavingMode = (x))

//--------------------------------------------------
// MACRO for OsdHPos
//--------------------------------------------------
#define GET_OSD_HPOS()                              (g_stOSDUserData.ucOsdHPos)
#define SET_OSD_HPOS(x)                             (g_stOSDUserData.ucOsdHPos = (x))

//--------------------------------------------------
// MACRO for OsdVPos
//--------------------------------------------------
#define GET_OSD_VPOS()                              (g_stOSDUserData.ucOsdVPos)
#define SET_OSD_VPOS(x)                             (g_stOSDUserData.ucOsdVPos = (x))

//--------------------------------------------------
// MACRO for OsdVPos
//--------------------------------------------------
#define GET_OSD_GAMMA()                             (g_stOSDUserData.b3Gamma)
#define SET_OSD_GAMMA(x)                            (g_stOSDUserData.b3Gamma = (x))

//--------------------------------------------------
// MACRO for OD Status
//--------------------------------------------------
#define GET_OSD_OD_STATUS()                         (g_stOSDUserData.b1ODStatus)
#define SET_OSD_OD_STATUS(x)                        (g_stOSDUserData.b1ODStatus = (x))

//--------------------------------------------------
// MACRO for OD Gain
//--------------------------------------------------
#define GET_OSD_OD_GAIN()                           (g_stOSDUserData.ucODGain)
#define SET_OSD_OD_GAIN(x)                          (g_stOSDUserData.ucODGain = (x))

//--------------------------------------------------
// MACRO for Color Effect
//--------------------------------------------------
#define GET_OSD_COLOR_EFFECT()                      (g_stOSDUserData.b4ColorEffect)
#define SET_OSD_COLOR_EFFECT(x)                     (g_stOSDUserData.b4ColorEffect = (x))

//--------------------------------------------------
// MACRO for DCRStatus
//--------------------------------------------------
#define GET_OSD_DCR_STATUS()                        (g_stOSDUserData.b1OsdDcrStatus)
#define SET_OSD_DCR_STATUS(x)                       (g_stOSDUserData.b1OsdDcrStatus = (x))

#if(_DEF_OPPOSITE_DCR)	//_MENU_FUN_DCR_OPPOSITE
#define GET_OSD_DCR_OPPOSITE()                        (g_stOSDUserData.b2OsdDcrOpposite)
#define SET_OSD_DCR_OPPOSITE(x)                       (g_stOSDUserData.b2OsdDcrOpposite = (x))
#endif

//--------------------------------------------------
// MACRO for FreeSync Status
//--------------------------------------------------
#define GET_OSD_FREE_SYNC_STATUS()                  (g_stOSDUserData.b1FreeSyncStatus)
#define SET_OSD_FREE_SYNC_STATUS(x)                 (g_stOSDUserData.b1FreeSyncStatus = (x))

//--------------------------------------------------
// MACRO for Clone Mode
//--------------------------------------------------
#define GET_OSD_CLONE_MODE()                        (g_stOSDUserData.b1CloneMode)
#define SET_OSD_CLONE_MODE(x)                       (g_stOSDUserData.b1CloneMode = (x))

//--------------------------------------------------
// MACRO for HDR Mode
//--------------------------------------------------
#define GET_OSD_HDR_MODE()                          (g_stOSDUserData.ucHdrMode)
#define SET_OSD_HDR_MODE(x)                         (g_stOSDUserData.ucHdrMode = (x))

//--------------------------------------------------
// MACRO for Dark Enhance Status
//--------------------------------------------------
#define GET_OSD_DARK_ENHANCE_STATUS()               (g_stOSDUserData.b1DarkEnhanceStatus)
#define SET_OSD_DARK_ENHANCE_STATUS(x)              (g_stOSDUserData.b1DarkEnhanceStatus = (x))

//--------------------------------------------------
// MACRO for HDR Sharpness
//--------------------------------------------------
#define GET_OSD_HDR_SHARPNESS()                     (g_stOSDUserData.b1HdrSharpnesse)
#define SET_OSD_HDR_SHARPNESS(x)                    (g_stOSDUserData.b1HdrSharpnesse = (x))

//--------------------------------------------------
// MACRO for HDR Contrast
//--------------------------------------------------
#define GET_OSD_HDR_CONTRAST()                      (g_stOSDUserData.ucHdrContrast)
#define SET_OSD_HDR_CONTRAST(x)                     (g_stOSDUserData.ucHdrContrast = (x))

#if(_HDR10_COLOR_ENHANCE_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for HDR ColorEnhance
//--------------------------------------------------
#define GET_OSD_HDR_COLOR_ENHANCE()                 (g_stOSDUserData.ucHdrColorEnhance)
#define SET_OSD_HDR_COLOR_ENHANCE(x)                (g_stOSDUserData.ucHdrColorEnhance= (x))
#endif
#if(_HDR10_LIGHT_ENHANCE_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for HDR LightEnhance
//--------------------------------------------------
#define GET_OSD_HDR_LIGHT_ENHANCE()                 (g_stOSDUserData.ucHdrLightEnhance)
#define SET_OSD_HDR_LIGHT_ENHANCE(x)                (g_stOSDUserData.ucHdrLightEnhance= (x))
#endif

#if(_OSD_LOCAL_DIMMING_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for Local Dimming
//--------------------------------------------------
#define GET_OSD_LOCAL_DIMMING()                     (g_stOSDUserData.b1HdrLocalDimming)
#define SET_OSD_LOCAL_DIMMING(x)                    (g_stOSDUserData.b1HdrLocalDimming= (x))

//--------------------------------------------------
// MACRO for Local Dimming Smooth Backlight adjust
//--------------------------------------------------
#define GET_OSD_LD_ADJ()                            (g_stOSDUserData.ucHdrLocalDimmingAdj)
#define SET_OSD_LD_ADJ(x)                           (g_stOSDUserData.ucHdrLocalDimmingAdj = (x))
#endif

#if (_SDR_TO_HDR_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for SDR to HDR
//--------------------------------------------------
#define GET_OSD_SDR_TO_HDR()                        (g_stOSDUserData.b1Sdr2HdrStatus)
#define SET_OSD_SDR_TO_HDR(x)                       (g_stOSDUserData.b1Sdr2HdrStatus = (x))
#endif
//--------------------------------------------------
// MACRO for Volume Mute
//--------------------------------------------------
#define GET_OSD_VOLUME_MUTE()                       (g_stOSDUserData.b1VolumeMute)
#define SET_OSD_VOLUME_MUTE(x)                      (g_stOSDUserData.b1VolumeMute = (x))

//--------------------------------------------------
// MACRO for Volume
//--------------------------------------------------
#define GET_OSD_VOLUME()                            (g_stOSDUserData.ucVolume)
#define SET_OSD_VOLUME(x)                           (g_stOSDUserData.ucVolume = (x))

//--------------------------------------------------
// MACRO for Audio Stand a long
//--------------------------------------------------
#define GET_OSD_AUDIO_STAND_ALONE()                 (g_stOSDUserData.b1AudioStandAloneStatus)
#define SET_OSD_AUDIO_STAND_ALONE(x)                (g_stOSDUserData.b1AudioStandAloneStatus = (x))

//--------------------------------------------------
// MACRO for Audio Source
//--------------------------------------------------
#define GET_OSD_AUDIO_SOURCE()                      (g_stOSDUserData.b1AudioSourceStatus)
#define SET_OSD_AUDIO_SOURCE(x)                     (g_stOSDUserData.b1AudioSourceStatus = (x))

//--------------------------------------------------
// MACRO for Hue
//--------------------------------------------------
#define GET_OSD_HUE()                               (g_stOSDUserData.ucHue)
#define SET_OSD_HUE(x)                              (g_stOSDUserData.ucHue = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_SATURATION()                        (g_stOSDUserData.ucSaturation)
#define SET_OSD_SATURATION(x)                       (g_stOSDUserData.ucSaturation = (x))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_OVERSCAN_STATUS()                   (g_stOSDUserData.b1OverScan)
#define SET_OSD_OVERSCAN_STATUS(x)                  (g_stOSDUserData.b1OverScan = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_HLWIN_TYPE()                        (g_stOSDUserData.ucHLWinType)
#define SET_OSD_HLWIN_TYPE(x)                       (g_stOSDUserData.ucHLWinType = (x))

//--------------------------------------------------
// MACRO for 3D Status
//--------------------------------------------------
#define GET_OSD_3D_STATUS()                         (g_stOSDUserData.b23DStatus)
#define SET_OSD_3D_STATUS(x)                        (g_stOSDUserData.b23DStatus = (x))

//--------------------------------------------------
// MACRO for 3D LR Status
//--------------------------------------------------
#define GET_OSD_3D_LR_STATUS()                      (g_stOSDUserData.b13DLRStatus)
#define SET_OSD_3D_LR_STATUS(x)                     (g_stOSDUserData.b13DLRStatus = (x))

//--------------------------------------------------
// MACRO for 3D Format Status
//--------------------------------------------------
#define GET_OSD_3D_FORMAT_STATUS()                  (g_stOSDUserData.b23DFormatStatus)
#define SET_OSD_3D_FORMAT_STATUS(x)                 (g_stOSDUserData.b23DFormatStatus = (x))

//--------------------------------------------------
// MACRO for 3D EFFECT
//--------------------------------------------------
#define GET_OSD_3D_EFFECT()                         (g_stOSDUserData.uc3DEffect)
#define SET_OSD_3D_EFFECT(x)                        (g_stOSDUserData.uc3DEffect = (x))

//--------------------------------------------------
// MACRO for 3D 3DTO2D
//--------------------------------------------------
#define GET_OSD_3D_3DTO2D()                         (g_stOSDUserData.b13D3DTO2DStatus)
#define SET_OSD_3D_3DTO2D(x)                        (g_stOSDUserData.b13D3DTO2DStatus = (x))

//--------------------------------------------------
// MACRO for 3D Convergence
//--------------------------------------------------
#define GET_OSD_3D_CONVERGENCE()                    (g_stOSDUserData.uc3DConvergence)
#define SET_OSD_3D_CONVERGENCE(x)                   (g_stOSDUserData.uc3DConvergence = (x))

//--------------------------------------------------
// MACRO for 3D Convergence Mode
//--------------------------------------------------
#define GET_OSD_3D_CONVERGENCE_MODE()               (g_stOSDUserData.b33DConvergenceMode)
#define SET_OSD_3D_CONVERGENCE_MODE(x)              (g_stOSDUserData.b33DConvergenceMode = (x))

//--------------------------------------------------
// MACRO for Auto-Color Type
//--------------------------------------------------
#define _AUTO_COLOR_TYPE_INTERNAL                   0
#define _AUTO_COLOR_TYPE_EXTERNAL                   1

#define GET_OSD_FACTORY_AUTO_COLOR_TYPE()           (g_stOSDUserData.b1FactoryAutoColorType)
#define SET_OSD_FACTORY_AUTO_COLOR_TYPE(x)          (g_stOSDUserData.b1FactoryAutoColorType = (x))

#define GET_OSD_OCC_RLT_TYPE()                      (g_stOSDUserData.b2OSDOccRlt)
#define SET_OSD_OCC_RLT_TYPE(x)                     (g_stOSDUserData.b2OSDOccRlt = (x))
//--------------------------------------------------
// MACRO for PCM Status
//--------------------------------------------------
#define GET_OSD_PCM_STATUS()                        (g_stOSDUserData.b3PCMStatus)
#define SET_OSD_PCM_STATUS(x)                       (g_stOSDUserData.b3PCMStatus = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------

#define GET_OSD_FLICKER_FREE_STATUS()               (g_stOSDUserData.b1FlickerFree)
#define SET_OSD_FLICKER_FREE_STATUS(x)              (g_stOSDUserData.b1FlickerFree = (x))
//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
	
#define GET_OSD_MPRT()             					 (g_stOSDUserData.b1MPRT)
#define SET_OSD_MPRT(x)           					 (g_stOSDUserData.b1MPRT = (x))

#if(_DEF_HOTKEY_REPLACE)//_MENU_FUN_HOT_REPLACE_LEFT
#define GET_OSD_HOT_REPLACE_LEFT()             			(g_stOSDUserData.b4HotKeyReplaceLeft)
#define SET_OSD_HOT_REPLACE_LEFT(x)            			(g_stOSDUserData.b4HotKeyReplaceLeft = (x))

#define GET_OSD_HOT_REPLACE_RIGHT()             		(g_stOSDUserData.b4HotKeyReplaceRight)
#define SET_OSD_HOT_REPLACE_RIGHT(x)            		(g_stOSDUserData.b4HotKeyReplaceRight = (x))

#define GET_OSD_HOT_REPLACE_EXIT()             			(g_stOSDUserData.b4HotKeyReplaceExit)
#define SET_OSD_HOT_REPLACE_EXIT(x)            			(g_stOSDUserData.b4HotKeyReplaceExit = (x))
#endif

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_OVERCLOCK()                        (g_stOSDUserData.b1OverClock)
#define SET_OSD_OVERCLOCK(x)                       (g_stOSDUserData.b1OverClock = (x))


#define GET_OSD_LOGO()                        (g_stOSDUserData.b1ShowLogoFlag)
#define SET_OSD_LOGO(x)                       (g_stOSDUserData.b1ShowLogoFlag = (x))

#define GET_OSD_DCC()                        (g_stOSDUserData.blDccFlag)
#define SET_OSD_DCC(x)                       (g_stOSDUserData.blDccFlag = (x))

#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
#define GET_OSD_ENGER()                       (g_stOSDUserData.b1Enger)
#define SET_OSD_ENGER(x)                      (g_stOSDUserData.b1Enger = (x))
#endif

//--------------------------------------------------
// MACRO for DP Lane Count switch
//--------------------------------------------------
#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
#define GET_OSD_D0_TYPEC_U3_MODE()                   (g_stOSDUserData.b2D0TypeCU3Mode)
#define SET_OSD_D0_TYPEC_U3_MODE(x)                  (g_stOSDUserData.b2D0TypeCU3Mode = (x))

#define GET_OSD_D1_TYPEC_U3_MODE()                   (g_stOSDUserData.b2D1TypeCU3Mode)
#define SET_OSD_D1_TYPEC_U3_MODE(x)                  (g_stOSDUserData.b2D1TypeCU3Mode = (x))

#define GET_OSD_D2_TYPEC_U3_MODE()                   (g_stOSDUserData.b2D2TypeCU3Mode)
#define SET_OSD_D2_TYPEC_U3_MODE(x)                  (g_stOSDUserData.b2D2TypeCU3Mode = (x))

#define GET_OSD_D6_TYPEC_U3_MODE()                   (g_stOSDUserData.b2D6TypeCU3Mode)
#define SET_OSD_D6_TYPEC_U3_MODE(x)                  (g_stOSDUserData.b2D6TypeCU3Mode = (x))
#endif

//--------------------------------------------------
// MACRO for HDMI version
//--------------------------------------------------
#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
#define GET_OSD_D0_HDMI_VER()                       (g_stOSDUserData.b2OsdHdmiD0PortVersion)
#define SET_OSD_D0_HDMI_VER(x)                      (g_stOSDUserData.b2OsdHdmiD0PortVersion = (x))

#define GET_OSD_D1_HDMI_VER()                       (g_stOSDUserData.b2OsdHdmiD1PortVersion)
#define SET_OSD_D1_HDMI_VER(x)                      (g_stOSDUserData.b2OsdHdmiD1PortVersion = (x))

#define GET_OSD_D2_HDMI_VER()                       (g_stOSDUserData.b2OsdHdmiD2PortVersion)
#define SET_OSD_D2_HDMI_VER(x)                      (g_stOSDUserData.b2OsdHdmiD2PortVersion = (x))

#define GET_OSD_D3_HDMI_VER()                       (g_stOSDUserData.b2OsdHdmiD3PortVersion)
#define SET_OSD_D3_HDMI_VER(x)                      (g_stOSDUserData.b2OsdHdmiD3PortVersion = (x))

#define GET_OSD_D4_HDMI_VER()                       (g_stOSDUserData.b2OsdHdmiD4PortVersion)
#define SET_OSD_D4_HDMI_VER(x)                      (g_stOSDUserData.b2OsdHdmiD4PortVersion = (x))

#define GET_OSD_D5_HDMI_VER()                       (g_stOSDUserData.b2OsdHdmiD5PortVersion)
#define SET_OSD_D5_HDMI_VER(x)                      (g_stOSDUserData.b2OsdHdmiD5PortVersion = (x))
#endif

#if(_USB3_RETIMER_SUPPORT == _ON)
#define GET_OSD_USB3_RETIMER_PS_PD_WAKEUP()         (g_stOSDUserData.b1OsdUsb3RetimerPSPDWakeUp)
#define SET_OSD_USB3_RETIMER_PS_PD_WAKEUP(x)        (g_stOSDUserData.b1OsdUsb3RetimerPSPDWakeUp = (x))
#endif

#define GET_OSD_FACTORY_MODE()                       (g_stOSDUserData.b1FACTORY_MODE)
#define SET_OSD_FACTORY_MODE(x)                      (g_stOSDUserData.b1FACTORY_MODE = (x))

#define GET_OSD_BURNING_MODE()                       (g_stOSDUserData.b1BURNING_MODE)
#define SET_OSD_BURNING_MODE(x)                      (g_stOSDUserData.b1BURNING_MODE = (x))

#define GET_OSD_ALIGN_MODE()                       (g_stOSDUserData.b1Align)
#define SET_OSD_ALIGN_MODE(x)                      (g_stOSDUserData.b1Align = (x))


#define GET_OSD_CROSS_STATUS()                  (g_stOSDUserData.b1OSDCross)//_MENU_FUN_CROSS
#define SET_OSD_CROSS_STATUS(x)                 (g_stOSDUserData.b1OSDCross = (x))


#define GET_OSD_LOW_BLUE()                      	 (g_stOSDUserData.ucLowBlue)
#define SET_OSD_LOW_BLUE(x)                     	 (g_stOSDUserData.ucLowBlue = (x))

#define GET_OSD_LED_TYPE()                      	 (g_stOSDUserData.b2OSDLedType)
#define SET_OSD_LED_TYPE(x)                     	 (g_stOSDUserData.b2OSDLedType = (x))

#define GET_OSD_AUTO_POWEROFF()                       (g_stOSDUserData.ucOSDAutoPowerOff)
#define SET_OSD_AUTO_POWEROFF(x)                      (g_stOSDUserData.ucOSDAutoPowerOff = (x))

#define GET_OSD_HOTKEY_LEFT()                       (g_stOSDUserData.ucHotKeyLeft)
#define SET_OSD_HOTKEY_LEFT(x)                      (g_stOSDUserData.ucHotKeyLeft = (x))

#define GET_OSD_HOTKEY_RIGHT()                       (g_stOSDUserData.ucHotKeyRight)
#define SET_OSD_HOTKEY_RIGHT(x)                      (g_stOSDUserData.ucHotKeyRight = (x))

#if(_DEF_DDCCI_EDID_TOOL)
#define GET_DDC_STATUS()                			(g_stOSDUserData.b1DDCStatus)
#define SET_DDC_STATUS(x)               			(g_stOSDUserData.b1DDCStatus  = (x))


#define GET_FACTORY_BURNIN()                    (g_stFactoryData.b1BurnIn)
#define SET_FACTORY_BURNIN(x)              		(g_stFactoryData.b1BurnIn = (x))

#define GET_FACTORY_MODE()                          (g_stFactoryData.b1OsdFactory)
#define SET_FACTORY_MODE(x)                         (g_stFactoryData.b1OsdFactory = (x))
#endif

#define GET_BURNING_AUDIO_TEST()                 (g_stOSDUserData.b1Burning_Audio_Test)
#define SET_BURNING_AUDIO_TEST(x)                (g_stOSDUserData.b1Burning_Audio_Test = (x))
//--------------------------------------------------
// MACRO for OSD double size
//--------------------------------------------------
#define GET_OSD_NVRAM_DOUBLE_SIZE()                 (g_stOSDUserData.b1OsdDoubleSize)
#define SET_OSD_NVRAM_DOUBLE_SIZE(x)                (g_stOSDUserData.b1OsdDoubleSize = (x))

//--------------------------------------------------
// MACRO for Panel Time Min
//--------------------------------------------------
#define GET_PANEL_TIME_MIN()                        (g_stPanelTimeData.ucMin)
#define SET_PANEL_TIME_MIN(x)                       (g_stPanelTimeData.ucMin = (x))

//--------------------------------------------------
// MACRO for Panel Time Hour
//--------------------------------------------------
#define GET_PANEL_TIME_HOUR()                       (g_stPanelTimeData.usHour)
#define SET_PANEL_TIME_HOUR(x)                      (g_stPanelTimeData.usHour = (x))

//--------------------------------------------------
// MACRO for Panel Time Hour
//--------------------------------------------------
#define GET_PANEL_BURN_TIME_HOUR()                       (g_stPanelTimeData.usBurnHour)
#define SET_PANEL_BURN_TIME_HOUR(x)                      (g_stPanelTimeData.usBurnHour = (x))

//--------------------------------------------------
// MACRO for Panel Time Min
//--------------------------------------------------
#define GET_PANEL_BURN_TIME_MIN()                        (g_stPanelTimeData.ucBurnMin)
#define SET_PANEL_BURN_TIME_MIN(x)                       (g_stPanelTimeData.ucBurnMin = (x))


//--------------------------------------------------
// MACRO for CROSS HAIR
//--------------------------------------------------

#define GET_OSD_CROSS_HAIR_TYPE1()                       (g_stOSDUserData.b2CrossHairMode1)
#define SET_OSD_CROSS_HAIR_TYPE1(x)                      (g_stOSDUserData.b2CrossHairMode1 = (x))

//--------------------------------------------------
// MACRO for CROSS HAIR
//--------------------------------------------------

#define GET_OSD_CROSS_HAIR_TYPE2()                        (g_stOSDUserData.b3CrossHairMode2)
#define SET_OSD_CROSS_HAIR_TYPE2(x)                       (g_stOSDUserData.b3CrossHairMode2 = (x))


//--------------------------------------------------
// MACRO for Factory Power Saving Case
//--------------------------------------------------
#define GET_FORCE_POW_SAV_STATUS()                  (g_bForcePowSavStatus)
#define SET_FORCE_POW_SAV_STATUS(x)                 (g_bForcePowSavStatus = (x))


#define GET_IR_OSD_PROGRESS_BAR_OR_OPTION()                  (IROsdOptionTypes)
#define SET_IR_OSD_PROGRESS_BAR_OR_OPTION(x)                 (IROsdOptionTypes = (x))

//--------------------------------------------------
// Definitions of OSD Number ROW COL
//--------------------------------------------------
#define _OSD_NUMBER_1_ROW                           15
#define _OSD_NUMBER_1_COL                           21

#define _OSD_NUMBER_UNSTLECT_COLOR                  COLOR(_CP_BLUE, _CP_BG)
#define _OSD_NUMBER_UNSTLECT_COLOR                  COLOR(_CP_BLUE, _CP_BG)
//--------------------------------------------------
// Definitions of OSD
//--------------------------------------------------
#define _PFONT_PAGE_0                               0
#define _PFONT_PAGE_1                               1
#define _PFONT_PAGE_2                               2
#define _PFONT_PAGE_ITEM_1                          3
#define _PFONT_PAGE_ITEM_2                          4
#define _PFONT_PAGE_ITEM_3                          5
#define _PFONT_PAGE_ITEM_4                          6
#define _PFONT_PAGE_ITEM_5                          7
#define _PFONT_PAGE_ITEM_6                          8
#define _PFONT_PAGE_ITEM_7                          9
#define _PFONT_PAGE_ITEM_8                          10
#define _PFONT_PAGE_ITEM_9                          11

#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))



#define _PFONT_PAGE_ITEM_10                          12

#define _PFONT_PAGE_INFORMATION                  13//  12

#define _OSD_GLOBAL_START                           0x01
#define _OSD_GLOBAL_END                             0x0F

#define _OSD_PAGE_0_START                           0x60
#define _OSD_PAGE_0_END                             0xF0

#define _OSD_PAGE_1_START                           0x00
#define _OSD_PAGE_1_END                             0x70

#define _OSD_PAGE_2_START                           0x71
#define _OSD_PAGE_2_END                         0xf5//     0xFb  //251

#define _SUB_PAGE_ITEM_1                            (_OSD_PAGE_2_START)
#define _SUB_PAGE_ITEM_1_END                        (_OSD_PAGE_2_START + 0x10)
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 0x10)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 0x10)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 0x10)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 0x10)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 0x10)
#define _SUB_PAGE_ITEM_7                            (_SUB_PAGE_ITEM_6_END)
#define _SUB_PAGE_ITEM_7_END                        (_SUB_PAGE_ITEM_6_END + 0x10)//0xe1
#define _SUB_PAGE_ITEM_8                            (_SUB_PAGE_ITEM_7_END)
#define _SUB_PAGE_ITEM_8_END                        (_SUB_PAGE_ITEM_7_END + 7)//232


#define _SUB_PAGE_ITEM_9                       0xf6//     (_SUB_PAGE_ITEM_8_END)
#define _SUB_PAGE_ITEM_9_END                        (_SUB_PAGE_ITEM_9 + 3)        //  1 // 235


#define _SUB_PAGE_ITEM_10                           (_SUB_PAGE_ITEM_9_END)
#define _SUB_PAGE_ITEM_10_END                        (_SUB_PAGE_ITEM_9_END + 2)        //  238

#else



#define _PFONT_PAGE_INFORMATION                     12

#define _OSD_GLOBAL_START                           0x01
#define _OSD_GLOBAL_END                             0x0F

#define _OSD_PAGE_0_START                           0x60
#define _OSD_PAGE_0_END                             0xF0

#define _OSD_PAGE_1_START                           0x00
#define _OSD_PAGE_1_END                             0x70

#define _OSD_PAGE_2_START                           0x71
#define _OSD_PAGE_2_END                             0xFb

#define _SUB_PAGE_ITEM_1                            (_OSD_PAGE_2_START)
#define _SUB_PAGE_ITEM_1_END                        (_OSD_PAGE_2_START + 0x10)
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 0x10)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 0x10)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 0x10)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 0x10)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 0x10)
#define _SUB_PAGE_ITEM_7                            (_SUB_PAGE_ITEM_6_END)
#define _SUB_PAGE_ITEM_7_END                        (_SUB_PAGE_ITEM_6_END + 0x10)
#define _SUB_PAGE_ITEM_8                            (_SUB_PAGE_ITEM_7_END)
#define _SUB_PAGE_ITEM_8_END                        (_SUB_PAGE_ITEM_7_END + 7)
#define _SUB_PAGE_ITEM_9                            (_SUB_PAGE_ITEM_8_END)
#define _SUB_PAGE_ITEM_9_END                        (_SUB_PAGE_ITEM_8_END + 1)





#endif


#define _OSD_PAGE_INFORMATION_START                 0x28
#define _OSD_PAGE_INFORMATION_END                   0xFF

#define _NORMAL                                     0
#define _CENTER                                     1
#define _START                                      0
#define _RUN                                        1

#define _UP                                         0
#define _DOWN                                       1

#define _OUTSUBSET                                  0
#define _INSUBSET                                   1

//--------------------------------------------------
// Definitions of OSD Window
//--------------------------------------------------
//=========== OSD Window Setting ======================//
//Blending type1:Only windows blending.
//Blending type2:All blending.
//Blending type3:Windows & Character background blending.
#define _WIN0                                       0
#define _WIN1                                       1
#define _WIN2                                       2
#define _WIN3                                       3
#define _WIN4                                       4
#define _WIN5                                       5
#define _WIN6                                       6
#define _WIN7                                       7
#define _WIN8                                       8
#define _WIN9                                       9
#define _WIN_ALL                                    0xFF

#define _WIN0_TRANS                                 (_BIT7 | 0)
#define _WIN1_TRANS                                 (_BIT7 | 1)
#define _WIN2_TRANS                                 (_BIT7 | 2)
#define _WIN3_TRANS                                 (_BIT7 | 3)
#define _WIN4_TRANS                                 (_BIT7 | 4)
#define _WIN5_TRANS                                 (_BIT7 | 5)
#define _WIN6_TRANS                                 (_BIT7 | 6)
#define _WIN7_TRANS                                 (_BIT7 | 7)

#define COLOR(fg, bg)                               ((fg) << 4 | (bg))
#define COLOR0(x)                                   (x)
#define COLOR1(x)                                   (x)
#define COLOR2(x)                                   (x)
#define COLOR3(x)                                   (x)

#define X_START(x)                                  (x)
#define Y_START(x)                                  (x)
#define X_END(x)                                    (x)
#define Y_END(x)                                    (x)

#define _BORDER0_1_PIXEL                            0
#define _BORDER0_2_PIXEL                            1
#define _BORDER0_3_PIXEL                            2
#define _BORDER0_4_PIXEL                            3
#define _BORDER0_5_PIXEL                            4
#define _BORDER0_6_PIXEL                            5
#define _BORDER0_7_PIXEL                            6
#define _BORDER0_8_PIXEL                            7

#define _BORDER1_1_PIXEL                            0x00
#define _BORDER1_2_PIXEL                            0x08
#define _BORDER1_3_PIXEL                            0x10
#define _BORDER1_4_PIXEL                            0x18
#define _BORDER1_5_PIXEL                            0x20
#define _BORDER1_6_PIXEL                            0x28
#define _BORDER1_7_PIXEL                            0x30
#define _BORDER1_8_PIXEL                            0x38

#define _BLEND_DISABLE                              0
#define _BLEND_ENABLE                               0x80
#define _GRADIENT_DISABLE                           0
#define _GRADIENT_ENABLE                            0x40
#define _GRADIENT_DIRECTION_H                       0
#define _GRADIENT_DIRECTION_V                       0x20
#define _BORDER_DISABLE                             0
#define _BORDER_ENABLE                              0x10

#define _1_LEVEL_RER_GRADIENT                       0x20
#define _2_LEVEL_RER_GRADIENT                       0x40
#define _3_LEVEL_RER_GRADIENT                       0x60
#define _4_LEVEL_RER_GRADIENT                       0x80
#define _5_LEVEL_RER_GRADIENT                       0xA0
#define _6_LEVEL_RER_GRADIENT                       0xC0
#define _7_LEVEL_RER_GRADIENT                       0xE0
#define _8_LEVEL_RER_GRADIENT                       0x00

#define _R_GRADIENT_DEC                             0x00
#define _R_GRADIENT_INC                             0x80
#define _G_GRADIENT_DEC                             0x00
#define _G_GRADIENT_INC                             0x40
#define _B_GRADIENT_DEC                             0x00
#define _B_GRADIENT_INC                             0x20

#define _GRADIENT_LEVEL_1                           0
#define _GRADIENT_LEVEL_2                           0x08
#define _GRADIENT_LEVEL_3                           0x10
#define _GRADIENT_LEVEL_4                           0x18

#define _R_GRADIENT_ENABLE                          0x04
#define _R_GRADIENT_DISABLE                         0x00
#define _G_GRADIENT_ENABLE                          0x02
#define _G_GRADIENT_DISABLE                         0x00
#define _B_GRADIENT_ENABLE                          0x01
#define _B_GRADIENT_DISABLE                         0x00

#define _SHADOW_1                                   0x00
#define _SHADOW_2                                   0x02
#define _SHADOW_3                                   0x04
#define _SHADOW_4                                   0x06
#define _3D_BUTTON_1                                0x08
#define _3D_BUTTON_2                                0x0A

#define _WIN0_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)

#define _WIN0_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN0_GRADIENT_CONTROL0                     (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC)
#define _WIN0_GRADIENT_CONTROL1                     (_3_LEVEL_RER_GRADIENT)

#define _WIN0_ROTATE_BORDER_PIXEL                   (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_ROTATE_BORDER_COLOR                   ((_CP_DARKBLUE << 4) | _CP_DARKBLUE)
#define _WIN0_ROTATE_FUNC_CONTROL                   (_BLEND_ENABLE | _GRADIENT_ENABLE | _GRADIENT_DIRECTION_V | _BORDER_ENABLE | _SHADOW_3)
#define _WIN0_ROTATE_GRADIENT_CONTROL0              (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_4 | _R_GRADIENT_DEC | _G_GRADIENT_DEC | _B_GRADIENT_DEC)
#define _WIN0_ROTATE_GRADIENT_CONTROL1              (_3_LEVEL_RER_GRADIENT)

#define _WIN1_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN1_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)

#define _WIN1_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN1_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN1_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN2_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN2_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN2_FUNC_CONTROL                          (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN2_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN2_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN3_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN3_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN3_FUNC_CONTROL                          (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN3_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN3_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN7_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN7_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN7_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN7_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN7_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN0_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN0_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN0_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN0_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN0_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN1_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN1_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN1_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN1_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN1_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN2_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN2_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN2_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN2_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN2_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN3_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN3_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN3_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN3_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN3_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN4_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN4_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN4_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN4_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN4_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN5_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN5_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN5_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN5_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN5_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN6_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN6_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN6_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN6_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN6_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN7_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN7_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN7_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN7_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN7_TRANS_GRADIENT_CONTROL1               (_DISABLE)



#define _OSD_UNSELECT                               0
#define _OSD_SELECT                                 1
#define _OSD_REJECT                                 2
#define _OSD_ADJUST                                 3
#define _OSD_UNHIGHLIGHT                            4
#define _OSD_HIGHLIGHT                              5
#define _OSD_PRE_SELECT                             6
#define _OSD_SELECT_ADJUST                          7


#define _KEY_INFO_ENTER                             0
#define _KEY_INFO_RIGHT                             1
#define _KEY_INFO_LEFT                              2
#define _KEY_INFO_EXIT                              3
#define _KEY_INFO_BACK                              4
#define _KEY_INFO_ALL                               5   // exit, left, right, enter

//=========== OSD Font Icon Address ======================//
#define _1GLOBAL_START                              0x00                        // Global 49
#define _1DYNAMIC_START                             (_1GLOBAL_START + 50)       // Dynamic 0
#define _1DYNAMIC_ICON_START                        (_1DYNAMIC_START + 0)       // main menu icon (6 x 4 x 8) = 196
#define _2DYNAMIC_START                             0x00

#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER||_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)
#define _2BIT_ICON_OFFSET                           0x20
#else
#define _2BIT_ICON_OFFSET                           0x4E
#endif

#define _2BIT_ICON_START                           _2BIT_ICON_OFFSET*2

#define _LOGO_START_ADDRESS                         0x00


#define  _1BIT_ICON_START                            0x01

#define _HKC_BAR_L                                  (_1BIT_ICON_START + 0x04)
#define _HKC_BAR0                                    (_1BIT_ICON_START + 0x05)
#define _HKC_BAR1                                    (_1BIT_ICON_START + 0x06)
#define _HKC_BAR2                                    (_1BIT_ICON_START + 0x07)
#define _HKC_BAR3                                    (_1BIT_ICON_START + 0x08)
#define _HKC_BAR4                                    (_1BIT_ICON_START + 0x09)
#define _HKC_BAR5                                    (_1BIT_ICON_START + 0x0a)
#define _HKC_BAR6                                    (_1BIT_ICON_START + 0x0b)
#define _HKC_BAR7                                    (_1BIT_ICON_START + 0x0c)
#define _HKC_BAR8                                    (_1BIT_ICON_START + 0x0d)
#define _HKC_BAR9                                    (_1BIT_ICON_START + 0x0e)
#define _HKC_BAR10                                  (_1BIT_ICON_START + 0x0f)
#define _HKC_BAR_R                                  (_1BIT_ICON_START + 0x10)

//=============== 1Bit Icon ========================

typedef enum
{
    ___ = 0,
	_iHKC_01,
	_iHKC_02,
	_iHKC_03,
	_iHKC_04,
	_iHKC_05,
	_iHKC_06,
	_iHKC_07,
	_iHKC_08,
	_iHKC_09,
	_iHKC_0A,
	_iHKC_0B,
	_iHKC_0C,
	_iHKC_0D,
	_iHKC_0E,	
	_iHKC_0F,	
	_iHKC_10,
	_iHKC_11,
	_iHKC_12,
	_iHKC_13,
	_iHKC_14,
	_iHKC_15,
	_iHKC_16,
	_iHKC_17,
	_iHKC_18,
	_iHKC_19,
	_iHKC_1A,
	_iHKC_1B,
	_iHKC_1C,
	_iHKC_1D,
	_iHKC_1E,
	_iHKC_1F,
	_iHKC_20,
	_iHKC_21,
	_iHKC_22,
	_iHKC_23,
	_iHKC_24,
	_iHKC_25,
	_iHKC_26,
	_iHKC_27,
	_iHKC_28,
	_iHKC_29,
	_iHKC_2A,
	_iHKC_2B,
	_iHKC_2C,
	_iHKC_2D,
	_iHKC_2E,
	_iHKC_2F,
	_iHKC_30,
	
}EnumOneBitGLOBAL;


typedef enum
{
_iHKC_1F_00=0x22,
_iHKC_1F_01,
_iHKC_1F_02,
_iHKC_1F_03,
_iHKC_1F_04,
_iHKC_1F_05,
_iHKC_1F_06,
_iHKC_1F_07,
_iHKC_1F_08,
_iHKC_1F_09,
_iHKC_1F_0A,
_iHKC_1F_0B,
_iHKC_1F_0C,
_iHKC_1F_0D,
_iHKC_1F_0E,
_iHKC_1F_0F,
_iHKC_1F_10,
_iHKC_1F_11,
_iHKC_1F_12,
_iHKC_1F_13,
_iHKC_1F_14,
_iHKC_1F_15,
_iHKC_1F_16,
_iHKC_1F_17,
_iHKC_1F_18,
_iHKC_1F_19,
_iHKC_1F_1A,
_iHKC_1F_1B,
_iHKC_1F_1C,
_iHKC_1F_1D,
_iHKC_1F_1E,
_iHKC_1F_1F,	
_iHKC_1F_20,
_iHKC_1F_21,
_iHKC_1F_22,
_iHKC_1F_23,
_iHKC_1F_24,
_iHKC_1F_25,
_iHKC_1F_26,    
_iHKC_1F_27,
_iHKC_1F_28,
_iHKC_1F_29,
_iHKC_1F_2A,
_iHKC_1F_2B,
_iHKC_1F_2C,
_iHKC_1F_2D,
_iHKC_1F_2E,
_iHKC_1F_2F,	
_iHKC_1F_30,
_iHKC_1F_31,
_iHKC_1F_32,
_iHKC_1F_33,

_iHKC_1F_34,
_iHKC_1F_35,
_iHKC_1F_36,    
_iHKC_1F_37,
_iHKC_1F_38,
_iHKC_1F_39,
_iHKC_1F_3A,
_iHKC_1F_3B,
_iHKC_1F_3C,
_iHKC_1F_3D,
_iHKC_1F_3E,
_iHKC_1F_3F,	
_iHKC_1F_40,
_iHKC_1F_41,
_iHKC_1F_42,
_iHKC_1F_43,
_iHKC_1F_44,
_iHKC_1F_45,
_iHKC_1F_46,    
_iHKC_1F_47,
_iHKC_1F_48,
_iHKC_1F_49,
_iHKC_1F_4A,
_iHKC_1F_4B,
_iHKC_1F_4C,
_iHKC_1F_4D,
_iHKC_1F_4E,
_iHKC_1F_4F,
_iHKC_1F_50,
_iHKC_1F_51,
_iHKC_1F_52,
_iHKC_1F_53,
_iHKC_1F_54,
_iHKC_1F_55,
_iHKC_1F_56,
_iHKC_1F_57,
_iHKC_1F_58,
_iHKC_1F_59,
_iHKC_1F_5A,
_iHKC_1F_5B,
_iHKC_1F_5C,
_iHKC_1F_5D,
_iHKC_1F_5E,
_iHKC_1F_5F,
_iHKC_1F_60,
_iHKC_1F_61,
_iHKC_1F_62,
_iHKC_1F_63,
_iHKC_1F_64,
_iHKC_1F_65,
_iHKC_1F_66,
_iHKC_1F_67,
_iHKC_1F_68,
_iHKC_1F_69,
_iHKC_1F_6A,
_iHKC_1F_6B,
_iHKC_1F_6C,
_iHKC_1F_6D,
_iHKC_1F_6E,
_iHKC_1F_6F,
_iHKC_1F_70,
_iHKC_1F_71,
_iHKC_1F_72,
_iHKC_1F_73,
_iHKC_1F_74,
_iHKC_1F_75,
_iHKC_1F_76,
_iHKC_1F_77,
_iHKC_1F_78,
_iHKC_1F_79,
_iHKC_1F_7A,
_iHKC_1F_7B,
_iHKC_1F_7C,
_iHKC_1F_7D,
_iHKC_1F_7E,
_iHKC_1F_7F,
_iHKC_1F_80,
_iHKC_1F_81,
_iHKC_1F_82,
_iHKC_1F_83,
_iHKC_1F_84,
_iHKC_1F_85,
_iHKC_1F_86,
_iHKC_1F_87,
_iHKC_1F_88,
_iHKC_1F_89,
_iHKC_1F_8A,
_iHKC_1F_8B,
_iHKC_1F_8C,
_iHKC_1F_8D,
_iHKC_1F_8E,
_iHKC_1F_8F,
_iHKC_1F_90,
_iHKC_1F_91,
_iHKC_1F_92,
_iHKC_1F_93,
_iHKC_1F_94,
_iHKC_1F_95,
_iHKC_1F_96,
_iHKC_1F_97,
_iHKC_1F_98,
_iHKC_1F_99,
_iHKC_1F_9A,
_iHKC_1F_9B,
_iHKC_1F_9C,
_iHKC_1F_9D,
_iHKC_1F_9E,
_iHKC_1F_9F,

_iHKC_1F_A0,
_iHKC_1F_A1,
_iHKC_1F_A2,
_iHKC_1F_A3,
_iHKC_1F_A4,
_iHKC_1F_A5,
_iHKC_1F_A6,
_iHKC_1F_A7,
_iHKC_1F_A8,
_iHKC_1F_A9,
_iHKC_1F_AA,
_iHKC_1F_AB,
_iHKC_1F_AC,
_iHKC_1F_AD,
_iHKC_1F_AE,
_iHKC_1F_AF,
_iHKC_1F_B0,
_iHKC_1F_B1,
_iHKC_1F_B2,
_iHKC_1F_B3,
_iHKC_1F_B4,
_iHKC_1F_B5,
_iHKC_1F_B6,
_iHKC_1F_B7,
_iHKC_1F_B8,
_iHKC_1F_B9,
_iHKC_1F_BA,
_iHKC_1F_BB,
_iHKC_1F_BC,
_iHKC_1F_BD,
_iHKC_1F_BE,
_iHKC_1F_BF,
};


//=============== 1Bit Icon ========================

extern BYTE code tOSD_BOARD_UP_LEFT[];
extern BYTE code tOSD_BOARD_DOWN_LEFT[];
extern BYTE code tOSD_HENGXIAN[];
extern BYTE code tOSD_SOURCE_SELECT[];

#if(_DEF_KEY_NAVIGATION)	//��������
extern BYTE code tOSD_KEY_M[];
extern BYTE code tOSD_KEY_E[];
extern BYTE code tOSD_KEY_R[];
extern BYTE code tOSD_KEY_L[];
extern BYTE code tOSD_KEY_POWER[];
#endif

#if(_DEF_OSD_LOGO)	//�˵�LOGO

extern BYTE code tOSD_OSD_LOGO0[];
extern BYTE code tOSD_OSD_LOGO1[];

#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER||_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)	//�˵�LOGO
extern BYTE code tOSD_OSD_LOGO2[];
extern BYTE code tOSD_OSD_LOGO3[];
#endif
#endif


extern BYTE code tOSD_BOARD_UP_LEFT_MSG[];
extern BYTE code tOSD_BOARD_DOWN_LEFT_MSG[];

extern BYTE code tOSD_BOARD_UP_LEFT_POWEROFF_MSG[];
extern BYTE code tOSD_BOARD_DOWN_LEFT_POWEROFF_MSG[];


extern BYTE code tOSD_BOARD_UP_LEFT_INPUT_MSG[];
extern BYTE code tOSD_BOARD_DOWN_LEFT_INPUT_MSG[];
extern BYTE code tOSD_BOARD_UP_LEFT_MSG_HOTHEY[];
extern BYTE code tOSD_BOARD_DOWN_LEFT_MSG_HOTHEY[];

extern BYTE code tOSD_BOARD_UP_LEFT_MSG_HOTHEY_2[];
extern BYTE code tOSD_BOARD_DOWN_LEFT_MSG_HOTHEY_2[];


#if(_NAVIGAT_MENU_SURPPORT == _ON)
extern BYTE code tOSD_BOARD_TOP_NAVIGATE_MSG[];
extern BYTE code tOSD_BOARD_BOTTOM_NAVIGATE_MSG[];
extern BYTE code tOSD_iNAVIGATE_ICON[];
extern BYTE code tOSD_iNAVIGATE_MAIN_OSD_ICON0[];
extern BYTE code tOSD_iNAVIGATE_MAIN_OSD_ICON1[];
extern BYTE code tOSD_iNAVIGATE_MAIN_OSD_ICON2[];
extern BYTE code tOSD_iNAVIGATE_MAIN_OSD_ICON3[];
extern BYTE code tOSD_iNAVIGATE_MAIN_OSD_ICON4[];
extern BYTE code tOSD_iFACTORY_F_MAIN_OSD_ICON[];
#endif
extern BYTE code tOSD_SLIDER[];

//=============== 2Bit Icon ========================
extern BYTE code tiOSD_MAIN_BIR_ICON[];
extern BYTE code tiOSD_MAIN_IMAGE_ICON[];
extern BYTE code tiOSD_MAIN_COLORTEMP_ICON[];
extern BYTE code tiOSD_MAIN_OSDSETTING_ICON[];
extern BYTE code tiOSD_MAIN_RESET_ICON[];
extern BYTE code tiOSD_MAIN_MISC_ICON[];

#if(_LOGO_TYPE != _NONE_LOGO)
extern BYTE code tiOSD_1BIT_LOGO0[];
extern BYTE code tiOSD_1BIT_LOGO1[];
#endif

extern BYTE code tOSD_TYPE1_ICON[];
extern BYTE code tOSD_TYPE1_ICON1[];



extern BYTE code tOSD_TYPE1_ICON_SMALL0[];
extern BYTE code tOSD_TYPE1_ICON1_SMALL1[];
extern BYTE code tOSD_TYPE1_ICON1_SMALL2[];



extern BYTE code tOSD_TYPE2_ICON1[];
extern BYTE code tOSD_TYPE2_ICON2[];
extern BYTE code tOSD_TYPE2_ICON3[];
extern BYTE code tOSD_TYPE2_ICON4[];
extern BYTE code tOSD_TYPE2_ICON5[];
extern BYTE code tOSD_TYPE2_ICON6[];

//---------------------------------------------------------------------
// Definitions of OSD Show Number Function Used by OsdDisplayShowNumber()
//---------------------------------------------------------------------
#define _ALIGN_LEFT                                 (0)
#define _ALIGN_RIGHT                                (1)

#define _FORCE_SHOW_NUMBER_OFF                      (0 << 1)
#define _FORCE_SHOW_NUMBER_ON                       (1 << 1)

#define _SHOW_1                                     (0 << 4)
#define _SHOW_2                                     (1 << 4)
#define _SHOW_3                                     (2 << 4)
#define _SHOW_4                                     (3 << 4)
#define _SHOW_5                                     (4 << 4)
#define _SHOW_6                                     (5 << 4)

//------------------------------------------------------
// Definitions of OSD Slider Function Used by OsdDisplaySlider()
//------------------------------------------------------
#define _SLIDER_RESOLUTION                          (10)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define _PALETTE_INDEX0                             0   // 0 ~ 15
#define _PALETTE_INDEX1                             1   // 16 ~ 31
#define _PALETTE_INDEX2                             2   // 32 ~ 47
#define _PALETTE_INDEX3                             3   // 48 ~ 63

// OSD Position
#define _POS_DIRECT                                 0
#define _POS_PERCENT                                1

//--------------------------------------------------
// Definations of OSD MAIN MENU
//--------------------------------------------------
#if 0//(_DEF_KEY_NAVIGATION)	//��������
//���Ӱ�������
#define _OSD_MAIN_MENU_WIDTH                        57
#else
#define _OSD_MAIN_MENU_WIDTH                        55
#endif
#define _OSD_MAIN_MENU_HEIGHT                       24
#define _IMAGE_INFO_OFFSET                          0

#if(_OSD_7PAGE || _DEF_PAGE8)
#define _HENG_COUNT                                9
#else
#define _HENG_COUNT                                 8
#endif



//--------------------------------------------------
// Definations of OSD Type
//--------------------------------------------------

#define _OSD_MESSAGE_ROW_START                      4// 2
#define _OSD_MESSAGE_CENTER_COL_START               1//12
#define _OSD_MESSAGE_CENTER_COL_END                24// 24//23

//--------------------------------------------------
// Definations of HL window Border Size
//--------------------------------------------------
#define _HL_WIN_BORDER_SIZE                         2

//--------------------------------------------------
// Definations of Slider
//--------------------------------------------------
#define _SLIDER_LENGHT                              250
#define _SLIDER_HIGH                                20
#define _SLIDER_BORDER_PIXEL                        2
#define _SLIDER_OFFSET                              6

#define _SLIDER_SELECT_BORDER_COLOR                 _CP_GRAY
#define _SLIDER_SELECT_BG_COLOR                     _CP_WHITE

#define _SLIDER_UNSELECT_BORDER_COLOR               _CP_WHITE
#define _SLIDER_UNSELECT_BG_COLOR                   _CP_GRAY

#define _SLIDER_SELECT_COLOR                        _CP_ORANGE
#define _SLIDER_UNSELECT_COLOR                      _CP_BLUE

#define _SLIDER_0                                   0
#define _SLIDER_1                                   1
#define _SLIDER_2                                   2

#define _SELECT                                     1
#define _UNSELECT                                   0

#define _SLIDER_0_BAR_WINDOW                        _OSD_WINDOW_4_8 // _OSD_WINDOW_4_5
#define _SLIDER_0_BG_WINDOW                         _OSD_WINDOW_4_7 // _OSD_WINDOW_4_4
#define _SLIDER_0_BORDER_WINDOW                     _OSD_WINDOW_4_6 // _OSD_WINDOW_4_3

#define _SLIDER_1_BAR_WINDOW                        _OSD_WINDOW_4_8
#define _SLIDER_1_BG_WINDOW                         _OSD_WINDOW_4_7
#define _SLIDER_1_BORDER_WINDOW                     _OSD_WINDOW_4_6

#define _SLIDER_0_ROW                               16
#define _SLIDER_0_COL                               11

#define _ITEM_0                                     0
#define _ITEM_1                                     1
#define _ITEM_2                                     2
#define _ITEM_3                                     3
#define _ITEM_4                                     4
#define _ITEM_5                                     5
#define _ITEM_6                                     6
#define _ITEM_7                                     7

#define _NONE_ITEM                                  8

#define _FONTFROM_0_255                             0x00
#define _FONTFROM_256_512                           _BIT5


//--------------------------------------------------
// Definations of Color effect user mode Hue & Saturation
//--------------------------------------------------
#define _COLOR_HUE                                  0
#define _COLOR_SATURATION                           1

//--------------------------------------------------
// Definations of PCB DEFAULT  //luo
//--------------------------------------------------

#ifndef OSD_LED_CONTRL
#define OSD_LED_CONTRL(x)                      {\
											   }
#endif

#ifndef _OSD_LED_OFF
#define _OSD_LED_OFF                           0
#endif

#ifndef _OSD_LED_ON
#define _OSD_LED_ON                            1
#endif

#ifndef GET_LED_STATUS
#define GET_LED_STATUS()                        {\
												}
#endif

#ifndef PCB_AUDIO_VOLUME_PWM
#define PCB_AUDIO_VOLUME_PWM(x) { }
#endif

#ifndef PCB_HEADPHONE_DETECT
#define PCB_HEADPHONE_DETECT()      _HEADPHONE_DISCONNECT
#endif

#ifndef _HEADPHONE_DISCONNECT
#define _HEADPHONE_DISCONNECT       1
#endif

#ifndef _HEADPHONE_CONNECT
#define _HEADPHONE_CONNECT          0
#endif

#ifndef _MPRT_MIN_FRAME_RATE
#define _MPRT_MIN_FRAME_RATE          740
#endif


#ifndef _MPRT_RATIO
#if(_MPRT_WEAK_MID_HIGH)
#define _MPRT_RATIO          50
#else
#define _MPRT_RATIO          30
#endif
#endif


#ifndef _MPRT_MID_RATIO
#define _MPRT_MID_RATIO 									40
#endif

#ifndef _MPRT_HIGH_RATIO
#define _MPRT_HIGH_RATIO									30
#endif


//--------------------------------------------------
// Define enter panel uniformity msg adjust from pcm or gamma
//--------------------------------------------------
typedef enum
{
    _FROM_STATE_PCM,
    _FROM_STATE_GAMMA,
    _FROM_STATE_HDR,
    _FROM_STATE_LD,
    _FROM_STATE_SDRTOHDR,
} EnumFromWhichState;


//--------------------------------------------------
// Define PCM Soft Proft
//--------------------------------------------------
typedef enum
{
    _PCM_SOFT_MODE_1,
    _PCM_SOFT_MODE_2,
    _PCM_SOFT_MODE_AMOUNT = _PCM_SOFT_MODE_2,
} EnumPCMSoftProftMode;


//--------------------------------------------------
// Define Gamma
//--------------------------------------------------
typedef enum
{
    _GAMMA_OFF,
    _GAMMA_18,
    _GAMMA_20,
    _GAMMA_22,
    _GAMMA_24,
	_GAMMA_26,
    _GAMMA_AMOUNT = _GAMMA_26,
}EnumGammaType;


typedef enum
{
    _OGC_NORMAL_TYPE = 0,
    _OGC_MAX_BACKLIGHT_TYPE,
} EnumOGCModeSelect;

//--------------------------------------------------
// Define HL Window Type
//--------------------------------------------------
typedef enum
{
    _HL_WIN_OFF,
    _HL_WIN_1,
    _HL_WIN_2,
    _HL_WIN_3,
    _HL_WIN_4,
    _HL_WIN_5,
    _HL_WIN_AMOUNT = _HL_WIN_5,
}EnumHLWinType;

typedef enum
{
    _COLOREFFECT_STANDARD,
    _COLOREFFECT_PHOTO,
    _COLOREFFECT_MOVIE,
    _COLOREFFECT_GAME,
#if (_EOC_RTS_FPS_SUPPORT == _ON)
	_COLOREFFECT_FPS,
	_COLOREFFECT_RTS,
#endif  

#if(_DEF_COLORFUL)
	_COLOREFFECT_COLORFUL,	//����
#endif

#if(_EOC_ENERGY_SAVING_SUPPORT == _ON)

	_COLOREFFECT_ENERGY_SAVING,

#endif

    _COLOREFFECT_VIVID,
    _COLOREFFECT_USER,
    
#if (_EOC_ENERGY_SAVING_SUPPORT == _ON)

    _COLOREFFECT_AMOUNT = _COLOREFFECT_ENERGY_SAVING,

#elif(_DEF_COLORFUL)
	_COLOREFFECT_AMOUNT = _COLOREFFECT_COLORFUL,

#elif(_EOC_RTS_FPS_SUPPORT == _ON)
	_COLOREFFECT_AMOUNT = _COLOREFFECT_RTS,

#else
	_COLOREFFECT_AMOUNT = _COLOREFFECT_PHOTO,
#endif
}EnumColorEffectType;

//--------------------------------------------------
// Define Color Effect Six Color
//--------------------------------------------------
typedef enum
{
    _SIXCOLOR_R,
    _SIXCOLOR_Y,
    _SIXCOLOR_G,
    _SIXCOLOR_C,
    _SIXCOLOR_B,
    _SIXCOLOR_M,
    _SIXCOLOR_AMOUNT = _SIXCOLOR_M,
}EnumSixColorType;

//--------------------------------------------------
// Define Ultra Vivid
//--------------------------------------------------
typedef enum
{
    _ULTRA_VIVID_OFF,
        _ULTRA_VIVID_L,
    _ULTRA_VIVID_M,
    _ULTRA_VIVID_H,

    _ULTRA_VIVID_AMOUNT = _ULTRA_VIVID_H,
}EnumUltraVividType;


//--------------------------------------------------
// Define Supported Aspect Ratios
//--------------------------------------------------
typedef enum
{
/*
    _OSD_ASPECT_RATIO_FULL,
    _OSD_ASPECT_RATIO_16_BY_9,
    _OSD_ASPECT_RATIO_4_BY_3,
    _OSD_ASPECT_RATIO_5_BY_4,
    _OSD_ASPECT_RATIO_ORIGIN,
    _OSD_ASPECT_RATIO_USER,
    _OSD_ASPECT_RATIO_AMOUNT = _OSD_ASPECT_RATIO_USER,
 */
 
    _OSD_ASPECT_RATIO_16_BY_9,
    _OSD_ASPECT_RATIO_4_BY_3,
    _OSD_ASPECT_RATIO_ORIGIN,
    _OSD_ASPECT_RATIO_USER,
    _OSD_ASPECT_RATIO_FULL,
    _OSD_ASPECT_RATIO_1_BY_1,
    _OSD_ASPECT_RATIO_5_BY_4,

#if(_DEF_ASPECT_11)
	_OSD_ASPECT_RATIO_AMOUNT = _OSD_ASPECT_RATIO_ORIGIN,
#else
	_OSD_ASPECT_RATIO_AMOUNT = _OSD_ASPECT_RATIO_USER,
#endif
}EnumAspectRatioTypeIndex;

//--------------------------------------------------
// Define DP Port Version
//--------------------------------------------------
typedef enum
{
    _DP_VER_1_DOT_1 = 0,
    _DP_VER_1_DOT_2,
    _DP_VER_1_DOT_3,
    _DP_VER_AMOUNT = _DP_VER_1_DOT_2,//_DP_VER_1_DOT_3,
}EnumOSDDpPortVersionDef;

typedef enum
{
    _MST_OFF = 0,
    _MST_D0,
    _MST_D1,
    _MST_D6,
    _MST_AMOUNT = _MST_D6,
}EnumOSDDpMstTypeDef;

//--------------------------------------------------
// Define Display Image Rotate
//--------------------------------------------------
typedef enum
{
    _DISP_ROTATE_0 = 0,
#if(_DISPLAY_ROTATION_90_SUPPORT == _ON)
    _DISP_ROTATE_90,
#endif
#if(_DISPLAY_ROTATION_180_SUPPORT == _ON)
    _DISP_ROTATE_180,
#endif
#if(_DISPLAY_ROTATION_270_SUPPORT == _ON)
    _DISP_ROTATE_270,
#endif
#if(_DISPLAY_HOR_MIRROR_SUPPORT == _ON)
    _DISP_ROTATE_HOR_MIRROR,
#endif
#if(_DISPLAY_VER_MIRROR_SUPPORT == _ON)
    _DISP_ROTATE_VER_MIRROR,
#endif

    _DISP_ROTATE_AMOUNT,

}EnumOSDDispRotateDegree;

//--------------------------------------------------
// Define Display Latency
//--------------------------------------------------
typedef enum
{
    _LATENCY_L = 0,
    _LATENCY_M,
    _LATENCY_H,
    _LATENCY_AMOUNT = _LATENCY_H,
}EnumOSDDLatency;

//--------------------------------------------------
// Define HotKey Option
//--------------------------------------------------
typedef enum
{
    _HOTKEY_DDCCI = 0,
    _HOTKEY_DP_D0_OPTION,
    _HOTKEY_DP_D1_OPTION,
    _HOTKEY_DP_D2_OPTION,
    _HOTKEY_DP_D6_OPTION,
    _HOTKEY_AMOUNT = _HOTKEY_DP_D6_OPTION,
}EnumOSDHotKeyDef;


//--------------------------------------------------
// Definitions of Input Port
//--------------------------------------------------
typedef enum
{
#if(_SOURCE_AUTO_ON)
    _OSD_INPUT_AUTO = 0,
#endif    
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    _OSD_INPUT_A0,
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
	_OSD_INPUT_D0,
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
	_OSD_INPUT_D1,
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
	_OSD_INPUT_D2,	
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
    _OSD_INPUT_D3,	
#endif
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
    _OSD_INPUT_D4,	
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
    _OSD_INPUT_D5,	
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
    _OSD_INPUT_D6,	
#endif
    _OSD_INPUT_AMOUNT,
}EnumOSDInputPortDef;

//--------------------------------------------------
// Definitions of Color Temperature
//--------------------------------------------------
typedef enum
{
    _CT_9300,
    _CT_7500,
    _CT_6500,
    _CT_USER,
    _CT_5800,
    _CT_SRGB,
    

#if(_DEF_CT_JX)
    _CT_7000,
	_CT_8000,
	_CT_GAMMA18,
	_CT_GAMMA20,
	_CT_GAMMA22,
	_CT_GAMMA24,
	_CT_GAMMA26,
	_CT_COLORTEMP_AMOUNT = _CT_GAMMA26,
#else
	_CT_COLORTEMP_AMOUNT = _CT_USER,
#endif
}EnumColortemptureDef;


//--------------------------------------------------
// Definitions of 3D Effect
//--------------------------------------------------
typedef enum
{
    _3D_EFFECT_OFF = _OFF,
    _3D_EFFECT_WEAK,
    _3D_EFFECT_MEDIUM,
    _3D_EFFECT_STRONG,
    _3D_EFFECT_AMOUNT = _3D_EFFECT_STRONG,
}EnumOSDSelect3DEffectDef;

//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
typedef enum
{
#if(_DEF_COLORGAMUT_USER)
	_PCM_OSD_USER_DEFINE_2,//0
    _PCM_OSD_USER_DEFINE_3,// 1
    _PCM_OSD_USER_DEFINE_4,//  2
    _PCM_OSD_USER_DEFINE_5,// 3
    _PCM_OSD_USER_DEFINE_6,// 4
    _PCM_OSD_NATIVE,//5

    _PCM_OSD_AMOUNT = _PCM_OSD_NATIVE,
	
    _PCM_OSD_DISPLAY_P3,
    _PCM_OSD_HDR_2084,
    _TOTAL_COLORSPACE_OSD_NUM,
    _PCM_OSD_BYPASS,



#else
#if(_OCC_SUPPORT == _ON)
    _PCM_OSD_SRGB,
    _PCM_OSD_ADOBE_RGB,
#endif
	_PCM_OSD_DCI_P3,
    _PCM_OSD_NATIVE,
    _PCM_OSD_USER,
#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
    _PCM_OSD_SOFT_PROFT,
    _PCM_OSD_AMOUNT = _PCM_OSD_SOFT_PROFT,
#else
    _PCM_OSD_AMOUNT = _PCM_OSD_NATIVE,
#endif

#endif
}EnumPCMTypeIndex;

//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
typedef enum
{
    _UNIFORMITY_OSD_TYPE1 = 0,  // gamma 1.8
    _UNIFORMITY_OSD_TYPE2,      // gamma 2.0
    _UNIFORMITY_OSD_TYPE3,      // gamma 2.2
    _UNIFORMITY_OSD_TYPE4,      // gamma 2.4
    _UNIFORMITY_OSD_TYPE5,      // srgb
    _UNIFORMITY_OSD_TYPE6,      // adobe rgb
}EnumUniformityTypeSelectIndex;
//--------------------------------------------------
// Definitions of Clone Mode
//--------------------------------------------------
typedef enum
{
    _OSD_CLONE_OFF = 0,
    _OSD_CLONE_ON,
}EnumOSDCloneModeDef;
//--------------------------------------------------
// Define of Level Type
//--------------------------------------------------
typedef enum
{
    _LEVEL_OFF = 0,
    _LEVEL_L,
    _LEVEL_M,
    _LEVEL_H,
    _LEVEL_AMOUNT = _LEVEL_H,
}EnumLevelType;

//--------------------------------------------------
// Definitions of EnumOSDShowType
//--------------------------------------------------

typedef enum
{
    _TYPE_NONE,
    _TYPE_ARROW,
    _TYPE_SLIDER,	//������
    _TYPE_SUBMENU,
}EnumOSDShowType;
//--------------------------------------------------
// Definitions of EnumOSDLedType
//--------------------------------------------------

typedef enum
{
    _OSDLedType_OFF,
    _OSDLedType_ON,
    _OSDLedType_FLASH, 
    _OSDLedType_END = _OSDLedType_ON,//_OSDLedType_FLASH,
}EnumOSDLedType;

//--------------------------------------------------
// Definitions of AutoPowerOff
//--------------------------------------------------



typedef enum
{
    _AutoPowerOff_OFF,
    _AutoPowerOff_1,    
    _AutoPowerOff_2,
    _AutoPowerOff_3,
    _AutoPowerOff_4,
    _AutoPowerOff_5,   
    _AutoPowerOff_6,   
    _AutoPowerOff_7,
	_AutoPowerOff_8,
	_AutoPowerOff_9,
	_AutoPowerOff_10,
	_AutoPowerOff_11,
	_AutoPowerOff_12,
	_AutoPowerOff_13,
	_AutoPowerOff_14,
	_AutoPowerOff_15,
	_AutoPowerOff_16,
	_AutoPowerOff_17,
	_AutoPowerOff_18,
	_AutoPowerOff_19,
	_AutoPowerOff_20,
	_AutoPowerOff_21,
	_AutoPowerOff_22,
	_AutoPowerOff_23,
	_AutoPowerOff_24,

	_AutoPowerOff_END = _AutoPowerOff_24,

}EnumOSDAutoPowerOff;


//--------------------------------------------------
//--------------------------------------------------

typedef struct
{
    BYTE b1OsdLogo : 1;
    BYTE b1OsdWakeUpSwitchDdcciPort : 1;
    BYTE b1OsdWakeUpShowSource : 1;
    BYTE b1OsdFactoryModeStatus : 1;
    BYTE b1OsdDoAspectRatio : 1;
    BYTE b3OsdColorFormat : 3;
    BYTE b3OsdsixColor : 3;
    BYTE b1OsdDoubleSizeStatus : 1;
    BYTE b1FreezeStatus : 1;
#if((_URGENT_EVENT_CHECK_MODE == _OFF) && (_FREEZE_SUPPORT == _ON))
    BYTE b1FreezeDisableOsdStatus : 1;
#endif
#if(_DP_DEBUG_MSG == _ON)
    BYTE b1OsdWakeUpShowDpINFO : 1;
    BYTE b4OsdWakeUpShowDpINFOPort : 4;
#endif
    BYTE ucOsdStatePrevious;
    WORD usOsdState;
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;
    BYTE b3OsdsixColorHue;
    BYTE b3OsdsixColorSaturation;
    BYTE ucOsd3DEffectRealValue;

#if(_FREESYNC_SUPPORT == _ON)
    BYTE ucOsdFREESYNCInforOsdAddress;
#endif
    BYTE ucOsdItemIndex;

    BYTE b2StringMode               : 2;
    BYTE ucStringModeLength;
    BYTE ucStringBlankPixel;

} StructOsdInfo;

enum OSDFontDef
{
_ = 0,
_0_,_1_,_2_,_3_,_4_,_5_,_6_,_7_,_8_,_9_,
_A_, _B_, _C_, _D_, _E_, _F_, _G_, _H_, _I_, _J_, _K_, _L_, _M_, _N_, _O_, _P_, _Q_, _R_, _S_, _T_, _U_, _V_, _W_, _X_, _Y_,_Z_,
_a_,_b_,_c_,_d_,_e_,_f_,_g_,_h_,_i_,_j_,_k_,_l_,_m_,_n_,_o_,_p_,_q_,_r_,_s_,_t_,_u_,_v_,_w_,_x_,_y_,_z_,
_x0_ = 0,
_x1_,_x2_,_x3_,_x4_,_x5_,_x6_,_x7_,_x8_,_x9_,_xa_,_xb_,_xc_,_xd_,_xe_,_xf_,
_x10_,_x11_,_x12_,_x13_,_x14_,_x15_,_x16_,_x17_,_x18_,_x19_,_x1a_,_x1b_,_x1c_,_x1d_,_x1e_,_x1f_,
_x20_,_x21_,_x22_,_x23_,_x24_,_x25_,_x26_,_x27_,_x28_,_x29_,_x2a_,_x2b_,_x2c_,_x2d_,_x2e_,_x2f_,
_x30_,_x31_,_x32_,_x33_,_x34_,_x35_,_x36_,_x37_,_x38_,_x39_,_x3a_,_x3b_,_x3c_,_x3d_,_x3e_,_x3f_,
_x40_,_x41_,_x42_,_x43_,_x44_,_x45_,_x46_,_x47_,_x48_,_x49_,_x4a_,_x4b_,_x4c_,_x4d_,_x4e_,_x4f_,
_x50_,_x51_,_x52_,_x53_,_x54_,_x55_,_x56_,_x57_,_x58_,_x59_,_x5a_,_x5b_,_x5c_,_x5d_,_x5e_,_x5f_,
_x60_,_x61_,_x62_,_x63_,_x64_,_x65_,_x66_,_x67_,_x68_,_x69_,_x6a_,_x6b_,_x6c_,_x6d_,_x6e_,_x6f_,
_x70_,_x71_,_x72_,_x73_,_x74_,_x75_,_x76_,_x77_,_x78_,_x79_,_x7a_,_x7b_,_x7c_,_x7d_,_x7e_,_x7f_,
_x80_,_x81_,_x82_,_x83_,_x84_,_x85_,_x86_,_x87_,_x88_,_x89_,_x8a_,_x8b_,_x8c_,_x8d_,_x8e_,_x8f_,
_x90_,_x91_,_x92_,_x93_,_x94_,_x95_,_x96_,_x97_,_x98_,_x99_,_x9a_,_x9b_,_x9c_,_x9d_,_x9e_,_x9f_,
_xa0_,_xa1_,_xa2_,_xa3_,_xa4_,_xa5_,_xa6_,_xa7_,_xa8_,_xa9_,_xaa_,_xab_,_xac_,_xad_,_xae_,_xaf_,
_xb0_,_xb1_,_xb2_,_xb3_,_xb4_,_xb5_,_xb6_,_xb7_,_xb8_,_xb9_,_xba_,_xbb_,_xbc_,_xbd_,_xbe_,_xbf_,
_xc0_,_xc1_,_xc2_,_xc3_,_xc4_,_xc5_,_xc6_,_xc7_,_xc8_,_xc9_,_xca_,_xcb_,_xcc_,_xcd_,_xce_,_xcf_,
_xd0_,_xd1_,_xd2_,_xd3_,_xd4_,_xd5_,_xd6_,_xd7_,_xd8_,_xd9_,_xda_,_xdb_,_xdc_,_xdd_,_xde_,_xdf_,
_xe0_,_xe1_,_xe2_,_xe3_,_xe4_,_xe5_,_xe6_,_xe7_,_xe8_,_xe9_,_xea_,_xeb_,_xec_,_xed_,_xee_,_xef_,
_xf0_,_xf1_,_xf2_,_xf3_,_xf4_,_xf5_,_xf6_,_xf7_,_xf8_,_xf9_,_xfa_,_xfb_,_xfc_,_xfd_,_xfe_,_xff_,
};

typedef enum
{
    _CP_EMPTY = 0,
    _CP_BG1 = 0,
    _CP_BLACK1 = 0,
    _CP_WHITE1,
    _CP_BLUE_1201,
    _CP_GREEN_119,
    _CP_BLUE1,
    _CP_YELLOW1,
    _CP_GRAY1,
    _CP_ORANGE,
    _CP_LIGHTBLUE1,
    _CP_SELECTBOTTOM1,
    _CP_PINK,
    _CP_RED1,
    _CP_GREEN_1,
    _CP_ORANGE_DARK,
    _CP_ORANGE_H,
    _CP_GRAY_1,
}EnumOSDColorPaletteDef;

typedef enum
{
	_CP_BG = 0,
    _CP_BLACK = 0,
    _CP_WHITE,
    _CP_RED,
    _CP_GREEN,
    _CP_BLUE,
    _CP_YELLOW,
    _CP_LIGHTBLUE,
    _CP_DARKBLUE,
    _CP_LIGHTBLUE_1,//8
    
    _CP_GRAY,
    _CP_BLACK_1,
    _CP_DARKBLUE_1,
    _CP_BLUE_1,


    _CP_LIGHTGRAY,

    
    _CP_BLUE_120,
    _CP_SELECTBOTTOM,
};

typedef enum
{
    _LOGO_CP_BG = 0,
    _LOGO_CP_BLACK = 0,
    _LOGO_CP_WHITE,
    _LOGO_CP_RED,
    _LOGO_CP_GREEN,
    _LOGO_CP_BLUE,
    _LOGO_CP_YELLOW,
    _LOGO_CP_GRAY,
    _LOGO_CP_DARKBLUE,
    _LOGO_CP_LIGHTBLUE,
    _LOGO_CP_SELECTBOTTOM,
    _LOGO_CP_PINK,
    _LOGO_CP_RED_1,
    _LOGO_CP_GREEN_1,
    _LOGO_CP_ORANGE_L,
    _LOGO_CP_ORANGE_H,
    _LOGO_CP_BLUE_1,
}EnumOSDColorPaletteLogo;


typedef enum
{
    _FONT1_GLOBAL,
	_FONT2_GLOBAL,
    _REALTEK_1BIT_LOGO0,
    _REALTEK_1BIT_LOGO1,
    _HOTKEY_1BIT_ICON,
}EnumFont;


typedef enum
{
    _PALETTE_RTD_LOGO,
    _PALETTE_MAIN_MENU,
}EnumPalette;
#if 0//

typedef enum
{

#if _ENGLISH_SUPPORT
    _START_LANGUAGE = 0,        
	_ENGLISH = 0,                //Ӣ��
#endif
#if _GERMAN_SUPPORT
    _GERMAN,							//����
#endif
#if _SPANISH_SUPPORT
	_SPANISH,				//��������
#endif
#if _FRENCH_SUPPORT
	_FRENCH,							//����
#endif
#if _ITALIAN_SUPPORT
    _ITALIAN,				//�������
#endif
#if _DUTCH_SUPPORT
    _DUTCH, 			//������
#endif
#if _PORTUGUESE_SUPPORT
    _PORTUGUESE,				//��������
#endif
#if _SVENSKA_SUPPORT
    _SVENSKA,			//�����
#endif
#if _TURKISH_SUPPORT
    _TURKISH,					//��������
#endif
#if _XILAYU_SUPPORT
    _XILAYU,	//ϣ����
#endif
#if _MAGYAR_SUPPORT
    _MAGYAR,   //��������
#endif
#if _POLSKI_SUPPORT
    _POLSKI,			//������
#endif
#if _CHINESE_S_SUPPORT
    _CHINESE_S,                         	//���� ����
#endif
#if _JAPANESE_SUPPORT
	_JAPANESE,			//����
#endif
#if _RUSSIAN_SUPPORT
	_RUSSIAN,           //����--�����˶���˹
#endif
#if _KOREAN_SUPPORT
	_KOREAN,          //����
#endif
#if _FINNISH_SUPPORT
	_FINNISH,		//������
#endif
#if _CZECH_SUPPORT
	_CZECH,			//�ݿ���
#endif

#if _CHINESE_F_SUPPORT
    _CHINESE_F,                         	//����
#endif

	_LANGUAGE_MAX=1,
    _LANGUAGE_AMOUNT = _LANGUAGE_MAX-1,
}EnumOSDLanguageDef;

#else


typedef enum
{

#if _ENGLISH_SUPPORT
    _START_LANGUAGE = 0,        
	_ENGLISH = 0,                //Ӣ��
#endif
#if _GERMAN_SUPPORT
    _GERMAN,							//����
#endif
#if _SPANISH_SUPPORT
	_SPANISH,				//��������
#endif
#if _FRENCH_SUPPORT
	_FRENCH,							//����
#endif
#if _ITALIAN_SUPPORT
    _ITALIAN,				//�������
#endif
#if _DUTCH_SUPPORT
    _DUTCH, 			//������
#endif
#if _PORTUGUESE_SUPPORT
    _PORTUGUESE,				//��������
#endif
#if _SVENSKA_SUPPORT
    _SVENSKA,			//�����
#endif
#if _TURKISH_SUPPORT
    _TURKISH,					//��������
#endif
#if _XILAYU_SUPPORT
    _XILAYU,	//ϣ����
#endif
#if _MAGYAR_SUPPORT
    _MAGYAR,   //��������
#endif
#if _POLSKI_SUPPORT
    _POLSKI,			//������
#endif
#if _CHINESE_S_SUPPORT
    _CHINESE_S,          //���� ����  12
#endif
#if _JAPANESE_SUPPORT
	_JAPANESE,			//����
#endif
#if _RUSSIAN_SUPPORT
	_RUSSIAN,           //����--�����˶���˹
#endif
#if _KOREAN_SUPPORT
	_KOREAN,          //����
#endif
#if _FINNISH_SUPPORT
	_FINNISH,		//������
#endif
#if _CZECH_SUPPORT
	_CZECH,			//�ݿ���
#endif

#if _CHINESE_F_SUPPORT
    _CHINESE_F,          //����
#endif

#if _KAZAK_SUPPORT
	_KAZAK,		//��������
#endif

	_LANGUAGE_MAX,

_LANGUAGE_AMOUNT = _LANGUAGE_MAX-1,
}EnumOSDLanguageDef;

#endif

typedef enum
{
    _OSDEVENT_NONE_MSG = 0,
    _OSDEVENT_SHOW_NOSIGNAL_MSG,
    _OSDEVENT_SHOW_NOCABLE_MSG,
    _OSDEVENT_SHOW_NOSUPPORT_MSG,
    _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG,
    _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_WAIT_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG,
    _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG,
    _OSDEVENT_DO_AUTO_CONFIG_MSG,
    _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG,
    _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG,
    _OSDEVENT_SAVE_NVRAM_BRICON_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG,
    _OSDEVENT_DP_VERSIOM_MSG,
	_OSDEVENT_BUININ_MSG,
}EnumOSDEvenMassage;

typedef enum
{
    _OSD_DISP_NOSIGNAL_MSG,
    _OSD_DISP_NOCABLE_MSG,
    _OSD_DISP_NOSUPPORT_MSG,	//��֧��  ����: ��Ƶ��֧��
    _OSD_DISP_FAIL_SAFE_MODE_MSG,
    _OSD_DISP_AUTO_CONFIG_MSG,
    _OSD_DISP_INPUT_SIGNAL_MSG,
    _OSD_DISP_AUTO_COLOR_MSG,
    _OSD_DISP_SWITCH_DDCCI_PORT_MSG,
    _OSD_DISP_POWER_SAVING_MSG,
    _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG,
#if(_FREEZE_SUPPORT == _ON)
    _OSD_DISP_DISABLE_FREEZE_MSG,
#endif
#if(_DP_MST_SUPPORT == _ON)
    _OSD_DISP_MST_WARNING_MSG,
#endif
	_OSD_DISP_BACKLIGHT_MODE_MSG,
	_OSD_DISP_ENERGE_NOTICE_MSG,

} EnumOSDDispMsg;


typedef enum
{
	_OSD_STRING_TITLE,
	
	_OSD_STRING_ITEM,
	
	_OSD_STRING_SHOW_NUMBER,

	
	_OSD_STRING_ARROW,

	_OSD_STRING_NO_SIGNAL,	
	_OSD_STRING_POWEROFF_SHOW,
	
	_OSD_STRING_NO_SUPPORT,
	_OSD_STRING_POWER_SAVING,
	_OSD_STRING_NOW_RESOLUTION,
	_OSD_STRING_NOW_RESOLUTION1,
	_OSD_STRING_FACTORY,

	_OSD_STRING_RGB,
	_OSD_STRING_SIGNAL,
	_OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_1,
	_OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_2,
	_OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_3,
	_OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_4,
		
	_OSD_STRING_HZ,

#if _ENABLE_ENERGE_NOTICE_MENU
	_OSD_STRING_ENERGY_NOTICE_1,
	_OSD_STRING_ENERGY_NOTICE_2,
	_OSD_STRING_ENERGY_NOTICE_3,
#endif

#if 1//_LONG_PRESS_MENU_LOCK_OSD_ENABLE
	_OSD_STRING_FUN_LOCK_MENU,
#endif

#if 1//_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
	_OSD_STRING_FUN_LOCK_POWER_KEY,
#endif

#if(_DEF_REAL_TIME_HZ)
	_OSD_PINLVXIANSHI_HZ,
#endif

#if 0//(_DEF_STA_SIX_COLOR)
	_OSD_STA_SIX_COLOR,
#endif
	_OSD_YES_NO,
    _OSD_STRING_NOW_SOURCE1,
    _OSD_STRING_NOW_WINDOW,
    _OSD_STRING_MODEL_VER,
    _STRIN_END,
}EnumStringIndex;

typedef enum
{
#if(_SOURCE_AUTO_ON)
	
	_STRING_AUDO_PORT,
#endif
    // input
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    _STRING_A0_PORT,
#endif
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)	
    _STRING_D0_PORT,
#endif    
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)	
    _STRING_D1_PORT,
#endif    
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)	
    _STRING_D2_PORT,
#endif    
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)	
    _STRING_D3_PORT,
#endif    
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)	
    _STRING_D4_PORT,
#endif    
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)	
    _STRING_D5_PORT,
#endif    
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)	
    _STRING_D6_PORT,
#endif    

}EnumStringPort;

typedef enum
{
    _A0_PORT = 0,
    _D0_PORT,
    _D1_PORT,
    _D2_PORT,
    _D3_PORT,
    _D4_PORT,
    _D5_PORT,
    _D6_PORT,
}EnumPortInx;

typedef enum
{
    _OSD_ROTATE_DISPLAY_FULL = 0,
    _OSD_ROTATE_DISPLAY_PIXEL_BY_PIXEL,
    _OSD_ROTATE_DISPLAY_KEEP_SRC_ASPECT_RATIO,
}EnumOsdRotationDisplaySizeDef;

typedef enum
{
    _AUTO_CONFIG_DO = 0,
    _AUTO_CONFIG_RESULT,
}EnumautoConfig;





//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
// __RTD_DDCCI__
extern bit g_bForcePowSavStatus;


// __RTD_OSD__
extern StructOsdInfo g_stOsdInfo;
extern WORD g_usAdjustValue;
extern WORD g_usBackupValue;
extern BYTE g_ucLogoTimerCounter;
extern WORD g_usPowerDownCount;
extern BYTE g_usPowerDownCount_MSG;

extern BYTE g_ucLanguage;
extern BYTE g_ucPowerPage;


#if(_DEF_HOTKEY_REPLACE)
extern BYTE g_ucHotKey_Left;
extern BYTE g_ucHotKey_Right;
extern BYTE g_ucHotKey_Exit;
#endif


// __RTD_OSDFUNC__
extern WORD g_usFontSelectStart;
extern WORD g_usFontTableStart;
extern BYTE g_ucOsdWidth;
extern BYTE g_ucOsdHeight;
extern BYTE g_ucOsdWidthB;
extern BYTE g_ucOsdHeightB;
extern BYTE g_ucFontPointer0;
extern BYTE g_ucFontPointer1;
extern BYTE g_ucFontPointer2;


//----------------------------------------------------------------------------------------

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserDdcci.c
//----------------------------------------------------------------------------------------
// __RTD_DDCCI__
extern void UserDdcciHandler(void);

//----------------------------------------------------------------------------------------
// Extern functions from RTDKey.c
//----------------------------------------------------------------------------------------
// __RTD_KEY__
extern void RTDKeyInitial(void);

//----------------------------------------------------------------------------------------
// Extern functions from Osd.c
//----------------------------------------------------------------------------------------
// __RTD_OSD__


//----------------------------------------------------------------------------------------
// Extern functions from OsdFunc.c
//----------------------------------------------------------------------------------------
// __RTD_OSDFUNC__
extern void OsdDispSliderAndNumber(BYTE ucItemRow,BYTE ucOsdState, WORD usValue);

extern void UpdateOSDMainInterface(BYTE ucState);

extern void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void OsdFuncSetPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY);
extern void OsdFuncTransparency(BYTE ucTrans);
extern void OsdFuncBlending(BYTE ucType);

extern void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex);
extern void OsdFuncDisableOsd(void);
extern void OsdFuncEnableOsd(void);
extern void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth ,BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom);
extern void OsdFuncSet2BitIconOffset(BYTE ucOffset);
extern void OsdFuncSet4BitIconOffset(WORD ucOffset);
extern void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth ,BYTE ucHeight);
#if(_PCM_FUNCTION == _ON)
extern void OsdFuncColorPcmAdjust(void);
#endif
extern void OsdFuncSetOsdItemFlag(void);

#if(_FREEZE_SUPPORT == _ON)
extern bit OsdFuncCheckFreezeDisable(void);
#endif

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
extern BYTE OsdFuncGetHdmiPortVersion(EnumSourceSearchPort enumSearchPort);
extern void OsdFuncSetHdmiPortVersion(EnumSourceSearchPort enumSearchPort,BYTE ucValue);
#endif

#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))
extern void OsdFuncPutIcon1BitAndColorWidthHeight(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucWidth , BYTE ucHeight, BYTE ucColor);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from OsdDisplay.c
//----------------------------------------------------------------------------------------
// __RTD_OSDDISPLAY__
extern BYTE OsdDispJudgeSourceType(void);

extern void OsdDispDisableOsd(void);
extern void OsdDispSetPosition(BYTE ucType,EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos);


#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))
extern void OsdDisplayVfreq(void);
#endif

#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
extern void OsdDispEngerMainMenu(void);
#endif
extern void OsdDispMainMenu(void);

extern WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
extern void OsdDispOsdReset(void);
extern WORD OsdDisplayDetOverRangeRotation(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
extern void OsdDispOsdMessageEngerConsumption(void);
#endif

extern void OsdDispOsdMessagePoweroff(void);
extern void UpdateOsdDispOsdMessagePoweroff(void);


extern void OsdDispOsdMessage(EnumOSDDispMsg enumMessage);
#if(_VGA_SUPPORT == _ON)
extern void OsdDispAutoConfigProc(void);
extern void OsdDisplayAutoBalanceProc(void);
#endif

extern void OsdDispShowLogo(void);
extern BYTE GetOsdShowType(BYTE ucStateIndex);
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
extern BYTE GetOSDMSG(BYTE ucStateIndex);
#endif
extern BYTE GetOsdValue(BYTE ucStateIndex);
extern BYTE GetOsdMaxItem(BYTE ucStateIndex);
extern BYTE GET_SILDER_PERCENT(BYTE ucOsdState);

#if(_DEF_STA_SIX_COLOR)
extern void OsdDisplaySixColorGetOneColor(BYTE ucColor);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from OsdFont.c
//----------------------------------------------------------------------------------------
// __RTD_OSDFONTVLC__
extern void OsdFontVLCLoadFont(BYTE ucState);

// __RTD_OSDFONTDYNAMICICON_1__
extern void OsdFontVLCDynamicLoadIcon(BYTE ucIconPos, WORD usIcon);
#if(_DEF_OSD_EDID_INFO)
void RTDOsdTableFuncPutStringProp_EDIDInfo(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE *pArray,BYTE COLOR);
#endif


// __RTD_OSDFONTTABLE__
extern void OsdFontPut1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor, BYTE ucPage);
extern void OsdFontPut1BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor, BYTE ucPage);
extern void OsdFontPut2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void OsdFontPut2BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void OsdFontPut1BitTable_LOGO(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor, BYTE ucPage);

extern void OsdFontPut4BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray);

// __RTD_OSDFONTPROP__
extern void SG_PutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucIndex,BYTE ucColor, BYTE ucLanguage);

extern void RTDOsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucIndex,BYTE ucColor, BYTE ucLanguage);
extern void RTDOsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucCOLOR,SBYTE ucCenterOffset , BYTE ucLanguage);
extern void OsdPropShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar ,BYTE ucFontPoint, BYTE ucColor);

// __RTD_OSDPALETTE__
extern void OsdPaletteSelectPalette(BYTE ucValue);

// __RTD_OSDWINDOW__
extern void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdWindowDrawingHighlight(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor, BYTE ucENABLE);
extern void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);

extern void OsdMenuDrawingHighlight(BYTE ucWindow,BYTE ucForegroundColor, BYTE ucBackgroundColor, BYTE ucENABLE);

#if((_HDR10_SUPPORT == _OFF)&&((_PROJECT == _RL6463_PROJECT)||(_PROJECT == _RL6369_PROJECT)))
extern void ScalerGetHDR10Data_MOCK(BYTE *pucHDRData);
#endif
//----------------------------------------------------------------------------------------
// Extern functions from OsdTableFunc.c
//----------------------------------------------------------------------------------------
// __RTD_OSDTABLEFUNC__
extern void OsdTableFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar, BYTE ucFontPoint);
extern BYTE OsdTableFuncVideoResolution(void);
extern void OsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucLanguage);
extern void OsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, SBYTE chCenterOffset, BYTE ucLanguage);
extern void OsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdTableFuncPutIcon1BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void OsdTableFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void UpdateMaskValue(void);
extern void OSDSubMenuMove(void);
extern BYTE OsdFuncGetOsdItemFlag(void);
extern void OsdFuncAdj(void);
extern void OsdFuncAdjHotKey(void);
#if(_NAVIGAT_MENU_SURPPORT)
extern void MenuNavigatNone(void);
extern void OsdDispNavigatMenu(void);
#endif

extern void RTDOsdDispHotkeyFuncAdjust(BYTE ucHotkeyType);
extern void RTDOsdDisplayDrawMessageWindow(WORD usValue);
extern void OsdHotKeyFuncSpacialProc(void);
extern WORD DetOverRangeForHotkeySelect(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
extern void UpdateItemMaskValue(void);
extern void FactoryBurnInEvent(void);
#if (_BURNIN_MSG_MENU_SUPPORT==_ON)

extern void RTDBurnInMenu(void);
#endif
extern void UpdateMaskItem(void);
extern void OsdInputSourceHotkey();
#if(_HDR10_SUPPORT == _OFF)
extern void MockHdrEffect(void);
#endif

#if(_MPRT_SUPPORT == _ON)
extern void UserAdjustLowMotionBlurDisplay(BYTE ucTconLevel);
#endif

#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)

#if(_DEF_2795E06)
extern BYTE xdata g_SouceSelect;
#endif

#if(_IR_VIRTUAL)	
extern bit f_resaveok;
extern DWORD r_data;
#endif

#if(_DEF_PAGE8)
#define _DEF_OSD_2_END							_MENU_MISC_TATE6
#define _OSD_NUM_DATA							7
#else
#define _DEF_OSD_2_END							_MENU_MISC_TATE5
#define _OSD_NUM_DATA							6
#endif

