/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "LIFO_Buffer.h"
 LIFO_buf_t UART_lifo;
 element_type temp;
int main ()
{
	element_type *buffer = (element_type *)malloc(width * sizeof (element_type));
	LIFO_buf_init(&UART_lifo, buffer, width);
	int i;
	for (i = 0;i < 7;++i)
	{
		if(LIFO_buf_push_item(&UART_lifo, i) == LIFO_no_error)
		printf("lifo item push:%d \n", i);
	}
	for (i = 0;i < 7;++i)
	{
		if(LIFO_buf_pop_item(&UART_lifo, &temp) == LIFO_no_error)
		printf ("uart lifo pop:%d \n",temp);
	}



return 0;
}

