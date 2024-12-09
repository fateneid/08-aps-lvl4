#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <utility>
#include <ctime>
using namespace std;

namespace P18_YourAgeInDays {

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

	short DaysFromTheBeginningOfYear(short Year, short Month, short Day) {

		short TotalDays = 0;
		for (short i = 1; i < Month; i++) {
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}
		TotalDays += Day;

		return TotalDays;

	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

		return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
			(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);

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

	stDate GetCurrentDate() {

		stDate CurrentDate;

		time_t t = time(0);
		tm* now = localtime(&t);

		CurrentDate.Day = now->tm_mday;
		CurrentDate.Month = now->tm_mon + 1;
		CurrentDate.Year = now->tm_year + 1900;

		return CurrentDate;

	}

	void Task() {

		cout << "Please Enter Your Date of Birth:\n\n";
		stDate BirthDate = ReadFullDate();
		stDate CurrentDate = GetCurrentDate();

		cout << "\nYour Age is : " << GetDiffrenceInDays(CurrentDate, BirthDate) << " Day(s).\n";



	}


}
