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
#if(_PANEL_TYPE == _AUO_M300DVR01V0_VBY_QHD)
//----------------------------------------------------------------------------------------------------
// ID Code      : _AUO_VBO_27_WUXGA_FREESYNC.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define _PANNEL_NAME                            _P__,_N__,_L__,_,_COLON__,__,_M__,_3__,_5__,_0__,_D__,_V__,_R__,_0__,_1__,_V__,_0__
//----------------------------------------------------------------------------------------------------
// ID Code      : _INNOLUX_LED_VBO_40_UHD.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//////////////////
// General Info //
//////////////////
#define _PANEL_PRESET_MODE_FRAME_RATE            2000

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_VBO

//--------------------------------------------------
// Definitions for VBO Panel Configuration
//--------------------------------------------------
#define _VBO_BYTE_MODE                          _VBO_DISP_3_BYTE_MODE
#define _VBO_OUTPUT_PORT                        _VBO_8_DATA_LANE
#define _VBO_BIT_MODE                           _VBO_DISP_24_BIT
#define _VBO_PANEL_SECTION                      _VBO_PANEL_2_SECTION
#define _VBO_HS_CONTROL                         _VBO_HS_NORMAL
#define _VBO_VS_CONTROL                         _VBO_VS_NORMAL
#define _VBO_VIDEO_TRANSFER_TYPE                _VBO_VIDEO_TRANSFER_IN_VERTICAL_BLANK
#define _CDR_TRANSFER_ALN_LATENCY               9

//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_INNOLUX

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_24_BIT

//--------------------------------------------------
// Definitions for Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_TYP_FRAME_RATE                   1200
#define _PANEL_MAX_FRAME_RATE                   2010
#define _PANEL_MIN_FRAME_RATE                   480 

#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE         2000
#define _PANEL_FREESYNC_MIN_FRAME_RATE         480
#endif


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
#define _PANEL_DH_TOTAL_MAX           			8184
#define _PANEL_DH_TOTAL_MIN                     2664

#define _PANEL_DV_START                         6
#define _PANEL_DV_HEIGHT                        1080
#define _PANEL_DV_END                           1086

#define _PANEL_DV_TOTAL                         1130	
#define _PANEL_DV_TOTAL_MAX         		    5463 
#define _PANEL_DV_TOTAL_MIN                     1090

#define _PANEL_DH_SYNC_WIDTH                    8
#define _PANEL_DV_SYNC_HEIGHT                   2

#define _PANEL_PIXEL_CLOCK                      390
#define _PANEL_PIXEL_CLOCK_MAX                  680 
#define _PANEL_PIXEL_CLOCK_MIN                  320 

#define _PANEL_POWER_ON_T1                      130//50
#define _PANEL_POWER_ON_T2                      200//1
#define _PANEL_POWER_ON_T3                      700//650

#define _PANEL_POWER_OFF_T4               		 150
#define _PANEL_POWER_OFF_T5                		 30
#define _PANEL_POWER_OFF_T6              		 1010


/////////////
// Display //
/////////////

//--------------------------------------------------
// Definitions for Last Line Finetune Target
//--------------------------------------------------
#define _LAST_LINE_TARGET                       (_PANEL_DH_TOTAL - 150)

//--------------------------------------------------
// Definitions for Frame Sync Margin (Unit: 0.1Hz)
//--------------------------------------------------
#define _FRAME_SYNC_MARGIN                      20

//--------------------------------------------------
// Definitions for Panel DCLK Unit
//--------------------------------------------------
#define _PANEL_PIXEL_CLOCK_UNIT                 _PANEL_CLOCK_MHZ


////////////////////
// VGA Auto Color //
////////////////////

//--------------------------------------------------
// Definitions for ADC Gain/Offset Adjust
//--------------------------------------------------
#define _PANEL_ADC_OFFSET_BIAS                  (0)
#define _PANEL_ADC_GAIN_BIAS                    (0)


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

