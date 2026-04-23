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
// ID Code      : RTD2014Key.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_KEY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)
code char KeyFlag[] = {"This is Keyboardflag Flag!"}; 
BYTE code KeyDefault[10] = 
{
	MENU_KEY,	
	POWER_KEY,
	EXIT_KEY,
	RIGHT_KEY,
	LEFT_KEY,
	
	MENU_REG,	
	POWER_REG,
	EXIT_REG,
	RIGHT_REG,
	LEFT_REG,
};

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Key Mask
//--------------------------------------------------
#define _RELEASE_KEY_MASK                           0x00
#define _POWER_KEY_MASK                             0x01
#define _MENU_KEY_MASK                              0x02
#define _RIGHT_KEY_MASK                             0x04
#define _LEFT_KEY_MASK                              0x08
#define _EXIT_KEY_MASK                              0x10
#define _UP_KEY_MASK                                0x20
#define _DOWN_KEY_MASK                              0x40
#define _OK_KEY_MASK                                0x80


#define _POWER_RIGHT_KEY_MASK                       (_POWER_KEY_MASK | _RIGHT_KEY_MASK)
#define _POWER_MENU_KEY_MASK                        (_POWER_KEY_MASK | _MENU_KEY_MASK)
#define _POWER_LEFT_RIGHT_KEY_MASK                  (_POWER_KEY_MASK | _LEFT_KEY_MASK | _RIGHT_KEY_MASK)

//--------------------------------------------------
// Definitions of IR Key Code
//--------------------------------------------------
#if(_IR_SUPPORT == _IR_HW_SUPPORT)
#if(_IR_PROTOCAL == _IR_NEC_DTV328)
#define _IR_CODE_KEY_POWER                          0xA0FB
#define _IR_CODE_KEY_MENU                           0xAAFB
#define _IR_CODE_KEY_RIGHT                          0xEBFB
#define _IR_CODE_KEY_LEFT                           0xA9FB
#define _IR_CODE_KEY_EXIT                           0xEFFB

#elif(_IR_PROTOCAL == _IR_HUIXIONG_CROSSOVER_KEY14))
#define _IR_CODE_KEY_POWER                          0xB946
#define _IR_CODE_KEY_MENU                           0xF10E
#define _IR_CODE_KEY_RIGHT                          0xB748
#define _IR_CODE_KEY_LEFT                           0xB24D
#define _IR_CODE_KEY_EXIT                           0xF20D
#define _IR_CODE_KEY_UP								0xB649
#define _IR_CODE_KEY_DOWN							0xB14E
#define _IR_CODE_KEY_OK								0xB54A
#define _IR_CODE_KEY_9								0xA758
#define _IR_CODE_KEY_10								0xA05F
#define _IR_CODE_KEY_11								0xED12
#define _IR_CODE_KEY_12								0xA15E
#define _IR_CODE_KEY_13								0xA25D
#define _IR_CODE_KEY_14								0xA35C

#elif(_IR_PROTOCAL == _IR_SONY_B102P)
#define _IR_CODE_KEY_POWER                          0x0950
#define _IR_CODE_KEY_MENU                           0x0A50
#define _IR_CODE_KEY_RIGHT                          0x0920
#define _IR_CODE_KEY_LEFT                           0x0930
#define _IR_CODE_KEY_EXIT                           0x0940

#elif(_IR_PROTOCAL == _IR_PHILIPS_RC6)
#define _IR_CODE_KEY_POWER                          0x000C
#define _IR_CODE_KEY_MENU                           0x005C
#define _IR_CODE_KEY_RIGHT                          0x005B
#define _IR_CODE_KEY_LEFT                           0x005A
#define _IR_CODE_KEY_EXIT                           0x000A
#elif(_IR_PROTOCAL == _IR_DATONG_MT1)
#define _IR_CODE_KEY_POWER                          0xA05F
#define _IR_CODE_KEY_MENU                           0xA055
#define _IR_CODE_KEY_RIGHT                          0xA014
#define _IR_CODE_KEY_LEFT                           0xA056
#define _IR_CODE_KEY_EXIT                           0xA01A
#define _IR_CODE_KEY_UP								0xA059
#define _IR_CODE_KEY_DOWN							0xA051
#define _IR_CODE_KEY_FUN1							0xA0EF
#define _IR_CODE_KEY_FUN2							0xA052
#define _IR_CODE_KEY_FUN3							0xA013
#define _IR_CODE_KEY_VOLUME_INCREASE				0xA05D
#define _IR_CODE_KEY_VOLUME_Reduce					0xA040

#endif
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
BYTE g_ucKeyStatePrev;
BYTE g_ucKeyStateCurr;
BYTE g_ucKeyStateSkip;

BYTE IROsdOptionTypes = _OFF;

#if(_AD_KEY_SUPPORT == _ON)
BYTE g_ucBackupKeyState = 0xFF;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserInterfaceKeyHandler(void);
void RTDKeyInitial(void);
bit RTDKeyScanReady(void);
BYTE RTDKeyScan(void);
bit RTDKeyPowerKeyProc(void);
void RTDKeyPowerKeyMix(void);
void RTDKeyMessageProc(void);
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg);

bit RTDKeySpecialProc(BYTE ucKeyMask);
void RTDKeyHoldKeyTimerCancel(void);
void RTDKeyHoldKeyCheck(void);


#if((_IR_SUPPORT == _IR_HW_SUPPORT)||(_IR_VIRTUAL==_ON))
BYTE RTDIRKeyScan(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Key Handler, executed in the main loop.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceKeyHandler(void)
{
    // Skip key status update for tool
    if(g_ucKeyStateSkip != 0)
    {
        g_ucKeyStateSkip = 0;
        return;
    }

    // Clear the key message
    if(GET_KEYMESSAGE() != _HOLD_KEY_MESSAGE)
    {
        SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
    }

    if(RTDKeyScanReady() == _TRUE)
    {
        // Store previous key state
        g_ucKeyStatePrev = g_ucKeyStateCurr;

        // Get current key state
        g_ucKeyStateCurr = RTDKeyScan();

#if(_DEF_REAL_TIME_HZ)
if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
		{
			if(GET_OSD_STATE() != _MENU_NONE)
			{
				SET_OSD_HZ_DISPLAYSTATUS(0);
			}
			else if(GET_OSD_FV_INFORMATION() && ((GET_OSD_HZ_DISPLAYSTATUS()&((BYTE)(~_BIT0))) != (GET_INPUT_TIMING_VFREQ()/10)) && (GET_OSD_HZ_DISPLAYSTATUS() & _BIT0))
			{
				if((((GET_INPUT_TIMING_VFREQ()/10)-GET_OSD_HZ_DISPLAYSTATUS()) < 5 && ((GET_INPUT_TIMING_VFREQ()/10)-GET_OSD_HZ_DISPLAYSTATUS()) >= 0) || (((GET_OSD_HZ_DISPLAYSTATUS()/10)-GET_INPUT_TIMING_VFREQ()) < 5 && ((GET_OSD_HZ_DISPLAYSTATUS()/10)-GET_INPUT_TIMING_VFREQ()) >= 0))
					g_ucKeyStateCurr = g_ucKeyStateCurr;
				else
					ScalerTimerActiveTimerEvent(SEC(1), _USER_REAL_TIME_REFRESH_RATE);
			}
		}
#endif
		if((SysPowerGetPowerStatus() == _POWER_STATUS_AC_ON) && (RTDKeyScan() == _MENU_KEY_MASK))
		{
			SET_OSD_FACTORY_MODE(_ON);				
			SET_OSD_BURNING_MODE(_ON);
			RTDNVRamSaveOSDData();
		}

#if(_OSD_5_KEY_SUPPROT)		
        if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
        {
            if(RTDKeyPowerKeyProc() == _TRUE)
            {
                return;
            }
        }
#else

#if _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
		if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
		{
    		
            RTDKeyMessageConvert(_MENU_KEY_MASK, _POWER_KEY_MASK);
            CLR_KEYREPEATENABLE();
			if(RTDKeyPowerKeyProc() == _TRUE)
			{
				return;
			}
		}
#else
		// Power key process, return if power key is pressed
		if(RTDKeyPowerKeyProc() == _TRUE)
		{
			return;
		}
#endif

#endif
        // Convert key state to key message, store in (ucKeyNotify)
        RTDKeyMessageProc();
    }
}

//--------------------------------------------------
// Description  : Key intial.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyInitial(void)
{
    CLR_KEYSCANREADY();
    CLR_KEYSCANSTART();
}

//--------------------------------------------------
// Description  : Key scan ready process. We wait 0.02 sec in order to keep the keypad debounce
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit RTDKeyScanReady(void)
{
    if(((GET_KEYSCANSTART() == _TRUE) &&
       (GET_KEYSCANREADY() == _TRUE))|| (SysPowerGetPowerStatus() == _POWER_STATUS_AC_ON))
    {
        return _TRUE;
    }
    else if(GET_KEYSCANSTART() == _FALSE)
    {
        // Set Scan start flag.
        SET_KEYSCANSTART();

        // SET_KEYSCANREADY();
        // Wait 0.02 sec in order to keep the keypad debounce
        ScalerTimerReactiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_KEY_SCAN_READY);

        return _FALSE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get key status
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
BYTE RTDKeyScan(void)
{
    BYTE ucKeyState = 0;
    BYTE ucVoltage0 = 0;
    BYTE ucVoltage1 = 0;
    BYTE ucVoltage2 = 0;
    BYTE ucVoltage3 = 0;
	BYTE retry_Key=0,temp=0;


#if(_AD_KEY_SUPPORT == _ON)
    ucVoltage0 = PCB_ADKEY0();
    ucVoltage1 = PCB_ADKEY1();
    ucVoltage2 = PCB_ADKEY2();
    ucVoltage3 = PCB_ADKEY3();

	retry_Key=3;
	while(retry_Key)
	{
		ucVoltage0 = PCB_ADKEY0();
		ScalerTimerDelayXms(3);
		temp = PCB_ADKEY0();
		if(abs(ucVoltage0-temp)<5)
			break;
		retry_Key--;
	}

	retry_Key=3;
	while(retry_Key)
	{
		ucVoltage1 = PCB_ADKEY1();
		ScalerTimerDelayXms(3);
		temp = PCB_ADKEY1();
		if(abs(ucVoltage1-temp)<5)
			break;
		retry_Key--;
	}

	retry_Key=3;
	while(retry_Key)
	{
		ucVoltage2 = PCB_ADKEY2();
		ScalerTimerDelayXms(3);
		temp = PCB_ADKEY2();
		if(abs(ucVoltage2-temp)<5)
			break;
		retry_Key--;
	}

	retry_Key=3;
	while(retry_Key)
	{
		ucVoltage3 = PCB_ADKEY3();
		ScalerTimerDelayXms(3);
		temp = PCB_ADKEY3();
		if(abs(ucVoltage3-temp)<5)
			break;
		retry_Key--;
	}


    PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);

    if(g_ucBackupKeyState == ucKeyState)
    {
        if(GET_KEYREPEATENABLE() != _ON)
        {
            RTDKeyInitial();
        }

        //return g_ucBackupKeyState;
    }
    else
    {
        g_ucBackupKeyState = ucKeyState;
        ucKeyState = 0;
    }

#else
    PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);
#endif // End of #if(_AD_KEY_SUPPORT == _ON)


#if((_IR_SUPPORT == _IR_HW_SUPPORT)||(_IR_VIRTUAL==_ON))
    if(ucKeyState == 0x00)
    {
        ucKeyState = RTDIRKeyScan();
    }
#endif // End of #if(_IR_SUPPORT == _IR_HW_SUPPORT)

    if(ucKeyState != 0)
    {
        RTDKeyInitial();
    }

    return ucKeyState;
}

//--------------------------------------------------
// Description  : Power key process
// Input Value  : None
// Output Value : Return _TRUE if power key is pressed
//--------------------------------------------------
bit RTDKeyPowerKeyProc(void)
{
    if((g_ucKeyStateCurr & _POWER_KEY_MASK) != 0)
    {
        if(((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & _POWER_KEY_MASK) != 0)
        {
            RTDKeyPowerKeyMix();

            if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
            {
            
				Cross_flag = 0;
                SET_OSD_STATE(_MENU_NONE);
                SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
				if(GET_OSD_FACTORY_MODE()==_OFF&&GET_OSD_AUTO_POWEROFF())
				{
					g_usPowerDownCount = GET_OSD_AUTO_POWEROFF() * 60;
					ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_AUTO_POWER_DOWN);
				}
            }
            else
            {
            
#if(_MPRT_SUPPORT == _ON)
				UserAdjustLowMotionBlurDisplay(_OFF);
#endif
				#if(_NAVIGAT_MENU_SURPPORT)			
				if(((GET_OSD_STATE() == _MENU_NONE))&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_OSD_FACTORY_MODE() == _OFF))
				{
					SET_OSD_STATE(_MENU_NAVIGAT_NONE);
					OsdDispNavigatMenu();			   
				}
				else if((GET_OSD_STATE() == _MENU_NAVIGAT_NONE)||(SysModeGetModeState() != _MODE_STATUS_ACTIVE) || (GET_OSD_FACTORY_MODE() == _ON))
				{
					SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);					
					SET_OSD_FACTORY_MODE(_OFF);
					SET_OSD_BURNING_MODE(_OFF);
					
					RTDNVRamSaveOSDData();
				}
					
				#else
				
					SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
				
					SET_BURNING_AUDIO_TEST(_OFF);	   
					if(GET_OSD_FACTORY_MODE())
					{
						SET_OSD_FACTORY_MODE(_OFF);					
						SET_OSD_BURNING_MODE(_OFF);
						
						SET_PANEL_BURN_TIME_HOUR(0);
						SET_PANEL_BURN_TIME_MIN(0);
						
						SET_PANEL_TIME_HOUR(0);
						SET_PANEL_TIME_HOUR(0);
						RTDNVRamSavePanelUsedTimeData();
						SET_COLOR_TEMP_TYPE(_CT_DEFAULT);
						RTDNVRamSaveOSDData();

					}
					
#if(_INTERNAL_AUDIO_TEST_SUPPORT)
					
					SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
					if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
					{
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
#endif
				#endif            		
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
            }

        return _TRUE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : We can add some settings here while combo key with power key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyPowerKeyMix(void)
{
    switch(g_ucKeyStateCurr)
    {
        case _POWER_RIGHT_KEY_MASK:
		#if(_CUSTOM_TYPE == _FKX_CUSTOMER)
            SET_OSD_FACTORY_MODE(_ON); 				
			SET_OSD_BURNING_MODE(_ON);
			
            RTDNVRamSaveOSDData();
		#endif
            break;

        case _POWER_MENU_KEY_MASK:
			#if 0//(_CUSTOM_TYPE != _FKX_CUSTOMER)  //�����Ҫ��ϼ�������
			SET_OSD_FACTORY_MODE(_ON); 				
			SET_OSD_BURNING_MODE(_ON);
			
            RTDNVRamSaveOSDData();
			#endif
            break;

        case _POWER_LEFT_RIGHT_KEY_MASK:
            break;

        default:
            break;
    }
}


//--------------------------------------------------
// Description  : Convert keypad status into key message, stores in ucKeyNotify
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyMessageProc(void)
{
    switch(g_ucKeyStateCurr)
    {


        case _MENU_KEY_MASK:
			

			RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);
			CLR_KEYREPEATENABLE();

            break;

        case _RIGHT_KEY_MASK:
#if(_OSD_7_KEY_SUPPROT)		
			if((_OSD_MAIN_SOURCE <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _DEF_OSD_2_END))			
	            RTDKeyMessageConvert(_RIGHT_KEY_MASK, _MENU_KEY_MESSAGE);
			else((_MENU_FUN_BACKLIGHT <= GET_OSD_STATE()) && (GET_OSD_STATE() < _MENU_NULL))
				RTDKeyMessageConvert(_RIGHT_KEY_MASK, _NONE_KEY_MESSAGE);	
			else
				RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);	
							
#else			
            RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
#endif
            break;

        case _LEFT_KEY_MASK:
#if(_OSD_7_KEY_SUPPROT)		
			if((_OSD_MAIN_SOURCE <= GET_OSD_STATE()) && (GET_OSD_STATE() < _MENU_NULL)) 		
				RTDKeyMessageConvert(_LEFT_KEY_MASK, _EXIT_KEY_MESSAGE);
			else
				RTDKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);	
							
#else			
			RTDKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);
#endif
            break;

        case _EXIT_KEY_MASK:
            CLR_KEYREPEATENABLE();
            RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
            break;

#if(_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE)
		case _POWER_KEY_MASK:
	     	CLR_KEYREPEATENABLE();
	      	RTDKeyMessageConvert(_POWER_KEY_MASK, _POWER_KEY_MESSAGE);
            break;
#endif

#if(_OSD_5_KEY_SUPPROT)	


		case _OK_KEY_MASK:
		if(GET_OSD_STATE() == _MENU_NONE)
		{
			CLR_KEYREPEATENABLE();
			RTDKeyMessageConvert(_OK_KEY_MASK, _MENU_KEY_MESSAGE);

		}
		else
		{
			CLR_KEYREPEATENABLE();
			RTDKeyMessageConvert(_OK_KEY_MASK, _MENU_KEY_MESSAGE);
		}
		break;
#elif(_OSD_7_KEY_SUPPROT)		
		case _UP_KEY_MASK:
			if(GET_OSD_STATE() == _MENU_NONE)
			RTDKeyMessageConvert(_UP_KEY_MASK, _UP_KEY_MESSAGE);
			else
			RTDKeyMessageConvert(_UP_KEY_MASK, _RIGHT_KEY_MESSAGE); 			
			break;

		case _DOWN_KEY_MASK:
			if(GET_OSD_STATE() == _MENU_NONE)
			RTDKeyMessageConvert(_DOWN_KEY_MASK, _DOWN_KEY_MESSAGE);
			else
			RTDKeyMessageConvert(_DOWN_KEY_MASK, _LEFT_KEY_MESSAGE);				
			break;
#endif //


        default:
            if((g_ucKeyStateCurr == _RELEASE_KEY_MASK) &&
               (g_ucKeyStatePrev != _RELEASE_KEY_MASK))
            {
                RTDKeyHoldKeyCheck(); // Check key release
            }

            CLR_KEYREPEATSTART();
            CLR_KEYREPEATENABLE();
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
            break;
    }
}

//--------------------------------------------------
// Description  : Key message translation
// Input Value  : ucKeyMask     --> Key mask
//                ucKeyMsg      --> Key message
// Output Value : None
//--------------------------------------------------
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg)
{
    // Key different
    if((g_ucKeyStatePrev != g_ucKeyStateCurr) && (ucKeyMask == g_ucKeyStateCurr))
	{
        // KeyLock function
        if (RTDKeySpecialProc(ucKeyMask) == _FALSE)
        {
            SET_KEYMESSAGE(ucKeyMsg);
            RTDKeyHoldKeyTimerCancel();
        }
    }
    else // Key the same
    {
        if(GET_KEYREPEATENABLE() == _TRUE)
        {
            if(GET_KEYREPEATSTART() == _TRUE)
            {
                SET_KEYMESSAGE(ucKeyMsg);
            }
            else
            {
                // Set repeat key after 500ms.
                ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
            }
        }
    }
}


//--------------------------------------------------
// Description  :  for special key check
// Input Value  : scan Key data
// Output Value : None
//--------------------------------------------------
bit RTDKeySpecialProc(BYTE ucKeyMask)
{
	ucKeyMask = ucKeyMask;
	if(GET_OSD_FACTORY_MODE() == _ON)
	{
	}

#if(_OSD_5_KEY_SUPPROT)		
    if(ucKeyMask == _MENU_KEY_MASK)
    {
        if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
        {
                    SET_OSD_STATE(_MENU_NONE);
                    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
                    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);

        }else
		ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_DO_POWER_DOWN);
   	 
		 SET_KEY_HOLD();
		 CLR_KEYREPEATENABLE(); 
		 return _TRUE;
    }
#elif(_LONG_PRESS_MENU_LOCK_OSD_ENABLE)
	if((ucKeyMask == _MENU_KEY_MASK)&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE))
	{
		ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_LOCK_OSD);
	 
		 SET_KEY_HOLD();
		 CLR_KEYREPEATENABLE(); 
		 return _TRUE;
	}

#endif

#if(_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE)
	if(ucKeyMask == _POWER_KEY_MASK)
	{
	   	ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_LOCK_POWER_KEY);

		SET_KEY_HOLD();
		CLR_KEYREPEATENABLE(); 
		return _TRUE;
	}
#endif


#if 0//(_VGA_SUPPORT == _ON)
    // Press Exit key for 3 sec to do Auto color
    if((GET_OSD_STATE() == _MENU_NONE) && (SysSourceGetSourceType() == _SOURCE_VGA))
    {
        if (ucKeyMask == _EXIT_KEY_MASK)
        {
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_DO_AUTO_COLOR);
            SET_KEY_HOLD();
            CLR_KEYREPEATENABLE();
            return _TRUE;
        }
    }
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyHoldKeyTimerCancel(void)
{
    if(GET_KEY_HOLD() == _TRUE)
    {
        CLR_KEY_HOLD();
		

        // list all off hold key timer event here!!!
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_AUTO_COLOR);
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_POWER_DOWN);
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_FACTORY);
		
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LOCK_OSD);
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LOCK_POWER_KEY);
		ScalerTimerCancelTimerEvent(_USER_REAL_TIME_REFRESH_RATE);
    }
}

//--------------------------------------------------
// Description  : Hold Key check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyHoldKeyCheck(void)
{
    if(GET_KEY_HOLD() == _TRUE)
    {
        switch(g_ucKeyStatePrev)
        {
            case _EXIT_KEY_MASK:
                SET_KEYMESSAGE(_EXIT_KEY_MESSAGE);
                break;

            case _MENU_KEY_MASK:
                SET_KEYMESSAGE(_MENU_KEY_MESSAGE);
                break;
            case _RIGHT_KEY_MASK:
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                break;
            case _LEFT_KEY_MASK:
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                break;

#if(_LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE)
			case _POWER_KEY_MASK:
				if(GET_POWER_KEY_LOCK() == _OFF)
				{
					g_ucKeyStatePrev = _RELEASE_KEY_MASK;
					g_ucKeyStateCurr = _POWER_KEY_MASK;
					RTDKeyPowerKeyProc();
				}
				else
				{
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_POWERKEY_LOCK_MENU-_MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
				}
				break;
#endif

            default:
                break;
        }
        RTDKeyHoldKeyTimerCancel();
    }
}


#if((_IR_SUPPORT == _IR_HW_SUPPORT)||(_IR_VIRTUAL==_ON))
//--------------------------------------------------
// Description  : IR Key Scan
// Input Value  : None
// Output Value : Key Mask
//--------------------------------------------------
BYTE RTDIRKeyScan(void)
{
    BYTE pucIRCodeBuffer[8] = {0};
    WORD usKeyCode = 0;
    BYTE ucKeyState = 0;


#if(_IR_VIRTUAL==_ON)
	if(f_resaveok)
#elif(_IR_SUPPORT == _IR_HW_SUPPORT)
    if(ScalerIRHWModeGetData(pucIRCodeBuffer) == _TRUE)
#endif
	{
#if(_IR_VIRTUAL==_ON)	
		{
			DebugMessageIR("r_data", r_data);
			pucIRCodeBuffer[0] =(r_data>>24)&0xff;
			pucIRCodeBuffer[1] =(r_data>>16)&0xff;
			pucIRCodeBuffer[2] =(r_data>>8)&0xff;
			pucIRCodeBuffer[3] =(r_data)&0xff;
			r_data = 0;
			f_resaveok = 0;
			DebugMessageIR("0.0", pucIRCodeBuffer[0]);
			DebugMessageIR("0.1", pucIRCodeBuffer[1]);
			DebugMessageIR("0.2", pucIRCodeBuffer[2]);
			DebugMessageIR("0.3", pucIRCodeBuffer[3]);
		}
#endif
        //if((pucIRCodeBuffer[0] == ~(pucIRCodeBuffer[1])) && (pucIRCodeBuffer[2] == ~(pucIRCodeBuffer[3])))
			
	if(pucIRCodeBuffer[0] == ~(pucIRCodeBuffer[1]))
	{
#if(_IR_PROTOCAL == _IR_NEC_DTV328)
        usKeyCode = (((WORD)pucIRCodeBuffer[1]) << 8) + pucIRCodeBuffer[2];
#elif(_IR_PROTOCAL == _IR_HUIXIONG_CROSSOVER_KEY14)
		usKeyCode = (((WORD)pucIRCodeBuffer[0]) << 8) + pucIRCodeBuffer[1];
#elif(_IR_PROTOCAL == _IR_SONY_B102P)
        usKeyCode = (((WORD)pucIRCodeBuffer[0]) << 8) + pucIRCodeBuffer[1];
#elif(_IR_PROTOCAL == _IR_PHILIPS_RC6)
        usKeyCode = (((WORD)pucIRCodeBuffer[2]) << 8) + pucIRCodeBuffer[3];
#elif(_IR_PROTOCAL == _IR_DATONG_MT1)
        usKeyCode = (((WORD)pucIRCodeBuffer[3]) << 8) + pucIRCodeBuffer[1];
#endif // End of #if(_IR_PROTOCAL == _IR_NEC_DTV328 || _IR_PROTOCAL == _IR_HUIXIONG_CROSSOVER_KEY14)
	}
    DebugMessageIR("RTDIRKeyScan", usKeyCode);

        switch(usKeyCode)
        {	
#if(_IR_PROTOCAL == _IR_HUIXIONG_CROSSOVER_KEY14)
			case _IR_CODE_KEY_POWER:
                ucKeyState = _POWER_KEY_MASK;
                break;

            case _IR_CODE_KEY_MENU:
                ucKeyState = _MENU_KEY_MASK;
                break;

            case _IR_CODE_KEY_RIGHT:
				//if(GET_OSD_STATE() == _MENU_NONE)
				//{
					//OsdDispDisableOsd();
					//RTDOsdDispHotkeyFuncAdjust(GET_OSD_HOTKEY_RIGHT());
					//SET_IR_OSD_PROGRESS_BAR_OR_OPTION(GetOsdShowType(_DEF_HOTKEY_RIGHT));
					//break;
				//}

				if(GET_OSD_STATE() == _MENU_FUN_SOURCE_HOTKEY && SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)	//ʡ��ģʽ��,���¼�ʱ
				{
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
					ucKeyState = _RIGHT_KEY_MASK;
					break;
				}
				
				if(GET_OSD_STATE() >= _OSD_MAIN_SOURCE && GET_OSD_STATE() < _MENU_FUN_BACKLIGHT)
					ucKeyState = _RIGHT_KEY_MASK;
				else if(GET_OSD_STATE() == _MENU_FUN_SOURCE_HOTKEY || GET_OSD_STATE() == _HOT_KEY_LOS_TYPE1 || GET_OSD_STATE() == _HOT_KEY_LOS_TYPE2)
					ucKeyState = _RIGHT_KEY_MASK;
				else if((GET_OSD_STATE() >= _MENU_FUN_BACKLIGHT && GET_OSD_STATE() < _MENU_NULL) && GetOsdShowType(GET_OSD_STATE()) != _TYPE_SLIDER)
					ucKeyState = _RIGHT_KEY_MASK;
				else if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && GET_IR_OSD_PROGRESS_BAR_OR_OPTION() != _TYPE_SLIDER)
					ucKeyState = 0x00;
				else if(GET_OSD_STATE() >= _MENU_FACTORY_AUTOCOLOR_TYPE && GET_OSD_STATE() < _MENU_FACTORY_OSD_END)
					ucKeyState = _RIGHT_KEY_MASK;
				else
					ucKeyState = 0x00;

                break;

            case _IR_CODE_KEY_LEFT:
				if(GET_OSD_STATE() == _MENU_NONE && SysModeGetModeState() == _MODE_STATUS_ACTIVE)
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(GET_OSD_HOTKEY_LEFT());
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
					//SET_IR_OSD_PROGRESS_BAR_OR_OPTION(GetOsdShowType(_DEF_HOTKEY_LEFT));
					break;
				}

				if(GET_OSD_STATE() == _MENU_FUN_SOURCE_HOTKEY && SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)	//ʡ��ģʽ��,���¼�ʱ
				{
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
					ucKeyState = _LEFT_KEY_MASK;
					break;
				}
				
				if(GET_OSD_STATE() >= _OSD_MAIN_SOURCE && GET_OSD_STATE() < _MENU_FUN_BACKLIGHT)
					ucKeyState = _LEFT_KEY_MASK;					
				else if(GET_OSD_STATE() == _MENU_FUN_SOURCE_HOTKEY || GET_OSD_STATE() == _HOT_KEY_LOS_TYPE1 || GET_OSD_STATE() == _HOT_KEY_LOS_TYPE2)
					ucKeyState = _LEFT_KEY_MASK;					
				else if((GET_OSD_STATE() >= _MENU_FUN_BACKLIGHT && GET_OSD_STATE() < _MENU_NULL) && GetOsdShowType(GET_OSD_STATE()) != _TYPE_SLIDER)
					ucKeyState = _LEFT_KEY_MASK;
				else if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && GET_IR_OSD_PROGRESS_BAR_OR_OPTION() != _TYPE_SLIDER)
					ucKeyState = 0x00;
				else if(GET_OSD_STATE() >= _MENU_FACTORY_AUTOCOLOR_TYPE && GET_OSD_STATE() < _MENU_FACTORY_OSD_END)
					ucKeyState = _LEFT_KEY_MASK;
				else
					ucKeyState = 0x00;
                break;

            case _IR_CODE_KEY_EXIT:
				if(GET_OSD_STATE() != _MENU_NONE)
				{
					ucKeyState = _EXIT_KEY_MASK;
				}
                break;

			case _IR_CODE_KEY_UP:
				if(GET_OSD_STATE() == _MENU_NONE)
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIVOLUME - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
					break;
				}

				
				if(GET_OSD_STATE() >= _OSD_MAIN_SOURCE && GET_OSD_STATE() < _DEF_OSD_2_END)
				{
					ucKeyState = _MENU_KEY_MASK;					
				}
				else if((GetOsdShowType(GET_OSD_STATE())) == _TYPE_SLIDER)
				{
					ucKeyState = _RIGHT_KEY_MASK;
				}
				else if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC)
					ucKeyState = _RIGHT_KEY_MASK;
				else
					ucKeyState = 0x00;
				break;

            case _IR_CODE_KEY_DOWN:
				if(GET_OSD_STATE() == _MENU_NONE)
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIVOLUME - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
					break;
				}
				
				if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
					ucKeyState = _LEFT_KEY_MASK;
				else if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC)
					ucKeyState = _LEFT_KEY_MASK;
				else
					ucKeyState = 0x00;
                break;

            case _IR_CODE_KEY_OK:
                ucKeyState = _MENU_KEY_MASK;
                break;

            case _IR_CODE_KEY_9:				
				if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
			   	{
					ucKeyState = _EXIT_KEY_MASK;
			   	}
				else if(GET_OSD_STATE() == _MENU_FUN_SOURCE_HOTKEY)
				{
					OsdDispDisableOsd();
				}
				else
				{
					if(GET_OSD_FACTORY_MODE() == _OFF)
					{
						OsdDispDisableOsd();
						OsdInputSourceHotkey();
						ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
					}
				}
				break;

			case _IR_CODE_KEY_10:
				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            	{
					ucKeyState = 0x00;
					break;
				};
				
				if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_ASPECT)
				{
					ucKeyState = _RIGHT_KEY_MASK;
				}
				else
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_ASPECT - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
				}
				//SET_IR_OSD_PROGRESS_BAR_OR_OPTION(_TYPE_ARROW);
                break;

			case _IR_CODE_KEY_11:
				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            	{
					ucKeyState = 0x00;
					break;
				};
				if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_AUDOIVOLUME)
				{
					ucKeyState = _LEFT_KEY_MASK;
				}
				else
				{
					OsdDispDisableOsd();

				
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIVOLUME - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
				}
				break;

			case _IR_CODE_KEY_12:
				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            	{
					ucKeyState = 0x00;
					break;
				};
				
				if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_ECO)
				{
					ucKeyState = _RIGHT_KEY_MASK;
				}
				else
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_ECO - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
				}
				//SET_IR_OSD_PROGRESS_BAR_OR_OPTION(_TYPE_ARROW);
                break;

			case _IR_CODE_KEY_13:
				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            	{
					ucKeyState = 0x00;
					break;
				};

				
				if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_AUDOIVOLUME)
				{
					ucKeyState = _RIGHT_KEY_MASK;
				}
				else
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIVOLUME - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
				}
                break;

			case _IR_CODE_KEY_14:
				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            	{
					ucKeyState = 0x00;
					break;
				};
				
				if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_AUDOIMUTE)
				{
					ucKeyState = _RIGHT_KEY_MASK;
				}
				else
				{
					OsdDispDisableOsd();
					RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIMUTE - _MENU_FUN_BACKLIGHT);
					ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
				}
				//SET_IR_OSD_PROGRESS_BAR_OR_OPTION(_TYPE_ARROW);
                break;
#elif(_IR_PROTOCAL == _IR_DATONG_MT1)
        case _IR_CODE_KEY_POWER:
            ucKeyState = _POWER_KEY_MASK;
            break;

        case _IR_CODE_KEY_MENU:
            if(GET_OSD_STATE() != _MENU_NONE)
            ucKeyState = _MENU_KEY_MASK;
            else
                ucKeyState = 0x00;
            break;

        case _IR_CODE_KEY_RIGHT:
            if(GET_OSD_STATE() >= _OSD_MAIN_SOURCE && GET_OSD_STATE() < _DEF_OSD_2_END)
            {
                ucKeyState = _MENU_KEY_MASK;                    
            }
            else
                ucKeyState = 0x00;
            break;


        case _IR_CODE_KEY_LEFT:
            if(GET_OSD_STATE() != _MENU_NONE)
            {
                ucKeyState = _EXIT_KEY_MASK;                    
            }
            else
                ucKeyState = 0x00;
            break;



        case _IR_CODE_KEY_EXIT:
            if(GET_OSD_STATE() == _MENU_NONE)
            {
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
            }
            break;

        case _IR_CODE_KEY_UP:
            if(GET_OSD_STATE() != _MENU_NONE)
            ucKeyState = _RIGHT_KEY_MASK;
            else
                ucKeyState = 0x00;
            break;




        case _IR_CODE_KEY_DOWN:

             if(GET_OSD_STATE() != _MENU_NONE)
                ucKeyState = _LEFT_KEY_MASK;
            else
                ucKeyState = 0x00;
            break;       
            



        case _IR_CODE_KEY_FUN1:    
            if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            {
                ucKeyState = 0x00;
                break;
            };
            
            if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_ECO)
            {
                ucKeyState = _RIGHT_KEY_MASK;
            }
            else
            {
                OsdDispDisableOsd();
                RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_ECO - _MENU_FUN_BACKLIGHT);
                ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
            }
            break;


        case _IR_CODE_KEY_FUN2:
             if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            {
                ucKeyState = 0x00;
                break;
            };
            
            if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_POWER_OFF)
            {
                ucKeyState = _RIGHT_KEY_MASK;
            }
            else
            {
                OsdDispDisableOsd();
                RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_POWER_OFF - _MENU_FUN_BACKLIGHT);
                ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
            }
            //SET_IR_OSD_PROGRESS_BAR_OR_OPTION(_TYPE_ARROW);
            break;                    break;

        case _IR_CODE_KEY_FUN3:
            if(GET_OSD_STATE() == _MENU_NONE)
                 ucKeyState = _MENU_KEY_MASK;
             else
                {
                 OsdDispDisableOsd();
                 ucKeyState = 0x00;
                }
             break;


        case _IR_CODE_KEY_VOLUME_Reduce :
            if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            {
                ucKeyState = 0x00;
                break;
            };

            

            if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_AUDOIVOLUME)
            {
                ucKeyState = _RIGHT_KEY_MASK;
            }
            else
            {
                OsdDispDisableOsd();
                RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIVOLUME - _MENU_FUN_BACKLIGHT);
                ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
            }
            break;

        case _IR_CODE_KEY_VOLUME_INCREASE:

            if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
            {
                ucKeyState = 0x00;
                break;
            };

            if(GET_OSD_STATE() == _MENU_HOT_KEY_FUNC && OSD_SubMenuCur == _MENU_FUN_AUDOIVOLUME)
            {
                ucKeyState = _LEFT_KEY_MASK;
            }
            else
            {
                OsdDispDisableOsd();

            
                RTDOsdDispHotkeyFuncAdjust(_MENU_FUN_AUDOIVOLUME - _MENU_FUN_BACKLIGHT);
                ScalerTimerReactiveTimerEvent(SEC(8),_USER_TIMER_EVENT_OSD_DISABLE);
            }
            break;


#else
			case _IR_CODE_KEY_POWER:
                ucKeyState = _POWER_KEY_MASK;
                break;

            case _IR_CODE_KEY_MENU:
                ucKeyState = _MENU_KEY_MASK;
                break;

            case _IR_CODE_KEY_RIGHT:
                ucKeyState = _RIGHT_KEY_MASK;
                break;

            case _IR_CODE_KEY_LEFT:
                ucKeyState = _LEFT_KEY_MASK;
                break;

            case _IR_CODE_KEY_EXIT:
                ucKeyState = _EXIT_KEY_MASK;
                break;
#endif


            default:
                ucKeyState = 0x00;
                break;
        }
    }

    return ucKeyState;
}
#endif // End of #if(_IR_SUPPORT == _IR_HW_SUPPORT)

#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
