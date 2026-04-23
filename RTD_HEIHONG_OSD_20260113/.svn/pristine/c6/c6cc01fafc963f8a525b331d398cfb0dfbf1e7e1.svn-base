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

#if(_PANEL_TYPE ==_BOE_MV315QHM_N40_LVDS_QHD75HZ)
//----------------------------------------------------------------------------------------------------
// ID Code      :175_BOE_MV315QHM_N40_LVDS_QHD75HZ.h No.0000
// Update Note  :
//通过FRC 最高超到120，画面变模糊

#define _PANEL_PRESET_MODE_FRAME_RATE            750

//////////////////
// General Info // 
//////////////////
#if(Project_ID == ID_HUIXIONG_HK2785E06_MV315QHM_N40_QHD90HZ_10BIT_EDID_X322Q90_20230713)
#define _PANNEL_NAME                            _P__,_N__,_L__,__,_COLON__,__,_M__,_V__,_3__,_1__,_5__,_Q__,_H__,_M__,_SLINE__,_N__,_4__,_0__
#elif(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define _PANNEL_NAME                            _P__,_N__,_L__,__,_COLON__,__,_S__,_G__,_2__,_7__,_0__,_1__,_G__,_0__,_1__,_SLINE__,_3__
#else
#define _PANNEL_NAME                            _P__,_N__,_L__,__,_COLON__,__,_M__,_3__,_1__,_5__,_Q__,_H__,_M__,_SLINE__,_4__,_0__
#endif

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
#if(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define  _LVDS_CABLE_TYPE				        _LVDS_CABLE_TYPE_0
#else
#define  _LVDS_CABLE_TYPE				        _LVDS_CABLE_TYPE_1
#endif
//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_BOE

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#if(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_24_BIT
#else
#define _PANEL_DISP_BIT_MODE                    _PANEL_DISP_30_BIT
#endif

//--------------------------------------------------
// Definitions for Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------


#define _PANEL_TYP_FRAME_RATE                   600

#if(_PANEL_QHD90HZ)
#define _PANEL_MAX_FRAME_RATE                   910
#elif(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define _PANEL_MAX_FRAME_RATE                   1000
#else
#define _PANEL_MAX_FRAME_RATE                   760
#endif

#define _PANEL_MIN_FRAME_RATE                   480

#if(_FREESYNC_SUPPORT == _ON)
	//--------------------------------------------------
	// FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
	//--------------------------------------------------
#if(_PANEL_QHD90HZ)
#define _PANEL_FREESYNC_MAX_FRAME_RATE          900
#elif(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define _PANEL_FREESYNC_MAX_FRAME_RATE           1000
#else
#define _PANEL_FREESYNC_MAX_FRAME_RATE          750
#endif
#define _PANEL_FREESYNC_MIN_FRAME_RATE          480

#endif


///////////////
// Parameter //
///////////////

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#if(Project_ID == ID_TJ_2556E01_SN270CS03_1_LOGO_FUEGO_27TZ180FIG2_FHD165_20240104)
#define _PANEL_DH_START                         48                  // Display Horizontal Start Position
#define _PANEL_DH_WIDTH                         2560                // Display Horizontal Width
#define _PANEL_DH_END                           2608                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         2968//2720//2760//20                // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     8000                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                    	2700//2676//2660//2716                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                   // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        1440                // Display Vertical Width
#define _PANEL_DV_END                           1446                // Display Vertical End Position

#define _PANEL_DV_TOTAL                         1490                // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     8000//8000                // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     1482                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      242                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  450                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  190                 // Mininum Pixel Clock in MHz


#define _PANEL_POWER_ON_T1                      20                  // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      20                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      500                 // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     250                 // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     30                  // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1100                // Panel Power Off T6 (ms)
#else
#define _PANEL_DH_START                         48                  // Display Horizontal Start Position
#define _PANEL_DH_WIDTH                         2560                // Display Horizontal Width
#define _PANEL_DH_END                           2608                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         2680//2720//2760//20                // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     4092                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                    	2660//2676//2660//2716                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                   // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        1440                // Display Vertical Width
#define _PANEL_DV_END                           1446                // Display Vertical End Position

#define _PANEL_DV_TOTAL                         1481                // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     9000//8000                // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     1452                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      242                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  400                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  190                 // Mininum Pixel Clock in MHz


#define _PANEL_POWER_ON_T1                      20                  // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      20                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      500                 // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     250                 // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     30                  // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1100                // Panel Power Off T6 (ms)
#endif

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

#endif



