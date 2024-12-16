#pragma once

#include <iostream>
using namespace std;

namespace P62_ValidateDate {

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

	short NumberOfDaysInAYear(short Year) {
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

	}

	bool IsAValidDate(stDate Date) {

		return (Date.Day >= 1 && Date.Day <= NumberOfDaysInAMonth(Date.Year, Date.Month) &&
			Date.Month >= 1 && Date.Month <= 12 && Date.Year >= 1);

	}


	void Task() {

		stDate Date = ReadFullDate();

		cout << (IsAValidDate(Date) ? 
			"\nYes, Date is a valid date.\n" : "\nNo, Date is NOT a valid date.\n");



	}


}