#include "Date.h"

bool is_leap_year(int year)
{
	const unsigned int ayear = (unsigned int)year;
	return ayear % 4 == 0 && (ayear % 100 != 0 || ayear % 400 == 0);
}

int days_of_month(int year, int month)
{
	static int days[2][MonthsOfYear + 1] =
	{
	  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	};
	return days[is_leap_year(year)][month];
}

int getJulianDayNumber(int year, int month, int day)
{
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	return day + (153 * m + 2) / 5 + y * 365 + y / 4 - y / 100 + y / 400 - 32045;
}

const int Date::JulianDayOf1970_01_01 = getJulianDayNumber(1970, 1, 1);

Date::YearMonthDay getYearMonthDay(int julianday_number)
{
	int a = julianday_number + 32044;
	int b = (4 * a + 3) / 146097;
	int c = a - ((b * 146097) / 4);
	int d = (4 * c + 3) / 1461;
	int e = c - ((1461 * d) / 4);
	int m = (5 * e + 2) / 153;
	Date::YearMonthDay ymd{};
	ymd.day = e - ((153 * m + 2) / 5) + 1;
	ymd.month = m + 3 - 12 * (m / 10);
	ymd.year = b * 100 + d - 4800 + (m / 10);
	return ymd;
}

Date::Date(int year, int month, int day)
{
	julianday_number_ = getJulianDayNumber(year, month, day);
}

Date::Date(const struct tm& t)
{
	julianday_number_ = getJulianDayNumber(t.tm_year+1900, t.tm_mon+1, t.tm_mday);
}

bool Date::Valid() const
{
	return julianday_number_ > 0;
}

int Date::Year() const
{
	return GetYearMonthDay().year;;
}

int Date::Month() const
{
	return GetYearMonthDay().month;
}

int Date::Day() const
{
	return GetYearMonthDay().day;
}

int Date::WeekDay() const // [0, 1, ..., 6] => [Sunday, Monday, ..., Saturday ]
{
	return (julianday_number_ + 1) % DaysPerWeek;
}

Date::YearMonthDay Date::GetYearMonthDay() const
{
	return getYearMonthDay(julianday_number_);
}

int Date::GetJulianDayNumber()
{
	return julianday_number_;
}


int getDayNumber(int hour, int min, int sec)
{
	return hour * 3600 + min * 60 + sec;
}

struct Day::HourMinSec getHourMinSec(int day_number)
{
	Day::HourMinSec hms{};
	int h = day_number / 3600;
	int m = (day_number - h * 3600) / 60;
	hms.hour = h;
	hms.min = m;
	hms.sec = day_number - h * 3600 - m * 60;
	return hms;
}

Day::HourMinSec Day::GetHourMinSec() const
{
	return getHourMinSec(day_number_);
}

bool Day::Valid() const
{
	return day_number_ > -1 && day_number_ < 86400;
}

int Day::Hour() const
{
	return GetHourMinSec().hour;
}

int Day::Min() const
{
	return GetHourMinSec().min;
}

int Day::Sec() const
{
	return GetHourMinSec().sec;
}

int Day::GetDayNumber()
{
	return day_number_;
}

Day::Day(int hour, int min, int sec)
{
	day_number_ = getDayNumber(hour, min, sec);
}

Day::Day(const tm& t)
{
	day_number_ = getDayNumber(t.tm_hour, t.tm_min + 1, t.tm_sec);
}
