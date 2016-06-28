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
    /* put your own code here */
    DisableInterrupts;


    EnableInterrupts;


    for(;;) {
        _FEED_COP(); /* feeds the dog */
    } /* loop forever */
    /* please make sure that you never leave main */
}
