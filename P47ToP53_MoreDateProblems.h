#pragma once

#include <iostream>
using namespace std;

namespace P47ToP53_MoreDateProblems {

	struct stDate {
		short Year;
		short Month;
		short Day;
	};

	bool IsLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

	}

	short NumberOfDaysInAYear(short Year) {
		return IsLeapYear(Year) ? 366 : 365;
	}

	short DaysFromTheBeginningOfYear(short Year, short Month, short Day) {

		short TotalDays = 0;
		for (short i = 1; i < Month; i++) {
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}
		TotalDays += Day;

		return TotalDays;

	}

	short DayOfWeekOrder(short Year, short Month, short Day) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder(stDate Date) {

		return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);

	}

	string GetDayName(short DayOrder) {

		string DaysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return DaysOfWeek[DayOrder];

	}

	stDate GetCurrentDate() {

		stDate CurrentDate;

		time_t t = time(0);
		tm* now = localtime(&t);

		CurrentDate.Day = now->tm_mday;
		CurrentDate.Month = now->tm_mon + 1;
		CurrentDate.Year = now->tm_year + 1900;

		return CurrentDate;

	}

	bool IsEndOfWeek(stDate Date) {
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekend(stDate Date) {
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(stDate Date) {
		//short DayIndex = DayOfWeekOrder(Date);
		//return !(DayIndex == 5 || DayIndex == 6);
		return !IsWeekend(Date);
	}

	short DaysUntilTheEndOfWeek(stDate Date) {
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilTheEndOfMonth(stDate Date) {
		return NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day;
	}

	short DaysUntilTheEndOfYear(stDate Date) {
		return NumberOfDaysInAYear(Date.Year) - DaysFromTheBeginningOfYear(Date.Year, Date.Month, Date.Day);
	}

	void Task() {


		stDate CurrentDate = GetCurrentDate();

		cout << "Today is " << GetDayName(DayOfWeekOrder(CurrentDate)) << " , " 
			<< CurrentDate.Day << '/' << CurrentDate.Month << '/' << CurrentDate.Year << '\n';

		cout << "\nIs it End of Week?\n";
		cout << (IsEndOfWeek(CurrentDate) ? "Yes it is end of week.\n" : "No Not end of week.\n");

		cout << "\nIs it Weekend?\n";
		cout << (IsWeekend(CurrentDate) ? "Yes it is a week end.\n" : "No Not a week end.\n");

		cout << "\nIs it Business Day?\n";
		cout << (IsBusinessDay(CurrentDate) ? "Yes it is a business day.\n" : "No it is NOT a business day.\n");

		cout << "\nDays until end of week : " << DaysUntilTheEndOfWeek(CurrentDate) << " Day(s).\n";
		cout << "Days until end of month : " << DaysUntilTheEndOfMonth(CurrentDate) << " Day(s).\n";
		cout << "Days until end of year : " << DaysUntilTheEndOfYear(CurrentDate) << " Day(s).\n";


	}


}
