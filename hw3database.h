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

int addRecord (struct record **aRecord, int, char [ ],char [ ],int);
int printRecord (struct record *aRecord, int);
int modifyRecord (struct record *aRecord, int, char [ ]);
void printAllRecords(struct record *aRecord);
int deleteRecord(struct record **aRecord, int);

