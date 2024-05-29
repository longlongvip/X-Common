#include "TimeUtil.h"
#include "Calendar.h"

namespace X
{
    const int Date::JulianDayOf1970_01_01 = get_julian_day_number(1970, 1, 1);
    Date::Date(bool bNow)
    {
        if (bNow)
        {
            time_t curr_time = time(nullptr);
            tm curr_tm;
            errno_t err = localtime_s(&curr_tm, &curr_time);
            if (err)
            {
                julian_day_number_ = 0;
            }
            *this = Date(curr_tm);
        }
        julian_day_number_ = 0;
    }


    Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day)
    {
        julian_day_number_ = get_julian_day_number(year, month, day);
    }

    Date::Date(int julian_day_number) : julian_day_number_(julian_day_number) 
    { 
        getYearMonthDay(julian_day_number);
    }

    Date::Date(const tm& t) : year_(t.tm_year + 1900), month_(t.tm_mon + 1), day_(t.tm_mday)
    {
        julian_day_number_ = get_julian_day_number(year_, month_, day_);
    }

    bool Date::isValid() const
    {
        return julian_day_number_ > 0;
    }

    int Date::week() const
    {

    }

    int Date::weekDay() const 
    {
        // [0, 1, ..., 6] => [Sunday, Monday, ..., Saturday ]
        return (julian_day_number_ + 1) % DaysPerWeek;
    }

    int Date::dayOfYear() const
    {
        return julian_day_number_ - get_julian_day_number(year_, 1, 1) + 1;
    }

    int Date::weekOfMonth() const
    {
        int first_weekDay = (julian_day_number_ + 1 - day_ + 1) % DaysPerWeek;
        return (day_ - 1 + first_weekDay) % 7 + 1;
    }

    int Date::weekOfYear() const
    {
        int first_julian_day_number = get_julian_day_number(year_, 1, 1);
        int first_weekDay = (first_julian_day_number + 1) % DaysPerWeek;
        return (julian_day_number_ - first_julian_day_number + first_weekDay) % 7 + 1;
    }

    void Date::getYearMonthDay(int julian_day_number)
    {
        int a = julian_day_number + 32044;
        int b = (4 * a + 3) / 146097;
        int c = a - ((b * 146097) / 4);
        int d = (4 * c + 3) / 1461;
        int e = c - ((1461 * d) / 4);
        int m = (5 * e + 2) / 153;
        day_ = e - ((153 * m + 2) / 5) + 1;
        month_ = m + 3 - 12 * (m / 10);
        year_ = b * 100 + d - 4800 + (m / 10);
    }

    int Date::getJulianDayNumber() const
    {
        return julian_day_number_;
    }

    void Date::setYear(int year)
    {
        year_ = year;
        julian_day_number_ = get_julian_day_number(year_, month_, day_);
    }

    void Date::setMonth(int month)
    {
        month_ = month;
        julian_day_number_ = get_julian_day_number(year_, month_, day_);
    }

    void Date::setDay(int day)
    {
        day_ = day;
        julian_day_number_ = get_julian_day_number(year_, month_, day_);
    }

    void Date::setDayOfYear(int dayOfYear)
    {
        julian_day_number_ = get_julian_day_number(year_, 1, 1) + dayOfYear - 1;
        getYearMonthDay(julian_day_number_);
    }

    void Date::setWeek(int week)
    {

    }

    bool Date::isBefore(const Date& date) const
    {
        return year_ < date.year_ && month_ < date.month_ && day_ < date.day_;
    }

    bool Date::isSame(const Date& date) const
    {
        return year_ == date.year_ && month_ == date.month_ && day_ == date.day_;
    }

    bool Date::isAfter(const Date& date) const
    {
        return year_ > date.year_ && month_ > date.month_ && day_ > date.day_;
    }

    bool Date::isSameOrBefore(const Date& date) const
    {
        return year_ <= date.year_ && month_ <= date.month_ && day_ <= date.day_;
    }

    bool Date::isSameOrAfter(const Date& date) const
    {
        return year_ >= date.year_ && month_ >= date.month_ && day_ >= date.day_;
    }

    bool Date::isBetween(const Date& date1, const Date& date2) const
    {
        return isSameOrAfter(date1) && isSameOrBefore(date2);
    }

    bool Date::isLeapYear() const
    {
        return is_leap_year(year_);
    }

    void Date::add(int value, const char* time_type)
    {
        
    }
}
