/*
 * q1).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include <stdio.h>

int main(){
    void rev(int);
    int x;
    printf("Enter the number: ");
    fflush(stdin);fflush(stdout);
    scanf("%d", &x);
    rev(x);
    return 0;
}
void rev(int x){
    int y,z=0;
    while (x!=0){
        y=x%10;
        z=z+y;
        x=x/10;
    }
    printf("The sum of number is: %d", z);
}
