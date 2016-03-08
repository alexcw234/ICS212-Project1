/*****************************************************************
//
// NAME: Alex Watanabe
//
// HOMEWORK: 3
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: Feb 2 , 2016
//
// FILE: hw3database.c
//
// DESCRIPTION: This file contains the database functions for hw3
//
//****************************************************************/

#include "hw3database.h"
extern debugmode;

/*****************************************************************
//
// Function name: addRecord [STUB]
//
// DESCRIPTION: (Not yet implemented) Function that adds data to the
//              struct "record" as specified by parameters
//
// Parameters:  nextrec (record **): pointer to the start record's next record.
//              accNo (int) : the user's account number to be added.
//              name (char[]) : the user's name to be added.
//              address (char[]) : the user's address to be added.
//              year (int) : the user's year of birth to be added.
//
// Return values: 0 : on success, other integers for failure based on specific reasons.
//                eg. -1 if accNo already exists in database.
//
//
//****************************************************************/

int addRecord (struct record **nextrec, int accNo, char name[ ],char address[ ],int year)
{
    if (debugmode == 1)
    {
    printf("\n\n**************************************************");
    printf("\n\naddRecord(struct record**, int, char[], char[], int) has been called with parameters passed:\naccNo: %d\nname: %s \naddress: %s\nyear: %d", accNo, name, address, year);
    printf("\n\n**************************************************\n");
    }



return 0;
}

/*****************************************************************
//
// Function name: printRecord [STUB]
//
// DESCRIPTION: (Not yet implemented) Function to print a record
//              from the database.
//
// Parameters:  arecord (record*): Pointer to the start record.
//              accNo (int) : The account number to use as a key.
//
// Return values: 0: on success, -1 on failure (eg. if accNo doesn't exist)
//
//
//****************************************************************/

int printRecord (struct record *arecord, int accNo)
{
      if (debugmode == 1)
      {
      printf("\n\n**************************************************");
      printf("\n\nprintRecord(struct record*, int) has been called with parameters passed:\naccNo: %d", accNo);
      printf("\n\n**************************************************\n");
      }



return 0;
}

/*****************************************************************
//
// Function name: modifyRecord [STUB]
//
// DESCRIPTION: (Not yet implemented) Function that modifies a
//              record in the database.
//
// Parameters:  arecord (record*): pointer to the start record
//              accNo (int) : the account number to use as a key
//              address (char[]) : The new address to add to record.
//
// Return values: 0 on success, -1 on failure.
//
//
//****************************************************************/

int modifyRecord (struct record *arecord, int accNo, char address[ ])
{
    if (debugmode == 1)
    {
    printf("\n\n**************************************************");
    printf("\n\nmodifyRecord(struct record*, int, char[]) has been called with parameters passed:\naccNo: %d\naddress: %s", accNo, address);
    printf("\n\n**************************************************\n");
    }



return 0;
}

/*****************************************************************
//
// Function name: printAllRecords [STUB]
//
// DESCRIPTION: (Not yet implemented) Function that prints all records in the database
//
//
// Parameters: arecord (record*) : pointer to the first record.
//
//
//****************************************************************/

void printAllRecords(struct record *arecord)
{
    if (debugmode == 1)
    {
    printf("\n\n**************************************************");
    printf("\n\nprintAllRecords(struct record*) has been called.");
    printf("\n\n**************************************************\n");
    }





}

/*****************************************************************
//
// Function name: deleteRecord [STUB]
//
// DESCRIPTION: (Not yet implemented)
//              Function that deletes a record in the database.
//
//
// Parameters:  nextrec (record **): pointer to the start record's next record.
//              accNo (int) : The account number to use as a key.
//
//
// Return values: 0 on success, -1 on failure.
//
//
//****************************************************************/

int deleteRecord(struct record **nextrec, int accNo)
{
    if (debugmode == 1)
    {
    printf("\n\n**************************************************");
    printf("\n\nprintRecord(struct record**) has been called with parameters passed:\naccNo: %d", accNo);
    printf("\n\n**************************************************\n");
    }




return 0;
}
