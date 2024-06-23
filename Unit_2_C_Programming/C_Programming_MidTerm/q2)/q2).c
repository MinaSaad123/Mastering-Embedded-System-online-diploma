/*
 * q1).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
#include"math.h"
int main(){
  float sqroot(int x);
   int x;
    printf("please enter a number:");
    fflush(stdin);fflush(stdout);
    scanf("%d",&x);
    printf("%.2f",sqroot(x));

return 0;
}
float sqroot (int x){
float c=sqrt(x);
return c;

}


