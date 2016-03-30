/*****************************************************************
//
// NAME: Alex Watanabe
//
// Project: 1
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: Feb, 7, 2016
//
// FILE: project1database.h
//
// DESCRIPTION: This file contains header for project1database.c
//
//
//****************************************************************/

#include "record.h"


int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
