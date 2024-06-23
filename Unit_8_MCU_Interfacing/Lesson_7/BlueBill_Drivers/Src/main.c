/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina Saad
 * @brief          : Main program body
 ******************************************************************************
 *
 */

//---------------------------<Include>
#include "EEPROM_Slave.h"
#include "Stm32f103c6_EXTI_Driver.h"
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103c6_I2C_Driver.h"
#include "Stm32f103c6_RCC_Driver.h"
#include "Stm32f103c6_SPI_Driver.h"
#include "Stm32f103c6_Uart_Driver.h"

int main(void)
{
	unsigned char ch1[7] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
	unsigned char ch2[7] = {0};

	EEPROM_Init();  /*Init EEPROM*/

	//Test Case 1
	EEPROM_Write_NBytes(0xAF, ch1, 7);
    EEPROM_Read_Nbyte(0xAF, ch2, 7);

    while (1);

}
