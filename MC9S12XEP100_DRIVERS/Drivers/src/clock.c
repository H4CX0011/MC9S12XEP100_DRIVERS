/******************************************************************************
 * @file clock.c														     
 *																		 
 * @version v0.01														 
 * 																		 
 * @date May, 20, 2016 													 
 *																		 
 * @brief Clock module source file.  									 
 *****************************************************************************/
#include "headers.h"

/* Clock module register APIs */
/******************************************************************************
 * @brief  Enable Real Time Interrupt														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_RealTimeIntEnable( void )
{
    CRGINT_RTIE = 1;    
}
/******************************************************************************
 * @brief  Disable Real Time Interrupt														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_RealTimeIntDisable( void )
{
    CRGINT_RTIE = 0;    
}
/******************************************************************************
 * @brief  Enable Lock Interrupt														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_LockIntEnable( void )
{
    CRGINT_LOCKIE = 1;    
}
/******************************************************************************
 * @brief  Disable Lock Interrupt														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_LockIntDisable( void )
{
    CRGINT_LOCKIE = 0;    
}
/******************************************************************************
 * @brief  Enable self clock mode interrupt														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_SelfClkIntEnable( void )
{
    CRGINT_SCMIE = 1;    
}
/******************************************************************************
 * @brief  Disable self clock mode interrupt														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_SelfClkIntDisable( void )
{
    CRGINT_SCMIE = 0;    
}
/******************************************************************************
 * @brief  Configure system clock														     
 *																		 
 * @param[in]  *pConfig pointer to user configure struct														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_SysClkConfig( ClockConfigType *pConfig )
{
    if( pConfig->SysClockSel )
    {
        CLKSEL_PLLSEL = 1;  /* System clocks fBUS = fPLL / 2 */
    }
    else
    {
        CLKSEL_PLLSEL = 0;  /* System clocks fBUS = fOSC / 2 */ 
    }
}
/******************************************************************************
 * @brief  IPLL keeps running in Wait Mode														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_IPLLWaitEnable( void )
{
    CLKSEL_PLLWAI = 0;   
}
/******************************************************************************
 * @brief  IPLL stops in Wait Mode														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_IPLLWaitDisable( void )
{
    CLKSEL_PLLWAI = 1;   
}
/******************************************************************************
 * @brief  Real Time Interrupt keeps running in Wait Mode														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_RTIWaitEnable( void )
{
    CLKSEL_RTIWAI = 0;   
}
/******************************************************************************
 * @brief  Real Time Interrupt stops in Wait Mode														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_RTIWaitDisable( void )
{
    CLKSEL_RTIWAI = 1;   
}
/******************************************************************************
 * @brief  COP keeps running in Wait Mode														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_COPWaitEnable( void )
{
    CLKSEL_COPWAI = 0;   
}
/******************************************************************************
 * @brief  COP stops in Wait Mode														     
 *																		 
 * @param  none														 
 * 																		 
 * @return	none												 																		   									 
 *****************************************************************************/
void Clock_COPWaitDisable( void )
{
    CLKSEL_COPWAI = 1;   
}
void Init_PLL_Clock (void)
{   
  /*set to 48M HZ, 16M crystal*/ 
  PLLCTL = 0B10000001;  //CME=1,PLLON=0,FM1=0,FM2=0,FSTWKP=0,PRE=0,PCE=0,SCME=1
  CLKSEL = 0B00000011;  //PLLSEL=0,PSTP=0,PLLWAI=0,RTIWAI=1,COPWAI=1
  SYNR = 0xC2;          //Set the multiplier register
  REFDV = 0xC0;        //Set the divider register
  POSTDIV = 0x00;       //Set the post divider register
  PLLCTL |= PLLCTL_PLLON_MASK;  //Enable the Phase Lock Loop 
     
  //Wait till the PLL VCO is within tolerance
  while((CRGFLG & CRGFLG_LOCK_MASK) == 0);      
  CLKSEL |= CLKSEL_PLLSEL_MASK; //system clocks are derived from PLLCLK  
}