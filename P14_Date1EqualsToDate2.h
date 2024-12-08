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