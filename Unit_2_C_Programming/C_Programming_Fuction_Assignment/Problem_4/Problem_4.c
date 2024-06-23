/*
 * Problem_4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
int main(){
	int power();
	int x,y;
	printf("please enter the power number:");
		fflush(stdin);fflush(stdout);
		scanf("%d",&x);
		printf("please enter the number:");
			fflush(stdin);fflush(stdout);
			scanf("%d",&y);
			printf("%d",power(x,y));
return 0;
}
int power(int x,int y){
	if (y!=0){
	return x*power(x,y-1);

	}
return 1;

}
