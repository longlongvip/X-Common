#pragma once
#include <time.h>

struct tm;

const int MonthsOfYear = 12;

bool is_leap_year(int year);
int days_of_month(int year, int month);

class Date
{
public:
	struct YearMonthDay
	{
		int year;
		int month;
		int day;
	};

	static const int DaysPerWeek = 7;
	static const int JulianDayOf1970_01_01;

	Date():julianday_number_(0) {}
	Date(int year, int month, int day);
	explicit Date(int juliandaynumber):julianday_number_(juliandaynumber) {}
	explicit Date(const struct tm& t);

	bool Valid() const;
	int Year() const;
	int Month() const;
	int Day() const;
	int WeekDay() const;

	YearMonthDay GetYearMonthDay() const;
	int GetJulianDayNumber();

	
private:
	int julianday_number_;

};

class Day
{
public:
	struct HourMinSec
	{
		int hour;
		int min;
		int sec;
	};

	static const int HoursPerDay = 24;
	static const int MinsPerHour = 60;
	static const int SecsPerMin = 60;

	Day() :day_number_(0) {}
	Day(int hour, int min, int sec);
	explicit Day(int day_number) :day_number_(day_number) {}
	explicit Day(const struct tm& t);

	bool Valid() const;
	int Hour() const;
	int Min() const;
	int Sec() const;

	HourMinSec GetHourMinSec() const;
	int GetDayNumber();
	
private:
	int day_number_;
};