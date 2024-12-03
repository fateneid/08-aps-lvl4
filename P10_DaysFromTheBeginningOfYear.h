#pragma once

#include <iostream>
using namespace std;

namespace P10_DaysFromTheBeginningOfYear {

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

	short DaysFromTheBeginningOfYear(short Year, short Month, short Day) {
		
		short TotalDays = 0;
		for (short i = 1; i < Month; i++) {
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}
		TotalDays += Day;

		return TotalDays;

	}
	
	void Task() {

		short Day = ReadNumber("Please enter a Day? ");
		short Month = ReadNumber("\nPlease enter a Month? ");
		short Year = ReadNumber("\nPlease enter a Year? ");

		cout << "\nNumber of Days from the beginning of year is "
			<< DaysFromTheBeginningOfYear(Year, Month, Day) << endl;


	}
	

}