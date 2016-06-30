/******************************************************************************
* @file pit.c														     
*																		 
* @version v0.01														 
* 																		 
* @date June, 28, 2016 													 
*																		 
* @brief Period interrupt timer (PIT) module source file.  									 
******************************************************************************/
#include "headers.h"

/******************************************************************************
* @brief  PIT_Enable - PIT is enabled.													     
*																		 
* @param  none														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_Enable( void ) 
{
    PITCFLMT_PITE = 1;
}
/******************************************************************************
* @brief  PIT_Disable - PIT is disabled.													     
*																		 
* @param  none														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_Disable( void ) 
{
    PITCFLMT_PITE = 0;
}
/******************************************************************************
* @brief  PIT_ForceLoadEnable0 - PIT Force Load for Micro Timer.													     
*																		 
* @param[in]  micro_timer  Micro timer 1:0														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_MicroForceLoadEnable( byte micro_timer ) 
{
    PITCFLMT_PFLMT |= (1 << micro_timer);
}
/******************************************************************************
* @brief  PIT_ForceLoadEnable - PIT Force Load for PIT timer.													     
*																		 
* @param[in]  PIT timer channel	7:0														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_TimerForceLoadEnable( byte channel ) 
{
    PITFLT |= (1 << channel);
}
/******************************************************************************
* @brief  PIT_ChannelEnable - Enable PIT timer channel.													     
*																		 
* @param[in]  PIT timer channel	7:0														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_ChannelEnable( byte channel ) 
{
    PITCE |= (1 << channel);
}
/******************************************************************************
* @brief  PIT_MultiplexSel - Select micro timer for timer 0 ~ 7.													     
*																		 
* @param[in]  PIT timer channel	7:0
* @param[in]  micro_timer  Micro timer 1:0														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_MultiplexSel( byte channel, byte micro_timer ) 
{
    if( micro_timer ) {
        PITMUX |= (1 << channel);
    }
    else {
        PITMUX &= ~(1 << channel);
    }
}
/******************************************************************************
* @brief  PIT_IntEnable - Enable channel interrupt for PIT timer.													     
*																		 
* @param[in]  PIT timer channel	7:0													 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_IntEnable( byte channel ) 
{
    PITINTE |= (1 << channel);
}
/******************************************************************************
* @brief  PIT_MicroLoadVal - Load register value for PIT micro timer.													     
*																		 
* @param[in]  micro_timer  Micro timer 1:0
* @param[in]  value  Loaded value at PIT micro timer register													 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_MicroLoadVal( byte micro_timer, byte value ) 
{
    if( !micro_timer ) {
        PITMTLD0 = value;
    }
    else {
        PITMTLD1 = value;
    }
}
/******************************************************************************
* @brief  PIT_TimerLoadVal - Load register value for PIT timer.													     
*																		 
* @param[in]  channel  PIT timer channel 7:0
* @param[in]  value  Loaded value at PIT timer register  														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_TimerLoadVal( byte channel, word value ) 
{
    switch( channel )
    {
    	case 0:
    	PITLD0 = value;
    	break;
    	case 1:
    	PITLD1 = value;
    	break;
    	case 2:
    	PITLD2 = value;
    	break;
    	case 3:
    	PITLD3 = value;
    	break;
    	case 4:
    	PITLD4 = value;
    	break;
    	case 5:
    	PITLD5 = value;
    	break;
    	case 6:
    	PITLD6 = value;
    	break;
    	case 7:
    	PITLD7 = value;
    	break;
    }
}
/******************************************************************************
* @brief  PIT_Init - Initialize PIT module.													     
*																		 
* @param  *pConfig  Pointer to PIT configure struct														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_Init( PitConfigType *pConfig ) 
{
    PIT_Disable();
    
    PIT_MicroForceLoadEnable( pConfig->bMicroTimerSel );
    PIT_TimerForceLoadEnable( pConfig->u8PitChannelSel );
        
    PIT_MicroLoadVal( pConfig->bMicroTimerSel, pConfig->u8MicroTimerVal );
    PIT_TimerLoadVal( pConfig->u8PitChannelSel, pConfig->u16PitLoadVal );
    
    PIT_MultiplexSel( pConfig->u8PitChannelSel, pConfig->bMicroTimerSel );
    
    PIT_ChannelEnable( pConfig->u8PitChannelSel );
    
    if( pConfig->bChannelIntEn ) {
        PIT_IntEnable( pConfig->u8PitChannelSel );        
    } 
           
    PIT_Enable();    
}
/******************************************************************************
* @brief  PIT_ClearIntFlag - Clear PIT Time-out Flag Bits for Timer Channel 													     
*																		 
* @param  channel  PIT timer channel 7:0														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void PIT_ClearIntFlag( byte channel )
{
    PITTF |= (1 << channel);    
}