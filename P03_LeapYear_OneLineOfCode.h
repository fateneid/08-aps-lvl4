#pragma once

#include <iostream>
using namespace std;

namespace P03_LeapYear_OneLineOfCode {

	short ReadYear(string Message) {
		short Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	bool IsLeapYear(int Number) {

		return (Number % 400 == 0) || (Number % 4 == 0 && Number % 100 != 0);

	}

	void Task() {


		int Year = ReadYear("Enter a Year? ");

		if (IsLeapYear(Year)) {
			cout << Year << " is a Leap Year!\n";
		}
		else {
			cout << Year << " is Not a Leap Year!\n";
		}


	}


}

