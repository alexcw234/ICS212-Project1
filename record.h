/*****************************************************************
//
// NAME: Alex Watanabe
//
// PROJECT: 1
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: Feb, 7, 2016
//
// FILE: record.h 
//
// DESCRIPTION: This file contains the record.h for the bank interface program.
//                                                    
//
//****************************************************************/
struct record
{
    int                accountno;  
    char               name[25];   
    char               address[80];
    int                yearofbirth;
    struct record*     next;
};
