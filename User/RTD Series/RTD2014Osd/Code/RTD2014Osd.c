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
// ID Code      : RTD2014Osd.c No.0000  //IDO
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSD__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)
BYTE g_flag_Nosignal = 0;

#if(_DEF_PAGE8)
BYTE idata OsdStateDefine[_OSD_MAIN_MENU_COUNT][7]={0};
#else
BYTE idata OsdStateDefine[_OSD_MAIN_MENU_COUNT][6]={0};
#endif

BYTE idata OSD_MASK[_OSD_MAIN_MENU_COUNT] = {0};

BYTE idata OSD_MAIN_MENU_ITEM = 0;
BYTE idata OSD_SubMenuCur = 0;

#if(_PROJECT == _RL6463_PROJECT)
BYTE idata OSD_ITEM_BASE[_MENU_NULL - _MENU_FUN_BACKLIGHT] = {0};
#else
BYTE xdata OSD_ITEM_BASE[_MENU_NULL - _MENU_FUN_BACKLIGHT] = {0};
#endif
BYTE idata OSD_ITEM_MASK[10] = {0}; //wwq   ����뺯����������������ʵ�ʲ˵��ϵĺ�������
//BYTE idata OSD_ITEM_MASK[_OSD_MAIN_MENU_COUNT] = {0}; 


BYTE xdata g_ucOsdRorateState = _DEF_OSDROTATE;

BYTE xdata g_ucBacktoHotKeyState = 0;
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))
WORD BackUpTempVFreq = 0;
#endif



#if(_DEF_2795E06)
BYTE xdata g_SouceSelect = 1;
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructOsdInfo g_stOsdInfo;

WORD g_usAdjustValue;
WORD g_usBackupValue;
BYTE xdata g_ucLogoTimerCounter;
WORD xdata g_usPowerDownCount;
BYTE xdata g_usPowerDownCount_MSG;
void MenuCross(void);

#if(_DEF_HOTKEY_REPLACE)
//ѡ��̫��,��ҳ�õ�
BYTE g_ucHotKey_Left = 0;
BYTE g_ucHotKey_Right = 0;
BYTE g_ucHotKey_Exit = 0;
#endif

BYTE g_ucLanguage = 0 ;
BYTE g_ucPowerPage = 0 ;
BYTE g_SavingTimerCount = 0;

#if (_LED_EFFECT_TJMODE14==_ON)
extern BYTE led_start;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void RTDOsdSystemFlowProc(void);
void RTDOsdEventMsgProc(void);
#if((_HDMI_HDR10_SUPPORT == _ON) && (_D3_INPUT_PORT_TYPE != _D3_HDMI_PORT) &&(_HDMI_MAC_PAGE72_USE == _ON))
extern void ScalerTMDSRx3GetHDR10Data(BYTE *pucHDRData);
#endif
//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Handler, executed in the main loop
// Input Value  : None
// Output Value : None
//--------------------------------------------------


#if 1
#define TYPEC_CC1       (P1_5) // _156PIN_PIN_132, P7D2

#define TYPEC_CC2		(P1_6) // _156PIN_PIN_131, P7D2


#define _3036_ROTATION1       (MCU_FE23_PORT83_PIN_REG) // _156PIN_PIN_68, P8D1

#define _3036_ROTATION2		(MCU_FE14_PORT64_PIN_REG) // _156PIN_PIN_49, P6D4



#define _ROTATION_IN_A       (MCU_FE13_PORT63_PIN_REG) // _156PIN_PIN_48, P6D3 

#define _ROTATION_IN_D		(MCU_FE12_PORT62_PIN_REG) // _156PIN_PIN_47, P6D2

#define _ROTATION_OUT_B		(MCU_FE21_PORT81_PIN_REG) // _156PIN_PIN_67, P8D0

#define _ROTATION_OUT_C		(MCU_FE1F_PORT77_PIN_REG) // _156PIN_PIN_66, P7D7 
#endif

void TypeC_Proc(void)
{
																																					  
#if(_PCB_TYPE == _RL6449__216PIN__HK_M_RTD2795E02__1T1DP1H__eDPVB1)||(_PCB_TYPE == _RL6449__216PIN__HK_M_RTD2795E06__1T1DP1H__eDPVB1 || _DEF_2795E06)
		  
	ScalerDpRx0SetDpLaneMapping(0,0);

	if(GET_FUN_KVM() == _OFF)//�Զ�
	{
		if(SysSourceGetInputPort()== _D0_INPUT_PORT )
		  HUB_SWITCH(0);
		else
		  HUB_SWITCH(1);
	}
	else
	{
		if(GET_FUN_KVM() == 1)	//PC
			HUB_SWITCH(1);
		else if(GET_FUN_KVM() == 2)	//Type-c
			HUB_SWITCH(0);
		else
			HUB_SWITCH(0);
	}

#if 0	//����TYPE C�����TYPE-C�ӿ�
	if((g_SouceSelect != 0))
	{   

	  if((bD0_DP_PIN16_CONNECT == _FALSE)&&((MCU_FFE4_DDC0_EDID_IRQ & _BIT0) == _TRUE)&&(SysSourceGetInputPort() != _D1_INPUT_PORT || SysSourceGetInputPort() != _D2_INPUT_PORT))
	  {

		  if(SysSourceGetInputPort() != _D0_INPUT_PORT)
		  {
		  
			  SET_FORCE_POW_SAV_STATUS(_FALSE);
			  SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
			  MCU_FFE4_DDC0_EDID_IRQ |=  (_BIT0);
			  SysSourceSwitchInputPort(_D0_INPUT_PORT);
			  SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
		  }

	  }   
	}
#endif

#endif
#if (_PCB_TYPE == _RL6449__216PIN__HK_M_RTD2775E05__1T1DP1H__eDPVB1)
        if(bD0_DP_PIN16_CONNECT == _FALSE)
          ScalerDpRx0SetDpLaneMapping(_TYPE_C_PIN_ASSIGNMENT_C,_TYPE_C_ORIENTATION_UNFLIP);

#elif (_PCB_TYPE == _RL6432__156PIN__HKMRT2556E12__1H1DP1T__LVDS)
			
	ScalerDpRx0SetDpLaneMapping(_TYPE_C_PIN_ASSIGNMENT_E,0);
//	if(SysSourceGetInputPort()== _D0_INPUT_PORT &&  GET_HUB_SWITCH()!=_HUB_C)
//	{
//		HUB_SWITCH(_HUB_C);
//		HUB_SWITCH_INIT(_HUB_INIT_ON);
//		ScalerTimerDelayXms(100);
//		HUB_SWITCH_INIT(_HUB_INIT_OFF);

//	}
//	else if(SysSourceGetInputPort()!= _D0_INPUT_PORT &&  GET_HUB_SWITCH()!=_HUB_B)
//	{
//		HUB_SWITCH(_HUB_B);
//		HUB_SWITCH_INIT(_HUB_INIT_ON);
//		ScalerTimerDelayXms(100);
//		HUB_SWITCH_INIT(_HUB_INIT_OFF);

//	}

	
#endif

}


void UserOsdHandler(void)
{
    RTDOsdSystemFlowProc();	
    RTDOsdEventMsgProc();

#if (_DEF_2795E06||_PCB_TYPE == _RL6449__216PIN__HK_M_RTD2775E05__1T1DP1H__eDPVB1)
	TypeC_Proc();
#endif
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdSystemFlowProc(void)
{
    switch(SysModeGetModeState())
    {
        case _MODE_STATUS_POWER_OFF:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }

            break;

        case _MODE_STATUS_INITIAL:

            if(SysModeGetModeStateChange() == _TRUE)
            {

        	g_flag_Nosignal=1;
			
#if(_FREESYNC_OD_MEASURE == _ON)
                UserAdjustFREESYNCODMeasure();
#endif
#if(_LOGO_TYPE != _NONE_LOGO)
    			if(GET_OSD_BURNING_MODE() == _OFF&&GET_OSD_LOGO() == _ON)
				{
	                OsdDispShowLogo();
	                UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
    			    OsdFuncEnableOsd();
                    PCB_LED_ACTIVE();

					
					ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_120s);
					ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);				
					ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BUININ_MSG);
	                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
				}
				else
				{
					OsdDispDisableOsd();
				}
#else				
				OsdDispDisableOsd();
#endif


				if(GET_OSD_LED_TYPE() == _OSDLedType_OFF)
				{
					ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED_MODE_FLICKER); 
				
					OSD_LED_CONTRL(_OSD_LED_OFF);
				}
				else if(GET_OSD_LED_TYPE() == _OSDLedType_ON)
				{
					ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED_MODE_FLICKER); 
				
					OSD_LED_CONTRL(_OSD_LED_ON);
				
				}
				else if(GET_OSD_LED_TYPE() == _OSDLedType_FLASH)
				{
					ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_LED_MODE_FLICKER); 	
				}

			}

            break;

        case _MODE_STATUS_SEARCH:

            if(SysModeGetModeStateChange() == _TRUE)
            {
#if(_FREEZE_SUPPORT == _ON)
                if(GET_OSD_FREEZE_STATUS() == _ON)
                {
                    SET_OSD_FREEZE_STATUS(_OFF);
                }
#endif
                if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
                {
                    UserInterfaceKeyPadLedControl(_LED_POWER_SEARCH);
                }
            }

            break;

        case _MODE_STATUS_DISPLAY_SETTING:

            break;

        case _MODE_STATUS_ACTIVE:

			if(g_flag_Nosignal&&GET_OSD_FACTORY_MODE()==_OFF)
 			{
 				DebugMessageSystem("_USER_TIMER_EVENT_AUTO_POWER_DOWN",0);	
 				g_flag_Nosignal=0;
 				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 			
 				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
 				if(GET_OSD_AUTO_POWEROFF())
 				{
	 				g_usPowerDownCount = GET_OSD_AUTO_POWEROFF() * 60;
	 				ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_AUTO_POWER_DOWN);
 				}
 				
                ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED_MODE_FLICKER); 
 			}
            if(SysModeGetModeStateChange() == _TRUE)
            {			

#if(_DEF_2795E06)
				PCB_USB_HUB_POWER(0);
				ScalerTimerDelayXms(300);
				PCB_USB_HUB_POWER(1);
#endif

#if(_MPRT_SUPPORT == _ON)
				UserAdjustLowMotionBlurDisplay(GET_OSD_MPRT());			
#endif

                if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
                {
                    UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
                }

                
#if(_LED_EFFECT_TJMODE14 == _ON)
            
                    OSD_LED_CONTRL(_OSD_LED_ON);
                    led_start = 1;
#else
                    if(GET_OSD_LED_TYPE() == _OSDLedType_OFF)
                    {
                        ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED_MODE_FLICKER); 
                    
                        OSD_LED_CONTRL(_OSD_LED_OFF);
        
                    }
                    else if(GET_OSD_LED_TYPE() == _OSDLedType_ON)
                    {
                        ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED_MODE_FLICKER); 
                    
                        OSD_LED_CONTRL(_OSD_LED_ON);
                    
                    
                    }
                    else if(GET_OSD_LED_TYPE() == _OSDLedType_FLASH)
                    {
                        ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_LED_MODE_FLICKER);  
                    }
#endif

            }
            
			if(GET_OSD_FACTORY_MODE()==_ON)
              ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_LED_MODE_FLICKER);  

            
            break;

        case _MODE_STATUS_NOSUPPORT:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
                {
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
                    UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);
                }
            }

            break;

        case _MODE_STATUS_NOSIGNAL:

            if(SysModeGetModeStateChange() == _TRUE)
            {
    			if(GET_OSD_BURNING_MODE() == _ON)
    			{
#if(_SOURCE_AUTO_ON)	//���ź�ѡ����Զ�ѡ��,��ѡ��Ϊ�Զ�ʱ��ѡ��
					if(GET_OSD_INPUT_PORT_OSD_ITEM() == _OSD_INPUT_AUTO)				
#endif
					{
						SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
					}
#if(_INTERNAL_AUDIO_TEST_SUPPORT)
					if(GET_BURNING_AUDIO_TEST()==_ON)
					{
						SET_FORCE_POW_SAV_STATUS(_FALSE);
						SysSourceSwitchInputPort(_D1_INPUT_PORT);
						SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
						SysAudioInternalGenTestProc(_ON);
						SysAudioMuteProc(_OFF);
        				UserAdjustAudioVolume(12);//0.5w
				
					}
#endif				


#if(_LED_EFFECT_TJMODE14==_ON)

                    led_start =1;
                    OSD_LED_CONTRL(_OSD_LED_ON);

#else

                    if(GET_OSD_LED_TYPE() == _OSDLedType_OFF)
                    {

                    OSD_LED_CONTRL(_OSD_LED_OFF);
                    }
                    else if(GET_OSD_LED_TYPE() == _OSDLedType_ON)
                    {

                    OSD_LED_CONTRL(_OSD_LED_ON);

                    }

#endif
					ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_BUININ_MSG);
					#if  (_BURNIN_MSG_MENU_SUPPORT==_ON)
						RTDBurnInMenu();
					#endif

					UserAdjustContrast(100);
					UserAdjustBacklight(100);
                    ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_LED_MODE_FLICKER); 
					UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
				}
				else
				{
//�������ź�״̬�Զ�����һ���ź�
#if(_AUTO_SearchSource) 
//                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_AUTO);

                SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
                if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
                {
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_MODE_FLICKER); 
#endif



//=====================================

					g_flag_Nosignal=1;
	                if(SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE)
	                {
	                    ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
	                }
	                else
	                {
	                    ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
	                }
				}
            }
			
            break;

        case _MODE_STATUS_POWER_SAVING:

            if(SysSourceGetCableDetect(SysSourceGetInputPort()) == _FALSE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }

            if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
            {
#if(_SOURCE_AUTO_ON)||(_DEF_SAVING_SOURCE)
                if(GET_OSD_POWER_SAVING_SHOW_SOURCE() == _TRUE)
                {
                    SET_OSD_POWER_SAVING_SHOW_SOURCE(_FALSE);

                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG);
                }
 #endif
            }

            break;

        case _MODE_STATUS_FACTORY:

            break;

        default:

            break;
    }
	

#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
    // Check embedded DP switch status
    UserCommonAdjustEmbeddedDpSwitch();
#endif


    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
    {
        // hot key
        if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) ||
        
           (SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) ||
           (SysModeGetModeState() == _MODE_STATUS_POWER_SAVING))
        {
            if((((((GET_OSD_STATE() < _MENU_END)&&(_MENU_FUN_BACKLIGHT <= GET_OSD_STATE())&& GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_SLIDER)||(_MENU_HOT_KEY_FUNC == GET_OSD_STATE() && GetOsdShowType(OSD_SubMenuCur) == _TYPE_SLIDER) )&& ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)))||((GetOsdShowType(GET_OSD_STATE())==_TYPE_SLIDER)&& ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE))))\
                ||(((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE))&&((GET_OSD_STATE()>=_MENU_FACTORY_CT1_RED_ADJ&&GET_OSD_STATE()<=_MENU_FACTORY_CT4_BLUE_ADJ)&&GET_OSD_IN_FACTORY_MENU_STATUS()==_ON)))
            {
                SET_KEYREPEATENABLE();
            }
#if(_DEF_STA_SIX_COLOR)
			if(GET_OSD_STATE() >= _MENU_FUN_SAT_RED && _MENU_FUN_HUE_YELLOW >= GET_OSD_STATE())
			{
				SET_KEYREPEATENABLE();
			}
#endif


        }
		
		
        if(GET_OSD_IN_FACTORY_MENU_STATUS() == _TRUE)
        {
            RTDFactoryMenuOperation();
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_120s);
        }
        else
        {
            // back up previous OSD State
            SET_OSD_STATE_PREVIOUS(GET_OSD_STATE());
			
			{
            	(*OperationTable[GET_OSD_STATE()])();
			}
			
            if(GET_OSD_IN_FACTORY_MENU_STATUS() == _FALSE)
            {
                if(SysModeGetModeState() == _MODE_STATUS_ACTIVE &&((GET_OSD_STATE() < _MENU_END)&&(_MENU_NONE < GET_OSD_STATE())))
                {
                    if((GET_OSD_STATE() == _HOT_KEY_LOS_TYPE1) || (GET_OSD_STATE() == _HOT_KEY_LOS_TYPE2))
                    {
                    
                       	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);                       
					  	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_120s);
                   }
//#if(_DEF_REAL_TIME_HZ)
//					else if(GET_OSD_FV_INFORMATION() && (GET_OSD_HZ_DISPLAYSTATUS()&(~(_BIT1|_BIT2|_BIT3|_BIT4|_BIT5|_BIT6|_BIT7))))
//					{
//						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
//					}
//#endif
                    else
                    {
						if(GET_OSD_TIME_OUT() > 60)
						{
//							ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
//							ScalerTimerReactiveTimerEvent(SEC((GET_OSD_TIME_OUT()-60)), _USER_TIMER_EVENT_OSD_DISABLE_120s);
							
						}
						else
						{
							ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_120s);
							ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
						}
//                        ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
                    }
                }
            }


/*
            if((GET_OSD_STATE() >= _MENU_NONE) &&
                (GET_OSD_STATE() < _MENU_END) &&
                ((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING) || (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL)))
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            }
            else//(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
            }

            if(GET_OSD_IN_FACTORY_MENU_STATUS())
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
            }
*/
        }
    }
}

//--------------------------------------------------
// Description  : OSD event message processing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdEventMsgProc(void)
{
	int i = 0;

    switch(GET_OSD_EVENT_MESSAGE())
    {
        case _OSDEVENT_SHOW_NOSIGNAL_MSG:
			
			ScalerDDomainBackgroundSetColor(0, 0, 0);
			ScalerDDomainBackgroundEnable(_ENABLE);
			
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 			
            OsdDispOsdMessage(_OSD_DISP_NOSIGNAL_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
			g_SavingTimerCount = 0;
			ScalerTimerActiveTimerEvent(SEC(20), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);

            break;

        case _OSDEVENT_SHOW_NOCABLE_MSG:
			ScalerDDomainBackgroundSetColor(0, 0, 0);
			ScalerDDomainBackgroundEnable(_ENABLE);
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
            OsdDispOsdMessage(_OSD_DISP_NOSIGNAL_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
			g_SavingTimerCount = 0;
			ScalerTimerActiveTimerEvent(SEC(20), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);

            break;

        case _OSDEVENT_SHOW_NOSUPPORT_MSG:

            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);

            OsdDispOsdMessage(_OSD_DISP_NOSIGNAL_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);

			//if(GET_FUN_OVERCLOCK_HINT() == _OFF);
			g_SavingTimerCount = 0;
           	ScalerTimerReactiveTimerEvent(SEC(20), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
			break;

        case _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG:
            OsdDispOsdMessage(_OSD_DISP_FAIL_SAFE_MODE_MSG);
            break;

        case _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG:

			if (g_SavingTimerCount < (GET_OSD_SAVING_MODE()/20 - 1)) {
				g_SavingTimerCount++;
				ScalerTimerActiveTimerEvent(SEC(20), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
			} else {
				g_SavingTimerCount = 0;
				OsdDispDisableOsd();
				OsdDispOsdMessage(_OSD_DISP_POWER_SAVING_MSG);
				UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
				ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
			}

            break;

        case _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG:
			Cross_flag = 0;

            OsdDispDisableOsd();
#if(_LED_EFFECT_TJMODE14==_ON)
                        SET_OSD_LED_TYPE(_OSDLedType_OFF);
                        led_start =1;                 //�رյ�Ч
                         // ScalerTimerDelayXms(30);
#endif
            SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_DO_AUTO_CONFIG_MSG:
#if(_FREEZE_SUPPORT == _ON)
            ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG);
#endif
            OsdDispAutoConfigProc();
            break;
#endif

        case _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG:

#if(_FREEZE_SUPPORT == _ON)
            ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG);
#endif

#if(_VGA_SUPPORT == _ON)
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                if(UserInterfaceGetFirstAutoConfigStatus() == _TRUE)
                {
                    OsdDispAutoConfigProc();
                }
            }
#endif

            if(GET_OSD_STATE() == _MENU_NONE)
            {
				if(GET_OSD_CROSS_STATUS()==_ON)//)(Cross_flag == 1)
				{
					//RTDOsdDispHotkeyFuncAdjust(_HOT_KEY_LOS_TYPE1-_MENU_FUN_BACKLIGHT);	
                                  MenuCross();
					
				}
				else
				{
					OsdDispOsdMessage(_OSD_DISP_INPUT_SIGNAL_MSG);
                    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);//��ֹ��RESET֮���ͬ���ɲ˵�����ʧʱ��
                    ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
				}
            }
            break;

        case _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG:
            UserCommonNVRamSaveSystemData();
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG:
            UserCommonNVRamSaveModeUserData();
            break;
#endif
        case _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG:
            RTDNVRamSaveOSDData();
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG:
            if(ScalerColorGetColorSpaceRGB(UserCommonInterfaceGetColorFormat()) == _TRUE)
            {
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            }
            else
            {
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);
            }
            break;
#endif

        case _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG:
            RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
            break;

        case _OSDEVENT_SAVE_NVRAM_BRICON_MSG:
            RTDNVRamSaveBriCon(SysSourceGetSourceType());
            break;

        case _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG:
            RTDNVRamSaveSixColorData();
            break;

	    case _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG:
//#if(_DEF_2795E06)	->ֻ����һ����־λ  �����Ժ����
			/*
			SET_OSD_POWER_SAVING_SHOW_SOURCE(_FALSE);
	    	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
            OsdFuncSetOsdItemFlag();
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
			
			RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_SIGNAL -_MENU_FUN_BACKLIGHT);
*/
			OsdInputSourceHotkey();
			UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
			if((SysSourceGetSourceType() == _SOURCE_NONE))
			{
				SET_FORCE_POW_SAV_STATUS(_TRUE);
			}


			break;

			case _OSDEVENT_BUININ_MSG:
            if((SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) && GET_OSD_BURNING_MODE())
            {
				FactoryBurnInEvent();			
        	}
			else
			{
			
	#if (_BURNIN_MSG_MENU_SUPPORT==_ON)
				OsdDispDisableOsd();
	#endif
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BUININ_MSG);
			}
			break;
        default:
            break;
    }

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_NONE_MSG);
}

#if(_NAVIGAT_MENU_SURPPORT)

void MenuNavigatNone(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			
            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                SET_OSD_STATE(_MENU_NAVIGAT_NONE);
				
				if(GET_OSD_FACTORY_MODE() == _ON)
				{
					RTDFactoryMainMenu();
				}
				else
				{
					OsdDispNavigatMenu();			   
				}
            }

			break;
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
            if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_OSD_FACTORY_MODE() == _OFF))
            {
                SET_OSD_STATE(_MENU_NAVIGAT_NONE);
				
				OsdDispNavigatMenu();			   
            }
            break;
		case _EXIT_KEY_MESSAGE:
            if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_OSD_FACTORY_MODE() == _OFF))
			 {
				 SET_OSD_STATE(_MENU_NAVIGAT_NONE);
				 OsdDispNavigatMenu();				
			 }
            
#if(_SOURCE_AUTO_ON)
			else if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
			{
				SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);

				if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING))
				{
					SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
				}
			}
#endif            
			break;

        default:
            break;
    }
}

#endif

#if(_DEF_HOTKEY_REPLACE)
void RTDOsdDispHotKeyUser(BYTE User_HotKey_i)
{
	if(User_HotKey_i == _OFF)
	{
		return;
	}

	if(User_HotKey_i == 11)	//�ź�ѡ��
	{
		if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
	   	{
		   	SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);
		   	if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING))
		   	{
			   SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
		   	}
			ScalerTimerActiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
	   	}
		else
		{
			OsdDispDisableOsd();
			OsdInputSourceHotkey();
		}
		return;
	}

	if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
	{
		return;
	}

	if(User_HotKey_i == 1)	//����
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_BACKLIGHT-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 2)	//�Աȶ�
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_CONTRAST-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 3)	//�龰ģʽ
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_ECO-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 4)	//ɫ��
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_COLORGAMUT-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 5)	//��׼��
	{
		SET_OSD_HOTKEY_RIGHT(_HOT_KEY_LOS_TYPE1-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 6)	//֡��׷��
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_FV_INFORMATION-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 7)	//����
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_AUDOIVOLUME-_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 8)	//ɫ��
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_BRIGHTNESS -_MENU_FUN_BACKLIGHT);
	}
	else if(User_HotKey_i == 9)	//������ǿ
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_COLORTEMP-_MENU_FUN_BACKLIGHT);
	}
#if(_DEF_OPPOSITE_DCR)
	else if(User_HotKey_i == 10) //��̬����ģʽ
	{
		SET_OSD_HOTKEY_RIGHT(_MENU_FUN_DCR_OPPOSITE-_MENU_FUN_BACKLIGHT);
	}
#endif

	RTDOsdDispHotkeyFuncAdjust(GET_OSD_HOTKEY_RIGHT());
	return;
}

#endif


void MenuCross(void)
{



			    Cross_flag = 1;
		//	    OsdFuncDisableOsd();
	                  OsdDispDisableOsd();
			    OsdFuncApplyMap(WIDTH(4), HEIGHT(2), COLOR(_CP_BG, _CP_BG));   

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
				ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(2), _DISABLE, 0, _ENABLE);  
#endif
				OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
				OsdFuncTransparency(_OSD_TRANSPARENCY_ALL); 

				// Adjust Color Palette
				OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);


				OsdFontVLCLoadFont(_HOTKEY_1BIT_ICON);


#if(_OSD_CROSS_SMALL)

if(0 == GET_OSD_CROSS_HAIR_TYPE1())
OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON_SMALL0, COLOR(_CP_RED, _CP_BG),0);
else if(1 == GET_OSD_CROSS_HAIR_TYPE1())
OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON_SMALL0, COLOR(_CP_GREEN, _CP_BG),0);
else if(2 == GET_OSD_CROSS_HAIR_TYPE1())
OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1_SMALL1, COLOR(_CP_GREEN, _CP_BG),0);
else
OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1_SMALL2, COLOR(_CP_GREEN, _CP_BG),0);

OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
	 OsdFuncEnableOsd();



#else
				if(0 == GET_OSD_CROSS_HAIR_TYPE1())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON, COLOR(_CP_RED, _CP_BG),0);
				else if(1 == GET_OSD_CROSS_HAIR_TYPE1())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1, COLOR(_CP_RED, _CP_BG),0);
				else if(2 == GET_OSD_CROSS_HAIR_TYPE1())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON, COLOR(_CP_GREEN, _CP_BG),0);
				else
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1, COLOR(_CP_GREEN, _CP_BG),0);

				OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
		             OsdFuncEnableOsd();

#endif

}


void MenuNone(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                OsdFuncSetOsdItemFlag();
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
				{
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				    SET_OSD_ENGER(_OFF);
					OSD_SubMenuCur=0;                   
					g_ucBacktoHotKeyState = 0;
#endif
#if _LONG_PRESS_MENU_LOCK_OSD_ENABLE
					if(GET_OSD_LOCK())
					{
						RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_LOCK_MENU-_MENU_FUN_BACKLIGHT);
						ScalerTimerReactiveTimerEvent(SEC(3),_USER_TIMER_EVENT_OSD_DISABLE);
					}
					else
#endif
					{

#if _ENABLE_ENERGE_NOTICE_MENU//��Ч����
						if(GET_OSD_ENERGE_NOTICE_FLAG()&&(GET_OSD_FACTORY_MODE() != _ON))
							RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_SHOW_ENERGE_MENU-_MENU_FUN_BACKLIGHT);
						else
#endif
		                	OsdDispMainMenu();
					}
				}
            }
            break;

        case _RIGHT_KEY_MESSAGE:
            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				SET_OSD_ENGER(_OFF);
				g_ucBacktoHotKeyState = 1;
#endif

#if _LONG_PRESS_MENU_LOCK_OSD_ENABLE
				if(GET_OSD_LOCK())
				{
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_LOCK_MENU-_MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
				}
				else
#endif
				{
				
#if(_DEF_HOTKEY_REPLACE)
					RTDOsdDispHotKeyUser(GET_OSD_HOT_REPLACE_RIGHT());
#else
					RTDOsdDispHotkeyFuncAdjust(GET_OSD_HOTKEY_RIGHT());
#endif
				}
        	}
  
            break;

        case _LEFT_KEY_MESSAGE:

            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				if(GET_OSD_HOTKEY_LEFT()!=_HOT_KEY_LOS_TYPE1)
				{
					SET_OSD_ENGER(_OFF);
					g_ucBacktoHotKeyState = 1;
				}
#endif
#if _LONG_PRESS_MENU_LOCK_OSD_ENABLE
				if(GET_OSD_LOCK())
				{
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_LOCK_MENU-_MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
				}
				else
#endif
				{
#if(_DEF_HOTKEY_REPLACE)
					RTDOsdDispHotKeyUser(GET_OSD_HOT_REPLACE_LEFT());
#else
					RTDOsdDispHotkeyFuncAdjust(GET_OSD_HOTKEY_LEFT());
#endif
				}
        	}
            break;

        case _EXIT_KEY_MESSAGE:
#if(_DEF_HOTKEY_REPLACE)
			if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
			{
				SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);
				if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING))
				{
				   SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
				}
				ScalerTimerActiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
			}
			else
			{
				if(SysModeGetModeState() == _MODE_STATUS_ACTIVE && SysSourceGetInputPort() != _NO_INPUT_PORT)
				{
					RTDOsdDispHotKeyUser(GET_OSD_HOT_REPLACE_EXIT());
				}
				else
				{
					OsdDispDisableOsd();
					OsdInputSourceHotkey();
				}
			}	
			break;	
#endif


			
#if(_DEF_SAVING_SOURCE || _SOURCE_AUTO_ON)
			if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
		   	{
			   	SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);
			   	if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING))
			   	{
				   SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
			   	}
				ScalerTimerActiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
		   	}
			else
			{
				OsdDispDisableOsd();
				OsdInputSourceHotkey();
			}			
#elif((_NAVIGAT_MENU_SURPPORT == _OFF)&&(_SOURCE_AUTO_ON))
            if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
            {
                SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);

                if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING))
                {
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
                }
            }		  
#else
            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
        	{

            OsdDispDisableOsd();
            OsdInputSourceHotkey();
        	}

#endif
            break;



#if(_OSD_7_KEY_SUPPROT)		
		case _UP_KEY_MESSAGE:
			
			if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
			{
				RTDOsdDispHotkeyFuncAdjust(_DEF_HOTKEY_UP - _MENU_FUN_BACKLIGHT);
			}
			break;	
			
		case _DOWN_KEY_MESSAGE:
			
			if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
			{
				RTDOsdDispHotkeyFuncAdjust(_DEF_HOTKEY_DOWN - _MENU_FUN_BACKLIGHT);
			}
			break;

#endif

        default:
            break;
    }
}

void MenuInputSouce(void)
{
#if 0//
BYTE i;
#endif

    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if 0//
			if(SysSourceGetInputPort() == _D0_INPUT_PORT)
				i = 1;
			else if(SysSourceGetInputPort() == _D1_INPUT_PORT)
				i = 0;
			else if(SysSourceGetInputPort() == _D2_INPUT_PORT)
				i = 2;
			g_usBackupValue = i;
#else

			g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
#endif
			g_usAdjustValue = g_usBackupValue;
			//OSDSubMenuMove();
			SET_OSD_STATE(_MENU_FUN_SIGNAL);

#if 0//
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(i))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_2_COL*12-10,((_ITEM_1_ROW+2*(i)))*18-9, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(i))+1)*18+7, _COLOR_WINDOW_BG);	
#else
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM()))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM()))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_2_COL*12-10,((_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM())))*18-9, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM()))+1)*18+7, _COLOR_WINDOW_BG);	
#endif
			break;

        case _RIGHT_KEY_MESSAGE:
            if(GET_OSD_FACTORY_MODE())
				{
            UpdateOSDMainInterface(_OSD_MAIN_FACTORY);
				}
			else
				{
			UpdateOSDMainInterface(_OSD_MAIN_OTHER);
				}
            break;

        case _LEFT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_BRI_CON);
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;

        default:
            break;
    }
}

void MenuBri_Con(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_SOURCE);
            break;

        case _LEFT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_COLOR_SETTING);
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            if(GET_OSD_CROSS_STATUS()==_ON)
            {
            
            MenuCross();
            
            }

            break;

        default:
            break;
    }
}
void MenuColorSetting(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_BRI_CON);
            break;

        case _LEFT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_PQ_SETTING );
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {
            	MenuCross();
            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;

        default:
            break;
    }
}

void MenuPQSetting(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        	
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_COLOR_SETTING);
            break;

        case _LEFT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_DISPLAY );
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;

        default:
            break;
    }
}

void MenuDisplay(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        	
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_PQ_SETTING);
            break;

        case _LEFT_KEY_MESSAGE:

#if(_OSD_7PAGE || _DEF_PAGE8)
			UpdateOSDMainInterface(_OSD_MAIN_AUDIO );
#else
            UpdateOSDMainInterface(_OSD_MAIN_OSD );
#endif
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;

        default:
            break;
    }
}
#if(_OSD_7PAGE || _DEF_PAGE8)

void MenAudio(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        	
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_DISPLAY);
            break;

        case _LEFT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_OSD );
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;

        default:
            break;
    }
}


#endif
void MenuOSD(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        	
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
#if(_OSD_7PAGE || _DEF_PAGE8)
		 UpdateOSDMainInterface(_OSD_MAIN_AUDIO);
#else
			UpdateOSDMainInterface(_OSD_MAIN_DISPLAY);
#endif
            break;

        case _LEFT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_OTHER);
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;

        default:
            break;
    }
}


void MenuOther(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        	
			OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
			
			UpdateOSDMainInterface(_OSD_MAIN_OSD);
            break;

        case _LEFT_KEY_MESSAGE:
            if(GET_OSD_FACTORY_MODE())
            UpdateOSDMainInterface(_OSD_MAIN_FACTORY);
			else
			UpdateOSDMainInterface(_OSD_MAIN_SOURCE);
			
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }
#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
#endif
            break;
			

        default:
            break;
    }
}


void MenuFactory(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			RTDFactoryMainMenu();
            break;

        case _RIGHT_KEY_MESSAGE:
			UpdateOSDMainInterface(_OSD_MAIN_OTHER);
            break;

        case _LEFT_KEY_MESSAGE:
			UpdateOSDMainInterface(_OSD_MAIN_SOURCE);
            break;

        case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {
            	MenuCross();
            }
			#if(_DEF_REAL_TIME_HZ)
			if(GET_OSD_FV_INFORMATION())
				SET_OSD_HZ_DISPLAYSTATUS((GET_OSD_HZ_DISPLAYSTATUS()|_BIT0));
			#endif
            break;

        default:
            break;
    }
}

void MENU_FUN_COMMON(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE: 
        case _EXIT_KEY_MESSAGE:
	        OSDSubMenuMove();
            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
			#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
			if(GetOSDMSG(GET_OSD_STATE())==1&&GET_OSD_ENGER()==_OFF&&GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE){
				OsdDispDisableOsd();
				OsdDispOsdMessageEngerConsumption();
			}else if(GetOSDMSG(GET_OSD_STATE())==2&&GET_OSD_ENGER()==_OFF)
			{   
				OsdDispDisableOsd();
				OsdDispOsdMessageEngerConsumption();
			}
			else
			#endif
            DebugMessageOsd("MENU_FUN_COMMON", 1111);
			OSDSubMenuMove();
            break;

        default:
            break;
    }
}

void MENU_FUN_INPUT_SOURCE(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE: 
			if(GET_OSD_INPUT_PORT_OSD_ITEM() != g_usBackupValue)
			{
				SET_FORCE_POW_SAV_STATUS(_FALSE);
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
		
	#if(_SOURCE_AUTO_ON)
				if(GET_OSD_INPUT_PORT_OSD_ITEM() == _OSD_INPUT_AUTO)
				{
					SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);	//�Զ������ź�
					
					if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
					{
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
				}
				else
				{		
					SysSourceSwitchInputPort(OsdFuncGetOsdItemFlag());
					SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);	//�ֶ������ź�
					if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
					{
						UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
				}
	#else					
				SysSourceSwitchInputPort(OsdFuncGetOsdItemFlag());
				SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
				if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
				   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				{
					UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				}						
	#endif		
	
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			}
		

			
			SET_OSD_STATE(_OSD_MAIN_SOURCE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_8);
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_1_COL*12-10,((_ITEM_1_ROW))*18-9, (_ITEM_1_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW)+1)*18+7, _COLOR_WINDOW_BG);
            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
			{
				g_usAdjustValue = (BYTE)(OsdDisplayDetOverRangeRotation(GET_OSD_INPUT_PORT_OSD_ITEM() , _OSD_INPUT_AMOUNT-1, 0, _ON));
			}
			SET_OSD_INPUT_PORT_OSD_ITEM(g_usAdjustValue);
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM()))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM()))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_2_COL*12-10,((_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM())))*18-9, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(GET_OSD_INPUT_PORT_OSD_ITEM()))+1)*18+7, _COLOR_WINDOW_BG);	
			

			break;


        case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_OSD_MAIN_SOURCE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_8);
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_1_COL*12-10,((_ITEM_1_ROW))*18-9, (_ITEM_1_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW)+1)*18+7, _COLOR_WINDOW_BG);	
			SET_OSD_INPUT_PORT_OSD_ITEM(g_usBackupValue);
            break;

        default:
            break;
    }
}




void MENU_HOT_KEY_FUNC(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE:
#if(_KEY_IR_HUIXIONG_CROOSSOVER)
			//SET_IR_HOTKEY_STATUS(_OFF);
#endif
			OsdHotKeyFuncSpacialProc();			
			OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {
            
            MenuCross();
            
            }

				break;
			
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
		
			if(OSD_SubMenuCur == 0xff)
				return;

		
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				if(GetOSDMSG(OSD_SubMenuCur)==1&&GET_OSD_ENGER()==_OFF&&GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE){
					OsdDispDisableOsd();
					OsdDispOsdMessageEngerConsumption();
				}else if(GetOSDMSG(OSD_SubMenuCur)==2&&GET_OSD_ENGER()==_OFF)
				{
					OsdDispDisableOsd();
					OsdDispOsdMessageEngerConsumption();
				}
				else
#endif
{
			switch(GetOsdShowType(OSD_SubMenuCur))
			{
				case _TYPE_SLIDER:
#if(_CUSTOM_TYPE == _FKX_CUSTOMER)
                    OsdDispSliderAndNumber(1, OSD_SubMenuCur, GetOsdValue(OSD_SubMenuCur));		
					
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_HOTKEY_SILDER_START*12,1*18,(_HOTKEY_SILDER_START+(GET_SILDER_PERCENT(OSD_SubMenuCur)))*12+1,1*18+18,  _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
#else

					OsdDispSliderAndNumber(1, OSD_SubMenuCur, GetOsdValue(OSD_SubMenuCur));		
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_HOTKEY_SILDER_START*12,1*18,(_HOTKEY_SILDER_START+(GET_SILDER_PERCENT(OSD_SubMenuCur)))*12+1,1*18+18,  _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
#endif
						break;
			
				case _TYPE_ARROW:
					
					OsdFuncAdjHotKey();			
#if _RUSSIAN_SUPPORT
						OsdFuncClearOsd(_HOTKEY_ROW_START, 13, 17 , 1);
#else
						OsdFuncClearOsd(_HOTKEY_ROW_START, _HOTKEY_SLIDER_COL, 8 , 1);			
#endif


//						RTDOsdTableFuncPutStringProp(_HOTKEY_ROW_START, _HOTKEY_SLIDER_COL, _PFONT_PAGE_ITEM_1, OSD_SubMenuCur, GetOsdValue(OSD_SubMenuCur), COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
                    RTDOsdTableFuncPutStringProp(_HOTKEY_ROW_START, _HOTKEY_SLIDER_COL, _PFONT_PAGE_ITEM_1, OSD_SubMenuCur, GetOsdValue(OSD_SubMenuCur), COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());


						break;
			
				case _TYPE_SUBMENU:	
					
					OsdFuncAdjHotKey(); 		
					OsdFuncClearOsd(_HOTKEY_ROW_START, _HOTKEY_SLIDER_COL+1, 12 , 1);					 
					RTDOsdTableFuncPutStringCenter(_HOTKEY_ROW_START, _HOTKEY_SLIDER_COL+1, _HOTKEY_SLIDER_COL+12, _PFONT_PAGE_ITEM_1 , OSD_SubMenuCur,  GetOsdValue(OSD_SubMenuCur), COLOR(_COLOR_MENU_FONT, _CP_BG), 0, 0);
						break;
							
				default :
					break;	
			
			}
			break;

		default:
			break;
	}
		}
}

void MENU_HOT_KEY_LOS1(void)
{

	switch(GET_KEYMESSAGE())
	{
		case _EXIT_KEY_MESSAGE:	
			Cross_flag = 0;

			OsdDispDisableOsd();		
			break;
		case _MENU_KEY_MESSAGE: 
			Cross_flag = 0;

			OsdDispDisableOsd();		
				break;
			
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
			SET_OSD_CROSS_HAIR_TYPE1(OsdDisplayDetOverRange(GET_OSD_CROSS_HAIR_TYPE1() ,3 ,0 , _ON));
					
#if(_OSD_CROSS_SMALL)
					
					if(0 == GET_OSD_CROSS_HAIR_TYPE1())
					OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON_SMALL0, COLOR(_CP_RED, _CP_BG),0);
					else if(1 == GET_OSD_CROSS_HAIR_TYPE1())
					OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON_SMALL0, COLOR(_CP_GREEN, _CP_BG),0);
					else if(2 == GET_OSD_CROSS_HAIR_TYPE1())
					OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1_SMALL1, COLOR(_CP_GREEN, _CP_BG),0);
					else
					OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1_SMALL2, COLOR(_CP_GREEN, _CP_BG),0);
					
					OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
						 OsdFuncEnableOsd();
					
					
					
#else
									if(0 == GET_OSD_CROSS_HAIR_TYPE1())
									OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON, COLOR(_CP_RED, _CP_BG),0);
									else if(1 == GET_OSD_CROSS_HAIR_TYPE1())
									OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1, COLOR(_CP_RED, _CP_BG),0);
									else if(2 == GET_OSD_CROSS_HAIR_TYPE1())
									OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON, COLOR(_CP_GREEN, _CP_BG),0);
									else
									OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1, COLOR(_CP_GREEN, _CP_BG),0);
					
									OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
										 OsdFuncEnableOsd();
					
#endif

            RTDNVRamSaveOSDData();
				break;
					
		default :
			break;				
	}
}


#if 1//(_LONG_PRESS_MENU_LOCK_OSD_ENABLE||_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE)
void MENU_FUN_LOCK_OSD(void)
{

	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE:
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:

                OsdDispDisableOsd();		

			break;
	
		default:
			break;
	}
}
#endif


#if _ENABLE_ENERGE_NOTICE_MENU
void MENU_SHOW_ENERGE_MENU(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 		
		    if(g_usAdjustValue == 1)
		     {
             	SET_OSD_ENERGE_NOTICE_FLAG(_OFF);
             	RTDNVRamSaveOSDData();
				ScalerOsdWindowDisable(_OSD_WINDOW_4_8);// henry 
			 
			 	OsdDispMainMenu();
			 }
			else
			 	OsdDispDisableOsd();
			break;

		case _LEFT_KEY_MESSAGE: 		
		case _RIGHT_KEY_MESSAGE:
             if(g_usAdjustValue == 1)
             {
			  	g_usAdjustValue = 0;
			  	OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, g_ucOsdWidth*6, 108, g_ucOsdWidth*12, 126, _CP_BLACK, _COLOR_MENU_FONT_SELECT, _CP_BLACK, _ON);
             }
			 else
			 {
			  	g_usAdjustValue = 1;
              	OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, 0, 108, g_ucOsdWidth*6, 126, _CP_BLACK, _COLOR_MENU_FONT_SELECT, _CP_BLACK, _ON);
			 }
			
			break;

		case _EXIT_KEY_MESSAGE:
			 OsdDispDisableOsd();
			break;
	}
}
#endif

void MENU_HOT_KEY_SOURCE(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			
			if(g_usBackupValue == GET_OSD_INPUT_PORT_OSD_ITEM())
            {
            OsdDispDisableOsd();
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }	

             }
			else
			{	
#if(_DEF_2795E06)
				g_SouceSelect = 0;
#endif
				SET_FORCE_POW_SAV_STATUS(_FALSE);
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
		
			#if(_SOURCE_AUTO_ON)
				if(GET_OSD_INPUT_PORT_OSD_ITEM() == _OSD_INPUT_AUTO)
				{
					SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
					
					if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
					{
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
				}
				else
				{		
					SysSourceSwitchInputPort(OsdFuncGetOsdItemFlag());
					SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
					if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
					{
						UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
				}
		#else					
				SysSourceSwitchInputPort(OsdFuncGetOsdItemFlag());
				SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
				if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
				   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				{
					UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				}						
		#endif				


			}
			
			break;
        case _EXIT_KEY_MESSAGE:
            OsdDispDisableOsd();    
            if(GET_OSD_CROSS_STATUS()==_ON)
            {

            MenuCross();

            }   
            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
            
            SET_OSD_INPUT_PORT_OSD_ITEM(OsdDisplayDetOverRangeRotation(GET_OSD_INPUT_PORT_OSD_ITEM() , _OSD_INPUT_AMOUNT-1, 0, _ON));

#if(_OSD_BLACK_TYPE) 	//��ɫ
            OsdWindowDrawingHighlight(_OSD_WINDOW_4_1, 0, (3+GET_OSD_INPUT_PORT_OSD_ITEM()*2)*18, 12*12, (4+GET_OSD_INPUT_PORT_OSD_ITEM()*2)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE); 
#else
            OsdWindowDrawingHighlight(_OSD_WINDOW_4_1, 0, (1+GET_OSD_INPUT_PORT_OSD_ITEM()*2)*18, 12*12, (2+GET_OSD_INPUT_PORT_OSD_ITEM()*2)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE); 
#endif
            break;
	}
}

void MENU_HOT_KEY_LOS2(void)
{

	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE:

			OsdDispDisableOsd();		
				break;
			
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
			SET_OSD_CROSS_HAIR_TYPE2(OsdDisplayDetOverRange(GET_OSD_CROSS_HAIR_TYPE2() ,5 ,0 , _ON));
					
			if(0 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON1, COLOR(_CP_YELLOW, _CP_BG),0);
			else if(1 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON2, COLOR(_CP_RED, _CP_BG),0);
			else if(2 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON3, COLOR(_CP_YELLOW, _CP_BG),0);
			else if(3 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON4, COLOR(_CP_RED, _CP_BG),0);
			else if(4 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON5, COLOR(_CP_YELLOW, _CP_BG),0);
			else if(5 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON6, COLOR(_CP_RED, _CP_BG),0);

            RTDNVRamSaveOSDData();
				break;
					
		default :
			break;				
	}
}

#if(_DEF_STA_SIX_COLOR)//_MENU_FUN_SAT_STATE

void MENU_FUN_HUE_SIX_COLOR(void)
{
    BYTE i = 0;
    switch(GET_KEYMESSAGE())
    {
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
		   OsdDispSliderAndNumber(_ITEM_1_ROW+(GET_OSD_STATE()-_MENU_FUN_HUE_RED)*2,(GET_OSD_STATE()),GetOsdValue(GET_OSD_STATE()));
		   OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GET_OSD_STATE()-_MENU_FUN_HUE_RED))*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(GET_OSD_STATE()))*12, ((_ITEM_1_ROW+2*(GET_OSD_STATE()-_MENU_FUN_HUE_RED))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);		
		   ScalerTimerDelayXms(80);//����ʱ�ᵼ���ٶ�̫��,���������������ٶȲ�һ��
			break;

		
        case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE:
			//�����ǰ������
			OsdFuncClearOsd(ROW(_ITEM_1_ROW+GET_HUE_STATE()*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));
			for(i = 0; i < 6;i++)//������ѡ�����´�ӡ
			{
				RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i,_MENU_FUN_SAT_STATE,i, COLOR(_COLOR_MENU_FONT, _CP_BG),_ENGLISH);
			}
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+GET_HUE_STATE()*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+GET_HUE_STATE()*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*GET_HUE_STATE()))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*GET_HUE_STATE())+1)*18+7, _COLOR_WINDOW_BG);
			SET_OSD_STATE(_MENU_FUN_HUE_STATE);
	}
}


void MENU_FUN_STA_SIX_COLOR(void)
{
    BYTE i = 0;
    switch(GET_KEYMESSAGE())
    {
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
		   OsdDispSliderAndNumber(_ITEM_1_ROW+(GET_OSD_STATE()-_MENU_FUN_SAT_RED)*2,(GET_OSD_STATE()),GetOsdValue(GET_OSD_STATE()));
		   OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GET_OSD_STATE()-_MENU_FUN_SAT_RED))*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(GET_OSD_STATE()))*12, ((_ITEM_1_ROW+2*(GET_OSD_STATE()-_MENU_FUN_SAT_RED))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);		
		   ScalerTimerDelayXms(80);	//����ʱ�ᵼ���ٶ�̫��,���������������ٶȲ�һ��
			break;

		
        case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE:
			//�����ǰ������
			OsdFuncClearOsd(ROW(_ITEM_1_ROW+GET_SAT_STATE()*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));
			for(i = 0; i < 6;i++)//������ѡ�����´�ӡ
			{
				RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i,_MENU_FUN_SAT_STATE,i, COLOR(_COLOR_MENU_FONT, _CP_BG),_ENGLISH);
			}
			
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+GET_SAT_STATE()*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+GET_SAT_STATE()*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*GET_SAT_STATE()))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*GET_SAT_STATE())+1)*18+7, _COLOR_WINDOW_BG);
			SET_OSD_STATE(_MENU_FUN_SAT_STATE);
	}
}
#endif




void MENU_FUN_RGB(void)
{
    BYTE i = 0;
    DebugMessageOsd("MENU_FUN_RGB_FUN",GET_OSD_STATE());
#if(_DEF_CT_JX)

#if 1
	BYTE CT_DATA_ORDER[_CT_COLORTEMP_AMOUNT+1];
	CT_DATA_ORDER[_CT_9300] = 0;
	CT_DATA_ORDER[_CT_7500] = 2;
	CT_DATA_ORDER[_CT_6500] = 4;
	CT_DATA_ORDER[_CT_5800] = 5;
	CT_DATA_ORDER[_CT_SRGB] = _OFF;
	CT_DATA_ORDER[_CT_USER] = 6;
	CT_DATA_ORDER[_CT_7000] = 3;
	CT_DATA_ORDER[_CT_8000] = 1;
	CT_DATA_ORDER[_CT_GAMMA18] = 6;
	CT_DATA_ORDER[_CT_GAMMA20] = 6;
	CT_DATA_ORDER[_CT_GAMMA22] = 6;
	CT_DATA_ORDER[_CT_GAMMA24] = 6;
	CT_DATA_ORDER[_CT_GAMMA26] = 6;
#else
	BYTE CT_DATA_ORDER[_CT_COLORTEMP_AMOUNT+1] =
	{
		0,//_CT_9300
		2,//_CT_7500
		4,//_CT_6500
		5,//_CT_5800
		_OFF,//_CT_SRGB
		6,//_CT_USER
		3,//_CT_7000
		1,//_CT_8000
		6,//_CT_GAMMA18
		6,//_CT_GAMMA20
		6,//_CT_GAMMA22
		6,//_CT_GAMMA24
		6//_CT_GAMMA26
	};
#endif

#endif  //(_DEF_CT_JX)


	
    switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE: 
			for(i = 0; i<3; i++)
			OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));
             SET_OSD_STATE(_MENU_FUN_R+g_usBackupValue);
			 OsdDispSliderAndNumber(_ITEM_1_ROW+g_usBackupValue*2,_MENU_FUN_R+g_usBackupValue,GetOsdValue(_MENU_FUN_R+g_usBackupValue));
			 OsdFontPut1BitTable(ROW(_ITEM_1_ROW+g_usBackupValue*2), COL(_ITEM_3_COL+_ITEM_SLIDER_OFFSET), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
			 OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*g_usBackupValue)*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(_MENU_FUN_R+g_usBackupValue))*12, ((_ITEM_1_ROW+2*g_usBackupValue)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			 OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*g_usBackupValue))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*g_usBackupValue)+1)*18+7, _COLOR_WINDOW_BG);
			 g_usAdjustValue = GetOsdValue(_MENU_FUN_R+g_usBackupValue);
			break;
			
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
		    g_usBackupValue = (BYTE)(OsdDisplayDetOverRangeRotation(g_usBackupValue , 2, 0, _ON));
            OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+g_usBackupValue*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+g_usBackupValue*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*g_usBackupValue))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*g_usBackupValue)+1)*18+7, _COLOR_WINDOW_BG);	
			break;

			 

		case _EXIT_KEY_MESSAGE:
             SET_OSD_STATE(_MENU_FUN_COLORTEMP);
			 g_usAdjustValue = _CT_USER;
             for(i = 0; i<3; i++)
		     OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));

#if(_DEF_CT_JX)
			for(i = _CT_9300; i <= _CT_8000; i++)
			{
				if(i != _CT_SRGB)
				{
					RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+CT_DATA_ORDER[i]*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + CT_DATA_ORDER[i], _MENU_FUN_COLORTEMP,i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
				}
			}
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+CT_DATA_ORDER[_CT_USER]*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+CT_DATA_ORDER[_CT_USER]*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*CT_DATA_ORDER[_CT_USER]))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*CT_DATA_ORDER[_CT_USER])+1)*18+7, _COLOR_WINDOW_BG);
#else
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+0*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 0, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  0, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+1*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 1, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  1, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
		    RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+2*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 2, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  2, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+3*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 3, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  3, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());

			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+3*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+3*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*3))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*3)+1)*18+7, _COLOR_WINDOW_BG);

#endif
			 break;
					
		default :
			break;				
	}
}




void MENU_FUN_RGB_ADJUST(void)
{

    BYTE i = 0;
    DebugMessageOsd("MENU_FUN_RGB_ADJUST",1);
    switch(GET_KEYMESSAGE())
	{	
		case _RIGHT_KEY_MESSAGE:
		case _LEFT_KEY_MESSAGE:
		   OsdDispSliderAndNumber(_ITEM_1_ROW+(GET_OSD_STATE()-_MENU_FUN_R)*2,(GET_OSD_STATE()),GetOsdValue(GET_OSD_STATE()));
		   OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GET_OSD_STATE()-_MENU_FUN_R))*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(GET_OSD_STATE()))*12, ((_ITEM_1_ROW+2*(GET_OSD_STATE()-_MENU_FUN_R))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);		
			break;

			 
        case _MENU_KEY_MESSAGE: 
		case _EXIT_KEY_MESSAGE:
			 g_usBackupValue = (GET_OSD_STATE()-_MENU_FUN_R);
             SET_OSD_STATE(_MENU_FUN_RGB);
			 
             for(i = 0; i<_HENG_COUNT; i++)
		     OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));

			 RTDOsdTableFuncPutStringProp(_ITEM_1_ROW, _ITEM_3_COL, _PFONT_PAGE_ITEM_1, _OSD_STRING_RGB,  0, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			 RTDOsdTableFuncPutStringProp(_ITEM_2_ROW, _ITEM_3_COL, _PFONT_PAGE_ITEM_2, _OSD_STRING_RGB,  1, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			 RTDOsdTableFuncPutStringProp(_ITEM_3_ROW, _ITEM_3_COL, _PFONT_PAGE_ITEM_3, _OSD_STRING_RGB,  2, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
		         
			 OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+g_usBackupValue*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+g_usBackupValue*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			 OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*g_usBackupValue))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*g_usBackupValue)+1)*18+7, _COLOR_WINDOW_BG);
			 break;
					
		default :
			break;				
	}
}


void MEMU_MESSAGE()
{	
	
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
	if(!GET_OSD_FACTORY_MODE()&&GET_OSD_AUTO_POWEROFF())
	{
    g_usPowerDownCount = GET_OSD_AUTO_POWEROFF()*60;
	ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_AUTO_POWER_DOWN); 
	}
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdDispDisableOsd();
}

#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)

void MENU_ENGER_CONSUMPTION(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE: 
		if(GET_OSD_ENGER()==_ON)
		{
			if(g_ucBacktoHotKeyState)
				RTDOsdDispHotkeyFuncAdjust(OSD_SubMenuCur-_MENU_FUN_BACKLIGHT);
			else
				OsdDispEngerMainMenu();
		}
		else

		{
			OsdDispDisableOsd();
		}
           break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:

		g_usAdjustValue = GET_OSD_ENGER();// GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);

		g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 1, 0, _ON);

		SET_OSD_ENGER(g_usAdjustValue);
// 	{
//		OsdFuncClearOsd(5, (11), 11 , 1);					 
//		RTDOsdTableFuncPutStringCenter(ROW(9),COL(4),COL(8), _PFONT_PAGE_ITEM_1, _OSD_YES_NO, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET,GET_OSD_LANGUAGE());		
//      RTDOsdTableFuncPutStringCenter(ROW(9),COL(14),COL(18), _PFONT_PAGE_ITEM_1, _OSD_YES_NO, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET,GET_OSD_LANGUAGE());      
// 	}
        
        OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,XSTART(24*12-GET_OSD_ENGER()*15*12), YSTART(9*18), XEND(29*12-GET_OSD_ENGER()*15*12), YEND(10*18), _COLOR_WINDOW_BG, _CP_RED, _CP_BG, _ENABLE); 
//        (_OSD_WINDOW_5, XSTART(6*12+GET_OSD_ENGER()*12*12), YSTART(9*18), XEND(10*12+GET_OSD_ENGER()*12*12), YEND(10*18), _CP_RED);    

		break;



          case _EXIT_KEY_MESSAGE:
	 
	    OsdDispDisableOsd();

		break;

        default:
            break;
    }
}

#endif

void MENU_FUN_NULL(void)//����һЩ��ʱ���õĺ������ֲ��붯kernel���֣���ֹ������������
{
	BYTE test = 0;
	
	if(test == 1)
	{
#if(_SIX_COLOR_SUPPORT == _ON)		
		ScalerColorSixColorInitial();
		ScalerColorSixColorAdjust(0,0,0);
#endif
		OsdFuncChangeColor1Bit(0,0,0,0,0,0);
		ScalerOsdDataPort(0);
		ScalerOsdSramAddressCount(0,0,_OSD_BYTE0);	
		UserInterfaceGetNVRamDataStatus(_CHECK_ADC_SAVE);		
#if(_FREESYNC_SUPPORT == _ON)
		ScalerFreeSyncGetFreeSyncInfo(_NO_INPUT_PORT,_SPD_INFO_OUI);
#endif
#if((_HDMI_HDR10_SUPPORT == _ON) && (_D3_INPUT_PORT_TYPE != _D3_HDMI_PORT) &&(_HDMI_MAC_PAGE72_USE == _ON))
		ScalerTMDSRx3GetHDR10Data(pData);
#endif
		OsdFontPut2BitTable(0,0,0,0,0,0,0);
	}
}


code void (*OperationTable[])(void) =
{
#if(_NAVIGAT_MENU_SURPPORT)
	MenuNavigatNone,
#endif
    MenuNone,
    
	MenuInputSouce,
	MenuBri_Con,
	MenuColorSetting,
	MenuPQSetting,
	MenuDisplay,  //7

#if(_OSD_7PAGE || _DEF_PAGE8)
    MenAudio,
#endif
	MenuOSD,
	MenuOther,
	MenuFactory, //11

// �����˵�	
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //17
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif

	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //23
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif
	
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //29
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif
	
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //35
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif


#if(_OSD_7PAGE || _DEF_PAGE8)

    OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //41
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif
#endif
	
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //47
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif
	
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,
	OSDSubMenuMove,  //53
#if(_DEF_PAGE8)
	OSDSubMenuMove,  //17
#endif

	MENU_FUN_COMMON,//MENU_FUN_BACKLIGHT,	
	MENU_FUN_COMMON,//MENU_FUN_CONTRAST,
	MENU_FUN_COMMON,//MENU_FUN_BRIGHTNESS,
	MENU_FUN_COMMON,//MENU_FUN_SHARPNESS,
	MENU_FUN_COMMON,//MENU_FUN_ECO,
	MENU_FUN_COMMON,//MENU_FUN_DCR,
	MENU_FUN_COMMON,//MENU_FUN_HDR,  //60

	MENU_FUN_COMMON,//_MENU_FUN_VGA_HPOSITON,	
	MENU_FUN_COMMON,//_MENU_FUN_VGA_VPOSITON,	
	MENU_FUN_COMMON,//_MENU_FUN_VGA_CLK, 
	MENU_FUN_COMMON,//_MENU_FUN_VGA_PHASE,
	MENU_FUN_COMMON,//_MENU_FUN_ASPECT,  //65

	
	MENU_FUN_COMMON,//_MENU_FUN_COLORTEMP,	
	MENU_FUN_RGB_ADJUST,
	MENU_FUN_RGB_ADJUST,
	MENU_FUN_RGB_ADJUST,
	MENU_FUN_COMMON,//_MENU_FUN_LANGUAGE
	MENU_FUN_COMMON,//_MENU_FUN_OSD_HPOSITON, 
	MENU_FUN_COMMON,//_MENU_FUN_OSD_VPOSITON, 
	MENU_FUN_COMMON,//_MENU_FUN_OSD_TIME, 
	MENU_FUN_COMMON,//_MENU_FUN_OSD_TRANS, //74

	
	MENU_FUN_NULL,//MENU_FUN_AUTO_ADJUST,	
	MENU_FUN_NULL,//MENU_FUN_AUTO_COLOR,	
	MENU_FUN_NULL,//MENU_FUN_RESET,	//77

	MENU_FUN_INPUT_SOURCE,//_MENU_FUN_SIGNAL,	
	MENU_FUN_COMMON,//_MENU_FUN_LOWBLUE,		
	MENU_FUN_COMMON,//_MENU_FUN_AUDOIMUTE,
	MENU_FUN_COMMON,//_MENU_FUN_AUDOIVOLUME,  //81
	
	#if _FREESYNC_SUPPORT
	MENU_FUN_COMMON,//_MENU_FUN_FREESYNC,
	#endif
	MENU_FUN_COMMON,//_MENU_FUN_OD,
	MENU_FUN_COMMON,//_MENU_FUN_POWER_OFF,
	MENU_FUN_COMMON,//_MENU_FUN_LED,  //85
		
	MENU_FUN_COMMON,//_MENU_FUN_FLICKER_FREE,
	MENU_FUN_COMMON,//_MENU_FUN_MPRT,
	MENU_FUN_COMMON,//_MENU_FUN_GAMMA,	
	MENU_FUN_COMMON,//_MENU_FUN_COLORGAMUT,
	MENU_FUN_COMMON,//_MENU_FUN_SATURATION
	MENU_FUN_COMMON,//_MENU_FUN_OVERCLOCK, //91
	
	MENU_FUN_COMMON,//_MENU_FUN_HUE,	
	MENU_FUN_COMMON,//_MENU_FUN_DCC,
	
   MENU_FUN_COMMON,//_MENU_FUN_FV_INFORMATION
   MENU_FUN_COMMON,//_MENU_FUN_DDCCI,
   
	MENU_FUN_COMMON,//_MENU_FUN_DP_VER  //96
	MENU_FUN_COMMON,//_MENU_FUN_OSD_RORATE,
	MENU_FUN_COMMON,//_MENU_FUN_VIVID
	MENU_FUN_COMMON,//_MENU_FUN_AUDIO_SOURCE
	MENU_FUN_COMMON,//_MENU_FUN_CHAOPING_TISHI
	MENU_FUN_COMMON,//_MENU_FUN_KVM
	MENU_FUN_COMMON,//_MENU_FUN_HDR_COLOR
    MENU_FUN_COMMON,//_MENU_FUN_CROSS,
	MENU_FUN_COMMON,//_MENU_FUN_SAVING_MODE hh

#if(_DEF_HOTKEY_REPLACE)
   	MENU_FUN_COMMON,//_MENU_FUN_HOT_REPLACE_LEFT
    MENU_FUN_COMMON,//_MENU_FUN_HOT_REPLACE_RIGHT
    MENU_FUN_COMMON,//_MENU_FUN_HOT_REPLACE_EXIT
#endif

#if(_DEF_STA_SIX_COLOR)
	MENU_FUN_COMMON,//MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_STATE
	MENU_FUN_COMMON, //_MENU_FUN_HUE_STATE

	MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_RED
	MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_GREEN
	MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_BLUE
	MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_CYAN
	MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_MAGENTA
	MENU_FUN_STA_SIX_COLOR, //_MENU_FUN_SAT_YELLOW

	MENU_FUN_HUE_SIX_COLOR, //_MENU_FUN_HUE_RED
	MENU_FUN_HUE_SIX_COLOR, //_MENU_FUN_HUE_GREEN
	MENU_FUN_HUE_SIX_COLOR, //_MENU_FUN_HUE_BLUE
	MENU_FUN_HUE_SIX_COLOR, //_MENU_FUN_HUE_CYAN
	MENU_FUN_HUE_SIX_COLOR, //_MENU_FUN_HUE_MAGENTA
	MENU_FUN_HUE_SIX_COLOR, //_MENU_FUN_HUE_YELLOW

#endif

#if(_DEF_OPPOSITE_DCR)
	MENU_FUN_COMMON,//_MENU_FUN_DCR_OPPOSITE
#endif
#if(_LED_EFFECT_TJMODE14)
        MENU_FUN_COMMON,//_MENU_FUN_LIGHTMODE,//turn off monitor 
        MENU_FUN_COMMON,//_MENU_FUN_COLOR,//turn off monitor 
#endif

	MENU_FUN_COMMON,//_MENU_FUN_HOTLEFT,
	MENU_FUN_COMMON,//_MENU_FUN_HOTRIGHT,   //102
	MENU_FUN_RGB,//_MENU_FUN_RGB
	MENU_FUN_NULL,  //_MENU_NULL
/***********************Spacil Hotkey*****************************/
	MENU_HOT_KEY_LOS1,//_HOT_KEY_LOS_TYPE1
	MENU_HOT_KEY_LOS2,//_HOT_KEY_LOS_TYPE2  //106
	MENU_HOT_KEY_SOURCE,//_MENU_FUN_SOURCE_HOTKEY

#if _ENABLE_ENERGE_NOTICE_MENU
	MENU_SHOW_ENERGE_MENU,//_MENU_FUN_SHOW_ENERGE_MENU
#endif

#if 1//_LONG_PRESS_MENU_LOCK_OSD_ENABLE
	MENU_FUN_LOCK_OSD,// _MENU_FUN_LOCK_MENU
#endif
	
#if 1//_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
	MENU_FUN_LOCK_OSD,// _MENU_FUN_POWERKEY_LOCK_MENU
#endif

/*****************************************************************/
	MEMU_MESSAGE,//_MENU_MESSAGE //111
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
	MENU_ENGER_CONSUMPTION,//_MENU_ENGER_CONSUMPTION
#endif

	MENU_HOT_KEY_FUNC,//_MENU_HOT_KEY_FUNC  //123
	MENU_FUN_NULL,//_MENU_END, 
};

#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
