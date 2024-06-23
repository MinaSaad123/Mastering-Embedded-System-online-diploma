/*
 * Student_DataBase_With_Queue.c
 *
 *  Created on: Mina Saad
 *      Author: HP
 */

//--------------------------------------<Include>
#include "Student_DataBase_With_Queue.h"

/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/
/*                           function definition                                   */
/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/

//=========================================================|FIFO_Init_Buf Function|
FIFO_Buf_Status FIFO_Init_Buf (FIFO_t* Init_FIFO_Buf, Sinfo_t* Buf)
{
	//if FIFO is not exist
	if (Buf == NULL)
	{
	  return FIFO_Null;
	}

	Init_FIFO_Buf->base = Buf;
	Init_FIFO_Buf->head = Buf;
	Init_FIFO_Buf->tail = Init_FIFO_Buf->base;

    return FIFO_No_Error;
}

//==============================================|FIFO_Buf_Is_Full Function|
FIFO_Buf_Status FIFO_Buf_Is_Full (FIFO_t* FIFO_Buf)
{
	//check FIFO is full or not
	if (FIFO_Buf->head == FIFO_Buf->base + Width) //yes
	{
		return FIFO_Full;

	} else //no
	{
		return FIFO_No_Error;
	}
}

//==============================================|Find_The_Student_By_First_Name Function|
void Find_The_Student_By_First_Name (FIFO_t* FIFO_Buf)
{
	//is database already Exit
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase does not exist \n");

	} else if (FIFO_Buf_Is_Full(FIFO_Buf) == FIFO_Full) //is database Full
	{
		printf("[ERROR] DataBase is Full\n");

	} else if (FIFO_Buf->head == FIFO_Buf->base) //is database Empty
	{
		printf("[ERROR] No Student in DataBase\n");

	}else 	//check the database
	{
		Sinfo_t* Temp;
		int count = 0;
		char FnameTemp[30];
		Temp = FIFO_Buf->base;
		Dprint("Enter the first name of student:")
		gets(FnameTemp);
		while (Temp < FIFO_Buf->head) //loop to end of database
		{
			//check the first name is correct
			if (!strcmp(Temp->Fname, FnameTemp))
			{
				printf("The Students details are\n");
				printf("The First name is: %s\n", Temp->Fname);
				printf("The Last name is: %s\n", Temp->Lname);
				printf("The Roll number is: %d\n", Temp->roll);
				printf(" The GPA is: %f\n", Temp->GPA);
				printf("Enter the course ID of each course\n");
				printf("The course ID is:%d\n", Temp->Cid[0]);
				printf("The course ID is:%d\n", Temp->Cid[1]);
				printf("The course ID is:%d\n", Temp->Cid[2]);
				printf("The course ID is:%d\n", Temp->Cid[3]);
				count++;
			}
			Temp++;
		}
		//Student is not exit
		if (!count)
		{
			printf("[ERROR] Student can not be found\n");

		} else
		{
			printf("[INFO] find is done successfully\n");
		}
	}
}

//==============================================|Find_The_Student_By_Given_Roll Function|
void Find_The_Student_By_Given_Roll (FIFO_t* FIFO_Buf)
{
	//is database already Exit
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase does not exist \n");

	}else if (FIFO_Buf_Is_Full(FIFO_Buf) == FIFO_Full)	//is database Full
	{
		printf("[ERROR] DataBase is Full\n");

	}else if (FIFO_Buf->head == FIFO_Buf->base) //is database Empty

	{
		printf("[ERROR] No Student in DataBase\n");

	}else 	//check the database

	{
		Sinfo_t* Temp = FIFO_Buf->base;
		int count = 0;
		int Troll;
		Dprint("Enter Roll number:")
		scanf("%d", &Troll);
		while (Temp < FIFO_Buf->head) //loop to end of database
		{
			//check the roll is correct
			if (Temp->roll == Troll)
			{
				printf("The Students details are\n");
				printf("The First name is: %s\n", Temp->Fname);
				printf("The Last name is: %s\n", Temp->Lname);
				printf("The Roll number is: %d\n", Temp->roll);
				printf(" The GPA is: %f\n", Temp->GPA);
				printf("Enter the course ID of each course\n");
				printf("The course ID is:%d\n", Temp->Cid[0]);
				printf("The course ID is:%d\n", Temp->Cid[1]);
				printf("The course ID is:%d\n", Temp->Cid[2]);
				printf("The course ID is:%d\n", Temp->Cid[3]);
				count++;
			}
			Temp++;
		}

		//Student is not exit
		if (!count)
		{
			printf("[ERROR] Student can not be found\n");

		} else
		{
			printf("[INFO] Find is done successfully\n");
		}
	}
}

//==============================================|Find_The_Student_By_First_Name Function|
void Show_All_Information (FIFO_t* FIFO_Buf)
 {
	//database does not exist
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase is not Exist");

	}else if (FIFO_Buf->head == FIFO_Buf->base)	//database is empty
	{
		printf("[ERROR] No Student in DataBase\n");

	}else 	//check
	{

		Sinfo_t* Temp = FIFO_Buf->base;
		while (Temp < FIFO_Buf->head)
		{
			printf("The Students details are\n");
			printf("The First name is: %s\n", Temp->Fname);
			printf("The Last name is: %s\n", Temp->Lname);
			printf("The Roll number is: %d\n", Temp->roll);
			printf(" The GPA is: %f\n", Temp->GPA);
			printf("Enter the course ID of each courses\n");
			printf("The course ID is:%d\n", Temp->Cid[0]);
			printf("The course ID is:%d\n", Temp->Cid[1]);
			printf("The course ID is:%d\n", Temp->Cid[2]);
			printf("The course ID is:%d\n", Temp->Cid[3]);
			printf("The course ID is:%d\n\n", Temp->Cid[4]);
			Temp++;
		}
		printf("[INFO] View is done successfully\n");
	}
}

//==============================================|Count_Of_Students Function|
void Count_Of_Students (FIFO_t* FIFO_Buf)
{
	//database does not exist
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase is not Exist");

	} else if (FIFO_Buf->head == FIFO_Buf->base)	//database is empty
	{
		printf("[ERROR] No Student in DataBase\n");

	} else 	//check
	{
		Dprint("\n[info] The Total Number of students is : %d", FIFO_Buf->StudentNumber);
		Dprint("\n[info] you can add up to 50 student ");
		Dprint("\n[info] you can add %d more students ", 50 - FIFO_Buf->StudentNumber);
	}
}

//==============================================|Delete_Student Function|
void Delete_Student (FIFO_t* FIFO_Buf)
{   
	//Assumption that database always has students
	int Delt_Roll, Flag = 0;

	Dprint("Enter Roll you want to delete:")
	scanf("%d", &Delt_Roll); /*input Roll*/

	//is database already Exit
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase does not exist \n");

	} else if (FIFO_Buf->head == FIFO_Buf->base) //is Roll exist already in database
	{
		printf("[ERROR] No Student in DataBase\n");

	} else if (Roll_is_Exist_OrNot(FIFO_Buf, Delt_Roll) == 1)
	{
		//swapping students details because of deleted student
		Sinfo_t* Temp = FIFO_Buf->base;
	    swapping(FIFO_Buf, Temp);
		FIFO_Buf->StudentNumber--;
		Flag++;
		printf("[INFO] Delete is done successfully\n");
		FIFO_Buf->tail = FIFO_Buf->base;
	}

	//check database
	if (!Flag)
	{
		printf("[ERROR] The Roll is Wrong\n");
	}
}

//==============================================|swapping Function|
void swapping (FIFO_t* FIFO_Buf, Sinfo_t* CurrentStudent)
{
	Sinfo_t* NextStudent = CurrentStudent + 1;
	while (NextStudent <= FIFO_Buf->head)
	{
		*CurrentStudent = *NextStudent;
		CurrentStudent = NextStudent;
		NextStudent++;
	}
	FIFO_Buf->head--;
}

//==============================================|Add_Student_Details_manually Function|
void Add_Student_Details_manually (FIFO_t* FIFO_Buf)
{

	int Flag= 0;
	int Entr_Roll;

	//is database already Exit
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase does not exist \n");

	}else if (FIFO_Buf_Is_Full(FIFO_Buf) == FIFO_Full)	//is database Full
	{
		printf("[ERROR] DataBase is Full\n");

	} else
	{
		Dprint("Enter the Number of Roll:");
		scanf("%d", &Entr_Roll);
		//check Roll exist or not
		if (Roll_is_Exist_OrNot(FIFO_Buf, Entr_Roll) == 1)
		{
			printf("[ERROR] Roll is Exist already\n");
			Flag++;
		}

		if (!Flag)
		{
			Sinfo_t* Temp;
			Temp = FIFO_Buf->head;
			Dprint("The Students details are\n")
			Dprint("The First name is:")
			gets(Temp->Fname);
			Dprint("The Last name is:")
			gets(Temp->Lname);
			Temp->roll = Entr_Roll;
			Dprint(" The GPA is:")
			scanf("%f", &(Temp->GPA));
			Dprint("Enter the course ID of each course\n")
			Dprint("The first course ID is:")
			scanf("%d", &(Temp->Cid[0]));
			Dprint("The secound course ID is:")
			scanf("%d", &(Temp->Cid[1]));
			Dprint("The third course ID is:")
			scanf("%d", &(Temp->Cid[2]));
			Dprint("The fourth course ID is:")
			scanf("%d", &(Temp->Cid[3]));
			Dprint("The fifth course ID is:")
			scanf("%d", &(Temp->Cid[4]));
			printf("[INFO] Add student is done successfully\n");
			printf("---------------------------------------------\n");
			FIFO_Buf->StudentNumber++;
			printf("[INFO] The total number of student is:%d\n", FIFO_Buf->StudentNumber);
			printf("[INFO] You can add up to 50\n");
			printf("[INFO] You can add %d\n", Width - FIFO_Buf->StudentNumber);
			FIFO_Buf->head++;
		}
		FIFO_Buf->tail = FIFO_Buf->base;
	}
}

//==============================================|Update_Student Function|
void Update_Student (FIFO_t* FIFO_Buf)
{
	//is database already Exit
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase does not exist \n");
	}else if (FIFO_Buf->head == FIFO_Buf->base) //is database Empty
	{
		printf("[ERROR] No Student in DataBase\n");

	} else
	{
		int Roll;
		Dprint("Enter Roll for Student you want to Updata:")
		scanf("%d", &Roll);
		if (Roll_is_Exist_OrNot(FIFO_Buf, Roll) == 1)
		{
			int choice, Nroll;
			printf("1. First name\n2. Last name\n3. Roll Number\n4. GPA\n5. Courses\n");
			Dprint("Enter your choice:")
			scanf("%d", &choice);
			switch (choice)
			{
			//no default because of assumption that the User will not miss THe choices
			case 1:
				Dprint("Enter the new First name:")
				gets(FIFO_Buf->tail->Fname);
				break;
			case 2:
				Dprint("Enter the new Last name: ")
				gets(FIFO_Buf->tail->Lname);
				break;
			case 3:
				Dprint("Enter the new Roll:")

				scanf("%d", &Nroll);
				if (Roll_is_Exist_OrNot(FIFO_Buf, Roll) == 0)
				{
					FIFO_Buf->tail->roll = Nroll;

				} else
				{
					printf("[ERROR] This Roll number is  already taken\n");
				}
				break;

			case 4:
				Dprint("Enter the new GPA:")
				scanf("%f", &(FIFO_Buf->tail->GPA));
				break;
			case 5:
				Dprint("    ------\n")
				;
				Dprint("Enter the new course\n")
				printf(
						"1. first course\n2. second course\n3. third course\n4. fourth course\n5. fifth course\n ");
				Dprint("Enter your choice:")
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:
					Dprint("Enter the First course:")
					scanf("%d", &FIFO_Buf->tail->Cid[0]);
					break;
				case 2:
					Dprint("Enter the second course:")
					scanf("%d", &FIFO_Buf->tail->Cid[1]);
					break;
				case 3:
					Dprint("Enter the third course:")
					scanf("%d", &FIFO_Buf->tail->Cid[2]);
					break;
				case 4:
					Dprint("Enter the fourth course:")
					scanf("%d", &FIFO_Buf->tail->Cid[3]);
					break;
				case 5:
					Dprint("Enter the fifth course:")
					scanf("%d", &FIFO_Buf->tail->Cid[4]);
					break;
				}
				break;
			}
			FIFO_Buf->tail = FIFO_Buf->base;
			printf("[INFO] Task has been End\n");
		} else
		{
			printf("[ERROR] Roll is not Exist\n");
		}
		FIFO_Buf->tail = FIFO_Buf->base;
	}
}

//==============================================|Roll_is_Exist_OrNot Function|
int Roll_is_Exist_OrNot (FIFO_t* FIFO_Buf, int Roll)
{
	while (FIFO_Buf->tail < FIFO_Buf->head)
	{
		if (FIFO_Buf->tail->roll == Roll)
		{
			return 1;
		}
		FIFO_Buf->tail++;
	}
	FIFO_Buf->tail--;
	return 0;
}

//==============================================|Find_The_Students_Registered_In_Course Function|
void Find_The_Students_Registered_In_Course (FIFO_t* FIFO_Buf)
{ 
    //Assumption that that User never miss course ID
	printf("choose one of courses (10, 15, 20, 25, 30)\n");
	int Course_ID, i, count = 0;
	Dprint("Enter your choice:")
	scanf("%d", &Course_ID);
	Sinfo_t* Temp = FIFO_Buf->base;
	while (Temp <= FIFO_Buf->head)
	{
		for (i = 0;i <= 4;i++)
		{
           if (Temp->Cid[i] == Course_ID)
           {
        	   printf("The Students details are\n");
        	   printf("The First name is: %s\n", Temp->Fname);
        	   printf("The Last name is: %s\n", Temp->Lname);
        	   printf("The Roll number is: %d\n", Temp->roll);
        	   printf(" The GPA is: %f\n", Temp->GPA);
        	   printf("Enter the course ID of each course\n");
        	   printf("The course ID is:%d\n", Temp->Cid[0]);
        	   printf("The course ID is:%d\n", Temp->Cid[1]);
        	   printf("The course ID is:%d\n", Temp->Cid[2]);
        	   printf("The course ID is:%d\n", Temp->Cid[3]);
        	   printf("          ---------------\n");
        	   count++;
           }
		}
		Temp++;
	}
	if (count)
	{
		printf("The total Students enrolled in course:%d\n", count);
	}else
	{
		printf("There is not student enrolled in course\n");
	}
}

//==============================================|Add_Student_Details_From_File Function|
void Add_Student_Details_From_File (FIFO_t* FIFO_Buf)
{
	//is database already Exit
	if (!FIFO_Buf->base || !FIFO_Buf->tail || !FIFO_Buf->head)
	{
		printf("[ERROR] DataBase does not exist \n");

	}else if (FIFO_Buf_Is_Full(FIFO_Buf) == FIFO_Full)	//is database Full
	{
		printf("[ERROR] DataBase is Full\n");

	}else
	{
		FILE* Students_file = fopen("students_data.txt", "r");
		if (Students_file == NULL)
		{
			printf("[ERROR] This File is not Valid\n");
		} else
		{
			Sinfo_t* Temp = FIFO_Buf->head;
			int Flag = 0;
			//loop until end of lines in files
			while (!feof(Students_file))
			{
				//stores value in one step
				fscanf(Students_file, "%d %s %s %f %d %d %d %d %d", &Temp->roll, Temp->Fname, Temp->Lname, &Temp->GPA, &Temp->Cid[0], &Temp->Cid[1], &Temp->Cid[2], &Temp->Cid[3], &Temp->Cid[4]);

				if (Roll_is_Exist_OrNot(FIFO_Buf, Temp->roll) == 1)
				{
					FIFO_Buf->tail = FIFO_Buf->base;
					printf("[ERROR] the student roll is already exist\n");

				} else
				{
					Dprint("[INFO] Add Student %s is done successfully\n", Temp->Fname)
					FIFO_Buf->StudentNumber++;
					FIFO_Buf->head++;
					Flag++;
					Temp = FIFO_Buf->head;
				}
			}
		}
		fclose(Students_file);
		Dprint("[INFO] End of task\n")
	}
}

