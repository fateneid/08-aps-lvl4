#pragma once

#include <iostream>
using namespace std;

namespace P02_LeapYear {

	short ReadYear(string Message) {
		short Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	bool IsLeapYear(int Number) {

		if (Number % 400 == 0 || (Number % 4 == 0 && Number % 100 != 0)) {
			return true;
		}
		else {
			return false;
		}

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