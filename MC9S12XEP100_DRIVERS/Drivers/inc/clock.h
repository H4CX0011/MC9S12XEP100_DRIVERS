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
    word RealTimeIntEn  :1; /* 1:enable, 0:disable */
    word SysClockSel    :1; /* 1:PLLCLK, 0:OSCCLK */
    word BusClock       :8; /* set bus clock, unit MHz */
}ClockConfigType, *ClockConfigTypePtr;



#endif
/* end _CLOCK_H_ */