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
// DATE: Feb 2, 2016
//
// FILE: hw3interface.c
//
// DESCRIPTION: This file contains the user interface for hw3
//
//****************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "project1interface.h"

int debugmode = 0;

/*****************************************************************
//
// Function name: main
//
// DESCRIPTION: Main function containing the user interface and
//              input/output statements of the program.
//              Accepts argument "debug" for debug mode output
//              or no arguments.
//
// Parameters:  argc (int): the number of arguments.
//              argv (char *[]) : The arguments specified.
//
// Return values: 0: on completion of the program.
//
//
//****************************************************************/


int main(int argc, char* argv[])
{
    int argsCorrect;

    int inLoop;

    int addRecLoop;

    int addLineLoop;

    int yesnoLoop;

    int validation;

    int allFieldsFilled[4] = {0,0,0,0};

    char choice[80];

    int tempAccNo;

    char tempName[25];

    char tempAddress[80];

    int tempYear;

    char input[800];

    struct record *start = NULL;


    inLoop = 1;
    addLineLoop = 0;
    yesnoLoop = 0;

    choice[0] = 0;
    validation = -1;

    argsCorrect = 0;

    if (argc > 2)
    {
        printf("hw3: Extra arguments (%d)", argc);
        printf("\n\tUsage: hw3");
        printf("\n\t       hw3 debug\n\n");

    }
    else if (argc == 1)
    {
        argsCorrect = 1;
        printf("\nWelcome! This is a sample user interface for a bank database application.\n\n");

    }
    else if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        argsCorrect = 2;
        debugmode = 1;
        printf("\n\n****************");
        printf("\n\nDEBUG MODE IS ON");
        printf("\n\n****************\n");

        printf("\nWelcome! This is a sample user interface for a bank database application.\n");

    }
    else
    {
        printf("hw3: Unrecognized argument (%s)", argv[1]);
        printf("\n\tUsage: hw3");
        printf("\n\t       hw3 debug\n\n");
    }

    if (inLoop == 0)
    {
        inLoop = 1;
    }

    while (inLoop == 1 && argsCorrect >= 1)
    {
        printf("\nMain Menu");
        printf("\n\t1\tAdd new record");
        printf("\n\t2\tModify record");
        printf("\n\t3\tPrint a record");
        printf("\n\t4\tPrint all records");
        printf("\n\t5\tDelete record");
        printf("\n\t6\tQuit");
        printf("\nPlease enter your choice and press return key: ");

        fgets(choice, 80, stdin);
        nullBreak(choice);

        if (choice[0] == '1')
        {/* Adds new record */
            addRecLoop = 1;
            while (addRecLoop == 1)
            {
                printf("\nAdd New Record");
                printf("\n\t1\tEnter Account Number");
                printf("\n\t2\tEnter Name");
                printf("\n\t3\tEnter Address");
                printf("\n\t4\tEnter Year of Birth");
                printf("\n\t5\tDone (Finalize or Go Back)");
                printf("\nEnter the number of your choice and press return key: ");

                fgets(choice, 80, stdin);
                nullBreak(choice);

                if (choice[0] == '1')
                {/* accountnumber */
                  addLineLoop = 1;
                  while (addLineLoop == 1)
                  {
                      printf("\nPlease enter your account number and press return: ");

                      fgets(input, 80, stdin);
                      nullBreak(input);
                      tempAccNo = validateInput(input, 1);

                      if (tempAccNo != -1)
                      {
                          yesnoLoop = 1;

                      }
                      else
                      {
                        yesnoLoop = 0;
                        printf("\nNot a valid entry, please re-enter.");
                      }

                      while (yesnoLoop == 1)
                      {
                          printf("\nIs %d correct (Y/N)?  ", tempAccNo);
                          fgets(choice, 80, stdin);
                          validation = validateInput(choice, 2);
                          if (validation == 0)
                          {
                              loopQuit(&addLineLoop);
                              loopQuit(&yesnoLoop);
                              allFieldsFilled[0] = 1;
                          }
                          else if (validation == 1)
                          {
                              loopQuit(&yesnoLoop);
                          }
                          else
                          {
                            printf("\nInvalid entry. Please re-enter.");
                          }
                      }

                  }

                }
                else if (choice[0] == '2')
                {   /* name */
                    addLineLoop = 1;

                    while (addLineLoop == 1)
                    {
                      printf("\nPlease enter your name and press return: ");

                        fgets(input, 80, stdin);
                        nullBreak(input);
                        strcpy(tempName,input);

                        if (strlen(tempName) <= 24)
                        {
                            yesnoLoop = 1;
                        }
                        else
                        {
                            yesnoLoop = 1;
                            printf("\nEntry must be 24 characters or less,");
                            printf(" please re-enter.");
                        }

                        while (yesnoLoop == 1)
                        {

                            printf("\nIs %s correct (Y/N)?  ", tempName);


                            fgets(choice, 80, stdin);
                            validation = validateInput(choice, 2);

                            if (validation == 0)
                            {
                                loopQuit(&addLineLoop);
                                loopQuit(&yesnoLoop);
                                allFieldsFilled[1] = 1;
                            }
                            else if (validation == 1)
                            {
                                loopQuit(&yesnoLoop);
                            }
                            else
                            {
                                printf("\nInvalid entry. Please re-enter.");
                            }
                        }
                    }



                }
                else if (choice[0] == '3')
                {
                    /* address */
                    addLineLoop = 1;
                    while (addLineLoop == 1)
                    {

                        getfield(tempAddress, 80);
                        nullBreak(tempAddress);

                        yesnoLoop = 1;

                        while (yesnoLoop == 1)
                        {

                            printf("\nIs the following correct");
                            printf(" (Y/N)?\n%s\n", tempAddress);


                            fgets(choice, 80, stdin);
                            validation = validateInput(choice, 2);

                            if (validation == 0)
                            {
                                loopQuit(&addLineLoop);
                                loopQuit(&yesnoLoop);
                                allFieldsFilled[2] = 1;
                            }
                            else if (validation == 1)
                            {
                                loopQuit(&yesnoLoop);
                            }
                            else
                            {
                                printf("\nInvalid entry. Please re-enter.");
                            }
                        }
                    }



                }
                else if (choice[0] == '4')
                {
                    /* yearofbirth */
                    addLineLoop = 1;
                    while (addLineLoop == 1)
                    {
                        printf("\nPlease enter your year of birth and press return: ");

                        fgets(input, 80, stdin);
                        nullBreak(input);
                        tempYear = validateInput(input, 1);

                        if (tempYear != -1)
                        {
                            yesnoLoop = 1;

                        }
                        else
                        {
                          yesnoLoop = 0;
                          printf("\nNot a valid entry, please re-enter.");
                        }

                        while (yesnoLoop == 1)
                        {
                            printf("\nIs %d correct (Y/N)?  ", tempYear);
                            fgets(choice, 80, stdin);
                            validation = validateInput(choice, 2);
                            if (validation == 0)
                            {
                                loopQuit(&addLineLoop);
                                loopQuit(&yesnoLoop);
                                allFieldsFilled[3] = 1;
                            }
                            else if (validation == 1)
                            {
                                loopQuit(&yesnoLoop);
                            }
                            else
                            {
                              printf("\nInvalid entry. Please re-enter.");
                            }
                        }
                    }
                }


                else if (choice[0] == '5' && allFieldsFilled[0] == 1
                && allFieldsFilled[1] == 1 && allFieldsFilled[2] == 1
                && allFieldsFilled[3] == 1)
                {
                    /* Finalize */
                    yesnoLoop = 1;

                    while (yesnoLoop == 1)
                    {

                        printf("\nIs this record correct?");
                        printf("\nAccount Number:\t%d", tempAccNo);
                        printf("\nName:\t%s", tempName);
                        printf("\nAddress:");
                        printf("\n%s",tempAddress);
                        printf("\nYear of Birth:\t%d", tempYear);
                        printf("\n(Y/N)? : ");

                        fgets(choice, 80, stdin);
                        validation = validateInput(choice, 2);

                        if (validation == 0)
                        {
                            loopQuit(&addRecLoop);
                            loopQuit(&yesnoLoop);
                            addRecord(&start, tempAccNo, tempName, tempAddress, tempYear);
                            allFieldsFilled[0] = 0;
                            allFieldsFilled[1] = 0;
                            allFieldsFilled[2] = 0;
                            allFieldsFilled[3] = 0;
                        }
                        else if (validation == 1)
                        {
                            while (yesnoLoop == 1)
                            {
                                printf("\nGo back to main menu (Y/N)?");

                                fgets(choice, 80, stdin);
                                validation = validateInput(choice, 2);

                                if (validation == 0)
                                {
                                    loopQuit(&yesnoLoop);
                                    loopQuit(&addRecLoop);
                                    allFieldsFilled[0] = 0;
                                    allFieldsFilled[1] = 0;
                                    allFieldsFilled[2] = 0;
                                    allFieldsFilled[3] = 0;
                                }
                                else if (validation == 1)
                                {

                                    loopQuit(&yesnoLoop);

                                }
                                else
                                {
                                    printf("\nInvalid entry. Please re-enter.");
                                }
                            }
                        }
                        else
                        {
                            printf("\nInvalid entry. Please re-enter.");
                        }
                    }
                }
                else if (choice[0] == '5' && (allFieldsFilled[0] != 1
                || allFieldsFilled[1] != 1 || allFieldsFilled[2] != 1
                || allFieldsFilled[3] != 1))
                {


                    printf("\nNot all fields specified. ");
                    printf("Record will not be added.");
                  /* Finalize */
                    yesnoLoop = 1;

                    while (yesnoLoop == 1)
                    {
                        printf("\nContinue editing new record (Y/N)?");

                        fgets(choice, 80, stdin);
                        validation = validateInput(choice, 2);

                        if (validation == 0)
                        {
                            loopQuit(&yesnoLoop);
                        }
                        else if (validation == 1)
                        {

                            while (yesnoLoop == 1)
                            {
                                printf("\nGo back to main menu (Y/N)?");

                                fgets(choice, 80, stdin);
                                validation = validateInput(choice, 2);

                                if (validation == 0)
                                {
                                    loopQuit(&yesnoLoop);
                                    loopQuit(&addRecLoop);
                                    allFieldsFilled[0] = 0;
                                    allFieldsFilled[1] = 0;
                                    allFieldsFilled[2] = 0;
                                    allFieldsFilled[3] = 0;
                                }
                                else if (validation == 1)
                                {
                                    loopQuit(&yesnoLoop);
                                }
                                else
                                {
                                    printf("\nInvalid entry. Please re-enter.");
                                }
                            }
                      }
                      else
                      {
                          printf("\nInvalid entry. Please re-enter.");

                      }
                    }
                }
                else
                {
                    printf("\nInvalid entry. Please re-enter.");
                }
            }
        }
        else if (choice[0] == '2')    /* Modifies a record */
        {


          addLineLoop = 1;
          while(addLineLoop == 1)
          {
                printf("\nEnter number of the account to be modified: ");

                fgets(input, 80, stdin);

                nullBreak(input);

                tempAccNo = validateInput(input, 1);

                if (tempAccNo != -1)
                {
                    yesnoLoop = 1;

                }
                else
                {
                  yesnoLoop = 0;
                  printf("\nNot a valid entry, please re-enter.");
                }

                while (yesnoLoop == 1)
                 {
                    printf("\nIs %d correct (Y/N)?  ", tempAccNo);
                    fgets(choice, 80, stdin);
                    validation = validateInput(choice, 2);
                    if (validation == 0)
                    {
                        loopQuit(&addLineLoop);
                        loopQuit(&yesnoLoop);
                    }
                    else if (validation == 1)
                    {
                        loopQuit(&yesnoLoop);
                    }
                    else
                    {
                      printf("\nInvalid entry. Please re-enter.");
                    }
                }

            }

            addLineLoop = 1;

            while (addLineLoop == 1)
            {

                getfield(tempAddress, 80);
                nullBreak(tempAddress);

                yesnoLoop = 1;

                while (yesnoLoop == 1)
                {

                    printf("\nIs the following correct");
                    printf(" (Y/N)?\n%s\n", tempAddress);


                    fgets(choice, 80, stdin);
                    validation = validateInput(choice, 2);

                    if (validation == 0)
                    {
                        loopQuit(&addLineLoop);
                        loopQuit(&yesnoLoop);
                    }
                    else if (validation == 1)
                    {
                        loopQuit(&yesnoLoop);
                    }
                    else
                    {
                        printf("\nInvalid entry. Please re-enter.");
                    }
                }
                    /* Finalize */
                yesnoLoop = 1;

                while (yesnoLoop == 1)
                {

                    printf("\nAddress of account number %d", tempAccNo);
                    printf(" will be changed to :");
                    printf("\n%s",tempAddress);
                    printf("\nIs this correct (Y/N)? : ");

                    fgets(choice, 80, stdin);
                    validation = validateInput(choice, 2);

                    if (validation == 0)
                    {
                        loopQuit(&addRecLoop);
                        loopQuit(&yesnoLoop);
                        modifyRecord(&start, tempAccNo, tempAddress);
                    }
                    else if (validation == 1)
                    {
                        while (yesnoLoop == 1)
                        {
                            printf("\nGo back to main menu (Y/N)?");

                            fgets(choice, 80, stdin);
                            validation = validateInput(choice, 2);

                            if (validation == 0)
                            {


                                loopQuit(&yesnoLoop);
                                loopQuit(&addRecLoop);

                            }
                            else if (validation == 1)
                            {

                                loopQuit(&yesnoLoop);
                            }
                            else
                            {
                                printf("\nInvalid entry. Please re-enter.");
                            }
                        }
                    }
                    else
                    {
                        printf("\nInvalid entry. Please re-enter.");
                    }
                }

            }
        }
        else if (choice[0] == '3')    /* Prints one record */
        {
          addLineLoop = 1;
          while(addLineLoop == 1)
          {
                printf("\nEnter an account number of account to be printed: ");

                fgets(input, 80, stdin);

                nullBreak(input);

                tempAccNo = validateInput(input, 1);

                if (tempAccNo != -1)
                {
                    yesnoLoop = 1;

                }
                else
                {
                  yesnoLoop = 0;
                  printf("\nNot a valid entry, please re-enter.");
                }

                while (yesnoLoop == 1)
                 {
                    printf("\nIs %d correct (Y/N)?  ", tempAccNo);
                    fgets(choice, 80, stdin);
                    validation = validateInput(choice, 2);
                    if (validation == 0)
                    {
                        loopQuit(&addLineLoop);
                        loopQuit(&yesnoLoop);
                        printRecord(&start, tempAccNo);
                    }
                    else if (validation == 1)
                    {
                        loopQuit(&yesnoLoop);
                    }
                    else
                    {
                      printf("\nInvalid entry. Please re-enter.");
                    }
                }

            }


        }
        else if (choice[0] == '4')    /* Prints all info */
        {
            yesnoLoop = 1;

            while (yesnoLoop == 1)
             {
                printf("\nAll records will be printed, is that ok (Y/N)?  ");
                fgets(choice, 80, stdin);
                validation = validateInput(choice, 2);
                if (validation == 0)
                {



                    printAllRecords(&start);


                    loopQuit(&yesnoLoop);
                }
                else if (validation == 1)
                {
                    loopQuit(&yesnoLoop);
                }
                else
                {
                  printf("\nInvalid entry. Please re-enter.");
                }
            }
        }
        else if (choice[0] == '5')    /* Deletes Record */
        {

            addLineLoop = 1;
            while(addLineLoop == 1)
            {
                  printf("\nEnter an account number of account to be deleted: ");

                  fgets(input, 80, stdin);

                  nullBreak(input);

                  tempAccNo = validateInput(input, 1);

                  if (tempAccNo != -1)
                  {
                      yesnoLoop = 1;

                  }
                  else
                  {
                    yesnoLoop = 0;
                    printf("\nNot a valid entry, please re-enter.");
                  }

                  while (yesnoLoop == 1)
                   {
                      printf("\nAll data from account number %d ", tempAccNo);
                      printf("will be erased.\nIs that ok (Y/N)? ");
                      fgets(choice, 80, stdin);
                      validation = validateInput(choice, 2);
                      if (validation == 0)
                      {

                          deleteRecord(&start, tempAccNo);
                          loopQuit(&addLineLoop);
                          loopQuit(&yesnoLoop);
                      }
                      else if (validation == 1)
                      {
                          loopQuit(&yesnoLoop);
                      }
                      else
                      {
                        printf("\nInvalid entry. Please re-enter.");
                      }
                  }

              }

        }
        else if (choice[0] == '6')    /* Quits the program */
        {
            yesnoLoop = 1;

            while (yesnoLoop == 1)
             {
                printf("\nAre you sure you want to quit(Y/N)?  ");
                fgets(choice, 80, stdin);
                validation = validateInput(choice, 2);
                if (validation == 0)
                {
                    loopQuit(&inLoop);
                    loopQuit(&yesnoLoop);
                    printf("\n\nGoodbye.\n\n\n");
                }
                else if (validation == 1)
                {
                    loopQuit(&yesnoLoop);
                }
                else
                {
                  printf("\nInvalid entry. Please re-enter.");
                }
            }
        }
        else
        {
            printf("\nInvalid entry, please try again.");

        }


    }
    return 0;
}


/*****************************************************************
//
// Function name: getfield
//
// DESCRIPTION: Function that collects user input for multiline
//              fields ie. address. Field must be less than 80 characters
//              but number of lines can be infinite.
//              Upon finished entry, return on a blank line will prompt to
//              finalize input.
// Parameters:  charField (char[]): The array for the user validated address to be stored.
//              maxlength (int): The maximum length of the string.
//
//
//
//****************************************************************/

void getfield (char charField[], int maxlength)
{


    char tempField[80];
    int inLoop = 1;
    int lengthcount = 0;
    int flcount;

    if (debugmode == 1)
    {
      printf("\n\n**************************************************\n");
      printf("\ngetfield(char[],int) function has been (re)called\n with parameters charField[] and maxlength: %d", maxlength);
      printf("\n\n**************************************************\n");
    }

    for (flcount = 0; flcount < maxlength; flcount++)
    {
        charField[flcount] = '\0';
    }

    printf("Please enter your address.\n");
    printf("\nTo add a new line, press return once.");
    printf("\nWhen finished, press return twice:\n");

    while (inLoop == 1)
    {
        fgets(tempField, maxlength, stdin);

        lengthcount = lengthcount + strlen(tempField);

        if (validateInput(tempField, 3) != 0)
        {
            if (lengthcount <= maxlength)
            {
                strcat(charField, tempField);
            }
            else
            {
              printf("\nAddress must be less than 80 characters.");
              printf("\nPlease try again.");

              for (flcount = 0; flcount < maxlength; flcount++)
              {
                  charField[flcount] = '\0';
              }
            }
        }
        else
        {
          inLoop = 0;
        }
    }
}

/*****************************************************************
//
// Function name: nullBreak
//
// DESCRIPTION: Function that replaces a line break in a string with
//              null character if it is the last character before the
//              original null character.
//
// Parameters:  theString (char[]) : The array to be modified.
//
//
//****************************************************************/

void nullBreak (char theString[])
{
    if (debugmode == 1)
    {
      printf("\n\n\t\t\t\t\t**************************************************\n");
      printf("\n\t\t\t\t\tnullBreak(char[]) function has been called.\n\t\t\t\t\tRemoving line break at the ");
      printf("end of fgets string.");

      printf("\n\n\t\t\t\t\t**************************************************\n");
    }


        if (theString[strlen(theString) - 1] == '\n')
        {
            theString[strlen(theString) - 1] = '\0';
        }
}

/*****************************************************************
//
// Function name: validateInput
//
// DESCRIPTION: Function that performs input validation and
//              string conversion, as specified by 'mode'.
//
// Parameters:  theString (char[]) : The array to be modified.
//              mode (int): The mode of validation to be used, specified as follows:
//                     1. Validates for positive integer as string input
//                        and converts it to an int data type if possible.
//                     2. Validates confirmation (Y/N) input;
//                        will return 0 if Y and 1 if N.
//                     3. Validates if first character of a string is a newline;
//                        if so, returns 0. Does not alter the string.
//
//
//
//
//
//
// Return values: convresult (int): (Mode 1) integer result of conversion, set to equal
//                -1 if failed to convert and/or otherwise invalid.
//                 (Mode 2) 0 if yes, 1 if no
//                 (Mode 3) 0 if found line break only string, -1 if not.
//
//
//****************************************************************/

int validateInput (char theString[], int mode)
{

    int goodInput;
    int foundEnd;
    int count;
    int convresult = -1;

    if (debugmode == 1)
    {
      printf("\n\n\t\t\t\t\t**************************************************\n");
      printf("\n\t\t\t\t\tvalidateInput(char[], int) function has been called with mode parameter %d: ", mode);

        if (mode == 1)
        {
            printf("\n\t\t\t\t\tInteger validation on fgets string input[]");
        }
        else if (mode == 2)
        {
            printf("\n\t\t\t\t\tYes/No validation on fgets string choice[]");
        }
        else if (mode == 3)
        {
            printf("\n\t\t\t\t\tLine break only string validation on fgets string tempField[]");
        }

      printf("\n\n\t\t\t\t\t**************************************************\n");
    }

    if (mode == 1)
    {
        if (theString[0] != '-')
        {
            goodInput = 1;

            foundEnd = 0;

            count = 0;

            while (foundEnd == 0 && count < strlen(theString))
            {
                if (theString[count] == '\0')
                {
                    foundEnd = 1;
                }
                else if (!isdigit(theString[count]))
                {
                    goodInput = 0;
                }
                count++;
            }

            if (goodInput == 1)
            {
                convresult  = atoi(theString);
            }
        }

    }
    else if (mode == 2)
    {
        if (*theString == 'Y' || *theString == 'y')
        {
            convresult = 0;
        }
        else if (*theString == 'N' || *theString == 'n')
        {
            convresult = 1;
        }
    }
    else if (mode == 3)
    {
        if (theString[0] == '\n' && theString[1] == '\0')
        {
            convresult = 0;
        }
    }

    return convresult;
}


/*****************************************************************
//
// Function name: loopQuit
//
// DESCRIPTION: Function that quits a loop by changing the
//              passed in loop variable from 1 to 0. For use with the menus.
//
//
// Parameters:  Loop (int*): Pointer to the loop variable to be changed.
//
//
//
//****************************************************************/

void loopQuit(int *Loop)
{
     if (debugmode == 1)
     {
       printf("\n\n\t\t\t\t\t**************************************************\n");
       printf("\n\t\t\t\t\tloopQuit(int*) function has been called. Exiting input loop.");
       printf("\n\n\t\t\t\t\t**************************************************\n");
     }

    *Loop = 0;
}
