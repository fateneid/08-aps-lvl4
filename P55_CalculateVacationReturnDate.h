#pragma once

#include <iostream>
using namespace std;

namespace P55_CalculateVacationReturnDate {

	struct stDate {
		short Year;
		short Month;
		short Day;
	};

	short DayOfWeekOrder(stDate Date) {
		short a, y, m;
		a = (14 - Date.Month) / 12;
		y = Date.Year - a;
		m = Date.Month + (12 * a) - 2;

		return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	string GetDayName(short DayOrder) {

		string DaysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return DaysOfWeek[DayOrder];

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

	short ReadNumber(string Message) {
		short Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	stDate ReadFullDate() {
		stDate Date;
		Date.Day = ReadNumber("Please enter a Day? ");
		Date.Month = ReadNumber("Please enter a Month? ");
		Date.Year = ReadNumber("Please enter a Year? ");
		return Date;
	}

	bool IsLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

		return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
			(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);

	}

	bool IsLastDayInMonth(stDate Date) {
		return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
	}

	bool IsLastMonthInYear(short Month) {
		return Month == 12;
	}

	stDate IncreaseDateByOneDay(stDate Date) {

		if (IsLastDayInMonth(Date)) {

			if (IsLastMonthInYear(Date.Month)) {
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}
		}
		else {
			Date.Day++;
		}

		return Date;

	}

	stDate GetReturnDate(stDate Date, short VacationDays) {

		while (VacationDays > 0) {
			if (IsBusinessDay(Date)) {
				VacationDays--;
			}
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;

	}

	void Task() {

		cout << "Vacation Starts:\n";
		stDate StartDate = ReadFullDate();
		short VacationDays = ReadNumber("\nPlease enter vacation days? ");

		stDate ReturnDate = GetReturnDate(StartDate, VacationDays);

		cout << "\n\nReturn Date: " << GetDayName(DayOfWeekOrder(ReturnDate)) << " , "
			<< ReturnDate.Day << '/' << ReturnDate.Month << '/' << ReturnDate.Year << '\n';


	}


}