#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace P01_NumberToText {

	long long int ReadNumber(string Message) {
		long long int Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	void NumberToTextFor3Digits(string NumInString, string OneToNine[9], string ElevenToNineteen[9], string ThirtyToNinety[8]) {

		if (NumInString.length() == 1) {

			if (NumInString[0] - '0' == 0) {
				cout << "Zero";
			}
			else {
				cout << OneToNine[(NumInString[0] - '0') - 1];
			}

		}

		else if (NumInString.length() == 2) {

			if (NumInString[0] - '0' == 0) {
				cout << OneToNine[(NumInString[1] - '0') - 1];
			}
		    else if (NumInString[0] - '0' == 1 && NumInString[1] - '0' == 0) {
				cout << "Ten";
			}
		    else if ( NumInString[0] - '0' == 1 && NumInString[2] - '0' != 0) {
				cout << ElevenToNineteen[(NumInString[1] - '0') - 1];
			}
			else if (NumInString[0] - '0' >= 2 && NumInString[0] - '0' <= 9) {
				cout << ThirtyToNinety[NumInString[0] - '0' - 2] << " "
					<< OneToNine[(NumInString[1] - '0') - 1];
			}

		}

		else if (NumInString.length() == 3) {

			if (NumInString[0] - '0' == 0 && NumInString[1] - '0' == 0) {
				cout << OneToNine[(NumInString[2] - '0') - 1];
			}
		    else if (NumInString[1] - '0' == 0 && NumInString[2] - '0' == 0) {
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred";

			}
			else if (NumInString[1] - '0' == 1 && NumInString[2] - '0' == 0) {
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< "Ten";
			}
			else if (NumInString[1] - '0' == 1 && NumInString[2] - '0' != 0) {
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< ElevenToNineteen[(NumInString[2] - '0') - 1];
			}
			else if (NumInString[1] - '0' >= 2 && NumInString[1] - '0' <= 9) {
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< ThirtyToNinety[NumInString[1] - '0' - 2] << " "
					<< OneToNine[(NumInString[2] - '0') - 1];
			}

		}

	
	}

	vector<string> ConvertNumInto3DigitsGroups(long long int Num) {

		string sNum = to_string(Num);
		vector<string>ThreeDigitsGroups;

		string Group = "";

		if (sNum.length() <= 3) {
			Group = sNum;
			ThreeDigitsGroups.push_back(Group);
		}

		else {

			short n = sNum.length() % 3;

			if (n != 0) {
				Group = sNum.substr(0, n);
				ThreeDigitsGroups.push_back(Group);
				sNum.erase(0, n);
			}

			for (short i = 0; i < sNum.length(); i +=3 ) {

				Group = sNum.substr(i, 3);
				ThreeDigitsGroups.push_back(Group);

			}

		}

		return ThreeDigitsGroups;

	}

	void NumberToText(long long int Number, string OneToNine[9], string ElevenToNineteen[9], string ThirtyToNinety[8], string AboveHundred[4]) {

		vector<string> Groups = ConvertNumInto3DigitsGroups(Number);

		short NumberOfGroups = Groups.size(), Counter = 0;

		for (string& Group : Groups) {

			NumberToTextFor3Digits(Group, OneToNine, ElevenToNineteen, ThirtyToNinety);

			if (NumberOfGroups - Counter > 0) {
				cout << " " << AboveHundred[NumberOfGroups - Counter - 1] << " ";
			}

			Counter++;

		}

	}

	void Task() {

		long long int Number = ReadNumber("Enter a Number? ");

		string OneToNine[9] = { "One", "Two", "Three", "Four", "Five", "six", "Seven", "Eight", "Nine" };
		string ElevenToNineteen[9] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string ThirtyToNinety[8] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		string AboveHundred[6] = { "", "Thousand","Million","Billion","Trillion","Quadrillion" };

		NumberToText(Number, OneToNine, ElevenToNineteen, ThirtyToNinety, AboveHundred);
		cout << endl;


	}


}

