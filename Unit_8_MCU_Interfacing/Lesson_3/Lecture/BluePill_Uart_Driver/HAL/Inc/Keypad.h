/*
 * Keypad.h
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

//========Include
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103x6.h"

//================Pins==================
#define R0 GPIO_PIN_11 //A11
#define R1 GPIO_PIN_12 //A12
#define R2 GPIO_PIN_13 //A13
#define R3 GPIO_PIN_14 //A14
#define C0 GPIO_PIN_3  //B3
#define C1 GPIO_PIN_4  //B4
#define C2 GPIO_PIN_5  //B5
#define C3 GPIO_PIN_6  //B6

//============Keypads Ports==============
#define KeyPad_Input    GPIOA
#define KeyPad_Output   GPIOB


//============Function prototype=========
char Keypad_Selected_char();
void Keypad_GPIO_Init();

#endif /* INC_KEYPAD_H_ */
