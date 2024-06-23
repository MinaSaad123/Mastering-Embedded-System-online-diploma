/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
void main(){
int a;
printf("Enter a integer you want to check:");
fflush(stdin);fflush(stdout);
scanf("%d",&a);
if(a%2==0){
	printf("%d is even",a);


}
else printf("%d is odd",a);

}


