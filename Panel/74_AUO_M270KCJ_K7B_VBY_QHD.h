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
#if(_PANEL_TYPE == _AUO_M270KCJ_K7B_VBY_QHD)
//----------------------------------------------------------------------------------------------------
// ID Code      : _AUO_VBO_27_WUXGA_FREESYNC.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define _PANNEL_NAME                            _P_,_N_,_L_,_,_COLON__,_,_M_,_2_,_7_,_0_,_K_,_C_,_J_,_K_,_7_,_B_

//////////////////
// General Info //
//////////////////
#define _PANEL_PRESET_MODE_FRAME_RATE            1650

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_VBO

//--------------------------------------------------
// Definitions for VBO Panel Configuration
//--------------------------------------------------
#define _VBO_BYTE_MODE                          _VBO_DISP_4_BYTE_MODE
#define _VBO_OUTPUT_PORT                        _VBO_8_DATA_LANE
#define _VBO_BIT_MODE                           _VBO_DISP_30_BIT
#define _VBO_PANEL_SECTION                      _VBO_PANEL_1_SECTION
#define _VBO_HS_CONTROL                         _VBO_HS_NORMAL
#define _VBO_VS_CONTROL                         _VBO_VS_NORMAL
#define _VBO_VIDEO_TRANSFER_TYPE                _VBO_VIDEO_TRANSFER_IN_VERTICAL_BLANK
#define _CDR_TRANSFER_ALN_LATENCY               0

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
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_30_BIT

//--------------------------------------------------
// Definitions for Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_TYP_FRAME_RATE                   600
#define _PANEL_MAX_FRAME_RATE                   1660
#define _PANEL_MIN_FRAME_RATE                   300

//--------------------------------------------------
// Definitions for FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE          1650
#define _PANEL_FREESYNC_MIN_FRAME_RATE          300


///////////////
// Parameter //
///////////////

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_START                         48
#define _PANEL_DH_WIDTH                         2560
#define _PANEL_DH_END                           2608

#define _PANEL_DH_TOTAL                         2880
#define _PANEL_DH_TOTAL_MAX               8184
#define _PANEL_DH_TOTAL_MIN              2608

#define _PANEL_DV_START                         6
#define _PANEL_DV_HEIGHT                        1440
#define _PANEL_DV_END                           1446

#define _PANEL_DV_TOTAL                     1481  
#define _PANEL_DV_TOTAL_MAX              8192
#define _PANEL_DV_TOTAL_MIN                1452

#define _PANEL_DH_SYNC_WIDTH                    8
#define _PANEL_DV_SYNC_HEIGHT                   2

#define _PANEL_PIXEL_CLOCK                256
#define _PANEL_PIXEL_CLOCK_MAX       700//  690//    720     // 设置成700，否则会走Memory，影响字体
#define _PANEL_PIXEL_CLOCK_MIN            200
//640x480异场---邋邋DCLK:559MHz




#define _PANEL_POWER_ON_T1                      5
#define _PANEL_POWER_ON_T2                      200
#define _PANEL_POWER_ON_T3                    600//  500

#define _PANEL_POWER_OFF_T4                     110
#define _PANEL_POWER_OFF_T5                     50
#define _PANEL_POWER_OFF_T6                     510

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

//--------------------------------------------------
// Definitions for Panel DCLK Unit
//--------------------------------------------------
#define _PANEL_PIXEL_CLOCK_UNIT                 _PANEL_CLOCK_MHZ


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

#endif // End of #if(_PANEL_TYPE == _AUO_VBO_27_WUXGA_FREESYNC)

