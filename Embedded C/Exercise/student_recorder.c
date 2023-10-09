/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

//Definition of a student record
typedef struct
{
    int rollNumber;
    char    name[100];
    char    branch[50];
    int dob;
    int semister;

}STUDENT_INFO_t;

// Maximum records
int max_record = 10;

// Global Array for student database
STUDENT_INFO_t students[10];

//Functions
// void display_record(void);
// void add_new_record(int *pAddr);
// void delete_record(int *pAddr);

//function prototypes of this program
void display_menu(void);
int read_menu_code(void);
void decode_menu_code(int8_t menu_code);
void display_all_records(STUDENT_INFO_t *record, int8_t max_record);
int check_roll_number(int roll_number, STUDENT_INFO_t *record, int8_t max_record);
int add_new_record(STUDENT_INFO_t *record, int8_t max_record);
int delete_record(STUDENT_INFO_t *record, int8_t max_record);

//starting point of the application
int main ()
{
    int8_t menu_code;
    int8_t app_continue = 1;
    
    printf("Student record management program\n");

     while(app_continue)
     {
		//1. display menu
		display_menu();

		//read the menu code
		menu_code = read_menu_code();

		if(menu_code){
			//Decode the menu code
			decode_menu_code(menu_code);
		}else{
			//end the application if menu_code = 0;
			app_continue = 0;
			printf("Exiting application\n");
		}

     }

    return 0;
}

/*
 * This function displays the menu to the user
 * Please note that 0 is the code to exit this program
 */
void display_menu(void)
{
    printf("Display all records  -->1\n");
    printf("Add new record       -->2\n");
    printf("Delete a record      -->3\n");
    printf("Exit application     -->0\n");
    printf("Enter your option here:");
}

/*
 * This function reads the menu code entered by the user and return the code
 */
int read_menu_code(void)
{
    int menu;
    scanf("%d",&menu);
    return menu;
}

//This function decodes the menu
void decode_menu_code(int8_t menu_code)
{
    int8_t ret;

    switch(menu_code)
    {
        case 1:
        	printf("Displaying all students record\n");
        	display_all_records(students,max_record);
        	break;
        case 2:
			printf("Add a new record\n");
			ret = add_new_record(students,max_record);
			!ret ? printf("Record add unsuccessful\n") : printf("Record added successfully\n");
			break;
        case 3:
			printf("Delete a record\n");
			ret = delete_record(students,max_record);
			ret ? printf("Record deleted successfully\n") : printf("Record not found\n");
			break;
        default:
			printf("Invalid input\n");
    }
}

/*
 * This function displays all the records so far entered by the user
 * in_param[1] : base address of the records
 * in_param[2] : maximum record number maintained by this program
 * Note: if no records found, then this fucntion should print "No records found'
 */

void display_all_records(STUDENT_INFO_t *record, int8_t max_record)
{
    if(record[0].rollNumber==0)
    {
        printf("No records found\n");
        // break;
        // return 0;
    }
    else
    {
        for(int i=0;i<max_record;i++)
        {
            printf("Student rollnumber is    : %d\n",record[i].rollNumber);
            printf("Student name is          : %s\n",record[i].name);
            printf("Student branch is        : %s\n",record[i].branch);
            printf("Student date of birth is : %d\n",record[i].dob);
            printf("Student semister is      : %d\n",record[i].semister);
        }
    }
}

/*
 * This function matches the given roll_numer with the roll numbers of the records by traversing through record node one by one
 * in_param[1]: given roll number
 * in_param[2]: base address of the records
 * in_param[3]: max record number of this program
 * return : 0 for no_match , 1 for match
 */
int check_roll_number(int roll_number, STUDENT_INFO_t *record, int8_t max_record)
{
  
	//TODO

}

/*
 * This function adds a new record by asking various information from the user.
 * before adding a record , function has to identify an empty node
 * Assume a node is empty , if roll number field of node is zero
 * in_param[1]: base address of the records
 * in_param[2]: max record number of this program
 * return values : 0 if add is unsuccessful, 1 if add is successful
 * Note1 : This function should also print "roll number already exist" if roll number entered is already exist in the record
 * Note2 : This function should also print "No space available", if all nodes of the array are occupied
 */
int add_new_record(STUDENT_INFO_t *record, int8_t max_record)
{
    int new_node=0;
    if(record[9].rollNumber!=0)
    {
        printf("No space available\n");
        return 0;
    }
    for(int i=0;i<max_record;i++)
    {
       if(record[i].rollNumber==0)
       {
           new_node = i;
           break;
       }
    }
    printf("Enter student rollnumber         : ");
    scanf("%d",&record[new_node].rollNumber);
    for(int i=0;i<new_node;i++)
    {
        if(record[i].rollNumber == record[new_node].rollNumber)
        {
            printf("Roll number already exist\n");
            return 0;
        }
    }
    printf("Enter student name               : ");
    scanf("%s",record[new_node].name);
    printf("Enter student branch             : ");
    scanf("%s",record[new_node].branch);
    printf("Enter student date of birth      : ");
    scanf("%d",&record[new_node].dob);
    printf("Enter student semister           : ");
    scanf("%d",&record[new_node].semister);
    
    return 1;

}

/*
 * Delete a record.
 * first ask the user to enter the roll number of the student
 * delete a node against that roll number
 * in_param[1]: base address of the records
 * in_param[2]: max record number of this program
 * return values : 0 if delete unsuccessful, 1 if delete successful
 *
 */
int delete_record(STUDENT_INFO_t *record, int8_t max_record)
{
    int dRollnumber,dNode = -1;
    printf("Enter student rollnumber : ");
    scanf("%d",&dRollnumber);
    for(int i=0;i<max_record;i++)
    {
        if(record[i].rollNumber == dRollnumber)
        {
            dNode = i;
        }
    }
    if(dNode == -1)
    {
        printf("No record found\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
