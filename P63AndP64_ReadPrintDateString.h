#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace P63AndP64_ReadPrintDateString {

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

	string ReadString(string Message) {
		string String;
		cout << Message;
		cin >> String;
		return String;
	}

	vector <string> SplitString(string MyString, string split) {

		string sWord;
		short pos = 0;
		vector <string> vSplitString;

		while ((pos = MyString.find(split)) != string::npos) {

			sWord = MyString.substr(0, pos);

			if (sWord != "") {
				vSplitString.push_back(sWord);
			}

			MyString.erase(0, pos + split.length());
		}

		if (MyString != "") {
			vSplitString.push_back(MyString);
		}

		return vSplitString;

	}

	stDate DateStringToStructure(string DateString) {

		stDate Date;
		vector<string> vDate = SplitString(DateString, "/");

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;

	}

	string DateStructureToString(stDate Date) {

		return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);

	}
	
	void Task() {

		string DateString = ReadString("Please Enter Date dd/mm/yyyy? ");

		stDate Date = DateStringToStructure(DateString);

		cout << "\nDay:" << Date.Day;
		cout << "\nMonth:" << Date.Month;
		cout << "\nYear:" << Date.Year;

		cout << "\n\nYou Entered: " << DateStructureToString(Date) << endl;


	}


}