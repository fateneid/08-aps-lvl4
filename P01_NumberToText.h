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

	void NumberToTextFor3Digits(string NumInString) {

		string OneToNine[9] = { "One", "Two", "Three", "Four", "Five", "six", "Seven", "Eight", "Nine" };
		string ElevenToNineteen[9] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string TenToNinety[9] = { "Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

		if (NumInString.length() == 1) {

			if (NumInString[0] - '0' == 0) {
				cout << "Zero";
			}
			else {
				cout << OneToNine[(NumInString[0] - '0') - 1];
			}

		}

		else if (NumInString.length() == 2) {

			if (NumInString[0] - '0' == 0 && NumInString[1] - '0' != 0) {      //0_
				cout << OneToNine[(NumInString[1] - '0') - 1];
			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 0) { //_0  
				cout << TenToNinety[(NumInString[0] - '0') - 1];

			}
			else if (NumInString[0] - '0' == 1 && NumInString[1] - '0' != 0) { //__  11->19
				cout << ElevenToNineteen[(NumInString[1] - '0') - 1];

			}
			else if (NumInString[0] - '0' >= 2 && NumInString[1] - '0' != 0) { //__  21->99
				cout << TenToNinety[(NumInString[0] - '0') - 1]
					<< " " << OneToNine[(NumInString[1] - '0') - 1];

			}

		}

		else if (NumInString.length() == 3) {

			if (NumInString[0] - '0' == 0 && NumInString[1] - '0' == 0 && NumInString[2] - '0' != 0) { //00_
				cout << OneToNine[(NumInString[2] - '0') - 1];
			}
		    else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 0 && NumInString[2] - '0' == 0) { //_00
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred";

			}
			else if (NumInString[0] - '0' == 0 && NumInString[1] - '0' != 0 && NumInString[2] - '0' == 0) { //0_0  
				cout << TenToNinety[(NumInString[1] - '0') - 1];  

			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' != 0 && NumInString[2] - '0' == 0) { //__0
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< TenToNinety[(NumInString[1] - '0') - 1];

			}
			else if (NumInString[0] - '0' == 0 && NumInString[1] - '0' == 1 && NumInString[2] - '0' != 0) { //0__  11->19
				cout << ElevenToNineteen[(NumInString[2] - '0') - 1];

			}
			else if (NumInString[0] - '0' == 0 && NumInString[1] - '0' >= 2 && NumInString[2] - '0' != 0) { //0__  21->99
				cout << TenToNinety[(NumInString[1] - '0') - 1]
					<< " " << OneToNine[(NumInString[2] - '0') - 1];

			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 0 && NumInString[2] - '0' != 0) { //_0_
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< OneToNine[(NumInString[2] - '0') - 1];
			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 1 && NumInString[2] - '0' != 0) { //___  111->919 no zeros the second is always 1
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< ElevenToNineteen[(NumInString[2] - '0') - 1];

			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' >= 2 && NumInString[2] - '0' != 0) { //___  121->999 no zeros
				cout << OneToNine[(NumInString[0] - '0') - 1] << " Hundred "
					<< TenToNinety[(NumInString[1] - '0') - 1]
					<< " " << OneToNine[(NumInString[2] - '0') - 1];

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

	void NumberToText(long long int Number) {

		string AboveHundred[6] = { "", "Thousand","Million","Billion","Trillion","Quadrillion" };

		vector<string> Groups = ConvertNumInto3DigitsGroups(Number);

		short NumberOfGroups = Groups.size(), Counter = 0;

		for (string& Group : Groups) {

			NumberToTextFor3Digits(Group);

			if (NumberOfGroups - Counter > 0) {
				cout << " " << AboveHundred[NumberOfGroups - Counter - 1] << " ";
			}

			Counter++;

		}

	}

	void Task() {

		long long int Number = ReadNumber("Enter a Number? ");

		NumberToText(Number);
		cout << endl;


	}


}

