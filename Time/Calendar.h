#pragma once
#include<ctime>

#include "TimeUtil.h"

namespace X
{
    class Date
    {
    public:
        static const int JulianDayOf1970_01_01;

        Date() = default;
        Date(int year, int month, int day);
        explicit Date(int julian_day_number);
        explicit Date(const tm& t);
        explicit Date(bool bNow);

        bool isValid() const;
        int year() const { return year_; } ;
        int month() const { return month_; };
        int day() const { return day_; };
        int week() const;
        int weekDay() const;
        int dayOfYear() const;
        int weekOfMonth() const;
        int weekOfYear() const;

        int getJulianDayNumber() const;

        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);
        void setDayOfYear(int dayOfYear);
        void setWeek(int week);

        bool isBefore(const Date& date) const;
        bool isSame(const Date& date) const;
        bool isAfter(const Date& date) const;
        bool isSameOrBefore(const Date& date) const;
        bool isSameOrAfter(const Date& date) const;
        bool isBetween(const Date& date1, const Date& date2) const;
        bool isLeapYear() const;

        void add(int value, const char* time_type);


    private:
        int julian_day_number_ = 0;
        int year_ = 0;
        int month_ = 0;
        int day_ = 0;
        void getYearMonthDay(int julian_day_number);
    };
}
