/*
 * TIMER.c
 *
 *  Created on: Mina Saad
 *      Author: HP
 */

//================================<Includes>
#include "TIMER.h"

//                          *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//--------------------------*                 Generic variables                     *-------------------------------
//                          *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

void (*G_P_TIMER_Callback)() = (void*)0;  /*Global Callback Function*/
TIMER_Config_t G_S_TIMER_CFG_t;

//                          *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//--------------------------*                 Generic Macros                        *-------------------------------
//                          *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

#define TIMER_NormalMode  0x48
#define TIMER_CTCMode     0x8


//
//                          \_________________________________________________________/
//                          |_________________________________________________________|
//==========================|                      Implementation                     |=============================
//                          |_________________________________________________________|


//===================================<MCAL_TIMER0_Init Function>
void MCAL_TIMER0_Init (TIMER_Config_t* TIMER_CFG)
{
	//Put all TIMER_CFG Data in Global TIMER_CFG
	G_S_TIMER_CFG_t = *TIMER_CFG;

	//1. Handle Clock TIMER
	if (TIMER_CFG->TIMER_CLK_Osc.Internal_CLK)
	{
		//Put Clock Prescaler//
		TCCR0 |= (TIMER_CFG->TIMER_CLK_Osc.Internal_CLK << CS00);

	} else
	{
		//TODO Support External Clock Oscillator
	}
	//==============================================================================================================

	//2. Select TIMER Mode
	if (TIMER_CFG->TIMER_Mode == Normal)
	{
		TCCR0 &= ~(TIMER_NormalMode); /*Select Normal Mode in TIMER0*/


	} else if (TIMER_CFG->TIMER_Mode == CTC)
	{
		TCCR0 |= (TIMER_CTCMode); /*Select Clear Time compare match "CTC" Mode in TIMER0*/

	} else
	{
		//TODO Support  Fast PWM Mode and the other Modes

	}
	//==============================================================================================================

	//3. Enable/Disable Interrupt
	if (TIMER_CFG->TIMER_Interrupt == TIMER_Interrupt_Enable)
	{
		TIMSK |= 0x2;    /*Enable Interrupt*/

	} else
	{
		TIMSK &= ~(0x2); /*Disable Interrupt*/
	}
}

//========================<MCAL_StopTimer0 Function>
void MCAL_StopTimer0 ()
{
	//Neglect Clock Source
	TCCR0 &= ~(0b111 << CS00);

}

//========================<MCAL_TIMER0_GetCompareValue Function>
void MCAL_TIMER0_GetCompareValue (uint8_t* TicksNumbers)
{
	*TicksNumbers = OCR0;

}

//========================<MCAL_TIMER0_SetCompareValue Function>
void MCAL_TIMER0_SetCompareValue (uint8_t TicksNumbers)
{
	//Clear OCR0 Register
	OCR0 &= ~(0xffUL);
	//Set the new value
	OCR0 |= TicksNumbers;

}

//========================<MCAL_TIMER0_GetCounterValue Function>
void MCAL_TIMER0_GetCounterValue (uint8_t* TicksNumbers)
{
	*TicksNumbers = TCNT0;
}

//========================<MCAL_TIMER0_SetCounterValue Function>
void MCAL_TIMER0_SetCounterValue (uint8_t TicksNumbers)
{
	//Clear TCNT0 Register
	TCNT0 &= ~(0xfful);
	//Set the new value
	TCNT0 |= TicksNumbers;

}

//===================================================================
//(_   _)( )                   ( )       ( )   ( )               ( )
//  | |  | |__    ____   ___   | |/ )     \ \_/ /  ___    _   _  | |
//  | |  |  _  \ / _  )/  _  \ | | <        \ /   /   \  ( ) ( ) | |
//  | |  | | | |( (_| || ( ) | | |\ \       | |  ( (_) ) | (_) | | |
//  (_)  (_) (_) \___ )(_) (_) (_) (_)      (_)   \___/   \___/  (_)


