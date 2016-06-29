/******************************************************************************
 * @file clock.h														     
 *																		 
 * @version v0.01														 
 * 																		 
 * @date May, 20, 2016 													 
 *																		 
 * @brief clock module header file.  									 
 *****************************************************************************/
#ifndef _CLOCK_H_
#define _CLOCK_H_

/* type define */
typedef struct
{
    dword bRealTimeIntEn   :1; /* 1:enable, 0:disable */
    dword bSysClockSel     :1; /* 1:PLLCLK, 0:OSCCLK */
    dword u8OscClock       :8; /* OSC clock */
    dword u8RefClock       :8; /* set reference clock */
    dword u8BusClock       :8; /* set bus clock, unit MHz */
}ClockConfigType, *ClockConfigTypePtr;

void Clock_Init( ClockConfigType *pConfig );

#endif
/* end _CLOCK_H_ */