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
// ID Code      : HK_OSD_UserInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_OSD_TYPE == _REALTEK_2014_OSD)
#include"Logo.h"
#include"LuoGang_OSD_UserInclude.h"
#include"HK_OSD_FuncDefine.h"

/*
		���ù��ܶ���
*/
#ifndef _OSD_BLACK_WHITE_TYPE
#define	_OSD_BLACK_WHITE_TYPE								_OFF //�ڰ׺����ײ˵�ѡ��
#endif


#ifndef _OSD_BLUE_TYPE
#define	_OSD_BLUE_TYPE								_OFF//N //��ɫ�ͺ�ɫ �˵�ѡ��
#endif

#ifndef _OSD_BLACK_TYPE//��ɫ�˵�ѡ��
#if(_OSD_BLUE_TYPE)
#define _OSD_BLACK_TYPE								4//_CP_BLUE
#elif(_OSD_BLACK_WHITE_TYPE)
#define _OSD_BLACK_TYPE								7//_CP_DARKBLUE

#elif(_CAIXIAOLI)
#define _OSD_BLACK_TYPE								_CP_BLACK//_CP_DARKBLUE


#else
#define _OSD_BLACK_TYPE								2//_CP_RED 
#endif
#endif

#ifndef  _LANG_19
#define	_LANG_19								_OFF
#endif



#ifndef _NAVIGAT_MENU_SURPPORT
#define _NAVIGAT_MENU_SURPPORT						  		_OFF  //�����˵�
#endif

#ifndef _SOURCE_AUTO_ON
#define _SOURCE_AUTO_ON								        _ON //�ź��л��Ƿ��auto
#endif

#ifndef	_EOC_RTS_FPS_SUPPORT
#define _EOC_RTS_FPS_SUPPORT					     	    _ON  //ECOģʽ�Ƿ�� RTS��FPS
#endif

#ifndef _WCH_MESSAGE_ADDR
#define _WCH_MESSAGE_ADDR									_OFF	//��ʺ絯��λ��
#endif

#ifndef	_EOC_ENERGY_SAVING_SUPPORT
#define _EOC_ENERGY_SAVING_SUPPORT					     	    _OFF  //ECOģʽ�Ƿ��ENERGY_SAVING
#endif


#ifndef _CT_7500_5800_sRGB_SUPPRT
#define _CT_7500_5800_sRGB_SUPPRT							_OFF  //ɫ���Ƿ��7500.5800.sRGB
#endif

#ifndef _RESET_KEEP_LANGUAGE
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#endif

#ifndef _ENABLE_ENERGE_NOTICE_MENU
#define _ENABLE_ENERGE_NOTICE_MENU         					_OFF	//�ܺ�����
#endif

#ifndef _LONG_PRESS_MENU_LOCK_OSD_ENABLE
#define _LONG_PRESS_MENU_LOCK_OSD_ENABLE  					_OFF	//�˵�������
#endif

#ifndef _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
#define _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE  			_OFF	//��Դ��������
#endif

#ifndef _DEF_REAL_TIME_HZ
#define _DEF_REAL_TIME_HZ									_OFF	//ʵʱˢ��Ƶ��
#endif

#ifndef _DEF_KEY_NAVIGATION
#define _DEF_KEY_NAVIGATION									_OFF	//��������
#endif

#ifndef _OD_WEAK_MID_HIGH
#define _OD_WEAK_MID_HIGH									_OFF	//OD ����ǿ
#endif

#ifndef _MPRT_WEAK_MID_HIGH
#define _MPRT_WEAK_MID_HIGH									_OFF
#endif

#ifndef _DEF_ECO_SET
#define _DEF_ECO_SET										_OFF	//�ͻ�Ҫ���ECOģʽ���趨ֵ(����/����7������Ҫ�����)
#endif

#ifndef _DCC_PROGRESS_BAR
#define _DCC_PROGRESS_BAR									_OFF	//DCC������ģʽ
#endif

#ifndef _DEF_PROGRESS_BAR_3PAGE
#define _DEF_PROGRESS_BAR_3PAGE								_OFF//����ѡ���ӳ����������˵�
#endif

#ifndef _DEF_RESET_SOURCE_AUTO
#define _DEF_RESET_SOURCE_AUTO								_OFF //���ú��źŻ�ԭ���Զ�
#endif

#ifndef _DEF_HSBL
#define _DEF_HSBL											_OFF //�˹����
#endif


#ifndef _DEF_PROGRESS_BAR_NEW
#define _DEF_PROGRESS_BAR_NEW								_OFF //��������ECO����
#endif

#ifndef _DEF_HDR_540
#define _DEF_HDR_540										_OFF //HDR����һ��
#endif

#ifndef _DEF_HUIXIONG_BURN_MENU
#define _DEF_HUIXIONG_BURN_MENU								_OFF //���ܹ����˵�
#endif

#ifndef _DEF_SCREEN_SWITCHING
#define _DEF_SCREEN_SWITCHING								_OFF //�л�����������
#endif

#ifndef _DEF_ASPECT_11
#define _DEF_ASPECT_11										_OFF //�����������1:1
#endif

#ifndef _DEF_OSD_LOGO
#define _DEF_OSD_LOGO										_OFF //�˵�LOGO
#endif

#ifndef _DEF_PANEL_IMPRINTING
#define _DEF_PANEL_IMPRINTING								_OFF	//ʮ�ֹ���
#endif

#ifndef _OSD_RECALL_FUNC
#define _OSD_RECALL_FUNC									_OFF //�˳��˵��Ƿ����ǰ���״̬
#endif

#ifndef _DEF_AUDIO_SOURCE_SELECT
#define _DEF_AUDIO_SOURCE_SELECT							_OFF //��Ƶѡ�����  ���Ȼ��Ƕ���
#endif

#ifndef _DCR_PANEL_ON_OFF
#define _DCR_PANEL_ON_OFF									_OFF //DCR�򿪣��ڳ��Ƿ�ر���
#endif

#ifndef _DEF_SAVING_SOURCE
#define _DEF_SAVING_SOURCE									_OFF //ʡ��ģʽ�¿���ѡ��ӿ�ͨ��
#endif

#ifndef _DEF_SHARPNESS_ONE
#define _DEF_SHARPNESS_ONE									_ON//FF	//�����Ƚ�������ʾ100
#endif

#ifndef _DEF_HDR_COLOR_6432
#define _DEF_HDR_COLOR_6432									_OFF	//6432HDR����˲����ɫ  (�����ȿ���,��˵��ٿ���û�й�������������ɫ)
#endif


#ifndef _DEF_HOTKEY_REPLACE
#define _DEF_HOTKEY_REPLACE									_OFF	//���ģʽ�л�
#endif


#ifndef _ADJ_BACKLIGHT_BY_TABLE
#define _ADJ_BACKLIGHT_BY_TABLE								_OFF //������ڷ�ʽ 
#endif
//ʹ��TABLE��ʽʱ����ͬʱҲ����_BACKLIGHT_DEF_PWM  _BACKLIGHT_MIN _BACKLIGHT_MAX (for DCR Mode)

#ifndef _OSD_7_KEY_SUPPROT
#define _OSD_7_KEY_SUPPROT									_OFF // 7���Ŀ���
#endif

#ifndef _KEY_IR_HUIXIONG_CROOSSOVER
#define _KEY_IR_HUIXIONG_CROOSSOVER							_OFF	//����ң�ذ���

#endif

#ifndef	_DEF_CT_JX 
#define _DEF_CT_JX											_OFF //����Ҫ���ɫ������
#endif

#ifndef _DEF_OSD_EDID_INFO
#define _DEF_OSD_EDID_INFO									_OFF	//OSD�˵���ʾEDID��Ϣ
#endif


#ifndef _DEF_STA_SIX_COLOR
#define _DEF_STA_SIX_COLOR									_OFF	//���Ͷ���ɫ
#endif

#ifndef _DEF_OPPOSITE_DCR
#define _DEF_OPPOSITE_DCR									_OFF	//����ģʽ֧��
#endif

#ifndef _DEF_COLORGAMUT_USER
#define _DEF_COLORGAMUT_USER								_OFF
#endif

#ifndef _DEF_COLORFUL
#define _DEF_COLORFUL										_OFF	//�龰ģʽ-����ģʽ
#endif

#ifndef _DEF_DP_OVERCLOCK
#define _DEF_DP_OVERCLOCK									_OFF	//DP��Ƶ
#endif


#ifndef _OSD_5_KEY_SUPPROT
#define _OSD_5_KEY_SUPPROT									_OFF // 5���Ŀ���
#endif

#ifndef _CUSTOM_TYPE
#define _CUSTOM_TYPE									_NONE_CUSTOMER// 5���Ŀ���
#endif

#ifndef _JX_OSD_TABLE_PORTUGUESE
#define _JX_OSD_TABLE_PORTUGUESE							_OFF	//������������
#endif

#ifndef _EDID_MESSAGE_SUPPROT
#define _EDID_MESSAGE_SUPPROT											_ON
#endif


#ifndef _ALIGN_SUPPROT
#define _ALIGN_SUPPROT											_ON//����ɫ���Ե�OSD ��־λ
#endif



#ifndef	_REMIND_ENERGY_EFFICIENCY_FUNCTION
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION					_OFF
#endif

#ifndef _TEST_FOR_FREESYNC
#define _TEST_FOR_FREESYNC         _OFF
#endif

#ifndef _DEF_OD
#if(_TEST_FOR_FREESYNC == _ON)
#define _DEF_OD										         _ON
#else
#define _DEF_OD										         _OFF
#endif
#endif

#ifndef _DEF_BACKLIGHT
#define _DEF_BACKLIGHT                                       80
#endif

#ifndef _DEF_CONTRAST
#define _DEF_CONTRAST                                        50
#endif

#ifndef _DEF_LANGUAGE
#define _DEF_LANGUAGE										 _CHINESE_S
#endif

#ifndef _DEF_COLORTEMP
#define _DEF_COLORTEMP										 _CT_6500
#endif
 
#ifndef _DEF_VOLUME
#define _DEF_VOLUME										     50
#endif

#ifndef _DEF_VOLUME_PWM
#define _DEF_VOLUME_PWM										 80
#endif


#ifndef _DEF_FREESYNC
#define _DEF_FREESYNC									     _OFF
#endif

#ifndef _DEF_HDR_MODE
#define _DEF_HDR_MODE									     _HDR10_MODE_OFF
#endif

#ifndef _DEF_GAMMA
#define _DEF_GAMMA											_GAMMA_OFF
#endif


#ifndef _DEF_CT_USER_OSD_R
#define _DEF_CT_USER_OSD_R									   	128
#endif

#ifndef _DEF_CT_USER_OSD_G
#define _DEF_CT_USER_OSD_G									   	128
#endif

#ifndef _DEF_CT_USER_OSD_B
#define _DEF_CT_USER_OSD_B									   	128
#endif


#ifndef _DEF_ASPECT
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_FULL
#endif





#ifndef _DEF_H_POS
#define _DEF_H_POS                                         50
#endif

#ifndef _DEF_V_POS
#define _DEF_V_POS                                         50
#endif

#ifndef _DEF_POWEROFF
#define _DEF_POWEROFF                                     	_AutoPowerOff_OFF//_AutoPowerOff_4
#endif

#ifndef _DEF_FACTORY_MODE
#define _DEF_FACTORY_MODE								     _ON
#endif

#ifndef _DEF_BURNING_MODE
#define _DEF_BURNING_MODE								     _ON
#endif

#ifndef _LOGO_TYPE
#define _LOGO_TYPE								    		 _NONE_LOGO
#endif





/*           ������ 				*/
#ifndef _DEF_BRIGHTNESS
#define _DEF_BRIGHTNESS                                      50
#endif

#ifndef _DEF_SHAPNESS
#define _DEF_SHAPNESS                                        2
#endif

#ifndef _DEF_ECO
#define _DEF_ECO                                             _COLOREFFECT_STANDARD
#endif

#ifndef _DEF_DCR
#define _DEF_DCR											_OFF
#endif

#ifndef _DEF_OSDROTATE
#define _DEF_OSDROTATE										_OSD_ROTATE_DEGREE_0
#endif

#ifndef _DEF_DISP_ROTATE
#define _DEF_DISP_ROTATE									_DISP_ROTATE_0
#endif

#ifndef _DEF_AUDIO_SOURCE
#define _DEF_AUDIO_SOURCE                 				    _DIGITAL_AUDIO
#endif

#ifndef _DEF_OSD_DOUBLE
#define _DEF_OSD_DOUBLE                 				    _OFF
#endif

#ifndef _DEF_OSD_LEDTYPE
#define _DEF_OSD_LEDTYPE                 				   _OSDLedType_ON
#endif

#ifndef _BURNIN_MSG_MENU_SUPPORT
#define _BURNIN_MSG_MENU_SUPPORT                 		    _ON
#endif

#ifndef _DEF_HOTKEY_LEFT
#define _DEF_HOTKEY_LEFT                 				    _MENU_FUN_HOTLEFT
#endif

#ifndef _DEF_HOTKEY_RIGHT
#define _DEF_HOTKEY_RIGHT                				    _MENU_FUN_HOTRIGHT
#endif


#ifndef _DEF_HOTKEY_UP
#define _DEF_HOTKEY_UP                 				        _MENU_FUN_BACKLIGHT
#endif

#ifndef _DEF_HOTKEY_DOWN
#define _DEF_HOTKEY_DOWN                				    _MENU_FUN_CONTRAST
#endif

#ifndef _DEF_FLICKER_FREE
#define _DEF_FLICKER_FREE									     _OFF
#endif

#ifndef _DEF_MPRT
#define _DEF_MPRT									   			 _OFF
#endif

#ifndef _OD_WEAK
#define _OD_WEAK									   			 0x18
#endif

#ifndef _OD_MID
#define _OD_MID									   				 0x30
#endif

#ifndef _OD_STRONG
#define _OD_STRONG									   			 0x40
#endif

//--------------------------------------------------
// Definitions of Langue
//--------------------------------------------------


#ifndef _ENGLISH_SUPPORT
#define _ENGLISH_SUPPORT										_ON
#endif

#ifndef _GERMAN_SUPPORT
#define _GERMAN_SUPPORT										_ON
#endif
#ifndef _SPANISH_SUPPORT
#define _SPANISH_SUPPORT										_ON
#endif
#ifndef _FRENCH_SUPPORT
#define _FRENCH_SUPPORT										_ON
#endif
#ifndef _ITALIAN_SUPPORT
#define _ITALIAN_SUPPORT										_ON
#endif
#ifndef _DUTCH_SUPPORT
#define _DUTCH_SUPPORT										_ON
#endif
#ifndef _PORTUGUESE_SUPPORT
#define _PORTUGUESE_SUPPORT										_ON
#endif
#ifndef _SVENSKA_SUPPORT
#define _SVENSKA_SUPPORT										_ON
#endif
#ifndef _TURKISH_SUPPORT
#define _TURKISH_SUPPORT										_ON
#endif
#ifndef _XILAYU_SUPPORT
#define _XILAYU_SUPPORT										_ON
#endif
#ifndef _MAGYAR_SUPPORT
#define _MAGYAR_SUPPORT										_ON
#endif
#ifndef _POLSKI_SUPPORT
#define _POLSKI_SUPPORT										_ON
#endif

//  Ĭ��  ǰ�� 12 �����Դ�  �������Ĺ� ��ѡ���ܹ�19��

#ifndef _CHINESE_S_SUPPORT
#define _CHINESE_S_SUPPORT										_ON//����
#endif


#ifndef _JAPANESE_SUPPORT
#define _JAPANESE_SUPPORT										_OFF  // ����
#endif

#ifndef _RUSSIAN_SUPPORT
#define _RUSSIAN_SUPPORT										_OFF  //����
#endif

#ifndef _KOREAN_SUPPORT
#define _KOREAN_SUPPORT											_OFF//����
#endif

#ifndef _FINNISH_SUPPORT
#define _FINNISH_SUPPORT										_OFF   //������
#endif

#ifndef _CZECH_SUPPORT
#define _CZECH_SUPPORT											_OFF    //�ݿ���
#endif

#ifndef _CHINESE_F_SUPPORT
#define _CHINESE_F_SUPPORT										_OFF  // ����
#endif

#ifndef _KAZAK_SUPPORT
#define _KAZAK_SUPPORT											_OFF	//�������� //�����һ��
#endif


//--------------------------------------------------
// Definitions of Backlight Range
//--------------------------------------------------
#ifndef _BACKLIGHT_MAX
	#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)
		#define _BACKLIGHT_MAX                              255
	#else
		#define _BACKLIGHT_MAX                              4095
	#endif
#endif

#ifndef _BACKLIGHT_MIN
#define _BACKLIGHT_MIN                          		    0
#endif

#ifndef _BACKLIGHT_DEF_PWM
#define _BACKLIGHT_DEF_PWM									 0x80
#endif

#ifndef _MPRT_PWM_MAX
#define _MPRT_PWM_MAX          0xff
#endif

#ifndef _MPRT_PWM_DEF
#define _MPRT_PWM_DEF          0xD0
#endif


#ifndef _MPRT_PWM_MIN
#define _MPRT_PWM_MIN          0x60
#endif

#ifndef _MPRT_LOW_PERCENT
#define _MPRT_LOW_PERCENT          80
#endif


#ifndef _MPRT_MID_PERCENT
#define _MPRT_MID_PERCENT          60
#endif

#ifndef _MPRT_HIGH_PERCENT
#define _MPRT_HIGH_PERCENT          40
#endif

/********************************For ECO MODE******************************************/
#ifndef _ECO_MOVIE_BACKLIGHT
#define _ECO_MOVIE_BACKLIGHT					100
#endif

#ifndef _ECO_GAME_BACKLIGHT
#define _ECO_GAME_BACKLIGHT						60
#endif

#ifndef _ECO_TEXT_BACKLIGHT
#define _ECO_TEXT_BACKLIGHT						50
#endif

#ifndef _ECO_MOVIE_CONTRAST
#define _ECO_MOVIE_CONTRAST						55
#endif

#ifndef _ECO_GAME_CONTRAST
#define _ECO_GAME_CONTRAST						50
#endif

#ifndef _ECO_TEXT_CONTRAST
#define _ECO_TEXT_CONTRAST						45
#endif


#ifndef _ECO_MOVIE_SHARPNESS
#define _ECO_MOVIE_SHARPNESS					2
#endif

#ifndef _ECO_GAME_SHARPNESS
#define _ECO_GAME_SHARPNESS						2
#endif

#define _ECO_MOVIE_BLACKLEVEL					50
#define _ECO_GAME_BLACKLEVEL					50
#define _ECO_TEXT_BLACKLEVEL					40


#if(_EOC_RTS_FPS_SUPPORT == _ON)
#define _ECO_FPS_BACKLIGHT						100
#define _ECO_RTS_BACKLIGHT						90

#define _ECO_FPS_CONTRAST						60
#define _ECO_RTS_CONTRAST						60

#define _ECO_FPS_BLACKLEVEL						60
#define _ECO_RTS_BLACKLEVEL						50

#endif




#define _ECO_ENERGY_SAVING_BACKLIGHT						20
#define _ECO_ENERGY_SAVING_CONTRAST						50
#define _ECO_ENERGY_SAVING_BLACKLEVEL						50


#ifndef _DEF_LIGHTMODE
#define _DEF_LIGHTMODE                                   LightMode_Breathe  //�����Ч��ʼ״̬
#endif


#ifndef _DEF_PreLIGHTMODE
#define _DEF_PreLIGHTMODE                                   LightMode_Breathe  //�����Ч��ʼ״̬
#endif

#ifndef _EDID_FHD165HZ
#define _EDID_FHD165HZ										_OFF	//M270 2.2  165��HBR2
#endif
	 
#ifndef _DEF_EDID_120HZ
#define _DEF_EDID_120HZ										_OFF
#endif
	 
#ifndef _PANEL_QHD90HZ
#define _PANEL_QHD90HZ										_OFF
#endif
	 
#ifndef _PANEL_MV270QHM_N41
#define _PANEL_MV270QHM_N41										_OFF
#endif

#ifndef _IR_VIRTUAL
#define _IR_VIRTUAL								_OFF
#endif

#ifndef _HDMI2_SUPPORT
#define _HDMI2_SUPPORT								_OFF
#endif

#ifndef _HDMI_24C02_SUPPORT
#define _HDMI_24C02_SUPPORT								_OFF
#endif
//���پ���
#ifndef _2822NE
#define _2822NE								_OFF
#endif

//���پ���
#ifndef _2822NJ
#define _2822NJ								_OFF
#endif
//���پ���
#ifndef _MD2869
#define _MD2869								_OFF
#endif
//���پ���
#ifndef _MD2769
#define _MD2769								_OFF
#endif

//���پ���
#ifndef _H2822U
#define _H2822U								_OFF
#endif

#ifndef _TJ_GAMMA
#define _TJ_GAMMA						  		_OFF  //GAMMA ������ OFFѡ��  1.8 2.0 2.2 2.4 2.6
#endif

#ifndef _AUTO_SearchSource
#define _AUTO_SearchSource						  		_OFF  //����AUTO ���ź��Զ�����һ������
#endif

#include"Logo_define.h"

#endif

