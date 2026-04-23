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
// ID Code      : RL6410__318PIN__JY29XT_PH_WS_R20_1__2H2DP__eDPVB1LVDS.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PCB_TYPE == _RL6410__318PIN__JY29XT_PH_WS_R20_1__2H2DP__eDPVB1LVDS)
 
 
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
 // D0 Input Port
 //--------------------------------------------------
#define _D0_INPUT_PORT_TYPE                     _D0_DP_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0
#define _D0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_256
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE
 
 //--------------------------------------------------
 // D1 Input Port
 //--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_DP_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D1_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE
 
 //--------------------------------------------------
 // D2 Input Port
 //--------------------------------------------------
#define _D2_INPUT_PORT_TYPE                     _D2_HDMI_PORT
#define _D2_DDC_CHANNEL_SEL                     _DDC2
#define _D2_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _D2_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
 
 //--------------------------------------------------
 // D3 Input Port
 //--------------------------------------------------
#define _D3_INPUT_PORT_TYPE                     _D3_HDMI_PORT
#define _D3_DDC_CHANNEL_SEL                     _DDC3
#define _D3_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _D3_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
 
 //--------------------------------------------------
 // D7 Input Port
 //--------------------------------------------------
 
#define _D7_INPUT_PORT_TYPE                     _D7_DP_PORT
#define _D7_D0_EMBEDDED_DDCRAM_SIZE             _EDID_SIZE_384
#define _D7_D1_EMBEDDED_DDCRAM_SIZE             _EDID_SIZE_256
#define _D7_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D7_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_DUAL_DP
#define _D7_SEARCH_MAIN_PORT_ONLY               _ON
 
 
 /////////////////////////////
 // Search Group & Priority //
 /////////////////////////////
 
 //--------------------------------------------------
 // Input Port Search Group Define
 //--------------------------------------------------
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D3_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D7_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
 
 //--------------------------------------------------
 // Input Port Search Priority Define (Must Start From Valid Port)
 //--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _D2_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D3_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _D0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _D1_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_4                _D7_INPUT_PORT
 
 
 ////////////////////
 // For LVDS Panel //
 ////////////////////
 
 //--------------------------------------------------
 // LVDS Port Config
 //--------------------------------------------------
#if(_LVDS_OUTPUT_PORT == _LVDS_2_PORT)
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_CD
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#define _LVDS_PORT_CD_SWAP                      _DISABLE
#define _LVDS_PORT_EF_SWAP                      _DISABLE
#define _LVDS_PORT_GH_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _ENABLE
#elif(_LVDS_OUTPUT_PORT == _LVDS_4_PORT)
 
#if(_LVDS_CABLE_TYPE == _LVDS_CABLE_TYPE_0)
#define _LVDS_PORT_SEL                          _LVDS_4_PORT_ABCD
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _ENABLE
#define _LVDS_PORT_CD_SWAP                      _DISABLE
#define _LVDS_PORT_EF_SWAP                      _DISABLE
#define _LVDS_PORT_GH_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
#elif(_LVDS_CABLE_TYPE == _LVDS_CABLE_TYPE_1)
#define _LVDS_PORT_SEL                          _LVDS_4_PORT_ABCD
#define _LVDS_PORT_MIRROR                       _ENABLE
#define _LVDS_PORT_AB_SWAP                      _ENABLE
#define _LVDS_PORT_CD_SWAP                      _ENABLE
#define _LVDS_PORT_EF_SWAP                      _DISABLE
#define _LVDS_PORT_GH_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
#endif
 
#endif
 
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
#define _LVDS_SPREAD_RANGE                      10
#define _LVDS_SPREAD_SPEED                      _SPEED_33K
 
 
 /////////////////////////
 // eDPTx 1.1 HBR Panel //
 /////////////////////////
 
 //--------------------------------------------------
 // eDPTx 1.1 HBR Main Link Config
 //--------------------------------------------------
#define _PANEL_DPTX_1_1_FB_SWAP                 _DISABLE
#define _PANEL_DPTX_1_1_LANE_SWAP               _DISABLE
#define _PANEL_DPTX_1_1_LANE_PN_SWAP            _ENABLE
#define _PANEL_DPTX_1_1_SWING_LEVEL             _DP_SWING_800_MV
#define _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_0_DB
 
 //--------------------------------------------------
 // eDPTx 1.1 HBR SSC Config
 //--------------------------------------------------
#define _PANEL_DPTX_1_1_SPREAD_RANGE            12
#define _PANEL_DPTX_1_1_SPREAD_SPEED            _SPEED_33K
 
 
 //////////////////////////
 // eDPTx 1.2 HBR2 Panel //
 //////////////////////////
 
 //--------------------------------------------------
 // eDPTx 1.2 HBR2 Main Link Config
 //--------------------------------------------------
#define _PANEL_DPTX_1_2_SWING_LEVEL             _DP_SWING_800_MV
#define _PANEL_DPTX_1_2_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_3_5_DB
 
 //--------------------------------------------------
 // eDPTx 1.2 HBR2 SSC Config
 //--------------------------------------------------
#define _PANEL_DPTX_1_2_SPREAD_RANGE            12
#define _PANEL_DPTX_1_2_SPREAD_SPEED            _SPEED_33K
 
 //--------------------------------------------------
 // eDPTx 1.2 HBR2 FB/Lane Config
 //--------------------------------------------------
#define _PANEL_DPTX_1_2_FB_SWAP                 _DISABLE
#define _PANEL_DPTX_1_2_LANE_SWAP               _DISABLE
#define _PANEL_DPTX_1_2_LANE_PN_SWAP            _ENABLE
 
 
 /////////////////
 // Memory DDR3 //
 /////////////////
 
 //--------------------------------------------------
 // Definitions of DDR3 Memory Size
 //--------------------------------------------------
#define _EXTERNAL_MEMORY_SIZE_CONFIG            _1G_16BIT_DDR3_2PCS
 
 //--------------------------------------------------
 // Definitions of DDR3 PLL Phase
 //--------------------------------------------------
#if((_EXTERNAL_MEMORY_SIZE_CONFIG & _MEMORY_DENSITY_MASK) == _MEMORY_DENSITY_64M_16)
#define _DDR3_PLL_INITIAL_PHASE_0               0x16032100
#define _DDR3_PLL_INITIAL_PHASE_1               0x18002314
#define _DDR3_READ_DQ_DLYN_TAP                  0x1F1F1F1F
#elif((_EXTERNAL_MEMORY_SIZE_CONFIG & _MEMORY_DENSITY_MASK) == _MEMORY_DENSITY_128M_16)
#define _DDR3_PLL_INITIAL_PHASE_0               0x1B002900
#define _DDR3_PLL_INITIAL_PHASE_1               0x1800291B
#define _DDR3_READ_DQ_DLYN_TAP                  0x1C1C1C1C
#elif((_EXTERNAL_MEMORY_SIZE_CONFIG & _MEMORY_DENSITY_MASK) == _MEMORY_DENSITY_256M_16)
#define _DDR3_PLL_INITIAL_PHASE_0               0x1A002500
#define _DDR3_PLL_INITIAL_PHASE_1               0x18002717
#define _DDR3_READ_DQ_DLYN_TAP                  0x1E1E1E1E
#endif
 
 
 /////////
 // PWM //
 /////////
 
 //--------------------------------------------------
 // PWM Setting
 //--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT
 
#define _BACKLIGHT_PWM                          _PWM5
#define _BACKLIGHT_PWM_INVERSE                  _ON
 
#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _ON
 
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
#define _PWM5_RST_BY_DVS                        _ON
#define _PWM_RST_BY_TCON                        _OFF
 
 
 /////////////////
 // SW & HW IIC //
 /////////////////
 
 //--------------------------------------------------
 // Sofware and Hardware IIC Option
 //--------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON
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
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_J7_H6
 
 
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
#include "RL6410__318PIN__JY29XT_PH_WS_R20_1__2H2DP__eDPVB1LVDS.h"
 
 
 //////////////////////
 // GPIO Power Macro //
 //////////////////////
 
 //-----------------------------------------------
 // Macro of Pcb GPIO ON/OFF Region Initial Setting
 //-----------------------------------------------
#define PCB_ON_REGION_GPIO_SETTING_POWER_AC_ON(){\
												 }
 
#define PCB_OFF_REGION_GPIO_SETTING_POWER_AC_PD_PS_ON()\
												 {\
												 }
 
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
												 }
 
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
												 }
 
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
												 }
 
 
 /////////////////////
 // PCB Power Macro //
 /////////////////////
 
 //-----------------------------------------------
 // Macro of VCCK_ON/VCCK_OFF Power Control
 //-----------------------------------------------
#define bVCCKOFFPOWER                           (MCU_FE23_PORT83_PIN_REG) // Pin_AH21
#define bRLE0779VCCKOFFPOWER                    (MCU_FE26_PORT86_PIN_REG) // Pin_AJ20
#define bRLE0779VCCKONPOWER                     (MCU_FE25_PORT85_PIN_REG) // Pin_AJ21
#define bRLE0779V33SPOWER                       (MCU_FE27_PORT87_PIN_REG) // Pin_AH20
 
#define _VCCK_OFF_POWER_ON                      1
#define _VCCK_OFF_POWER_OFF                     0
 
#define _V33S_POWER_ON                          1
#define _V33S_POWER_OFF                         0
 
#define PCB_VCCK_OFF_POWER(x)                   {\
													 bVCCKOFFPOWER = (x);\
												 }
 
#define PCB_RLE0779_VCCK_OFF_POWER(x)           {\
													 bRLE0779VCCKOFFPOWER = (x);\
												 }
 
#define PCB_RLE0779_VCCK_ON_POWER(x)            {\
													 bRLE0779VCCKONPOWER = (x);\
												 }
 
#define PCB_RLE0779_V33S_POWER(x)               {\
													 bRLE0779V33SPOWER = (x);\
												 }
 
 //-----------------------------------------------
 // Macro of DDR Poewr Control
 //-----------------------------------------------
#define bDDRPOWER                               (MCU_FE24_PORT84_PIN_REG) // Pin_AK21
 
#define _DDR_POWER_ON                           1
#define _DDR_POWER_OFF                          0
 
#define PCB_DDR_POWER(x)                        {\
													 bDDRPOWER = (x);\
												 }
 
 
 ///////////////////////
 // Panel Power Macro //
 ///////////////////////
 
 //--------------------------------------------------
 // Macro of Panel Power Up/Down
 //--------------------------------------------------
#define bPANELPOWER                             (MCU_FE0C_PORT54_PIN_REG) // Pin_AM3
 
#define _PANEL_CONTROL_ON                       1
#define _PANEL_CONTROL_OFF                      0
 
#define PCB_PANEL_POWER(x)                      {\
													 bPANELPOWER = (x);\
												 }
 
#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)
 
 //--------------------------------------------------
 // Macro of Light Power Up/Down
 //--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_FE32_PORTA2_PIN_REG) // Pin_AJ27
 
#define _LIGHT_CONTROL_ON                       0
#define _LIGHT_CONTROL_OFF                      1
 
#define PCB_BACKLIGHT_POWER_PIN(x)              {\
													 bBACKLIGHTPOWER = (x);\
												 }
 
#define PCB_BACKLIGHT_POWER(x)                  {\
													 if((x) == _LIGHT_CONTROL_ON)\
													 {\
														 ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
														 ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (((DWORD)_PANEL_TYP_FRAME_RATE * 60) / 100));\
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
#define bFLASH_WRITE_PROTECT                    (MCU_FE28_PORT90_PIN_REG) // Pin_AL21
 
#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1
 
#define PCB_FLASH_WRITE_PROTECT(x)              {\
													 bFLASH_WRITE_PROTECT = (x);\
												 }
 
 //-----------------------------------------------
 // Macro of System Eeprom WP High/Low
 //-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_FE0D_PORT55_PIN_REG) // Pin_G7
 
#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0
 
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
													 bEEPROM_WRITE_PROTECT = (x);\
												 }
 
#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)
 
 //-----------------------------------------------
 // Macro of EDID Eeprom WP High/Low
 //-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_FE30_PORTA0_PIN_REG)  // Pin_AG24
 
#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0
 
#define PCB_D2_EDID_EEPROM_WRITE_PROTECT(x)     {\
													 bEDID_WRITE_PROTECT = (x);\
												 }
 
#define PCB_D3_EDID_EEPROM_WRITE_PROTECT(x)     {\
													 bEDID_WRITE_PROTECT = (x);\
												 }
 
 
 ////////////////////////
 // Cable Status Macro //
 ////////////////////////
 
#define bDDC2IICSCL                             (MCU_FE55_PORTE5_PIN_REG) //_IIC_FOR_DDC2// _PIN_M6
#define bDDC2IICSDA                             (MCU_FE56_PORTE6_PIN_REG)  //_IIC_FOR_DDC2// _PIN_M5
 
 //_IIC_FOR_DDC3
#define bDDC3IICSCL                             (MCU_FE53_PORTE3_PIN_REG)  // _PIN_L6
#define bDDC3IICSDA                             (MCU_FE54_PORTE4_PIN_REG)  // _PIN_L5
 
#define bSWIIC_SYS_EEPROM_SCL                 (MCU_FE0E_PORT56_PIN_REG) // _PIN_J7, EESCL P5.6
#define bSWIIC_SYS_EEPROM_SDA                 (MCU_FE0F_PORT57_PIN_REG) // _PIN_H6, EESDA  P5.7
 
 
#define PCB_SW_IIC_SDA_SET()                    {\
													  if(GET_SW_IIC_STATUS() == _IIC_DDC3)	 \
													 {												 \
														 bDDC3IICSDA = _TRUE;						 \
													 }												 \
													  else if(GET_SW_IIC_STATUS() == _IIC_DDC2)  \
													 {												 \
														 bDDC2IICSDA = _TRUE;						 \
													 }												 \
													  else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
													 {												 \
														 bSWIIC_SYS_EEPROM_SDA = _TRUE; 			 \
													 }												 \
												 }
#define PCB_SW_IIC_SDA_CLR()                    {\
													 if(GET_SW_IIC_STATUS() == _IIC_DDC3)	 \
													 {												 \
														 bDDC3IICSDA = _FALSE;						 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_DDC2)	 \
													 {												 \
														 bDDC2IICSDA = _FALSE;						 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
													 {												 \
														 bSWIIC_SYS_EEPROM_SDA = _FALSE;			 \
													 }												 \
												 }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
													  if(GET_SW_IIC_STATUS() == _IIC_DDC3)	 \
													 {												 \
														 x = bDDC3IICSDA;							 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_DDC2)	 \
													 {												 \
														 x = bDDC2IICSDA;							 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
													 {												 \
														 x = bSWIIC_SYS_EEPROM_SDA; 				 \
													 }												 \
												 }
#define PCB_SW_IIC_SCL_SET()                    {\
													  if(GET_SW_IIC_STATUS() == _IIC_DDC3)	 \
													 {												 \
														 bDDC3IICSCL = _TRUE;						 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_DDC2)	 \
													 {												 \
														 bDDC2IICSCL = _TRUE;						 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
													 {												 \
														 bSWIIC_SYS_EEPROM_SCL = _TRUE; 			 \
													 }												 \
												 }
#define PCB_SW_IIC_SCL_CLR()                    {\
													 if(GET_SW_IIC_STATUS() == _IIC_DDC3)	 \
													 {												 \
														 bDDC3IICSCL = _FALSE;						 \
													 }												 \
													  else if(GET_SW_IIC_STATUS() == _IIC_DDC2)  \
													 {												 \
														 bDDC2IICSCL = _FALSE;						 \
													 }												 \
													 else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
													 {												 \
														 bSWIIC_SYS_EEPROM_SCL = _FALSE;			 \
													 }												 \
												 }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
													 if(GET_SW_IIC_STATUS() == _IIC_DDC3)	 \
													 {												 \
														 x = bDDC3IICSCL;							 \
													 }												 \
													  else if(GET_SW_IIC_STATUS() == _IIC_DDC2)  \
													 {												 \
														 x = bDDC2IICSCL;							 \
													 }												 \
													  else if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM) \
													 {												 \
														 x = bSWIIC_SYS_EEPROM_SCL; 				 \
													 }												 \
												 }
 
 //-----------------------------------------------
 // Macro of Input Cable Connect
 //-----------------------------------------------
#define bD0_DP_PIN15_CONNECT                    (MCU_FE33_PORTA3_PIN_REG)  // Pin_AG29
#define bD0_DP_PIN16_CONNECT                    (MCU_FE35_PORTA5_PIN_REG)  // Pin_AF29
#define bD0_DP_PIN17_CONNECT                    (MCU_FE34_PORTA4_PIN_REG)  // Pin_AH25
#define bD0_CONNECT                             (0)// (((bit)bD0_DP_PIN15_CONNECT == _TRUE) && ((bit)bD0_DP_PIN16_CONNECT == _TRUE) && ((bit)bD0_DP_PIN17_CONNECT == _FALSE))
 
#define bD1_DP_PIN15_CONNECT                    (MCU_FE36_PORTA6_PIN_REG)   // Pin_AJ25
#define bD1_DP_PIN16_CONNECT                    (MCU_FE38_PORTB0_PIN_REG)   // Pin_AH24
#define bD1_DP_PIN17_CONNECT                    (MCU_FE37_PORTA7_PIN_REG)   // Pin_AG28
#define bD1_CONNECT                             (0)// (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))
 
#define bD2_CONNECT                             (MCU_FE46_PORTC6_PIN_REG)// Pin_AJ4
#define bD3_CONNECT                             (MCU_FE3B_PORTB3_PIN_REG)// Pin_AG27
 
#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)
#define PCB_D2_PIN()                            (bD2_CONNECT)
#define PCB_D3_PIN()                            (bD3_CONNECT)
 
 //-----------------------------------------------
 // Macro of DP Source Power
 //-----------------------------------------------
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_DP_PIN17_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)
 
 //-----------------------------------------------
 // Macro of MHL Cable Connect
 //-----------------------------------------------
 
 
 ////////////////////
 // Hot Plug Macro //
 ////////////////////
 
 //-----------------------------------------------
 // Macro of Digital Hot Plug High/Low
 //-----------------------------------------------
#define bD0_HPD                                 (MCU_FE4C_PORTD4_PIN_REG) // Pin_AH5
#define bD1_HPD                                 (MCU_FE4B_PORTD3_PIN_REG) // Pin_AH6
#define bD2_HPD                                 (P1_4) // PIN_L4
#define bD3_HPD                                 (P1_6) // Pin_F4
 
#define _D0_HOT_PLUG_HIGH                       1
#define _D0_HOT_PLUG_LOW                        0
 
#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0
 
#define _D2_HOT_PLUG_HIGH                       1
#define _D2_HOT_PLUG_LOW                        0
 
#define _D3_HOT_PLUG_HIGH                       1
#define _D3_HOT_PLUG_LOW                        0
 
#define PCB_D0_HOTPLUG(x)                       {\
													 bD0_HPD = (x);\
												 }
 
#define PCB_D1_HOTPLUG(x)                       {\
													 bD1_HPD = (x);\
												 }
 
#define PCB_D2_HOTPLUG(x)                       {\
													 bD2_HPD = (x);\
												 }
 
#define PCB_D3_HOTPLUG(x)                       {\
													 bD3_HPD = (x);\
												 }
 
#define PCB_D0_HOTPLUG_DETECT()                 (bD0_HPD)
#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)
#define PCB_D2_HOTPLUG_DETECT()                 (bD2_HPD)
#define PCB_D3_HOTPLUG_DETECT()                 (bD3_HPD)
 
 
 ///////////////
 // MHL Macro //
 ///////////////
 
 
 
 
 ///////////////
 // PWM Macro //
 ///////////////
 
 //-----------------------------------------------
 // Macro of Pcb PWM Inital Setting
 //-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
													 ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 240);\
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
#define bLED1                                   (MCU_FE03_PORT43_PIN_REG) // Pin_AJ9
#define bLED2                                   (MCU_FE04_PORT44_PIN_REG) // Pin_AJ8
 
#define _LED_ON                                 1
#define _LED_OFF                                0
 
#define PCB_LED_AC_ON_INITIAL()                 {\
													 bLED1 = _LED_OFF;\
													 bLED2 = _LED_OFF;\
												 }
 
#define PCB_LED_ACTIVE()                        {\
													 bLED1 = _LED_ON;\
													 bLED2 = _LED_OFF;\
												 }
 
#define PCB_LED_IDLE()                          {\
													 bLED1 = _LED_OFF;\
													 bLED2 = _LED_ON;\
												 }
 
#define PCB_LED_POWER_SAVING()                  {\
													 bLED1 = _LED_OFF;\
													 bLED2 = _LED_ON;\
												 }
 
#define PCB_LED_ON()                            {\
													 bLED1 = _LED_OFF;\
													 bLED2 = _LED_ON;\
												 }
 
#define PCB_LED_OFF()                           {\
													 bLED1 = _LED_OFF;\
													 bLED2 = _LED_OFF;\
												 }
 
#define PCB_LED_TYPE1()                         {\
													 bLED1 = _LED_ON;\
												 }
 
#define PCB_LED_TYPE2()                         {\
													 bLED2 = _LED_ON;\
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
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT)// Pin_AH9
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT)// Pin_AH8
 
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
 
#define PCB_KEY_STATE(ucV0, ucV1,\
					   ucV2, ucV3, ucKeyState)	 {\
													 if((ucV2) < 0x20)\
													 {\
														 (ucKeyState) |= _LEFT_KEY_MASK;\
													 }\
													 if((0x40 <= (ucV2)) && ((ucV2) < 0x80))\
													 {\
														 (ucKeyState) |= _RIGHT_KEY_MASK;\
													 }\
													 if((0x90 <= (ucV2)) && ((ucV2) < 0xE0))\
													 {\
														 (ucKeyState) |= _EXIT_KEY_MASK;\
													 }\
													 if((ucV1) < 0x20)\
													 {\
														 (ucKeyState) |= _POWER_KEY_MASK;\
													 }\
													 if((0x40 <= (ucV1)) && ((ucV1) < 0x80))\
													 {\
														 (ucKeyState) |= _MENU_KEY_MASK;\
													 }\
													 if((0x90 <= (ucV1)) && ((ucV1) < 0xE0))\
													 {\
														 (ucKeyState) |= _EXIT_KEY_MASK;\
													 }\
												 }
 
 
 //////////////////
 // GPIO Macro	 //
 //////////////////
 
 
 
#endif// End of #if(_PCB_TYPE == _RL6410__318PIN__JY29XT_PH_WS_R20_1__2H2DP__eDPVB1LVDS)
