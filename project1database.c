/*****************************************************************
//
// NAME: Alex Watanabe
//
// Project : 1
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: Mar 7 , 2016
//
// FILE: hw3database.c
//
// DESCRIPTION: This file contains the database functions for project1
//
//****************************************************************/

#include "project1database.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
extern debugmode;

/*****************************************************************
//
// Function name: addRecord [STUB]
//
// DESCRIPTION: (Not yet implemented) Function that adds data to the
//              struct "record" as specified by parameters
//
// Parameters:  start (record **): pointer to the start record's pointer.
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

int addRecord (struct record **start, int uaccountno, char uname[ ],char uaddr[ ],int uyob)
{

struct record * temp ;

struct record * prev;

struct record *tempnext = NULL;

if (debugmode == 1)
{
printf("\n\n**************************************************");
printf("\n\naddRecord(struct record**, int, char[], char[], int) has been called with parameters passed:\naccNo: %d\nname: %s \naddress: %s\nyear: %d", uaccountno, uname, uaddr, uyob);
printf("\n\n**************************************************\n");
}


if (*start != NULL)
{
    temp = *start;

    if (uaccountno <= temp->accountno)
    {
      tempnext = temp;
      temp = (struct record*) malloc(sizeof(struct record));
      *start = temp;
      temp->next = NULL;

    }

    while (temp->next != NULL)
    {
        if (uaccountno > temp->accountno)
        {
            prev = temp;
            temp = temp->next;
        }

        if (uaccountno <= temp->accountno)
        {

            tempnext = temp;
            prev->next = (struct record*) malloc(sizeof(struct record));
            temp = prev->next;

        }

    }

    if (tempnext != NULL)
    {
        temp->next = tempnext;
        temp->accountno = uaccountno;
        strcpy(temp->name, uname);
        strcpy(temp->address, uaddr);
        temp->yearofbirth = uyob;

    }
    if (temp->next == NULL)
    {
       if (uaccountno > temp->accountno)
       {
          temp->next = (struct record*) malloc(sizeof(struct record));

          prev = temp->next;
          temp = temp->next;

          temp->accountno = uaccountno;
          strcpy(temp->name, uname);
          strcpy(temp->address, uaddr);
          temp->yearofbirth = uyob;
          temp->next = NULL;
      }
    }
}
else if (*start == NULL)
{

    *start = (struct record*) malloc(sizeof(struct record));

    temp = *start;

    temp->accountno = uaccountno;
    strcpy(temp->name, uname);
    strcpy(temp->address, uaddr);
    temp->yearofbirth = uyob;
    temp->next = NULL;
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

int printRecord (struct record *start, int uaccountno)
{
      struct record * temp ;

      struct record * prev;

      int returnvalue = 0;

      temp = start;

      prev = NULL;

      if (debugmode == 1)
      {
      printf("\n\n**************************************************");
      printf("\n\nprintRecord(struct record*, int) has been called with parameters passed:\naccNo: %d", uaccountno);
      printf("\n\n**************************************************\n");
      }

      if (start == NULL)
      {
          printf("\nThe list is empty\n");
          returnvalue = -1;
      }
      else
      {
          while (temp->next != NULL)
          {
              if (uaccountno == temp->accountno)
              {
                  printf("\nAccount Number:\t%d", temp->accountno);
                  printf("\nName:\t%s", temp->name);
                  printf("\nAddress:");
                  printf("\n%s",temp->address);
                  printf("\nYear of Birth:\t%d\n", temp->yearofbirth);

              }
                  prev = temp;
                  temp = temp->next;
          }

          if (temp->next == NULL && uaccountno == temp->accountno)
          {
              printf("\nAccount Number:\t%d", temp->accountno);
              printf("\nName:\t%s", temp->name);
              printf("\nAddress:");
              printf("\n%s",temp->address);
              printf("\nYear of Birth:\t%d\n", temp->yearofbirth);

          }

      }

return returnvalue;
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

int modifyRecord (struct record *start, int uaccountno, char uaddr[ ])
{
    if (debugmode == 1)
    {
    printf("\n\n**************************************************");
    printf("\n\nmodifyRecord(struct record*, int, char[]) has been called with parameters passed:\naccNo: %d\naddress: %s", uaccountno, uaddr);
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

void printAllRecords(struct record *start)
{

  struct record * temp ;

  struct record * prev;

if (start != NULL) {

  temp = start;

    if (debugmode == 1)
    {
    printf("\n\n**************************************************");
    printf("\n\nprintAllRecords(struct record*) has been called.");
    printf("\n\n**************************************************\n");
    }

    while (temp->next != NULL)
    {
        printf("\nAccount Number:\t%d", temp->accountno);
        printf("\nName:\t%s", temp->name);
        printf("\nAddress:");
        printf("\n%s",temp->address);
        printf("\nYear of Birth:\t%d\n", temp->yearofbirth);

        prev = temp;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("\nAccount Number:\t%d", temp->accountno);
        printf("\nName:\t%s", temp->name);
        printf("\nAddress:");
        printf("\n%s",temp->address);
        printf("\nYear of Birth:\t%d\n", temp->yearofbirth);
    }
}
else
{
  printf("\nThe list is empty\n");
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

int deleteRecord(struct record **start, int uaccountno)
{

struct record * temp ;

struct record * prev;

int returnvalue = 0;

temp = *start;

prev = NULL;

if (debugmode == 1)
{
printf("\n\n**************************************************");
printf("\n\ndeleteRecord(struct record**) has been called with parameters passed:\naccNo: %d", uaccountno);
printf("\n\n**************************************************\n");
}

if (*start == NULL)
{

    returnvalue = -1;
}
else if (temp->next == NULL)
{
    if (uaccountno == temp->accountno)
    {
        free(temp);
        *start = NULL;
    }
}
else
{
    while (*start != NULL && temp->next != NULL)
    {

        while (uaccountno != temp->accountno && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;

        }

        while (*start != NULL && uaccountno == temp->accountno)
        {

            if (temp->next == NULL && prev != NULL)
            {
                prev->next = NULL;

                free(temp);

                temp = prev;


            }
            else if (temp->next == NULL && prev == NULL)
            {
                free(temp);
                *start = NULL;

            }
            else if (temp->next != NULL)
            {
                if (prev != NULL)
                {
                    prev->next = temp->next;

                    free(temp);

                    temp = prev->next;
                }
                else
                {
                    *start = temp->next;
                    prev = temp;
                    temp = temp->next;
                    free(prev);
                    prev = NULL;
                }
            }
        }
    }

}

return returnvalue;
}
