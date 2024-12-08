#pragma once

#include <iostream>
using namespace std;

namespace P16_IncreaseDateByOneDay {

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

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

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

	stDate ReadFullDate() {
		stDate Date;
		Date.Day = ReadNumber("Please enter a Day? ");
		Date.Month = ReadNumber("Please enter a Month? ");
		Date.Year = ReadNumber("Please enter a Year? ");
		return Date;
	}

	void Task() {

		stDate Date = ReadFullDate();

		Date = IncreaseDateByOneDay(Date);

		cout << "\nDate after adding one day is: ";
		cout << Date.Day << '/' << Date.Month << '/' << Date.Year << endl;



	}


}