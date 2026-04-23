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
// ID Code      : RTD2014OsdPalette.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDPALETTE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)



//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _RGB_BLACK                                0,   0,   0
#define _RGB_WHITE                              255, 255, 255
#define _RGB_RED                                255,   0,   0
#define _RGB_GREEN                                0, 255,   0//19,  119,  19
#define _RGB_BLUE                                22,  14, 245// 65,   150, 210//0,    68, 166
#define _RGB_YELLOW                             255, 255,   0
#define _RGB_GRAY                               210,210,210//96,  96,   96

#if(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER) || (_DEF_OSD_LOGO == _DEF_OSD_LOGO_OVERPOWER)||(_DEF_OSD_LOGO == _DEF_OSD_LOGO_CROSSOVER2)
#define _RGB_BLUE_120                          255, 255, 255
#else
#define _RGB_BLUE_120                          0,   30,  120
#endif

#define _RGB_ORANGE                             255, 196,   0
#define _RGB_LIGHTBLUE                          170, 205, 235// 208, 208, 208
#define _RGB_DARKBLUE_1                            16, 16, 16
#define _RGB_DARKBLUE                            60,  90, 150
#define _RGB_GRAY0                                120,  120,  120

#define _RGB_SELECTBOTTOM                  60,  90, 150//58,  70,  80
#define _RGB_PINK                               255, 128, 255

#define _RGB_ORANGE_H                           250, 180,  40
#define _RGB_ORANGE_DARK                        224, 120,   7

#if 1//
#define _RGB_LIGHT_GRAY                           141, 141, 141
#else
#define _RGB_LIGHT_GRAY                           210, 210, 210
#endif


#define _LOGO_BLACK                             0,     0,   0
#define _LOGO_WHITE                             255, 255, 255

#define _LOGO_RED                               255,   0,   0
#define _LOGO_GREEN                             0,   255,   0
#define _LOGO_BLUE                              0,     0, 255
#if(_LOGO_TYPE == _LOGO_FUEGO)
#define _LOGO_YELLOW                           231, 49, 16
#else
#define _LOGO_YELLOW                            255, 255,   0
#endif
#if(_LOGO_TYPE == _LOGO_FUEGO)
#define _LOGO_GRAY                              36, 41, 38
#else
#define _LOGO_GRAY                              96,   96,  96
#endif
#define _LOGO_DARKBLUE                          64,   64, 255
#define _LOGO_LIGHTBLUE                         128, 128, 255
#define _LOGO_SELECTBOTTOM                      58,   70,  80
#define _LOGO_PINK                              255, 128, 255
#if(_LOGO_TYPE == _LOGO_SKY)
#define _LOGO_BLUE1								0,99,177
#elif(_LOGO_TYPE == _LOGO_AMOI_XIAXIN)
#define _LOGO_BLUE1								45,123,210
#elif(_LOGO_TYPE == _LOGO_MUCAI)
#define _LOGO_BLUE1								0,0,0
#elif(_LOGO_TYPE == _LOGO_CHUANSHENG)
#define _LOGO_BLUE1                             0,   0,  1
#elif(_LOGO_TYPE == _LOGO_GUANJIE)
#define _LOGO_BLUE1                             0,   0,  0
#elif(_LOGO_TYPE == _LOGO_XGAMING)
#define _LOGO_BLUE1                          235, 251, 251
#elif(_LOGO_TYPE == _LOGO_ARZOPA)
#define _LOGO_BLUE1                         0, 140, 196
#elif(_LOGO_TYPE == _LOGO_ASTEX)
#define _LOGO_BLUE1                         0, 140, 196
#elif(_LOGO_TYPE == _LOGO_GENLOVE)
#define _LOGO_BLUE1                             16,122,222 

#else
#define _LOGO_BLUE1								1,123,188
#endif
#define _LOGO_GREEN1                             92,191,20

#define _LOGO_ORANGE_H                          250, 180,  40
#if(_LOGO_TYPE == _LOGO_SUNWIND_QHD)
#define _LOGO_ORANGE_L                          243, 112,   32
#elif(_LOGO_TYPE == _LOGO_XGAMING)
#define _LOGO_ORANGE_L                           0, 160, 233
#else
#define _LOGO_ORANGE_L                          235, 160,   5
#endif



#if(_LOGO_TYPE == _LOGO_AMOI_XIAXIN)
#define _LOGO_BLUE_1                             0,0,255
#elif(_LOGO_TYPE == _LOGO_SOOANN)
#define _LOGO_BLUE_1								0,149,222
#else
#define _LOGO_BLUE_1                             10,     46, 140
#endif

#define _RGB_BLUE1            100,210,210
#define _RGB_LIGHTBLACK1       130,130,130

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_LOGO_TYPE == _LOGO_ARZOPA_4BIT)
BYTE code tPALETTE_RTD_LOGO[] =
{
    _LOGO_BLACK,
    _LOGO_WHITE,
    _LOGO_BLACK,
    _LOGO_BLACK,

	_LOGO_BLACK,
    _LOGO_BLACK,
    _LOGO_BLACK,
    _LOGO_BLACK,

	_LOGO_BLACK,
	_LOGO_BLACK,
	_LOGO_BLACK,
	_LOGO_BLACK,

	_LOGO_BLACK,
	_LOGO_BLACK,
	_LOGO_BLACK,
	_LOGO_BLACK,	// 15

	0,0,0,
	0,175,203,	// 5	//128,0,0,
	0,180,204,	// 4	//0,128,0,
	0,185,204,	// 3	//128,128,0,	// 3
	
	0,197,205,	// 2	//0,0,128,
	0,202,206,	// 1	//128,0,128,
	0,154,198,	// 7	//0,128,128,
	0,147,197,	// 8	//128,128,128,	// 7
	
	0,164,201,	// 6	//192,192,192,
	0,141,196,	// 9	//255,0,0,
	0,132,194,	// 10	//0,255,0,
	0,123,192,	// 11	//255,255,0,		// 11
	
	0,115,190,	// 12	//0,0,255,
	0,108,189,	// 13	//255,0,255,
	0,100,187,	// 14	//0,255,255,
	0,90,185,	// 15	//255,255,255,	// 15

	0,0,0,
	0,175,203,	// 5	//128,0,0,
	0,197,204,	// 4	//0,128,0,
	0,187,205,	// 3	//128,128,0,	// 3
	
	0,76,183,	// 17
	0,80,183,	// 16
	0,154,198,	// 7	//0,128,128,
	0,147,197,	// 8	//128,128,128,	// 7
	
	0,164,201,	// 6	//192,192,192,
	0,141,196,	// 9	//255,0,0,
	0,132,194,	// 10	//0,255,0,
	0,123,192,	// 11	//255,255,0,		// 11
	
	0,115,190,	// 12	//0,0,255,
	0,108,189,	// 13	//255,0,255,
	0,100,187,	// 14	//0,255,255,
	0,90,185,	// 15	//255,255,255,	// 15
    
};

#else
BYTE code tPALETTE_RTD_LOGO[] =
{
    _LOGO_BLACK,
    _LOGO_WHITE,
#if(_LOGO_TYPE == _LOGO_TIEMU)
	_RGB_BLUE1,
#else
	_LOGO_RED,
#endif
    _LOGO_GREEN,
    _LOGO_BLUE,
    _LOGO_YELLOW,
    _LOGO_GRAY,
    _LOGO_DARKBLUE,
    
    _LOGO_LIGHTBLUE,
    _LOGO_SELECTBOTTOM,
    _LOGO_PINK,
    _LOGO_RED,
    _LOGO_GREEN1,
    _LOGO_ORANGE_L,
    _RGB_LIGHTBLACK1,
    _LOGO_BLUE1,
};
#endif



BYTE code tPALETTE_MAIN_MENU[] =
{

		_RGB_BLACK,
		_RGB_WHITE,
		_RGB_RED,
		_RGB_GREEN,
		_RGB_BLUE,
		_RGB_YELLOW,
		_RGB_LIGHTBLUE,
		_RGB_DARKBLUE,
		_RGB_LIGHTBLUE,
		_RGB_GRAY0,
		_RGB_BLACK,
		_RGB_DARKBLUE_1,
//		_RGB_DARKBLUE,
		_RGB_BLUE,	
		_RGB_LIGHT_GRAY,
		_RGB_BLUE_120,
		_RGB_SELECTBOTTOM,    

};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdPaletteLoadPigment(BYTE ucPaletteIndex, BYTE *pucColorPaletteArray, BYTE ucColorPaletteCount);
void OsdPaletteSelectPalette(BYTE ucValue);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPaletteLoadPigment(BYTE ucPaletteIndex, BYTE *pucColorPaletteArray, BYTE ucColorPaletteCount)
{
    BYTE ucAddr = ucPaletteIndex * 16;
    BYTE ucI = 0;

    for(ucI = 0; ucI < ucColorPaletteCount; ucI++)
    {
        ScalerOsdSetColorPalette(ucAddr + ucI, *(pucColorPaletteArray + (ucI * 3)), *(pucColorPaletteArray + (ucI * 3) + 1), *(pucColorPaletteArray + (ucI * 3) + 2));
    }
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPaletteSelectPalette(BYTE ucValue)
{
    switch(ucValue)
    {
        case _PALETTE_RTD_LOGO:
            OsdPaletteLoadPigment(_PALETTE_INDEX0, tPALETTE_RTD_LOGO, sizeof(tPALETTE_RTD_LOGO)/3);
            break;

        case _PALETTE_MAIN_MENU:
            OsdPaletteLoadPigment(_PALETTE_INDEX0, tPALETTE_MAIN_MENU, 16);
            break;

        default:
            break;
    }
}

#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)
