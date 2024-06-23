/*
 * Problem_3.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"

int main(){
void inverse();

	printf("enter any string:");
	fflush(stdin);fflush(stdout);
inverse();
	return 0;
}
void inverse(){

	char c;
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	if(c!='\n')
	{
inverse();
printf("%c",c);
	}



}

