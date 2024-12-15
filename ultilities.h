#pragma once
#include "Library.h"


bool isValidDate(const char* dateStr, int day, int month, int year);
void inputDateValid(char* dateStr);
void addDaysToDate(const char* dateStr, int days, char* newDateStr);
void addMonthsToDate(const char* dateStr, int months, char* newDateStr);
bool isLeapYear(int year);
void stringToDate(const char* dateStr, int& day, int& month, int& year);
int daysInMonth(int month, int year);
int daysFromStartOfYear(int day, int month, int year);
int daysBetweenDates(const char* dateStr1, const char* dateStr2);
bool isArrayEmpty(char strings[][20], int n);
void endlineHandler(char* str);

