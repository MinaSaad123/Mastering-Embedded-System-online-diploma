/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina Saad
 * @brief          : Main program body
 ******************************************************************************
 */

//===================================<Include lib>
#include "Stm32f103c6_EXTI_Driver.h"
#include "Stm32f103c6_GPIO_Driver.h"

int flag = 0;
void Clock_Init()
{
	//Init GPIOs clock
	E_GPIOA_CLK_EN();
	E_GPIOB_CLK_EN();

	//Init AFIO clock
	E_AFIO_CLK_EN();
}

void EXTI9_Callback()
{
	int DoesItWork;
}

int main(void)
{
	Clock_Init();

	EXTI_PinConfig EXTI_CFG;

	EXTI_CFG.EXTI_Pin = EXTI9pB9;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_CFG.Trigger = EXTI_Trigger_RISING;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);  //Init my peripherals

	while (1); //Infinite loops

}
