/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"

struct Sstudent
{

char m_name[30];
int m_roll_number;
int m_mark;
}student_1;

void informations_of_student();
void displaying_student_details();
void main()
{
	 informations_of_student();
	 displaying_student_details();

}
void informations_of_student()
{
	printf("Enter information of students\t\n");
	printf("Enter name:");
	fflush(stdin);
	fflush(stdout);

	scanf("%s",&student_1.m_name);
	printf("Enter roll:");
	fflush(stdin);
	fflush(stdout);

    scanf("%d",&student_1.m_roll_number);
    printf("Enter marks;");
    fflush(stdin);
    fflush(stdout);

    scanf("%d",&student_1.m_mark);

}
void displaying_student_details()
{
	printf("Displaing information\t\n");
	printf("name: %s\t\n",student_1.m_name);
	printf("roll: %d\t\n",student_1.m_roll_number);
	printf("marks: %d\t\n",student_1.m_mark);

}
