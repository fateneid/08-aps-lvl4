#pragma once

#include <iostream>
using namespace std;

namespace P20ToP32_IncreaseDateProblems {

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

	bool IsLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	short NumberOfDaysInAMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) return 0;

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) :
			((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

	}

	bool IsLastDayInMonth(stDate Date) {
		return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
	}

	bool IsLastMonthInYear(short Month) {
		return Month == 12;
	}

	stDate IncreaseDateByOneDay(stDate Date) {

		if (IsLastDayInMonth(Date)) {

			if (IsLastMonthInYear(Date.Month)) {
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}
		}
		else {
			Date.Day++;
		}

		return Date;

	}

	stDate IncreaseDateByXDays(stDate Date, short XDays) {

		while (XDays--) {
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;

	}

	stDate IncreaseDateByOneWeek(stDate Date) {

		Date = IncreaseDateByXDays(Date, 7);

		return Date;

	}

	stDate IncreaseDateByXWeeks(stDate Date, short XWeeks) {

		while (XWeeks--) {
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;

	}

	stDate IncreaseDateByOneMonth(stDate Date) {

		if (Date.Month == 12) {
			Date.Year++;
			Date.Month = 1;
		}
		else {
			Date.Month++;
		}
		short NumberOfDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInMonth) {
			Date.Day = NumberOfDaysInMonth;
		}

		return Date;

	}

	stDate IncreaseDateByXMonths(stDate Date, short XMonths) {

		while (XMonths--) {
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;

	}

	stDate IncreaseDateByOneYear(stDate Date) {

		Date.Year++;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate IncreaseDateByXYears(stDate Date, short XYears) {

		while (XYears--) {
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;

	}

	stDate IncreaseDateByXYearsFaster(stDate Date, short XYears) {

		Date.Year += XYears;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate IncreaseDateByOneDecade(stDate Date) {

		Date.Year += 10;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate IncreaseDateByXDecades(stDate Date, short XDecades) {

		while (XDecades--) {
			Date = IncreaseDateByOneDecade(Date);
		}

		return Date;

	}

	stDate IncreaseDateByXDecadesFaster(stDate Date, short XDecades) {

		Date.Year += XDecades * 10;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate IncreaseDateByOneCentury(stDate Date) {

		Date.Year += 100;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate IncreaseDateByOneMillennium(stDate Date) {

		Date.Year += 1000;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate ReadFullDate() {
		stDate Date;
		Date.Day = ReadNumber("Please enter a Day? ");
		Date.Month = ReadNumber("Please enter a Month? ");
		Date.Year = ReadNumber("Please enter a Year? ");
		return Date;
	}

	void Task() {

		stDate Date = ReadFullDate();

		cout << "\n\nDate After:\n\n";
		Date = IncreaseDateByOneDay(Date);
		cout << "\n01-Adding one day is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXDays(Date,10);
		cout << "02-Adding 10 days is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByOneWeek(Date);
		cout << "03-Adding one week is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXWeeks(Date, 10);
		cout << "04-Adding 10 week is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByOneMonth(Date);
		cout << "05-Adding one month is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXMonths(Date, 5);
		cout << "06-Adding 5 months is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByOneYear(Date);
		cout << "07-Adding one year is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXYears(Date, 10);
		cout << "08-Adding 10 Year is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXYearsFaster(Date, 10);
		cout << "09-Adding 10 Year (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByOneDecade(Date);
		cout << "10-Adding one Decade is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXDecades(Date, 10);
		cout << "11-Adding 10 Decades is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByXDecadesFaster(Date, 10);
		cout << "12-Adding 10 Decades (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByOneCentury(Date);
		cout << "13-Adding One Century is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = IncreaseDateByOneMillennium(Date);
		cout << "14-Adding One Millennium is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';


	}


}