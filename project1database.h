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
// DATE: Feb, 7, 2016
//
// FILE: hw3database.h
//
// DESCRIPTION: This file contains header for hw3database.c
//
//
//****************************************************************/

#include "record.h"


int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
