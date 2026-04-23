/********************************************************************************/
/*   Copyright (c) 2021 Realtek Semiconductor Corp. All rights reserved.        */
/*                                                                              */
/*   SPDX-License-Identifier: LicenseRef-Realtek-Proprietary                    */
/*                                                                              */
/*   This software component is confidential and proprietary to Realtek         */
/*   Semiconductor Corp. Disclosure, reproduction, redistribution, in whole     */
/*   or in part, of this work and its derivatives without express permission    */
/*   is prohibited.                                                             */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : Panel_Config_Pre_Check.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef __PANEL_CONFIG_PRE_CHECK_H__
#define __PANEL_CONFIG_PRE_CHECK_H__

//--------------------------------------------------
// Definitions for eDP Panel Configuration
//--------------------------------------------------
#if(_PANEL_STYLE == _PANEL_DPTX)

#ifdef _PANEL_DPTX_FORCE_OUTPUT_SUPPORT
#if(_PANEL_DPTX_FORCE_OUTPUT_SUPPORT == _ON)

#ifndef _PANEL_DPTX_FORCE_MSA_ENHANCE_FRAMING
#warning "Please Define _PANEL_DPTX_FORCE_MSA_ENHANCE_FRAMING at Panel.h for DPTX Force Output. Refer to the output of debug message _DEBUG_MESSAGE_CHECK_DISP_SETTING in ScalerDisplayDpTx1LinkConfig/ScalerDisplayDpTx2LinkConfig."
#endif

#ifndef _PANEL_DPTX_FORCE_MSA_DOWN_SPREAD
#warning "Please Define _PANEL_DPTX_FORCE_MSA_DOWN_SPREAD at Panel.h for DPTX Force Output. Refer to the output of debug message _DEBUG_MESSAGE_CHECK_DISP_SETTING in ScalerDisplayDpTx1LinkConfig/ScalerDisplayDpTx2LinkConfig."
#endif

#ifndef _PANEL_DPTX_FORCE_FRAMING_CHANGE_CAP
#warning "Please Define _PANEL_DPTX_FORCE_FRAMING_CHANGE_CAP at Panel.h for DPTX Force Output. Refer to the output of debug message _DEBUG_MESSAGE_CHECK_DISP_SETTING in ScalerDisplayDpTx1LinkConfig/ScalerDisplayDpTx2LinkConfig."
#endif

#ifndef _PANEL_DPTX_FORCE_ALTERNATE_SR_CAP
#warning "Please Define _PANEL_DPTX_FORCE_ALTERNATE_SR_CAP at Panel.h for DPTX Force Output. Refer to the output of debug message _DEBUG_MESSAGE_CHECK_DISP_SETTING in ScalerDisplayDpTx1LinkConfig/ScalerDisplayDpTx2LinkConfig."
#endif

#endif
#endif

#endif
///////////////////////////
// Color Characteristics //
///////////////////////////

//--------------------------------------------------
// Display HDR Option
//--------------------------------------------------
#if(_HDR10_SUPPORT == _ON)

#ifndef _PANEL_MAX_LUMINANCE
#warning "Please Define _PANEL_MAX_LUMINANCE at Panel.h for HDR10"
#endif

#ifndef _PANEL_MAX_FRAME_AVERAGE_LUMINANCE
#warning "Please Define _PANEL_MAX_FRAME_AVERAGE_LUMINANCE at Panel.h for HDR10"
#endif

//--------------------------------------------------
// HDR User Define Panel Max Lv
//--------------------------------------------------
#if(_HDR10_USER_DEFINE_PANEL_MAX_LV_SUPPORT == _ON)
#ifndef _PANEL_MAX_USER_DEFINE_LUMINANCE
#warning "_PANEL_MAX_USER_DEFINE_LUMINANCE should be defined at Panel.h when _HDR10_USER_DEFINE_PANEL_MAX_LV_SUPPORT is _ON"
#endif
#endif

#endif

//-------------------------------------------------
// Definitions for Panel Pixel Type
//-------------------------------------------------
#ifndef _PANEL_PIXEL_TYPE
#warning "_PANEL_PIXEL_TYPE should be defined at Panel.h"
#endif

#endif // End of #ifndef __PANEL_CONFIG_PRE_CHECK_H__

