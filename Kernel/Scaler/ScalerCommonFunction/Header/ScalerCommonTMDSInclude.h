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
// ID Code      : ScalerCommonTMDSInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Macros of Dx HDMI 5V Status
//--------------------------------------------------
#define GET_D1_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D1Hdmi5vPinDetect)
#define SET_D1_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D1Hdmi5vPinDetect = _TRUE)
#define CLR_D1_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D1Hdmi5vPinDetect = _FALSE)

#define GET_D2_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D2Hdmi5vPinDetect)
#define SET_D2_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D2Hdmi5vPinDetect = _TRUE)
#define CLR_D2_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D2Hdmi5vPinDetect = _FALSE)

#define GET_D3_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D3Hdmi5vPinDetect)
#define SET_D3_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D3Hdmi5vPinDetect = _TRUE)
#define CLR_D3_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D3Hdmi5vPinDetect = _FALSE)

#define GET_D4_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D4Hdmi5vPinDetect)
#define SET_D4_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D4Hdmi5vPinDetect = _TRUE)
#define CLR_D4_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D4Hdmi5vPinDetect = _FALSE)

#define GET_D5_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D5Hdmi5vPinDetect)
#define SET_D5_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D5Hdmi5vPinDetect = _TRUE)
#define CLR_D5_HDMI_5V_PIN_HIGH()                      (g_stTmdsMacRx5vPinDetect.b1D5Hdmi5vPinDetect = _FALSE)

//--------------------------------------------------
// Macro of HDMI Set SCDC Info
//--------------------------------------------------
#define GET_RX0_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1Rx0ScdcInfoSet)
#define SET_RX0_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1Rx0ScdcInfoSet = _TRUE)
#define CLR_RX0_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1Rx0ScdcInfoSet = _FALSE)

#define GET_RX1_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D1ScdcInfoSet)
#define SET_RX1_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D1ScdcInfoSet = _TRUE)
#define CLR_RX1_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D1ScdcInfoSet = _FALSE)

#define GET_RX2_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D2ScdcInfoSet)
#define SET_RX2_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D2ScdcInfoSet = _TRUE)
#define CLR_RX2_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D2ScdcInfoSet = _FALSE)

#define GET_RX3_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D3ScdcInfoSet)
#define SET_RX3_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D3ScdcInfoSet = _TRUE)
#define CLR_RX3_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D3ScdcInfoSet = _FALSE)

#define GET_RX4_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D4ScdcInfoSet)
#define SET_RX4_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D4ScdcInfoSet = _TRUE)
#define CLR_RX4_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D4ScdcInfoSet = _FALSE)

#define GET_RX5_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D5ScdcInfoSet)
#define SET_RX5_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D5ScdcInfoSet = _TRUE)
#define CLR_RX5_SCDC_INFO_SET()                        (g_stTmdsMacRxScdcInfoSet.b1D5ScdcInfoSet = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b1D1Hdmi5vPinDetect : 1;
    BYTE b1D2Hdmi5vPinDetect : 1;
    BYTE b1D3Hdmi5vPinDetect : 1;
    BYTE b1D4Hdmi5vPinDetect : 1;
    BYTE b1D5Hdmi5vPinDetect : 1;
} Struct5vPinDetect;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern Struct5vPinDetect g_stTmdsMacRx5vPinDetect;
extern StructScdcInfoSet g_stTmdsMacRxScdcInfoSet;
#endif
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_MAC_PAGE2_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
extern void ScalerTMDSRx0GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
extern void ScalerTMDSRx0GetHDR10Data(BYTE *pucHDRData);
#endif

#endif

#if(_HDMI_MAC_PAGE71_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
extern void ScalerTMDSRx2GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
extern void ScalerTMDSRx2GetHDR10Data(BYTE *pucHDRData);
#endif

#endif

#if(_HDMI_MAC_PAGE72_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
extern void ScalerTMDSRx3GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
extern void ScalerTMDSRx3GetHDR10Data(BYTE *pucHDRData);
#endif
#endif

#if(_HDMI_MAC_PAGE73_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
extern void ScalerTMDSRx4GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
extern void ScalerTMDSRx4GetHDR10Data(BYTE *pucHDRData);
#endif
#endif

#if(_HDMI_MAC_PAGE74_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
extern void ScalerTMDSRx5GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
extern void ScalerTMDSRx5GetHDR10Data(BYTE *pucHDRData);
#endif
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
extern bit ScalerTMDSRxGetCableStatus(BYTE ucInputPort);
extern void ScalerTMDSHdmiSetScdcInfo(BYTE ucInputPort);
extern void ScalerTMDSHdmiSetScdcInfoProc(BYTE ucInputPort);
extern void ScalerTMDSHdmiResetScdcInfo(BYTE ucInputPort);
extern void ScalerTMDSHdmiSetScdcInfoFlag(BYTE ucInputPort, bit bValue);
extern bit ScalerTMDSHdmiGetScdcInfoFlag(BYTE ucInputPort);
extern void ScalerTMDSHdmiHpd5vPinCheckEvent(BYTE ucInputPort, bit bEnable);
extern void ScalerTMDSHdmiHpd5vPinCheckProc(BYTE ucInputPort);
extern void ScalerTMDSHdmiHpd5vPinCheck(BYTE ucInputPort);
extern bit ScalerTMDSHdmiHpd5vPinDetect(BYTE ucInputPort);
extern void ScalerTMDSHdmiSetHpd5vPinHighFlag(BYTE ucInputPort, bit bValue);
extern bit ScalerTMDSHdmiGetHpd5vPinHighFlag(BYTE ucInputPort);
extern BYTE ScalerTMDSHdmiGetHwVersion(void);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern EnumFreeSyncSupport ScalerTMDSHdmiGetFreeSyncSupport(BYTE ucInputPort);
extern void ScalerTMDSHdmiSetAmdAupiScdcInfo(BYTE ucInputPort, bit bEnable);
#endif
#endif
#endif // End of #if(_HDMI_SUPPORT == _ON)

