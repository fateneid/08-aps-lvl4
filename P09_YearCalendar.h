#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace P09_YearCalendar {

	short ReadNumber(string Message) {
		short Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	short GetDayOrder(short Year, short Month, short Day) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	}

	bool IsLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

	}

	string GetMonthName(short Month) {

		string MonthsOfYear[12] = {
	   "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
		};

		return  MonthsOfYear[Month - 1];

	}

	void PrintMonthCalendar(short Year, short Month) {

		short DaysInAMonth = NumberOfDaysInAMonth(Year, Month);
		short Place = GetDayOrder(Year, Month, 1) * 5;

		cout << "\n  _______________" << GetMonthName(Month) << "_______________\n";
		cout << "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		for (short i = 1; i <= DaysInAMonth; i++) {

			if (i == 1) {
				cout << "  " << setw(Place) << "";
			}

			cout << setw(3) << i << "  ";
			Place += 5;

			if (Place >= 33) {
				cout << "\n  ";
				Place = 0;
			}

		}
		cout << "\n  _________________________________\n";


	}

	void PrintYearCalendar(short Year) {

		cout << "\n  _________________________________\n";
		cout << "\n\t  Calendar - " << Year;
		cout << "\n  _________________________________\n";

		for (short i = 1; i <= 12; i++) {
			PrintMonthCalendar(Year, i);
		}

	}

	void Task() {

		short Year = ReadNumber("Please enter a Year? ");
		PrintYearCalendar(Year);


	}


}
