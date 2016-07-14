/******************************************************************************
* @file sci.c														     
*																		 
* @version v0.01														 
* 																		 
* @date June, 29, 2016 													 
*																		 
* @brief Serial Communication interface (PIT) module source file.  									 
******************************************************************************/
#include "headers.h"

/******************************************************************************
* @brief  SCI_InfraredEnable - enables the infrared modulation/demodulation 
*                              submodule.													     
*																		 
* @param  SCIx  SCI module number 7:0.														 
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_InfraredEnable( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
        SCI0BDH_IREN = 1;
        break;
        case 1:
        SCI1BDH_IREN = 1;
        break;
        case 2:
        SCI2BDH_IREN = 1;
        break;
        case 3:
        SCI3BDH_IREN = 1;
        break;
        case 4:
        SCI4BDH_IREN = 1;
        break;
        case 5:
        SCI5BDH_IREN = 1;
        break;
        case 6:
        SCI6BDH_IREN = 1;
        break;
        case 7:
        SCI7BDH_IREN = 1;
        break;
    }
}
/******************************************************************************
* @brief  SCI_SetBaudRate - Set baud rate for SCI module.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* @param[in]  infrared_en  Intrared enable bit.														 
* @param[in]  fBUS  System clock, MHz.
* @param[in]  baud_rate  Baud rate of SCI module, bit/s.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_SetBaudRate( byte SCIx, byte infrared_en, byte fBUS, word baud_rate )
{
    switch( SCIx ) {
    	case 0:
	    if( infrared_en ) {
	        SCI0BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI0BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 1:
	    if( infrared_en ) {
	        SCI1BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI1BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 2:
	    if( infrared_en ) {
	        SCI2BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI2BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 3:
	    if( infrared_en ) {
	        SCI3BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI3BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 4:
	    if( infrared_en ) {
	        SCI4BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI4BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 5:
	    if( infrared_en ) {
	        SCI5BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI5BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 6:
	    if( infrared_en ) {
	        SCI6BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI6BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    case 7:
	    if( infrared_en ) {
	        SCI7BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 32;
	    }
	    else {
	        SCI7BD_SBR = fBUS * (10000 / (baud_rate / 100)) / 16;
	    }
	    break;
	    
	}
}
/******************************************************************************
* @brief  SCI_LoopEnable - Loop operation enabled.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_LoopEnable( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
        SCI0CR1_LOOPS = 1; 
    	break;
    	case 1:
        SCI1CR1_LOOPS = 1; 
    	break;
    	case 2:
        SCI2CR1_LOOPS = 1; 
    	break;
    	case 3:
        SCI3CR1_LOOPS = 1; 
    	break;
    	case 4:
        SCI4CR1_LOOPS = 1; 
    	break;
    	case 5:
        SCI5CR1_LOOPS = 1; 
    	break;
    	case 6:
        SCI6CR1_LOOPS = 1; 
    	break;
    	case 7:
        SCI7CR1_LOOPS = 1; 
    	break;
    } 
}
/******************************************************************************
* @brief  SCI_LoopDisable - Normal operation enabled.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_LoopDisable( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
        SCI0CR1_LOOPS = 0; 
    	break;
    	case 1:
        SCI1CR1_LOOPS = 0; 
    	break;
    	case 2:
        SCI2CR1_LOOPS = 0; 
    	break;
    	case 3:
        SCI3CR1_LOOPS = 0; 
    	break;
    	case 4:
        SCI4CR1_LOOPS = 0; 
    	break;
    	case 5:
        SCI5CR1_LOOPS = 0; 
    	break;
    	case 6:
        SCI6CR1_LOOPS = 0; 
    	break;
    	case 7:
        SCI7CR1_LOOPS = 0; 
    	break;
    } 
}
/******************************************************************************
* @brief  SCI_DataFormat8 - One start bit, eight data bits, one stop bit.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_DataFormat8( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
    	SCI0CR1_M = 0;
        break;
        case 1:
    	SCI1CR1_M = 0;
        break;
        case 2:
    	SCI2CR1_M = 0;
        break;
        case 3:
    	SCI3CR1_M = 0;
        break;
        case 4:
    	SCI4CR1_M = 0;
        break;
        case 5:
    	SCI5CR1_M = 0;
        break;
        case 6:
    	SCI6CR1_M = 0;
        break;
        case 7:
    	SCI7CR1_M = 0;
        break;
    }
}
/******************************************************************************
* @brief  SCI_DataFormat9 - One start bit, nine data bits, one stop bit.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_DataFormat9( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
    	SCI0CR1_M = 1;
        break;
        case 1:
    	SCI1CR1_M = 1;
        break;
        case 2:
    	SCI2CR1_M = 1;
        break;
        case 3:
    	SCI3CR1_M = 1;
        break;
        case 4:
    	SCI4CR1_M = 1;
        break;
        case 5:
    	SCI5CR1_M = 1;
        break;
        case 6:
    	SCI6CR1_M = 1;
        break;
        case 7:
    	SCI7CR1_M = 1;
        break;
    }
}
/******************************************************************************
* @brief  SCI_ReceiveIntEnable - Enable receive interrupt.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_ReceiveIntEnable( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
    	SCI0CR2_RIE = 1;
    	break;
    	case 1:
    	SCI1CR2_RIE = 1;
    	break;
    	case 2:
    	SCI2CR2_RIE = 1;
    	break;
    	case 3:
    	SCI3CR2_RIE = 1;
    	break;
    	case 4:
    	SCI4CR2_RIE = 1;
    	break;
    	case 5:
    	SCI5CR2_RIE = 1;
    	break;
    	case 6:
    	SCI6CR2_RIE = 1;
    	break;
    	case 7:
    	SCI7CR2_RIE = 1;
    	break;
    }
}
/******************************************************************************
* @brief  SCI_ReceiveEnable - Enable receiver.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_ReceiveEnable( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
    	SCI0CR2_RE = 1;
    	break;
    	case 1:
    	SCI1CR2_RE = 1;
    	break;
    	case 2:
    	SCI2CR2_RE = 1;
    	break;
    	case 3:
    	SCI3CR2_RE = 1;
    	break;
    	case 4:
    	SCI4CR2_RE = 1;
    	break;
    	case 5:
    	SCI5CR2_RE = 1;
    	break;
    	case 6:
    	SCI6CR2_RE = 1;
    	break;
    	case 7:
    	SCI7CR2_RE = 1;
    	break;
    }    
}
/******************************************************************************
* @brief  SCI_TransmitEnable - Enable transmiter.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
void SCI_TransmitEnable( byte SCIx )
{
    switch( SCIx ) {
    	case 0:
    	SCI0CR2_TE = 1;
    	break;
    	case 1:
    	SCI1CR2_TE = 1;
    	break;
    	case 2:
    	SCI2CR2_TE = 1;
    	break;
    	case 3:
    	SCI3CR2_TE = 1;
    	break;
    	case 4:
    	SCI4CR2_TE = 1;
    	break;
    	case 5:
    	SCI5CR2_TE = 1;
    	break;
    	case 6:
    	SCI6CR2_TE = 1;
    	break;
    	case 7:
    	SCI7CR2_TE = 1;
    	break;
    }    
}
/******************************************************************************
* @brief  SCI_ReadValue - Read SCI data register.													     
*																		 
* @param[in]  SCIx  SCI module number 7:0.
* 																		 
* @return	none												 																		   									 
******************************************************************************/
byte SCI_ReadValue( byte SCIx )
{
    byte temp;
    switch( SCIx ) {
    	case 0:
    	temp = SCI0DRL;
    	break;
    	case 1:
    	temp = SCI1DRL;
    	break;
    	case 2:
    	temp = SCI2DRL;
    	break;
    	case 3:
    	temp = SCI3DRL;
    	break;
    	case 4:
    	temp = SCI4DRL;
    	break;
    	case 5:
    	temp = SCI5DRL;
    	break;
    	case 6:
    	temp = SCI6DRL;
    	break;
    	case 7:
    	temp = SCI7DRL;
    	break;  	
    }
    return temp;
}