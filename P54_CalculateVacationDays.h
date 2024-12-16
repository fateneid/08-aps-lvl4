#pragma once

#include <iostream>
using namespace std;

namespace P54_CalculateVacationDays {

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

	short CalcBusinessDays(stDate DateFrom, stDate DateTo) {

		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo)) {

			if (IsBusinessDay(DateFrom)) {
				Days++;
			}

			DateFrom = IncreaseDateByOneDay(DateFrom);

		}

		return Days;

	}

	void Task() {
		
		cout << "Vacation Starts:\n";
		stDate DateFrom = ReadFullDate();

		cout << "\nVacation Ends:\n";
		stDate DateTo = ReadFullDate();

		cout << "\nVacation From: " << GetDayName(DayOfWeekOrder(DateFrom)) << " , "
			<< DateFrom.Day << '/' << DateFrom.Month << '/' << DateFrom.Year << '\n';

		cout << "Vacation To: " << GetDayName(DayOfWeekOrder(DateTo)) << " , "
			<< DateTo.Day << '/' << DateTo.Month << '/' << DateTo.Year << '\n';

		cout << "\n\nActucal Vacation Days is: " << CalcBusinessDays(DateFrom, DateTo) << endl;


	}


}