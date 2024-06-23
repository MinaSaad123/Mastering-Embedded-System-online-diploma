/*
 * Problem_3.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: HP
 */

#include"stdio.h"
int main()
{
	char str[30];
	char y = 0, i;
	char* strptr = str;
	printf("Pointer :Print a string in reverse order:\t\n------------------\n");
	printf("input a string :");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", str);
	while(*strptr)
	{
	    strptr++;
		y++;
	}
	printf("reverse of string is :");
	for(i = 0;y > i;i++)
	{
		printf("%c", *(strptr - i - 1));
	}
	return 0;
}

