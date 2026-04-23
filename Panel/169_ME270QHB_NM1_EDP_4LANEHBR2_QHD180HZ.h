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

#if(_PANEL_TYPE == _ME270QHB_NM1_EDP_8LANEHBR_QHD180HZ)
//----------------------------------------------------------------------------------------------------
// ID Code      : 167_INN_M315KCA_E7B_EDP_HBR2_QHD165HZ No.0000
// Update Note  :


#define _PANEL_PRESET_MODE_FRAME_RATE            1650

//////////////////
// General Info // 
//////////////////
#if(Project_ID == ID_TJZG_HK2775E05_M270KCAD8B_EDP4LANHBR2_MD2769_QHD180HZ_20240313)
#if _SN270ES01_1
#define _PANNEL_NAME                           _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_S__,_N__,_2__,_7__,_0__,_E__,_S__,_0__,_1__,_SLINE__,_1__
#else
#define _PANNEL_NAME                           _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_M__,_2__,_7__,_0__,_K__,_C__,_A__,_SLINE__,_D__,_8__,_B__
#endif
#elif(Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_20240426)
#define _PANNEL_NAME                           _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_S__,_N__,_2__,_7__,_0__,_E__,_S__,_0__,_1__,_SLINE__,_1__
#else
#define _PANNEL_NAME                           _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_S__,_G__,_2__,_7__,_0__,_1__,_G__,_0__,_3__,_SLINE__,_3__
#endif
//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_DPTX
#define _PANEL_PIXEL_TYPE                       _PANEL_PIXEL_LCD

//--------------------------------------------------
// Definitions for DPTx Panel Configuration
//--------------------------------------------------
#define _PANEL_DPTX_LINK_RATE                   _PANEL_DPTX_LINK_HBR
#define _PANEL_DPTX_LANE_NUMBER                 _PANEL_DPTX_LANE_NUMBER_8
#define _PANEL_DPTX_VENDOR_SPECIFIC_TYPE        _PANEL_DPTX_VENDOR_SPECIFIC_NONE

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
#define _PANEL_TYP_FRAME_RATE                 	1200//600
#define _PANEL_MAX_FRAME_RATE                  	1810//1810
#define _PANEL_MIN_FRAME_RATE                	480

#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// FREESYNC Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_FREESYNC_MAX_FRAME_RATE         	1810
#define _PANEL_FREESYNC_MIN_FRAME_RATE        	480
#endif

///////////////
// Parameter //
///////////////

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_START                         48
#define _PANEL_DH_WIDTH                         2560
#define _PANEL_DH_END                           	2608

#define _PANEL_DH_TOTAL            			    2720
#define _PANEL_DH_TOTAL_MAX       			    3120
#define _PANEL_DH_TOTAL_MIN          		    2664

#define _PANEL_DV_START                         10
#define _PANEL_DV_HEIGHT                        1440
#define _PANEL_DV_END                           	1450

#define _PANEL_DV_TOTAL                         1500
#define _PANEL_DV_TOTAL_MAX  				    6448
#define _PANEL_DV_TOTAL_MIN    				    1461

#define _PANEL_DH_SYNC_WIDTH                    8
#define _PANEL_DV_SYNC_HEIGHT                   2

#define _PANEL_PIXEL_CLOCK                			588
#define _PANEL_PIXEL_CLOCK_MAX         			720
#define _PANEL_PIXEL_CLOCK_MIN      			220


#define _PANEL_POWER_ON_T1                      10  //20                // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      200                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      500                 // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     250                 // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     40  //30                // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     1200  //1100               // Panel Power Off T6 (ms)



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

