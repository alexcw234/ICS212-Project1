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

#include "project1database.h"
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

struct rec * temp ;

struct rec * prev;

struct rec * tempnext = NULL;

if (debugmode == 1)
{
printf("\n\n**************************************************");
printf("\n\naddRecord(struct record**, int, char[], char[], int) has been called with parameters passed:\naccNo: %d\nname: %s \naddress: %s\nyear: %d", accNo, name, address, year);
printf("\n\n**************************************************\n");
}


if (start != NULL)
{
    temp = start;
    prev = temp;
    temp = start.next;


    while (temp.next != NULL)
    {
        if (uaccount > temp.accountno)
        {
            prev = temp;
            temp = temp.next;
        }


        if (uaccount <= temp.accountno)
        {

            tempnext = temp;
            prev.next = malloc(sizeof(struct rec));
            temp = prev.next;
        }

    }

    if (temp.next != NULL)
    {
        temp.next = tempnext;

        temp.accountno = uaccount;


        temp.name = uname;


        temp.address = uaddr;


        temp.yearofbirth = uyob;

    }
    if (temp.next == NULL)
    {
     if (uaccount > temp.accountno)
     {

        temp.next = malloc(sizeof(struct rec));


        prev = temp.next;

        temp = temp.next;

        temp.accountno = uaccount;


        temp.name = uname;


        temp.address = uaddr;


        temp.yearofbirth = uyob;


        temp.next = NULL;
      }
    }
}
if (start = NULL)
{
    start = malloc(sizeof(struct rec));

    temp = start;

    temp.next = malloc(sizeof(struct rec));


    temp = temp.next;

    temp.accountno = uaccount;


    temp.name = uname;

    temp.address = uaddr;

    temp.yearofbirth = uyob;

    temp.next = NULL;

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

struct rec * temp ;

struct rec * prev;

temp = start;


if (debugmode == 1)
{
printf("\n\n**************************************************");
printf("\n\nprintRecord(struct record**) has been called with parameters passed:\naccNo: %d", accNo);
printf("\n\n**************************************************\n");
}

while (temp.next != NULL)
{
    while (uaccountNumber != temp.accountno)
    {

        prev = temp;

        temp = next;
    }

    while (uaccountNumber == temp.accountno)
    {

        if (temp.next == NULL)
        {
            prev.next = NULL;


            free(temp);

            temp = prev;
        }
        if (temp.next != NULL)
        {
            prev.next = temp.next


            free(temp);



            temp = prev.next;
        }
    }
}






return 0;
}
