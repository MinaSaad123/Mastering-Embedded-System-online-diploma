/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
int main(){
int x,y,i;
 int defiter();
printf("please enter the first number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("please enter the second number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);
	for(i=x;i<=y;i++){
	if(defiter(i)==0){
		printf("%d\t",i);
	}
	}


return 0;
}
int defiter(int i){
	int y,b;
	for(y=2;y<=10;y++){
	if(i%y==0){
		 b=1;
		 break;

	}
	else{
		b=0;
		}

	}

	return b;

}

