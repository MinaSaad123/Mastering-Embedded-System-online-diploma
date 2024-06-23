/*
 * Problem_6.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
void main(){
int x,y=1;
printf("Enter an integer:");
fflush(stdin);fflush(stdout);
scanf("%d",&x);
	if(x<1){
		printf("ERROR!! factorial of negative number doesnt exsit");
	}
	else{
		for(int i=1;i<=x;i++){
			y=y*i;
		}printf("%d",y);
	}


}
