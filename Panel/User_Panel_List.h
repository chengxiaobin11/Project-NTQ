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
// ID Code      : User_Panel_List.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Panel Type List
//--------------------------------------------------

//d8b
#define _PANEL_LVDS_EXAMPLE                     0xFFFF
#define _PANEL_DPTX_EXAMPLE                     0xFFFF
#define _PANEL_VBO_EXAMPLE                      0xFFFF
#define _PANEL_TTL_EXAMPLE                      0xFFFF

#define _MULTIPANEL_LVDS_21_5_WUXGA             1
#define _CMO_LVDS_17                            2    // 1280 x 1024
#define _CMO_LVDS_19_WXGA                       3    // 1440 x  900
#define _AU_LVDS_22_WSXGA                       4    // 1680 x 1050
#define _AU_LVDS_22_WSXGA_QC                    5    // 1680 x 1050
#define _AU_LVDS_21_5_WUXGA                     6    // 1920 x 1080
#define _AU_LVDS_21_5_WUXGA_FREESYNC            7    // 1920 x 1080
#define _AU_LVDS_23_WUXGA                       8    // 1920 x 1200
#define _AU_LVDS_24_WUXGA                       9    // 1920 x 1080
#define _AU_LVDS_27_WUXGA_FREESYNC              10    // 1920 x 1080
#define _LG_LED_LVDS_27_WUXGA                   11    // 2560 x 1440
#define _LG_LED_LVDS_23_UHD                     12    // 3840 x 2160

#define _MULTIPANEL_DP_21_5_WUXGA               13
#define _AU_DP_21_5_WUXGA                       14    // 1920 x 1080
#define _AU_DP_21_5_WUXGA_FREESYNC              15    // 1920 x 1080
#define _LG_LED_DP_34_WFHD                      16    // 2560 x 1080
#define _LG_LED_DP_17_QHD                       17    // 2560 x 1440
#define _LG_LED_DP_27_QHD                       18    // 2560 x 1440
#define _LG_LED_DP_27_QHD_QC                    19    // 2560 x 1440
#define _SAMSUNG_LED_DP_15_6_UHD                20    // 3840 x 2160
#define _SAMSUNG_LED_DP_23_6_UHD                21    // 3840 x 2160
#define _LG_LED_DP_27_UHD                       22    // 3840 x 2160
#define _AUO_LED_DP_32_UHD                      23    // 3840 x 2160
#define _LG_LED_DP_27_QQHD                      24    // 5120 x 2880
#define _AUO_EDP_27_UHD_LOCAL_DIMMING           25    // 3840 x 2160

#define _AUO_VBO_27_WUXGA_FREESYNC              26    // 1920 x 1080
#define _INNOLUX_LED_VBO_28_UHD                 27    // 3840 x 2160
#define _INNOLUX_LED_VBO_40_UHD                 28    // 3840 x 2160
#define _INNOLUX_TTL_7                          29    // 800 x  480

/*************************User Define*************************************/
//�������ֵ����������ֶ�Ӧ��������� ����: 32_AUO_M270QAN010_EDP_UHD_60HZ.h
//panel ��������:��������->����->�ӿ�����->�ֱ���
//SG3151

#define  _AUO_M270QAN010_EDP_UHD_60HZ           32   // 3840 x  2160
#define  _LG_LM270WR2_EDP_UHD_60HZ          	33   // 3840 x  2160
#define  _LG_LM270WQ4_SSA1_LVDS_QHD_60HZ        34   // 2560 x  1440
#define  _INL_M236HJJP02_LVDS_FHD_60HZ          35   //1920 x 1080
#define  _AUO_M270DAN02V0_LVDS_QHD_60HZ  		36  // 2560 x  1440
#define  _AUO_M238DAN013_LVDS_QHD_60HZ          37  // 2560 X 1440
#define  _AUO_T320HVN05A_LVDS_FHD_144HZ         38  //1920x1080
#define  _INL_M238DCJ_E50_eDP_UHD				39   //3840x2160
#define  _SAMSUNG_LSM315HP01_VB1_FHD_144        40	//1920x1080
#define  _AUO_M270DAN010_LVDS_QHD_60HZ          41	//2560x1440
#define _AUO_M250HTN011_LVDS_FHD_60HZ           42	//1920x1080
#define _AUO_M195RTN01_0_LVDS_60HZ              43	//1600x900
#define _AUO_T215HVN05_1_LVDS_60HZ              44	//1920x1080
#define _AUO_M238FHB_N40_LVDS_60HZ              45	//1920x1080
#define _CSOT_ST2151B01_1_LVDS_60HZ             46	//1920x1080
#define _AUO_M270DTR01_0_EDP_165HZ              47	//2560x1440@165
#define _AUO_M315DVR01_0_EDP_165HZ              48	//2560x1440
#define _SAMSUNG_LSM270DP01_0_EDP2_144HZ        49	//2560x1440
#define _SAMSUNG_LSM236HP02_G02_165HZ           50	//1920x1080@165
#define _AUO_P320HVN05_0_144HZ                  51	//1920x1080@165
#define _AUO_M250HTN01_LVDS_60HZ                52	//1920x1080
#define _AUO_M250HTN01_6_VBY_144HZ              53	//1920x1080@165
#define _AUO_M250HTN01_0_VBY_240HZ              54	//1920x1080@240
#define _AUO_M270HTN02_0_VBY_240HZ              55	//1920x1080@240
#define _LG_LM230WF9_SSA3_LVDS_60HZ             56	//1920x1080@60
#define _AUO_M270HTN02_5_LVDS_60HZ               57	//1920x1080@60
#define _LG_LM238WF4_SSB1_LVDS_FHD_60HZ         58	//1920x1080@60
#define _AUO_M315DVR01_9_EDP_165HZ              59	//2560x1440  @165
#define _AUO_LC185TT7A_LVDS_60HZ                60	//1366x768
#define _BOE_HV320QHM_C80_LVDS_75HZ              61	//2560X1440@75
#define _CSOT_SG3151B02_1_LVDS_144HZ              62	//1920X1080@144
#define _INL_M280DGJ_L30_LVDS_FHD_60HZ              63	//1920X1080@60
#define _BOE_MV238FHB_N40_LVDS_FHD_60HZ              64	//1920X1080@60
#define _BOE_MV230FHM_N30__LVDS_FHD_60HZ              65	//1920X1080@60
#define _CSOT_ST2151B03_1_LVDS_60HZ            66	//1920x1080@60
#define _AUO_M320QAN01_0_EDP_60HZ            67	//3840X2160@60
#define _INL_M280DGJ_L30_VBY_UHD_60HZ              68	//3840X2160@60
#define _SAMSUNG_LSM270HP06_LVDS        69	//1920x1080@165
#define _PANDA_LC238LF1L_LVDS        70	//1920x1080@75
#define _SAMSUNG_LSM315DP01_EDP        71	//2560x1440@144
#define _AUO_M238HVN010_LVDS             72	//1920x1080@75
#define _SAMSUNG_LSM315DP06_EDP        73	//2560x1440@165
#define _AUO_M270KCJ_K7B_VBY_QHD        74	//2560x1440@165
#define _INNOLUX_M270KCJ_L5B_LVDS_QHD				75	// 2560 x 1440@75
#define _AUO_M300DVR01V0_VBY_QHD				76	// 2560 x 1080@200
#define _AUO_M270HVR01_LVDS_FHD				77	// 1920 x 1080@75
#define _BOE_MV270QUM_N10_EDP_UHD				78	// 3840x2160@60
#define _BOE_HV320FHB_N00_LVDS_FHD				79	// 1920X1080@60
#define _AUO_M270DTN01_V8_EDP_165HZ              80	//2560x1440@165
#define _BOE_MV270QUM_N20_EDP_UHD				81	// 3840x2160@60
#define _AUO_M270QAN021_EDP_UHD_60HZ           82   // 3840 x  2160@60
#define _LHCX_2380_FHD_75_LVDS             83	//1920x1080@75
#define _LHCX_295_QHD_75_LVDS             84	//2560X1080@75	//WFHD
#define _LHCX_315_FHD_144HZ_LVDS             85	//1920x1080@144
#define _LHCX_35_UHD_100HZ_EDP             86	//3440X1440
#define _CSOT_SG2701B01_3_165HZ              87	//1920X1080@165
#define _BOE_MV315QHB_N10_LVDS_75HZ              88	//2560X1440@75
#define _INN_M315DJJ_Q01_VBY1_60HZ              89	//3840x2160@60
#define _CSOT_SG3151B05_6_VBY1_240HZ          90    // 800 x  480
#define _AUO_M270HAN02_2_165HZ              91	//1920X1080@165
#define _HSMB270_1QAN02_UHD60HZ              92	//3840*2160
#define _LG_LM270WQA_SSA1_EDP_QHD              93	//3840*2160
#define _LC270LF1F_LVDS_FHD144             		94	//1920x1080@144
#define _M315DJJ_VBO_UHD60              		95	//3840*2160
#define _BOE_MV270QHB_N50_LVDS_75H              96	//3840*2160
#define _CSOT_SG2701G01_1_EDP_QHD               97    // 2560X1440@165
#define _HKC_PN238CT02_14_LVDS_FHD75            98    // FHD@75
#define _PANDA_LC238LF1F_LVDS       			99	//1920x1080@165
#define _INX_M280DCA_P3B_EDP_HBR2_UHD60         100//3840*2160
#define _AUO_M315DVR012_EPD_HBR1_QHD75          101
#define _AUO_M270HVR01_LVDS_FHD165              102
#define _AUO_M315HVR01_LVDS_FHD165          103
#define _AUO_M270HVR01_0_LVDS_FHD_144       104
#define _AUO_M270HAN02_6_LVDS_FHD165HZ		105
#define _AUO_M350QVR010_EDP_WQHD100HZ 			106	//3440x1440@100
#define _BOE_MV238FHM_NG2_EDP_FHD280HZ			107
#define _LG_LM270WF9_SSA1_EDP_HBR2_FHD280HZ		108	//1920x1080@280
#define _BOE_MV270QHM_NF2_EDP_HBR2_QHD165HZ		109// 2560X1440@165
#define _BOE_MV290VUB_NX0_LVDS_WFHD100HZ       	110	//2560x1080@100
#define _BOE_MV238QHM_NF0_EDP_HBR2_QHD165HZ		111// 2560X1440@165  4Lan
#define _AUO_M270DAN07_2_LVDS_QHD75HZ			112
#define _BOE_MV315QHM_N40_LVDS_QHD75HZ			113	//2560x1440@75	//����
#define  _AUO_M270DAN09_1_EDP_4LANHBR_QHD75HZ  		115  // 2560 x  1440
#define _AUO_M315HVR01_7_4HBR2_FHD240       116
#define _HKC_PN270EU01_1_4LANHBR2_QHD165HZ               117    // 2560X1440@165
#define _M270KCAD8B_EDP_4LANEHBR2_QHD180HZ               118    // 2560X1440@180
#define _AUO_M340QVR01_1_EDP_WQHD_100HZ               119   // 
#define _AUO_SN270ES01_1_EDP_4LANEHBR2_QHD180HZ               120   // 2560X1440@180


#define _LG_LM270WQA_SSA1_EDP_QHD165HZ                       	128	//2560X1440@165
#define _BOE_SG2451BO1_4_VBO_FHD240HZ             				129//1920 x 1080@240
#define _SN245ES01_2_EDP_4LANEHBR2_QHD180HZ               130    // 2560X1440@180
#define _BOE_MV270FHM_NF1_EDP4LANEHBR2_FHD240HZ             	131//1920 x 1080@240
#define _CSOT_SG2701G03_3_4LAN_HBR2_QHD180HZ             	132//2560X1440@180





#define _PANDA_M270HCA_L7B_LVDS_FHD_165HZ						150 //1920x1080@165
#define _HKC_SN270CS03_1_V11_FHD180HZ						151 //1920x1080@165
#define _BOE_MV238QHB_NF0_EDP_HBR2_QHD165HZ						152 //2560x1440@165



#define _INN_M315KCA_E7B_EDP_HBR2_QHD165HZ						167	//2560x1440@165

#define _HKC_SN270GS03_1_UHD_60HZ_						168	///3440x1440@60


#define _ME270QHB_NM1_EDP_8LANEHBR_QHD180HZ               169    // 2560X1440@180


#define _ME270QHB_NF5_EDP_4LANEHBR2_QHD180HZ               170    // 2560X1440@180-----NF2-----NF5


#define _ME270QHB_NF0_EDP_8LANEHBR_QHD180HZ               171    // 2560X1440@180

#define _CSOT_SG2451B01_2_8LANVBY_FHD280HZ					172//1k280
//NTQ Project panel
#define _BOE_DV430QUB_C10_VBY_UHD_60HZ                      173	//3840X2160@60
#define _AUO_P490QAR010_VBY_UHD_60HZ                        174	//3840X2160@60
#define _AUO_P550QVR010_VBY_UHD_60HZ                        175 //3840X2160@60
#define _BOE_MV315QUM_N70_EDP_UHD_60HZ                      176 //3840X2160@60
#define _AUO_P430QVR010_VBY_UHD_60HZ                        177 //3840X2160@60
//--------------------------------------------------
// Panel Led Driver List (Can Not Be 0xFF)
//--------------------------------------------------
#define _DEVICE_LED_DRIVER_01_O2_OZ9913         0x01
#define _DEVICE_LED_DRIVER_02_AUSTRIA_AS3820    0x02
#define _DEVICE_LED_DRIVER_03_AUSTRIA_AS3824    0x03

