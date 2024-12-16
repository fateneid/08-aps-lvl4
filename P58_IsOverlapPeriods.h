#pragma once

#include <iostream>
using namespace std;

namespace P58_IsOverlapPeriods {

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

	bool IsOverlapPeriods(stDatePeriod Period1, stDatePeriod Period2) {

		// e1 >= s2  &&  e2 >= s1  -> true
		// e1 < s2   ||  e2 < s1   -> false 

		return !(IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate) ||
			IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate));

	}
    
	void Task() {

		cout << "Enter Period1:\n";
		stDatePeriod Period1 = ReadDatePeriod();

		cout << "\nEnter Period2:\n";
		stDatePeriod Period2 = ReadDatePeriod();

		cout << (IsOverlapPeriods(Period1, Period2) ? "\nYes, Periods Overlap\n" : "\nNo, Periods do not Overlap\n");


	}


}