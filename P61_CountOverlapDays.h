#pragma once

#include <iostream>
#include <utility>
using namespace std;

namespace P61_CountOverlapDays {

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

	short GetDiffrenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {

		short TotalDays = 0;

		if (!IsDate1BeforeDate2(Date1, Date2)) {
			swap(Date1, Date2);
		}

		if (Date1.Year != Date2.Year) {

			for (short i = Date1.Year; i < Date2.Year; i++) {
				TotalDays += NumberOfDaysInAYear(i);
			}

		}

		TotalDays += DaysFromTheBeginningOfYear(Date2.Year, Date2.Month, Date2.Day) -
			DaysFromTheBeginningOfYear(Date1.Year, Date1.Month, Date1.Day);

		return IncludeEndDay ? ++TotalDays : TotalDays;

	}

	short PeriodLengthInDays(stDatePeriod Period, bool IncludeEndDay = false) {
		return GetDiffrenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	short CountOverlapDays(stDatePeriod Period1, stDatePeriod Period2) {

		if (!IsOverlapPeriods(Period1, Period2)) {
			return 0;
		}

		stDatePeriod OverlapPeriod;

		OverlapPeriod.StartDate = (IsDate1BeforeDate2(Period1.StartDate, Period2.StartDate) ?
			Period2.StartDate : Period1.StartDate);

		OverlapPeriod.EndDate = (IsDate1BeforeDate2(Period1.EndDate, Period2.EndDate) ?
			Period1.EndDate : Period2.EndDate);

		return PeriodLengthInDays(OverlapPeriod);

	}

	void Task() {

		cout << "Enter Period1:\n";
		stDatePeriod Period1 = ReadDatePeriod();

		cout << "\nEnter Period2:\n";
		stDatePeriod Period2 = ReadDatePeriod();

		cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;



	}


}