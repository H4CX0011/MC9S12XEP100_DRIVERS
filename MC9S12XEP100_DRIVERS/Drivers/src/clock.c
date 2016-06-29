/******************************************************************************
* @file clock.c														     
*																		 
* @version v0.01														 
* 																		 
* @date May, 20, 2016 													 
*																		 
* @brief Clock module source file.  									 
******************************************************************************/
#include "headers.h"

/******************************************************************************
* @brief  Clock_IPLLOn - IPLL is turned on.													     
*																		 
* @param  none														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void Clock_IPLL_On( void )
{
    PLLCTL_PLLON = 1;    
}
/******************************************************************************
* @brief  Clock_IPLLOff - IPLL is turned off.													     
*																		 
* @param  none														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void Clock_IPLL_Off( void )
{
    PLLCTL_PLLON = 0;    
}
/******************************************************************************
* @brief  Clock_OSC_Enable - System clocks are derived from OSCCLK
*                            (fBUS = fOSC / 2)													     
*																		 
* @param  none														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void Clock_OSC_Enable( void )
{
    CLKSEL_PLLSEL = 0;    
} 
/******************************************************************************
* @brief  Clock_OSC_Enable - System clocks are derived from PLLCLK
*                            (fBUS = fPLL / 2)													     
*																		 
* @param  none														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void Clock_PLL_Enable( void )
{
    CLKSEL_PLLSEL = 1;    
} 
/******************************************************************************
* @brief  Clock_Init - Initialize system clock.													     
*																		 
* @param  *pConfig  Pointer to clok configure struct.														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void Clock_Init( ClockConfigType *pConfig )
{   
    byte fBUS;
    byte fREF;
    byte fPLL;
    byte fVCO;
    byte fOSC;
    
    fOSC = (byte)pConfig->u8OscClock;
    fBUS = (byte)pConfig->u8BusClock;
    fREF = (byte)pConfig->u8RefClock;
    
    Clock_IPLL_Off();    /* Disable the Phase Lock Loop */
    Clock_OSC_Enable();
    //CLKSEL = 0B00000011;  //PLLSEL=0,PSTP=0,PLLWAI=0,RTIWAI=1,COPWAI=1
        
    /* Configure REFDV register. The REFDV register provides a finer 
       granularity for the IPLL multiplier steps. */
    if( (fREF >= 1) && (fREF <= 2) ) {
        REFDV_REFFRQ = 0;
    }
    else if( (fREF > 2) && (fREF <= 6) ) {
        REFDV_REFFRQ = 1;
    }
    else if( (fREF > 6) && (fREF <= 12) ) {
        REFDV_REFFRQ = 2;
    }
    else if( fREF > 12 ) {
        REFDV_REFFRQ = 3;
    }
    REFDV_REFDIV = fBUS / fREF - 1;
    
    /* The POSTDIV register controls the frequency ratio between the VCOCLK
       and PLLCLK. */	
    POSTDIV = 0x00;
    
    /* Configure SYNDR register.The SYNR register controls the multiplication
       factor of the IPLL and selects the VCO frequency range. */
    fPLL = 2 * fBUS;
    if( !POSTDIV ) {
        fVCO = fPLL;  
    }
    else {
        fVCO = 2 * POSTDIV * fPLL;
    }
    
    if( (fVCO >= 32) && (fVCO <= 48) ) {
        SYNR_VCOFRQ = 0;
    }
    else if( (fVCO > 48) && (fVCO <= 80) ) {
        SYNR_VCOFRQ = 1;
    } 
    else if( (fVCO > 80) && (fVCO <= 120) ) {
        SYNR_VCOFRQ = 3;
    }
    SYNR_SYNDIV = fVCO / (2*fOSC) * (REFDV_REFDIV+1) - 1;
  
    Clock_IPLL_On();  /* Enable the Phase Lock Loop */ 
     
    /* Wait till the PLL VCO is within tolerance */
    while((CRGFLG & CRGFLG_LOCK_MASK) == 0);      
    CLKSEL |= CLKSEL_PLLSEL_MASK; //system clocks are derived from PLLCLK  
}