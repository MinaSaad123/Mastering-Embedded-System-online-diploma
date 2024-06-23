#include "uart.h"
#define UART0DR *((volatile unsigned char*const)((unsigned char*)0x101f1000))
void uart_send_string(unsigned char* p_tx_string)
{
	//loop to assign characters to uart0
while(*p_tx_string != '\0')
{
	UART0DR = (unsigned char)(*p_tx_string);
	p_tx_string ++;
}
  

}