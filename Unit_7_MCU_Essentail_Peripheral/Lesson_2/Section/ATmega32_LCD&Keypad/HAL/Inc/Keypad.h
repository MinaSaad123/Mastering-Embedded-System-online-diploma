/*
 * Keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

//================Pins==================
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//============Keypads Ports==============
#define Keypad_output   PORTD
#define Keypad_Pin      PIND


//============Function prototype=========
char Keypad_Selected_char();
void Keypad_INIT();


#endif /* INC_KEYPAD_H_ */
