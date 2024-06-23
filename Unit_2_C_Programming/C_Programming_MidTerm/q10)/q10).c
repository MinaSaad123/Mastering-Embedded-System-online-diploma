/*
 * q10).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"
int main(){
    int max(int);
int x;
printf("please enter the number:");
fflush(stdin);fflush(stdout);
scanf("%d",&x);
printf("the max size ==> %d",max(x));
}
int max(int x){
int c=0,v=0,i;
for(i=0;i<=31;i++){
if((x^(1<<i))<x){
   c+=1;
}
else c=0;
 if(v<c) v=c;
}
return v;
}
