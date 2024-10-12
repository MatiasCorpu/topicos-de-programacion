#include "tda-date.h"

int day(Date date)
{
    return date.day;
}

int month(Date date)
{
    return date.month;
}

int year(Date date)
{
    return date.year;
}

int daysInMonth(int month, int year)
{
    int dm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;

    return dm[month];
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isDateValid(Date date)
{
    if (date.year >= MIN_YEAR)
        if (date.month >= 1 && date.month <= 12)
            if (date.day >= 1 && date.day <= daysInMonth(date.month, date.year))
                return true;

    return false;
}

Date nextDay(Date date)
{
    if (isDateValid(date))
    {
        date.day++;
        if (date.day > daysInMonth(date.month, date.year))
        {
            date.day = 1;
            date.month++;

            if (date.month > 12)
            {
                date.month = 1;
                date.year++;
            }
        }
    }
    return date;
}

Date previousDay(Date date)
{
    if (isDateValid(date))
    {
        date.day--;
        if (date.day == 0)
        {
            date.month--;

            if (date.month == 0)
            {
                date.month = 12;
                date.year--;
            }

            date.day = daysInMonth(date.month, date.year);
        }
    }
    return date;
}

Date addDays(Date date, int days)
{
    for (int i = 0; i < days; i++)
        date = nextDay(date);

    return date;
}

Date subtractDays(Date date, int days)
{
    for (int i = 0; i < days; i++)
        date = previousDay(date);

    return date;
}

int daysBetweenDates(Date date1, Date date2)
{
    int days = 0;
    Date aux = date1;

    while (aux.year != date2.year || aux.month != date2.month || aux.day != date2.day)
    {
        aux = nextDay(aux);
        days++;
    }

    return days;
}

int dayOfWeek(Date date)
{
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;
    return (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}
