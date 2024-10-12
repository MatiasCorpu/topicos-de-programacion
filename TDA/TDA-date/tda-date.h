#ifndef TDA_DATE_H_INCLUDED
#define TDA_DATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_YEAR 1900

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int day(Date date);
int month(Date date);
int year(Date date);
int daysInMonth(int month, int year);
bool isLeapYear(int year);
bool isDateValid(Date date);
Date nextDay(Date date);
Date previousDay(Date date);
Date addDays(Date date, int days);
Date subtractDays(Date date, int days);
int daysBetweenDates(Date date1, Date date2);
int dayOfWeek(Date date);

#endif // TDA_DATE_H_INCLUDED
