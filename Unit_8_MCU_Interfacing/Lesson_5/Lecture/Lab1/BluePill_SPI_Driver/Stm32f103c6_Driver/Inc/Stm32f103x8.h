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
//               NVIC Registers in Cortex M3
//******************************************************************
#define NVIC_ISER0            *(volatile uint32_t*)(NVIC_BASE + 0x0)
#define NVIC_ISER1            *(volatile uint32_t*)(NVIC_BASE + 0x4)
#define NVIC_ISER2            *(volatile uint32_t*)(NVIC_BASE + 0x8)
#define NVIC_ICER0            *(volatile uint32_t*)(NVIC_BASE + 0x80)
#define NVIC_ICER1            *(volatile uint32_t*)(NVIC_BASE + 0x84)
#define NVIC_ICER2            *(volatile uint32_t*)(NVIC_BASE + 0x88)

//******************************************************************
//               Base Addresses for APB2 Peripherals
//******************************************************************

//=============LQFP48

//===GPIOA, GPIOB is fully package
#define GPIOA_BASE                            0x40010800
#define GPIOB_BASE                            0x40010C00

//===GPIOC, GPIOD is not in  package
#define GPIOC_BASE                            0x40011000
#define GPIOD_BASE                            0x40011400

//===RCC
#define RCC_BASE                              0x40021000
//===AFIO
#define AFIO_BASE                             0x40010000

//===EXTI
#define EXTI_BASE                             0x40010400


//===NVIC
#define NVIC_BASE                             0xE000E100

//=======Uart2
#define UART2_BASE                           0x40004400UL

//=======Uart3
#define UART3_BASE                           0x40004800UL

//=======SPI1
#define SPI1_BASE              		         0x40013000

//******************************************************************
//               Base Addresses for APB1 Peripherals
//******************************************************************


//=======Uart1
#define UART1_BASE                           0x40013800UL

//=======SPI2
#define SPI2_BASE		                     0x40003800


//****************************************************
//               Peripherals Registers
//****************************************************

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//      Peripheral Register:GPIO
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
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

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//      Peripheral Register:AFIO
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[3];
	volatile uint32_t MAPR2;
} AFIO_t;

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//      Peripheral Register:EXTI
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_t;

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//      Peripheral Register:UART
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}UART_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t	CR1;
	volatile uint32_t	CR2;
	volatile uint32_t	SR;
	volatile uint32_t	DR;
	volatile uint32_t	CPCRP;
	volatile uint32_t	RXCRCR;
	volatile uint32_t	TXCRCR;
	volatile uint32_t	I2SCFGR;
	volatile uint32_t	I2SPR;
}SPI_t;

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//      Peripheral Register:RCC
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
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

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//             Peripherals Address map Registers
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

//********************GPIO Instants********************
#define GPIOA            ((GPIO_t *)(GPIOA_BASE))
#define GPIOB            ((GPIO_t *)(GPIOB_BASE))
#define GPIOC            ((GPIO_t *)(GPIOC_BASE))
#define GPIOD            ((GPIO_t *)(GPIOD_BASE))

//********************UART Instants*******************
#define UART1           ((UART_t*)(UART1_BASE))
#define UART2           ((UART_t*)(UART2_BASE))
#define UART3           ((UART_t*)(UART3_BASE))

//********************SPI Instants*******************
#define SPI1            ((SPI_t*)(SPI1_BASE))
#define SPI2            ((SPI_t*)(SPI2_BASE))

//*******************EXTI********************
#define EXTI             ((EXTI_t*)(EXTI_BASE))

//********************RCC*********************
#define RCC              ((RCC_t*)(RCC_BASE))

//***********************Clock Enable***************************
//======Enable GPIO Clock
#define E_GPIOA_CLK_EN()    (RCC->APB2ENR |= 1 << 2)
#define E_GPIOB_CLK_EN()    (RCC->APB2ENR |= 1 << 3)
#define E_GPIOC_CLK_EN()    (RCC->APB2ENR |= 1 << 4)

//======Enable AFIO
#define E_AFIO_CLK_EN()      (RCC->APB2ENR |= 1)

//========================<Enable SPIs Clocks>
//SPI1
#define E_SPI1_CLK_EN()      (RCC->APB2ENR |= (1 << 12))
//SPI2
#define E_SPI2_CLK_EN()      (RCC->APB2ENR |= (1 << 14))

//========================<Disable SPIs Clocks>
//SPI1
#define E_SPI1_CLK_DIS()      (RCC->APB2ENR &= ~(1 << 12))
//SPI2
#define E_SPI2_CLK_DIS()      (RCC->APB1ENR &= ~(1 << 14))

//======Enable UART Clock

//UART1
#define RCC_UART1_CLK_EN() (RCC->APB2ENR |= 1 << 14)

//(UART2-UART3)
#define RCC_UART2_CLK_EN() (RCC->APB1ENR |= 1 << 17)
#define RCC_UART3_CLK_EN() (RCC->APB1ENR |= 1 << 18)

//======Reset UART Clock

//UART1
#define RCC_UART1_Reset()  (RCC->APB2RSTR |= 1 << 14)

//(UART2-UART3)
#define RCC_UART2_Reset()  (RCC->APB1RSTR |= 1 << 17)
#define RCC_UART3_Reset()  (RCC->APB1RSTR |= 1 << 18)


//=====================
//        IVT
//=====================

//EXTI
#define EXTI0_IRQ        6
#define EXTI1_IRQ        7
#define EXTI2_IRQ        8
#define EXTI3_IRQ        9
#define EXTI4_IRQ        10
#define EXTI5_IRQ        23
#define EXTI6_IRQ        23
#define EXTI7_IRQ        23
#define EXTI8_IRQ        23
#define EXTI9_IRQ        23
#define EXTI10_IRQ       40
#define EXTI11_IRQ       40
#define EXTI12_IRQ       40
#define EXTI13_IRQ       40
#define EXTI14_IRQ       40
#define EXTI15_IRQ       40

//UART
#define UART1_IRQ       37
#define UART2_IRQ       38
#define UART3_IRQ       39

//SPI
#define SPI1_IRQ        35
#define SPI2_IRQ        36

//***************************NVIC Enable/disabled****************************

//========Enable EXTI NVIC
#define NVIC_IRQ6_EXTI0_Disable				(NVIC_ICER0 |= (1 << 6))
#define NVIC_IRQ7_EXTI1_Disable				(NVIC_ICER0 |= (1 << 7))
#define NVIC_IRQ8_EXTI2_Disable				(NVIC_ICER0 |= (1 << 8))
#define NVIC_IRQ9_EXTI3_Disable				(NVIC_ICER0 |= (1 << 9))
#define NVIC_IRQ10_EXTI4_Disable			(NVIC_ICER0 |= (1 << 10))
#define NVIC_IRQ23_EXTI5_9_Disable			(NVIC_ICER0 |= (1 << 23))
#define NVIC_IRQ40_EXTI10_15_Disable		(NVIC_ICER1 |= (1 << 8))

//========Enable NVIC
#define NVIC_IRQ6_EXTI0_Enable				(NVIC_ISER0 |= (1 << 6))
#define NVIC_IRQ7_EXTI1_Enable				(NVIC_ISER0 |= (1 << 7))
#define NVIC_IRQ8_EXTI2_Enable				(NVIC_ISER0 |= (1 << 8))
#define NVIC_IRQ9_EXTI3_Enable				(NVIC_ISER0 |= (1 << 9))
#define NVIC_IRQ10_EXTI4_Enable				(NVIC_ISER0 |= (1 << 10))
#define NVIC_IRQ23_EXTI5_9_Enable			(NVIC_ISER0 |= (1 << 23))
#define NVIC_IRQ40_EXTI10_15_Enable			(NVIC_ISER1 |= (1 << 8))

//=========Enable UART NVIC
#define NVIC_IRQ37_UART1_15_Enable			NVIC_ISER1 |= (1 << (UART1_IRQ - 32))
#define NVIC_IRQ38_UART2_15_Enable			NVIC_ISER1 |= (1 << (UART2_IRQ - 32))
#define NVIC_IRQ39_UART3_15_Enable			NVIC_ISER1 |= (1 << (UART3_IRQ - 32))

//=========Disable UART NVIC
#define NVIC_IRQ37_UART1_15_Disable		    NVIC_ICER1 |= (1 << (UART1_IRQ - 32))
#define NVIC_IRQ38_UART2_15_Disable	       	NVIC_ICER1 |= (1 << (UART2_IRQ - 32))
#define NVIC_IRQ39_UART3_15_Disable 		NVIC_ICER1 |= (1 << (UART3_IRQ - 32))

//=========<Enable SPI NVIC>
#define NVIC_IRQ37_SPI1_Enable			    NVIC_ISER1 |= (1 << (SPI1_IRQ - 32))
#define NVIC_IRQ37_SPI2_Enable			    NVIC_ISER1 |= (1 << (SPI2_IRQ - 32))

//=========<Disable SPI NVIC>
#define NVIC_IRQ37_SPI1_Disable		        NVIC_ICER1 |= (1 << (SPI1_IRQ - 32))
#define NVIC_IRQ37_SPI2_Disable		        NVIC_ICER1 |= (1 << (SPI2_IRQ - 32))
//================================================================================

//======Enumeration
enum  Polling_Mechansim
{
	Disable,
	Enable
};


#endif /* STM32F103X6_H_ */
