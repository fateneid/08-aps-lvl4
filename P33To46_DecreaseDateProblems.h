#pragma once

#include <iostream>
using namespace std;

namespace P33To46_DecreaseDateProblems {

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

	stDate DecreaseDateByOneDay(stDate Date) {

		if (Date.Day == 1) { 
			if (Date.Month == 1) {
				Date.Year--;
				Date.Month = 12;
				Date.Day = 31;
			}
			else {
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
			}
		}
		else {
			Date.Day--;
		}

		return Date;

	}

	stDate DecreaseDateByXDays(stDate Date, short XDays) {

		while (XDays--) {
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;

	}

	stDate DecreaseDateByOneWeek(stDate Date) {

		Date = DecreaseDateByXDays(Date, 7);

		return Date;

	}

	stDate DecreaseDateByXWeeks(stDate Date, short XWeeks) {

		while (XWeeks--) {
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;

	}

	stDate DecreaseDateByOneMonth(stDate Date) {

		if (Date.Month == 1) {
			Date.Year--;
			Date.Month = 12;
		}
		else {
			Date.Month--;
		}

		short NumberOfDaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInMonth) {
			Date.Day = NumberOfDaysInMonth;
		}

		return Date;

	}

	stDate DecreaseDateByXMonths(stDate Date, short XMonths) {

		while (XMonths--) {
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;

	}

	stDate DecreaseDateByOneYear(stDate Date) {

		Date.Year--;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate DecreaseDateByXYears(stDate Date, short XYears) {

		while (XYears--) {
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;

	}

	stDate DecreaseDateByXYearsFaster(stDate Date, short XYears) {

		Date.Year -= XYears;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate DecreaseDateByOneDecade(stDate Date) {

		Date.Year -= 10;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate DecreaseDateByXDecades(stDate Date, short XDecades) {

		while (XDecades--) {
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;

	}

	stDate DecreaseDateByXDecadesFaster(stDate Date, short XDecades) {

		Date.Year -= XDecades * 10;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate DecreaseDateByOneCentury(stDate Date) {

		Date.Year -= 100;

		if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}

		return Date;

	}

	stDate DecreaseDateByOneMillennium(stDate Date) {

		Date.Year -= 1000;

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
		Date = DecreaseDateByOneDay(Date);
		cout << "\n01-Subtracting one day is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXDays(Date, 10);
		cout << "02-Subtracting 10 days is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByOneWeek(Date);
		cout << "03-Subtracting one week is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXWeeks(Date, 10);
		cout << "04-Subtracting 10 week is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByOneMonth(Date);
		cout << "05-Subtracting one month is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXMonths(Date, 5);
		cout << "06-Subtracting 5 months is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByOneYear(Date);
		cout << "07-Subtracting one year is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXYears(Date, 10);
		cout << "08-Subtracting 10 Year is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXYearsFaster(Date, 10);
		cout << "09-Subtracting 10 Year (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByOneDecade(Date);
		cout << "10-Subtracting one Decade is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXDecades(Date, 10);
		cout << "11-Subtracting 10 Decades is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByXDecadesFaster(Date, 10);
		cout << "12-Subtracting 10 Decades (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByOneCentury(Date);
		cout << "13-Subtracting One Century is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';
		Date = DecreaseDateByOneMillennium(Date);
		cout << "14-Subtracting One Millennium is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';


	}


}