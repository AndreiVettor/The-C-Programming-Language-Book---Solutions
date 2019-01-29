#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
    int year = 1996;
    int month = 06;
    int day = 27;

    int pmonth, pday;

    int yearday = day_of_year(year, month, day);

    printf("day_of_year %d-%d-%d: %d\n",year, month, day, yearday);

    month_day(year, yearday, &pmonth, &pday);
    printf("month_day: %d-%d\n", pmonth, pday);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(month < 1 || month > 12)
    {
        printf("Not a valid month!\n");
        return -1;
    }
    if(day < 1 || day > daytab[leap][month])
    {
        printf("Not a valid day!\n");
        return -1;
    }

    for(i = 1; i < month; ++i)
    {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if(yearday < 1 || yearday > (leap ? 366 : 365))
    {
        return;
    }

    for(i = 1; yearday > daytab[leap][i]; ++i)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}