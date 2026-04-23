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

#if(_PANEL_TYPE == _AUO_P320HVN05_0_144HZ)
//----------------------------------------------------------------------------------------------------
// ID Code      : Panel.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------
#define _PANEL_PRESET_MODE_FRAME_RATE            1650

//////////////////
// General Info // 
//////////////////
#define _PANNEL_NAME                            _P_,_N_,_L_,_,_COLON__,_,_T_,_3_,_2_,_0_,_H_,_V_,_N_,_0_,_5_,_0_



//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS

//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#if 0
#define _PANEL_TYP_FRAME_RATE                   1440
#define _PANEL_MAX_FRAME_RATE                   1460            
#define _PANEL_MIN_FRAME_RATE                 1200//  300//490

#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE          1440
#define _PANEL_FREESYNC_MIN_FRAME_RATE         1200//// 300//490
#endif
#endif

#define _PANEL_TYP_FRAME_RATE                   600
#define _PANEL_MAX_FRAME_RATE               1660//    1450
#define _PANEL_MIN_FRAME_RATE               500//    470


#if(_FREESYNC_SUPPORT == _ON)
	//--------------------------------------------------
	// FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
	//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE         1650// 1440
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480

#endif


//--------------------------------------------------
// Frame Sync Margin (Unit: 0.1Hz)
//--------------------------------------------------
#define _FRAME_SYNC_MARGIN                      20

//--------------------------------------------------
// Set Last Line Finetune Target (Must Be Larger than 4 Pixel!!)
//--------------------------------------------------
#define _LAST_LINE_TARGET                       (_PANEL_DH_TOTAL - 200)

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_AUO          

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_24_BIT 

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
         
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1_3

//--------------------------------------------------
// Definitions for LVDS Panel Configuration
//--------------------------------------------------
#define _LVDS_OUTPUT_PORT                       _LVDS_4_PORT
#define _LVDS_PANEL_SECTION                     _LVDS_PANEL_1_SECTION
#define _LVDS_CABLE_TYPE                        _LVDS_CABLE_TYPE_0






//--------------------------------------------------


//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#if 0
#define _PANEL_DH_START                         48                  // Display Horizontal Start Position
#define _PANEL_DH_WIDTH                         1920                // Display Horizontal Width
#define _PANEL_DH_END                           1968                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                      2100//   2120                // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     6000 //2280                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                  2080//   1972                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                   // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        1080                // Display Vertical Width
#define _PANEL_DV_END                           1086                // Display Vertical End Position

#define _PANEL_DV_TOTAL                     1105//    1125                // Display Vertical Total Clock Number in One Display Line
#if (_FREESYNC_SUPPORT==_ON)
#define _PANEL_DV_TOTAL_MAX                     8000  //1130              // Maxinum Display Vertical Total Clock Number in One Display Line
#else
#define _PANEL_DV_TOTAL_MAX                 1130//    1450                // Maxinum Display Vertical Total Clock Number in One Display Line
#endif
#define _PANEL_DV_TOTAL_MIN                 1100//    1090                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                   334//   309                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  500                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN           309//       128                 // Mininum Pixel Clock in MHz

#endif

#define _PANEL_DH_START                         48                  // Display Horizontal Start Position
#define _PANEL_DH_WIDTH                         1920                // Display Horizontal Width
#define _PANEL_DH_END                           1968                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         2120                // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX               2280//      2180                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                     2100                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                   // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        1080                // Display Vertical Width
#define _PANEL_DV_END                           1086                // Display Vertical End Position

#define _PANEL_DV_TOTAL                         1110                // Display Vertical Total Clock Number in One Display Line
#if(_FREESYNC_SUPPORT == _ON)
//144Hz <-> 48Hz so DV_Total = DV_Total * (144/48)
#define _PANEL_DV_TOTAL_MAX                4520//     3354                // Maxinum Display Vertical Total Clock Number in One Display Line
#else
#define _PANEL_DV_TOTAL_MAX                     1118               	// Maxinum Display Vertical Total Clock Number in One Display Line
#endif
#define _PANEL_DV_TOTAL_MIN                     1106                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      141                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX            400//      360                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  116                 // Mininum Pixel Clock in MHz

#define _PANEL_POWER_ON_T1                      20//100                 // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      20//40                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      720//300                 // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     20                  // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                   20//  0                  // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1050                 // Panel Power Off T6 (ms)


#define _PANEL_PIXEL_CLOCK_UNIT                 _PANEL_CLOCK_MHZ
#define BYPASS_VIDEO_COMPENSATION(Vin, Vout)    ((Vin) == ((Vout) >> 1))
#define _PANEL_ADC_OFFSET_BIAS                  (0)
#define _PANEL_ADC_GAIN_BIAS                    (0)


///////////////////////////
// Color Characteristics //
///////////////////////////
#define _PANEL_MAX_LUMINANCE                    0x62 // from OGC Tool
#define _PANEL_MAX_FRAME_AVERAGE_LUMINANCE      0x62 // from OGC Tool



/////////////////////////
// Color Default Table //
/////////////////////////

//--------------------------------------------------
// Color Default Value
//--------------------------------------------------
#include "./RTDColorDefaultTable/ColorTableInclude.h"


#endif

