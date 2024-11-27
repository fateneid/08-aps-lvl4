#pragma once

#include <iostream>
using namespace std;

namespace P07_DayName {

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
	
	string GetDayName(short DayOrder) {

		string DaysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return DaysOfWeek[DayOrder];

	}

	void Task() {

		short Year = ReadNumber("Please enter a year? ");
		short Month = ReadNumber("\nPlease enter a Month? ");
		short Day = ReadNumber("\nPlease enter a Day? ");

		cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
		cout << "\nDay Order : " << GetDayOrder(Year, Month, Day);
		cout << "\nDay Name  : " << GetDayName(GetDayOrder(Year, Month, Day)) << endl;



	}

}
