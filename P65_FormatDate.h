#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace P65_FormatDate {

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

	string FormatDate(stDate Date, string Format = "dd/mm/yyyy") {

		Format.replace(Format.find("dd"), 2, to_string(Date.Day));
		Format.replace(Format.find("mm"), 2, to_string(Date.Month));
		Format.replace(Format.find("yyyy"), 4, to_string(Date.Year));
		
		return Format;

	}

	void Task() {

		string DateString = ReadString("Please Enter Date dd/mm/yyyy? ");

		stDate Date = DateStringToStructure(DateString);

		cout << "\n" << FormatDate(Date) << "\n";
		cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
		cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
		cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
		cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
		cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";


	}


}