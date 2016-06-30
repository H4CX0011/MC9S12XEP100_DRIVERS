/******************************************************************************
 * @file main.c														     
 *																		 
 * @version v0.01														 
 * 																		 
 * @date May, 20, 2016 													 
 *																		 
 * @brief main file.  									 
 *****************************************************************************/
#include "headers.h"

void main( void ) 
{
    
    ClockConfigType sClockConfig;
    ClockConfigType *pClockConfigPtr = &sClockConfig;
    PitConfigType sPitConfig0;
    PitConfigType *pPitConfigPtr0 = &sPitConfig0;
    /* Configure system clock at 40 Mhz, OSC 4 MHz */
    pClockConfigPtr->bSysClockSel = 1;   /* Select PLL as system clock */
    pClockConfigPtr->u8OscClock = 4;	 /* OSC frequency MHz */
    pClockConfigPtr->u8BusClock = 40;    /* Set system clock, MHz */
    pClockConfigPtr->u8RefClock = 4;     /* Set reference clock, MHz */
    
    /* Configure PIT mosule channel 0 */
    pPitConfigPtr0->bMicroTimerSel = 0;
    pPitConfigPtr0->u8PitChannelSel = 0;
    pPitConfigPtr0->u8MicroTimerVal = 199;
    pPitConfigPtr0->u16PitLoadVal = 39999;/* 200 ms */
    
    /* put your own code here */
    DisableInterrupts;

    DDRA = 0xFF;
    PORTA = 0xFF;
    
    
    
    Clock_Init( pClockConfigPtr );
    PIT_Init( pPitConfigPtr0 );

    EnableInterrupts;


    for(;;) {
        _FEED_COP(); /* feeds the dog */
        
        if( PITTF_PTF0 ) {
            PORTA_PA0 = ~PORTA_PA0;
            PITTF_PTF0 = 1; 
        }
        
    } /* loop forever */
    /* please make sure that you never leave main */
}
