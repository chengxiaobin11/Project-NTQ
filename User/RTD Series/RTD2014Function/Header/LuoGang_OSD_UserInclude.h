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
// ID Code      : LuoGang_OSD_UserInclude.h No.0000      //IDO
// Update Note  : ��ض��嶼�� HK_OSD_UserInclude.h
//----------------------------------------------------------------------------------------------------
#if(Project_ID == ID_COMMON) 
#define _LOGO_TYPE											_NONE_LOGO

#define _MPRT_RATIO         						 30

#define _DEF_HOTKEY_LEFT									_HOT_KEY_LOS_TYPE1
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_BACKLIGHT
#define _BACKLIGHT_DEF_PWM									 0x80
#define _BACKLIGHT_MAX										 0xFF	
#define _BACKLIGHT_MIN										8

#define _DEF_LANGUAGE										 _ENGLISH


#define _DEF_P4_OSDSETTING_ITEM2      _MENU_FUN_MPRT
#elif(Project_ID == ID_TJZG_TMDTMD2822_HK2775E01_2P2H_UHD60HZ_20231217)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#if (_2822NE || _2822NB || _2822NJ)
#define _DEF_VOLUME										     100
#define _DEF_VOLUME_PWM										 100
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_ECO
#else
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
#define _OSD_7PAGE											1	//�˵�7ҳ
#endif
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT

#if _H2822U
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_TGDB//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#elif _2822NJ
#define _DEF_LANGUAGE										_JAPANESE
#define _LOGO_TYPE											_LOGO_XGAMING//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#elif _MD2869
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#else
#define _DEF_LANGUAGE										_ENGLISH
#define _LOGO_TYPE											_LOGO_XGAMING//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#endif

#if (_2822NE || _2822NB )
#define _BACKLIGHT_MAX										(0XB6)
#define _BACKLIGHT_DEF_PWM									(0X74)        
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                       65
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _ON // ��Ч����
#define _HDCP_KEY_WIRTE_FLAG										 _ON
#elif _H2822U
#define _BACKLIGHT_MAX										(0XB8)
#define _BACKLIGHT_DEF_PWM									(0XA4)        
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                       80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
#define _HDCP_KEY_WIRTE_FLAG										 _OFF
#elif _MD2869
#define _BACKLIGHT_MAX										(0XB8)
#define _BACKLIGHT_DEF_PWM									(0XA4)        
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                       80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
#define _HDCP_KEY_WIRTE_FLAG										 _OFF
#else
#define _BACKLIGHT_MAX										(0XB8)
#define _BACKLIGHT_DEF_PWM									(0XA4)        
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                       80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
#define _HDCP_KEY_WIRTE_FLAG										 _ON
#endif
    
    
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
    
#define _DEF_COLORTEMP                                    	_CT_6500
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
     
#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										_ON
#define _GERMAN_SUPPORT										_OFF
#define _CHINESE_S_SUPPORT										_ON
#define _ITALIAN_SUPPORT										_OFF
#define _JAPANESE_SUPPORT										_ON
#define _RUSSIAN_SUPPORT										_ON
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_ON
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									_OFF
    
#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_FUN_LOWBLUE
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_OD
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_FUN_DCC   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_FUN_BRIGHTNESS
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_NULL
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
#define _DEF_P4_AUDIO_ITEM0      _MENU_FUN_AUDOIMUTE 
#define _DEF_P4_AUDIO_ITEM1       _MENU_FUN_AUDOIVOLUME
#define _DEF_P4_AUDIO_ITEM2      _MENU_NULL   
#define _DEF_P4_AUDIO_ITEM3      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM4      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM5      _MENU_NULL
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_LANGUAGE
#define _DEF_P5_RESET_ITEM1     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM2    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM3    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM4     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM5      	 _MENU_FUN_OSD_RORATE

#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_OD
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM3      	 _MENU_NULL
#define _DEF_P6_MISC_ITEM4      	 _MENU_NULL
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
#elif(Project_ID == ID_TJZG_HK2775E05_M270KCAD8B_EDP4LANHBR2_MD2769_QHD180HZ_20240313)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_PROGRESS_BAR_3PAGE                             _ON //
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#if _DEF_PROJECT_TEST
#define _BACKLIGHT_MAX										(0XFF)
#define _BACKLIGHT_DEF_PWM									(0XC2)        
#elif ARZOPA
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                  _OFF//  _ON // ��Ч���� 20240518
#define _DEF_LANGUAGE										_ENGLISH
    //#define _OSD_5_KEY_SUPPROT                                    _ON // 5���Ŀ���
#define _LOGO_TYPE											_LOGO_ARZOPA_4BIT//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0XD4)
#define _BACKLIGHT_DEF_PWM									(0XC2)        
#elif ARZOPB
#define _DEF_LANGUAGE										_CHINESE_S
    //#define _OSD_5_KEY_SUPPROT                                    _ON // 5���Ŀ���
#define _LOGO_TYPE											_LOGO_ARZOPA_4BIT//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0XE3)
#define _BACKLIGHT_DEF_PWM									(0XD7)        
#elif   _SN270ES01_1 
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                  _OFF//  _ON // ��Ч���� 20240518
#define _DEF_LANGUAGE										_CHINESE_S
    //#define _OSD_5_KEY_SUPPROT                                    _ON // 5���Ŀ���
#define _LOGO_TYPE											_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0XC9)
#define _BACKLIGHT_DEF_PWM									(0XC0)        
#else
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_ARZOPA//_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0XC9)
#define _BACKLIGHT_DEF_PWM									(0XB3)        
#endif
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                      80
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_7500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto


#define _GERMAN_SUPPORT										_ON//_OFF   20240712
#define _ITALIAN_SUPPORT										_ON//_OFF  20240712
     
#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										_ON
#define _CHINESE_S_SUPPORT										_ON
#define _JAPANESE_SUPPORT										_ON
#define _RUSSIAN_SUPPORT										_ON
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_ON
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									_OFF
    
#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_FUN_LOWBLUE
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_OD
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_FUN_DCC   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_FUN_BRIGHTNESS
#if ARZOPA||ARZOPB||_SN270ES01_1
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_FUN_MPRT
#else
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_NULL
#endif
    
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
#define _DEF_P4_AUDIO_ITEM0      _MENU_FUN_AUDOIMUTE 
#define _DEF_P4_AUDIO_ITEM1       _MENU_FUN_AUDOIVOLUME
#define _DEF_P4_AUDIO_ITEM2      _MENU_NULL   
#define _DEF_P4_AUDIO_ITEM3      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM4      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM5      _MENU_NULL
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_LANGUAGE
#define _DEF_P5_RESET_ITEM1     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM2    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM3    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM4     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM5      	 _MENU_FUN_OSD_RORATE

#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_OD
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#if ARZOPA||_SN270ES01_1
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_CROSS
#define _DEF_P6_MISC_ITEM3      	  _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM4      	 _MENU_NULL
#else
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_LED
#define _DEF_P6_MISC_ITEM3      	  _MENU_FUN_CROSS
#define _DEF_P6_MISC_ITEM4      	 _MENU_FUN_RESET
#endif
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
#elif(Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_F2761QK_QHD180HZ_20240416)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_TGDB//_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0XC9)
#define _BACKLIGHT_DEF_PWM									(0XB3)        
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                      80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_7500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
     
#elif(Project_ID == ID_TJZG_HK2775E05_SN245ES01_2_EDP4LANHBR2_MD2569_QHD180HZ_20240528)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_PROGRESS_BAR_3PAGE                             _ON //
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_TGDA//
#define _BACKLIGHT_MAX										(0XC9)
#define _BACKLIGHT_DEF_PWM									(0XB3)        
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                      80
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_7500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
     
#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										_ON
#define _GERMAN_SUPPORT										_OFF
#define _CHINESE_S_SUPPORT										_ON
#define _ITALIAN_SUPPORT										_OFF
#define _JAPANESE_SUPPORT										_ON
#define _RUSSIAN_SUPPORT										_ON
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_ON
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									_OFF
    
#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_FUN_LOWBLUE
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_OD
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_FUN_DCC   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_FUN_BRIGHTNESS
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_FUN_MPRT
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
#define _DEF_P4_AUDIO_ITEM0      _MENU_FUN_AUDOIMUTE 
#define _DEF_P4_AUDIO_ITEM1       _MENU_FUN_AUDOIVOLUME
#define _DEF_P4_AUDIO_ITEM2      _MENU_NULL   
#define _DEF_P4_AUDIO_ITEM3      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM4      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM5      _MENU_NULL
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_LANGUAGE
#define _DEF_P5_RESET_ITEM1     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM2    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM3    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM4     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM5      	 _MENU_FUN_OSD_RORATE
    

#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_OD
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_CROSS
#define _DEF_P6_MISC_ITEM3      	  _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM4      	 _MENU_NULL
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
#elif(Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_F2761QK_QHD180HZ_20240416)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_TGDB//_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0XC9)
#define _BACKLIGHT_DEF_PWM									(0XB3)        
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                      80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_7500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto

#elif(Project_ID == TEXTF0_ID_KAITENG_2795E04_4LANEHBR)
#define _LOGO_TYPE												_NONE_LOGO//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_NONE_LOGO//_LOGO_CHIGO_ZHIGAO_QHD

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto


#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1
#define _BACKLIGHT_MAX 										 	(0xFF-0x63)//480
#define _BACKLIGHT_DEF_PWM 										(0xFF-0x74)//420

#define _BACKLIGHT_MIN											(0XFF-0xEF)
#define _EOC_RTS_FPS_SUPPORT					     	    		_OFF //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_6500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED
#elif(Project_ID == ID_KAITENG_HK2795E04_FHD300HZ_VB1)
#define _LOGO_TYPE												0
//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_NONE//_LOGO_CHIGO_ZHIGAO_QHD
#define _DEF_ASPECT												_OSD_ASPECT_RATIO_16_BY_9

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        	_OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1

#define _OSD_CROSS_SMALL										_ON
#define _DEF_GAMMA												_GAMMA_24
#if(_CAIXIAOLI)
#define _DEF_H_POS                                         		96
#define _DEF_V_POS                                         		8
#endif

/*
#define _BACKLIGHT_MAX 										 	0x91//440
#define _BACKLIGHT_DEF_PWM 										0x84//400

#define _BACKLIGHT_MAX 										 	0x84//400
#define _BACKLIGHT_DEF_PWM 										0x76//360

#define _BACKLIGHT_MAX 										 	0x62//300
#define _BACKLIGHT_DEF_PWM 										0x5C//280
*/
#define _BACKLIGHT_MAX 										 	0x6F//340
#define _BACKLIGHT_DEF_PWM 										0x5C//280


#define _BACKLIGHT_MIN											0X10

#define _EOC_RTS_FPS_SUPPORT					     	    	_ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE									_ON //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF										_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO									_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH										_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_6500//_CT_USER//_CT_6500


#define _DEF_P5_RESET_ITEM3    	  	  							_MENU_FUN_LED


#elif(Project_ID == ID_KAIXIA_HK2795E04_SG2451B01_2_8LAN_VBY1_FHD280HZ_8BIT_20240103)
#define _LOGO_TYPE												0//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_NONE//_LOGO_CHIGO_ZHIGAO_QHD
#define _DEF_ASPECT												_OSD_ASPECT_RATIO_16_BY_9

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1

#define _OSD_CROSS_SMALL										_ON
#define _DEF_GAMMA												_GAMMA_22


#define _BACKLIGHT_MAX 										 	(0xFF-0xA8)	//360mA
#define _BACKLIGHT_DEF_PWM 										(0xFF-0xAF)	//280mA --- 600MA

#define _BACKLIGHT_MIN											0X10

//#define _EOC_RTS_FPS_SUPPORT


//69-240      83-300

//#define _BACKLIGHT_MAX 										 	0x83//
//#define _BACKLIGHT_DEF_PWM 										0x69//
//#define _BACKLIGHT_MIN											0X10//(0xFF-0xEF)

#define _EOC_RTS_FPS_SUPPORT					     	    		_ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_ON //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_7500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED


#elif(Project_ID == TEXTF1_ID_KAITENG_XIAOLI_2795E04_4LANEHBR2_1K280)
#define _LOGO_TYPE												0//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_NONE//_LOGO_CHIGO_ZHIGAO_QHD
#define _DEF_ASPECT												_OSD_ASPECT_RATIO_16_BY_9

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1

#define _OSD_CROSS_SMALL										_ON
#define _DEF_GAMMA												_GAMMA_22


#define _BACKLIGHT_MAX 										 	0XA8//400
#define _BACKLIGHT_DEF_PWM 										0X95//360
#define _BACKLIGHT_MIN											0X10

//#define _EOC_RTS_FPS_SUPPORT


//69-240      83-300

//#define _BACKLIGHT_MAX 										 	0x83//
//#define _BACKLIGHT_DEF_PWM 										0x69//
//#define _BACKLIGHT_MIN											0X10//(0xFF-0xEF)

#define _EOC_RTS_FPS_SUPPORT					     	    		_ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_ON //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_6500
#if(_CAIXIAOLI)
#define _DEF_H_POS                                         96
#define _DEF_V_POS                                         8
#endif
#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED

#elif(Project_ID == TEXTF2_ID_SONGREN_2795E04_4LANEHBR2_2K185_D8B)
#define _LOGO_TYPE												0//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_NONE//_LOGO_CHIGO_ZHIGAO_QHD

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1

#define _OSD_CROSS_SMALL										_ON


#define _BACKLIGHT_MAX 										 	(0XFF-0x80)//480
#define _BACKLIGHT_DEF_PWM 										(0XFF-0xA0)//400
#define _BACKLIGHT_MIN											(0XFF-0xEF)



//69-240      83-300

//#define _BACKLIGHT_MAX 										 	0x83//
//#define _BACKLIGHT_DEF_PWM 										0x69//
//#define _BACKLIGHT_MIN											0X10//(0xFF-0xEF)

#define _EOC_RTS_FPS_SUPPORT					     	    		_OFF //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_7500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED
#elif(Project_ID == _ID_SANSE_2795QR_2K180_NF0_)
#define _LOGO_TYPE												0//_LOGO_SANSE//_LOGO_UG//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_NONE_LOGO//_LOGO_CHIGO_ZHIGAO_QHD
#define _FW_VERSION                         					_F__,_W__,__,_COLON__,__,_V__,_0__,_0__,_1__,__,_2__,_0__,_2__,_5__,_0__,_8__,_1__,_1__
#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        	_OFF//�ź��л��Ƿ��auto
#define _DEF_ASPECT												_OSD_ASPECT_RATIO_16_BY_9

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1
#define _OSD_CROSS_SMALL										_OFF



//#define _BACKLIGHT_MIN											(0XFF-0xEF)



//69-240      83-300
/*
#define _BACKLIGHT_MAX 										 	(0XFF-0x70)//540
#define _BACKLIGHT_DEF_PWM 										(0XFF-0x80)//480


#define _BACKLIGHT_MAX 										 	(0XFF-0xA6)//280
#define _BACKLIGHT_DEF_PWM 										(0XFF-0xA0)//260

#define _BACKLIGHT_MAX 										 	(0XFF-0xA0)//260 
#define _BACKLIGHT_DEF_PWM 										(0XFF-0xA6)//280

#define _BACKLIGHT_MAX 										 	0XB6//420
#define _BACKLIGHT_DEF_PWM 										0XA6//380


*/

#define _BACKLIGHT_MAX 										 	0XB6//420
#define _BACKLIGHT_DEF_PWM 										0XA6//380


#define _BACKLIGHT_MIN											0X10

#define _EOC_RTS_FPS_SUPPORT					     	    _ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_ON //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _CT_DEFAULT    					 				 	_CT_7500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED

#elif(Project_ID == _ID_KAITENG_2795QR_QHD180HZ_EDP)
#define _LOGO_TYPE												0//_LOGO_SANSE//_LOGO_UG//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_NONE_LOGO//_LOGO_CHIGO_ZHIGAO_QHD
#define _FW_VERSION                         					_F__,_W__,__,_COLON__,__,_V__,_0__,_0__,_1__,__,_2__,_0__,_2__,_5__,_0__,_8__,_1__,_1__
#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        	_OFF//�ź��л��Ƿ��auto
#define _DEF_ASPECT												_OSD_ASPECT_RATIO_16_BY_9

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1
#define _OSD_CROSS_SMALL										_OFF



//#define _BACKLIGHT_MIN											(0XFF-0xEF)



//69-240      83-300
/*
#define _BACKLIGHT_MAX 										 	(0XFF-0x70)//540
#define _BACKLIGHT_DEF_PWM 										(0XFF-0x80)//480


#define _BACKLIGHT_MAX 										 	(0XFF-0xA6)//280
#define _BACKLIGHT_DEF_PWM 										(0XFF-0xA0)//260

#define _BACKLIGHT_MAX 										 	(0XFF-0xA0)//260 
#define _BACKLIGHT_DEF_PWM 										(0XFF-0xA6)//280

#define _BACKLIGHT_MAX 										 	0XB6//420
#define _BACKLIGHT_DEF_PWM 										0XA6//380


*/

#define _BACKLIGHT_MAX 										 	0XB6//420
#define _BACKLIGHT_DEF_PWM 										0XA6//380


#define _BACKLIGHT_MIN											0X10

#define _EOC_RTS_FPS_SUPPORT					     	    _ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_ON //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _CT_DEFAULT    					 				 	_CT_7500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED

#elif(Project_ID == TEXTF_ID_KAITENG_2795E04_8LANEHBR2)
#define _LOGO_TYPE												_LOGO_SANSE//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_NONE//_LOGO_CHIGO_ZHIGAO_QHD

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1

#define _OSD_CROSS_SMALL										_ON


//#define _BACKLIGHT_MAX 										 	(0XFF-0x70)//540
//#define _BACKLIGHT_DEF_PWM 										(0XFF-0x80)//480
//#define _BACKLIGHT_MIN											(0XFF-0xEF)

//#define _BACKLIGHT_MAX 										 	0xFA//600--600ma
//#define _BACKLIGHT_DEF_PWM 										0xF1//580--600ma



//69-240      83-300

//#define _BACKLIGHT_MAX 										 	0xC8//480--600ma
//#define _BACKLIGHT_DEF_PWM 										0xBE//450--600ma

//#define _BACKLIGHT_MAX 										 	0xa1//380--600ma
//#define _BACKLIGHT_DEF_PWM 										0x99//360--600ma


//#define _BACKLIGHT_MAX 										 	0x71//260
//#define _BACKLIGHT_DEF_PWM 										0x68//240

#define _BACKLIGHT_MAX 										 		0x99//360
#define _BACKLIGHT_DEF_PWM 											0x90//

#define _BACKLIGHT_MIN											0X10//(0xFF-0xEF)

#define _EOC_RTS_FPS_SUPPORT					     	    		_OFF //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_7500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED


#elif(Project_ID == ID_KAITENG_HK2795E01_QHD180HZ_EDP)
#define _LOGO_TYPE												_LOGO_SNAV
//_LOGO_SNAV//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_CHIGO_ZHIGAO_QHD

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        	_OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_CONTRAST
#define _DEF_HOTKEY_RIGHT                				    	_MENU_FUN_BACKLIGHT

#define _CT_DEFAULT					 				 			_CT_7500
#define _OSD_CROSS_SMALL										_ON

/*
0xDA = 600 ma
0xDF = 610 ma
0xE4 = 620 ma
0xEA = 630 ma
0xEF = 640 ma
0xF4 = 650 ma
0xFA = 660 ma


#define _BACKLIGHT_MAX 										 	0xDA//600
#define _BACKLIGHT_DEF_PWM 										0xD0//580


*/

#define _BACKLIGHT_MAX 										 	0xA2//(0XFF-0xA2)//370
#define _BACKLIGHT_DEF_PWM 										0x9A//(0XFF-0x9A)//350


#define _BACKLIGHT_MIN											0X10//(0xFF-0xEF)//(0xFF-0xEF)

#define _EOC_RTS_FPS_SUPPORT					     	    		_ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED

#elif(Project_ID == ID_WMX_ME270QHB_NF5_2K180)
#define _LOGO_TYPE												_LOGO_WMX//_LOGO_SANSE//_LOGO_SSZP_HUO//_LOGO_DIAMOND//_LOGO_NONE//_LOGO_CHIGO_ZHIGAO_QHD

#define _DEF_BACKLIGHT                                       	80
#define _DEF_LANGUAGE										 	_CHINESE_S
#define _SOURCE_AUTO_ON								        	_OFF//�ź��л��Ƿ��auto

//#define  _DEF_H_POS 100
//#define  _DEF_V_POS 0

#define _DEF_HOTKEY_LEFT                 				    	_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT                				    	_HOT_KEY_LOS_TYPE1

#define _OSD_CROSS_SMALL										_ON


//#define _BACKLIGHT_MAX 										 	(0XFF-0x70)//540
//#define _BACKLIGHT_DEF_PWM 										(0XFF-0x80)//480
//#define _BACKLIGHT_MIN											(0XFF-0xEF)



//69-240      83-300

#define _BACKLIGHT_MAX 										 	0xA2//(0XFF-0xA2)//370
#define _BACKLIGHT_DEF_PWM 										0x9A//(0XFF-0x9A)//350




//#define _BACKLIGHT_MAX 										 	0x83//300
//#define _BACKLIGHT_DEF_PWM 										0x69//
#define _BACKLIGHT_MIN											0x10//(0xFF-0xEF)//(0xFF-0xEF)

#define _EOC_RTS_FPS_SUPPORT					     	    		_ON //ECOģʽ�Ƿ�� RTS��FPS
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_RESET_SOURCE_AUTO								_ON //���ú��źŻ�ԭ���Զ�
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ

#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x22
#define _OD_STRONG									   			 0x3A

#define _DEF_COLORTEMP    					 				 	_CT_7500


#define _DEF_P5_RESET_ITEM3    	  	  						_MENU_FUN_LED


#elif(Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_20240426)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_TGDA//_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0X94)
#define _BACKLIGHT_DEF_PWM									(0X8C)        
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                      80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
#define _DEF_PROGRESS_BAR_3PAGE                             _ON //
    
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_6500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
    
#define _CHINESE_S_SUPPORT									_ON//����
#define _JAPANESE_SUPPORT										_ON  // ����
#define _KOREAN_SUPPORT											_ON//����
#define _CHINESE_F_SUPPORT										_ON  // ����
#define _RUSSIAN_SUPPORT										_ON  //����
    
#define _GERMAN_SUPPORT										_OFF
#define _ITALIAN_SUPPORT										_OFF
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT									_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
    
#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_FUN_LOWBLUE
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_OD
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_FUN_DCC   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_FUN_BRIGHTNESS
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_NULL
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
#define _DEF_P4_AUDIO_ITEM0      _MENU_FUN_AUDOIMUTE 
#define _DEF_P4_AUDIO_ITEM1       _MENU_FUN_AUDOIVOLUME
#define _DEF_P4_AUDIO_ITEM2      _MENU_NULL   
#define _DEF_P4_AUDIO_ITEM3      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM4      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM5      _MENU_NULL
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_LANGUAGE
#define _DEF_P5_RESET_ITEM1     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM2    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM3    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM4     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM5      	 _MENU_FUN_OSD_RORATE
    
#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_OD
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_MPRT
#define _DEF_P6_MISC_ITEM3      	  _MENU_FUN_CROSS
#define _DEF_P6_MISC_ITEM4      	 _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
#elif(Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_G27L61QK_20240509)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_GENLOVE//_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
#define _BACKLIGHT_MAX										(0X94)
#define _BACKLIGHT_DEF_PWM									(0X8C)        
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                      80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
#define _DEF_PROGRESS_BAR_3PAGE                             _ON //
    
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_6500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
    
#define _CHINESE_S_SUPPORT									_ON//����
#define _JAPANESE_SUPPORT										_ON  // ����
#define _KOREAN_SUPPORT											_ON//����
#define _CHINESE_F_SUPPORT										_ON  // ����
#define _RUSSIAN_SUPPORT										_ON  //����
    
#define _GERMAN_SUPPORT										_OFF
#define _ITALIAN_SUPPORT										_OFF
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT									_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
    
#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_FUN_LOWBLUE
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_OD
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_FUN_DCC   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_FUN_BRIGHTNESS
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_NULL
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
#define _DEF_P4_AUDIO_ITEM0      _MENU_FUN_AUDOIMUTE 
#define _DEF_P4_AUDIO_ITEM1       _MENU_FUN_AUDOIVOLUME
#define _DEF_P4_AUDIO_ITEM2      _MENU_NULL   
#define _DEF_P4_AUDIO_ITEM3      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM4      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM5      _MENU_NULL
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_LANGUAGE
#define _DEF_P5_RESET_ITEM1     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM2    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM3    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM4     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM5      	 _MENU_FUN_OSD_RORATE
    

#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_OD
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_MPRT
#define _DEF_P6_MISC_ITEM3      	  _MENU_FUN_CROSS
#define _DEF_P6_MISC_ITEM4      	 _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
    
#elif(Project_ID == ID_TJZG_HK2775E01_SG2451B014_VBY8LANHBR2_FHD240HZ_20240330)
#define _TJ_GAMMA                                           _ON
#define _AUTO_SearchSource                                  _ON
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _OSD_5_KEY_SUPPROT									_ON // 5���Ŀ���
    
    
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
#define _DEF_LANGUAGE										_CHINESE_S
#define _LOGO_TYPE											_LOGO_TGDA//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
    
#define _BACKLIGHT_MAX										(0X68)
#define _BACKLIGHT_DEF_PWM									(0X61)        
#define _BACKLIGHT_MIN										0X15
#define _DEF_BACKLIGHT                                      80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _CT_DEFAULT											_CT_6500
    
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
     
#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										_ON
#define _GERMAN_SUPPORT										_OFF
#define _CHINESE_S_SUPPORT										_ON
#define _ITALIAN_SUPPORT										_OFF
#define _JAPANESE_SUPPORT										_ON
#define _RUSSIAN_SUPPORT										_ON
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_ON
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									_OFF
    
#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    //_MPRT_RATIO
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_FUN_LOWBLUE
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_OD
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_FUN_DCC   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_FUN_BRIGHTNESS
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_NULL
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
#define _DEF_P4_AUDIO_ITEM0      _MENU_FUN_AUDOIMUTE 
#define _DEF_P4_AUDIO_ITEM1       _MENU_FUN_AUDOIVOLUME
#define _DEF_P4_AUDIO_ITEM2      _MENU_NULL   
#define _DEF_P4_AUDIO_ITEM3      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM4      _MENU_NULL
#define _DEF_P4_AUDIO_ITEM5      _MENU_NULL
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_LANGUAGE
#define _DEF_P5_RESET_ITEM1     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM2    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM3    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM4     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM5      	 _MENU_FUN_OSD_RORATE

#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_OD
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_MPRT
#define _DEF_P6_MISC_ITEM3      	  _MENU_FUN_CROSS
#define _DEF_P6_MISC_ITEM4      	 _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
    
#elif(Project_ID == ID_TEST_VBY1_HK2775E01_2P2H_UHD60HZ_20240102)
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
#define _DEF_LANGUAGE										_ENGLISH
#define _LOGO_TYPE											_NONE_LOGO//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
    
#define _BACKLIGHT_MAX										(0XB8)
#define _BACKLIGHT_DEF_PWM									(0XA4)        
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                       80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
    
#define _DEF_COLORTEMP                                    	_CT_6500
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
     
#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										_ON
#define _GERMAN_SUPPORT										_OFF
#define _CHINESE_S_SUPPORT										_ON
#define _ITALIAN_SUPPORT										_OFF
#define _JAPANESE_SUPPORT										_ON
#define _RUSSIAN_SUPPORT										_ON
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_ON
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									_OFF
#elif((Project_ID == ID_NTQ_CO43AJ_HK2775E01_1P1H_P430QVR010_C10_UHD60HZ) || (Project_ID == ID_NTQ_CO49AJL_HK2775E01_1P1H_P490QAR010_UHD60HZ)||(Project_ID == ID_NTQ_CO55AJL_HK2775E01_1P1H_P550QVR010_UHD60HZ)||(Project_ID == ID_NTQ_CO32AL_HK2775E01_1P1H_MV315QUM_N70_UHD60HZ)\
||(Project_ID == ID_NTQ_CO27AL_HK2775E01_1P1H_MV270QUM_N10_UHD60HZ))
#define _DEF_CONTRAST                                           50
#define _DEF_VOLUME										        50
#define _DEF_VOLUME_PWM										    80
        
#define _DEF_ASPECT											    _OSD_ASPECT_RATIO_16_BY_9
    
#define _DEF_HOTKEY_LEFT									    _MENU_FUN_CONTRAST 
#define _DEF_HOTKEY_RIGHT									    _MENU_FUN_BACKLIGHT
#define _DEF_LANGUAGE										    _ENGLISH
#define _LOGO_TYPE											    _NONE_LOGO
    
#define _BACKLIGHT_MAX										    0xFFF
#define _BACKLIGHT_DEF_PWM									    0x800
#define _BACKLIGHT_MIN										    0x000
#define _DEF_BACKLIGHT                                          50
#define _ADJ_BACKLIGHT_BY_TABLE								    _ON
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                      _OFF
#define _OSD_7PAGE											    _OFF
#define _EN_AUDIO_PAGE										    _OFF
#define _DEF_OSD_RGV_PAGE4									    _ON
#define _EOC_RTS_FPS_SUPPORT								    _ON
#define _DEF_OSD_EDID_INFO									    _ON
    
#define _DEF_GAMMA											    _GAMMA_22
#define _OD_WEAK_MID_HIGH									    _ON
    
#define _DEF_COLORTEMP                                    	    _CT_6500
#define _WCH_MESSAGE_ADDR									    _ON

#define _SOURCE_AUTO_ON								            _OFF

#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										    _ON
#define _GERMAN_SUPPORT										    _ON
#define _CHINESE_S_SUPPORT										_ON
#define _ITALIAN_SUPPORT										_ON
#define _JAPANESE_SUPPORT										_OFF
#define _RUSSIAN_SUPPORT										_OFF
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_OFF
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										    _OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										    _OFF
#define _MAGYAR_SUPPORT										    _OFF
#define _POLSKI_SUPPORT										    _OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									            _OFF

#define _DEF_P1_PICTURE_ITEM0      _MENU_FUN_BACKLIGHT
#define _DEF_P1_PICTURE_ITEM1      _MENU_FUN_CONTRAST
#define _DEF_P1_PICTURE_ITEM2      _MENU_FUN_DCR 
#define _DEF_P1_PICTURE_ITEM3      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM4      _MENU_NULL
#define _DEF_P1_PICTURE_ITEM5      _MENU_NULL
    
    
#define _DEF_P2_DISPLAY_ITEM0      _MENU_FUN_GAMMA
#define _DEF_P2_DISPLAY_ITEM1      _MENU_FUN_ECO
#define _DEF_P2_DISPLAY_ITEM2      _MENU_FUN_COLORTEMP
#define _DEF_P2_DISPLAY_ITEM3      _MENU_FUN_HUE
#define _DEF_P2_DISPLAY_ITEM4      _MENU_FUN_SATURATION
#define _DEF_P2_DISPLAY_ITEM5      _MENU_NULL
    
    
#define _DEF_P3_COLORTEMP_ITEM0  	_MENU_FUN_SHARPNESS
#define _DEF_P3_COLORTEMP_ITEM1   	_MENU_FUN_BRIGHTNESS
#define _DEF_P3_COLORTEMP_ITEM2    _MENU_NULL   
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_NULL
#define _DEF_P3_COLORTEMP_ITEM4   	_MENU_NULL
#define _DEF_P3_COLORTEMP_ITEM5  	_MENU_NULL
    
#define _DEF_P4_OSDSETTING_ITEM0    _MENU_FUN_ASPECT
#define _DEF_P4_OSDSETTING_ITEM1   	_MENU_NULL 
#define _DEF_P4_OSDSETTING_ITEM2    _MENU_NULL   
#define _DEF_P4_OSDSETTING_ITEM3    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM4    _MENU_NULL
#define _DEF_P4_OSDSETTING_ITEM5    _MENU_NULL
    
    
#define _DEF_P5_RESET_ITEM0     	 _MENU_FUN_OSD_HPOSITON
#define _DEF_P5_RESET_ITEM1    	 	 _MENU_FUN_OSD_VPOSITON 
#define _DEF_P5_RESET_ITEM2    	  	 _MENU_FUN_OSD_TRANS
#define _DEF_P5_RESET_ITEM3     	 _MENU_FUN_OSD_TIME
#define _DEF_P5_RESET_ITEM4      	 _MENU_FUN_OSD_RORATE
#define _DEF_P5_RESET_ITEM5     	 _MENU_FUN_SAVING_MODE
    
#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_FREESYNC
#else
#define _DEF_P6_MISC_ITEM0      	    _MENU_FUN_LANGUAGE
#endif
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_OD
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM3      	  _MENU_NULL
#define _DEF_P6_MISC_ITEM4      	 _MENU_NULL
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL



#elif(Project_ID == ID_DATONG_HK2795E01_MV270QUM_N50_EDP4LANHBR2_UHD60HZ_20240511)
#define _DEF_CONTRAST                                        50
#define _DEF_VOLUME										     50
#define _DEF_VOLUME_PWM										 80
        
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
#define _DEF_LANGUAGE										_JAPANESE
#define _LOGO_TYPE											_LOGO_ASTEX//_LOGO_XGAMING// _LOGO_XGAMING//_LOGO_BOETEC
    
    
#if _MV270QUM_N31
#define _BACKLIGHT_MAX										(0X68)
#define _BACKLIGHT_DEF_PWM									(0X58)  
#elif _MV270FHM_NF1
#define _BACKLIGHT_MAX										(0XBC)
#define _BACKLIGHT_DEF_PWM									(0XA0)  
#elif _MV270QHM_NF2
#define _BACKLIGHT_MAX										(0XA8)
#define _BACKLIGHT_DEF_PWM									(0X81)   
#else
#define _BACKLIGHT_MAX										(0XB8)
#define _BACKLIGHT_DEF_PWM									(0XA4)   
#endif
    
    
#define _BACKLIGHT_MIN										0
#define _DEF_BACKLIGHT                                       80
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION                    _OFF // ��Ч����
    //#define _HDCP_KEY_WIRTE_FLAG                                       _ON
    
    
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_OSD_RGV_PAGE4									_ON	//������ 4���˵�
#define _EOC_RTS_FPS_SUPPORT								_ON //�龰ģʽ����RTS��FPS
#define _DEF_OSD_EDID_INFO									_ON	//OSD�˵���ʾEDID��Ϣ
    
#define _DEF_GAMMA											_GAMMA_22
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
    
#define _DEF_COLORTEMP                                    	_CT_6500
#define _WCH_MESSAGE_ADDR									_ON	//��ʺ絯��λ��
    
#define _SOURCE_AUTO_ON								        _OFF//�ź��л��Ƿ��auto
     
#define _ENGLISH_SUPPORT										_ON
#define _FRENCH_SUPPORT										_ON
#define _GERMAN_SUPPORT										_OFF
#define _CHINESE_S_SUPPORT										_ON
#define _ITALIAN_SUPPORT										_OFF
#define _JAPANESE_SUPPORT										_ON
#define _RUSSIAN_SUPPORT										_ON
#define _KOREAN_SUPPORT											_ON
#define _CHINESE_F_SUPPORT										_ON
    
#define _SPANISH_SUPPORT										_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT										_OFF
#define _SVENSKA_SUPPORT										_OFF
#define _TURKISH_SUPPORT										_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT										_OFF
#define _CZECH_SUPPORT											_OFF
#define _LANG_19									_OFF

#elif(Project_ID == ID_HK2556E02_M270KCJ_L5B_QHD75HZ_LVDS_20240415)
#define _LOGO_TYPE											_LOGO_WMX
#define _DEF_BACKLIGHT                               		90
#define _DEF_HOTKEY_LEFT									_MENU_FUN_ECO
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME

#define _BACKLIGHT_MAX										0xb0
#define _BACKLIGHT_DEF_PWM									0xa0
#define _BACKLIGHT_MIN										12

#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _DCR_PANEL_ON_OFF									_ON	//DCR�򿪣��ڳ��Ƿ�ر���
#define _DEF_ECO_SET										_ON	//�ͻ�Ҫ���ECOģʽ���趨ֵ
#define _EOC_RTS_FPS_SUPPORT					     	    _ON //ECOģʽ�Ƿ�� RTS��FPS
#define _DEF_PROGRESS_BAR_NEW								_ON	//��������ECO����
#define _DEF_OSD_NOSIGNAL_SOURCE							_ON //���ź�ʱ�����ź��л�
#define _DEF_SCREEN_SWITCHING								_ON	//�л�����������
//#define _DEF_DDCCI											_ON

#define _DEF_LANGUAGE										_CHINESE_S// _ENGLISH//_CHINESE_S



#define _OD_WEAK									   			 0x14
#define _OD_MID									   				 0x23
#define _OD_STRONG									   			 0x3A

#define _ECO_MOVIE_BACKLIGHT					60
#define _ECO_GAME_BACKLIGHT						80
#define _ECO_TEXT_BACKLIGHT						10
#define _DEF_COLORTEMP    					 			    _CT_6500

#define _ECO_MOVIE_CONTRAST						56
#define _ECO_GAME_CONTRAST						62

#define _ECO_MOVIE_SHARPNESS					3
#define _ECO_GAME_SHARPNESS						4

#define _DEF_P2_DISPLAY_ITEM0		_MENU_FUN_ASPECT
#define _DEF_P2_DISPLAY_ITEM1		_MENU_NULL
#define _DEF_P2_DISPLAY_ITEM2		_MENU_NULL
#define _DEF_P2_DISPLAY_ITEM3		_MENU_NULL
#define _DEF_P2_DISPLAY_ITEM4		_MENU_NULL
#define _DEF_P2_DISPLAY_ITEM5		_MENU_NULL

#define _DEF_P3_COLORTEMP_ITEM4      _MENU_FUN_LOWBLUE

#define _DEF_P5_RESET_ITEM0    	  	 _MENU_FUN_POWER_OFF 
#define _DEF_P5_RESET_ITEM1    	  	 _MENU_FUN_RESET
#define _DEF_P5_RESET_ITEM2    	  	 _MENU_NULL

#define _DEF_P6_MISC_ITEM1			_MENU_FUN_AUDOIMUTE
#define _DEF_P6_MISC_ITEM2			_MENU_FUN_AUDOIVOLUME
#if _FREESYNC_SUPPORT
#define _DEF_P6_MISC_ITEM3      	    _MENU_FUN_FREESYNC
#define _DEF_P6_MISC_ITEM4      	    _MENU_FUN_OD
#else
#define _DEF_P6_MISC_ITEM3      	    _MENU_FUN_OD
#define _DEF_P6_MISC_ITEM4      	    _MENU_FUN_POWER_OFF
#endif



#elif(Project_ID == ID_HUIXIONG_HK2785E06_MV315QHM_N40_QHD90HZ_10BIT_EDID_X322Q90_20230713)
#define _DEF_HOTKEY_LEFT									_HOT_KEY_LOS_TYPE1
#define _DEF_HOTKEY_RIGHT									_MENU_FUN_AUDOIVOLUME
    
#define _DEF_BACKLIGHT										80
#define _LOGO_TYPE											_NONE_LOGO
    
#define _BACKLIGHT_MAX									   	0xBF//C8
#define _BACKLIGHT_DEF_PWM								  	0xA1
#define _BACKLIGHT_MIN								        10 
    
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _DCR_PANEL_ON_OFF									_ON	//DCR�򿪣��ڳ��Ƿ�ر���
    
#define _SOURCE_AUTO_ON								        _ON	//�ź��л��Ƿ��auto
#define _DEF_ECO_SET										_ON	//�ͻ�Ҫ���ECOģʽ���趨ֵ
#define _OSD_7PAGE											_ON	//�˵�7ҳ
#define _DEF_SAVING_SOURCE									_ON	//ʡ��ģʽ�¿���ѡ��ӿ�ͨ��
#define _DEF_SHARPNESS_ONE									_ON	//�����Ƚ�������ʾ100
#define _DEF_PROGRESS_BAR_3PAGE								_ON//����ѡ���ӳ����������˵�
#define _EOC_RTS_FPS_SUPPORT					     	    _OFF  //ECOģʽ�Ƿ�� RTS��FPS
#define _DEF_PROGRESS_BAR_NEW								_ON	//��������ECO����
#define _DEF_RESET_SOURCE_AUTO								_ON	//���ú��źŻ�ԭ���Զ�
#define _DEF_HDR_540										_ON	//HDR����һ��
#define _DEF_HUIXIONG_BURN_MENU								_ON	//���ܹ����˵�
#define _DEF_HDR_COLOR_6432									_ON	//6432HDR����˲����ɫ  (�����ȿ���,��˵��ٿ���û�й�������������ɫ)
    //#define _OSD_BLACK_TYPE                                       0 //��ɫ�˵�ѡ��
#define	_OSD_BLUE_TYPE										_OFF//��ɫ�ͺ�ɫ �˵�ѡ��
#define _DEF_STA_SIX_COLOR									_OFF
    
#define _CT_DEFAULT											_CT_6500
    
#define _DEF_POWEROFF                                     	_AutoPowerOff_OFF
    
#define _KOREAN_SUPPORT										_ON//����
#define _RUSSIAN_SUPPORT									_ON  //����
#define _LANG_19											_ON
#define _DEF_LANGUAGE										_KOREAN
    
#define _OD_WEAK									   			 0x12
#define _OD_MID									   				 0x26
#define _OD_STRONG									   			 0x3A//
    
    
#define _ECO_MOVIE_BACKLIGHT								70
#define _ECO_FPS_BACKLIGHT									70
#define _ECO_RTS_BACKLIGHT									60
    
#define _ECO_MOVIE_CONTRAST									50
#define _ECO_FPS_CONTRAST									50
#define _ECO_RTS_CONTRAST									50
    
    
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_NULL
    
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_POWER_OFF
#define _DEF_P6_MISC_ITEM3      	 _MENU_FUN_RESET
    
#elif(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION					_OFF
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _SOURCE_AUTO_ON								        _OFF //�ź��л��Ƿ��auto
    
#define _DEF_LIGHTMODE                                      LightMode_Static
#define _DEF_PreLIGHTMODE                                   LightMode_Static
    
    
#define _DEF_OSD_LEDTYPE                 				    _OSDLedType_OFF
    
#define _DEF_GAMMA											_GAMMA_22
#define _DEF_ASPECT											_OSD_ASPECT_RATIO_16_BY_9
    
#define _EOC_RTS_FPS_SUPPORT								 _ON
    
#define _OD_WEAK_MID_HIGH								    _ON
    
#define _SKYWORTH_OSD_LOGO								    _ON
    
#define _CT_7500_5800_sRGB_SUPPRT							_ON
#define _CT_DEFAULT                               			_CT_6500
    
#define _FW_VERSION                         _F__,_W__,__,_COLON__,__,_V__,_C__,_0__,_1__,__,_2__,_0__,_2__,_4__,_0__,_1__,_1__,_7__
    
#if _MD2769
#define _DEF_LANGUAGE                          _CHINESE_S
#define _DEF_P6_MISC_ITEM3     	     _MENU_FUN_RESET
#define _DEF_P6_MISC_ITEM4      	 _MENU_NULL
#define _DEF_P6_MISC_ITEM5      	 _MENU_NULL
#define _BACKLIGHT_MAX                           0xb0
#define _BACKLIGHT_DEF_PWM                       0xa0
#define _BACKLIGHT_MIN                           0x16
#define _LOGO_TYPE                                        _NONE_LOGO  
#else
#define _DEF_LANGUAGE                          _ENGLISH
#define _DEF_P6_MISC_ITEM3     	     _MENU_FUN_LIGHTMODE
#define _DEF_P6_MISC_ITEM4      	 _MENU_FUN_COLOR
#define _DEF_P6_MISC_ITEM5      	 _MENU_FUN_RESET
#define _LOGO_TYPE                                          _LOGO_WMX
#define _BACKLIGHT_MAX                           0x79
#define _BACKLIGHT_DEF_PWM                       0x70
#define _BACKLIGHT_MIN                           0x16
#endif
#define _DEF_BACKLIGHT                                      80  
    
#define _DEF_HOTKEY_LEFT                                 _MENU_FUN_BACKLIGHT   
#define _DEF_HOTKEY_RIGHT                                _MENU_FUN_AUDOIVOLUME    
    
    
    
    
    
    
#define _MPRT_WEAK_MID_HIGH                                 _ON // OD ǿ����
    
    
#define _MPRT_RATIO                                      50  //��
#define _MPRT_MID_RATIO                                  40  //��
#define _MPRT_HIGH_RATIO                                 30 //��
    
    
#define _DEF_P3_COLORTEMP_ITEM2      _MENU_FUN_OD  
#define _DEF_P3_COLORTEMP_ITEM3      _MENU_NULL  
#define _DEF_P6_MISC_ITEM1      	 _MENU_FUN_HDR
#define _DEF_P6_MISC_ITEM2      	 _MENU_FUN_MPRT
#define _DEF_P5_RESET_ITEM5      	 _MENU_NULL
    
    
#define _ECO_GAME_BACKLIGHT                     60
#define _ECO_MOVIE_BACKLIGHT                    80
#define _ECO_TEXT_BACKLIGHT                     40
    
#define _ECO_GAME_CONTRAST                      50
#define _ECO_MOVIE_CONTRAST                     50
#define _ECO_TEXT_CONTRAST                      50
    
    
    
#define _ENGLISH_SUPPORT									_ON
#define _FRENCH_SUPPORT										_ON
#define _GERMAN_SUPPORT										_ON
#define _CHINESE_S_SUPPORT									_ON
#define _ITALIAN_SUPPORT									_ON
#define _JAPANESE_SUPPORT									_OFF
#define _RUSSIAN_SUPPORT									_ON
#define _KOREAN_SUPPORT										_OFF
#define _CHINESE_F_SUPPORT									_OFF
    
#define _SPANISH_SUPPORT									_ON
#define _DUTCH_SUPPORT										_OFF
#define _PORTUGUESE_SUPPORT									_ON
#define _SVENSKA_SUPPORT									_OFF
#define _TURKISH_SUPPORT									_OFF
#define _XILAYU_SUPPORT										_OFF
#define _MAGYAR_SUPPORT										_OFF
#define _POLSKI_SUPPORT										_OFF
#define _FINNISH_SUPPORT									_OFF
#define _CZECH_SUPPORT										_OFF
#define _LANG_19									        _OFF
    
#elif(Project_ID == ID_2556_TEST)
#define _LOGO_TYPE											_MAG_LOGO
#define _DEF_BACKLIGHT                               		80
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_HOT_KEY_LOS_TYPE1
    
#define _BACKLIGHT_MAX										(0xFF-0x6D)
#define _BACKLIGHT_DEF_PWM							        (0xFF-0x9E)
#define _BACKLIGHT_MIN										12
    
#define _OD_WEAK_MID_HIGH									_ON	//OD ����ǿ
#define _DCR_PANEL_ON_OFF									_ON	//DCR�򿪣��ڳ��Ƿ�ر���
#define	_OSD_BLUE_TYPE										_OFF//��ɫ�ͺ�ɫ �˵�ѡ��
#define _SOURCE_AUTO_ON								        _ON	//�ź��л��Ƿ��auto
#define _OSD_7PAGE											1	//�˵�7ҳ
#define _DEF_SAVING_SOURCE									_ON	//ʡ��ģʽ�¿���ѡ��ӿ�ͨ��
#define _DEF_PROGRESS_BAR_3PAGE								_ON//����ѡ���ӳ����������˵�
#define _DEF_LANGUAGE										_CHINESE_S
    
#define _DEF_POWEROFF                                     	_AutoPowerOff_OFF
    
    
#elif(Project_ID == ID_CHANGHONG_HK2525E04_1V1P1H_HKC_PN238CT02_FHD75_20201021)
#define _LOGO_TYPE											_CHANGHONG_LOGO  
    
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_HOT_KEY_LOS_TYPE1
    
#define _BACKLIGHT_DEF_PWM									 0x80//111
#define _BACKLIGHT_MAX										0xff// (118)	
#define _BACKLIGHT_MIN										0X10
    
#define _DEF_LANGUAGE										 _ENGLISH
#define _DEF_P3_COLORTEMP_ITEM2     _MENU_NULL 
    
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_NULL  
    
#define _DEF_P3_COLORTEMP_ITEM4     _MENU_NULL
    
#define  _OSD_BLUE_TYPE                _OFF
    
#define _DEF_P1_PICTURE_ITEM0		_MENU_FUN_OSD_RORATE
    
    
#elif(Project_ID == ID_CHANGHONG_2513_TEST)
#define _LOGO_TYPE											_LOGO_PICHAU  
    
#define _REMIND_ENERGY_EFFICIENCY_FUNCTION					_ON
    
#define _DEF_HOTKEY_LEFT									_MENU_FUN_BACKLIGHT
#define _DEF_HOTKEY_RIGHT									_HOT_KEY_LOS_TYPE1
    
#define _BACKLIGHT_DEF_PWM									 (0xFF-0xA0)//111
#define _BACKLIGHT_MAX										(0xFF-0x80)// (118)	
#define _BACKLIGHT_MIN										0X10
    
#define _DEF_LANGUAGE										 _ENGLISH
#define _DEF_P3_COLORTEMP_ITEM2     _MENU_NULL 
    
#define _DEF_P3_COLORTEMP_ITEM3     _MENU_NULL  
    
#define _DEF_P3_COLORTEMP_ITEM4     _MENU_NULL


#endif

#ifndef _OSD_CROSS_SMALL
#define _OSD_CROSS_SMALL										_OFF	//KAITENG SMALL CROSS
#endif


#ifndef _OSD_7PAGE
#define _OSD_7PAGE										0	//�˵�7ҳ
#endif


#ifndef _DEF_PAGE8
#define _DEF_PAGE8									_OFF
#endif


#ifndef _HDCP_KEY_WIRTE_FLAG
#define _HDCP_KEY_WIRTE_FLAG										_OFF	//����HDCP KEY ��׼
#endif

#ifndef _EN_AUDIO_PAGE
#define _EN_AUDIO_PAGE								_ON
#endif

#ifndef _DEF_TIMEOUT
#define _DEF_TIMEOUT										20	
#endif

#ifndef _DEF_SAVING_MODE
#define _DEF_SAVING_MODE										60	
#endif


