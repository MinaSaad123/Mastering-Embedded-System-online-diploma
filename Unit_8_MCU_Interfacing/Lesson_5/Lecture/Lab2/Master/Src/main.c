/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina saad
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

//==================================<Include>
#include "Stm32f103c6_EXTI_Driver.h"
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103c6_RCC_Driver.h"
#include "Stm32f103c6_SPI_Driver.h"
#include "Stm32f103c6_Uart_Driver.h"

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                       Generic macros
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
#define MCU_Act_As_Master
//#define MCU_Act_As_Slave

unsigned short int ch = 0;

//========Interrupt CallBack SPI
void SPI_CallBack (	struct S_SPI_IRQ SPI_IRQ)
{
#ifdef MCU_Act_As_Slave
	if (SPI_IRQ.RXE)
	{
		MCAL_SPI_TX_RX(SPI1, &ch, &ch, Disable);
		MCAL_UART_SendData(UART1, &ch, Enable);
	}
#endif

}


//========Interrupt CallBack Uart
void Uart_CallBack(void)
{
#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(UART1, &ch, Disable);

	//Enable Salve
	MCAL_GPIO_WritePin(GPIOA, LOW, GPIO_PIN_4);
    MCAL_SPI_TX_RX(SPI1, &ch, &ch, Enable);
	MCAL_GPIO_WritePin(GPIOA, HIGH, GPIO_PIN_4);
#endif

}

//========GPIO_Init
void Clock_Init()
{
	//=====Enable GPIO Clocks
	E_GPIOA_CLK_EN();
	E_GPIOB_CLK_EN();

	//======Enable AFIO Clock
	E_AFIO_CLK_EN();

	//=====Enable UART Clocks
	//Uart1
	RCC_UART1_CLK_EN();
	//Uart2
	RCC_UART2_CLK_EN();
	//Uart3
	RCC_UART3_CLK_EN();

	//====Enable SPI Clocks
	//SPI1
	E_SPI1_CLK_EN();
	//SPI2
	E_SPI2_CLK_EN();

}

//=====main Function
int main(void)
{
#ifdef MCU_Act_As_Master

	GPIO_Config_t GPIO_Pin;
#endif
	UART_Config Pin;
	SPI_Config SPI_Pin;

	//==Init Clock
	Clock_Init();

	//           ***<UART Config>***
	Pin.UART_BaudRate = UART_BaudRate_115200;
	Pin.HwFlowCTRL = UART_HwFlowCtl_None;
	Pin.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	Pin.P_IRQ_CallBack = Uart_CallBack;
	Pin.Parity = UART_Parity_NONE;
	Pin.Pay_Load_Length = UART_Pay_Load_Length_8bit;
	Pin.Stop_Bits = UART_Stop_Bit1;
	Pin.UART_Mode = UART_Mode_RX_TX;
	MCAL_UART_Init(UART1, &Pin);
	MCAL_UART_GPIO_Set_Pins(UART1);
	//================================================

	//            ***<SPI Config>***
	SPI_Pin.BaudRate_Prescaler = SPI_BaudRate_Prescaler_By8;
	SPI_Pin.Clock_Phase = SPI_2Edge_Transimation_First_Data_Capture;
	SPI_Pin.Clock_Polarity = SPI_Clock_Polarity_High_Idle;
	SPI_Pin.Data_Format = SPI_Data_Format_8bit;
	SPI_Pin.Frame_Format = SPI_Frame_Format_MSB;
	SPI_Pin.NSS = SPI_Communication_DIR_2Lines;

#ifdef MCU_Act_As_Master
	SPI_Pin.Device_Mode = SPI_Device_Mode_Master;
	SPI_Pin.NSS = SPI_NSS_Internal_SOFT_Set;
	SPI_Pin.SPI_IRQ_Enable = SPI_IRQ_Enable_None;
	SPI_Pin.CallBack = (void*)0;

	//Configure NSS Pin as GPIO in SPI1
	GPIO_Pin.GPIO_PinNumber = GPIO_PIN_4;
	GPIO_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	GPIO_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOA, &GPIO_Pin);

	//Disable Slave throughout making it High
	MCAL_GPIO_WritePin(GPIOA, HIGH, GPIO_PIN_4);

#endif

#ifdef MCU_Act_As_Slave
	SPI_Pin.SPI_IRQ_Enable = SPI_IRQ_Enable_Rx_Only;
	SPI_Pin.NSS = SPI_NSS_Hard_Slave;
	SPI_Pin.Device_Mode = SPI_Device_Mode_Slave;
	SPI_Pin.CallBack = SPI_CallBack;
#endif

	MCAL_SPI_Init(SPI1, &SPI_Pin);
	MCAL_SPI_Set_Pin(SPI1);


	while (1)
	{

	}
    return 0;
}
