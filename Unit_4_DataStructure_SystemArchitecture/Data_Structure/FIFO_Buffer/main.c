/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "FIFO_Buffer.h"
FIFO_buf_t UART_buffer;
int main ()
{
	int i;
	//init buffer address
	element_type* buffer = (element_type*)malloc(width * sizeof(element_type));
	element_type temp;
	//init function calling
	FIFO_buf_init(&UART_buffer, buffer);
	printf("******enqueue buffer***** \n");
    for(i = 0; i < 8;++i)
    {   //enqueue function calling
    	if(FIFO_buf_enqueue(&UART_buffer, i) == FIFO_no_error)
    	printf("enqueue is done(%d)\n",i);

    }
    printf("**********done**********\n\n");
    //print function calling
    FIFO_print_buffer(&UART_buffer);
    printf("******dequeue buffer*****\n");
    for(i = 0; i < 8;++i)
    {
    	//dequeue function calling
    	if(FIFO_buf_dequeue(&UART_buffer, &temp) == FIFO_no_error)
    	printf("dequeue is done(%d)\n", temp);

    }
    printf("**********done**********\n");
 	return 0;
}
