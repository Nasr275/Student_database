#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"


 uint32 id;                  /**The id that the user will be entering to read,add or delete an entry*/
 uint8 count;                /**How many IDs available in our database*/
 uint32 list[MAX_STUDENTS];  /**A list of integers to store all student IDs with a max limit of 10*/

void SDB_APP()
{ first_three_students(); /**Adding our mandatory minimum number of students*/
  uint32 choice;

  do    /**We used a do while loop as declaring an integer always sets it to zero which will case the skipping of a traditional while loop*/
  {
     printf("To add entry, enter 1\n");
     printf("To get used size in database, enter 2\n");
     printf("To read student data, enter 3\n");
     printf("To get the list of all student IDs, enter 4\n");
     printf("To check if the ID exists, enter 5\n");
     printf("To delete student data, enter 6\n");
     printf("To check is database is full, enter 7\n");
     printf("To exit, enter 0\n");
     scanf("%d",&choice);
     SDB_action(choice);
     if(choice!=0)
        {
         printf("would you like another service?\n");
        }
  }
  while(choice != 0);
}






void SDB_action(uint8 choice)
{


 switch (choice)
 {
 case 1:
     SDB_AddEntry();
     break;
 case 2:
     printf("%hhu \n", SDB_GetUsedSize());
     break;
 case 3:
     printf("Please enter student ID to read entry: \n");
     scanf("%u",&id);        //we have to scan the id every time so to overwrite the old value
     SDB_ReadEntry(id);
     break;
 case 4:
     SDB_GetList(&count, list);
     break;
 case 5:
     printf("Please enter student Id:");
     scanf("%u",&id);        //we have to scan the id every time so to overwrite the old value
     SDB_IsIdExist(id);
     break;
 case 6:
     printf("Please enter student Id to delete:");
     scanf("%u", &id);      //we have to scan the id every time so to overwrite the old value
     SDB_DeleteEntry(id);
     break;
 case 7:
     SDB_IsFull();
     break;
 case 0 :
     printf("\nHave a nice day!");
     break;
 case '`' :        //adding a special case because if the user enters this symbol by mistake it will result in an infinite loop
     printf("Please enter a valid choice\n");
     break;
 default:
     printf("Please enter a valid choice\n");
     break;
}
printf("\n");
}
