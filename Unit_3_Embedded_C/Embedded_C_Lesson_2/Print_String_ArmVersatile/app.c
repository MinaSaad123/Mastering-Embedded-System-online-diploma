#include "uart.h"
char string_buffer[100] = "learn-in-depth:<mina>";
void main(void)
{

uart_send_string(string_buffer);


}

