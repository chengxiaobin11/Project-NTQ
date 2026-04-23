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
#if(_PANEL_TYPE == _LG_LM270WF9_SSA1_EDP_HBR2_FHD280HZ)
//----------------------------------------------------------------------------------------------------
// ID Code      : 108_LG_LM270WF9_SSA1_EDP_HBR2_FHD280HZ.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//////////////////
// General Info //
//////////////////
#define _PANEL_PRESET_MODE_FRAME_RATE            2400

#if(_CAIXIAOLI)//M270HTN02.E

//#define _PANNEL_NAME                            _P_,_A_,_N_,_E_,_L_,_,_COLON__,_,_M_,_2_,_7_,_0_,_H_,_T_,_N_,_0_,_2_,_DOT__,_E_
#define _PANNEL_NAME                            _P_,_A_,_N_,_E_,_L_,_,_COLON__,_,_M_,_2_,_4_,_1_,_H_,_T_,_N_,_0_,_1_,_DOT__,_7_

#else

#define _PANNEL_NAME                            _P_,_A_,_N_,_E_,_L_,_,_COLON__,_,_L_,_M_,_2_,_7_,_0_,_W_,_F_,_9_,_SLINE__,_S_,_S_,_A_,_1_

#endif
//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_DPTX

//--------------------------------------------------
// Definitions for DPTx  Panel Configuration
//--------------------------------------------------
/*
#define _PANEL_DPTX_LINK_RATE                   _PANEL_DPTX_LINK_HBR
#define _PANEL_DPTX_LANE_NUMBER                 _PANEL_DPTX_LANE_NUMBER_8


#define _PANEL_DPTX_LINK_RATE                   _PANEL_DPTX_LINK_HBR2
#define _PANEL_DPTX_LANE_NUMBER                 _PANEL_DPTX_LANE_NUMBER_4
*/
#define _PANEL_DPTX_LINK_RATE                   _PANEL_DPTX_LINK_HBR2
#define _PANEL_DPTX_LANE_NUMBER                 _PANEL_DPTX_LANE_NUMBER_4

#define _PANEL_DPTX_VENDOR_SPECIFIC_TYPE        _PANEL_DPTX_VENDOR_SPECIFIC_NONE
//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_AUO

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_24_BIT

//--------------------------------------------------
// Definitions for Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#if _FAKE_FREE
#define _PANEL_TYP_FRAME_RATE                   2400//1200
#define _PANEL_MAX_FRAME_RATE          		    2410//2410
#define _PANEL_MIN_FRAME_RATE                   480//650


#define _PANEL_FREESYNC_MAX_FRAME_RATE          2400//2800
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480//650

#else
#define _PANEL_TYP_FRAME_RATE                   2400//1200
#define _PANEL_MAX_FRAME_RATE          		    3000//2410
#define _PANEL_MIN_FRAME_RATE                   480//650


#define _PANEL_FREESYNC_MAX_FRAME_RATE          3000//2800
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480//650
#endif

///////////////
// Parameter //
///////////////

//--------------------------------------------------
#define _PANEL_DH_START                         48
#define _PANEL_DH_WIDTH                         1920
#define _PANEL_DH_END                           1968

#define _PANEL_DH_TOTAL                         2080
#define _PANEL_DH_TOTAL_MAX                     2720
#define _PANEL_DH_TOTAL_MIN                     2020//2000 // 2440 

#define _PANEL_DV_START                         6
#define _PANEL_DV_HEIGHT                        1080
#define _PANEL_DV_END                           1086

#define _PANEL_DV_TOTAL                         1112
#define _PANEL_DV_TOTAL_MAX                     8200//8200//6360
#define _PANEL_DV_TOTAL_MIN                     1098//1100

#define _PANEL_DH_SYNC_WIDTH                    8
#define _PANEL_DV_SYNC_HEIGHT                   2

#define _PANEL_PIXEL_CLOCK                      462
#define _PANEL_PIXEL_CLOCK_MAX                  720//670
#define _PANEL_PIXEL_CLOCK_MIN                  220	


#define _PANEL_POWER_ON_T1                      20//100
#define _PANEL_POWER_ON_T2                      150//30
#define _PANEL_POWER_ON_T3                      600//250//550

#define _PANEL_POWER_OFF_T4                     100
#define _PANEL_POWER_OFF_T5                     20
#define _PANEL_POWER_OFF_T6                     1100


/////////////
// Display //
/////////////

//--------------------------------------------------
// Definitions for Last Line Finetune Target
//--------------------------------------------------
#define _LAST_LINE_TARGET                       (_PANEL_DH_TOTAL - 300)

//--------------------------------------------------
// Definitions for Frame Sync Margin (Unit: 0.1Hz)
//--------------------------------------------------
#define _FRAME_SYNC_MARGIN                      20


///////////////////////////
// Color Characteristics //
///////////////////////////



/////////////////////////
// Color Default Table //
/////////////////////////

//--------------------------------------------------
// Color Default Value
//--------------------------------------------------
#include "./RTDColorDefaultTable/ColorTableInclude.h"

#endif


