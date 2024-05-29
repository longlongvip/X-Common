#pragma once

#include <array>

namespace X
{
    constexpr int SecondsPerMinute = 60;
    constexpr int MinutesPerHour = 60;
    constexpr int SecondsPerHour = SecondsPerMinute * MinutesPerHour;
    constexpr int HoursOfDay = 24;
    constexpr int MinutesOfDay = HoursOfDay * MinutesPerHour;
    constexpr int SecondsOfDay = MinutesOfDay * SecondsPerMinute;

    constexpr int DaysPerWeek = 7;
    constexpr int MonthsOfYear = 12;

    constexpr std::array<std::array<int, MonthsOfYear + 1>, 2> DaysOfMonth =
    {{
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    }};

    constexpr int NSPerUS = 1000;
    constexpr int USPerMS = 1000;
    constexpr int MSPerS = 1000;

    constexpr int NSPerMS = NSPerUS * USPerMS;
    constexpr int USPerS = MSPerS * USPerMS;
    constexpr int NSPerS = MSPerS * USPerMS * NSPerUS;

    constexpr std::array<const char*, 13> NamesOfMonth =
    { 
        "",  "January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December"
    };

    constexpr std::array<const char*, 13> ShortNamesOfMonth =
    {
        "",  "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    constexpr std::array<const char*, 7> NamesOfWeekDay =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    constexpr std::array<const char*, 7> ShortNamesOfWeekDay =
    {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };

    constexpr std::array<const char*, 7> MoreShortNamesOfWeekDay =
    {
        "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"
    };



}
