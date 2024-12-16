#pragma once

#include <iostream>
using namespace std;

namespace P56_IsDate1AfterDate2 {

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

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

		return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
			(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);

	}

	bool IsDate1EqualsToDate2(stDate Date1, stDate Date2) {
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	bool IsDate1AfterDate2(stDate Date1, stDate Date2) {

		return !(IsDate1BeforeDate2(Date1, Date2) || IsDate1EqualsToDate2(Date1, Date2));

		//return (Date1.Year > Date2.Year) || (Date1.Year == Date2.Year && Date1.Month > Date2.Month) ||
		//	(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day > Date2.Day);

	}

	void Task() {

		cout << "Enter Date1:\n";
		stDate Date1 = ReadFullDate();

		cout << "\nEnter Date2:\n";
		stDate Date2 = ReadFullDate();

		cout << (IsDate1AfterDate2(Date1, Date2) ? "\nYes, Date1 is After Date2.\n"
			: "\nNo, Date1 is NOT After Date2.\n");



	}


}
  