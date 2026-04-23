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
// ID Code      : RL6851_Series_ScalerSyncInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
extern BYTE code tVIC_VFREQ_TABLE[256];
extern WORD code tVIC_HACTIVE_TABLE[256];
extern WORD code tVIC_HBLANK_TABLE[256];
extern WORD code tVIC_VACTIVE_TABLE[256];
extern WORD code tVIC_PIXEL_RATE_TABLE[256];
#endif

//------------------------------------------------------
// Definitions of DP Link Loss time interval check (ms)
//------------------------------------------------------
#define _DP_RX_LINK_LOSS_CHECK_INTERVAL                 30

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if((_FREESYNC_SUPPORT == _ON) || (_EMBEDDED_EDID_SUPPORT == _ON))
extern void ScalerSyncGetCtaExtDbAddress(WORD *pusCtaDataBlockAddr, BYTE *pucDdcRamAddr);
extern void ScalerSyncGetDidExtDbAddress(WORD *pusDidDataBlockAddr, BYTE *pucDdcRamAddr);
#endif

#if(_DP_SUPPORT == _ON)
#if(_HW_DIGITAL_PORT_COMBO_PHY_TYPE != _DIGITAL_PORT_COMBO_PHY_ALL)
extern void ScalerSyncDpMeasureCountInitial(void);
#endif
#endif

#if(_ADC_SUPPORT == _ON)
extern void ScalerSyncAdcApllPowerDown(void);
extern void ScalerSyncAdcPowerProc(EnumPowerAction enumPowerAction);
#endif

#if(_DDR_BURN_IN_TEST == _ON)
extern void ScalerSyncDDRBurnInCRCTest(void);
#endif
