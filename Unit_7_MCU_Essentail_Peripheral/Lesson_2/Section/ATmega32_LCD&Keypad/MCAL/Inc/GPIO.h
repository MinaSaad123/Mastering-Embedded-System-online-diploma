/*
 * GPIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef GPIO_H_
#define GPIO_H_


//Include Libs
#include "util/delay.h"

/*******GPIOA Register Addresses*********/
#define PORTA     *((volatile uint32_t*)0x3B)
#define DDRA      *((volatile uint32_t*)0x3A)
#define PINA      *((volatile uint32_t*)0x39)

/*******GPIOB Register Addresses*********/
#define PORTB     *((volatile uint32_t*)0x38)
#define DDRB      *((volatile uint32_t*)0x37)
#define PINB      *((volatile uint32_t*)0x36)

/*******GPIOD Register Addresses*********/
#define PORTD     *((volatile uint32_t*)0x32)
#define DDRD      *((volatile uint32_t*)0x31)
#define PIND      *((volatile uint32_t*)0x30)

/*********(Set, Reset, Toggle) Bits Macros***********/
#define Set_bit(Address, Position)      Address |= (1 << Position)
#define Reset_bit(Address, Position)    Address &= ~(1 << Position)
#define Toggle_bit(Address, Position)   Address |= (1 << Position)

/*********Make Pins output Direction or Write(Low, High)***********/
#define Set_output(Address, Bits)       Address |= (Bits)
#define Reset_output(Address, Bits)     Address &= ~(Bits)
#define Set_input(Address, Bits)        Address &= ~(Bits)
#define Set_Pull_up(Address, Bits)      Address |= (Bits)

/*********Make Pins input***********/
#define Set_input(Address, Bits)       Address &= ~(Bits)

#endif /* GPIO_H_ */
