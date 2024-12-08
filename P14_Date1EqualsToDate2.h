#pragma once

#include <iostream>
using namespace std;

namespace P14_Date1EqualsToDate2 {

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
		return IsLeapYear(Year) ? 366 : 365;
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

	bool IsDate1EqualsToDate2(stDate Date1, stDate Date2) {
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	stDate ReadFullDate() {
		stDate Date;
		Date.Day = ReadNumber("Please enter a Day? ");
		Date.Month = ReadNumber("Please enter a Month? ");
		Date.Year = ReadNumber("Please enter a Year? ");
		return Date;
	}

	void Task() {

		stDate Date1 = ReadFullDate();
		cout << '\n';
		stDate Date2 = ReadFullDate();

		if (IsDate1EqualsToDate2(Date1, Date2)) {
			cout << "\n\nYes, Date1 is Equals To Date2.\n";
		}
		else {
			cout << "\n\nNo, Date1 is NOT Equals To Date2.\n";
		}


	}


}