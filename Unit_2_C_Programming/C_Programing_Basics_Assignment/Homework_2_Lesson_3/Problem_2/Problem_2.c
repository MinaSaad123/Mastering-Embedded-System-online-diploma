/*
 * Problem_2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"
void main(){
char a;
printf("Enter an alphabet:");
fflush(stdin);fflush(stdout);
scanf("%c",&a);
if(a=='a'||a=='o'||a=='i'||a=='u'||a=='e'){
	printf("%c is a vowel",a);


}
else printf("%c is consonant",a);

}


