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
// ID Code      : TypeC_Pmic_ONSEMI_NCP81239.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "UserCommonInclude.h"

#if(_TYPE_C_PMIC_TYPE == _PMIC_NCP81239)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of PMIC NCP81239
//--------------------------------------------------
#define _NCP81239_SUBADDR_LENGTH            0x01
#define _NCP81239_CTRL_REG00                0x00
#define _NCP81239_CTRL_REG01                0x01
#define _NCP81239_CTRL_REG02                0x02
#define _NCP81239_CTRL_REG03                0x03
#define _NCP81239_CTRL_REG04                0x04
#define _NCP81239_CTRL_REG05                0x05
#define _NCP81239_CTRL_REG06                0x06
#define _NCP81239_CTRL_REG07                0x07
#define _NCP81239_CTRL_REG08                0x08
#define _NCP81239_CTRL_REG09                0x09
#define _NCP81239_CTRL_REG0A                0x0A
#define _NCP81239_CTRL_REG10                0x10
#define _NCP81239_CTRL_REG11                0x11
#define _NCP81239_CTRL_REG12                0x12
#define _NCP81239_CTRL_REG13                0x13
#define _NCP81239_CTRL_REG14                0x14
#define _NCP81239_CTRL_REG15                0x15

//--------------------------------------------------
// Definitions of Pmic NCP81239 Control
//--------------------------------------------------
#define _TUNE_RISE                          0
#define _TUNE_FALL                          1
#define _PMIC_SOURCE                        1
#define _PMIC_SINK                          0

//--------------------------------------------------
// NCP81239 Initial Setting
//--------------------------------------------------
#define _SLEW_RATE                          0x00
#define _PWM_FREQ                           0x00
#define _OCP_CLIM_POS                       0x00
#define _OCP_CLIM_NEG                       0x00
#define _INT_MASK_CS_CLIND                  0x00
#define _INT_MASK_OVP                       0x00
#define _INT_MASK_OCP_P                     0x00
#define _INT_MASK_PG_INT                    0x00
#define _INT_MASK_TSD                       0x00
#define _INT_MASK_UVP                       0x00
#define _INT_MASK_VCHN                      0x00
#define _INT_MASK_IIC_ACK                   0x00
#define _INT_MASK_SHUT_DOWN                 0x00

//--------------------------------------------------
// Definitions of PMIC FUNCTION
//--------------------------------------------------
#define _TYPE_C_PMIC_DEBUG                  _OFF
#define _TYPE_C_PMIC_VOLTAGE_OFFSET         1      // unit: 0.1V

//--------------------------------------------------
// Definitions of PMIC Voltage Compesation
//--------------------------------------------------
#define _VOLTAGE_COMPESATION_CURRENT_UNIT   50     // unit: 10mA, 0.1V / _VOLTAGE_COMPESATION_CURRENT_UNIT

//--------------------------------------------------
// Macros of PMIC STATUS
//--------------------------------------------------
#define GET_PMIC_BIDIR_MODE()               (g_stPMICData.b1CR0BPmicDirection)
#define GET_PMIC_OUTPUT_ENABLE()            (PCB_PMIC_POWER_DETECT())

//--------------------------------------------------
// Macros of PMIC CHECK START
//--------------------------------------------------
#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
#define GET_PMIC_CHECK_START()              (g_bPmicCheckFlag)
#define SET_PMIC_CHECK_START()              (g_bPmicCheckFlag = _TRUE)
#define CLR_PMIC_CHECK_START()              (g_bPmicCheckFlag = _FALSE)
#endif


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b2CR00Reserved : 2;
    BYTE b1CR00EnMask : 1;
    BYTE b1CR00EnInternal : 1;
    BYTE b4CR00Reserved : 4;

    BYTE ucCR01DacTarget;

    BYTE b2CR02SlewRate : 2;
    BYTE b6CR02Reserved : 6;

    BYTE b3CR03PwmFreq : 3;
    BYTE b1CR03Reserved : 1;
    BYTE b1CR03DacLsb : 1;
    BYTE b3CR03Reserved : 3;

    BYTE b1CR04Pfet : 1;
    BYTE b1CR04Cfet : 1;
    BYTE b3CR04Reserved : 3;
    BYTE b1CR04Cs2DisCharge : 1;
    BYTE b2CR04Reserved : 2;

    BYTE b2CR05OcpClimPos : 2;
    BYTE b2CR05Reserved1 : 2;
    BYTE b2CR05OcpClimNeg : 2;
    BYTE b2CR05Reserved2 : 2;

    BYTE b2CR06Cs1Clind : 2;
    BYTE b2CR06Cs2Clind : 2;
    BYTE b4CR06Reserved : 4;

    BYTE b3CR07LoGmAmpSetting : 3;
    BYTE b1CR07GmManual : 1;
    BYTE b3CR07HiGmAmpSetting : 3;
    BYTE b1CR07GmAmpConfig : 1;

    BYTE b2CR08AmuxTrigger : 2;
    BYTE b3CR08AmuxSel : 3;
    BYTE b1CR08DisAdc : 1;
    BYTE b2CR08Reserved : 2;

    BYTE b1CR09IntMaskCsClind : 1;
    BYTE b1CR09IntMaskOvp : 1;
    BYTE b1CR09IntMaskOcpP : 1;
    BYTE b1CR09IntMaskPgInt : 1;
    BYTE b1CR09IntMaskTsd : 1;
    BYTE b1CR09IntMaskUvp : 1;
    BYTE b1CR09IntMaskVchn : 1;
    BYTE b1CR09IntMaskI2cAck : 1;

    BYTE b1CR0AIntMaskShutDown : 1;
    BYTE b7CR0AReserved : 7;

    BYTE b1CR0BPmicDirection : 1;
    BYTE b7CR0BReserved : 7;
    BYTE ucCR0CReserved;
    BYTE ucCR0DReserved;
    BYTE ucCR0EReserved;
    BYTE ucCR0FReserved;

    BYTE ucCR10VfbValue;
    BYTE ucCR11VinValue;
    BYTE ucCR12Cs2Value;
    BYTE ucCR13Cs1Value;

    BYTE b1CR14IntCsClindFlag : 1;
    BYTE b1CR14IntOvpFlag : 1;
    BYTE b1CR14IntOcpPFlag : 1;
    BYTE b1CR14IntPgIntFlag : 1;
    BYTE b1CR14IntTsdFlag : 1;
    BYTE b1CR14IntUvpFlag : 1;
    BYTE b1CR14IntVchnFlag : 1;
    BYTE b1CR14IntI2cAckFlag : 1;

    BYTE b1CR15IntShutDownFlag : 1;
    BYTE b7CR15Reserved : 7;
} StructNCP81239RegisterMap;

//****************************************************************************
// CODE TABLES
//****************************************************************************
StructNCP81239RegisterMap code g_stPmicInitialData =
{
    0x00,                              // Reserved
    0x00,                              // Hardware enable selected
    0x00,                              // Software control disable
    0x00,                              // Reserved

    0x32,                              // VBUS setting is 5V

    _SLEW_RATE,                        // Slwe rate by define
    0x00,                              // Reserved

    _PWM_FREQ,                         // by define
    0x00,                              // PWM freq Reserved
    0x00,                              // DAC resolution is 10mV
    0x00,                              // Reserved

    0x00,                              // PFET is disable
    0x00,                              // CFET is disable
    0x00,                              // Reserved
    0x00,                              // CS2 discharge is disable
    0x00,                              // Reserved

    _OCP_CLIM_POS,                     // internal positive current limit by define
    0x00,                              // Reserved
    _OCP_CLIM_NEG,                     // internal negative current limit by define
    0x00,                              // Reserved

    0x00,                              // CS1 positive current limit
    0x00,                              // CS2 positive current limit
    0x00,                              // Reserved

    0x01,                              // Low Amp GM value
    0x01,                              // register of amp gm settings
    0x05,                              // High Amp GM value
    0x00,                              // register of amp gm config

    0x00,                              // ADC Trigger
    0x00,                              // ADC MUX select
    0x00,                              // ADC is enable
    0x00,                              // Reserved

    _INT_MASK_CS_CLIND,                // cs_clind int flag enable by define
    _INT_MASK_OVP,                     // OVP int flag enable by define
    _INT_MASK_OCP_P,                   // OCP_P int flag enable by define
    _INT_MASK_PG_INT,                  // PG int flag enable by define
    _INT_MASK_TSD,                     // TSD int flag enable by define
    _INT_MASK_UVP,                     // UVP int flag enable by define
    _INT_MASK_VCHN,                    // VCHN int flag enable by define
    _INT_MASK_IIC_ACK,                 // IIC_ACK int flag enable by define

    _INT_MASK_SHUT_DOWN,               // SHUT_DOWN int flag enable by define
    0x00,                              // Reserved

    _PMIC_SINK,                        // Source/Sink status
    0x00,                              // Reserved
    0x00,                              // Reserved
    0x00,                              // Reserved
    0x00,                              // Reserved
    0x00,                              // Reserved

    0x00,                              // Vfb value(Read Only)
    0x00,                              // Vin value(Read Only)
    0x00,                              // CS2 value(Read Only)
    0x00,                              // CS1 value(Read Only)

    0x00,                              // CsClind flag(Read Only)
    0x00,                              // OVP flag(Read Only)
    0x00,                              // OCP_P flag(Read Only)
    0x00,                              // PG flag(Read Only)
    0x00,                              // TSD flag(Read Only)
    0x00,                              // UVP flag(Read Only)
    0x00,                              // VCHN flag(Read Only)
    0x00,                              // IIC_ACK flag(Read Only)

    0x00,                              // SHUT_DOWN flag(Read Only)
    0x00,                              // Reserved
};


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructNCP81239RegisterMap g_stPMICData;

#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
bit g_bPmicCheckFlag = _FALSE;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ExternalDeviceInterfaceTypeCPmicInitial(BYTE ucSlaveAddr);
void ExternalDeviceInterfaceTypeCPmicReset(BYTE ucSlaveAddr);
bit ExternalDeviceInterfaceTypeCPmicSetting(BYTE ucSlaveAddr, bit bAction, bit bPowerDirection, WORD usVoltage, WORD usCurrent);
BYTE ExternalDeviceInterfaceTypeCPmicSetting_EXINT0(BYTE ucSlaveAddr, bit bAction, bit bPowerDirection, WORD usVoltage, WORD usCurrent);
BYTE ExternalDeviceInterfaceTypeCPmicSetting_WDINT(BYTE ucSlaveAddr, bit bAction, bit bPowerDirection, WORD usVoltage, WORD usCurrent);
bit ExternalDeviceInterfaceTypeCPmicVbusDischarge(BYTE ucSlaveAddr, bit bEn);
BYTE ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(BYTE ucSlaveAddr, bit bEn);
#if(_TYPE_C_PMIC_CHECK_SUPPORT == _ON)
bit ExternalDeviceInterfaceTypeCPmicCheck(BYTE ucSlaveAddr);
bit ExternalDeviceInterfaceTypeCPmicTracking(BYTE ucSlaveAddr);
#if(_TYPE_C_PMIC_DEBUG == _ON)
bit ExternalDeviceInterfaceTypeCPmicStatus(BYTE ucSlaveAddr);
#endif
#endif


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : PMIC Initial Settings
// Input Value  : ucSlaveAddr : I2C Slave Address
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicInitial(BYTE ucSlaveAddr)
{
    ucSlaveAddr = ucSlaveAddr;

    g_stPMICData = g_stPmicInitialData;
}

//--------------------------------------------------
// Description  : PMIC Reset Settings
// Input Value  : ucSlaveAddr : I2C Slave Address
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicReset(BYTE ucSlaveAddr)
{
    ucSlaveAddr = ucSlaveAddr;

    PCB_PMIC_POWER(_POWER_OFF);

#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
    CLR_PMIC_CHECK_START();
#endif
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : ucSlaveAddr : I2C Slave Address
//                bAction : _ON / _OFF
//                bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 0 ~ 400 (Unit = 50mV) / usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
bit ExternalDeviceInterfaceTypeCPmicSetting(BYTE ucSlaveAddr, bit bAction, bit bPowerDirection, WORD usVoltage, WORD usCurrent)
{
    usCurrent = usCurrent;

    if(usVoltage > 400)
    {
        return _FAIL;
    }

    if(bAction == _ON)
    {
        if(bPowerDirection == _PMIC_SOURCE)
        {
            g_stPMICData.b1CR0BPmicDirection = _PMIC_SOURCE;
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_ON);
        }
        else
        {
            g_stPMICData.b1CR0BPmicDirection = _PMIC_SINK;
            PCB_PMIC_POWER(_POWER_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_ON);
            return _SUCCESS;
        }

        // Set VBUS Voltage
        g_stPMICData.ucCR01DacTarget = (BYTE)((usVoltage / 2) + _TYPE_C_PMIC_VOLTAGE_OFFSET);

        if(PCB_PMIC_POWER_DETECT() == _POWER_OFF)
        {
            if(ScalerTypeCPmicIICWrite(ucSlaveAddr, _NCP81239_CTRL_REG00, _NCP81239_SUBADDR_LENGTH, 11, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG00) == _FAIL)
            {
                return _FAIL;
            }

            PCB_PMIC_POWER(_POWER_ON);
        }
        else
        {
            if(ScalerTypeCPmicIICWrite(ucSlaveAddr, _NCP81239_CTRL_REG01, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG01) == _FAIL)
            {
                return _FAIL;
            }
        }
    }
    else
    {
        PCB_PMIC_POWER(_POWER_OFF);
        PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
        PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
    }

#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
    if((bAction == _ON) && (GET_PMIC_BIDIR_MODE() == _PMIC_SOURCE))
    {
        SET_PMIC_CHECK_START();
    }
    else
    {
        CLR_PMIC_CHECK_START();
    }
#endif

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : ucSlaveAddr : I2C Slave Address
//                bAction : _ON / _OFF
//                bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 0 ~ 400 (Unit = 50mV) / usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicSetting_EXINT0(BYTE ucSlaveAddr, bit bAction, bit bPowerDirection, WORD usVoltage, WORD usCurrent) using 1
{
    usCurrent = usCurrent;

    if(usVoltage > 400)
    {
        return _FAIL;
    }

    if(bAction == _ON)
    {
        if(bPowerDirection == _PMIC_SOURCE)
        {
            g_stPMICData.b1CR0BPmicDirection = _PMIC_SOURCE;
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_ON);
        }
        else
        {
            g_stPMICData.b1CR0BPmicDirection = _PMIC_SINK;
            PCB_PMIC_POWER(_POWER_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_ON);
            return _SUCCESS;
        }

        // Set VBUS Voltage
        g_stPMICData.ucCR01DacTarget = (BYTE)((usVoltage / 2) + _TYPE_C_PMIC_VOLTAGE_OFFSET);

        if(PCB_PMIC_POWER_DETECT() == _POWER_OFF)
        {
            if(ScalerTypeCPmicIICWrite_EXINT0(ucSlaveAddr, _NCP81239_CTRL_REG00, _NCP81239_SUBADDR_LENGTH, 11, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG00) == _FAIL)
            {
                return _FAIL;
            }

            PCB_PMIC_POWER(_POWER_ON);
        }
        else
        {
            if(ScalerTypeCPmicIICWrite_EXINT0(ucSlaveAddr, _NCP81239_CTRL_REG01, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG01) == _FAIL)
            {
                return _FAIL;
            }
        }
    }
    else
    {
        PCB_PMIC_POWER(_POWER_OFF);
        PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
        PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
    }

#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
    if((bAction == _ON) && (GET_PMIC_BIDIR_MODE() == _PMIC_SOURCE))
    {
        SET_PMIC_CHECK_START();
    }
    else
    {
        CLR_PMIC_CHECK_START();
    }
#endif

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : ucSlaveAddr : I2C Slave Address
//                bAction : _ON / _OFF
//                bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 0 ~ 400 (Unit = 50mV) / usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicSetting_WDINT(BYTE ucSlaveAddr, bit bAction, bit bPowerDirection, WORD usVoltage, WORD usCurrent) using 3
{
    usCurrent = usCurrent;

    if(usVoltage > 400)
    {
        return _FAIL;
    }

    if(bAction == _ON)
    {
        if(bPowerDirection == _PMIC_SOURCE)
        {
            g_stPMICData.b1CR0BPmicDirection = _PMIC_SOURCE;
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_ON);
        }
        else
        {
            g_stPMICData.b1CR0BPmicDirection = _PMIC_SINK;
            PCB_PMIC_POWER(_POWER_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_ON);
            return _SUCCESS;
        }

        // Set VBUS Voltage
        g_stPMICData.ucCR01DacTarget = (BYTE)((usVoltage / 2) + _TYPE_C_PMIC_VOLTAGE_OFFSET);

        if(PCB_PMIC_POWER_DETECT() == _POWER_OFF)
        {
            if(ScalerTypeCPmicIICWrite_WDINT(ucSlaveAddr, _NCP81239_CTRL_REG00, _NCP81239_SUBADDR_LENGTH, 11, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG00) == _FAIL)
            {
                return _FAIL;
            }

            PCB_PMIC_POWER(_POWER_ON);
        }
        else
        {
            if(ScalerTypeCPmicIICWrite_WDINT(ucSlaveAddr, _NCP81239_CTRL_REG01, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG01) == _FAIL)
            {
                return _FAIL;
            }
        }
    }
    else
    {
        PCB_PMIC_POWER(_POWER_OFF);
        PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
        PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
    }

#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
    if((bAction == _ON) && (GET_PMIC_BIDIR_MODE() == _PMIC_SOURCE))
    {
        SET_PMIC_CHECK_START();
    }
    else
    {
        CLR_PMIC_CHECK_START();
    }
#endif

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : ucSlaveAddr : I2C Slave Address
//                bEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
bit ExternalDeviceInterfaceTypeCPmicVbusDischarge(BYTE ucSlaveAddr, bit bEn)
{
    // Set PMIC VBUS Discharge status
    g_stPMICData.b1CR04Pfet = bEn;

    // Disable Pmic VBUS Discharge
    return ScalerTypeCPmicIICWrite(ucSlaveAddr, _NCP81239_CTRL_REG04, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG04);
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : ucSlaveAddr : I2C Slave Address
//                bEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(BYTE ucSlaveAddr, bit bEn) using 3
{
    // Set PMIC VBUS Discharge status
    g_stPMICData.b1CR04Pfet = bEn;

    // Disable Pmic VBUS Discharge
    return ScalerTypeCPmicIICWrite_WDINT(ucSlaveAddr, _NCP81239_CTRL_REG04, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG04);
}

#if(_TYPE_C_PMIC_CHECK_SUPPORT == _ON)
//--------------------------------------------------
// Description  : PMIC VBUS Check
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
bit ExternalDeviceInterfaceTypeCPmicCheck(BYTE ucSlaveAddr)
{
    ucSlaveAddr = ucSlaveAddr;

#if((_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON) || (_TYPE_C_PMIC_DEBUG == _ON))
    if(GET_PMIC_CHECK_START() == _TRUE)
    {
        CLR_PMIC_CHECK_START();
#if(_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON)
        ScalerTimerReactiveTimerEvent(20, _SCALER_TIMER_EVENT_PMIC_TRACKING);
#endif

#if(_TYPE_C_PMIC_DEBUG == _ON)
        ScalerTimerDelayXms(20);

        ExternalDeviceInterfaceTypeCPmicStatus(ucSlaveAddr);
#endif
        return _SUCCESS;
    }
#endif

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Check
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
bit ExternalDeviceInterfaceTypeCPmicTracking(BYTE ucSlaveAddr)
{
#if(_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON)
    WORD usCurrentValue = 0x0000;
    WORD usSchmittVIL = 0x0000;
    WORD usSchmittVIH = 0x0000;
#endif

    ucSlaveAddr = ucSlaveAddr;

#if(_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON)
    // If VBUS is source output, then keep tracking
    if((GET_PMIC_BIDIR_MODE() == _PMIC_SOURCE) && (GET_PMIC_OUTPUT_ENABLE() == _ON))
    {
        // Only source mode need to tracking
        ScalerTimerReactiveTimerEvent(200, _SCALER_TIMER_EVENT_PMIC_TRACKING);
    }
    else
    {
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_PMIC_TRACKING);
        return _SUCCESS;
    }

    // Translate Current of 10bSARADC to 10mA/bit
    usCurrentValue = ((WORD)((((DWORD)ScalerTypeCPowerGetAdcOutput(_TYPEC_UFP_IMON)) * 8 * 1000) / 1024 / 10));

    // Calculate VIL of compesation voltage
    usSchmittVIL = (GET_RX0_OUTPUT_VOL() / 2) + (usCurrentValue / _VOLTAGE_COMPESATION_CURRENT_UNIT) + _TYPE_C_PMIC_VOLTAGE_OFFSET;

    // Calculate VIH of compesation voltage
    usSchmittVIH = (GET_RX0_OUTPUT_VOL() / 2) + ((usCurrentValue + 5) / _VOLTAGE_COMPESATION_CURRENT_UNIT) + _TYPE_C_PMIC_VOLTAGE_OFFSET;

    if(g_stPMICData.ucCR01DacTarget < usSchmittVIL)
    {
        g_stPMICData.ucCR01DacTarget = usSchmittVIL;

        DebugMessageTypeC("0.Pmic:Currnet Value", usCurrentValue);
        DebugMessageTypeC("0.Pmic:Voltage Change", usSchmittVIL);

        if(ScalerTypeCPmicIICWrite(ucSlaveAddr, _NCP81239_CTRL_REG01, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG01) == _FAIL)
        {
            return _FAIL;
        }
    }
    else if(g_stPMICData.ucCR01DacTarget > usSchmittVIH)
    {
        g_stPMICData.ucCR01DacTarget = usSchmittVIH;

        DebugMessageTypeC("0.Pmic:Currnet Value", usCurrentValue);
        DebugMessageTypeC("0.Pmic:Voltage Change", usSchmittVIH);

        if(ScalerTypeCPmicIICWrite(ucSlaveAddr, _NCP81239_CTRL_REG01, _NCP81239_SUBADDR_LENGTH, 1, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG01) == _FAIL)
        {
            return _FAIL;
        }
    }
#endif // End of #if(_TYPE_C_PMIC_VOLTAGE_COMPENSATION == _ON)

    return _SUCCESS;
}

#if(_TYPE_C_PMIC_DEBUG == _ON)
//--------------------------------------------------
// Description  : PMIC Status
// Input Value  : ucSlaveAddr : I2C Slave Address
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
bit ExternalDeviceInterfaceTypeCPmicStatus(BYTE ucSlaveAddr)
{
    BYTE ucResult = 0;

    ucResult = ScalerTypeCPmicIICRead(ucSlaveAddr, _NCP81239_CTRL_REG10, _NCP81239_SUBADDR_LENGTH, 6, (BYTE *)(&g_stPMICData) + _NCP81239_CTRL_REG10);

    DebugMessageTypeC("0.Pmic:VFB Value", g_stPMICData.ucCR10VfbValue);
    DebugMessageTypeC("0.Pmic:Vin Value", g_stPMICData.ucCR11VinValue);
    DebugMessageTypeC("0.Pmic:CS2 Value", g_stPMICData.ucCR12Cs2Value);
    DebugMessageTypeC("0.Pmic:CS1 Value", g_stPMICData.ucCR13Cs1Value);
    DebugMessageTypeC("0.Pmic:Cs Clind Flag", g_stPMICData.b1CR14IntCsClindFlag);
    DebugMessageTypeC("0.Pmic:VBUS OVP Flag", g_stPMICData.b1CR14IntOvpFlag);
    DebugMessageTypeC("0.Pmic:OCP_P Flag", g_stPMICData.b1CR14IntOcpPFlag);
    DebugMessageTypeC("0.Pmic:Power Good Flag", g_stPMICData.b1CR14IntPgIntFlag);
    DebugMessageTypeC("0.Pmic:Thermal Sensor Flag", g_stPMICData.b1CR14IntTsdFlag);
    DebugMessageTypeC("0.Pmic:VBUS UVP Flag", g_stPMICData.b1CR14IntUvpFlag);
    DebugMessageTypeC("0.Pmic:Vchn Flag", g_stPMICData.b1CR14IntVchnFlag);
    DebugMessageTypeC("0.Pmic:IIC ACK Flag", g_stPMICData.b1CR14IntI2cAckFlag);
    DebugMessageTypeC("0.Pmic:Shut Down Flag", g_stPMICData.b1CR15IntShutDownFlag);

    return ucResult;
}
#endif // End of #if(_TYPE_C_PMIC_DEBUG == _ON)
#endif // End of #if(_TYPE_C_PMIC_CHECK_SUPPORT == _ON)
#endif // End of #if(_TYPE_C_PMIC_TYPE == _PMIC_NCP81239)

