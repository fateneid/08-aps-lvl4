#pragma once

#include <iostream>
using namespace std;

namespace P06_NumberOfDaysInAMonthShortLogic {

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
			
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : 
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

		//or 
		/*
		
		int NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

		
		*/
	
	}

	short NumberOfHoursInAMonth(short Year, short Month) {
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	int NumberOfMinutesInAMonth(short Year, short Month) {
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth(short Year, short Month) {
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	void Task() {

		short Year = ReadNumber("Please enter a year to check? ");
		short Month = ReadNumber("\nPlease enter a Month to check? ");

		cout << "\nNumber of Days    in Month [" << Month << "] is "
			<< NumberOfDaysInAMonth(Year, Month) << endl;
		cout << "Number of Hours   in Month [" << Month << "] is "
			<< NumberOfHoursInAMonth(Year, Month) << endl;
		cout << "Number of Minutes in Month [" << Month << "] is "
			<< NumberOfMinutesInAMonth(Year, Month) << endl;
		cout << "Number of Seconds in Month [" << Month << "] is "
			<< NumberOfSecondsInAMonth(Year, Month) << endl;


	}

}