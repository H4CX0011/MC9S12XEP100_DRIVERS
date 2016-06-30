/******************************************************************************
* @file pit.h														     
*																		 
* @version v0.01														 
* 																		 
* @date June, 28, 2016 													 
*																		 
* @brief Period interrupt timer (PIT) module header file.  									 
******************************************************************************/
#ifndef _PIT_H_
#define _PIT_H_


typedef struct {
    byte bMicroTimerSel   :1;
    byte bChannelIntEn    :1;
    
    byte u8MicroTimerVal;
    byte u8PitChannelSel;
    word u16PitLoadVal;
}PitConfigType, *PitConfigTypePtr;


void PIT_Init( PitConfigType *pConfig ); 

#endif