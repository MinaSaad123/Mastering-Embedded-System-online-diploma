/*
 * q5).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
int num_digits(int);
int main(){
    int x;
    printf("please enter a number:");
    fflush(stdin);fflush(stdout);
    scanf("%d",&x);
    printf("the sum of digits==>%d",num_digits(x));

}
int num_digits(int x){
  int i,c=0;
  // there is logical error here when i make the range  0 to 31 here  a problem i cant detecte it, but when i substracte 1 from 31 it runs correctly
    for(i=0;i<=30;i++){
    if((x^(1<<i))>x) c=c+0;
    else c=c+1;

    }

return c;

}

