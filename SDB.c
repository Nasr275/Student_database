#include "SDB.h"
#include "STD.h"


student students[MAX_STUDENTS]; //array of structs of type student with 10 spot registered in case of max students
uint8 numStudents = 3; //A counter to keep track of the number of students in the school that starts with 3 because 3 is the minimum number




/**1-Adding our first three students manually */

void first_three_students()
{
    /**Passing every value manually to each student*/

    students[0].Student_ID=1;
    students[0].Student_year=1;
    students[0].courseIDs[0]=1;
    students[0].courseGrades[0]=89;
    students[0].courseIDs[1]=2;
    students[0].courseGrades[1]=78;
    students[0].courseIDs[2]=3;
    students[0].courseGrades[2]=67;

    students[1].Student_ID=2;
    students[1].Student_year=2;
    students[1].courseIDs[0]=3;
    students[1].courseGrades[0]=66;
    students[1].courseIDs[1]=4;
    students[1].courseGrades[1]=47;
    students[1].courseIDs[2]=5;
    students[1].courseGrades[2]=93;

    students[2].Student_ID=3;
    students[2].Student_year=3;
    students[2].courseIDs[0]=6;
    students[2].courseGrades[0]=88;
    students[2].courseIDs[1]=7;
    students[2].courseGrades[1]=35;
    students[2].courseIDs[2]=8;
    students[2].courseGrades[2]=75;

}





/**2-Function to check if the database is full or not*/
bool SDB_IsFull()
{
    if(numStudents >= MAX_STUDENTS)   //if the number of students exceed the number of students allowed return True
   {
    printf("Database is full\n");
    return true;

   }
printf("The database has free space \n");
return false;
}





/**3-Function to get the current size of the database*/
uint8 SDB_GetUsedSize() {
    printf("Getting used size in database\n");
    printf("Number of students is: \n");
    return numStudents;          //Returning the count of available students in the database
}






/**4-Function to add a new entry in the database*/
bool SDB_AddEntry()
{   /**first we need to check if there is a free space to add a new student*/
    if (SDB_IsFull())    //We use a function we defined earlier to check if the database is full
        {
        printf("Cannot add more students.\n");
        return false;  //exit the function
    }


    student newStudent;    //creating a new struct of type student
    printf("For student number %u please:\n", numStudents+1);
    printf("Enter student ID: ");
    scanf("%u", &newStudent);           //Address points to the first element in the struct
    /**Second step we need to check if this student already exists in the database**/
    if (SDB_IsIdExist(newStudent.Student_ID)) {
        printf("Student with ID %u already exists in the database.\n", newStudent.Student_ID);
        return false;
    }

    printf("Enter student year: ");           // receiving student year
    scanf("%u", &newStudent.Student_year);    // %u is used for unsigned integers


    for (uint32 i = 0; i < 3; i++) {          //receiving course gardes
        printf("Enter course %d ID: ", i + 1);
        scanf("%u", &newStudent.courseIDs[i]);
        printf("Enter course %d grade: ", i + 1);
        scanf("%u", &newStudent.courseGrades[i]);
    }
    /**finally we add our newly created student structure to our database and incrementing the number of students*/
    students[numStudents] = newStudent;
    numStudents++;

    printf("Student added successfully.\n");
    return true;
}






/**5-Function to deleting an entry in our database*/
void SDB_DeleteEntry(uint32 id)
{
    /**The minimum number of students in our database is 3*/
    if(numStudents <= 3)
    {
        printf("sorry we can't delete anymore entries\n");
        return;
    }
    for (uint32 i = 0; i < numStudents; i++) {
        if (students[i].Student_ID == id) {
            /**Shift all elements after the deleted student to the left*/
            for (uint32 j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;     //decrement our student count
            printf("Student with ID %u deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found in the database.\n", id);
}





/**6-Function takes a student ID as a parameter and prints the corresponding student's data if ID does not exist return false*/
bool SDB_ReadEntry(uint32 id) {
    for (uint32 i = 0; i < numStudents; i++)
    {
        if (students[i].Student_ID == id)
        {        /** we check for the right ID*/
            printf("Student ID: %u \n", students[i].Student_ID);
            printf("Year: %u \n", students[i].Student_year);
            for (int j = 0; j < 3; j++)
            {    /**loop to print all courses*/
                printf("Course %u ID: %u\n", j + 1, students[i].courseIDs[j]);
                printf("Course %u grade: %u\n", j + 1, students[i].courseGrades[j]);
            }
            return true;
        }
    }
    printf("Student with ID %u not found in the database.\n", id);
    return false;
}






/**7-Function that prints how many IDs available in the database as well as a list of all these IDs*/
void SDB_GetList(uint8 *count, uint32 *list)    //we received the address passed as parameter in  a pointer
{
    *count = numStudents;        // The number of IDs is equivalent to the number of students
    printf("Number of IDs: %u\n", *count);
    printf("List of IDs: ");
    for (uint32 i = 0; i < numStudents; i++)      // looping over the list and passing the values of the IDs
    {
        list[i] = students[i].Student_ID;
        printf("%u ", list[i]);
    }
    printf("\n");
}







/**8-Function to check the existence of an ID as a main option and used in other functions*/
bool SDB_IsIdExist(uint32 id)
{
    for (int i = 0; i < numStudents; i++)        //looping over the exact number of student available by using numStudents
    {
        if (students[i].Student_ID == id)       //comparing with every id in the database
        {
            printf("ID exists\n");
            return true;
        }
    }
    printf("ID %u is not taken.\n", id);
    return false;
}
