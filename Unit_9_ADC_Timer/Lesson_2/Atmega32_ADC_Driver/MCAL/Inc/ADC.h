/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef ADC_H_
#define ADC_H_

//============================<Includes>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Utils.h"

/*                                                 ============================
 *=================================================*  Typedef For ADC Config  *===================================================
 *                                                 ============================
 */

typedef struct
{
	uint16_t ADC_VOLT_REF; 			  //Specifies ADC VOLT Reference (Internal Vref turned off - Internal 2.56V - Compare Mode - AVCC with external capacitor at AREF pin)
									  //This Parameter must be set base on @ref ADC_VOLT_REF

	uint16_t ADC_CLK;                 //Specifies ADC VOLT Reference Clock
	  	  	  	  	  	  	  	  	  //This Parameter must be set base on @ref ADC_CLK_Define

	uint16_t ADC_Channel;             //Specifies ADC Channel
									  //This Parameter must be set base on @ref ADC_Channel_Define

	/*Regardless Interrupt*/

}S_ADC_CFG_t;
//================================================================================================================================

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                                                  ADC @ref
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

//==========================================================================================<ADC_VOLT_REF>

//-----------------------------------------------------------------------------------------
// REFS1 | REFS0 |Voltage Reference Selection                                              |
//-------|-------|-------------------------------------------------------------------------|
// 0     |  0    |AREF, Internal Vref turned off                                           |
// 0     |  1    |AVCC with external capacitor at AREF pin                                 |
// 1     |  0    |Reserved                                                                 |
// 1     |  1    |Internal 2.56V Voltage Reference with external capacitor at AREF pin     |
//------------------------------------------------------------------------------------------
typedef enum
{
	ADC_INL_Vref_Off,
	ADC_AVCC_EXL_CAP,
	ADC_INL_2_56V_WTH_EXL_CAP = 3
}ADC_VOLT_REF_t;

//===================================================================<@ref ADC_CLK_Define>

//------------------------------------------
// ADPS2 | ADPS1 | ADPS0 | Division Factor |
//-------|-------|-------|-----------------|
//   0   |  0    |  0    |     2           |
//   0   |  0    |  1    |     2           |
//   0   |  1    |  0    |     4           |
//   0   |  1    |  1    |     8           |
//------------------------------------------
#define ADC_CLK_500KHZ   0x1UL
#define ADC_CLK_200KHZ   0x2UL
#define ADC_CLK_125KHZ   0x3UL

//===================================================================<@ref ADC_Channel_Define>
#define ADC0_PA0 0x0UL
#define ADC1_PA1 0x1UL
#define ADC2_PA2 0x2UL
#define ADC3_PA3 0x3UL
#define ADC4_PA4 0x4UL
#define ADC5_PA5 0x5UL
#define ADC6_PA6 0x6UL
#define ADC7_PA7 0x7UL
//================================================================================================================================

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                                            Support APIs by: ADC
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
void MCAL_ADC_Init (S_ADC_CFG_t* ADC_CFG);
uint16_t MCAL_ADC_Get_CNV_RSLT (uint8_t ChannelNUM);
void MCAL_ADC_Start_Conversion ();

#endif /* ADC_H_ */
