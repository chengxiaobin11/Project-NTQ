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
// ID Code      : User_Panel_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PANEL_EXIST_MULTIPANEL == _OFF)
#if(_PANEL_STYLE == _PANEL_LVDS)
#if(_LVDS_ULTRA_HIGH_SPEED_SUPPORT == _OFF)

#if(_PANEL_PIXEL_CLOCK_UNIT == _PANEL_CLOCK_KHZ)

#if(((_LVDS_OUTPUT_PORT == _LVDS_1_PORT) && (_PANEL_PIXEL_CLOCK_MAX > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_2_PORT) && ((_PANEL_PIXEL_CLOCK_MAX / 2) > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_4_PORT) && ((_PANEL_PIXEL_CLOCK_MAX / 4) > 97650)))
#undef _LVDS_ULTRA_HIGH_SPEED_SUPPORT
#define _LVDS_ULTRA_HIGH_SPEED_SUPPORT                  _ON
#endif

#elif(_PANEL_PIXEL_CLOCK_UNIT == _PANEL_CLOCK_MHZ)

#if(((_LVDS_OUTPUT_PORT == _LVDS_1_PORT) && ((_PANEL_PIXEL_CLOCK_MAX * 1000UL) > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_2_PORT) && (((_PANEL_PIXEL_CLOCK_MAX * 1000UL) / 2) > 97650)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_4_PORT) && (((_PANEL_PIXEL_CLOCK_MAX * 1000UL) / 4) > 97650)))
#undef _LVDS_ULTRA_HIGH_SPEED_SUPPORT
#define _LVDS_ULTRA_HIGH_SPEED_SUPPORT                  _ON
#endif

#endif

#endif
#endif
#endif
