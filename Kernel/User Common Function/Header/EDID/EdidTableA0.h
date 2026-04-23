//--------------------------------------------------
// EDID Type Selection
//--------------------------------------------------
#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080) && (_PANEL_PRESET_MODE_FRAME_RATE == 600))
#define _A0_EDID_TYPE_SEL                               _HK_EDID_VGA_1920_1080_60HZ
#elif((_PANEL_DH_WIDTH == 1600) && (_PANEL_DV_HEIGHT == 900) && (_PANEL_PRESET_MODE_FRAME_RATE == 600))
#define _A0_EDID_TYPE_SEL                               _HK_EDID_VGA_1600_900_60HZ
#else
#define _A0_EDID_TYPE_SEL                               _HK_EDID_VGA_1920_1080_60HZ
#endif


//--------------------------------------------------
// EDID Table
//--------------------------------------------------
#if((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON) || ((_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)))

BYTE code tEDID_TABLE_A0[] =
{
#if(_A0_EDID_TYPE_SEL == _EDID_VGA_1920_1200_60HZ)
#include "./EDID/EdidVga/EDID_VGA_1920x1200@60.h"
#elif(_A0_EDID_TYPE_SEL == _HK_EDID_VGA_1920_1080_60HZ)
#include "./EDID/HK_EDID/HK_EDID_VGA_1920_1080_60HZ.h"
#elif(_A0_EDID_TYPE_SEL == _HK_EDID_VGA_1600_900_60HZ)
#include "./EDID/HK_EDID/HK_EDID_VGA_1600_900_60HZ.h"

#endif
};

#endif
