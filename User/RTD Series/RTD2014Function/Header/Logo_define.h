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
// ID Code      : Logo_define.h No.0001
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_LOGO_TYPE == _REALTEK_LOGO)
	#define _LOGO_FG_COLOR                                      _LOGO_CP_BG
	#define _LOGO_BG_COLOR                                      _LOGO_CP_BLUE
	
	#define _LOGO_COL_SIZE										70
	#define _LOGO_ROW_SIZE										10


	#define _LOGO_ROW_START1 										0  //不是分2段载的logo不需要定义
	#define _LOGO_COL_START1 									    19 //不是分2段载的logo不需要定义

	#define _LOGO_BG_RED                                                       0
	#define _LOGO_BG_GREEN                                                   0
	#define _LOGO_BG_BLUE                                                     0     
#elif(_LOGO_TYPE == _MAG_LOGO)
	#define _LOGO_FG_COLOR                                      _LOGO_CP_BG
	#define _LOGO_BG_COLOR                                      _LOGO_CP_RED
	
	#define _LOGO_COL_SIZE										58
	#define _LOGO_ROW_SIZE										11

	#define _LOGO_BG_RED                                                       0
	#define _LOGO_BG_GREEN                                                   0
	#define _LOGO_BG_BLUE                                                     0     
#elif(_LOGO_TYPE == _TOPUSHENN)
	#define _LOGO_FG_COLOR                                      _LOGO_CP_WHITE
	#define _LOGO_BG_COLOR                                      _LOGO_CP_BG
	
	#define _LOGO_COL_SIZE										50
	#define _LOGO_ROW_SIZE										10

	#define _LOGO_BG_RED                                                       0
	#define _LOGO_BG_GREEN                                                   0
	#define _LOGO_BG_BLUE                                                     0                         
#elif(_LOGO_TYPE == _CHANGHONG_LOGO)
#define _LOGO_FG_COLOR									   _LOGO_CP_BLUE_1 
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
					
#define _LOGO_COL_SIZE										69
#define _LOGO_ROW_SIZE										8
				
#define _LOGO_BG_RED													   1
#define _LOGO_BG_GREEN													 123
#define _LOGO_BG_BLUE													  188

	
#elif(_LOGO_TYPE == _LOGO_CHIQ_FHD)
#define _LOGO_FG_COLOR									   _LOGO_CP_BLUE_1 
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
							
#define _LOGO_COL_SIZE										40
#define _LOGO_ROW_SIZE										8
						
#define _LOGO_BG_RED													   1
#define _LOGO_BG_GREEN													 123
#define _LOGO_BG_BLUE	                                                 188

#elif(_LOGO_TYPE == _LOGO_RECO_FHD)
#define _LOGO_FG_COLOR									   _LOGO_CP_WHITE
#define _LOGO_BG_COLOR										_LOGO_CP_BLUE//_LOGO_CP_WHITE
							
#define _LOGO_COL_SIZE										59
#define _LOGO_ROW_SIZE										10
						
#define _LOGO_BG_RED													 255
#define _LOGO_BG_GREEN													 255
#define _LOGO_BG_BLUE	                                                 255

#elif(_LOGO_TYPE ==_LOGO_CHIQ_QHD)
#define _LOGO_FG_COLOR									   _LOGO_CP_BLUE_1 
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
							
#define _LOGO_COL_SIZE										57
#define _LOGO_ROW_SIZE										11
						
#define _LOGO_BG_RED													   1
#define _LOGO_BG_GREEN													 123
#define _LOGO_BG_BLUE	                                                 188

#elif(_LOGO_TYPE ==_LOGO_SUNWIND_QHD)
#define _LOGO_FG_COLOR									   _LOGO_CP_ORANGE_L 
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
							
#define _LOGO_COL_SIZE										77
#define _LOGO_ROW_SIZE										8
						
#define _LOGO_BG_RED													 243
#define _LOGO_BG_GREEN													 112
#define _LOGO_BG_BLUE	                                                  32

#elif(_LOGO_TYPE ==_LOGO_JAPANEXT_QHD)
#define _LOGO_FG_COLOR									   _LOGO_CP_BLACK 
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
							
#define _LOGO_COL_SIZE										42
#define _LOGO_ROW_SIZE										4
						
#define _LOGO_BG_RED													 0
#define _LOGO_BG_GREEN													 0
#define _LOGO_BG_BLUE	                                                 0

#elif(_LOGO_TYPE == _LOGO_XDIGITAL)
#define _LOGO_FG_COLOR										_LOGO_CP_BLACK
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE//_LOGO_CP_WHITE		
			
#define _LOGO_COL_SIZE										46
#define _LOGO_ROW_SIZE										9

#define _LOGO_BG_RED										0
#define _LOGO_BG_GREEN										0
#define _LOGO_BG_BLUE										0


#elif(_LOGO_TYPE == _LOGO_PEAQ)
	
#define _LOGO_FG_COLOR							_LOGO_CP_WHITE
#define _LOGO_BG_COLOR						      _LOGO_CP_BLACK 		  		     
							
#define _LOGO_COL_SIZE										78
#define _LOGO_ROW_SIZE										16
						
#define _LOGO_BG_RED													  0
#define _LOGO_BG_GREEN													 0
#define _LOGO_BG_BLUE													  0	  

#elif(_LOGO_TYPE == _LOGO_LVYUAN)
#define _LOGO_FG_COLOR						    				_LOGO_CP_BG 	
#define _LOGO_BG_COLOR						   					_LOGO_CP_WHITE  		  		     
								
#define _LOGO_COL_SIZE											78
#define _LOGO_ROW_SIZE											8
							
#define _LOGO_BG_RED											255
#define _LOGO_BG_GREEN											255
#define _LOGO_BG_BLUE											255 

#elif(_LOGO_TYPE == _LOGO_FYHXELE)
#define _LOGO_FG_COLOR						    				_LOGO_CP_BG 	
#define _LOGO_BG_COLOR						   					_LOGO_CP_WHITE  		  		     
								
#define _LOGO_COL_SIZE											74
#define _LOGO_ROW_SIZE											9
							
#define _LOGO_BG_RED											255
#define _LOGO_BG_GREEN											255
#define _LOGO_BG_BLUE											255 

#elif(_LOGO_TYPE == _LOGO_GREBEAR2)
#define _LOGO_FG_COLOR									 _LOGO_CP_BLACK
#define _LOGO_BG_COLOR									  _LOGO_CP_WHITE     
							
#define _LOGO_COL_SIZE										67
#define _LOGO_ROW_SIZE										9
						
#define _LOGO_BG_RED										255
#define _LOGO_BG_GREEN										255
#define _LOGO_BG_BLUE										255

#elif(_LOGO_TYPE == _LOGO_PICHAU)
#define _LOGO_FG_COLOR						    				_LOGO_CP_BG 	
#define _LOGO_BG_COLOR						   					_LOGO_CP_WHITE  		  		     
								
#define _LOGO_COL_SIZE											62
#define _LOGO_ROW_SIZE											14
							
#define _LOGO_BG_RED											0
#define _LOGO_BG_GREEN											0
#define _LOGO_BG_BLUE											0 
#elif(_LOGO_TYPE == _LOGO_TGDA)



#define _LOGO_FG_COLOR								_LOGO_CP_BLACK	 
#define _LOGO_BG_COLOR								 _LOGO_CP_WHITE    		
					
#define _LOGO_COL_SIZE										 60
#define _LOGO_ROW_SIZE										 15
				
#define _LOGO_BG_RED													255
#define _LOGO_BG_GREEN													255
#define _LOGO_BG_BLUE													255


#elif(_LOGO_TYPE == _LOGO_TGDB)


#define _LOGO_FG_COLOR						_LOGO_CP_BLACK		 
#define _LOGO_BG_COLOR						 _LOGO_CP_WHITE  			  		
					
#define _LOGO_COL_SIZE										 56
#define _LOGO_ROW_SIZE										 13
				
#define _LOGO_BG_RED													255
#define _LOGO_BG_GREEN													255
#define _LOGO_BG_BLUE													255
#elif(_LOGO_TYPE == _LOGO_ARZOPA_4BIT)
#define _LOGO_FG_COLOR                                 _LOGO_CP_BLACK
#define _LOGO_BG_COLOR                                 _LOGO_CP_WHITE
			
#define _LOGO_COL_SIZE									71
#define _LOGO_ROW_SIZE									10

#define _LOGO_BG_RED                                	255
#define _LOGO_BG_GREEN                              	255
#define _LOGO_BG_BLUE                         			255

#elif(_LOGO_TYPE == _LOGO_ARZOPA)


#define _LOGO_FG_COLOR						_LOGO_CP_BLACK		 
#define _LOGO_BG_COLOR						 _LOGO_CP_WHITE  			  		
					
#define _LOGO_COL_SIZE										 75
#define _LOGO_ROW_SIZE										 11
				
#define _LOGO_BG_RED													255
#define _LOGO_BG_GREEN													255
#define _LOGO_BG_BLUE													255

#elif(_LOGO_TYPE == _LOGO_ASTEX)


#define _LOGO_FG_COLOR				_LOGO_CP_WHITE				 
#define _LOGO_BG_COLOR						_LOGO_CP_BG    			  		
					
#define _LOGO_COL_SIZE										 83
#define _LOGO_ROW_SIZE										 19
				
#define _LOGO_BG_RED													27
#define _LOGO_BG_GREEN													51
#define _LOGO_BG_BLUE													147
#elif(_LOGO_TYPE == _LOGO_SANSE)
#define _LOGO_FG_COLOR                                      _LOGO_CP_RED
#define _LOGO_BG_COLOR                                      _LOGO_CP_WHITE//_LOGO_CP_BLACK
			
#define _LOGO_COL_SIZE										54
#define _LOGO_ROW_SIZE										10
	
#define _LOGO_BG_RED                                   		255
#define _LOGO_BG_GREEN                                      255
#define _LOGO_BG_BLUE			 							255

#elif(_LOGO_TYPE == _LOGO_WMX)
#define _LOGO_FG_COLOR                                      _LOGO_CP_BLACK
#define _LOGO_BG_COLOR                                      _LOGO_CP_BG
			
#define _LOGO_COL_SIZE										55
#define _LOGO_ROW_SIZE										11
	
#define _LOGO_BG_RED                                   		255
#define _LOGO_BG_GREEN                                     255
#define _LOGO_BG_BLUE			 							255

#elif(_LOGO_TYPE == _LOGO_LANLIPU)
#define _LOGO_FG_COLOR                                      _LOGO_CP_WHITE
#define _LOGO_BG_COLOR                                      _LOGO_CP_BG
				
#define _LOGO_COL_SIZE										50
#define _LOGO_ROW_SIZE										4
		
#define _LOGO_BG_RED                                   		0
#define _LOGO_BG_GREEN                                      0
#define _LOGO_BG_BLUE			 							0
#elif(_LOGO_TYPE == _LOGO_ENVISION)
#define _LOGO_FG_COLOR                                      _LOGO_CP_WHITE
#define _LOGO_BG_COLOR                                      _LOGO_CP_BG
				
#define _LOGO_COL_SIZE										50
#define _LOGO_ROW_SIZE										5
		
#define _LOGO_BG_RED                                   		0
#define _LOGO_BG_GREEN                                      0
#define _LOGO_BG_BLUE			 							0
#elif(_LOGO_TYPE == _LOGO_UG)
#define _LOGO_FG_COLOR                                      _LOGO_CP_WHITE
#define _LOGO_BG_COLOR                                      _LOGO_CP_BG
				
#define _LOGO_COL_SIZE										40
#define _LOGO_ROW_SIZE										18
		
#define _LOGO_BG_RED                                   		0
#define _LOGO_BG_GREEN                                      0
#define _LOGO_BG_BLUE			 							0




#elif(_LOGO_TYPE == _LOGO_SNAV)
#define _LOGO_FG_COLOR                                      _LOGO_CP_WHITE
#define _LOGO_BG_COLOR                                      _LOGO_CP_BLACK
			
#define _LOGO_COL_SIZE										54
#define _LOGO_ROW_SIZE										8
	
#define _LOGO_BG_RED                                   						0
#define _LOGO_BG_GREEN                                      					0
#define _LOGO_BG_BLUE			 							0

#elif(_LOGO_TYPE == _LOGO_NewToolTest)
    
#define _OSD_2_FONT_FUNCTION_LOGO                   _ON

#define _OSD_LOGOA_WIDTH                            300
#define _OSD_LOGOA_HEIGHT                           216

#define _OSD_LOGOB_WIDTH                            384
#define _OSD_LOGOB_HEIGHT                           216

#define _OSD_LOGO_2BIT_OFFSET                       175
#define _OSD_LOGO_4BIT_OFFSET                       0

#elif(_LOGO_TYPE == _LOGO_CHUANSHENG_TEXT)
#define _LOGO_FG_COLOR						    				_LOGO_CP_BG 	
#define _LOGO_BG_COLOR						   					_LOGO_CP_WHITE  		  		     
								
#define _LOGO_COL_SIZE											60
#define _LOGO_ROW_SIZE											5
							
#define _LOGO_BG_RED											0
#define _LOGO_BG_GREEN											0
#define _LOGO_BG_BLUE											0 

#elif(_LOGO_TYPE == _LOGO_BEZEL)
#define _LOGO_FG_COLOR											_LOGO_CP_WHITE
#define _LOGO_BG_COLOR											_LOGO_CP_GRAY

#define _LOGO_COL_SIZE											53
#define _LOGO_ROW_SIZE											10
										
#define _LOGO_BG_RED											255
#define _LOGO_BG_GREEN											255
#define _LOGO_BG_BLUE											255

#elif(_LOGO_TYPE == _LOGO_MUCAI)
#define _LOGO_FG_COLOR									 	_LOGO_CP_WHITE    	  
#define _LOGO_BG_COLOR										_LOGO_CP_BLUE_1
										
#define _LOGO_COL_SIZE										43
#define _LOGO_ROW_SIZE										14
									
#define _LOGO_BG_RED										255
#define _LOGO_BG_GREEN										255
#define _LOGO_BG_BLUE										255	

#elif(_LOGO_TYPE == _LOGO_AIWA)


#define _LOGO_FG_COLOR						    _LOGO_CP_RED 	
#define _LOGO_BG_COLOR						   _LOGO_CP_WHITE  		  		     
							
#define _LOGO_COL_SIZE										58
#define _LOGO_ROW_SIZE										8
						
#define _LOGO_BG_RED													255
#define _LOGO_BG_GREEN													255
#define _LOGO_BG_BLUE													255 


#elif(_LOGO_TYPE == _LOGO_IPASON)
#define _LOGO_FG_COLOR									   _LOGO_CP_BLACK 
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
					
#define _LOGO_COL_SIZE										70
#define _LOGO_ROW_SIZE										9
				
#define _LOGO_BG_RED													  0
#define _LOGO_BG_GREEN													 0
#define _LOGO_BG_BLUE													  0	


#elif(_LOGO_TYPE == _LOGO_SKY)
#define _LOGO_FG_COLOR									  _LOGO_CP_BLUE_1    
#define _LOGO_BG_COLOR										_LOGO_CP_WHITE
					
#define _LOGO_COL_SIZE										78
#define _LOGO_ROW_SIZE										6
				
#define _LOGO_BG_RED													  0
#define _LOGO_BG_GREEN													 99
#define _LOGO_BG_BLUE													  177	




#elif(_LOGO_TYPE == _LOGO_TIEMU)
	#define _LOGO_FG_COLOR                                  _LOGO_CP_BLACK    
	#define _LOGO_BG_COLOR                                    _LOGO_CP_WHITE   
								
	#define _LOGO_COL_SIZE									21//	30
	#define _LOGO_ROW_SIZE									18//	21
							
	#define _LOGO_BG_RED                                                       0
	#define _LOGO_BG_GREEN                                                   0
	#define _LOGO_BG_BLUE                                                     0    





#elif(_LOGO_TYPE == _3G_LOGO)
	#define _LOGO_FG_COLOR                                     _LOGO_CP_PINK 
	#define _LOGO_BG_COLOR                                      _LOGO_CP_BG
						
	#define _LOGO_COL_SIZE										31
	#define _LOGO_ROW_SIZE										21
					
	#define _LOGO_BG_RED                                                       255
	#define _LOGO_BG_GREEN                                                   255
	#define _LOGO_BG_BLUE													  255 						
		
#elif(_LOGO_TYPE == _ZORO_LOGO)
	#define _LOGO_FG_COLOR                                      _LOGO_CP_BG
	#define _LOGO_BG_COLOR                                      _LOGO_CP_WHITE
				
	#define _LOGO_COL_SIZE										65
	#define _LOGO_ROW_SIZE										13
			
	#define _LOGO_BG_RED                                                       255
	#define _LOGO_BG_GREEN                                                   255
	#define _LOGO_BG_BLUE													  255 						


#elif(_LOGO_TYPE == _HYINGDA_LOGO)
	#define _LOGO_FG_COLOR                                      _LOGO_CP_BG
	#define _LOGO_BG_COLOR                                      _LOGO_CP_BLUE_1
		
	#define _LOGO_COL_SIZE										85
	#define _LOGO_ROW_SIZE										9
	
	#define _LOGO_BG_RED                                                       255
	#define _LOGO_BG_GREEN                                                   255
	#define _LOGO_BG_BLUE                                                     255        

#elif(_LOGO_TYPE == _BIG_ELECTRIQ_LOGO)
	#define _LOGO_FG_COLOR                                      _LOGO_CP_WHITE
	#define _LOGO_BG_COLOR                                      _LOGO_CP_GRAY

	#define _LOGO_FG_COLOR1										_LOGO_CP_WHITE
	#define _LOGO_BG_COLOR1										_LOGO_CP_GRAY
		
		
	#define _LOGO_COL_SIZE										75
	#define _LOGO_ROW_SIZE										11
	
	#define _LOGO_BG_RED                                                       255
	#define _LOGO_BG_GREEN                                                   255
	#define _LOGO_BG_BLUE                                                     255                         

	#define _LOGO_ROW_START1										0  //不是分2段载的logo不需要定义
	#define _LOGO_COL_START1										36 //不是分2段载的logo不需要定义



#elif(_LOGO_TYPE == _LOGO_KGAN)

	#define _LOGO_FG_COLOR                                        _CP_WHITE
	#define _LOGO_BG_COLOR                                  _LOGO_CP_BLACK  

	#define _LOGO_FG_COLOR1								_CP_WHITE		
	#define _LOGO_BG_COLOR1						_LOGO_CP_BLACK				
		
		
	#define _LOGO_COL_SIZE										56
	#define _LOGO_ROW_SIZE										13
	
	#define _LOGO_BG_RED                                                       0
	#define _LOGO_BG_GREEN                                                   0
	#define _LOGO_BG_BLUE                                                     0                         

	#define _LOGO_ROW_START1										0  //???2???logo?????
	#define _LOGO_COL_START1										28 //???2???logo?????


	
	
#elif(_LOGO_TYPE == _LOGO_PEAQ_2K)
	
	#define _LOGO_FG_COLOR                                        _LOGO_CP_BLACK
	#define _LOGO_BG_COLOR                                  _CP_WHITE//_LOGO_CP_BLACK  
	
	#define _LOGO_FG_COLOR1								_LOGO_CP_BLACK		
	#define _LOGO_BG_COLOR1						_CP_WHITE				
			
			
	#define _LOGO_COL_SIZE										94
	#define _LOGO_ROW_SIZE										21
		
	#define _LOGO_BG_RED                                                       0
	#define _LOGO_BG_GREEN                                                   0
	#define _LOGO_BG_BLUE                                                     0                         
	
	#define _LOGO_ROW_START1										0  //???2???logo?????
	#define _LOGO_COL_START1										47 //???2???logo?????
	


#elif(_LOGO_TYPE == _LOGO_AMOI_XIAXIN)
#define _LOGO_FG_COLOR						_CP_WHITE
#define _LOGO_BG_COLOR						_LOGO_CP_BLUE_1
	
#define _LOGO_COL_SIZE							(71)
#define _LOGO_ROW_SIZE							(10)
	
#define _LOGO_ROW_START1						0
#define _LOGO_COL_START1						41
	
#define _LOGO_BG_RED							255
#define _LOGO_BG_GREEN							255
#define _LOGO_BG_BLUE							255

#elif(_LOGO_TYPE == _LOGO_SOOANN)
#define _LOGO_FG_COLOR						_LOGO_CP_BLUE_1
#define _LOGO_BG_COLOR						_CP_WHITE
		
#define _LOGO_COL_SIZE							(98)
#define _LOGO_ROW_SIZE							(10)
		
#define _LOGO_ROW_START1						0
#define _LOGO_COL_START1						30
		
#define _LOGO_BG_RED							255
#define _LOGO_BG_GREEN							255
#define _LOGO_BG_BLUE							255

#elif(_LOGO_TYPE == _LOGO_CHUANSHENG)
#define _LOGO_FG_COLOR							 			_LOGO_CP_WHITE
#define _LOGO_BG_COLOR										_LOGO_CP_BLUE_1
	
#define _LOGO_FG_COLOR1 									_LOGO_CP_WHITE				
#define _LOGO_BG_COLOR1 									_LOGO_CP_BLUE_1
			
			
#define _LOGO_COL_SIZE										74
#define _LOGO_ROW_SIZE										15
		
#define _LOGO_BG_RED										255
#define _LOGO_BG_GREEN										255
#define _LOGO_BG_BLUE										255

#define _LOGO_ROW_START1										0  
#define _LOGO_COL_START1										37

#elif(_LOGO_TYPE == _LOGO_GUANJIE)
#define _LOGO_FG_COLOR                                       _CP_WHITE
#define _LOGO_BG_COLOR                                     _LOGO_CP_BLUE_1
			
#define _LOGO_FG_COLOR1						                _CP_WHITE			
#define _LOGO_BG_COLOR1						                _LOGO_CP_BLUE_1					
					
					
#define _LOGO_COL_SIZE										50
#define _LOGO_ROW_SIZE										27
				
#define _LOGO_BG_RED                                                        255
#define _LOGO_BG_GREEN                                                   255
#define _LOGO_BG_BLUE                                                     255                    
			
#define _LOGO_ROW_START1										0
#define _LOGO_COL_START1										25

#elif(_LOGO_TYPE == _LOGO_XGAMING)
#define _LOGO_FG_COLOR                                       _LOGO_CP_ORANGE_L
#define _LOGO_BG_COLOR                                     _LOGO_CP_BLUE_1 
			
#define _LOGO_FG_COLOR1						                _LOGO_CP_ORANGE_L			
#define _LOGO_BG_COLOR1						                _LOGO_CP_BLUE_1					
					
					
#define _LOGO_COL_SIZE										139
#define _LOGO_ROW_SIZE										15


#define _LOGO_BG_RED                                                        0
#define _LOGO_BG_GREEN                                                   160
#define _LOGO_BG_BLUE                                                     233                    
			
#define _LOGO_ROW_START1										0
#define _LOGO_COL_START1										69
#elif(_LOGO_TYPE == _LOGO_FUEGO)


#define _LOGO_FG_COLOR							_LOGO_CP_GRAY	  
#define _LOGO_BG_COLOR							 _LOGO_CP_WHITE		 	
					
#define _LOGO_COL_SIZE									    88
#define _LOGO_ROW_SIZE										27
				
#define _LOGO_BG_RED													   255
#define _LOGO_BG_GREEN													 255
#define _LOGO_BG_BLUE													  255	

			
#define _LOGO_ROW_START1										0
#define _LOGO_COL_START1										29
#elif(_LOGO_TYPE == _LOGO_GENLOVE)
	#define _LOGO_FG_COLOR                                    	_LOGO_CP_BLUE_1
	#define _LOGO_BG_COLOR                                  	_LOGO_CP_WHITE
	#define _LOGO_FG_COLOR1										_LOGO_CP_BLUE_1		
	#define _LOGO_BG_COLOR1										_LOGO_CP_WHITE				

				
	#define _LOGO_COL_SIZE										76
	#define _LOGO_ROW_SIZE										11
			
	#define _LOGO_BG_RED                                            255
	#define _LOGO_BG_GREEN                                              255
	#define _LOGO_BG_BLUE                                                 255                         
		
	#define _LOGO_ROW_START1										0  //不是分2段载的logo不需要定义
	#define _LOGO_COL_START1										38 //不是分2段载的logo不需要定义

#endif









/***************************************************************************/

#ifndef _LOGO_POS_H
#define _LOGO_POS_H                				  			50
#endif

#ifndef _LOGO_POS_V
#define _LOGO_POS_V                							50
#endif

#ifndef _LOGO_FG_COLOR1
#define _LOGO_FG_COLOR1                						_LOGO_FG_COLOR
#endif

#ifndef _LOGO_BG_COLOR1
#define _LOGO_BG_COLOR1                						_LOGO_BG_COLOR
#endif


