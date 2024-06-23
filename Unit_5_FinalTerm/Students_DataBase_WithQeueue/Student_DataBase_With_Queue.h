/*
 * Student_DataBase_With_Queue.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef STUDENT_DATABASE_WITH_QUEUE_H_
#define STUDENT_DATABASE_WITH_QUEUE_H_
/*
 * student_information_mangement_system.h
 *
 *  Created on: 
 *      Author: HP
 */

#ifndef STUDENT_INFORMATION_MANGEMENT_SYSTEM_H_
#define STUDENT_INFORMATION_MANGEMENT_SYSTEM_H_

/*************************************************************************************************/
/*************i Try to do his project without count in FIFO element to get it harder**************/
/*************************************************************************************************/

//include lib
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//macros
#define Width 50
#define Dprint(...) {printf(__VA_ARGS__);\
	                 fflush(stdin);\
                     fflush(stdout);\
                    }
//typedef student details
typedef struct
{
	char Fname[30];
	char Lname[30];
	int roll;
	float GPA;
	int Cid[10];
}Sinfo_t;

//typedef FIFO
typedef struct
{
	Sinfo_t* base;
	Sinfo_t* tail;
	Sinfo_t* head;
	int StudentNumber;

}FIFO_t;

//typedef FIFO status
typedef enum
{
	FIFO_Empty,
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Null
}FIFO_Buf_Status;

/**************function prototype*******************/

//for students
void Add_Student_Details_From_File(FIFO_t* FIFO_Buf);
void Add_Student_Details_manually(FIFO_t* FIFO_Buf);
void Find_The_Student_By_Given_Roll(FIFO_t* FIFO_Buf);
void Find_The_Student_By_First_Name(FIFO_t* FIFO_Buf);
//courses 10, 15, 20, 25, 30, 35
void Find_The_Students_Registered_In_Course(FIFO_t* FIFO_Buf);// assumption that that User never miss course ID
void Count_Of_Students(FIFO_t* FIFO_Buf);
void Delete_Student(FIFO_t* FIFO_Buf);
void Update_Student(FIFO_t* FIFO_Buf);
void Show_All_Information(FIFO_t* FIFO_Buf);
void swapping(FIFO_t* FIFO_Buf, Sinfo_t* CurrentStudent);
int Roll_is_Exist_OrNot(FIFO_t* FIFO_Buf, int Roll);


//for FIFO
FIFO_Buf_Status FIFO_Init_Buf(FIFO_t* Init_FIFO_Buf,Sinfo_t* Buf);
FIFO_Buf_Status FIFO_Buf_Is_Full(FIFO_t* FIFO_Buf);


#endif /* STUDENT_INFORMATION_MANGEMENT_SYSTEM_H_ */



#endif /* STUDENT_DATABASE_WITH_QUEUE_H_ */
