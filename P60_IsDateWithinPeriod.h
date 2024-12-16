#pragma once

#include <iostream>
using namespace std;

namespace P60_IsDateWithinPeriod {

	enum enCompareDate { Before = -1, Equal = 0, After = 1 };

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

	struct  stDatePeriod {
		stDate StartDate;
		stDate EndDate;
	};

	stDatePeriod ReadDatePeriod() {
		stDatePeriod DatePeriod;
		cout << "Enter Start Date:\n\n";
		DatePeriod.StartDate = ReadFullDate();
		cout << "\nEnter End Date:\n\n";
		DatePeriod.EndDate = ReadFullDate();
		return DatePeriod;
	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

		return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
			(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);

	}

	bool IsDate1EqualsToDate2(stDate Date1, stDate Date2) {
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	enCompareDate CompareDate(stDate Date1, stDate Date2) {

		if (IsDate1BeforeDate2(Date1, Date2)) {
			return enCompareDate::Before;
		}
		else if (IsDate1EqualsToDate2(Date1, Date2)) {
			return enCompareDate::Equal;
		}
		else {
			return enCompareDate::After;
		}

	}

	bool IsDateWithinPeriod(stDatePeriod Period, stDate Date) {

		return !(CompareDate(Date, Period.StartDate) == enCompareDate::Before ||
			CompareDate(Date, Period.EndDate) == enCompareDate::After);

	}


	void Task() {

		cout << "Enter Period:\n";
		stDatePeriod Period = ReadDatePeriod(); 

		cout << "\nEnter Date to check:\n\n";   
		stDate Date = ReadFullDate();

		cout << (IsDateWithinPeriod(Period, Date) ? "\nYes, Date is Within Period\n" : "\nNo, Date is NOT Within Period\n");


	}


}