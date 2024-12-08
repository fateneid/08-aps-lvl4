#pragma once

#include <iostream>
using namespace std;

namespace P12_AddDaysToDate {

	struct stDate {

		short Year;
		short Month;
		short Day;

	};

	short ReadNumber(string Message) {
		short Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	bool IsLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	short NumberOfDaysInAYear(short Year) {
		return IsLeapYear(Year)? 366 : 365;
	}

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

	}

	short DaysFromTheBeginningOfYear(short Year, short Month, short Day) {

		short TotalDays = 0;
		for (short i = 1; i < Month; i++) {
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}
		TotalDays += Day;

		return TotalDays;   

	}

	stDate DateFromDayOrderInAYear(short Year, short DayOrderInAYear) {

		stDate Date;
		Date.Year = Year;
		Date.Month = 1;  

		short RemainingDays = DayOrderInAYear;
		short MonthDays = 0;

		while (true) {

			MonthDays = NumberOfDaysInAMonth(Year, Date.Month);

			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;

	}

	stDate AddDaysToDate(short Year, short Month, short Day, int DaysToAdd) {

		int TotalDays = DaysToAdd + DaysFromTheBeginningOfYear(Year, Month, Day);

		while (TotalDays >= NumberOfDaysInAYear(Year)) {
			TotalDays -= NumberOfDaysInAYear(Year);
			Year++;
		}
		if (TotalDays == 0) {
			TotalDays++;
		}
		return DateFromDayOrderInAYear(Year, TotalDays);
	
	}

	void Task() {
		
		short Day = ReadNumber("Please enter a Day? ");
		short Month = ReadNumber("\nPlease enter a Month? ");
		short Year = ReadNumber("\nPlease enter a Year? ");
		int DaysToAdd = ReadNumber("\nHow many days to add? ");

		stDate Date = AddDaysToDate(Year, Month, Day, DaysToAdd);

		cout << "\nDate after adding [" << DaysToAdd << "] days is: ";
		cout << Date.Day << '/' << Date.Month << '/' << Date.Year << endl;

	}


}