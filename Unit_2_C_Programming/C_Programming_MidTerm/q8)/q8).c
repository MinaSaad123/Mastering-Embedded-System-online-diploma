/*
 * q8).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"

int main(){
void inverse(int);
int x;
printf("please enter number:");
fflush(stdin);fflush(stdout);
scanf("%d",&x);
inverse(x);
}
void inverse(int x){
  int i,arr[x],c=x-1;
for(i=0;i<x;i++){
printf("please enter:");
 fflush(stdin);fflush(stdout);
scanf("%d",&arr[i]);
}
here:
printf("%d",arr[c]);
c--;
if(c!=-1){
goto here ;
}


}
