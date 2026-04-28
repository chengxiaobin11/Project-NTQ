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
// ID Code      : RTD2014OsdDisplay.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDDISPLAY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)
#if (_LED_EFFECT_TJMODE14==_ON)
extern BYTE led_start;
#endif
BYTE Cross_flag = 0;

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _VGA_A0 = 0x01,
} EnumOsdSourceTypeVga;

typedef enum
{
    _DVI = 0x02,
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
    _DVI_D0,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    _DVI_D1,
#endif
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
    _DVI_D2,
#endif
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
    _DVI_D3,
#endif
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
    _DVI_D4,
#endif
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
    _DVI_D5,
#endif

    _HDMI = 0x10,
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
    _HDMI_D0,
#endif
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    _HDMI_D1,
#endif
#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
    _HDMI_D2,
#endif
#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
    _HDMI_D3,
#endif
#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
    _HDMI_D4,
#endif
#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
    _HDMI_D5,
#endif
}EnumOsdSourceTypeTMDS;

typedef enum
{
    _DP = 0x0E,
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    _DP_D0,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    _DP_D1,
#endif
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    _DP_D2,
#endif
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
    _DP_D6,
#endif
} EnumOsdSourceTypeDP;

//****************************************************************************
// CODE TABLES
//****************************************************************************





//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UpdateMaskValue(void);
BYTE OsdDisplayGetSourcePortString(void);


BYTE OsdDispJudgeSourceType(void);
void OsdDispDisableOsd(void);
void OsdDispSetPosition(BYTE ucType, EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos);
void OSDSubMenuMove(void);

void OsdTextEDIDInfo();//RTDBurnInMenu

WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
void OsdDispOsdMessage(EnumOSDDispMsg enumMessage);

#if(_VGA_SUPPORT == _ON)
void OsdDispAutoConfigProc(void);
void OsdDisplayAutoBalanceProc(void);
#endif
int SwapRotateValue(int value);

void OsdDispOsdReset(void);
void OsdDispShowLogo(void);

void OsdDispSliderAndNumber(BYTE ucItemRow,BYTE ucOsdState, WORD usValue);
void OsdDispNavigatMenu(void);
void RTDOsdDispHotkeyFuncAdjust(BYTE ucHotkeyType);
void RTDOsdDisplayDrawMessageWindow(WORD usValue);
WORD DetOverRangeForHotkeySelect(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
void UpdateItemMaskValue(void);

#if(_DEF_STA_SIX_COLOR)
void OsdDisplaySixColorGetOneColor(BYTE ucColor);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_NAVIGAT_MENU_SURPPORT)

void OsdDispDisableOsdForNavigat(void)
{
    SET_OSD_STATE(_MENU_NAVIGAT_NONE);
    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncDisableOsd();
    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
    g_ucOsdWidth = 0;
    g_ucOsdHeight = 0;
    g_ucOsdWidthB = 0;
    g_ucOsdHeightB = 0;
}
#endif

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
#if(_NAVIGAT_MENU_SURPPORT)

void OsdDispNavigatMenu(void)
{
    OsdDispDisableOsdForNavigat();
    
    OsdFuncApplyMap(WIDTH(_OSD_NAVIGAT_MENU_WIDTH), HEIGHT(_OSD_NAVIGAT_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(_OSD_NAVIGAT_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);

    //20140210 Abel Background window Modify
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), HEIGHT(g_ucOsdWidth), _COLOR_BG_0);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(g_ucOsdHeight-12),HEIGHT(g_ucOsdWidth), _COLOR_BG_0);
    }
    else
#endif
    {
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(6), XEND(_OSD_NAVIGAT_MENU_WIDTH * 12), YEND(18*_OSD_NAVIGAT_MENU_HEIGHT - 5), _COLOR_BG_0);
    }

    OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_TOP_NAVIGATE_MSG, COLOR(_COLOR_BG_0, _CP_BG), 0);
    OsdFontPut1BitTable( ROW(_OSD_NAVIGAT_MENU_HEIGHT-2), COL(0), tOSD_iNAVIGATE_ICON, COLOR(_COLOR_BG_1, _CP_BG), 0);
    OsdFontPut1BitTable( ROW(_OSD_NAVIGAT_MENU_HEIGHT-1), COL(0), tOSD_BOARD_BOTTOM_NAVIGATE_MSG, COLOR(_COLOR_BG_0, _CP_BG), 0);    

	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, GET_OSD_ROTATE_STATUS()? 5:95, GET_OSD_ROTATE_STATUS()?0:100);
	
	#if(2160 <= _PANEL_DV_HEIGHT)
	if(!GET_OSD_ROTATE_STATUS())
		ScalerSetByte(0x3A2C, 0x3e);
	#endif

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();
}
#endif
//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------

void RTDOsdDisplayDrawMessageWindow(WORD usValue)
{
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;

    
#if(_NAVIGAT_MENU_SURPPORT)
	OsdDispDisableOsdForNavigat();
#else
	OsdDispDisableOsd();
#endif
if(GetOsdShowType(usValue) == _TYPE_SLIDER)
    OsdFuncApplyMap(WIDTH(22), HEIGHT(3), COLOR(_CP_DARKBLUE, _CP_BG));
else
    OsdFuncApplyMap(WIDTH(30), HEIGHT(9), COLOR(_CP_DARKBLUE, _CP_BG));
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    if(GetOsdShowType(usValue) == _TYPE_SLIDER)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(3), _DISABLE, 0, _ENABLE);
    else
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(9), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
#if(_OSD_BLACK_WHITE_TYPE == _ON)
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(312+48), YEND(152), _COLOR_BG_0);        
        OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(19), XEND(312+48), YEND(138), _CP_WHITE);    
        OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(23), XEND(312+48), YEND(134), _COLOR_BG_3);    
#else
        if(GetOsdShowType(usValue) == _TYPE_SLIDER)
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(22*12), YEND(3*18), _COLOR_WINDOW_BG);     
        else
        {
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(30*12), YEND(9*18), _COLOR_WINDOW_BG);     
            OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(0), XEND(312+48), YEND(2*18), _OSD_BLACK_TYPE);    

        }
#endif
if(GetOsdShowType(usValue) != _TYPE_SLIDER)
{

OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_MSG_HOTHEY, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
OsdFontPut1BitTable( ROW(8), COL(0), tOSD_BOARD_DOWN_LEFT_MSG_HOTHEY,COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

}

}
#if(_CUSTOM_TYPE == _FKX_CUSTOMER)

void RTDOsdDisplayDrawMessageWindowSmall(void)
{
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;

    
#if(_NAVIGAT_MENU_SURPPORT)
	OsdDispDisableOsdForNavigat();
#else
	OsdDispDisableOsd();
#endif
    OsdFuncApplyMap(WIDTH(30), HEIGHT(3), COLOR(_CP_DARKBLUE, _CP_BG));
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(3), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
#if(_OSD_BLACK_WHITE_TYPE == _ON)
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(312+48), YEND(152), _COLOR_BG_0);        
        OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(19), XEND(312+48), YEND(138), _CP_WHITE);    
        OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(23), XEND(312+48), YEND(134), _COLOR_BG_3);    
#else
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(360), YEND(54), _COLOR_WINDOW_BG);        
		//OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(0), XEND(312+48), YEND(2*18), _COLOR_MENU_FONT_SELECT);    
#endif
        // OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_MSG_HOTHEY, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
		//OsdFontPut1BitTable( ROW(8), COL(0), tOSD_BOARD_DOWN_LEFT_MSG_HOTHEY,COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

}

 #endif
//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------

void OsdInputSourceHotkey()
{
	BYTE i = 0;
	BYTE OSD_SOURCE_SPE = 0;
#if(_OSD_BLACK_TYPE)	//��ɫ
	OSD_SOURCE_SPE = 3;
#else
	OSD_SOURCE_SPE = 1;
#endif
    OsdDispDisableOsd();
		
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;

    SET_OSD_STATE(_MENU_FUN_SOURCE_HOTKEY);
	OsdFuncApplyMap(WIDTH(13), HEIGHT((OSD_SOURCE_SPE+7)+_OSD_INPUT_AMOUNT*2), COLOR(_COLOR_BG_0, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT((OSD_SOURCE_SPE+7)+_OSD_INPUT_AMOUNT*2), _DISABLE, 0, _ENABLE);
#endif

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
	OsdFuncSetOsdItemFlag();

	
     g_usBackupValue =  GET_OSD_INPUT_PORT_OSD_ITEM();

				

	{
    #if(_OSD_BLACK_WHITE_TYPE == _ON)    
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(156), YEND(80+(_OSD_INPUT_AMOUNT-1)*36), _COLOR_BG_0);                
        OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(14), XEND(156), YEND(72+(_OSD_INPUT_AMOUNT-1)*36), _CP_WHITE);    
        OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(18), XEND(156), YEND(68+(_OSD_INPUT_AMOUNT-1)*36), _COLOR_BG_3);  
    #else
#if(!_OSD_BLACK_TYPE) 	//��ɫ
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(12*13), YEND((3+_OSD_INPUT_AMOUNT*2)*18), _COLOR_WINDOW_BG);
#else
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(12*13), YEND((5+_OSD_INPUT_AMOUNT*2)*18), _COLOR_WINDOW_BG);
        OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(0), XEND(12*13), YEND(36), _OSD_BLACK_TYPE);    
#endif
	#endif
		OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_INPUT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
		OsdFontPut1BitTable( ROW(OSD_SOURCE_SPE+_OSD_INPUT_AMOUNT*2+1), COL(0), tOSD_BOARD_DOWN_LEFT_INPUT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
	}

	for(i = 0; i < _OSD_INPUT_AMOUNT; i++)
//		RTDOsdTableFuncPutStringCenter(ROW(OSD_SOURCE_SPE+i*2), COL(0), COL(12), _PFONT_PAGE_0, _MENU_FUN_SIGNAL, i,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());					 
    RTDOsdTableFuncPutStringProp(ROW(OSD_SOURCE_SPE+i*2), COL(1),  _PFONT_PAGE_0, _MENU_FUN_SIGNAL, i,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//selected color
	OsdWindowDrawingHighlight(_OSD_WINDOW_4_1, 0, (OSD_SOURCE_SPE+GET_OSD_INPUT_PORT_OSD_ITEM()*2)*18, 12*12, ((OSD_SOURCE_SPE+1)+GET_OSD_INPUT_PORT_OSD_ITEM()*2)*18, _COLOR_WINDOW_BG, _CP_RED, _CP_BG, _ENABLE); 

#if(_WCH_MESSAGE_ADDR)
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
#else

	if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_180)
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 2, 98);
	else if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_90)
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 98);
	else if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270)
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 2, 2);
	else
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 2);
#endif
	//OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 2);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}



#define  ENERGY_MENU_HEIGHT       13
#define  ENERGY_MENU_WEIGHT      39

#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)

void OsdDispOsdMessageEngerConsumption(void)
{
    SET_OSD_STATE(_MENU_ENGER_CONSUMPTION);
    SET_OSD_ENGER(_ON);


    OsdFuncApplyMap(WIDTH(ENERGY_MENU_WEIGHT), HEIGHT(ENERGY_MENU_HEIGHT), COLOR(_CP_DARKBLUE, _CP_BG));
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(ENERGY_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
#if(_OSD_BLACK_WHITE_TYPE == _ON)
        OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(312+48), YEND(152), _COLOR_BG_0);        
        OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(19), XEND(312+48), YEND(138), _CP_WHITE);    
        OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(23), XEND(312+48), YEND(134), _COLOR_BG_3);    
#else
//	OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(312+48+36), YEND(152), _COLOR_BG_0);        
	OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(ENERGY_MENU_WEIGHT*12), YEND((ENERGY_MENU_HEIGHT-10)*18), _CP_RED);        

	OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART((ENERGY_MENU_HEIGHT-10)*18), XEND(ENERGY_MENU_WEIGHT*12), YEND(ENERGY_MENU_HEIGHT*18-4), _CP_BLACK);    
#endif
//OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_MSG_HOTHEY_2, COLOR(_COLOR_BG_0, _CP_BG), 0);
//OsdFontPut1BitTable( ROW(8), COL(0), tOSD_BOARD_DOWN_LEFT_MSG_HOTHEY_2, COLOR(_COLOR_BG_0, _CP_BG), 0);
OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_MSG_HOTHEY_2, COLOR(_CP_LIGHTGRAY, _CP_BG), 0);
OsdFontPut1BitTable( ROW(12), COL(0), tOSD_BOARD_DOWN_LEFT_MSG_HOTHEY_2, COLOR(_CP_LIGHTGRAY, _CP_BG), 0);



	RTDOsdTableFuncPutStringCenter(ROW(5), 0, (ENERGY_MENU_WEIGHT-1), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_1, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, 0);		
//#if _ITALIAN_SUPPORT
//if((GET_OSD_LANGUAGE()==_FRENCH)||(GET_OSD_LANGUAGE()==_ITALIAN))
//{
//	RTDOsdTableFuncPutStringProp(ROW(2+1), COL(2), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_2,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//	RTDOsdTableFuncPutStringProp(ROW(3+1), COL(2), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_3,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//}  else
//#endif

//#if _DUTCH_SUPPORT

// if((GET_OSD_LANGUAGE()==_DUTCH))

//{
//	RTDOsdTableFuncPutStringProp(ROW(2+1), COL(2), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_2,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//	RTDOsdTableFuncPutStringProp(ROW(3+1), COL(2), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_3,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//}	else 
//#endif
//#if _MAGYAR_SUPPORT

//if((GET_OSD_LANGUAGE()==_MAGYAR))
//{
//	RTDOsdTableFuncPutStringProp(ROW(2+1), COL(6), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_2,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//	RTDOsdTableFuncPutStringProp(ROW(3+1), COL(6), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_3,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//}  else
//#endif

//#if _POLSKI_SUPPORT

// if((GET_OSD_LANGUAGE()==_POLSKI))
//{
//	RTDOsdTableFuncPutStringProp(ROW(2+1), COL(4), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_2,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//	RTDOsdTableFuncPutStringProp(ROW(3+1), COL(4), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_3,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
//}
//else
//#endif

{
	RTDOsdTableFuncPutStringProp(ROW(5+2), COL(6), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_2,1, COLOR(_COLOR_BG_2,_CP_BG),0);
//	RTDOsdTableFuncPutStringProp(ROW(3+1), COL(3), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_3,1, COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());
}	

//	RTDOsdTableFuncPutStringProp(ROW(5), COL(10), _PFONT_PAGE_1, _OSD_STRING_ARROW,0, COLOR(_COLOR_MENU_FONT_SELECT,_CP_BG),0);
//	RTDOsdTableFuncPutStringCenter(ROW(5),COL(0),COL(32), _PFONT_PAGE_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_4, GET_OSD_ENGER(),COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET,GET_OSD_LANGUAGE());		
//	RTDOsdTableFuncPutStringProp(ROW(5), COL(22), _PFONT_PAGE_1, _OSD_STRING_ARROW,1, COLOR(_COLOR_MENU_FONT_SELECT,_CP_BG), 0);
		RTDOsdTableFuncPutStringCenter(ROW(9),COL(10),COL(14), _PFONT_PAGE_ITEM_1, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_4, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET,0);		
        RTDOsdTableFuncPutStringCenter(ROW(9),COL(24),COL(28), _PFONT_PAGE_ITEM_2, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_4, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET,0);      

        OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,XSTART(24*12-GET_OSD_ENGER()*15*12), YSTART(9*18), XEND(29*12-GET_OSD_ENGER()*15*12), YEND(10*18), _COLOR_WINDOW_BG, _CP_RED, _CP_BG, _ENABLE); 

        //==== Show page item =======

    OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}

#endif




void OsdDispOsdMessagePoweroff(void)
{
    OsdDispDisableOsd();
	SET_OSD_STATE(_MENU_MESSAGE);
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;

    
    	OsdFuncApplyMap(WIDTH(33), HEIGHT(9), COLOR(_COLOR_BG_0, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)  
    	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(9), _DISABLE, 0, _ENABLE);
#endif

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
	//OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(312+84), YEND(98), _CP_LIGHTGRAY);				 

	OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(312+84), YEND(9*18), _COLOR_WINDOW_BG);
	OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(0), XEND(312+84), YEND(36), _COLOR_MENU_FONT_SELECT);	
	OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_POWEROFF_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
	OsdFontPut1BitTable( ROW(8), COL(0), tOSD_BOARD_DOWN_LEFT_POWEROFF_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);



	switch(GET_OSD_LANGUAGE())
	{
		case _ENGLISH:
#if _ITALIAN_SUPPORT
                case _ITALIAN:
#endif

		#if (_DUTCH_SUPPORT)
		case _DUTCH:
		#endif
		#if (_PORTUGUESE_SUPPORT)
		case _PORTUGUESE:
		#endif

		#if (_SVENSKA_SUPPORT)
	       case _SVENSKA:
		#endif


		#if(_RUSSIAN_SUPPORT)
		case _RUSSIAN:
		#endif
		//case _ENGLISH:
			
			
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringCenter(5, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
			
			break;
#if _GERMAN_SUPPORT
        case _GERMAN:           
        RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());      
        RTDOsdTableFuncPutStringProp(5, COL(5), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());     
            break;
#endif
			
		case _FRENCH:
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(1), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;



#if _TURKISH_SUPPORT
		case _TURKISH:	
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(3), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
		break;
#endif

		#if(_CZECH_SUPPORT)
		case _CZECH:	
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(3), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;
		#endif



#if _MAGYAR_SUPPORT
	   case _MAGYAR:
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(2), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;
#endif



#if _SPANISH_SUPPORT
	case _SPANISH:
#endif
#if _POLSKI_SUPPORT
	case _POLSKI:
#endif
#if _XILAYU_SUPPORT
case _XILAYU:
#endif
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(6), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;
		default:
				
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringCenter(5, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
			break;
	}

        //==== Show page item =======

    OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}



void UpdateOsdDispOsdMessagePoweroff(void)
{

	
	//OsdFuncClearOsd(ROW(3), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END), HEIGHT(1));
	switch(GET_OSD_LANGUAGE())
	{
		case _ENGLISH:
#if _ITALIAN_SUPPORT
        case _ITALIAN:
#endif
		#if (_DUTCH_SUPPORT)
		case _DUTCH:
		#endif

		#if (_PORTUGUESE_SUPPORT)
		case _PORTUGUESE:
		#endif

		#if (_SVENSKA_SUPPORT)
	       case _SVENSKA:
		#endif
             #if (_RUSSIAN_SUPPORT)
		case _RUSSIAN:
		#endif
		//case _ENGLISH:
			
			
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringCenter(5, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
			
			break;
#if _GERMAN_SUPPORT
                    case _GERMAN:           
                    RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());      
                    RTDOsdTableFuncPutStringProp(5, COL(5), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE());     
                        break;
#endif
		case _FRENCH:
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(1), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;

#if _TURKISH_SUPPORT
		case _TURKISH:		
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(3), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;
#endif


			

#if _MAGYAR_SUPPORT
	   case _MAGYAR:
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(2), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;
#endif


#if _SPANISH_SUPPORT
	case _SPANISH:
#endif
#if _POLSKI_SUPPORT
	case _POLSKI:
#endif
#if _XILAYU_SUPPORT
case _XILAYU:
#endif
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(6), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;

		#if(_CZECH_SUPPORT)
		case _CZECH:	
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringProp(5, COL(3), _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			break;
		#endif

			
		default:
		RTDOsdTableFuncPutStringCenter(3, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		
		RTDOsdTableFuncPutStringCenter(5, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END+7, _PFONT_PAGE_1, _OSD_STRING_POWEROFF_SHOW, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());		

				
			break;
	}

}


//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------

void OsdDispOsdMessage(EnumOSDDispMsg ucMessage)
{
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
    OsdDispDisableOsd();
		
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;
#if(_DEF_REAL_TIME_HZ)
	if(GET_OSD_FV_INFORMATION())
		SET_OSD_HZ_DISPLAYSTATUS(2);
#endif	

	if(ucMessage == _OSD_DISP_INPUT_SIGNAL_MSG)
    	OsdFuncApplyMap(WIDTH(13), HEIGHT(5), COLOR(_COLOR_BG_0, _CP_BG));
	else if(ucMessage == _OSD_DISP_BACKLIGHT_MODE_MSG)
		OsdFuncApplyMap(WIDTH(13), HEIGHT(6), COLOR(_COLOR_BG_0, _CP_BG));
	else if(ucMessage == _OSD_DISP_BACKLIGHT_MODE_MSG)
		OsdFuncApplyMap(WIDTH(30), HEIGHT(9), COLOR(_COLOR_BG_0, _CP_BG));
	else			
    	OsdFuncApplyMap(WIDTH(26), HEIGHT(9), COLOR(_COLOR_BG_0, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	if(ucMessage == _OSD_DISP_INPUT_SIGNAL_MSG)
    	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(5), _DISABLE, 0, _ENABLE);
	else if(ucMessage == _OSD_DISP_BACKLIGHT_MODE_MSG)
    	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(6), _DISABLE, 0, _ENABLE);
	else if(ucMessage == _OSD_DISP_BACKLIGHT_MODE_MSG)
    	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(9), _DISABLE, 0, _ENABLE);
	else			
    	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(9), _DISABLE, 0, _ENABLE);

#endif

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    if(ucMessage == _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG)
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), g_ucOsdHeight, _CP_LIGHTBLUE);
    }
    else
    {
	    if(ucMessage == _OSD_DISP_INPUT_SIGNAL_MSG)
		{
        #if(_OSD_BLACK_WHITE_TYPE == _ON)    
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(156), YEND(80), _COLOR_BG_0);                
            OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(14), XEND(156), YEND(72), _CP_WHITE);    
            OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(18), XEND(156), YEND(68), _COLOR_BG_3);  
        #else
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(156), YEND(5*18), _COLOR_WINDOW_BG);
            OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(0), XEND(156), YEND(18), _OSD_BLACK_TYPE);    
        #endif
    		OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_INPUT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
    		OsdFontPut1BitTable( ROW(4), COL(0), tOSD_BOARD_DOWN_LEFT_INPUT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
		}
		else if(ucMessage == _OSD_DISP_BACKLIGHT_MODE_MSG)
		{
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(g_ucOsdWidth*12), YEND(6*18), _COLOR_WINDOW_BG);
            OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(0), XEND(g_ucOsdWidth*12), YEND(18), _OSD_BLACK_TYPE);    
    		OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_INPUT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
    		OsdFontPut1BitTable( ROW(5), COL(0), tOSD_BOARD_DOWN_LEFT_INPUT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

		}
	    else
		{
        #if(_OSD_BLACK_WHITE_TYPE == _ON)     
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(312), YEND(152), _COLOR_BG_0);                
            OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(19), XEND(312), YEND(138), _CP_WHITE);   
            OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(23), XEND(312), YEND(134), _COLOR_BG_3);    
        #else
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(g_ucOsdWidth*12), YEND(9*18), _CP_DARKBLUE_1);
            OsdWindowDrawing(_OSD_WINDOW_2, XSTART(0), YSTART(0), XEND(g_ucOsdWidth*12), YEND(36), _OSD_BLACK_TYPE);    
        #endif
    		OsdFontPut1BitTable( ROW(0), COL(0), tOSD_BOARD_UP_LEFT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
    		OsdFontPut1BitTable( ROW(8), COL(0), tOSD_BOARD_DOWN_LEFT_MSG, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
		}
	//four corner
    }	

        //==== Show page item =======
    switch(ucMessage)
    {
        case _OSD_DISP_NOSIGNAL_MSG:
            
			//RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		
			
			//RTDOsdTableFuncPutStringProp(0, 8, _PFONT_PAGE_0, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_1, 0,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
//			RTDOsdTableFuncPutStringCenter(2, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_1, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		
#if _JAPANESE_SUPPORT
        if(GET_OSD_LANGUAGE()==_JAPANESE)
            RTDOsdTableFuncPutStringProp(_OSD_MESSAGE_ROW_START, 11,  _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 0,COLOR(_COLOR_BG_2,_CP_BG),GET_OSD_LANGUAGE());       
        else
#endif
        RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		

//			RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START+2, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 1,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		


			//RTDOsdTableFuncPutStringProp(_OSD_MESSAGE_ROW_START, 8, _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 0,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
			//RTDOsdTableFuncPutStringProp(_OSD_MESSAGE_ROW_START+2, 8, _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 1,COLOR(_COLOR_BG_2,_CP_BG), GET_OSD_LANGUAGE()); 	
            break;

        case _OSD_DISP_NOCABLE_MSG:
#if _JAPANESE_SUPPORT
            if(GET_OSD_LANGUAGE()==_JAPANESE)
                RTDOsdTableFuncPutStringProp(_OSD_MESSAGE_ROW_START, 11,  _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 0,COLOR(_COLOR_BG_2,_CP_BG),GET_OSD_LANGUAGE());       
            else
#endif
            RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_NO_SIGNAL, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());       
        
            break;

        case _OSD_DISP_NOSUPPORT_MSG:
			
			RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_NO_SUPPORT, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		
            break;

        case _OSD_DISP_FAIL_SAFE_MODE_MSG:
            break;
			
		case _OSD_DISP_BACKLIGHT_MODE_MSG:
            RTDOsdTableFuncPutStringCenter(ROW(2), COL(0), COL(12), _PFONT_PAGE_0, _OSD_STRING_ITEM,0, COLOR((OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT)? _COLOR_MENU_FONT_MASK: _COLOR_BG_2),_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());                    
			
			OsdDispSliderAndNumber(0xff,_MENU_FUN_BACKLIGHT,GetOsdValue(_MENU_FUN_BACKLIGHT));
			break;

        case _OSD_DISP_AUTO_CONFIG_MSG:

    		RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_ITEM, _MENU_FUN_AUTO_ADJUST - _MENU_FUN_BACKLIGHT,COLOR(_COLOR_BG_2,_CP_BG) ,_OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());                    

            break;

        case _OSD_DISP_INPUT_SIGNAL_MSG:   
            RTDOsdTableFuncPutStringCenter(ROW(2), COL(0), COL(12), _PFONT_PAGE_0, _MENU_FUN_SIGNAL, (OsdDisplayGetSourcePortString()),COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());                    
            break;

        case _OSD_DISP_AUTO_COLOR_MSG:
    		RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_ITEM, _MENU_FUN_AUTO_COLOR - _MENU_FUN_BACKLIGHT,COLOR(_COLOR_BG_2,_CP_BG) ,_OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE());                    

            break;

        case _OSD_DISP_POWER_SAVING_MSG:
#if _RUSSIAN_SUPPORT
                if(GET_OSD_LANGUAGE()==_RUSSIAN)
                    RTDOsdTableFuncPutStringProp(_OSD_MESSAGE_ROW_START, 3 ,_PFONT_PAGE_0, _OSD_STRING_POWER_SAVING, 0,COLOR(_COLOR_BG_2,_CP_BG),  GET_OSD_LANGUAGE());
                else
#endif
#if _JAPANESE_SUPPORT
                if(GET_OSD_LANGUAGE()==_JAPANESE)
                    RTDOsdTableFuncPutStringProp(_OSD_MESSAGE_ROW_START, 9,_PFONT_PAGE_0, _OSD_STRING_POWER_SAVING, 0,COLOR(_COLOR_BG_2,_CP_BG),  GET_OSD_LANGUAGE());
                else
#endif
			RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_POWER_SAVING, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		
			//RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_ENERGY_CONSUMPTION_SHOW_SHOW_1, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		
			//RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START+2, _OSD_MESSAGE_CENTER_COL_START, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_POWER_SAVING, 0,COLOR(_COLOR_BG_2,_CP_BG), _OSD_MESSAGE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 		
			break;
        case _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG:

            break;
    }


#if(_WCH_MESSAGE_ADDR)
	if(ucMessage==_OSD_DISP_BACKLIGHT_MODE_MSG)
#else
	if((ucMessage==_OSD_DISP_INPUT_SIGNAL_MSG)||(ucMessage==_OSD_DISP_BACKLIGHT_MODE_MSG))
#endif
		if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_180)
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 2, 98);
		else if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_90)
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 98);
		else if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270)
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 2, 2);
		else
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 2);
	else
    	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
void HotKeySpacilProc(BYTE ucHotkeyType)
{
	OsdDispDisableOsd();		

	switch(ucHotkeyType)
	{
	
		case _MENU_FUN_SOURCE_HOTKEY:
			OsdInputSourceHotkey();

		break;
			
		case _HOT_KEY_LOS_TYPE1:
			
			Cross_flag = 1;
			OsdFuncApplyMap(WIDTH(4), HEIGHT(2), COLOR(_CP_BG, _CP_BG));   

		#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(2), _DISABLE, 0, _ENABLE);  
		#endif
			OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
			OsdFuncTransparency(_OSD_TRANSPARENCY_ALL); 

			// Adjust Color Palette
			OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);


			OsdFontVLCLoadFont(_HOTKEY_1BIT_ICON);
			
#if(_OSD_CROSS_SMALL)
			
			if(0 == GET_OSD_CROSS_HAIR_TYPE1())
			OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON_SMALL0, COLOR(_CP_RED, _CP_BG),0);
			else if(1 == GET_OSD_CROSS_HAIR_TYPE1())
			OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON_SMALL0, COLOR(_CP_GREEN, _CP_BG),0);
			else if(2 == GET_OSD_CROSS_HAIR_TYPE1())
			OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1_SMALL1, COLOR(_CP_GREEN, _CP_BG),0);
			else
			OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1_SMALL2, COLOR(_CP_GREEN, _CP_BG),0);
			
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
				 OsdFuncEnableOsd();
			
			
			
#else
							if(0 == GET_OSD_CROSS_HAIR_TYPE1())
							OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON, COLOR(_CP_RED, _CP_BG),0);
							else if(1 == GET_OSD_CROSS_HAIR_TYPE1())
							OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1, COLOR(_CP_RED, _CP_BG),0);
							else if(2 == GET_OSD_CROSS_HAIR_TYPE1())
							OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON, COLOR(_CP_GREEN, _CP_BG),0);
							else
							OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE1_ICON1, COLOR(_CP_GREEN, _CP_BG),0);
			
							OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
								 OsdFuncEnableOsd();
			
#endif

	
			break;

		case _HOT_KEY_LOS_TYPE2:
			
			OsdFuncApplyMap(WIDTH(8), HEIGHT(6), COLOR(_CP_BG, _CP_BG));   

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(6), _DISABLE, 0, _ENABLE);  
#endif
			OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
			OsdFuncTransparency(_OSD_TRANSPARENCY_ALL); 

			// Adjust Color Palette
			OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
			OsdFontVLCLoadFont(_HOTKEY_1BIT_ICON);
			
			if(0 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON1, COLOR(_CP_YELLOW, _CP_BG),0);
			else if(1 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON2, COLOR(_CP_RED, _CP_BG),0);
			else if(2 == GET_OSD_CROSS_HAIR_TYPE2())
				OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON3, COLOR(_CP_YELLOW, _CP_BG),0);
			else if(3 == GET_OSD_CROSS_HAIR_TYPE2())
			    OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON4, COLOR(_CP_RED, _CP_BG),0);
			else if(4 == GET_OSD_CROSS_HAIR_TYPE2())
			    OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON5, COLOR(_CP_YELLOW, _CP_BG),0);
			else if(5 == GET_OSD_CROSS_HAIR_TYPE2())
			    OsdFontPut1BitTable(ROW(0), COL(0), tOSD_TYPE2_ICON6, COLOR(_CP_RED, _CP_BG),0);

	
			break;

#if _ENABLE_ENERGE_NOTICE_MENU			
		case _MENU_FUN_SHOW_ENERGE_MENU:
			g_usAdjustValue = GET_OSD_ENERGE_NOTICE_FLAG();
			RTDOsdDisplayDrawMessageWindow(0);
//			if(GET_OSD_LANGUAGE() == _ENGLISH)
//			{
//				RTDOsdTableFuncPutStringProp(3,2,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,12,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else if(GET_OSD_LANGUAGE() == _GERMAN)
//			{
//				RTDOsdTableFuncPutStringProp(3,5,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,8,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else if(GET_OSD_LANGUAGE() == _SPANISH)
//			{
//				RTDOsdTableFuncPutStringProp(3,1,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,12,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else if(GET_OSD_LANGUAGE() == _FRENCH)
//			{
//				RTDOsdTableFuncPutStringProp(3,5,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,9,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else if(GET_OSD_LANGUAGE() == _ITALIAN)
//			{
//				RTDOsdTableFuncPutStringProp(3,1,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,9,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else if(GET_OSD_LANGUAGE() == _DUTCH)
//			{
//				RTDOsdTableFuncPutStringProp(3,5,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,7,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else if(GET_OSD_LANGUAGE() == _PORTUGUESE)
//			{
//				RTDOsdTableFuncPutStringProp(3,1,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//				RTDOsdTableFuncPutStringProp(4,12,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//			}
//			else
			{
				RTDOsdTableFuncPutStringProp(3,2,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_1,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(_COLOR_MENU_FONT, _CP_BG),_ENGLISH);
				RTDOsdTableFuncPutStringProp(4,10,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_2,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),_ENGLISH);
			}
			
			RTDOsdTableFuncPutStringCenter(5,0,30,_PFONT_PAGE_1,_OSD_STRING_ENERGY_NOTICE_3,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR( _COLOR_MENU_FONT, _CP_BG),0,GET_OSD_LANGUAGE());


			RTDOsdTableFuncPutStringCenter(6,0,16,_PFONT_PAGE_1,_OSD_YES_NO,1,COLOR(_COLOR_MENU_FONT, _CP_BG),0,GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringCenter(6,16,29,_PFONT_PAGE_1,_OSD_YES_NO,0,COLOR(_COLOR_MENU_FONT, _CP_BG),0,GET_OSD_LANGUAGE()); 		
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, 80, 108, 150, 126, _CP_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ON);
			break;
#endif
			
#if _LONG_PRESS_MENU_LOCK_OSD_ENABLE
		case _MENU_FUN_LOCK_MENU:
			RTDOsdDisplayDrawMessageWindow(0);
			RTDOsdTableFuncPutStringCenter(4, 5, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_FUN_LOCK_MENU,GET_OSD_LOCK() ,COLOR(_COLOR_BG_2,_CP_BG) ,_OSD_MESSAGE_PIXEL_OFFSET, _ENGLISH); 				   
		break;
#endif	

#if _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
		case _MENU_FUN_POWERKEY_LOCK_MENU:
			RTDOsdDisplayDrawMessageWindow(0);
			RTDOsdTableFuncPutStringCenter(_OSD_MESSAGE_ROW_START, 5, _OSD_MESSAGE_CENTER_COL_END, _PFONT_PAGE_0, _OSD_STRING_FUN_LOCK_POWER_KEY,GET_POWER_KEY_LOCK() ,COLOR(_COLOR_BG_2,_CP_BG) ,_OSD_MESSAGE_PIXEL_OFFSET, _ENGLISH); 				   
			break;
#endif

		default:

			break;
	}

}

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
void RTDOsdDispHotkeyFuncAdjust(BYTE ucHotkeyType)
{
	BYTE Osd_fun_num = 0;
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
	ucHotkeyType += _MENU_FUN_BACKLIGHT;
	
	if(ucHotkeyType > _MENU_NULL)
	{
		HotKeySpacilProc(ucHotkeyType);
		SET_OSD_STATE(ucHotkeyType);
		
	}
	else
	{
	    #if(_CUSTOM_TYPE == _FKX_CUSTOMER)
       		if(GetOsdShowType(ucHotkeyType) == _TYPE_SLIDER)
        		RTDOsdDisplayDrawMessageWindowSmall();
        	else
	    #endif
				RTDOsdDisplayDrawMessageWindow(ucHotkeyType);
	
		UpdateMaskItem();
		UpdateItemMaskValue();
		if(GetOsdShowType(ucHotkeyType) == _TYPE_NONE)
		{
			RTDOsdTableFuncPutStringCenter(_HOTKEY_ROW_START,0,29,_PFONT_PAGE_1,_OSD_STRING_ITEM,ucHotkeyType -_MENU_FUN_BACKLIGHT,COLOR(OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT, _CP_BG),0,GET_OSD_LANGUAGE());
		}
		else if(GetOsdShowType(ucHotkeyType) == _TYPE_SLIDER)
		{
		#if(_CUSTOM_TYPE == _FKX_CUSTOMER)
		    OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,(_HOTKEY_SLIDER_COL+4)*12,1*18,30*12,1*18+18,  _COLOR_WINDOW_BG, OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			SG_PutStringProp(1, 1, _PFONT_PAGE_1, _MENU_FUN_HOTLEFT, ucHotkeyType, COLOR(OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
			OsdFontPut1BitTable(ROW(1), COL(_HOTKEY_SILDER_START), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_HOTKEY_SILDER_START*12,1*18,(_HOTKEY_SILDER_START+(GET_SILDER_PERCENT(ucHotkeyType)))*12+1,1*18+18,  _COLOR_WINDOW_BG, OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
			
		#else
//			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,(_HOTKEY_SILDER_START)*12,_HOTKEY_ROW_START*18,22*12,_HOTKEY_ROW_START*18+18,  _COLOR_WINDOW_BG, OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
//			SG_PutStringProp(_HOTKEY_ROW_START, 1, _PFONT_PAGE_1, _MENU_FUN_HOTLEFT, ucHotkeyType, COLOR(OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
//            OsdFuncClearOsd(_HOTKEY_ROW_START, 0, WIDTH(8), HEIGHT(1));
            RTDOsdTableFuncPutStringCenter(1, 0,7, _PFONT_PAGE_1, _MENU_FUN_HOTLEFT, ucHotkeyType-_MENU_FUN_BACKLIGHT, COLOR(OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT, _CP_BG),0,GET_OSD_LANGUAGE());
            OsdDispSliderAndNumber(1,ucHotkeyType,(BYTE)GetOsdValue(ucHotkeyType));
            OsdFontPut1BitTable(ROW(1), COL(_HOTKEY_SILDER_START), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_HOTKEY_SILDER_START*12,1*18,(_HOTKEY_SILDER_START+(GET_SILDER_PERCENT(ucHotkeyType)))*12+1,1*18+18,  _COLOR_WINDOW_BG, OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
        #endif
		}	
		else
		{
			#if(_RUSSIAN_SUPPORT)
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,15*12,_HOTKEY_ROW_START*18,30*12,_HOTKEY_ROW_START*18+18,  _COLOR_WINDOW_BG, OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			#else
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,15*12,_HOTKEY_ROW_START*18,30*12,_HOTKEY_ROW_START*18+18,  _COLOR_WINDOW_BG, OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			#endif
			SG_PutStringProp(_HOTKEY_ROW_START, 1, _PFONT_PAGE_1, _MENU_FUN_HOTLEFT, ucHotkeyType, COLOR(OSD_ITEM_MASK_GET(ucHotkeyType)?_COLOR_MENU_FONT_MASK: _COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
		}
		g_usBackupValue = GetOsdValue(ucHotkeyType);

		OSD_SubMenuCur = ucHotkeyType;
		Osd_fun_num = 0;
#if(_DEF_OPPOSITE_DCR)

		if(OSD_SubMenuCur == _MENU_FUN_DCR_OPPOSITE)
		{
			if(0)//if(((GET_OSD_HDR_MODE() == _HDR10_MODE_AUTO)&&(GET_HDR10_EOTF_SETTING() == _HDR_TARGET_STATUS_SMPTE_ST_2084))||(GET_OSD_HDR_MODE() == _HDR10_MODE_FORCE_2084))
			{
				Osd_fun_num = 0;
			}
			else
			{
				if(GET_OSD_DCR_STATUS() == _OFF)
				{
					Osd_fun_num = OSD_SubMenuCur;
				}
			}
		}

#endif

		if(OSD_ITEM_MASK_GET(ucHotkeyType))
		{
			OSD_SubMenuCur = 0xff;
		}

		if(Osd_fun_num != 0)
		{
			OSD_SubMenuCur = Osd_fun_num;
		}
		SET_OSD_STATE(_MENU_HOT_KEY_FUNC);
	}
	
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
		OsdFuncEnableOsd();
}

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
BYTE OsdDisplayGetSourcePortString(void)
{
    switch(SysSourceGetInputPort())
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
            return _STRING_A0_PORT;
#endif
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
            return _STRING_D0_PORT;
#endif
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
            return _STRING_D1_PORT;
#endif
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
            return _STRING_D2_PORT;
#endif
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
            return _STRING_D3_PORT;
#endif
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
            return _STRING_D4_PORT;
#endif
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:
            return _STRING_D5_PORT;
#endif
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
        case _D6_INPUT_PORT:
            return _STRING_D6_PORT;
#endif
        default:
            return 0;
    }
}

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : Source Port Number
//--------------------------------------------------
BYTE OsdDispJudgeSourceType(void)
{
    BYTE ucOsdSourcePort = _VGA_A0;

    switch(SysSourceGetInputPort())
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
            ucOsdSourcePort = _VGA_A0;
            return ucOsdSourcePort;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            ucOsdSourcePort = _DVI_D0;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            ucOsdSourcePort = _HDMI_D0;
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ucOsdSourcePort = _DP_D0;
#endif
            return ucOsdSourcePort;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            ucOsdSourcePort = _DVI_D1;
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            ucOsdSourcePort = _HDMI_D1;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ucOsdSourcePort = _DP_D1;
#endif
            return ucOsdSourcePort;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
            if(_DVI_D2 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D2;
            }
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            if(_HDMI_D2 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D2;
            }
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if(_DP_D2 > 0x10)
            {
                ucOsdSourcePort = 0x0F;
            }
            else
            {
                ucOsdSourcePort = _DP_D2;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
            if(_DVI_D3 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D3;
            }
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            if(_HDMI_D3 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D3;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
            if(_DVI_D4 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D4;
            }
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
            if(_HDMI_D4 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D4;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
            if(_DVI_D5 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D5;
            }
#endif

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
            if(_HDMI_D5 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D5;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
        case _D6_INPUT_PORT:
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
            if(_DP_D6 > 0x10)
            {
                ucOsdSourcePort = 0x0F;
            }
            else
            {
                ucOsdSourcePort = _DP_D6;
            }
#endif
            return ucOsdSourcePort;
#endif

        default:
            return ucOsdSourcePort;
    }
}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispDisableOsd(void)
{
#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_DRR_VFREQ);
#endif

    SET_OSD_STATE(_MENU_NONE);
    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncDisableOsd();
    OsdFuncCloseWindow(_OSD_WINDOW_ALL);

#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))
     BackUpTempVFreq = 0;
#endif
	
    g_ucOsdWidth = 0;
    g_ucOsdHeight = 0;
    g_ucOsdWidthB = 0;
    g_ucOsdHeightB = 0;
   g_ucFactoryPage = 0;
#if(_DEF_REAL_TIME_HZ)
	if(GET_OSD_FV_INFORMATION() && GET_OSD_HZ_DISPLAYSTATUS() != 2)
		SET_OSD_HZ_DISPLAYSTATUS(1);
#endif

#if 0//(_KEY_IR_HUIXIONG_CROOSSOVER)
	SET_IR_OSD_PROGRESS_BAR_OR_OPTION(_OFF);
#endif
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispSetPosition(BYTE ucType, EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos)
{
    WORD usX  = 0;
    WORD usY = 0;
    BYTE ucFonWidth = 12;
    BYTE ucFonHeight = 18;
    BYTE ucHorizontalDelayStep = 4;
    BYTE ucTempWidth = g_ucOsdWidth;
    BYTE ucTempHeight = g_ucOsdHeight;

    if((enumOsdPositionType == _OSD_POSITION_GLOBAL_B) ||
       (enumOsdPositionType == _OSD_POSITION_FONT_B))
    {
        ucTempWidth = g_ucOsdWidthB;
        ucTempHeight = g_ucOsdHeightB;
    }

    if(ScalerOsdGetHorizontalDelayStep() == _OSD_HORIZONTAL_DELAY_STEP_1_PIXEL)
    {
        ucHorizontalDelayStep = 1;
    }

    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        ucFonWidth *= 2;
        ucFonHeight *= 2;
    }

    if(ucType == _POS_PERCENT)
    {
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonHeight) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonWidth) * usVPos) / _OSD_V_POS_MAX;
        }
        else
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
        }
#elif(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempHeight * ucFonHeight) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempWidth * ucFonWidth) * usVPos) / _OSD_V_POS_MAX;
        }
        else
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
        }
#else
        usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
        usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
#endif
    }
    else
    {
        // Notice!!! if osd set double size need to chek real position
        usX = usHPos;
        usY = usVPos;
    }
    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        usX = usX / 2;
        usY = usY / 2;
    }
	if(2048 <= usY)
	{
		usY = 2047; //usY�ļĴ���ֻ��11λ  luo
	}
    OsdFuncSetPosition(enumOsdPositionType, usX, usY);
}



//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
#if(_DEF_PROGRESS_BAR_NEW)
BYTE OsdDispProgressBarNew(BYTE Osd_date,BYTE value)
{
	if(Osd_date == _MENU_FUN_BACKLIGHT)
	{
		if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_MOVIE)
			value = _ECO_MOVIE_BACKLIGHT;
		else if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_GAME)	
			value = _ECO_GAME_BACKLIGHT;
		else if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_PHOTO)	
			value = _ECO_TEXT_BACKLIGHT;
	}
	else if(Osd_date == _MENU_FUN_CONTRAST)
	{
		if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_MOVIE)
			value = _ECO_MOVIE_CONTRAST;
		else if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_GAME)	
			value = _ECO_GAME_CONTRAST;
	}

	return value;
}
#endif


void OsdDispSliderAndNumber(BYTE ucItemRow,BYTE ucOsdState, WORD usValue)
{
	BYTE ucColor = 0;
	BYTE ucShowMax = 100;
	BYTE ucShowMin = 0;    
	BYTE ucPagePositionSelect = 19+ LENGTH(18);
	BYTE ucPFnotPageItem = _PFONT_PAGE_ITEM_1 + ((ucItemRow -_ITEM_1_ROW)/2);
	
	ucColor = ((_COLOR_MENU_FONT<<4)|_CP_BG);
	
	if((GET_OSD_STATE() == _MENU_HOT_KEY_FUNC)||
#if(_NAVIGAT_MENU_SURPPORT)
	(GET_OSD_STATE() == _MENU_NAVIGAT_NONE))
#else
	(GET_OSD_STATE() == _MENU_NONE))
#endif
	{
		ucPagePositionSelect = _HOTKEY_SLIDER_COL-3;
	}
    if(OSD_ITEM_MASK_GET(ucOsdState))
    ucColor = ((_CP_GRAY<<4)|_CP_BG);

 	if(0xff == ucItemRow)
	{
		ucItemRow = 4;
		ucPagePositionSelect = 5;
		ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
	}

	g_usAdjustValue = usValue;

#if(_DEF_STA_SIX_COLOR)
	if((_MENU_FUN_BACKLIGHT<=GET_OSD_STATE() && GET_OSD_STATE()< _MENU_END)&& (GET_OSD_STATE() != _MENU_FUN_COLORTEMP)&&(GET_OSD_STATE()!=_MENU_FUN_HUE_STATE)&&(GET_OSD_STATE()!=_MENU_FUN_SAT_STATE))
#else
	if((_MENU_FUN_BACKLIGHT<=GET_OSD_STATE() && GET_OSD_STATE()< _MENU_END)&& (GET_OSD_STATE() != _MENU_FUN_COLORTEMP))
#endif
	{
	

			switch(ucOsdState)
			{
				case _MENU_FUN_BACKLIGHT:	
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_BACKLIGHT(g_usAdjustValue);
					UserAdjustBacklight(GET_OSD_BACKLIGHT());
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;
					
				case _MENU_FUN_CONTRAST:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_CONTRAST(g_usAdjustValue);	
					UserAdjustContrast(GET_OSD_CONTRAST());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
					break;

				case _MENU_FUN_BRIGHTNESS:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(0)//(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    {
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    }
					SET_OSD_BRIGHTNESS(g_usAdjustValue);
					UserAdjustBrightness(GET_OSD_BRIGHTNESS());	
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
					break;


#if(_DCC_PROGRESS_BAR)
				case _MENU_FUN_DCC:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue,20,0,_OFF);
		  
					SET_OSD_DCC(g_usAdjustValue);
					UserAdjustDCC(GET_OSD_DCC());
					
					if(GET_OSD_DCC())
						ScalerColorDCCEnable(1);
					else
						ScalerColorDCCEnable(0);
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
					ucShowMax = 20;
					break;						
#endif

				case _MENU_FUN_SHARPNESS:	
#if(_DEF_SHARPNESS_ONE)
					ucShowMax = 100;
					ucShowMin = 0;	  
#else
					ucShowMax = 4;
				    ucShowMin = 0;    
#endif
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 4, 0, _OFF);
					SET_OSD_SHARPNESS(g_usAdjustValue);
					#if(_CUSTOM_TYPE == _FKX_CUSTOMER)
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue,4,0,2);
					#endif					
					g_usAdjustValue *= 25;
#if(_SHARPNESS_SUPPORT == _ON)
					UserCommonAdjustSharpness(SysSourceGetInputPort());
#endif
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

					break;
#if(_VGA_SUPPORT == _ON)
					
				case _MENU_FUN_VGA_HPOSITON:	
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_VGA_MODE_ADJUST_H_POSITION(g_usAdjustValue);
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			        UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());        
				
					break;
					
				case _MENU_FUN_VGA_VPOSITON:	
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_VGA_MODE_ADJUST_V_POSITION(g_usAdjustValue);
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			        UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());        			
					break;

				case _MENU_FUN_VGA_CLK:	
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_VGA_MODE_ADJUST_CLOCK(g_usAdjustValue);
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
					UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());			
					break;
				case _MENU_FUN_VGA_PHASE:	
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_VGA_MODE_ADJUST_PHASE(g_usAdjustValue);
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
					UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());			
					break;
#endif
				case _MENU_FUN_R:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					if(GET_OSD_STATE() == _MENU_FUN_R || GET_OSD_STATE() == _MENU_HOT_KEY_FUNC)
					{
						g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
						SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 255, 0, _DEF_CT_USER_OSD_R));
					}
#if(_DEF_COLORFUL)
					UserAdjustContrast(GetOsdValue(_MENU_FUN_CONTRAST));
#else	
					UserAdjustContrast(GET_OSD_CONTRAST());	
#endif

#if(_DEF_CT_JX)
					if(GET_OSD_GAMMA() != _GAMMA_OFF)
					{
						RTDNVRamSaveColorSetting(_CT_8000+GET_OSD_GAMMA());
					}
					else
					{
						RTDNVRamSaveColorSetting(_CT_USER);
					}

#else
					RTDNVRamSaveColorSetting(_CT_USER);
#endif
					break;

				case _MENU_FUN_G:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);			
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					if(GET_OSD_STATE() == _MENU_FUN_G || GET_OSD_STATE() == _MENU_HOT_KEY_FUNC)
					{
						g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
						SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 255, 0, _DEF_CT_USER_OSD_G));
					}
#if(_DEF_COLORFUL)
					UserAdjustContrast(GetOsdValue(_MENU_FUN_CONTRAST));
#else
					UserAdjustContrast(GET_OSD_CONTRAST());		
#endif

#if(_DEF_CT_JX)
					if(GET_OSD_GAMMA() != _GAMMA_OFF)
					{
						RTDNVRamSaveColorSetting(_CT_8000+GET_OSD_GAMMA());
					}
					else
					{
						RTDNVRamSaveColorSetting(_CT_USER);
					}

#else
					RTDNVRamSaveColorSetting(_CT_USER);
#endif
					break;
					
				case _MENU_FUN_B:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					if(GET_OSD_STATE() == _MENU_FUN_B || GET_OSD_STATE() == _MENU_HOT_KEY_FUNC)
					{
						g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
						SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 255, 0, _DEF_CT_USER_OSD_B));
					}

#if(_DEF_COLORFUL)
					UserAdjustContrast(GetOsdValue(_MENU_FUN_CONTRAST));
#else
					UserAdjustContrast(GET_OSD_CONTRAST());
#endif

#if(_DEF_CT_JX)
					if(GET_OSD_GAMMA() != _GAMMA_OFF)
					{
						RTDNVRamSaveColorSetting(_CT_8000+GET_OSD_GAMMA());
					}
					else
					{
						RTDNVRamSaveColorSetting(_CT_USER);
					}

#else
					RTDNVRamSaveColorSetting(_CT_USER);
#endif
					break;

					
				case _MENU_FUN_OSD_HPOSITON:	
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_HPOS(g_usAdjustValue);
					
					if(GET_OSD_STATE() != _MENU_HOT_KEY_FUNC)
					OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, GET_OSD_HPOS(), 100 - GET_OSD_VPOS());	
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;
				
				case _MENU_FUN_OSD_VPOSITON:	
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_VPOS(g_usAdjustValue);
					
					if(GET_OSD_STATE() != _MENU_HOT_KEY_FUNC)
					OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, GET_OSD_HPOS(), 100 - GET_OSD_VPOS());	
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;
					
				case _MENU_FUN_OSD_TIME:
				
					ucShowMax = 60;
					ucShowMin = 5;    
#if(_CUSTOMER_TYPE == _HUASHUOHUI_CUSTOMER)
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 60, 5, _OFF);
#else
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 60, 5, _OFF);
#endif
                    while(1)
                    {                       
                        if(g_usAdjustValue%5==0)
                            break;
                        if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
                            g_usAdjustValue++;
                        else if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
                            g_usAdjustValue--;

                    }

					SET_OSD_TIME_OUT(g_usAdjustValue);
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				
					break;
				case  _MENU_FUN_SAVING_MODE:
									
					ucShowMax = 180;
					ucShowMin = 60;	  
#if(_CUSTOMER_TYPE == _HUASHUOHUI_CUSTOMER)
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 60, 5, _OFF);
#else
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 180, 20, _OFF);
#endif
					while(1)
					{						
						if(g_usAdjustValue%20==0)
							break;
						if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
							g_usAdjustValue++;
						else if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
							g_usAdjustValue--;

					}

					SET_OSD_SAVING_MODE(g_usAdjustValue);
					
					DebugMessageSystem("GET_OSD_SAVING_MODE() -------", GET_OSD_SAVING_MODE());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				
					break;

				case _MENU_FUN_OSD_TRANS:	
				
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 160, 0, 80);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    while(1)
                    {                       
                        if(g_usAdjustValue%20==0)
                            break;
                        if(GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE)
                            g_usAdjustValue++;
                        else if(GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE)
                            g_usAdjustValue--;

                    }
					SET_OSD_TRANSPARENCY_STATUS(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 160, 0, 80));
					OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());		
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;


				case _MENU_FUN_AUDOIVOLUME:	
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_VOLUME(g_usAdjustValue);
					UserAdjustAudioVolume(GET_OSD_VOLUME());	//_DIGITAL_VOLUME_MAX
					SET_OSD_VOLUME_MUTE(_OFF);
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;	

				case _MENU_FUN_SATURATION:	
					
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_SATURATION(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
#if(_GLOBAL_HUE_SATURATION == _ON)
					UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
#endif
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;	

				case _MENU_FUN_HUE:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 230, 30, 130);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_HUE(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 230, 30, 130));
#if(_GLOBAL_HUE_SATURATION == _ON)
					UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
#endif
					
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					break;


#if(_DEF_STA_SIX_COLOR && _SIX_COLOR_SUPPORT)
				case _MENU_FUN_SAT_RED:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_SAT_R(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
					ScalerColorICMEnable(_FUNCTION_ON);				
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_R);
					ScalerColorSixColorAdjust(_SIXCOLOR_R, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					//SET_KEYREPEATENABLE();

					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;
	
				case _MENU_FUN_SAT_GREEN:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_SAT_G(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_G);				
					ScalerColorSixColorAdjust(_SIXCOLOR_G, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;

				case _MENU_FUN_SAT_BLUE:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_SAT_B(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_B);
					ScalerColorSixColorAdjust(_SIXCOLOR_B, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;
	
				case _MENU_FUN_SAT_CYAN:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_SAT_C(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_C);
					ScalerColorSixColorAdjust(_SIXCOLOR_C, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;

				case _MENU_FUN_SAT_MAGENTA:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_SAT_M(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_M);
					ScalerColorSixColorAdjust(_SIXCOLOR_M, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;

			
				case _MENU_FUN_SAT_YELLOW:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_SAT_Y(UserCommonAdjustPercentToRealValue(g_usAdjustValue, 200, 0, 100));
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_Y);
					ScalerColorSixColorAdjust(_SIXCOLOR_Y, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;




				case _MENU_FUN_HUE_RED:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_HUE_R(g_usAdjustValue);
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_R);
					ScalerColorSixColorAdjust(_SIXCOLOR_R, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;
	
				case _MENU_FUN_HUE_GREEN:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_HUE_G(g_usAdjustValue);
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_G);
					ScalerColorSixColorAdjust(_SIXCOLOR_G, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;

				case _MENU_FUN_HUE_BLUE:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_HUE_B(g_usAdjustValue);
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_B);
					ScalerColorSixColorAdjust(_SIXCOLOR_B, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;
	
				case _MENU_FUN_HUE_CYAN:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_HUE_C(g_usAdjustValue);
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_C);
					ScalerColorSixColorAdjust(_SIXCOLOR_C, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;

				case _MENU_FUN_HUE_MAGENTA:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_HUE_M(g_usAdjustValue);
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_M);
					ScalerColorSixColorAdjust(_SIXCOLOR_M, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;

			
				case _MENU_FUN_HUE_YELLOW:
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    if(GET_KEYREPEATSTART()) //�ӿ쳤���ٶ�
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_SIX_COLOR_HUE_Y(g_usAdjustValue);
					ScalerColorICMEnable(_FUNCTION_ON);
					OsdDisplaySixColorGetOneColor(_SIXCOLOR_Y);
					ScalerColorSixColorAdjust(_SIXCOLOR_Y, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG);
					break;
#endif
				
					
				default :

					break;
			}
	}
	else
	{
		switch(ucOsdState)
			{
				case _MENU_FUN_SHARPNESS:	
					#if(_CUSTOM_TYPE  == _FKX_CUSTOMER)
					
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue,4,0,2);
					#else
					ucShowMax = 4;
					ucShowMin = 0;	 
					#endif
					
#if(_DEF_SHARPNESS_ONE)
					ucShowMax = 100;
					ucShowMin = 0;	
					g_usAdjustValue *= 25;
#endif

					
					break;
#if(_DCC_PROGRESS_BAR)
				case _MENU_FUN_DCC:				
					ucShowMax = 20;
					ucShowMin = 0;	  
					break;
#endif
				case _MENU_FUN_R:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);
					break;

				case _MENU_FUN_G:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128); 		
					break;
					
				case _MENU_FUN_B:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);
					break;
					
				case _MENU_FUN_OSD_TIME:			
					ucShowMax = 60;
					ucShowMin = 5;	  				
					break;
				case  _MENU_FUN_SAVING_MODE:
					ucShowMax = 180;
					ucShowMin = 60;					
					break;

				case _MENU_FUN_OSD_TRANS:				
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 160, 0, 80);
					break;

					
				case _MENU_FUN_SATURATION:	
#if(_DEF_STA_SIX_COLOR)
				case _MENU_FUN_SAT_RED:
				case _MENU_FUN_SAT_GREEN:
				case _MENU_FUN_SAT_BLUE:
				case _MENU_FUN_SAT_CYAN:
				case _MENU_FUN_SAT_MAGENTA:
				case _MENU_FUN_SAT_YELLOW:
#endif
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
					break;

				case _MENU_FUN_HUE:	
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 230, 30, 130);
					break;
					
				default :

					break;
			}


	}
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_DEF_PROGRESS_BAR_NEW)
	OsdPropShowNumber(ucItemRow, COL(ucPagePositionSelect ), OsdDispProgressBarNew(ucOsdState,g_usAdjustValue), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), ucPFnotPageItem, ucColor);
#else
	OsdPropShowNumber(ucItemRow, COL(ucPagePositionSelect ), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), ucPFnotPageItem, ucColor);
#endif
}


BYTE GET_SILDER_PERCENT(BYTE ucOsdState)
{
	BYTE ucShowMax = 100;
	BYTE ucShowMin = 0;  
	BYTE Percent = 0;
	
	if(ucOsdState == 0)
		ucOsdState = OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur];

	g_usAdjustValue = GetOsdValue(ucOsdState);

		switch(ucOsdState)
		{
			case _MENU_FUN_SHARPNESS:				
				ucShowMax = 4;
				ucShowMin = 0;	  
				break;
				
			case _MENU_FUN_R:	
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);
				break;

			case _MENU_FUN_G:	
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128); 		
				break;
				
			case _MENU_FUN_B:	
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 255, 0, 128);
				break;
				
			case _MENU_FUN_OSD_TIME:			
				ucShowMax = 60;
				ucShowMin = 5;					
				break;
			case  _MENU_FUN_SAVING_MODE:
				ucShowMax = 180;
				ucShowMin = 60;					
				break;

			case _MENU_FUN_OSD_TRANS:				
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 160, 0, 80);
				break;

				
			case _MENU_FUN_SATURATION:
#if(_DEF_STA_SIX_COLOR)
			case _MENU_FUN_SAT_RED:
			case _MENU_FUN_SAT_GREEN:
			case _MENU_FUN_SAT_BLUE:
			case _MENU_FUN_SAT_CYAN:
			case _MENU_FUN_SAT_MAGENTA:
			case _MENU_FUN_SAT_YELLOW:
#endif
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 200, 0, 100);
				break;

			case _MENU_FUN_HUE:	
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 230, 30, 130);
				break;

			case _MENU_FUN_DCC:
				ucShowMax = 20;
				ucShowMin = 0;					
				break;
				
			default :

				break;
		}

	Percent = (DWORD)g_usAdjustValue*100/ucShowMax/10;
	
	return Percent;

}

//--------------------------------------------------
// Description  :����ͼ��
// Input Value  :
// Output Value :
//--------------------------------------------------

void UpdateOSDMainIcon(void)
{
	//OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_1_COL*12,(_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE))*18, (_ITEM_1_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
/*
if(GET_OSD_STATE() != _OSD_MAIN_SOURCE)
	OsdFuncChangeColor1Bit(_ITEM_1_ROW-2+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT, _CP_BG),0);
else
	OsdFuncChangeColor1Bit(_ITEM_1_ROW+(_OSD_MAIN_MENU_COUNT*2)+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT, _CP_BG),0);

	OsdFuncChangeColor1Bit(_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT_SELECT, _CP_BG),0);

if(GET_OSD_STATE() != _OSD_MAIN_OTHER)
	OsdFuncChangeColor1Bit(_ITEM_1_ROW+2+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT, _CP_BG),0);
else	
	OsdFuncChangeColor1Bit(_ITEM_1_ROW-_OSD_MAIN_MENU_COUNT*2+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT, _CP_BG),0);
*/
    OsdFuncChangeColor1Bit(_ITEM_1_ROW,_ITEM_1_COL,_ITEM_COL_LENGTH,2*(_OSD_MAIN_MENU_COUNT+2),COLOR(_COLOR_MENU_FONT, _CP_BG),0);
	OsdFuncChangeColor1Bit(_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT_SELECT, _CP_BG),0);
	OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_1_COL*12-10,((_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE)))*18-9, (_ITEM_1_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE))+1)*18+7, _COLOR_WINDOW_BG);	

}


//--------------------------------------------------
// Description  :����������
// Input Value  :
// Output Value :
//--------------------------------------------------

void UpdateOSDMainInterface(BYTE ucState)
{
	BYTE i = 0;
	
	SET_OSD_STATE(ucState);
	OSD_MAIN_MENU_ITEM = ucState - _OSD_MAIN_BRI_CON;

	for(i =0; i<_HENG_COUNT; i++)
		OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_2_COL), WIDTH(_OSD_MAIN_MENU_WIDTH*2/3), HEIGHT(1));
	
	UpdateOSDMainIcon();
    if(ucState == _OSD_MAIN_FACTORY)
    return;
	
	UpdateMaskValue();

	OSD_SubMenuCur = 0;

	if(_OSD_MAIN_SOURCE == ucState)
	{
		for(i =0; i<_OSD_INPUT_AMOUNT; i++)
		{
			RTDOsdTableFuncPutStringProp(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_2_COL+3), _PFONT_PAGE_1, _OSD_STRING_SIGNAL, i, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
		}
    	OsdFontPut1BitTable(ROW(_ITEM_1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2), COL(_ITEM_2_COL+1), tOSD_SOURCE_SELECT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
	}
	else
	{
#if(_DEF_PAGE8)
		for(i=0; i<7; i++)
#else
		for(i=0; i<6; i++)
#endif
		{
			if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_NULL)
			{
				OSD_MASKSET(OSD_MAIN_MENU_ITEM,i);	
				
			}
			else
			{
				SG_PutStringProp(_ITEM_1_ROW+i*2, _ITEM_2_COL, _PFONT_PAGE_1, _OSD_STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i], COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
			}
		}	

	}

}
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void SpecialFuncAdj(void)
{
	BYTE i = 0;
#if(_DEF_STA_SIX_COLOR)
	BYTE sat_color_num = 0;
#endif


	switch(GET_OSD_STATE_PREVIOUS())
	{
	
		case _MENU_FUN_LANGUAGE:			
			if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
				OsdDispMainMenu();
			}
			else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{			
				SET_OSD_LANGUAGE(g_usBackupValue);
				//SET_OSD_LANGUAGE(GetRealLanguage(g_usBackupValue));
			}
			break;	
			
		case _MENU_FUN_OSD_RORATE:	
			if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
			    SET_OSD_ROTATE_STATUS((g_usAdjustValue));
				OsdDispMainMenu();
			}
			else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{			
			    g_ucOsdRorateState = g_usBackupValue;
				SET_OSD_ROTATE_STATUS(g_usBackupValue);
			}
						
			RTDNVRamSaveOSDData();	//������ֵ
			break;

		#if _FREESYNC_SUPPORT
		case _MENU_FUN_FREESYNC:
			if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
				#if(_FAKE_FREE)
				PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);
				ScalerTimerDelayXms(1500);
				PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
				return;

				#endif
				#if(_FREESYNC_SUPPORT == _ON)
				UserCommonInterfaceFreeSyncSupportSwitch();
				#endif	
				
#if(_TEST_FOR_FREESYNC == _ON)
				if(g_usAdjustValue == _ON)
				{
#if(_OD_SUPPORT == _ON)
				SET_OSD_OD_STATUS(_FUNCTION_ON);
				ScalerODEnable(GET_OSD_OD_STATUS()?(_FUNCTION_ON):(_FUNCTION_OFF));
#endif
				}
#endif
			}
			else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{			
				SET_OSD_FREE_SYNC_STATUS(g_usBackupValue);
			}
			break;
		#endif

	     case _MENU_FUN_DP_VER:
			if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
                if((GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1) && (GET_OSD_DP_MST() == _MST_D0))
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_DP_HDR10_SUPPORT == _ON))
                // Disable HDR Function, if DP Version Switch to 1.1/1.2
                if((GET_OSD_DP_D0_VERSION() <= _DP_VER_1_DOT_2) && (GET_OSD_HDR_MODE() != _HDR10_MODE_OFF))
                {
                    SET_OSD_HDR_MODE(_HDR10_MODE_OFF);

                    // Switch DP D1 Port Edid
                    UserCommonInterfaceDPSwitchEdid(_D0_INPUT_PORT);
                }
#endif
#endif

                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

#if(_DP_SUPPORT == _ON)
                UserCommonInterfaceDpVersionSwitch(_D0_INPUT_PORT, UserInterfaceGetDPVersion(_D0_INPUT_PORT), UserInterfaceGetDpMSTCapablePort());

                if(SysSourceGetInputPort() == _D0_INPUT_PORT)
                {
                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                }
#endif
            }
			else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{			
				//OsdFuncClearOsd(_ITEM_1_ROW+OSD_SubMenuCur*3, _OSD_ITEM_COL_SLIDER+1, 12 , 1);					 
				//RTDOsdTableFuncPutStringCenter(_ITEM_1_ROW+OSD_SubMenuCur*3, _OSD_ITEM_COL_SLIDER+1, _OSD_ITEM_COL_SLIDER+12, _PFONT_PAGE_ITEM_1 + OSD_SubMenuCur, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  g_usBackupValue, COLOR(_COLOR_MENU_FONT, _CP_BG), 0, GET_OSD_LANGUAGE()); 
				SET_OSD_DP_D0_VERSION(g_usBackupValue);
			}
			break;
			
            #if(_CUSTOM_TYPE == _FKX_CUSTOMER)
				case _MENU_FUN_ECO:
					if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD))
					{
						SET_OSD_DCR_STATUS(_OFF);
					}	

					UserAdjustBacklight(GET_OSD_BACKLIGHT());
#if(_DEF_COLORFUL)
					UserAdjustContrast(GetOsdValue(_MENU_FUN_CONTRAST));
#else
					UserAdjustContrast(GET_OSD_CONTRAST());
#endif
					UserAdjustBrightness(GET_OSD_BRIGHTNESS());	
				#if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))    
					UserAdjustColorEffectMode();
				#endif
				    break;
			#endif


			
          		case _MENU_FUN_COLORTEMP:
#if(_DEF_CT_JX)
					if(((g_usAdjustValue == _CT_USER)||(g_usAdjustValue >= _CT_GAMMA18 && g_usAdjustValue <= _CT_GAMMA26)) && GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
#else
                	if(g_usAdjustValue == _CT_USER && GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
#endif
					{
              			g_usBackupValue = 0;
              			SET_OSD_STATE(_MENU_FUN_RGB);
			  		}
              	break;

		  		case _MENU_FUN_R:
		  		case _MENU_FUN_G:
		  		case _MENU_FUN_B:
              		g_usBackupValue = GET_OSD_STATE_PREVIOUS() - _MENU_FUN_R;	//��������ѡ��ĵڼ���
              		SET_OSD_STATE(_MENU_FUN_RGB);
             	 break;
            

#if(_DEF_STA_SIX_COLOR)
			case _MENU_FUN_SAT_STATE:
				sat_color_num = GET_SAT_STATE() - _SIXCOLOR_R;
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{						
					for(i = 0; i<6; i++)	//���
						OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));
					
					 OsdDispSliderAndNumber(_ITEM_1_ROW+sat_color_num*2,_MENU_FUN_SAT_RED+sat_color_num,GetOsdValue(_MENU_FUN_SAT_RED+sat_color_num));
					 OsdFontPut1BitTable(ROW(_ITEM_1_ROW+sat_color_num*2), COL(_ITEM_3_COL+_ITEM_SLIDER_OFFSET), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0); //���ӽ�����,����1BITͼ��ȥ����

					 //���������Ȳ���
					 OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*sat_color_num)*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(_MENU_FUN_SAT_RED+sat_color_num))*12, ((_ITEM_1_ROW+2*sat_color_num)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					 OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*sat_color_num))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*sat_color_num)+1)*18+7, _COLOR_WINDOW_BG);
					 SET_OSD_STATE(_MENU_FUN_SAT_RED+sat_color_num);

				}
			break;

			case _MENU_FUN_HUE_STATE:
				sat_color_num = GET_HUE_STATE() - _SIXCOLOR_R;
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{						
					for(i = 0; i<6; i++)	//���
						OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));
					
					 OsdDispSliderAndNumber(_ITEM_1_ROW+sat_color_num*2,_MENU_FUN_HUE_RED+sat_color_num,GetOsdValue(_MENU_FUN_HUE_RED+sat_color_num));
					 OsdFontPut1BitTable(ROW(_ITEM_1_ROW+sat_color_num*2), COL(_ITEM_3_COL+_ITEM_SLIDER_OFFSET), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0); //���ӽ�����,����1BITͼ��ȥ����

					 //���������Ȳ���
					 OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*sat_color_num)*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(_MENU_FUN_HUE_RED+sat_color_num))*12, ((_ITEM_1_ROW+2*sat_color_num)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					 OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*sat_color_num))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*sat_color_num)+1)*18+7, _COLOR_WINDOW_BG);
					 SET_OSD_STATE(_MENU_FUN_HUE_RED+sat_color_num);

				}
			break;
	

#endif






/*
		case _MENU_FUN_SIGNAL:
		
			if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
				SET_FORCE_POW_SAV_STATUS(_FALSE);
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
		
				#if(_SOURCE_AUTO_ON)
				if(GET_OSD_INPUT_PORT_OSD_ITEM() == _OSD_INPUT_AUTO)
				{
					SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
					
					if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
					{
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
				}
				else
				{		
					SysSourceSwitchInputPort(OsdFuncGetOsdItemFlag());
					SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
					if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
					{
						UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
						UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					}
				}
				#else					
				SysSourceSwitchInputPort(OsdFuncGetOsdItemFlag());
				SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
				if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
				   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				{
					UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				}						
				#endif   			
			}
			else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{			
				SET_OSD_INPUT_PORT_OSD_ITEM(g_usBackupValue);
			}
		
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			break;

		case _MENU_FUN_LANGUAGE:
		
			OsdFuncClearOsd(ROW(1), COL(7), WIDTH(_OSD_MAIN_MENU_WIDTH-7), HEIGHT(_OSD_MAIN_MENU_HEIGHT-4));					
			RTDOsdTableFuncPutStringCenter(_TITLE_ROW_START, _TITLE_COL_START, _TITLE_COL_END, _PFONT_PAGE_0, _OSD_STRING_TITLE, OSD_MAIN_MENU_ITEM - _OSD_MAIN_SOURCE+1,COLOR(_CP_WHITE, _CP_BG), _TITLE_PIXEL_OFFSET, GET_OSD_LANGUAGE()); 

			for(i=0; i<6; i++)
			{
				if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_NULL)
				{
					OSD_MASKSET(OSD_MAIN_MENU_ITEM,i);	
				}
				else
				{
					SG_PutStringProp(_ITEM_1_ROW+i*3, _OSD_ITEM_COL_START, _PFONT_PAGE_1, _OSD_STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i], COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
				}
			}
			UpdateMaskValue();

			break;	
*/
		case _MENU_FUN_OVERCLOCK:
			
			if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
				//UserCommonInterfaceLoadEmbeddedEdidData();
				
				PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
				UserCommonInterfaceLoadEmbeddedEdidData();
				ScalerTimerDelayXms(300);

				PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
			}
			else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
			{
				SET_OSD_OVERCLOCK(g_usBackupValue);
			}
			
			break;
			
            RTDNVRamSaveOSDData();
	}
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OSDSubMenuMove(void)
{
	BYTE i = OSD_SubMenuCur; 
//	BYTE i = 0; 
	BYTE count = 6;
	WORD WinRowStartX = 0,WinRowEndX = 1,WinRowStartY = 0,WinRowEndY = 1;
	BYTE enable = _ENABLE;
#if(_DEF_PAGE8)
	BYTE OSD_PAGE_2 = 0;
#endif

#if(_DEF_CT_JX)
	BYTE CT_DATA_ORDER[_CT_COLORTEMP_AMOUNT+1] =
	{
		0,//_CT_9300
		2,//_CT_7500
		4,//_CT_6500
		5,//_CT_5800
		_OFF,//_CT_SRGB
		6,//_CT_USER
		3,//_CT_7000
		1,//_CT_8000
		6,//_CT_GAMMA18
		6,//_CT_GAMMA20
		6,//_CT_GAMMA22
		6,//_CT_GAMMA24
		6//_CT_GAMMA26
	};
#endif	
	
	if((_MENU_PICTURE_TATE0 <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _DEF_OSD_2_END) && GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
	{
		g_usAdjustValue = GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);
		g_usBackupValue = GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);
	}	

	
	if((_OSD_MAIN_SOURCE <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _OSD_MAIN_OTHER))// 1�� �˵�
	{
	
		if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
		{
			while(count--)
			{
				if(OSD_MASK(OSD_MAIN_MENU_ITEM,i) == 0)
				{
					OSD_SubMenuCur = i;
					
					{
//                        Ĭ���ڵڶ��е�һ��
//						SET_OSD_STATE(_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA); 		
						SET_OSD_STATE(_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur); 		
					}
					break;			
				}
				
				if(i == 5)
				{
					i = 0;
				}
				else
				{
					i++;
				}
			}
		}
	}
	else if((_MENU_PICTURE_TATE0 <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _DEF_OSD_2_END))	// 2���˵�
	{ 
#if(_DEF_PAGE8)
		count = 7;	
#else
		count = 6;	
#endif
		{
			if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
			{
				
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				SET_OSD_ENGER(_OFF);
#endif
				while(count--)
				{	
#if(_DEF_PAGE8)
					if(i == 6)
#else
					if(i == 5)
#endif
					{
						i = 0;
					}
					else
					{
						i++;
					}
						
					if(OSD_MASK(OSD_MAIN_MENU_ITEM,i) == 0)
					{
						OSD_SubMenuCur = i;
						SET_OSD_STATE(_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur); 				
		
						break;
					}
		
				}
				
			}
			else if(GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)
			{			
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				SET_OSD_ENGER(_OFF);
#endif
				while(count--)
				{
					if(i == 0)
					{
#if(_DEF_PAGE8)
						i = 6;
#else
						i = 5;
#endif
					}
					else
					{
						i--;
					}
						
					if(OSD_MASK(OSD_MAIN_MENU_ITEM,i) == 0)
					{
						OSD_SubMenuCur = i;
						SET_OSD_STATE(_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur); 		
		
						break;
					}
				 }
		
			}
			else if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
			{	
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
                    SET_OSD_ENGER(_OFF);
#endif

				SET_OSD_STATE(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);
#if(_DEF_PAGE8)
				OSD_PAGE_2 = OSD_SubMenuCur;
#endif
				if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_NONE)
				{
					OsdFuncAdj();	
				}
				
				if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_ARROW)
				{
#if(_DEF_PROGRESS_BAR_3PAGE)
					for(i = 0; i < _OSD_NUM_DATA; i++)
						OsdWindowDrawing(_OSD_WINDOW_4_1+i, _ITEM_2_COL*12, (_ITEM_1_ROW+2*(i))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG);
					UpdateMaskValue();
#endif
#if(_DEF_PAGE8)
				OSD_SubMenuCur = OSD_PAGE_2;
#endif									

					for(i = 0; i<_HENG_COUNT; i++)
							OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));
					if(GET_OSD_STATE() == _MENU_FUN_COLORTEMP)
					{
#if(_DEF_CT_JX)
							for(i = _CT_9300; i <= _CT_8000; i++)
							{
								if(i != _CT_SRGB)
								{
									RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+CT_DATA_ORDER[i]*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + CT_DATA_ORDER[i], _MENU_FUN_COLORTEMP, i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
								}
							}
#else
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+0*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 0, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  0, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+1*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 1, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  1, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+2*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 2, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  2, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+3*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 3, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  3, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());

#endif
					}
					else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])== _MENU_FUN_LANGUAGE)
					{
						//_PFONT_PAGE_ITEM_1 + (i%_PAGE_MAX_LANGUAGE_COUNT)
						g_ucLanguage = g_usAdjustValue/_PAGE_MAX_LANGUAGE_COUNT;
						for(i=_PAGE_MAX_LANGUAGE_COUNT*g_ucLanguage; i<(g_ucLanguage+1)*_PAGE_MAX_LANGUAGE_COUNT; i++ ) 				
                            {
                            RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+(i%_PAGE_MAX_LANGUAGE_COUNT)*2, _ITEM_3_COL, _PFONT_PAGE_2, _MENU_FUN_LANGUAGE,  0, COLOR(_COLOR_MENU_FONT, _CP_BG),  i);
								if(i==_LANGUAGE_AMOUNT)
									break;
							}
					}
#if(_DEF_HOTKEY_REPLACE)
					else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _MENU_FUN_HOT_REPLACE_LEFT)
					{
						g_ucHotKey_Left = g_usAdjustValue/_PAGE_MAX_LANGUAGE_COUNT; //һ��12��ѡ��
						for(i=_PAGE_MAX_LANGUAGE_COUNT*g_ucHotKey_Left; i<(g_ucHotKey_Left+1)*_PAGE_MAX_LANGUAGE_COUNT; i++ )				
						{
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+(i%_PAGE_MAX_LANGUAGE_COUNT)*2, _ITEM_3_COL, _PFONT_PAGE_2, _MENU_FUN_HOT_REPLACE_LEFT,	i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
							if(i==11)
								break;
						}
					}
					else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _MENU_FUN_HOT_REPLACE_RIGHT)
					{
						g_ucHotKey_Right = g_usAdjustValue/_PAGE_MAX_LANGUAGE_COUNT;	//һ��12��ѡ��
						for(i=_PAGE_MAX_LANGUAGE_COUNT*g_ucHotKey_Right; i<(g_ucHotKey_Right+1)*_PAGE_MAX_LANGUAGE_COUNT; i++ ) 				
						{
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+(i%_PAGE_MAX_LANGUAGE_COUNT)*2, _ITEM_3_COL, _PFONT_PAGE_2, _MENU_FUN_HOT_REPLACE_RIGHT,	i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
							if(i==11)
								break;
						}
					}
					else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _MENU_FUN_HOT_REPLACE_EXIT)
					{
						g_ucHotKey_Exit = g_usAdjustValue/_PAGE_MAX_LANGUAGE_COUNT; //һ��12��ѡ��
						for(i=_PAGE_MAX_LANGUAGE_COUNT*g_ucHotKey_Exit; i<(g_ucHotKey_Exit+1)*_PAGE_MAX_LANGUAGE_COUNT; i++ )				
						{
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+(i%_PAGE_MAX_LANGUAGE_COUNT)*2, _ITEM_3_COL, _PFONT_PAGE_2, _MENU_FUN_HOT_REPLACE_EXIT,	i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
							if(i==11)
								break;
						}
					}
#endif
					else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])== _MENU_FUN_POWER_OFF)
					{
						//_PFONT_PAGE_ITEM_1 + (i%_HENG_COUNT)
						g_ucPowerPage = g_usAdjustValue/_HENG_COUNT;
						for(i=_HENG_COUNT*g_ucPowerPage; i<(g_ucPowerPage+1)*_HENG_COUNT; i++ ) 				
							{RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+(i%_HENG_COUNT)*2, _ITEM_3_COL, _PFONT_PAGE_2, _MENU_FUN_POWER_OFF,  i, COLOR(_COLOR_MENU_FONT, _CP_BG),	GET_OSD_LANGUAGE());
								if(i==_AutoPowerOff_END)
									break;
							}
					}
					else
					{
						for(i=0; i<=GetOsdMaxItem(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]); i++ )					
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_2 , (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());

					}

				}
				
				if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_SLIDER)
				{
					for(i = 0; i<= _OSD_NUM_DATA+1; i++)
					{
						if(i!=OSD_SubMenuCur)
						{
//						���ڽ�������Ҫ��������ѡ���ֵ
//							OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));

						}
						else
						{
							OsdFontPut1BitTable(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL+_ITEM_SLIDER_OFFSET), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

						}

					}

				}	

			}
			else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
			{
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)
				SET_OSD_ENGER(_OFF);
#endif
				SET_OSD_STATE(_OSD_MAIN_BRI_CON+OSD_MAIN_MENU_ITEM);
                OSD_SubMenuCur = 0;// �����˵��˵�һ���˵� ���µ�0

				
			}
			
		}

	}

	else if((_MENU_FUN_BACKLIGHT <= GET_OSD_STATE()) && (GET_OSD_STATE() < _MENU_NULL))// 3���˵�
	{
		if((GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)||(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE))
		{
			if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_ARROW )
            OsdFuncAdj();
			else if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_SLIDER)
			{
			
				OsdDispSliderAndNumber(_ITEM_1_ROW+OSD_SubMenuCur*2,(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]));
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*OSD_SubMenuCur)*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(0))*12, ((_ITEM_1_ROW+2*OSD_SubMenuCur)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
			}
				
		}

		if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
		{
			
			SET_OSD_STATE(_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur); 
			SpecialFuncAdj();

#if(_DEF_STA_SIX_COLOR)
			if(GET_OSD_STATE() >= _MENU_FUN_SAT_RED && _MENU_FUN_HUE_YELLOW >= GET_OSD_STATE())
			{
				return;
			}
#endif
			for(i = 0; i<_HENG_COUNT; i++)
				OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));


			if(GET_OSD_STATE() == _MENU_FUN_RGB)
			{
				RTDOsdTableFuncPutStringProp(_ITEM_1_ROW, _ITEM_3_COL, _PFONT_PAGE_ITEM_1, _OSD_STRING_RGB,  0, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
				RTDOsdTableFuncPutStringProp(_ITEM_2_ROW, _ITEM_3_COL, _PFONT_PAGE_ITEM_2, _OSD_STRING_RGB,  1, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
				RTDOsdTableFuncPutStringProp(_ITEM_3_ROW, _ITEM_3_COL, _PFONT_PAGE_ITEM_3, _OSD_STRING_RGB,  2, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());

				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+g_usBackupValue*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+g_usBackupValue*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*g_usBackupValue))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*g_usBackupValue)+1)*18+7, _COLOR_WINDOW_BG);	
				return;
			}
			else
			{

#if(_DEF_PAGE8)
			for(i=0; i<7; i++)
#else
			for(i=0; i<6; i++)
#endif
			{
				if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] != _MENU_NULL)
				{
					if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ==_TYPE_SLIDER)
						OsdDispSliderAndNumber(_ITEM_1_ROW+i*2,(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]),GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]));
					else if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ==_TYPE_ARROW)
					{
						if((OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) == _MENU_FUN_OSD_RORATE) //��������תģʽ��ʱ�� 270��180�Ի�
						{
							if(GetOsdValue(_MENU_FUN_OSD_RORATE) == _OSD_ROTATE_DEGREE_270)
								RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), 3, COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
							else if(GetOsdValue(_MENU_FUN_OSD_RORATE) == _OSD_ROTATE_DEGREE_180)
								RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), 2, COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
							else
								RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
						}
#if(_DEF_STA_SIX_COLOR)
						else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) == _MENU_FUN_SAT_STATE || (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) == _MENU_FUN_HUE_STATE)
						{
							continue;
						}
#endif
						else
							RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
					}
				}
			}	
			}
#if(_DEF_PROGRESS_BAR_3PAGE)

    #if(_DEF_PAGE8)
			OSD_PAGE_2 = OSD_SubMenuCur;
    #endif

			for(i = 0; i < _OSD_NUM_DATA; i++)
				OsdWindowDrawing(_OSD_WINDOW_4_1+i, _ITEM_2_COL*12, (_ITEM_1_ROW+2*(i))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG);
			UpdateMaskValue();

    #if(_DEF_PAGE8)
			OSD_SubMenuCur = OSD_PAGE_2;
    #endif

#endif
		}


            
		if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE))
		{
			
			SET_OSD_STATE(_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur); 
			SpecialFuncAdj();
#if(_DEF_STA_SIX_COLOR)
			if(GET_OSD_STATE() == _MENU_FUN_SAT_STATE || GET_OSD_STATE() == _MENU_FUN_HUE_STATE)
			{
				return;
			}
#endif

			
			for(i = 0; i<_HENG_COUNT; i++)
				OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));

#if(_DEF_PAGE8)
			for(i=0; i<7; i++)
#else
			for(i=0; i<6; i++)
#endif
			{
				if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] != _MENU_NULL)
				{
					if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ==_TYPE_SLIDER)
						OsdDispSliderAndNumber(_ITEM_1_ROW+i*2,(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]),GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]));
					else if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ==_TYPE_ARROW)
					{
#if(_DEF_STA_SIX_COLOR)
								if((OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) == _MENU_FUN_SAT_STATE || (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) == _MENU_FUN_HUE_STATE)
								{
									continue;
								}
#endif


					
								if((OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) == _MENU_FUN_OSD_RORATE)	//��������תģʽ��ʱ�� 270��180�Ի�
								{
									if(GetOsdValue(_MENU_FUN_OSD_RORATE) == _OSD_ROTATE_DEGREE_270)
										RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), 3, COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
									else if(GetOsdValue(_MENU_FUN_OSD_RORATE) == _OSD_ROTATE_DEGREE_180)
										RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), 2, COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
									else
										RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
								}
								else
									RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]), COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
					}
				}
			}	
			
#if(_DEF_PROGRESS_BAR_3PAGE)
#if(_DEF_PAGE8)
			OSD_PAGE_2 = OSD_SubMenuCur;
#endif
			for(i = 0; i < _OSD_NUM_DATA; i++)
				OsdWindowDrawing(_OSD_WINDOW_4_1+i, _ITEM_2_COL*12, (_ITEM_1_ROW+2*(i))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG);
			UpdateMaskValue();
#if(_DEF_PAGE8)
			OSD_SubMenuCur = OSD_PAGE_2;
#endif
#endif
		}

	}

	
	if((_OSD_MAIN_SOURCE <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _OSD_MAIN_OTHER))
	{
		ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_8);
		OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_1_COL*12-10,((_ITEM_1_ROW+2*(GET_OSD_STATE()-_OSD_MAIN_SOURCE)))*18-9, (_ITEM_1_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*((GET_OSD_STATE()-_OSD_MAIN_SOURCE)))+1)*18+7, _COLOR_WINDOW_BG);	

	}
	if((_MENU_PICTURE_TATE0 <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _DEF_OSD_2_END))
	{
		ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
		OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(OSD_SubMenuCur))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
		OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_2_COL*12-10,((_ITEM_1_ROW+2*(OSD_SubMenuCur)))*18-9, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18+7, _COLOR_WINDOW_BG);	
		
	}
	else if((_MENU_FUN_BACKLIGHT <= GET_OSD_STATE()) && (GET_OSD_STATE() < _MENU_NULL))
	{	

		switch(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))
		{
			case _TYPE_NONE:
				break;

		    case _TYPE_SLIDER:
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*OSD_SubMenuCur)*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(0))*12, ((_ITEM_1_ROW+2*OSD_SubMenuCur)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
				
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*OSD_SubMenuCur))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*OSD_SubMenuCur)+1)*18+7, _COLOR_WINDOW_BG);	
				break;
				
		    case _TYPE_ARROW:
				if(GET_OSD_STATE() == _MENU_FUN_COLORTEMP)
				{
#if(_DEF_CT_JX)
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*CT_DATA_ORDER[GET_COLOR_TEMP_TYPE()])*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*CT_DATA_ORDER[GET_COLOR_TEMP_TYPE()])+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*CT_DATA_ORDER[GET_COLOR_TEMP_TYPE()]))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*CT_DATA_ORDER[GET_COLOR_TEMP_TYPE()])+1)*18+7, _COLOR_WINDOW_BG);	

#else
					if(_CT_9300 == GET_COLOR_TEMP_TYPE())
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*0)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*0)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*0))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*0)+1)*18+7, _COLOR_WINDOW_BG);	

					}
					else if(_CT_7500 == GET_COLOR_TEMP_TYPE())
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*1)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*1)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*1))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*1)+1)*18+7, _COLOR_WINDOW_BG);	
					}
					else if(_CT_6500 == GET_COLOR_TEMP_TYPE())
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*2))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*2)+1)*18+7, _COLOR_WINDOW_BG);	
					}
					else if(_CT_USER == GET_COLOR_TEMP_TYPE())
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*3)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*3)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*3))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*3)+1)*18+7, _COLOR_WINDOW_BG);	
					}
#endif
				}
				else if(0)//(GET_OSD_STATE() == _MENU_FUN_DP_VER)
				{
				    if(GET_OSD_DP_D0_VERSION())
				    {
                    OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(1))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,     ((_ITEM_1_ROW+2*1)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,		 (_ITEM_1_ROW+2*(1))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*1)+1)*18+7, _COLOR_WINDOW_BG);	
				    }
					else
					{
                    OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*0)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,     ((_ITEM_1_ROW+2*0)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,		 (_ITEM_1_ROW+2*0)*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*0)+1)*18+7, _COLOR_WINDOW_BG);	
					}
				}
				else if(GET_OSD_STATE() == _MENU_FUN_LANGUAGE)
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT)*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT)*36+7, _COLOR_WINDOW_BG);	
				}
#if(_DEF_HOTKEY_REPLACE)
				else if(GET_OSD_STATE() >= _MENU_FUN_HOT_REPLACE_LEFT && GET_OSD_STATE() <= _MENU_FUN_HOT_REPLACE_EXIT)
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT)*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_PAGE_MAX_LANGUAGE_COUNT)*36+7, _COLOR_WINDOW_BG);	
				}
#endif
				else if(GET_OSD_STATE() == _MENU_FUN_POWER_OFF)
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT)*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT)*36+7, _COLOR_WINDOW_BG);	
				}
				else if(GET_OSD_STATE() == _MENU_FUN_OSD_RORATE)
				{   
					if(g_ucOsdRorateState==_OSD_ROTATE_DEGREE_270)
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*_OSD_ROTATE_DEGREE_180)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*_OSD_ROTATE_DEGREE_180)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+_OSD_ROTATE_DEGREE_180*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+_OSD_ROTATE_DEGREE_180*36+7, _COLOR_WINDOW_BG);	
					}
					else if(g_ucOsdRorateState==_OSD_ROTATE_DEGREE_180)
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*_OSD_ROTATE_DEGREE_270)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*_OSD_ROTATE_DEGREE_270)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+_OSD_ROTATE_DEGREE_270*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+_OSD_ROTATE_DEGREE_270*36+7, _COLOR_WINDOW_BG);	
					}
					else
					{
						OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
						OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36+7, _COLOR_WINDOW_BG);	
					}
					
				}

				else
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36+7, _COLOR_WINDOW_BG);	
						
				}

			break;

			
			case _TYPE_SUBMENU:
				
			break;
		}
	}


}


//--------------------------------------------------
// Description  :��ʼ��OSD_ITEM_BASE���飬����������ܶ�λ��
// Input Value  :
// Output Value :
//--------------------------------------------------
void UpdateMaskItem(void)
{
	BYTE i,j;
	
	memset(OSD_ITEM_BASE, 0xff, sizeof(OSD_ITEM_BASE));
	
	for(i=0; i<_OSD_MAIN_MENU_COUNT; i++)
	{
		for(j=0; j<6; j++)
		{
			if(OsdStateDefine[i][j] != _MENU_NULL)
			{
				OSD_ITEM(OsdStateDefine[i][j]) = ((i<<4) | j);								
			}
			else

			{
				OSD_MASKSET(i,j);	
			}
		}
	}
}
//--------------------------------------------------
// Description  :	�߼��б����������ӹ���  ��ʱֻ��hotkeyʹ��
// Input Value  :
// Output Value :
//--------------------------------------------------
void UpdateItemMaskValue(void)
{
	BYTE i = 0;

#if((_HDR10_SUPPORT == _OFF)&&((_PROJECT == _RL6463_PROJECT)||(_PROJECT == _RL6369_PROJECT)))
	BYTE pucHDRInfoData[_HW_DP_INFOFRAME_RSV0_LENGTH];
	ScalerGetHDR10Data_MOCK(pucHDRInfoData);
	if(((GET_OSD_HDR_MODE() == _HDR10_MODE_AUTO)&&(pucHDRInfoData[0] == 1)&&(pucHDRInfoData[1] == 0x1A)&&(pucHDRInfoData[2] == 2))||(GET_OSD_HDR_MODE() == _HDR10_MODE_FORCE_2084))			
#elif(_DEF_HDCP1_4)
	if(GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)
#elif(Project_ID == _ID_SANSE_2795QR_2K180_NF0_)
	if(0)
#else
	if(0)//if(((GET_OSD_HDR_MODE() == _HDR10_MODE_AUTO)&&(GET_HDR10_EOTF_SETTING() == _HDR_TARGET_STATUS_SMPTE_ST_2084))||(GET_OSD_HDR_MODE() == _HDR10_MODE_FORCE_2084))
#endif
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_LOWBLUE);
		OSD_ITEM_MASK_SET(_MENU_FUN_HUE);
		OSD_ITEM_MASK_SET(_MENU_FUN_SATURATION);
#if(_DEF_STA_SIX_COLOR)
		OSD_ITEM_MASK_SET(_MENU_FUN_HUE_STATE);
		OSD_ITEM_MASK_SET(_MENU_FUN_SAT_STATE);
#endif


		OSD_ITEM_MASK_SET(_MENU_FUN_BACKLIGHT);		
		OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST);		
		OSD_ITEM_MASK_SET(_MENU_FUN_BRIGHTNESS); 	
		OSD_ITEM_MASK_SET(_MENU_FUN_SHARPNESS);
		OSD_ITEM_MASK_SET(_MENU_FUN_ECO);		
		OSD_ITEM_MASK_SET(_MENU_FUN_DCR);
#if(_DEF_OPPOSITE_DCR)
		OSD_ITEM_MASK_SET(_MENU_FUN_DCR_OPPOSITE);
#endif
		
		OSD_ITEM_MASK_SET(_MENU_FUN_GAMMA);
		OSD_ITEM_MASK_SET(_MENU_FUN_COLORGAMUT);

		OSD_ITEM_MASK_SET(_MENU_FUN_COLORTEMP);//henry
		OSD_ITEM_MASK_CLR(_MENU_FUN_HDR_COLOR);
		
	}
	else
	{

		OSD_ITEM_MASK_SET(_MENU_FUN_HDR_COLOR);
		OSD_ITEM_MASK_CLR(_MENU_FUN_COLORTEMP); //henry

		OSD_ITEM_MASK_CLR(_MENU_FUN_LOWBLUE);
		OSD_ITEM_MASK_CLR(_MENU_FUN_ECO);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_DCR);
#if(_DEF_OPPOSITE_DCR)
		OSD_ITEM_MASK_CLR(_MENU_FUN_DCR_OPPOSITE);
#endif


#if(_DEF_COLORFUL && _DEF_OPPOSITE_DCR == _OFF)
		if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD && GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_COLORFUL)||(GET_OSD_DCR_STATUS() != _OFF))
#elif(_DEF_OPPOSITE_DCR)
		if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD)||(GET_OSD_DCR_STATUS() != _OFF || GET_OSD_DCR_OPPOSITE() != _OFF))
#else
		if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD)||(GET_OSD_DCR_STATUS() != _OFF))
#endif
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_BACKLIGHT);		
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST);		
			OSD_ITEM_MASK_SET(_MENU_FUN_BRIGHTNESS); 	
			OSD_ITEM_MASK_SET(_MENU_FUN_SHARPNESS);
			
		}
		else
		{
		
			OSD_ITEM_MASK_CLR(_MENU_FUN_BACKLIGHT);		
			OSD_ITEM_MASK_CLR(_MENU_FUN_CONTRAST);		
			OSD_ITEM_MASK_CLR(_MENU_FUN_BRIGHTNESS); 	
			OSD_ITEM_MASK_CLR(_MENU_FUN_SHARPNESS);

		}

		if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_GAMMA);
			OSD_ITEM_MASK_SET(_MENU_FUN_SATURATION);	
			OSD_ITEM_MASK_SET(_MENU_FUN_HUE);
#if(_DEF_STA_SIX_COLOR)
			OSD_ITEM_MASK_SET(_MENU_FUN_HUE_STATE);
			OSD_ITEM_MASK_SET(_MENU_FUN_SAT_STATE);
#endif

		}
		else
		{
			OSD_ITEM_MASK_CLR(_MENU_FUN_GAMMA);
			OSD_ITEM_MASK_CLR(_MENU_FUN_SATURATION);	
			OSD_ITEM_MASK_CLR(_MENU_FUN_HUE);
#if(_DEF_STA_SIX_COLOR)
			OSD_ITEM_MASK_CLR(_MENU_FUN_HUE_STATE);
			OSD_ITEM_MASK_CLR(_MENU_FUN_SAT_STATE);
#endif
		}
		
	}


/*						COLORTEMP				 */

#if(_DEF_CT_JX)
	if(GET_COLOR_TEMP_TYPE() == _CT_USER || (GET_COLOR_TEMP_TYPE() >= _CT_GAMMA18 && GET_COLOR_TEMP_TYPE() <= _CT_GAMMA26))
	{
		OSD_ITEM_MASK_CLR(_MENU_FUN_R);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_G);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_B);			
	}
	else
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_R);		
		OSD_ITEM_MASK_SET(_MENU_FUN_G);		
		OSD_ITEM_MASK_SET(_MENU_FUN_B);		
	}

#else
	if(GET_COLOR_TEMP_TYPE() != _CT_USER)
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_R);		
		OSD_ITEM_MASK_SET(_MENU_FUN_G);		
		OSD_ITEM_MASK_SET(_MENU_FUN_B);		
	}
	else
	{
		OSD_ITEM_MASK_CLR(_MENU_FUN_R);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_G);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_B);		 
	}
#endif 
#if(_LED_EFFECT_TJMODE14)
   if( GET_OSD_LED_LIGHTMODE() == LightMode_OFF)
   {
       OSD_ITEM_MASK_SET(_MENU_FUN_COLOR);      
   }
   else
    {
       OSD_ITEM_MASK_CLR(_MENU_FUN_COLOR);      
    }
#endif


/*						VGA 				 */
	if(SysSourceGetSourceType() != _SOURCE_VGA)
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_VGA_HPOSITON);		
		OSD_ITEM_MASK_SET(_MENU_FUN_VGA_VPOSITON);		
		OSD_ITEM_MASK_SET(_MENU_FUN_VGA_CLK);		
		OSD_ITEM_MASK_SET(_MENU_FUN_VGA_PHASE);
		OSD_ITEM_MASK_SET(_MENU_FUN_AUTO_ADJUST);		
		OSD_ITEM_MASK_SET(_MENU_FUN_AUTO_COLOR);
	}
	else
	{
		OSD_ITEM_MASK_CLR(_MENU_FUN_VGA_HPOSITON);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_VGA_VPOSITON);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_VGA_CLK);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_VGA_PHASE);
		OSD_ITEM_MASK_CLR(_MENU_FUN_AUTO_ADJUST);		
		OSD_ITEM_MASK_CLR(_MENU_FUN_AUTO_COLOR);
	}

#if(_DEF_2795E06)
	if(SysSourceGetSourceType() != _SOURCE_DP && SysSourceGetInputPort() != _D1_INPUT_PORT)//if(SysSourceGetInputPort() != _D0_INPUT_PORT)//if(SysSourceGetSourceType() != _SOURCE_DP)
#else
    if(SysSourceGetSourceType() != _SOURCE_DP)//if(SysSourceGetInputPort() != _D0_INPUT_PORT)//if(SysSourceGetSourceType() != _SOURCE_DP)
#endif
	{
        OSD_ITEM_MASK_SET(_MENU_FUN_DP_VER);
    }
	else
	{
        OSD_ITEM_MASK_CLR(_MENU_FUN_DP_VER);
	}


if(g_ucOsdRorateState != _OFF)
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_FV_INFORMATION);
	}
	else
	{
		OSD_ITEM_MASK_CLR(_MENU_FUN_FV_INFORMATION);
	}

	if(GET_OSD_MPRT() != _OFF)
	{
	
		OSD_ITEM_MASK_SET(_MENU_FUN_OD);
		#if _FREESYNC_SUPPORT
		OSD_ITEM_MASK_SET(_MENU_FUN_FREESYNC);
		#endif
	}
	else
	{
	
		OSD_ITEM_MASK_CLR(_MENU_FUN_OD);
		#if _FREESYNC_SUPPORT
		OSD_ITEM_MASK_CLR(_MENU_FUN_FREESYNC);
		#endif
	}

	if((GET_OSD_FREE_SYNC_STATUS() != _OFF))
	{		
		OSD_ITEM_MASK_SET(_MENU_FUN_MPRT);
	}
	else
	{
		OSD_ITEM_MASK_CLR(_MENU_FUN_MPRT);
	}

	if(GET_INPUT_TIMING_VFREQ() < 750)
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_MPRT);
	}

#if(_DEF_ECO_SET)
	if(GET_OSD_COLOR_EFFECT()==_COLOREFFECT_GAME || GET_OSD_COLOR_EFFECT()==_COLOREFFECT_MOVIE)
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_SATURATION);
		OSD_ITEM_MASK_SET(_MENU_FUN_VIVID);
	}
	else
	{
		OSD_ITEM_MASK_CLR(_MENU_FUN_VIVID);
	}
#endif



#if(_DEF_COLORFUL)
	if(GET_OSD_COLOR_EFFECT()== _COLOREFFECT_COLORFUL)
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_SATURATION);
	}
#endif

#if(_DEF_OPPOSITE_DCR)
	if(GET_OSD_DCR_STATUS())
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_DCR_OPPOSITE);
	}
	else if(GET_OSD_DCR_OPPOSITE())
	{
		OSD_ITEM_MASK_SET(_MENU_FUN_DCR);
	}

#endif

	OSD_ITEM_MASK_CLR(_MENU_FUN_HOTLEFT);		
	OSD_ITEM_MASK_CLR(_MENU_FUN_HOTRIGHT);

	for(i = _MENU_FUN_BACKLIGHT; i<_MENU_NULL; i++)
	{
		if(OSD_ITEM(i) == 0xff)
		{
			OSD_ITEM_MASK_SET(i);
		}
	}
}



//--------------------------------------------------
// Description  :	�߼��б����������ӹ���
// Input Value  :
// Output Value :
//--------------------------------------------------
void UpdateMaskValue(void)
{
	BYTE i = 0;
	BYTE j = 0;
#if((_HDR10_SUPPORT == _OFF)&&((_PROJECT == _RL6463_PROJECT)||(_PROJECT == _RL6369_PROJECT)))
	BYTE pucHDRInfoData[_HW_DP_INFOFRAME_RSV0_LENGTH];	
	ScalerGetHDR10Data_MOCK(pucHDRInfoData);
	if(((GET_OSD_HDR_MODE() == _HDR10_MODE_AUTO)&&(pucHDRInfoData[0] == 1)&&(pucHDRInfoData[1] == 0x1A)&&(pucHDRInfoData[2] == 2))||(GET_OSD_HDR_MODE() == _HDR10_MODE_FORCE_2084))
#elif(_DEF_HDCP1_4)
	if(GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)
#else
	if(0)//if(((GET_OSD_HDR_MODE() == _HDR10_MODE_AUTO)&&(GET_HDR10_EOTF_SETTING() == _HDR_TARGET_STATUS_SMPTE_ST_2084))||(GET_OSD_HDR_MODE() == _HDR10_MODE_FORCE_2084))
#endif
	{
		OSD_MASK_SET(_MENU_FUN_LOWBLUE);
		OSD_MASK_SET(_MENU_FUN_HUE);
		OSD_MASK_SET(_MENU_FUN_SATURATION);
#if(_DEF_STA_SIX_COLOR)
		OSD_MASK_SET(_MENU_FUN_HUE_STATE);
		OSD_MASK_SET(_MENU_FUN_SAT_STATE);
#endif

		
		OSD_MASK_SET(_MENU_FUN_BACKLIGHT);		
		OSD_MASK_SET(_MENU_FUN_CONTRAST);		
		OSD_MASK_SET(_MENU_FUN_BRIGHTNESS); 	
		OSD_MASK_SET(_MENU_FUN_SHARPNESS);
		OSD_MASK_SET(_MENU_FUN_ECO);		
		OSD_MASK_SET(_MENU_FUN_DCR);
#if(_DEF_OPPOSITE_DCR)
		OSD_MASK_SET(_MENU_FUN_DCR_OPPOSITE);
#endif
		OSD_MASK_SET(_MENU_FUN_GAMMA);
		OSD_MASK_SET(_MENU_FUN_COLORGAMUT);

		OSD_MASK_SET(_MENU_FUN_COLORTEMP);// henry 
		OSD_MASK_CLR(_MENU_FUN_HDR_COLOR); 
		
	}
	else
	{
		OSD_MASK_SET(_MENU_FUN_HDR_COLOR); 
		OSD_MASK_CLR(_MENU_FUN_COLORTEMP);// henry 
		
		OSD_MASK_CLR(_MENU_FUN_LOWBLUE);
		OSD_MASK_CLR(_MENU_FUN_COLORGAMUT);
		OSD_MASK_CLR(_MENU_FUN_ECO);		
		OSD_MASK_CLR(_MENU_FUN_DCR);
#if(_DEF_OPPOSITE_DCR)
		OSD_MASK_CLR(_MENU_FUN_DCR_OPPOSITE);
#endif

#if(_DEF_COLORFUL && _DEF_OPPOSITE_DCR == _OFF)
		if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD && GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_COLORFUL)||(GET_OSD_DCR_STATUS() != _OFF))
#elif(_DEF_OPPOSITE_DCR)
		if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD)||(GET_OSD_DCR_STATUS() != _OFF || GET_OSD_DCR_OPPOSITE() != _OFF))
#else
		if((GET_OSD_COLOR_EFFECT()!= _COLOREFFECT_STANDARD)||(GET_OSD_DCR_STATUS() != _OFF))
#endif
		{
			OSD_MASK_SET(_MENU_FUN_BACKLIGHT);		
			OSD_MASK_SET(_MENU_FUN_CONTRAST);		
			OSD_MASK_SET(_MENU_FUN_BRIGHTNESS); 	
			OSD_MASK_SET(_MENU_FUN_SHARPNESS);
			
		}
		else
		{
		
			OSD_MASK_CLR(_MENU_FUN_BACKLIGHT);		
			OSD_MASK_CLR(_MENU_FUN_CONTRAST);		
			OSD_MASK_CLR(_MENU_FUN_BRIGHTNESS); 	
			OSD_MASK_CLR(_MENU_FUN_SHARPNESS);

		}

		
		if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
		{
			OSD_MASK_SET(_MENU_FUN_SATURATION);		
			OSD_MASK_SET(_MENU_FUN_GAMMA);
			OSD_MASK_SET(_MENU_FUN_HUE);	
#if(_DEF_STA_SIX_COLOR)
			OSD_MASK_SET(_MENU_FUN_HUE_STATE);
			OSD_MASK_SET(_MENU_FUN_SAT_STATE);
#endif

		}
		else
		{
			OSD_MASK_CLR(_MENU_FUN_GAMMA);
			OSD_MASK_CLR(_MENU_FUN_SATURATION);	
#if(_DEF_STA_SIX_COLOR)
			OSD_MASK_CLR(_MENU_FUN_HUE_STATE);
			OSD_MASK_CLR(_MENU_FUN_SAT_STATE);
#endif
			OSD_MASK_CLR(_MENU_FUN_HUE);	
		}
	}

	
/*						COLORTEMP				 */

#if(_DEF_CT_JX)
	if(GET_COLOR_TEMP_TYPE() == _CT_USER || (GET_COLOR_TEMP_TYPE() >= _CT_GAMMA18 && GET_COLOR_TEMP_TYPE() <= _CT_GAMMA26))
	{
		OSD_MASK_CLR(_MENU_FUN_R);		
		OSD_MASK_CLR(_MENU_FUN_G);		
		OSD_MASK_CLR(_MENU_FUN_B);		
	}
	else
	{
		OSD_MASK_SET(_MENU_FUN_R);		
		OSD_MASK_SET(_MENU_FUN_G);		
		OSD_MASK_SET(_MENU_FUN_B);		
	}
#else
	if(GET_COLOR_TEMP_TYPE() != _CT_USER)
	{
		OSD_MASK_SET(_MENU_FUN_R);		
		OSD_MASK_SET(_MENU_FUN_G);		
		OSD_MASK_SET(_MENU_FUN_B);		
	}
	else
	{
		OSD_MASK_CLR(_MENU_FUN_R);		
		OSD_MASK_CLR(_MENU_FUN_G);		
		OSD_MASK_CLR(_MENU_FUN_B);		
	}
#endif
#if(_LED_EFFECT_TJMODE14)

    if( GET_OSD_LED_LIGHTMODE() == LightMode_OFF)
    {
        OSD_MASK_SET(_MENU_FUN_COLOR);      
    }
    else
    {
        OSD_MASK_CLR(_MENU_FUN_COLOR);      
    }
#endif

/*						VGA 				 */
	if(SysSourceGetSourceType() != _SOURCE_VGA)
	{
		OSD_MASK_SET(_MENU_FUN_VGA_HPOSITON);		
		OSD_MASK_SET(_MENU_FUN_VGA_VPOSITON);		
		OSD_MASK_SET(_MENU_FUN_VGA_CLK);		
		OSD_MASK_SET(_MENU_FUN_VGA_PHASE);
		OSD_MASK_SET(_MENU_FUN_AUTO_ADJUST);		
		OSD_MASK_SET(_MENU_FUN_AUTO_COLOR);
	}
	else
	{
		OSD_MASK_CLR(_MENU_FUN_VGA_HPOSITON);		
		OSD_MASK_CLR(_MENU_FUN_VGA_VPOSITON);		
		OSD_MASK_CLR(_MENU_FUN_VGA_CLK);		
		OSD_MASK_CLR(_MENU_FUN_VGA_PHASE);
		OSD_MASK_CLR(_MENU_FUN_AUTO_ADJUST);		
		OSD_MASK_CLR(_MENU_FUN_AUTO_COLOR);
	}

#if(_DEF_2795E06)
	if(SysSourceGetSourceType() != _SOURCE_DP && SysSourceGetInputPort() != _D1_INPUT_PORT)
#else
	if(SysSourceGetSourceType() != _SOURCE_DP)//if(SysSourceGetInputPort() != _D0_INPUT_PORT)//if(SysSourceGetSourceType() != _SOURCE_DP)
#endif
	{
        OSD_MASK_SET(_MENU_FUN_DP_VER);
    }
	else
	{
        OSD_MASK_CLR(_MENU_FUN_DP_VER);
	}


	if(GET_OSD_MPRT() != _OFF)
	{
	
		OSD_MASK_SET(_MENU_FUN_OD);
		#if _FREESYNC_SUPPORT
		OSD_MASK_SET(_MENU_FUN_FREESYNC);
		#endif
	}
	else
	{
	
		OSD_MASK_CLR(_MENU_FUN_OD);
		#if _FREESYNC_SUPPORT
		OSD_MASK_CLR(_MENU_FUN_FREESYNC);
		#endif
	}
	
	if((GET_OSD_FREE_SYNC_STATUS() != _OFF))
	{		
		OSD_MASK_SET(_MENU_FUN_MPRT);
	}
	else
	{
		OSD_MASK_CLR(_MENU_FUN_MPRT);
	
	}

	if(GET_INPUT_TIMING_VFREQ() < 750)
	{
		OSD_MASK_SET(_MENU_FUN_MPRT);
	}

if(g_ucOsdRorateState != _OFF)
	{
		OSD_MASK_SET(_MENU_FUN_FV_INFORMATION);
	}
	else
	{
		OSD_MASK_CLR(_MENU_FUN_FV_INFORMATION);
	}

#if(_DEF_ECO_SET)
	if(GET_OSD_COLOR_EFFECT()==_COLOREFFECT_GAME || GET_OSD_COLOR_EFFECT()==_COLOREFFECT_MOVIE)
	{
		OSD_MASK_SET(_MENU_FUN_SATURATION);
		OSD_MASK_SET(_MENU_FUN_VIVID);
	}
	else
	{
		OSD_MASK_CLR(_MENU_FUN_VIVID);
	}
#endif

#if(_DEF_OPPOSITE_DCR)
	if(GET_OSD_DCR_STATUS())
	{
		OSD_MASK_SET(_MENU_FUN_DCR_OPPOSITE);
	}
	else if(GET_OSD_DCR_OPPOSITE())
	{
		OSD_MASK_SET(_MENU_FUN_DCR);
	}
#endif

#if(_DEF_COLORFUL)
	if(GET_OSD_COLOR_EFFECT()== _COLOREFFECT_COLORFUL)
	{
		OSD_MASK_SET(_MENU_FUN_SATURATION);
	}
#endif




	if(OSD_MAIN_MENU_ITEM < 7)
	{

#if(_DEF_PAGE8)
		for(i = 0; i < 7; i++)
#else
		for(i = 0; i < 6; i++)
#endif
		{
		
        
			if(OSD_MASK(OSD_MAIN_MENU_ITEM,i))
			{
				
				OsdMenuDrawingHighlight(_OSD_WINDOW_4_1+i, _COLOR_MENU_FONT_MASK, _CP_BG, _ENABLE);
			}
			else
			{
				OsdMenuDrawingHighlight(_OSD_WINDOW_4_1+i, _COLOR_MENU_FONT_MASK, _CP_BG, _DISABLE);
			}
		}
	}
	else
	{
#if(_DEF_PAGE8)
		for(i = 0; i < 7; i++)
#else
		for(i = 0; i < 6; i++)
#endif
			OsdMenuDrawingHighlight(_OSD_WINDOW_4_1+i, _COLOR_MENU_FONT_MASK, _CP_BG, _DISABLE);

	}

}
#define _DEF_OSD_EDID_INFO_NUMDATA  			4
#if(_REMIND_ENERGY_EFFICIENCY_FUNCTION==_ON)

void OsdDispEngerMainMenu(void)
{
	BYTE i = 0;
	g_ucOsdRorateState = GET_OSD_ROTATE_STATUS();
	g_ucFontPointer0 = _OSD_PAGE_0_START;
	g_ucFontPointer1 = _OSD_PAGE_1_START;
	g_ucFontPointer2 = _OSD_PAGE_2_START;

#if(_DEF_CT_JX)
	BYTE CT_DATA_ORDER[_CT_COLORTEMP_AMOUNT+1] =
	{
		0,//_CT_9300
		2,//_CT_7500
		4,//_CT_6500
		5,//_CT_5800
		_OFF,//_CT_SRGB
		6,//_CT_USER
		3,//_CT_7000
		1,//_CT_8000
		6,//_CT_GAMMA18
		6,//_CT_GAMMA20
		6,//_CT_GAMMA22
		6,//_CT_GAMMA24
		6//_CT_GAMMA26
	};

#endif

	OsdFuncCloseWindow(_OSD_WINDOW_ALL);

	//OsdDispDisableOsd();
	OsdFuncDisableOsd();

#if(_DEF_KEY_NAVIGATION)	//��������
        OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH+2), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
#elif(_DEF_OSD_LOGO)
        OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT+3), COLOR(_CP_WHITE, _CP_BG));
#elif(_DEF_OSD_EDID_INFO)
        OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT+_DEF_OSD_EDID_INFO_NUMDATA), COLOR(_CP_WHITE, _CP_BG));
#else
        OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
#endif

	//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
#if(_DEF_KEY_NAVIGATION)	//��������
        ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#elif(_DEF_OSD_LOGO)
        ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT+3), _DISABLE, 0, _ENABLE);
#elif(_DEF_OSD_EDID_INFO)
        ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT+_DEF_OSD_EDID_INFO_NUMDATA), _DISABLE, 0, _ENABLE);
#else
        ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
#endif
{
	for(i = 0; i < 6; i++)
		OsdWindowDrawing(_OSD_WINDOW_4_1+i, _ITEM_2_COL*12, (_ITEM_1_ROW+2*(i))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG);
}


	UpdateMaskItem();
	UpdateMaskValue();
	UpdateItemMaskValue();
	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

	// Adjust Color Palette
	OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

	// Load Font & Icon
	OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

	OsdFontVLCLoadFont(_FONT1_GLOBAL);

// Background window

#if(_OSD_BLACK_WHITE_TYPE == _ON)	
	OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(492), YEND(315+5), _COLOR_BG_0);
	OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(50), XEND(492), YEND(278), _COLOR_BG_1);	  
	OsdWindowDrawing(_OSD_WINDOW_2, XSTART(72+3), YSTART(54), XEND(492), YEND(274), _COLOR_BG_3);	
#else
    #if(_DEF_KEY_NAVIGATION)	//��������
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(57*12), YEND(_OSD_MAIN_MENU_HEIGHT*18), _OSD_BLACK_TYPE);
            OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(2*18+9), XEND(57*12), YEND((_OSD_MAIN_MENU_HEIGHT-1)*18-9), _COLOR_WINDOW_BG);
    #elif(_DEF_OSD_LOGO)
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT+3)*18), _OSD_BLACK_TYPE);
    #elif(_DEF_OSD_EDID_INFO)
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT+_DEF_OSD_EDID_INFO_NUMDATA)*18), _OSD_BLACK_TYPE); //��ɫ
            OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(2*18+9), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT-1+_DEF_OSD_EDID_INFO_NUMDATA)*18-9), _COLOR_WINDOW_BG);
    #else
            OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND(_OSD_MAIN_MENU_HEIGHT*18), _OSD_BLACK_TYPE);
            OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(2*18+9), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT-1)*18-9), _COLOR_WINDOW_BG);
    #endif
    	OsdFontPut1BitTable(ROW(0), COL(0), tOSD_BOARD_UP_LEFT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER)	//�˵�LOGO
            OsdFontPut1BitTable(ROW(24), COL(iv_data), tOSD_OSD_LOGO2, COLOR(_CP_BG, _CP_BLUE_120), 0);
#endif
    
#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER)	
            OsdFontPut2BitTable(ROW(23), COL(16),tOSD_OSD_LOGO3,COLOR0(_CP_WHITE),COLOR1(_CP_BG),COLOR2(_CP_GREEN),COLOR3(_CP_BG));
            RTDOsdFuncChangeColor1Bit(ROW(22), COL(5), WIDTH(17), HEIGHT(1), COLOR(_CP_BG, _CP_GREEN));
            //OsdWindowDrawingHighlight(_OSD_WINDOW_4_4,5,22,228,414,_CP_GREEN,_CP_GREEN,_CP_GREEN, _ENABLE); 
#elif(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)
            OsdFontPut2BitTable(ROW(22), COL(iv_data),tOSD_OSD_LOGO3,COLOR0(_CP_WHITE),COLOR1(_CP_BG),COLOR2(_CP_GREEN),COLOR3(_CP_BG));
            RTDOsdFuncChangeColor1Bit(ROW(22), COL(9), WIDTH(2), HEIGHT(1), COLOR(_CP_BG, _CP_GREEN));
#endif
    
    //�»���
//          OsdFontPut1BitTable(ROW(_OSD_MAIN_MENU_HEIGHT-1), COL(0), tOSD_BOARD_DOWN_LEFT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
#endif

	for(i= 0; i<_HENG_COUNT; i++)
	{
	OsdFontPut1BitTable(ROW(_ITEM_1_ROW+1+i*2), COL(_ITEM_1_COL), tOSD_HENGXIAN, COLOR(_CP_WHITE, _CP_BG), 0);
	OsdFontPut1BitTable(ROW(_ITEM_1_ROW+1+i*2), COL(_ITEM_1_COL+18), tOSD_HENGXIAN, COLOR(_CP_WHITE, _CP_BG), 0);
	OsdFontPut1BitTable(ROW(_ITEM_1_ROW+1+i*2), COL(_ITEM_1_COL+36), tOSD_HENGXIAN, COLOR(_CP_WHITE, _CP_BG), 0);

	}
for(i= 0; i<_HENG_COUNT-1+GET_OSD_FACTORY_MODE(); i++)
	RTDOsdTableFuncPutStringProp(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_1_COL), _PFONT_PAGE_0, _OSD_STRING_TITLE, i, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());



//	UpdateOSDMainInterface(OSD_MAIN_MENU_ITEM+_OSD_MAIN_BRI_CON);


	
	UpdateOSDMainIcon();
	UpdateMaskValue();
	for(i=0; i<6; i++)
	{
		if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_NULL)
		{
			OSD_MASKSET(OSD_MAIN_MENU_ITEM,i);	
			
		}
		else
		{
			//SG_PutStringProp(_ITEM_1_ROW+i*2, _ITEM_2_COL, _PFONT_PAGE_1, _OSD_STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i], COLOR(_COLOR_MENU_FONT, _CP_BG),GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringProp( _ITEM_1_ROW+i*2,  _ITEM_2_COL,  _PFONT_PAGE_1,  _OSD_STRING_ITEM,	OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_MENU_FUN_BACKLIGHT, COLOR(_COLOR_MENU_FONT, _CP_BG), GET_OSD_LANGUAGE());
		}
	}




{	

	SET_OSD_STATE(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);

	if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_ARROW)
	{
		if(GET_OSD_STATE() == _MENU_FUN_COLORTEMP)
		{
#if(_DEF_CT_JX)
			for(i = _CT_9300; i <= _CT_8000;i++)
			{
				if(i != _CT_SRGB)
				{
					RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+CT_DATA_ORDER[i]*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + CT_DATA_ORDER[i], _MENU_FUN_COLORTEMP, i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
				}
			}
#else
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+0*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 0, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  0, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+1*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 1, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  1, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+2*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 2, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  2, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());
			RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+3*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + 3, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  3, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());

#endif
		}
		else if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])== _MENU_FUN_POWER_OFF)
		{
			
			g_ucPowerPage = g_usAdjustValue/_HENG_COUNT;
			for(i=_HENG_COUNT*g_ucPowerPage; i<(g_ucPowerPage+1)*_HENG_COUNT; i++ ) 				
			{
				RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+(i%(_HENG_COUNT))*2, _ITEM_3_COL, _PFONT_PAGE_2, _MENU_FUN_POWER_OFF,  i, COLOR(_COLOR_MENU_FONT, _CP_BG),	GET_OSD_LANGUAGE());
				if(i==_AutoPowerOff_END)
					break;
			}
		}
		else
		{
			for(i=0; i<=GetOsdMaxItem(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]); i++ )					
				RTDOsdTableFuncPutStringProp(_ITEM_1_ROW+i*2, _ITEM_3_COL, _PFONT_PAGE_ITEM_1 + i, (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),  i, COLOR(_COLOR_MENU_FONT, _CP_BG),  GET_OSD_LANGUAGE());

		}

	}
	
	if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_SLIDER)
	{
	

        for(i = 0; i<7; i++)
		{
			if(i!=OSD_SubMenuCur)
			{
//				OsdFuncClearOsd(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL), WIDTH(_ITEM_COL_LENGTH), HEIGHT(1));

			}
			else
			{
				OsdFontPut1BitTable(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_3_COL+_ITEM_SLIDER_OFFSET), tOSD_SLIDER,  COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

			}

		}

	}	

}


	OsdFuncChangeColor1Bit(_ITEM_1_ROW+2*(OSD_MAIN_MENU_ITEM+1),_ITEM_1_COL,_ITEM_COL_LENGTH,1,COLOR(_COLOR_MENU_FONT_SELECT, _CP_BG),0);
	OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(OSD_SubMenuCur))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	


{	

	switch(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))
	{
		case _TYPE_NONE:
			break;

		case _TYPE_SLIDER:
			OsdDispSliderAndNumber(_ITEM_1_ROW+OSD_SubMenuCur*2,(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]),GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]));
			OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*OSD_SubMenuCur)*18, (_ITEM_3_COL+_ITEM_SLIDER_OFFSET+GET_SILDER_PERCENT(0))*12, ((_ITEM_1_ROW+2*OSD_SubMenuCur)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE); 
			
			OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*OSD_SubMenuCur))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*OSD_SubMenuCur)+1)*18+7, _COLOR_WINDOW_BG);	
			break;
			
		case _TYPE_ARROW:
			if(GET_OSD_STATE() == _MENU_FUN_COLORTEMP)
			{
#if(_DEF_CT_JX)
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*CT_DATA_ORDER[GET_OSD_STATE()])*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*CT_DATA_ORDER[GET_OSD_STATE()])+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*CT_DATA_ORDER[GET_OSD_STATE()]))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*CT_DATA_ORDER[GET_OSD_STATE()])+1)*18+7, _COLOR_WINDOW_BG);	
#else
				if(_CT_9300 == GET_COLOR_TEMP_TYPE())
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*0)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*0)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*0))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*0)+1)*18+7, _COLOR_WINDOW_BG);	

				}
				else if(_CT_7500 == GET_COLOR_TEMP_TYPE())
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*1)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*1)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*1))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*1)+1)*18+7, _COLOR_WINDOW_BG);	
				}
				else if(_CT_6500 == GET_COLOR_TEMP_TYPE())
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*2)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*2)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*2))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*2)+1)*18+7, _COLOR_WINDOW_BG);	
				}
				else if(_CT_USER == GET_COLOR_TEMP_TYPE())
				{
					OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*3)*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*3)+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
					OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,((_ITEM_1_ROW+2*3))*18-9, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*3)+1)*18+7, _COLOR_WINDOW_BG);	
				}
#endif
			}
			else if(GET_OSD_STATE() == _MENU_FUN_POWER_OFF)
			{
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT)*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])%_HENG_COUNT)*36+7, _COLOR_WINDOW_BG);	
			}else if(GET_OSD_STATE() == _MENU_FUN_DCR)
			{
                SET_OSD_DCR_STATUS(_ON);
    #if(_DEF_ECO_SET)
			if(GET_OSD_DCR_STATUS())
			{
				SET_OSD_DCROFF_ECO(GET_OSD_COLOR_EFFECT());
				SET_OSD_COLOR_EFFECT(_COLOREFFECT_STANDARD);
			}
			else
			{
				SET_OSD_COLOR_EFFECT(GET_OSD_DCROFF_ECO());
			}	
			
			UserAdjustBacklight(GET_OSD_BACKLIGHT());

#if(_DEF_COLORFUL)
			UserAdjustContrast(GetOsdValue(_MENU_FUN_CONTRAST));
#else
			UserAdjustContrast(GET_OSD_CONTRAST());
#endif
			UserAdjustBrightness(GET_OSD_BRIGHTNESS());
#if(_ULTRA_VIVID_SUPPORT == _ON)
			UserInterfaceAdjustUltraVivid();
#endif
			UserCommonAdjustSharpness(SysSourceGetInputPort()); 		
			UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GetOsdValue(_MENU_FUN_SATURATION)); //GetSaturationValue());
#if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))    
			UserAdjustColorEffectMode();
#endif

#else
			
			if(GET_OSD_DCR_STATUS() != _OFF)
			{
				SET_OSD_COLOR_EFFECT(_COLOREFFECT_STANDARD);

#if(_DEF_COLORFUL)
				UserAdjustContrast(GetOsdValue(_MENU_FUN_CONTRAST));
#else
				UserAdjustContrast(GET_OSD_CONTRAST());
#endif

				UserAdjustBrightness(GET_OSD_BRIGHTNESS()); 
#if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))    
				UserAdjustColorEffectMode();
#endif
			}	
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
#endif
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36+7, _COLOR_WINDOW_BG);	
					
            }
            else if(GET_OSD_STATE() == _MENU_FUN_HDR)
            {
                SET_OSD_HDR_MODE(_ON);
                if(GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)
                {   
                
                #if(_TJ_GAMMA)
                                SET_OSD_GAMMA(_GAMMA_OFF);
                #endif
                    SET_OSD_PCM_STATUS(_PCM_OSD_NATIVE);
                    SET_OSD_COLOR_EFFECT(_COLOREFFECT_STANDARD);
                    SET_OSD_DCR_STATUS(_OFF);
                    
                    UserAdjustBrightness(GET_OSD_BRIGHTNESS()); 
#if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))    
                    UserAdjustColorEffectMode();
#endif
                }
                
                UserAdjustBacklight(GET_OSD_BACKLIGHT());
                
#if(_HDR10_SUPPORT == _ON)						
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                UserCommonHDRAdjust(_HDR_FLOW_OSD_MODE_CHANGE);
                UserCommonHDR10SupportSwitch(); 
#endif	
    
#if((_HDR10_SUPPORT == _OFF)&&(_PROJECT == _RL6463_PROJECT))
                MockHdrEffect();
#endif
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36+7, _COLOR_WINDOW_BG);	
					
            }
			else
			{
				OsdWindowDrawingHighlight(_OSD_WINDOW_4_7,_ITEM_3_COL*12,(_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12,((_ITEM_1_ROW+2*(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);
				OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_3_COL*12-10,(_ITEM_1_ROW*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36-9), (_ITEM_3_COL+_ITEM_COL_LENGTH)*12-2, (_ITEM_1_ROW+1)*18+(GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]))*36+7, _COLOR_WINDOW_BG);	
					
			}

		break;

		
		case _TYPE_SUBMENU:
			
		break;
	}
}

    #if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))

		if(ScalerSyncGetFREESYNCEnable() == _TRUE)
		{
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_DRR_VFREQ);
		}
	
		BackUpTempVFreq = 0;
	

      OsdDisplayVfreq();
  #endif
//���ϽǷֱ���
//#if _ITALIAN_SUPPORT
//      if(GET_OSD_LANGUAGE()==_ITALIAN)
//      RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+9), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//else 
//#endif

//#if _RUSSIAN_SUPPORT
//       if (GET_OSD_LANGUAGE()==_RUSSIAN)
//	RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+9), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//else
//#endif
//#if _FINNISH_SUPPORT
//       if (GET_OSD_LANGUAGE()==_FINNISH)
//	RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+7), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//   else
//#endif
#if _CHINESE_S_SUPPORT
          if(GET_OSD_LANGUAGE()==_CHINESE_S)
          {
              RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8),COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, GET_OSD_LANGUAGE());
              RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
          }   else
#endif
#if _CHINESE_F_SUPPORT
           if(GET_OSD_LANGUAGE()==_CHINESE_F)
               {
               RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
               RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8),COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, GET_OSD_LANGUAGE());
              }
           else
#endif
#if _JAPANESE_SUPPORT
         if(GET_OSD_LANGUAGE()==_JAPANESE)
             {
             RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
             RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8),COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, GET_OSD_LANGUAGE());
            }
         else
#endif
          {
              RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+9),COL(_OSD_MAIN_MENU_WIDTH/2+16), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, 0);
              RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+16), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
          }


//���Ͻ��ź�
	RTDOsdTableFuncPutStringProp(ROW(1), COL(1),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);

	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, GET_OSD_HPOS(), 100 - GET_OSD_VPOS());
#if(_DEF_OSD_EDID_INFO)
            OsdTextEDIDInfo();
#endif

	// Osd Enable
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	OsdFuncEnableOsd();
}


#endif

#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))

void OsdDisplayVfreq(void)
{
	WORD ucTempVfreq = 0;


		ucTempVfreq = (GET_INPUT_TIMING_VFREQ()+5)/10;
	//V Freq:

	if(BackUpTempVFreq != ucTempVfreq)
	{
		if((GET_INPUT_TIMING_HWIDTH() >= 1000) && (GET_INPUT_TIMING_VHEIGHT() >= 1000))
		{
			OsdFuncPutIcon1BitAndColorWidthHeight(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+15+8), 0x00, WIDTH(2), HEIGHT(1), COLOR(_CP_WHITE, _CP_BG));
			OsdPropShowNumber(ROW(1),  COL(_OSD_MAIN_MENU_WIDTH/2+15+8), ucTempVfreq, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_2), _PFONT_PAGE_ITEM_9, ((_CP_WHITE<<4)|_CP_BG));
			RTDOsdTableFuncPutStringProp(1, COL(_OSD_MAIN_MENU_WIDTH/2+15+10), _PFONT_PAGE_ITEM_10,_OSD_STRING_HZ,0, ((_CP_WHITE<<4)|_CP_BG), _ENGLISH);
		}
		else if((GET_INPUT_TIMING_HWIDTH() < 1000) && (GET_INPUT_TIMING_VHEIGHT() < 1000))
		{
			OsdFuncPutIcon1BitAndColorWidthHeight(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+15+7), 0x00, WIDTH(2), HEIGHT(1), COLOR(_CP_WHITE, _CP_BG));
			OsdPropShowNumber(ROW(1),  COL(_OSD_MAIN_MENU_WIDTH/2+15+7), ucTempVfreq, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_2), _PFONT_PAGE_ITEM_9, ((_CP_WHITE<<4)|_CP_BG));
			RTDOsdTableFuncPutStringProp(1, COL(_OSD_MAIN_MENU_WIDTH/2+15+9), _PFONT_PAGE_ITEM_10,_OSD_STRING_HZ,0, ((_CP_WHITE<<4)|_CP_BG), _ENGLISH);
		}
		else
		{

			OsdFuncPutIcon1BitAndColorWidthHeight(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+15+7), 0x00, WIDTH(2), HEIGHT(1), COLOR(_CP_WHITE, _CP_BG));
	   		OsdPropShowNumber(ROW(1),  COL(_OSD_MAIN_MENU_WIDTH/2+15+7), ucTempVfreq, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_2), _PFONT_PAGE_ITEM_9, ((_CP_WHITE<<4)|_CP_BG));
	        RTDOsdTableFuncPutStringProp(1, COL(_OSD_MAIN_MENU_WIDTH/2+15+9), _PFONT_PAGE_ITEM_10,_OSD_STRING_HZ,0, ((_CP_WHITE<<4)|_CP_BG), _ENGLISH);
		}
			BackUpTempVFreq = ucTempVfreq;
	}
	

	#if (_FREESYNC_SUPPORT == _ON)
    if(ScalerSyncGetFREESYNCEnable() == _TRUE)
    {
        ScalerTimerActiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_OSD_SHOW_DRR_VFREQ);
    }
	#endif
}

#endif

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void RTDOsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
    BYTE ucHeightCount = 0;
    BYTE ucWidthCount = 0;

#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _ON)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol - ucWidthCount) * g_ucOsdWidth + ucRow + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x8E, ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucHeight);            
        }
    }
    else
#endif       
    {
        for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
        {
            //ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x8C, ucWidth);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucWidth);
            usOsdAddr += g_ucOsdWidth;
        }
    }
}


//--------------------------------------------------
// Description : When the signal is selected in automatic mode, the menu is displayed as the signal source 
// Input Value : None
// Output Value :Signal source
//--------------------------------------------------
BYTE OsdSignalMessageData(void)
{

#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
	BYTE OsdSignalData_A0 = 1;
#else
	BYTE OsdSignalData_A0 = 0;
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_NO_PORT)
	BYTE OsdSignalData_D0 = OsdSignalData_A0;
#else
	BYTE OsdSignalData_D0 = OsdSignalData_A0+1;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_NO_PORT)
	BYTE OsdSignalData_D1 = OsdSignalData_D0;
#else
	BYTE OsdSignalData_D1 = OsdSignalData_D0+1;
#endif

#if (_D2_INPUT_PORT_TYPE == _D2_NO_PORT)
	BYTE OsdSignalData_D2 = OsdSignalData_D1;
#else
	BYTE OsdSignalData_D2 = OsdSignalData_D1+1;
#endif

#if (_D3_INPUT_PORT_TYPE == _D3_NO_PORT)
	BYTE OsdSignalData_D3 = OsdSignalData_D2;
#else
	BYTE OsdSignalData_D3 = OsdSignalData_D2+1;
#endif

#if (_D4_INPUT_PORT_TYPE == _D4_NO_PORT)
	BYTE OsdSignalData_D4 = OsdSignalData_D3;
#else
	BYTE OsdSignalData_D4 = OsdSignalData_D3+1;
#endif

#if(_D5_INPUT_PORT_TYPE == _D5_NO_PORT)
	BYTE OsdSignalData_D5 = OsdSignalData_D4;
#else
	BYTE OsdSignalData_D5 = OsdSignalData_D4+1;
#endif

#if (_D6_INPUT_PORT_TYPE == _D6_NO_PORT)
	BYTE OsdSignalData_D6 = OsdSignalData_D5;
#else
	BYTE OsdSignalData_D6 = OsdSignalData_D5+1;
#endif

	if(SysSourceGetInputPort() == _D0_INPUT_PORT)
		return OsdSignalData_D0;
	else if(SysSourceGetInputPort() == _D1_INPUT_PORT)
		return OsdSignalData_D1;
	else if(SysSourceGetInputPort() == _D2_INPUT_PORT)
		return OsdSignalData_D2;
	else if(SysSourceGetInputPort() == _D3_INPUT_PORT)
		return OsdSignalData_D3;
	else if(SysSourceGetInputPort() == _D4_INPUT_PORT)
		return OsdSignalData_D4;
	else if(SysSourceGetInputPort() == _D5_INPUT_PORT)
		return OsdSignalData_D5;
	else if(SysSourceGetInputPort() == _D6_INPUT_PORT)
		return OsdSignalData_D6;
	else if(SysSourceGetInputPort() == _A0_INPUT_PORT)
		return OsdSignalData_A0;
	else
		return 0;

	return 0;
}

#if(_DEF_OSD_EDID_INFO)

BYTE EdidDataConvert_OSDInfo(BYTE EDID_dataInfo_i)
{
	BYTE i = 0;
	if(EDID_dataInfo_i >= 0x61 && EDID_dataInfo_i <= 0x7A)	//a~z
	{
		i = _a_ + (EDID_dataInfo_i - 0x61);
		return i;
	}
	else if(EDID_dataInfo_i >= 0x41 && EDID_dataInfo_i <= 0x5A)	//A~Z
	{
		i = _A_ + (EDID_dataInfo_i - 0x41);
		return i;
	}	
	else if(EDID_dataInfo_i >= 0x30 && EDID_dataInfo_i <= 0x39)	//0~9
	{
		i = _0_ + (EDID_dataInfo_i - 0x30);
		return i;
	}
	else if(EDID_dataInfo_i == 0x2D || EDID_dataInfo_i == 0x5F)
	{
		return _x44_;	//-
	}
	else if(EDID_dataInfo_i == 0x20)
	{
		return 0;	//�ո�
	}
	else if(EDID_dataInfo_i == 0x2E)
	{
		return _x42_;	//.
	}
	else if(EDID_dataInfo_i == 0x0A)
	{
		return _END_;	//  /
	}
	else if(EDID_dataInfo_i == 0x2F)
	{
		return _x3f_;	//  /
	}
	else if(EDID_dataInfo_i == 0x5B)
	{
		return _x41_;	//[
	}
	else if(EDID_dataInfo_i == 0x5D)
	{
		return _x43_;	//]
	}
	else
	{
		return 0;
	}


}


#define _DEF_EDID_TIMING_COL				19
#define _DEF_EDID_TIMING_ROW				23

void OsdTextEDIDInfo()//RTDBurnInMenu
{
	BYTE pucBuffer_Info[128] = {0};
	WORD ManVal=0;
	BYTE EDID_InfoNum[15] = 0;
	BYTE i = 0;
	BYTE EDID_NameDataLong = 0;

    //window1
//        RTDOsdTableFuncPutStringProp(ROW(21), COL(_DEF_EDID_TIMING_COL), _PFONT_PAGE_0, _OSD_STRING_NOW_WINDOW, GET_OSD_LANGUAGE(), COLOR(_CP_RED,_CP_BG), GET_OSD_LANGUAGE());
    
    //   input source   
        RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL), _PFONT_PAGE_0, _OSD_STRING_NOW_SOURCE1, GET_OSD_LANGUAGE(), COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//RESOLUTION
        RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL),_PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, GET_OSD_LANGUAGE(),COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());                     



	//�ֱ�����ʾ
	switch(GET_OSD_LANGUAGE()){
        
#if _SPANISH_SUPPORT
            case _SPANISH:
                RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL+7), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
                break;
#endif
#if _FRENCH_SUPPORT
            case _FRENCH:  
                RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL+7), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
                break;
#endif
#if _RUSSIAN_SUPPORT
            case _RUSSIAN:
                RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL+8), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
                break;
#endif
#if _KOREAN_SUPPORT
            case _KOREAN:
                RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL+5), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
                break;
#endif
#if _CHINESE_S_SUPPORT
            case _CHINESE_S:
#endif
#if _JAPANESE_SUPPORT
            case _JAPANESE:
#endif
#if _CHINESE_F_SUPPORT
            case _CHINESE_F:
#endif
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL+4), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
            break;
        default:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW), COL(_DEF_EDID_TIMING_COL+7), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
            break;
            
       }

	
#if (_SOURCE_AUTO_ON)	//���Ͻ��ź���ʾ
	if(GET_OSD_INPUT_PORT_OSD_ITEM() == _OSD_INPUT_AUTO)
	{
        switch(GET_OSD_LANGUAGE()){
#if _SPANISH_SUPPORT
        case _SPANISH:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+12),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                    
            break;
#endif
#if _FRENCH_SUPPORT
        case _FRENCH:  
#endif
#if _GERMAN_SUPPORT
        case _GERMAN:  
#endif
#if _ITALIAN_SUPPORT
        case _ITALIAN:  
#endif

            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+11),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                    
            break;
#if _RUSSIAN_SUPPORT
        case _RUSSIAN:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+6),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                    
            break;
#endif
#if _KOREAN_SUPPORT
        case _KOREAN:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+5),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                    
            break;
#endif
#if _CHINESE_S_SUPPORT
        case _CHINESE_S:
#endif
#if _JAPANESE_SUPPORT
        case _JAPANESE:
#endif
#if _CHINESE_F_SUPPORT
        case _CHINESE_F:
#endif
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+3),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                    
            break;
        default:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+8),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                    
            break;
                
           }
	}
	else
#endif
	{ 
//	�ź���ʾ
	switch(GET_OSD_LANGUAGE()){
#if _SPANISH_SUPPORT
        case _SPANISH:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+12),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
#endif
#if _FRENCH_SUPPORT
        case _FRENCH:  
#endif
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+11),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;

#if _GERMAN_SUPPORT
        case _GERMAN:  
#endif
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+9),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
#if _ITALIAN_SUPPORT
        case _ITALIAN:  
#endif
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+13),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
#if _RUSSIAN_SUPPORT
        case _RUSSIAN:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+6),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
#endif
#if _KOREAN_SUPPORT
        case _KOREAN:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+5),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
#endif
#if _CHINESE_S_SUPPORT
        case _CHINESE_S:
#endif
#if _JAPANESE_SUPPORT
        case _JAPANESE:
#endif
#if _CHINESE_F_SUPPORT
        case _CHINESE_F:
#endif
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+3),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
        default:
            RTDOsdTableFuncPutStringProp(ROW(_DEF_EDID_TIMING_ROW-1), COL(_DEF_EDID_TIMING_COL+8),_PFONT_PAGE_0, _MENU_FUN_SIGNAL, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);                     
            break;
                
           }
	}


#if 0//(_DEF_EDID_SAVE_ADDR == _EDID_TABLE_LOCATION_FLASH)
	memset(EDID_InfoNum, 0, 15);
	memset(pucBuffer_Info, 0, 128);

	if(SysSourceGetInputPort() == _D0_INPUT_PORT)
		UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D0_ADDRESS_FLASH), 128, pucBuffer_Info);
	else if(SysSourceGetInputPort() == _D1_INPUT_PORT)
		UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D1_ADDRESS_FLASH), 128, pucBuffer_Info);
	else if(SysSourceGetInputPort() == _D2_INPUT_PORT)
		UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D2_ADDRESS_FLASH), 128, pucBuffer_Info);
	else if(SysSourceGetInputPort() == _D3_INPUT_PORT)
		UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D3_ADDRESS_FLASH), 128, pucBuffer_Info);
	else
		UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D0_ADDRESS_FLASH), 128, pucBuffer_Info);

	//����
	ManVal=((pucBuffer_Info[_EDID_MAN_NAME_INDEX0]<<8)|pucBuffer_Info[_EDID_MAN_NAME_INDEX1]);
	EDID_InfoNum[0]=GetManufactNameC1(ManVal);
	EDID_InfoNum[1]=GetManufactNameC2(ManVal);
	EDID_InfoNum[2]=GetManufactNameC3(ManVal);
	EDID_InfoNum[3]=_END_;
	RTDOsdTableFuncPutStringProp_EDIDInfo(24, 23, _PFONT_PAGE_0,EDID_InfoNum,COLOR(_COLOR_MENU_FONT,_CP_BG));



	memset(EDID_InfoNum, 0, 15);
	//������
	i = 0;
	for(i = 0;i<= 12;i++)
	{
		EDID_InfoNum[i] = EdidDataConvert_OSDInfo(pucBuffer_Info[0x71+i]);
		if(EDID_InfoNum[i] == _END_)
		{
			break;
		}
	}
	if(EDID_InfoNum[i] != _END_)
	{
		EDID_InfoNum[i+1] = _END_;
	}
	EDID_NameDataLong = i+1;
	RTDOsdTableFuncPutStringProp_EDIDInfo(24, 27, _PFONT_PAGE_0,EDID_InfoNum,COLOR(_COLOR_MENU_FONT,_CP_BG));


	memset(EDID_InfoNum, 0, 15);
	//���к�
	i = 0;
	for(i = 0;i<= 12;i++)
	{
		EDID_InfoNum[i] = EdidDataConvert_OSDInfo(pucBuffer_Info[0x4D+i]);
		if(EDID_InfoNum[i] == _END_)
		{
			break;
		}
	}
	if(EDID_InfoNum[i] != _END_)
	{
		EDID_InfoNum[i+1] = _END_;
	}
	RTDOsdTableFuncPutStringProp_EDIDInfo(24, (27+EDID_NameDataLong), _PFONT_PAGE_0,EDID_InfoNum,COLOR(_COLOR_MENU_FONT,_CP_BG));

#endif


}

#endif


void OsdDispMainMenu(void)
{
    BYTE i = 0;
#if(_DEF_OSD_LOGO)
	BYTE iv_data = 0;

#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)
	iv_data = 2;
#else
	iv_data = 4;
#endif

#endif

	g_ucOsdRorateState = GET_OSD_ROTATE_STATUS();
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;

#if 0//(_CUSTOMER_TYPE == _HUASHUOHUI_CUSTOMER)	//OSDˮƽ�ƶ�4���ػ�1����
	ScalerOsdHorizontalDelayStep(_OSD_HORIZONTAL_DELAY_STEP_1_PIXEL);
#endif

	OsdDispDisableOsd();

    //OsdFuncCloseWindow(_OSD_WINDOW_ALL);
 
    OsdFuncDisableOsd();

#if(_DEF_KEY_NAVIGATION)	//��������
	OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH+2), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
#elif(_DEF_OSD_LOGO)
	OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT+3), COLOR(_CP_WHITE, _CP_BG));
#elif(_DEF_OSD_EDID_INFO)
	OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT+_DEF_OSD_EDID_INFO_NUMDATA), COLOR(_CP_WHITE, _CP_BG));
#else
    OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
#endif

//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
#if(_DEF_KEY_NAVIGATION)	//��������
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#elif(_DEF_OSD_LOGO)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT+3), _DISABLE, 0, _ENABLE);
#elif(_DEF_OSD_EDID_INFO)
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT+_DEF_OSD_EDID_INFO_NUMDATA), _DISABLE, 0, _ENABLE);
#else
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
#endif



	{
#if(_DEF_PROGRESS_BAR_3PAGE)
		for(i = 0; i < _OSD_NUM_DATA; i++)
			OsdWindowDrawing(_OSD_WINDOW_4_1+i, _ITEM_2_COL*12, (_ITEM_1_ROW+2*(i))*18, (_ITEM_3_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG);
#else
		for(i = 0; i < _OSD_NUM_DATA; i++)
			OsdWindowDrawing(_OSD_WINDOW_4_1+i, _ITEM_2_COL*12, (_ITEM_1_ROW+2*(i))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(i))+1)*18, _COLOR_WINDOW_BG);
#endif
	}


	UpdateMaskItem();
	UpdateMaskValue();
	UpdateItemMaskValue();
    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);	//ɫ��

    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER||_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)	//�˵�LOGO
	OsdFontVLCLoadFont(_FONT2_GLOBAL);
#endif
    // Background window
	if(1)//(GET_OSD_ROTATE_STATUS()== _OSD_ROTATE_DEGREE_0)
	{
#if(_OSD_BLACK_WHITE_TYPE == _ON)	
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(4), XEND(492), YEND(315+5), _COLOR_BG_0);
		OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(50), XEND(492), YEND(278), _COLOR_BG_1);
		OsdWindowDrawing(_OSD_WINDOW_2, XSTART(72+3), YSTART(54), XEND(492), YEND(274), _COLOR_BG_3);
#else

#if(_DEF_KEY_NAVIGATION)	//��������
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(57*12), YEND(_OSD_MAIN_MENU_HEIGHT*18), _OSD_BLACK_TYPE);
		OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(2*18+9), XEND(57*12), YEND((_OSD_MAIN_MENU_HEIGHT-1)*18-9), _COLOR_WINDOW_BG);
#elif(_DEF_OSD_LOGO)
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT+3)*18), _OSD_BLACK_TYPE);
#elif(_DEF_OSD_EDID_INFO)
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT+_DEF_OSD_EDID_INFO_NUMDATA)*18), _OSD_BLACK_TYPE);	//��ɫ
		OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(2*18+9), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT-1+_DEF_OSD_EDID_INFO_NUMDATA)*18-9), _COLOR_WINDOW_BG);
#else
		OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(0), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND(_OSD_MAIN_MENU_HEIGHT*18), _OSD_BLACK_TYPE);
		OsdWindowDrawing(_OSD_WINDOW_1, XSTART(0), YSTART(2*18+9), XEND(_OSD_MAIN_MENU_WIDTH*12), YEND((_OSD_MAIN_MENU_HEIGHT-1)*18-9), _COLOR_WINDOW_BG);
#endif
		OsdFontPut1BitTable(ROW(0), COL(0), tOSD_BOARD_UP_LEFT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

#if(_DEF_OSD_LOGO)	//�˵�LOGO
		OsdFontPut1BitTable(ROW(26), COL(0), tOSD_BOARD_DOWN_LEFT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);//������ĺ���

	
#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)
		OsdFontPut1BitTable(ROW(22), COL(iv_data+7), tOSD_OSD_LOGO0, COLOR(_CP_BG, _CP_BLUE_120), 0);
		OsdFontPut1BitTable(ROW(23), COL(iv_data), tOSD_OSD_LOGO1, COLOR(_CP_BG, _CP_BLUE_120), 0);

#elif(_DEF_OSD_LOGO == _OSD_LOGO_MUCAI)
		OsdFontPut1BitTable(ROW(23), COL(iv_data), tOSD_OSD_LOGO0, COLOR(_CP_BG, _CP_WHITE), 0);

#elif(_DEF_OSD_EDID_INFO)
		OsdFontPut1BitTable(ROW(_OSD_MAIN_MENU_HEIGHT-1+_DEF_OSD_EDID_INFO_NUMDATA), COL(0), tOSD_BOARD_DOWN_LEFT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);

#else
		OsdFontPut1BitTable(ROW(22), COL(iv_data), tOSD_OSD_LOGO0, COLOR(_CP_BG, _CP_BLUE_120), 0);
		OsdFontPut1BitTable(ROW(23), COL(iv_data), tOSD_OSD_LOGO1, COLOR(_CP_BG, _CP_BLUE_120), 0);


#endif

#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER)	//�˵�LOGO
		OsdFontPut1BitTable(ROW(24), COL(iv_data), tOSD_OSD_LOGO2, COLOR(_CP_BG, _CP_BLUE_120), 0);
#endif

#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER)	
		OsdFontPut2BitTable(ROW(23), COL(16),tOSD_OSD_LOGO3,COLOR0(_CP_WHITE),COLOR1(_CP_BG),COLOR2(_CP_GREEN),COLOR3(_CP_BG));
		RTDOsdFuncChangeColor1Bit(ROW(22), COL(5), WIDTH(17), HEIGHT(1), COLOR(_CP_BG, _CP_GREEN));
		//OsdWindowDrawingHighlight(_OSD_WINDOW_4_4,5,22,228,414,_CP_GREEN,_CP_GREEN,_CP_GREEN, _ENABLE); 
#elif(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)
		OsdFontPut2BitTable(ROW(22), COL(iv_data),tOSD_OSD_LOGO3,COLOR0(_CP_WHITE),COLOR1(_CP_BG),COLOR2(_CP_GREEN),COLOR3(_CP_BG));
		RTDOsdFuncChangeColor1Bit(ROW(22), COL(9), WIDTH(2), HEIGHT(1), COLOR(_CP_BG, _CP_GREEN));
#endif

#else
//�»���
//		OsdFontPut1BitTable(ROW(_OSD_MAIN_MENU_HEIGHT-1), COL(0), tOSD_BOARD_DOWN_LEFT, COLOR(_COLOR_MENU_FONT, _CP_BG), 0);
#endif

	for(i= 0; i<_HENG_COUNT; i++)
	{
		OsdFontPut1BitTable(ROW(_ITEM_1_ROW+1+i*2), COL(_ITEM_1_COL), tOSD_HENGXIAN, COLOR(_CP_WHITE, _CP_BG), 0);
		OsdFontPut1BitTable(ROW(_ITEM_1_ROW+1+i*2), COL(_ITEM_1_COL+18), tOSD_HENGXIAN, COLOR(_CP_WHITE, _CP_BG), 0);
		OsdFontPut1BitTable(ROW(_ITEM_1_ROW+1+i*2), COL(_ITEM_1_COL+36), tOSD_HENGXIAN, COLOR(_CP_WHITE, _CP_BG), 0);
	}

	for(i= 0; i<_HENG_COUNT-1+GET_OSD_FACTORY_MODE(); i++)
		RTDOsdTableFuncPutStringProp(ROW(_ITEM_1_ROW+i*2), COL(_ITEM_1_COL), _PFONT_PAGE_0, _OSD_STRING_TITLE, i, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());

#endif	
	}

	if(GET_OSD_STATE_PREVIOUS() == _MENU_FUN_LANGUAGE)
	{
		UpdateOSDMainInterface(_OSD_MAIN_OTHER);   //hh
		if(GET_OSD_STATE_PREVIOUS() == _MENU_FUN_LANGUAGE)
		{
			OSD_SubMenuCur = 0;	//锟斤拷一锟斤拷
		}
		SET_OSD_STATE((_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur));
		OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(OSD_SubMenuCur))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
		OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_2_COL*12-10,((_ITEM_1_ROW+2*(OSD_SubMenuCur)))*18-9, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18+7, _COLOR_WINDOW_BG);	
	}
	else if(GET_OSD_STATE_PREVIOUS() == _MENU_FUN_OSD_RORATE)
	{
		UpdateOSDMainInterface(_OSD_MAIN_OSD);   //hh
		if(GET_OSD_STATE_PREVIOUS() == _MENU_FUN_OSD_RORATE)
		{
			OSD_SubMenuCur = 4;	//锟斤拷6锟斤拷
		}
		SET_OSD_STATE((_MENU_PICTURE_TATE0+(OSD_MAIN_MENU_ITEM)*_OSD_NUM_DATA+OSD_SubMenuCur));
		OsdWindowDrawingHighlight(_OSD_WINDOW_4_8,_ITEM_2_COL*12,(_ITEM_1_ROW+2*(OSD_SubMenuCur))*18, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18, _COLOR_WINDOW_BG, _COLOR_MENU_FONT_SELECT, _CP_BG, _ENABLE);	
		OsdWindowDrawing(_OSD_WINDOW_8,_ITEM_2_COL*12-10,((_ITEM_1_ROW+2*(OSD_SubMenuCur)))*18-9, (_ITEM_2_COL+_ITEM_COL_LENGTH)*12-2, ((_ITEM_1_ROW+2*(OSD_SubMenuCur))+1)*18+7, _COLOR_WINDOW_BG);	
	}
	else
		UpdateOSDMainInterface(_OSD_MAIN_SOURCE);

#if((_FREESYNC_SUPPORT == _ON)&&(_OSD_VFREQ_CHANGE == _ON))

		if(ScalerSyncGetFREESYNCEnable() == _TRUE)
		{
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_DRR_VFREQ);
		}
	
		BackUpTempVFreq = 0;
	

      OsdDisplayVfreq();

#endif
//#ifndef _ITALIAN_SUPPORT
//	if((GET_OSD_LANGUAGE()==_ITALIAN))
//	{
//		RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//	}	else
//#endif
//	#if _RUSSIAN_SUPPORT
//	 if(GET_OSD_LANGUAGE()==_RUSSIAN)
//		RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//	else
//	#endif
//	#if _FINNISH_SUPPORT
//	 if(GET_OSD_LANGUAGE()==_FINNISH)
//		RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+6), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), GET_OSD_LANGUAGE());
//		else
//	#endif
#if _CHINESE_S_SUPPORT
        if(GET_OSD_LANGUAGE()==_CHINESE_S)
        {
            RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8),COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, GET_OSD_LANGUAGE());
            RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
        }   else
#endif
#if _CHINESE_F_SUPPORT
         if(GET_OSD_LANGUAGE()==_CHINESE_F)
             {
             RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
             RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+8),COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, GET_OSD_LANGUAGE());
            }
         else
#endif
#if _JAPANESE_SUPPORT
         if(GET_OSD_LANGUAGE()==_JAPANESE)
             {
             RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+14), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
             RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+9),COL(_OSD_MAIN_MENU_WIDTH/2+16), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, GET_OSD_LANGUAGE());
            }
         else
#endif

        {
        	RTDOsdTableFuncPutStringCenter(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+9),COL(_OSD_MAIN_MENU_WIDTH/2+16), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION1, 0, COLOR(_COLOR_MENU_FONT,_CP_BG),0, 0);
            RTDOsdTableFuncPutStringProp(ROW(1), COL(_OSD_MAIN_MENU_WIDTH/2+16), _PFONT_PAGE_0, _OSD_STRING_NOW_RESOLUTION, 0, COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
        }
#if(_SOURCE_AUTO_ON)	//���Ͻ��ź���ʾ
	if(GET_OSD_INPUT_PORT_OSD_ITEM() == _OSD_INPUT_AUTO)
	{
		RTDOsdTableFuncPutStringProp(ROW(1), COL(1),_PFONT_PAGE_0, _MENU_FUN_SIGNAL,OsdSignalMessageData(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);
	}
	else
#endif
	{
		RTDOsdTableFuncPutStringProp(ROW(1), COL(1),_PFONT_PAGE_0, _OSD_STRING_MODEL_VER, GET_OSD_INPUT_PORT_OSD_ITEM(),COLOR(_COLOR_MENU_FONT,_CP_BG), _ENGLISH);					 
	}

	#if(_DEF_KEY_NAVIGATION)	//��������

	OsdFontPut1BitTable(ROW(7), COL(55), tOSD_KEY_M, COLOR(_CP_RED, _CP_BG), 0);
	OsdFontPut1BitTable(ROW(9), COL(56), tOSD_KEY_E, COLOR(_CP_RED, _CP_BG), 0);
	OsdFontPut1BitTable(ROW(11), COL(56), tOSD_KEY_R, COLOR(_CP_RED, _CP_BG), 0);
	OsdFontPut1BitTable(ROW(13), COL(56), tOSD_KEY_L, COLOR(_CP_RED, _CP_BG), 0);
	OsdFontPut1BitTable(ROW(16), COL(55), tOSD_KEY_POWER, COLOR(_CP_RED, _CP_BG), 0);

	#endif
#if(_DEF_OSD_EDID_INFO)
    OsdTextEDIDInfo();
#endif

	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, GET_OSD_HPOS(), 100 - GET_OSD_VPOS());

    // Osd Enable
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();
}
//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
WORD DetOverRangeForHotkeySelect(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
{

	bCycle = bCycle;
if( _MENU_FUN_BACKLIGHT<=GET_OSD_STATE() && GET_OSD_STATE()< _MENU_END)
{
    switch(GET_KEYMESSAGE())
    {
        case _RIGHT_KEY_MESSAGE:
			do{
			    if(usValue >= usMax)
			    {
		            usValue = usMin;
			    }
			    else
			    {
			        usValue++;
			    }
			}while((usValue == (_MENU_NULL - _MENU_FUN_BACKLIGHT))?1:(((_MENU_NULL - _MENU_FUN_BACKLIGHT) < usValue)?0: OSD_ITEM_MASK_GET(usValue+_MENU_FUN_BACKLIGHT)));
			
			
            break;

        case _LEFT_KEY_MESSAGE:
			
			do{
			    if (usValue <= usMin)
			    {
		            usValue = usMax;
			    }
			    else
			    {
			        usValue--;
			    }			
			}while((usValue == (_MENU_NULL - _MENU_FUN_BACKLIGHT))?1:(((_MENU_NULL - _MENU_FUN_BACKLIGHT) < usValue)?0: OSD_ITEM_MASK_GET(usValue+_MENU_FUN_BACKLIGHT)));
			
				
		    break;

        default:
            break;
    }
}
    return usValue;
}

//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
WORD OsdDisplayDetOverRangeRotation(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
{
if( _MENU_FUN_BACKLIGHT<=GET_OSD_STATE() && GET_OSD_STATE()< _MENU_END)
{
    switch(GET_KEYMESSAGE())
    {
        case _LEFT_KEY_MESSAGE:
            if(usValue >= usMax)
            {
                if(bCycle == _ON)
                {
                    return usMin;
                }
                else
                {
                    return usMax;
                }
            }
            else
            {
                usValue++;
            }

            break;

        case _RIGHT_KEY_MESSAGE :
            if (usValue <= usMin)
            {
                if(bCycle == _ON)
                {
                    return usMax;
                }
                else
                {
                    return usMin;
                }
            }
            else
            {
                usValue--;
            }
            break;

        default:
            break;
    }
}
    return usValue;
}

//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
{
if( _MENU_FUN_BACKLIGHT<=GET_OSD_STATE() && GET_OSD_STATE()< _MENU_END)
{
    switch(GET_KEYMESSAGE())
    {
        case _RIGHT_KEY_MESSAGE:
            if(usValue >= usMax)
            {
                if(bCycle == _ON)
                {
                    return usMin;
                }
                else
                {
                    return usMax;
                }
            }
            else
            {
                usValue++;
            }

            break;

        case _LEFT_KEY_MESSAGE:
            if (usValue <= usMin)
            {
                if(bCycle == _ON)
                {
                    return usMax;
                }
                else
                {
                    return usMin;
                }
            }
            else
            {
                usValue--;
            }
            break;

        default:
            break;
    }
}
    return usValue;
}

/*
WORD OsdDisplayDetOverRangeReverse(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
{
if( _MENU_FUN_BACKLIGHT<=GET_OSD_STATE() && GET_OSD_STATE()< _MENU_END)
{
    switch(GET_KEYMESSAGE())
    {
        case _LEFT_KEY_MESSAGE:
            if(usValue >= usMax)
            {
                if(bCycle == _ON)
                {
                    return usMin;
                }
                else
                {
                    return usMax;
                }
            }
            else
            {
                usValue++;
            }

            break;

        case _RIGHT_KEY_MESSAGE:
            if (usValue <= usMin)
            {
                if(bCycle == _ON)
                {
                    return usMax;
                }
                else
                {
                    return usMin;
                }
            }
            else
            {
                usValue--;
            }
            break;

        default:
            break;
    }
}
    return usValue;
}
*/

//--------------------------------------------------
// Description  : Six Color Get One Color
// Input Value  : SixColor
// Output Value : None
//--------------------------------------------------

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispAutoConfigProc(void)
{
    OsdDispOsdMessage(_OSD_DISP_AUTO_CONFIG_MSG);
    UserCommonAutoConfig();
    OsdDispDisableOsd();
}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDisplayAutoBalanceProc(void)
{
    OsdDispDisableOsd();
    OsdDispOsdMessage(_OSD_DISP_AUTO_COLOR_MSG);

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
        {
            // Perform auto-color for RGB
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA))
                // Calculate YPbPr gain/offset using formula
                g_stAdcData = ScalerAutoBalanceYPbPrFromFormula(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);

                // Restore RGB gain/offset
                ScalerAutoGetAutoColorResult(&g_stAdcData);
#endif
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
        else
        {
            // Perform auto-color for YPbPr
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_YPBPR) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#endif
    }

    OsdDispDisableOsd();
    // SET_KEYMESSAGE(_HOLD_KEY_MESSAGE);
}
#endif // End of #if(_VGA_SUPPORT == _ON)

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispOsdReset(void)
{
    BYTE ucIndex = GET_OSD_LANGUAGE();
	BYTE TEMP_LEFT = GET_OSD_HOTKEY_LEFT();
	BYTE TEMP_RIGHT = GET_OSD_HOTKEY_RIGHT();
	BYTE ucShowLogoFlag = GET_OSD_LOGO();

#if(_DEF_SCREEN_SWITCHING)	//�л�����������
	UserCommonInterfacePanelPowerAction(_PANEL_OFF);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWDDomainEnable(_FUNCTION_OFF);
#endif

    OsdDispDisableOsd();

    UserCommonNVRamRestoreSystemData();
    RTDNVRamRestoreOSDData();

    RTDNVRamRestoreUserColorSetting();
	UserAdjustGamma(GET_OSD_GAMMA());
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    RTDNVRamRestoreSixColorData();

    RTDNVRamRestoreBriCon();
    RTDNVRamRestoreBacklight();

#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        SET_VGA_MODE_DO_FIRST_AUTO(_TRUE);
        UserCommonModeSearchInitalUserAndCenterData(g_stVGAModeUserData.ucModeNumber);
        UserCommonNVRamSaveModeUserData();
    }
#endif

#if(_DP_SUPPORT == _ON)
    // Set Aux Diff mode & Resistance Setting
    SET_DP_AUX_DIFF_MODE();

    SET_DP_AUX_ADJR_SETTING(UserCommonNVRamGetSystemData(_DP_AUX_ADJR_SETTING));

    UserCommonInterfaceDpAuxSet();
#endif
      
#if(_RESET_KEEP_LANGUAGE)
    if(ucIndex != GET_OSD_LANGUAGE())
    {
        SET_OSD_LANGUAGE(ucIndex);
        RTDNVRamSaveOSDData();
    }
#endif 
	SET_OSD_HOTKEY_LEFT(TEMP_LEFT);
	SET_OSD_HOTKEY_RIGHT(TEMP_RIGHT);
	SET_OSD_LOGO(ucShowLogoFlag);
	SET_OSD_FACTORY_MODE(_OFF);
	SET_OSD_BURNING_MODE(_OFF);
	
	RTDNVRamSaveOSDData();

#if(_DCR_SUPPORT)
#if(_DEF_OPPOSITE_DCR)	//_MENU_FUN_DCR_OPPOSITE
	if(GET_OSD_DCR_OPPOSITE()||GET_OSD_DCR_STATUS())
	{
		UserAdjustDCRControl(_ON);
	}
	else
	{
		UserAdjustDCRControl(_OFF);
	}
#else
	UserAdjustDCRControl(GET_OSD_DCR_STATUS());
#endif

#endif


#if(_FREESYNC_SUPPORT == _ON)
		UserCommonInterfaceFreeSyncSupportSwitch();
#endif	

    OsdFuncSetOsdItemFlag();

    // Set Backlight OFF to prevent garbage
    #if(_PANEL_TYPE==_AUO_M270HVR01_0_LVDS_FHD_144)
    UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
   #endif
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN_MSG); 
	if(GET_OSD_AUTO_POWEROFF()!=0)
	{	
		g_usPowerDownCount = GET_OSD_AUTO_POWEROFF() * 60;
		ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_AUTO_POWER_DOWN);
	}
    SET_OSD_STATE(_MENU_NONE);

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    UserCommonInterfaceDataExchangeAllDataReset();
#endif

#if(_SIX_COLOR_SUPPORT == _ON && _DEF_STA_SIX_COLOR)
	//if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER)
		ScalerColorICMEnable(_FUNCTION_ON);//�޸���ɫ����ʧЧ
		for(ucIndex = 0; ucIndex < 6; ucIndex++)
		{
			SET_OSD_SIX_COLOR(ucIndex);
			OsdDisplaySixColorGetOneColor(ucIndex);
			ScalerColorSixColorAdjust(ucIndex, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
		}
		//ScalerColorSixColorInitial();
#endif


#if(_LED_EFFECT_TJMODE14==_ON)
	led_start =1;
	ScalerTimerDelayXms(30);



#endif



#if(_DEF_RESET_SOURCE_AUTO)	//�źŻ�ԭ���Զ�
	if(GET_OSD_INPUT_PORT_OSD_ITEM())
	{
		SET_OSD_INPUT_PORT_OSD_ITEM(0);
		SET_FORCE_POW_SAV_STATUS(_FALSE);
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
		SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP); //�Զ������ź�
		if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
		{
			UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
		}
		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	}
#endif
ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);

}

//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_LOGO_TYPE != _NONE_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    OsdFuncDisableOsd();
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerDDomainBackgroundSetColor(_LOGO_BG_RED, _LOGO_BG_GREEN, _LOGO_BG_BLUE);
    ScalerDDomainBackgroundEnable(_ENABLE);
	
    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);
	
    OsdFuncApplyMap(WIDTH(_LOGO_COL_SIZE), HEIGHT(_LOGO_ROW_SIZE), COLOR(_LOGO_CP_BG, _LOGO_CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, _LOGO_ROW_SIZE, _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
	
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);
	
#if(_LOGO_TYPE == _LOGO_ARZOPA_4BIT)
        OsdFuncSet4BitIconOffset(0xA0/4);
    
#endif

#if(_LOGO_TYPE != _NONE_LOGO)

	#if(_LOGO_TYPE == _LOGO_TIEMU)
		OsdFontPut4BitTable(0,0,tiOSD_1BIT_LOGO0);
    #elif(_LOGO_TYPE == _LOGO_ARZOPA_4BIT)
        OsdFontPut1BitTable_LOGO(ROW(0), COL(0), tiOSD_1BIT_LOGO0, COLOR(_LOGO_FG_COLOR, _LOGO_BG_COLOR), 0);
        OsdFontPut4BitTable(0,33,tiOSD_1BIT_LOGO1);
	#else
	    OsdFontPut1BitTable_LOGO(ROW(0), COL(0), tiOSD_1BIT_LOGO0, COLOR(_LOGO_FG_COLOR, _LOGO_BG_COLOR), 0);
	#endif
	
	#if(0xf000 <= _LOGO_TYPE&&(_LOGO_TYPE != _LOGO_ARZOPA_4BIT))
	OsdFontPut1BitTable_LOGO(ROW(_LOGO_ROW_START1), COL(_LOGO_COL_START1), tiOSD_1BIT_LOGO1, COLOR(_LOGO_FG_COLOR1, _LOGO_BG_COLOR1) , 1);
	#endif

#endif

#if(_LOGO_TYPE == _BIG_ELECTRIQ_LOGO)
	OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, 56*12, 0, (56+19)*12, 11*18, _CP_WHITE, _CP_WHITE, _LOGO_CP_GREEN_1, _ENABLE); 
#elif(_LOGO_TYPE == _ZORO_LOGO)
	OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, 0*12, 0, (20)*12, 13*18, _CP_WHITE, _LOGO_CP_DARKBLUE , _CP_WHITE, _ENABLE);
#elif(_LOGO_TYPE == _LOGO_MUCAI)
   ScalerOsdChange1BitColor(ROW(12), COL(0), LENGTH(14), HEIGHT(2), FG_COLOR(_LOGO_CP_RED), BG_COLOR(_LOGO_BG_COLOR));
   ScalerOsdChange1BitColor(ROW(12), COL(14), LENGTH(15), HEIGHT(2), FG_COLOR(_LOGO_CP_BLUE), BG_COLOR(_LOGO_BG_COLOR));
   ScalerOsdChange1BitColor(ROW(12), COL(29), LENGTH(14), HEIGHT(2), FG_COLOR(_LOGO_CP_GREEN), BG_COLOR(_LOGO_BG_COLOR));
#elif(_LOGO_TYPE == _LOGO_FUEGO)
       ScalerOsdChange1BitColor(ROW(0), COL(0), LENGTH(29), HEIGHT(27), FG_COLOR(_CP_YELLOW), BG_COLOR(_CP_BG ));

#elif (_LOGO_TYPE == _LOGO_GUANJIE)
    OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, 0, 0, (50)*12, (18)*18, _CP_WHITE, _CP_WHITE, _LOGO_CP_RED, _ENABLE);    
#elif (_LOGO_TYPE == _LOGO_XGAMING)
//    OsdWindowDrawingHighlight(_OSD_WINDOW_4_8, 0, 0, (50)*12, (18)*18, _CP_WHITE, _CP_WHITE, _LOGO_CP_RED, _ENABLE);    
#elif (_LOGO_TYPE == _LOGO_ARZOPA)
    ScalerOsdChange1BitColor(ROW(0), COL(33), LENGTH(20), HEIGHT(11), FG_COLOR(_LOGO_CP_BLUE_1), BG_COLOR(_LOGO_CP_WHITE));

#elif (_LOGO_TYPE == _LOGO_WMX)
    ScalerOsdChange1BitColor(ROW(0), COL(29), LENGTH(25), HEIGHT(5), FG_COLOR(_LOGO_CP_RED), BG_COLOR(_LOGO_CP_BG));
#elif (_LOGO_TYPE == _LOGO_ENVISION)
    ScalerOsdChange1BitColor(ROW(0), COL(34), LENGTH(8), HEIGHT(5), FG_COLOR(_LOGO_CP_RED), BG_COLOR(_LOGO_CP_BG));


#elif(_LOGO_TYPE == _LOGO_ARZOPA_4BIT)

    //ScalerOsdChange4BitColor(ROW(0), COL(33), LENGTH(16), HEIGHT(10), BGCOLOR(0), (_OSD_4BIT_PALETTE_00_01_02_03 | _OSD_4BIT_PALETTE_04_05_06_07 | _OSD_4BIT_PALETTE_08_09_10_11 | _OSD_4BIT_PALETTE_12_13_14_15));
	ScalerOsdChange4BitColor(ROW(0), COL(33), LENGTH(16), HEIGHT(10), BGCOLOR(0), (_OSD_4BIT_PALETTE_16_17_18_19 | _OSD_4BIT_PALETTE_20_21_22_23 | _OSD_4BIT_PALETTE_24_25_26_27 | _OSD_4BIT_PALETTE_28_29_30_31));
	ScalerOsdChange4BitColor(ROW(5), COL(33), LENGTH(16), HEIGHT(5), BGCOLOR(0), (_OSD_4BIT_PALETTE_32_33_34_35 | _OSD_4BIT_PALETTE_36_37_38_39 | _OSD_4BIT_PALETTE_40_41_42_43 | _OSD_4BIT_PALETTE_44_45_46_47));

#endif


OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _LOGO_POS_H, _LOGO_POS_V);
//    OsdFuncEnableOsd();

    SET_OSD_LOGO_ON(_ON);
}

#endif
int SwapRotateValue(int value)
{
#if(Project_ID == ID_TJZG_TMDTMD2822_HK2775E01_2P2H_UHD60HZ_20231217)||\
        (Project_ID == ID_TJZG_HK2775E05_M270KCAD8B_EDP4LANHBR2_MD2769_QHD180HZ_20240313)||\
    (Project_ID == ID_TJZG_HK2775E05_SN245ES01_2_EDP4LANHBR2_MD2569_QHD180HZ_20240528)||\
        (Project_ID == ID_TJZG_HK2775E01_SG2451B014_VBY8LANHBR2_FHD240HZ_20240330)||\
        (Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_20240426)||\
        (Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_QHD180HZ_G27L61QK_20240509)||\
        (Project_ID == ID_TJZG_HK2775E01_SN270ES011_EDP4LANHBR2_F2761QK_QHD180HZ_20240416)
               if(value==_OSD_ROTATE_DEGREE_270)
                value = _OSD_ROTATE_DEGREE_90;
               else if(value==_OSD_ROTATE_DEGREE_90)
                value = _OSD_ROTATE_DEGREE_270;
             
#endif
        return value;
}

#if(_DEF_STA_SIX_COLOR)
void OsdDisplaySixColorGetOneColor(BYTE ucColor)
{
    switch(ucColor)
    {
        case _SIXCOLOR_R:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueR);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationR);
            break;

        case _SIXCOLOR_Y:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueY);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationY);
            break;

        case _SIXCOLOR_G:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueG);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationG);
            break;

        case _SIXCOLOR_C:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueC);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationC);
            break;

        case _SIXCOLOR_B:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueB);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationB);
            break;

        case _SIXCOLOR_M:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueM);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationM);
            break;

        default:
            break;
    }
}




#endif//(_DEF_STA_SIX_COLOR)


#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
