/*
 * Stm32f103cx.h
 *
 *  Created on: Sep 4, 2023
 *      Author: HP
 */

#ifndef STM32F103X6_H_
#define STM32F103X6_H_
//********************************************
//            Includes Library
//********************************************

#include <stdint.h>

//******************************************************************
//                 Memories Base addresses
//******************************************************************

#define Flash_Memory_BASE                     0x08000000
#define System_Memory_BASE                    0x1FFFF000
#define SRAM_BASE                             0x20000000
#define Peripherals_BASE                      0x40000000
#define Cortex_M_3_Internals_Prepherals_BASE  0xE0000000
#define RCC_BASE                              0x40021000

//******************************************************************
//               Base Addresses for APB2 Peripherals
//******************************************************************

//=============LQFP48

//GPIOA, GPIOB is fully package
#define GPIOA_BASE                            0x40010800
#define GPIOB_BASE                            0x40010C00
//GPIOC, GPIOD is not in  package
#define GPIOC_BASE                            0x40011000
#define GPIOD_BASE                            0x40011400
//EXTI
#define EXTI_BASE                             0x40010400
//AFIO
#define AFIO_BASE                             0x40010000

//******************************************************************
//               Base Addresses for APB1 Peripherals
//******************************************************************



//****************************************************
//               Peripherals Registers
//****************************************************

//-------------------------------------
//      Peripheral Register:GPIO
//-------------------------------------
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_t;

//-------------------------------------
//      Peripheral Register:AFIO
//-------------------------------------
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4 ;
	volatile uint32_t MAPR2;
} AFIO_t;

//-------------------------------------
//      Peripheral Register:EXTI
//-------------------------------------

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_t;

//-------------------------------------
//      Peripheral Register:RCC
//-------------------------------------
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_t;

//*************************************************************
//             Peripherals Address map Registers
//*************************************************************

//********************GPIO Instants********************/
#define GPIOA            (GPIO_t*)(GPIOA_BASE)
#define GPIOB            (GPIO_t*)(GPIOB_BASE)
#define GPIOC            (GPIO_t*)(GPIOC_BASE)
#define GPIOD            (GPIO_t*)(GPIOD_BASE)

//********************RCC********************/
#define RCC_Address      (RCC_t*)(RCC_BASE)

/***********************Clock Enable***************************/
extern  RCC_t*  RCC;
#define E_GPIOA_CLK()    (RCC->APB2ENR |= 1 << 2)
#define E_GPIOB_CLK()    (RCC->APB2ENR |= 1 << 3)
#define E_GPIOC_CLK()    (RCC->APB2ENR |= 1 << 4)


#endif /* STM32F103X6_H_ */
