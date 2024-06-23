/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
void main(){
	int i=0,x=0;
	char c[30],ch;
	printf("Enter the string:");
	fflush(stdin);fflush(stdout);
	gets(c);
	printf("Enter the character to find it frequency:");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	for(i=0;i<30;i++){
	if(ch==c[i]){
	x=x+1;
	}
	else x=x;
	}
	printf("frequency of %c:%d",ch,x);

}

