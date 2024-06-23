/*
 * Uart.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//==========Include
#include "Uart.h"

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//    Generic  Funtion Pointer
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
void (*G_CallBack[2])();

/**************************Function Definition********************************/

//=======MCAL_Uart_Init Function
void MCAL_Uart_Init ()
{
	//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*Configuration
	UBRRL = 51;                //for 9600 baud rate
	Reset_Bit(UCSRC, UMSEL);   //Make it asynchronous(Default)
	Reset_Bit(UCSRC, UPM1);    //Make Parity Disabled(Default)
	Reset_Bit(UCSRA, U2X);     //Make double off(Default)
	Reset_Bit(UCSRC, USBS);    //Make Stop 1-Bit(Default)

    /*********Make transmitting 8-Bit******/
	Set_Bit(UCSRC, UCSZ0);
	Set_Bit(UCSRC, UCSZ1);
	Reset_Bit(UCSRB, UCSZ2);

	//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*Enable
	Set_Bit(UCSRB, TXEN);      //Make Transmitter Enabled
	Set_Bit(UCSRB, RXEN);      //Make Receiver Enabled

}

//======MCAL_ENR_DIS_Interrupt Function
void MCAL_Uart_ENR_DIS_Interrupt (uint8_t IRQ)
{
	if (IRQ == Enable)
	{
		Set_Bit(UCSRB, RXCIE);  //Enable  transmitter Interrupt

		//Set_Bit(UCSRB, RXCIE); //Enable  Receiver Interrupt

		SREG |= (1 << 7);      //Enable Global Interrupt

	} else
	{
		Reset_Bit(UCSRB, RXCIE);  //Disable  transmitter Interrupt

		Reset_Bit(UCSRB, RXCIE);  //Disable  Receiver Interrupt

		SREG &= ~(1 << 7);        //Disable Global Interrupt

	}
}

//=======MCAL_Uart_Send Function
void MCAL_Uart_Send (uint8_t Data)
{
	while ( !( Read_Bit(UCSRA, UDRE) ) );  //To make sure the Buffer is not Empty

	UDR = Data;
}

//=======MCAL_Uart_Receive Function
uint8_t MCAL_Uart_Receive ()
{
	while ( !( Read_Bit(UCSRA, RXC) ) );  //To make sure the Buffer is not Empty

	return (uint8_t)UDR;
}

//=======MCAL_Uart_Send_String Function
void MCAL_Uart_Send_String (uint8_t* Pstr)
{
	 while ( *Pstr != 0 )
	 {
		 MCAL_Uart_Send(*Pstr);
		 Pstr++;
	 }
}

//=======MCAL_Uart_Receive_String Function
uint8_t MCAL_Uart_Receive_String ()
{
	uint8_t *Ptr = (uint8_t*)&UDR;

	while ( *Ptr != 0)
	{
		while ( ( Read_Bit(UCSRA, RXC) ) );
		return UDR;
	}
	return 0;
}

//=======MCAL_Send_Int Function
void MCAL_Send_Int (uint32_t Data )
{
	uint8_t *Ptr = (uint8_t*)&Data;

	//Send Data
	MCAL_Uart_Send(Ptr[0]);
	MCAL_Uart_Send(Ptr[1]);
	MCAL_Uart_Send(Ptr[2]);
	MCAL_Uart_Send(Ptr[3]);

}

//=======MCAL_Receive_Int Function
uint32_t MCAL_Receive_Int ()
{
	uint8_t Data = 0;
	uint8_t* Ptr = &Data;

	//Receive Data
	Ptr[0] = MCAL_Uart_Receive();
	Ptr[1] = MCAL_Uart_Receive();
	Ptr[2] = MCAL_Uart_Receive();
	Ptr[3] = MCAL_Uart_Receive();

	return Data;

}

ISR(USART_RXC_vect)
{
	G_CallBack[0]();
}

ISR(USART_TXC_vect)
{
	G_CallBack[1]();
}

