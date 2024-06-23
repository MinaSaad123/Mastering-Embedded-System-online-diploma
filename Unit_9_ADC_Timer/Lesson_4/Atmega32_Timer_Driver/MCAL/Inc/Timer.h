/*
 * TIMER.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef Timer_H_
#define Timer_H_

//============================<Includes>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Utils.h"

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                                            User Define
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

//===========================<Config Clock OSC>
typedef struct
{
	uint8_t Internal_CLK;
	uint8_t External_CLK;

}S_TIMER_CLK_Osc_t;


/*                                                 ============================
 *=================================================* Typedef For TIMER Config *===================================================
 *                                                 ============================
 */

typedef struct
{
	uint32_t TIMER_Mode;       	          //Specifies TIMER Mode (Normal Mode - Compare Mode - Fast PWM Mode)
									      //This Parameter must be set base on @ref TIMER_Mode

	S_TIMER_CLK_Osc_t TIMER_CLK_Osc;      //Specifies Oscillator source Mode (Internal - External)
									      //This Parameter must be set base on @ref TIMER_CLK

	uint32_t TIMER_Interrupt;             //Specifies TIMER Interrupt to be Enable or not
										  //This Parameter must be set base on @ref TIMER_Interrupt_Define

	void (*P_TIMER_Callback)();           //Specifies Function Callback Symbols

}TIMER_Config_t;
//================================================================================================================================

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                                                  TIMER @ref
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

//==========================<@ref TIMER_CLK_Define>
#define TIMER_CLK_Internal_NoSource 0x0
#define TIMER_CLK_Internal_1MHZ     0x1
#define TIMER_CLK_Internal_125KHZ   0x2

//==========================<@ref TIMER_Mode>
typedef enum
{
	CTC,
	Normal,
	Fast_PWM
}TMR_MDE_t;

//==========================<@ref TIMER_Interrupt_Define>
#define TIMER_Interrupt_Disable 0x0
#define TIMER_Interrupt_Enable  0x1
//================================================================================================================================

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                                            Support APIs by: TIMER
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
void MCAL_TIMER0_Init (TIMER_Config_t* TIMER_CFG);
void MCAL_StopTimer0 ();

void MCAL_TIMER0_GetCompareValue (uint8_t* TicksNumbers);
void MCAL_TIMER0_SetCompareValue (uint8_t TicksNumbers);

void MCAL_TIMER0_GetCounterValue (uint8_t* TicksNumbers);
void MCAL_TIMER0_SetCounterValue (uint8_t TicksNumbers);

#endif /* Timer_H_ */
