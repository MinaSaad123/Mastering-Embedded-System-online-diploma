/*
 * Problem_2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
void main(){
char c[30];
	int i=0;
	printf("Enter a string:");
	fflush(stdin);fflush(stdout);
	gets(c);
	for(i=0;c[i]!='\0';i++);
	printf("string length:%d",i);

}



