/*
 * Problem_5.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include"stdio.h"

void main(){

char x;
int y;
printf("enter a character:");
fflush(stdin);fflush(stdout);
scanf("%c",&x);
y='x';
if(y<=90&&y>66||y>=97&&y<=122){
	printf("%c is an alphabet",x);
}
else printf("%c is not an alphabet",x);

}
