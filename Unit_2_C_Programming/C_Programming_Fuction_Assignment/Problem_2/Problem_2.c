/*
 * Problem_2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
facto(int);
int main(){

int x;
printf("please enter the factorial number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("%d",facto(x));
}
int facto(int x){

if(x!=1)
return x*facto(x-1);

}


