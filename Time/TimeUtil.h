#pragma once

#include <windows.h>

#include "TimeConstant.h"

struct tm;

namespace X
{
    inline bool is_leap_year(int year)
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    inline int days_of_month(int year, int month)
    {
        return DaysOfMonth[is_leap_year(year)][month];
    }

    inline int get_julian_day_number(int year, int month, int day)
    {
        int a = (14 - month) / 12;
        int y = year + 4800 - a;
        int m = month + 12 * a - 3;
        return day + (153 * m + 2) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
    }

    inline int get_day_number(int hour, int min, int sec)
    {
        return hour * 3600 + min * 60 + sec;
    }
}
