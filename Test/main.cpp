#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "vendor/doctest.h"

#include "../Common/Date.h"
#include "../Common/Timer.h"

#include <iostream>

TEST_CASE("Test Date") {
    
    /*SUBCASE("Test Julian Day") {
        int julianDayNumber = 2415021;
        int weekDay = 1;
        for (int year = 1900; year < 2500; ++year)
        {
            CHECK(Date(year, 3, 1).GetJulianDayNumber() - Date(year, 2, 29).GetJulianDayNumber() == is_leap_year(year));
            for (int month = 1; month <= MonthsOfYear; ++month)
            {
                for (int day = 1; day <= days_of_month(year, month); ++day)
                {
                    Date d(year, month, day);
                    CHECK(year == d.Year());
                    CHECK(month == d.Month());
                    CHECK(day == d.Day());
                    CHECK(weekDay == d.WeekDay());
                    CHECK(julianDayNumber == d.GetJulianDayNumber());

                    Date d2(julianDayNumber);
                    CHECK(year == d2.Year());
                    CHECK(month == d2.Month());
                    CHECK(day == d2.Day());
                    CHECK(weekDay == d2.WeekDay());
                    CHECK(julianDayNumber == d2.GetJulianDayNumber());

                    ++julianDayNumber;
                    weekDay = (weekDay + 1) % 7;
                }
            }
        }
    }*/

    /*SUBCASE("Test Day") {
        int DayNumber = 0;
        for (int hour = 0; hour < 24; ++hour)
        {
            for (int min = 0; min < 60; ++min)
            {
                for (int sec = 0; sec < 60; ++sec)
                {
                    Day d(hour, min, sec);
                    CHECK(hour == d.Hour());
                    CHECK(min == d.Min());
                    CHECK(sec == d.Sec());
                    CHECK(DayNumber == d.GetDayNumber());

                    Day d2(DayNumber);
                    CHECK(hour == d2.Hour());
                    CHECK(min == d2.Min());
                    CHECK(sec == d2.Sec());
                    CHECK(DayNumber == d2.GetDayNumber());

                    ++DayNumber;
                }
            }
        }
    }*/

    {
        Timer global_timer = Timer();
        global_timer.Start();
        int c = 0;
        while (1)
        {
            static int64_t logic = global_timer.GetSeconds();
            int64_t now = global_timer.GetSeconds();
            int64_t step = now - logic;
            if (step >= 1)
            { 
                c++;
                logic = logic + 1;
                step = now - logic;
               
                std::cout << c << '\n';
            }
        }
    }
}