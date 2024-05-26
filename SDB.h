#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"


/**All the functions prototypes*/
void first_three_students();

bool SDB_IsFull();

uint8 SDB_GetUsedSize();

bool SDB_AddEntry();

void SDB_DeleteEntry(uint32 id);

bool SDB_ReadEntry(uint32 id);

void SDB_GetList(uint8 *count, uint32 *list);

bool SDB_IsIdExist(uint32 id);

void SDB_APP();

void SDB_action(uint8 choice);

/**Our user defined data type named student which houses the information about each student*/
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 courseIDs[3];  //creating a list of all courses IDs
 uint32 courseGrades[3];  //creating a list of all courses Grades

} student;


#endif // SDB_H_INCLUDED
