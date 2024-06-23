/*
 * Series.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef UTILS_H_
#define UTILS_H_

//Set Bit
#define Set_Bit(Reg, Bit)     (Reg |= (1 << Bit))
//Reset Bit
#define Reset_Bit(Reg, Bit)   (Reg &= ~(1 << Bit))
//Toggle bit
#define Toggle_Bit(Reg, Bit)  (Reg ^= (1 << Bit))
//Read bit
#define Read_Bit(Reg, Bit)    ( ((Reg >> Bit) & 1 ))


#endif /* UTILS_H_ */
