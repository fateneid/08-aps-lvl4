#pragma once

#include <iostream>
using namespace std;

namespace P04_NumberOfDaysHoursMinutesSecondsInAYear {

	short ReadYear(string Message) {
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

	short NumberOfHoursInAYear(short Year) {
		return NumberOfDaysInAYear(Year) * 24;
	}

	int NumberOfMinutesInAYear(short Year) {
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear(short Year) {
		return NumberOfMinutesInAYear(Year) * 60;
	}

	void Task() {

		short Year = ReadYear("Please enter a year to check? ");


		cout << "\nNumber of Days    in Year [" << Year << "] is "
			<< NumberOfDaysInAYear(Year) << endl;
		cout << "\nNumber of Hours   in Year [" << Year << "] is "
			<< NumberOfHoursInAYear(Year) << endl;
		cout << "\nNumber of Minutes in Year [" << Year << "] is "
			<< NumberOfMinutesInAYear(Year) << endl;
		cout << "\nNumber of Seconds in Year [" << Year << "] is "
			<< NumberOfSecondsInAYear(Year) << endl;

	}


}
