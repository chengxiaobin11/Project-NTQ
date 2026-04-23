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

#if(_PANEL_TYPE == _INNOLUX_M270KCJ_L5B_LVDS_QHD)
//----------------------------------------------------------------------------------------------------
// ID Code      : _INNOLUX_M270KCJ_L5B_LVDS_QHD.h No.0000
// Update Note  :


#define _PANEL_PRESET_MODE_FRAME_RATE            750

//////////////////
// General Info // 
//////////////////

#define _PANNEL_NAME                        	_P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_S__,_N__,_2__,_7__,_0__,_E__,_S__,_0__,_2__,_SLINE__,_2__
//#define _PANNEL_NAME                            _P__,_N__,_L__,__,_COLON__,__,_M__,_2__,_7__,_0__,_K__,_C__,_J__,_SLINE__,_L__,_5__,_B__

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS

//--------------------------------------------------
// Definitions for LVDS Panel Configuration
//--------------------------------------------------
#define _LVDS_OUTPUT_PORT                       _LVDS_4_PORT
#define _LVDS_PANEL_SECTION                     _LVDS_PANEL_1_SECTION
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1_3
#define  _LVDS_CABLE_TYPE						_LVDS_CABLE_TYPE_0//_LVDS_CABLE_TYPE_1
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
#if(_EDID_QHD100HZ)
#define _PANEL_TYP_FRAME_RATE                   600
#define _PANEL_MAX_FRAME_RATE                   1010
#define _PANEL_MIN_FRAME_RATE                   480

//--------------------------------------------------
// FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE          1000
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480//300


#define _PANEL_DH_START                         48                  // Display Horizontal Start Position: (20+8)*4
#define _PANEL_DH_WIDTH                         2560                // Display Horizontal Width: 640*4
#define _PANEL_DH_END                           2608                // Display Horizontal End Position: 640*4 + (20+8)*4

#define _PANEL_DH_TOTAL                         2792//2720                // Display Horizontal Total Clock Number in One Display Line: 680*4
#define _PANEL_DH_TOTAL_MAX                     8000//4092                // Maxinum Display Horizontal Total Clock Number in One Display Line: 684*4
#define _PANEL_DH_TOTAL_MIN                     2676//2720//2776//2660//716                // Mininum Display Horizontal Total Clock Number in One Display Line: 676*4

#define _PANEL_DV_START                         6                   // Display Vertical Start Position: (33+5)
#define _PANEL_DV_HEIGHT                        1440                // Display Vertical Width
#define _PANEL_DV_END                           1446                // Display Vertical End Position: 1440 + (33+5)

#define _PANEL_DV_TOTAL                         1481                // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     8000//2347                // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     1452//1479//1452                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width: 8*4
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      340//242                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  440//420//306                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  300//193                 // Mininum Pixel Clock in MHz

#define _PANEL_POWER_ON_T1                      10// 20//1                  // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      40//20//5                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      600//550                 // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     250                 // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     30//20                  // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1010//1100                // Panel Power Off T6 (ms)


#else
#define _PANEL_TYP_FRAME_RATE                   600
#define _PANEL_MAX_FRAME_RATE                  	760
#define _PANEL_MIN_FRAME_RATE                   480

//--------------------------------------------------
// Definitions for FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE          750
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480


///////////////
// Parameter //
///////////////

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_START                         48                  // Display Horizontal Start Position
#define _PANEL_DH_WIDTH                         2560                // Display Horizontal Width
#define _PANEL_DH_END                           2608                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         2720//2792                // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     4000//2800                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                     2656//2680//2784                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                   // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        1440                // Display Vertical Width
#define _PANEL_DV_END                           1446                // Display Vertical End Position

#define _PANEL_DV_TOTAL                         1481                // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     8000//3000//1487                // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     1456//1479                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      248                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  400//312                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  110//190                 // Mininum Pixel Clock in MHz


#define _PANEL_POWER_ON_T1                      20                  // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      20                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      550                 // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     150                 // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     25                  // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1300                // Panel Power Off T6 (ms)
#endif

/////////////
// Display //
/////////////

//--------------------------------------------------
// Definitions for Last Line Finetune Target
//--------------------------------------------------
#define _LAST_LINE_TARGET                       (_PANEL_DH_TOTAL - 200)

//--------------------------------------------------
// Definitions for Frame Sync Margin (Unit: 0.1Hz)
//--------------------------------------------------
#define _FRAME_SYNC_MARGIN                      20

//--------------------------------------------------
// Definitions for Panel DCLK Unit
//--------------------------------------------------
#define _PANEL_PIXEL_CLOCK_UNIT                 _PANEL_CLOCK_MHZ

//--------------------------------------------------
// Definitions for video compensation
//-------------------------------------------------
#define BYPASS_VIDEO_COMPENSATION(Vin, Vout)    ((Vin) == ((Vout) >> 1))


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
#define _PANEL_MAX_LUMINANCE                    0x62 // from OGC Tool
#define _PANEL_MAX_FRAME_AVERAGE_LUMINANCE      0x62 // from OGC Tool



/////////////////////////
// Color Default Table //
/////////////////////////

//--------------------------------------------------
// Color Default Value
//--------------------------------------------------
#include "./RTDColorDefaultTable/ColorTableInclude.h"

#endif // End of #if(_PANEL_TYPE == _AUO_M270DAN02V0_LVDS_QHD)

