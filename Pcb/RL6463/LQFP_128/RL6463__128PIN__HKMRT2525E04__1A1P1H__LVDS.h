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
// ID Code      : _RL6463__128PIN__HKMRT2525E04__1A1P1H__LVDS.h No.0000
// Update Note  :
#if(_PCB_TYPE == _RL6463__128PIN__HKMRT2525E04__1A1P1H__LVDS)

#define _PCB_DEBUG_DDC                       _VGA_DDC//   _DDC0

#undef _DAC_HP_OUTPUT_SWAP
#define _DAC_HP_OUTPUT_SWAP                                     _ON

///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#define _EXT_XTAL                               _XTAL14318K


///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#if(_HDMI_24C02_SUPPORT)
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#else
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_128
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_FLASH
#endif
//--------------------------------------------------
// D0 Input Port
//--------------------------------------------------
#define _D0_INPUT_PORT_TYPE                     _D0_HDMI_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0
#if(_HDMI_24C02_SUPPORT)
#define _D0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#else
#define _D0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_256
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_FLASH
#endif
//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_DP_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_FLASH
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _D1_INPUT_PORT

#define _D1_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#define _D1_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#define _D1_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#define _D1_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3

//#define _D0_TMDS_PN_SWAP                        _OFF
//#define _D0_TMDS_BR_SWAP                        _OFF

////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Port Config
//--------------------------------------------------
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_AB
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL               _DISABLE

//--------------------------------------------------
// LVDS SSC Config
//--------------------------------------------------
#define _LVDS_SPREAD_RANGE                  12//10
#define _LVDS_SPREAD_SPEED                      _SPEED_33K


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM0
#define _BACKLIGHT_PWM_INVERSE                 	_ON

#define _AUDIO_VOLUMN_PWM					_NO_PWM//	_PWM1
#define _AUDIO_VOLUMN_PWM_INVERSE				_OFF


#define _PWM0_EN                                _ON
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_PDOW_EN                           _OFF
#define _PWM1_PDOW_EN                           _OFF
#define _PWM2_PDOW_EN                           _OFF
#define _PWM3_PDOW_EN                           _OFF
#define _PWM4_PDOW_EN                           _OFF
#define _PWM5_PDOW_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _OFF
#define _PWM_RST_BY_TCON                        _OFF


/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// Sofware and Hardware IIC Option
//--------------------------------------------------
#if(_HDMI_24C02_SUPPORT)
#define _SW_IIC_SUPPORT                         _ON
#else
#define _SW_IIC_SUPPORT                         _OFF
#endif
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#if(_HDMI_24C02_SUPPORT)
#define _PCB_SYS_EEPROM_IIC                     _SW_IIC_PIN_GPIO
#else
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_47_48
#endif

//////////
// Misc //
//////////

//--------------------------------------------------
// AD Key Option
//--------------------------------------------------
#define _AD_KEY_SUPPORT                         _ON

//--------------------------------------------------
// Low Speed ADC Option
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON


//////////////////////
// Series Pin Share //
//////////////////////
#include "RL6463__128PIN__HKMRT2525E04__1A1P1H__LVDS__PINSHARE.h"


//////////////////////
// GPIO Power Macro //
//////////////////////

//-----------------------------------------------
// Macro of Pcb GPIO Inital Setting
//-----------------------------------------------
#define PCB_ON_REGION_GPIO_SETTING_POWER_AC_ON(){\
	  													PCB_AMP_MUTE(_AMP_MUTE_ON);\
}

#define PCB_OFF_REGION_GPIO_SETTING_POWER_AC_PD_PS_ON()\
                                                {\
  													PCB_AMP_MUTE(_AMP_MUTE_ON);\
  							   }


#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
}

#define PCB_GPIO_SETTING_POWER_SAVING()         {\
													PCB_AMP_MUTE(_AMP_MUTE_ON);\
}

#define PCB_GPIO_SETTING_POWER_DOWN()           {\
													PCB_AMP_MUTE(_AMP_MUTE_ON);\
 }

/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of Embedded LDO Support
//-----------------------------------------------
#define _EMBEDDED_LDO_OFF                       0
#define _EMBEDDED_LDO_ON                        1

#define PCB_EMBEDDED_LDO_DETECT()               (_EMBEDDED_LDO_OFF)


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             _PIN_97_MCU_REG

#define _PANEL_CONTROL_ON                       1
#define _PANEL_CONTROL_OFF                      0

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         _PIN_35_MCU_REG

#define _LIGHT_CONTROL_ON                     1//  0
#define _LIGHT_CONTROL_OFF                   0//   1

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = (x);\
                                                }

#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if((x) == _LIGHT_CONTROL_ON)\
                                                    {\
                                                       ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                       ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, GET_OSD_FLICKER_FREE_STATUS()? 25000: (((DWORD)_PANEL_TYP_FRAME_RATE * 160) / 100));\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    PCB_BACKLIGHT_POWER_PIN(x)\
                                                }


/////////////////////////
// Write Protect Macro //
/////////////////////////

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    _PIN_96_MCU_REG

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)//LFC 没有用到

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)//LFC 没有用到

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }


////////////////////////
// Cable Status Macro //
////////////////////////
#if(_HDMI_24C02_SUPPORT)

#define bSWIIC_SYS_EEPROM_SCL                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS) 

//HDMI1
//sbit bDDC1IICSCL         				    	      =P3^2; // _156PIN_PIN_137, 
//sbit bDDC1IICSDA          					      =P3^3; // _156PIN_PIN_138,

//VGA
#define bVgaDDCIICSCL							(MCU_FE1E_PORT76_PIN_REG) // _156PIN_PIN_100, 
#define bVgaDDCIICSDA							(MCU_FE1F_PORT77_PIN_REG) // _156PIN_PIN_101,

//HDMI1
#define bDDC0IICSCL         				   	(MCU_FE22_PORT82_PIN_REG) // _156PIN_PIN_110, 
#define bDDC0IICSDA          					(MCU_FE23_PORT83_PIN_REG) // _156PIN_PIN_111,


#define PCB_SW_IIC_SDA_SET()                    {\
                                                     if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)	\
                                                    {												\
                                                    	bVgaDDCIICSDA = _TRUE;						\
                                                    }												\
                                                  else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC0)	\
                                                    {												\
                                                    	bDDC0IICSDA = _TRUE;						\
                                                    }												\
                                                   else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          		\
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;         		\
                                                    }                                          		\
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                     if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)	\
                                                    {												\
                                                    	bVgaDDCIICSDA = _FALSE;						\
                                                    }												\
                                                  else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC0)	\
                                                    {												\
                                                    	bDDC0IICSDA = _FALSE;						\
                                                    }												\
                                                   else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          		\
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;        		\
                                                    }                                          		\
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                     if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 	\
                                                    {                                          		\
                                                        x = bVgaDDCIICSDA;             				\
                                                    }                                          		\
                                                          else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC0) 	\
                            					{                                          		\
                                                        x = bDDC0IICSDA;             				\
                                                    }                                          		\
                                                  else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          		\
                                                        x = bSWIIC_SYS_EEPROM_SDA;             		\
                                                    }                                          		\
                                                }
#define PCB_SW_IIC_SCL_SET()                    {\
                                                     if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 	\
                                                    {                                          		\
                                                        bVgaDDCIICSCL = _TRUE;         				\
                                                    }                                          		\
                                                     else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC0) 	\
                                                    {                                          		\
                                                        bDDC0IICSCL = _TRUE;         				\
                                                    }                                          		\
                                                    else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          		\
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;         		\
                                                    }                                          		\
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                     if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 	\
                                                    {                                          		\
                                                        bVgaDDCIICSCL = _FALSE;        				\
                                                    }                                          		\
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC0) 	\
                                                    {                                          		\
                                                        bDDC0IICSCL = _FALSE;        				\
                                                    }                                          		\
                                                else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          		\
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;        		\
                                                    }                                          		\
                                                }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                     if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 	\
                                                    {                                          		\
                                                        x = bVgaDDCIICSCL;             				\
                                                    }                                          		\
                                                    else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC0) 	\
                                                    {                                          		\
                                                        x = bDDC0IICSCL;             				\
                                                    }                                          		\
                                                   else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
                                                    {                                          		\
                                                        x = bSWIIC_SYS_EEPROM_SCL;             		\
                                                    }                                          		\
                                                }


#endif

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------
#define bD1_DP_PIN15_CONNECT              _PIN_47_MCU_REG//      _PIN_50_MCU_REG  //DP_SINK_ASS_P1
#define bD1_DP_PIN16_CONNECT                    _PIN_45_MCU_REG  //DP_CABLE_DETECT
#define bD1_DP_PIN17_CONNECT               _PIN_48_MCU_REG//     _PIN_49_MCU_REG  //DP_SINK_ASS_N1

#define bA0_CONNECT                             (_PIN_36_MCU_REG)
#define bD0_CONNECT                             _PIN_44_MCU_REG
//#define bD1_CONNECT                             (((bit)bD1_DP_PIN15_CONNECT == _FALSE) && ((bit)bD1_DP_PIN16_CONNECT == _FALSE) && ((bit)bD1_DP_PIN17_CONNECT == _TRUE))
#define bD1_CONNECT                             (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 _PIN_38_MCU_REG// HDMI
#define bD1_HPD                                 _PIN_37_MCU_REG//DP

#define _D0_HOT_PLUG_HIGH                       1
#define _D0_HOT_PLUG_LOW                        0

#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = (x);\
                                                }

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = (x);\
                                                }

#define PCB_D0_HOTPLUG_DETECT()                 (bD0_HPD)
#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)


///////////////
// PWM Macro //
///////////////

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, GET_OSD_FLICKER_FREE_STATUS()? 25000: (((DWORD)_PANEL_TYP_FRAME_RATE * 160) / 100));\
                                                }


#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_GET_8BIT_PWM_DUTY(_BACKLIGHT_PWM))

#elif(_PWM_DUT_RESOLUTION == _PWM_12BIT)

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_12BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_GET_12BIT_PWM_DUTY(_BACKLIGHT_PWM))

#endif


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   _PIN_114_MCU_REG
#define bLED2                                   _PIN_115_MCU_REG

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                    bLED1 = _LED_ON;\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_TYPE3()                         {\
                                                }

#define PCB_LED_TYPE4()                         {\
                                                }

#define PCB_LED_TYPE5()                         {\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
                                                }


//////////////////
// AD Key Macro //
//////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT) // Pin_42
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT) // Pin_43

#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)

#define POWER_KEY								0x80
#define MENU_KEY								0x80
#define RIGHT_KEY								0XD0
#define LEFT_KEY								0X0A
#define EXIT_KEY 								0XA8

#define POWER_REG								1
#define MENU_REG								2
#define RIGHT_REG								1
#define LEFT_REG								1
#define EXIT_REG 								1



#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                                if((((KeyDefault[4]<10)? 0: KeyDefault[4]-10) <= ((KeyDefault[9]==1)? AD_KEY1 : AD_KEY2)) && (((KeyDefault[9]==1)? AD_KEY1 : AD_KEY2) < ((KeyDefault[4]>237)? 247: KeyDefault[4]+10)))\
                                                                {\
                                                                    (ucKeyState) |= _LEFT_KEY_MASK ;\
                                                                }\
                                                                if((((KeyDefault[3]<10)? 0: KeyDefault[3]-10) <= ((KeyDefault[8]==1)? AD_KEY1 : AD_KEY2)) && (((KeyDefault[8]==1)? AD_KEY1 : AD_KEY2) < ((KeyDefault[3]>237)? 247: KeyDefault[3]+10)))\
                                                                {\
                                                                    (ucKeyState) |= _RIGHT_KEY_MASK ;\
                                                                }\                                                             
                                                                if((((KeyDefault[2]<10)? 0: KeyDefault[2]-10) <= ((KeyDefault[7]==1)? AD_KEY1 : AD_KEY2)) && (((KeyDefault[7]==1)? AD_KEY1 : AD_KEY2) < ((KeyDefault[2]>237)? 247: KeyDefault[2]+10)))\
                                                                {\
																	(ucKeyState) |= _EXIT_KEY_MASK ;\
                                                                }\                                                 
                                                                if((((KeyDefault[1]<10)? 0: KeyDefault[1]-10) <= ((KeyDefault[6]==1)? AD_KEY1 : AD_KEY2)) && (((KeyDefault[6]==1)? AD_KEY1 : AD_KEY2) < ((KeyDefault[1]>237)? 247: KeyDefault[1]+10)))\
                                                                {\
                                                                    (ucKeyState) |= _MENU_KEY_MASK ;\
                                                                }\
                                                                if((((KeyDefault[0]<10)? 0: KeyDefault[0]-10) <= ((KeyDefault[5]==1)? AD_KEY1 : AD_KEY2)) && (((KeyDefault[5]==1)? AD_KEY1 : AD_KEY2) < ((KeyDefault[0]>237)? 247: KeyDefault[0]+10)))\
                                                                {\
                                                                    (ucKeyState) |= _POWER_KEY_MASK;\
                                                                }\                                                                
                                                            }


// Audio Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Audio Connect
//-----------------------------------------------
#define bAUDIODETECT                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _AUDIO_CONNECT                          0
#define _AUDIO_DISCONNECT                       1

#define PCB_AUDIO_DETECT()                      (bAUDIODETECT)

#define _AUDIO_HEADPHONE_SUPPORT                         	_ON

#if (_AUDIO_HEADPHONE_SUPPORT==_ON)
#define bHeadphoneDetect                        _PIN_53_MCU_REG


#define _HEADPHONE_CONNECT					   1
#define _HEADPHONE_DISCONNECT				   0  

#define PCB_HEADPHONE_DETECT()                  (bHeadphoneDetect)

#endif

//-----------------------------------------------
// Macro of PCB Audio AMP Control
//-----------------------------------------------
#define bPCBAMPMUTECONTROL                      (_PIN_65_MCU_REG)

#define _AMP_MUTE_ON                            1
#define _AMP_MUTE_OFF                           0

#define PCB_AMP_MUTE(x)                         {\
                                                    bPCBAMPMUTECONTROL = (x);\
                                                }

#define _MAIN_PAGE_MODEL_NAME               _M__,_o__,_d__,_e__,_l__,__,_COLON__,__,_R__,_T__,_D__,_2__,_5__,_2__,_5__
#define _BURNIN_STR_IC_NAME                	_R__,_T__,_D__,_2__,_5__,_2__,_5__

#endif // End of #if(_PCB_TYPE == _RL6463__128PIN__HKMRT2525E04__1A1P1H__LVDS)
//----------------------------------------------------------------------------------------------------
