/*
 * Uart.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef UART_H_
#define UART_H_

//Include
#include <avr/io.h>
#include "Utils.h"
#include "avr/interrupt.h"
#include "util/delay.h"

#define SREG	*((volatile uint8_t*)0x5F)	  //Global interrupt Register

//=*=*=*=*=*Enumeration Typedef
typedef enum
{

	Disable,
	Enable

}State;

//===================Function Prototype
void MCAL_Send_Int ();
void MCAL_Uart_Init ();
uint32_t MCAL_Receive_Int ();
uint8_t MCAL_Uart_Receive ();
void MCAL_Uart_Send (uint8_t Data);
uint8_t MCAL_Uart_Receive_String (void);
void MCAL_Uart_Send_String (uint8_t* PStr);
void MCAL_Uart_ENR_DIS_Interrupt (uint8_t IRQ);


#endif /* UART_H_ */
