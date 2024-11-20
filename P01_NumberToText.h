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

	struct stNumbers {

		string OneToNine[9] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
		string ElevenToNineteen[9] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string TenToNinety[9] = { "Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

	};

	string NumberToTextFor3Digits(string NumInString) {

		stNumbers stNums;

		if (NumInString.length() == 1) {

			if (NumInString[0] - '0' == 0) {
				return "Zero";
			}
			else {
				return stNums.OneToNine[(NumInString[0] - '0') - 1];
			}

		}

		else if (NumInString.length() == 2) {

			if (NumInString[0] - '0' == 0 && NumInString[1] - '0' != 0) {      //0_
				return stNums.OneToNine[(NumInString[1] - '0') - 1];
			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 0) { //_0  
				return stNums.TenToNinety[(NumInString[0] - '0') - 1];

			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' != 0) {

				if (NumInString[0] - '0' == 1) {        //__  11->19
					return stNums.ElevenToNineteen[(NumInString[1] - '0') - 1];
				}
				else if (NumInString[0] - '0' >= 2) {   //__  21->99
					return stNums.TenToNinety[(NumInString[0] - '0') - 1]
						+ " " + stNums.OneToNine[(NumInString[1] - '0') - 1];
				}
			}
		}

	    else if (NumInString.length() == 3) {

			if (NumInString[0] - '0' == 0 && NumInString[1] - '0' == 0 && NumInString[2] - '0' != 0) {      //00_
				return stNums.OneToNine[(NumInString[2] - '0') - 1];
			}
		    else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 0 && NumInString[2] - '0' == 0) { //_00
				return stNums.OneToNine[(NumInString[0] - '0') - 1] + " Hundred";

			}
			else if (NumInString[0] - '0' == 0 && NumInString[1] - '0' != 0 && NumInString[2] - '0' == 0) { //0_0  
				return stNums.TenToNinety[(NumInString[1] - '0') - 1];

			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' != 0 && NumInString[2] - '0' == 0) { //__0
				return stNums.OneToNine[(NumInString[0] - '0') - 1] + " Hundred "
					+ stNums.TenToNinety[(NumInString[1] - '0') - 1];

			}
			else if (NumInString[0] - '0' == 0 && NumInString[1] - '0' != 0 && NumInString[2] - '0' != 0) { //0__  
				
				if (NumInString[1] - '0' == 1) {       //11->19
					return stNums.ElevenToNineteen[(NumInString[2] - '0') - 1];

				}
				else if (NumInString[1] - '0' >= 2) {  //21->99
					return stNums.TenToNinety[(NumInString[1] - '0') - 1]
						+ " " + stNums.OneToNine[(NumInString[2] - '0') - 1];
				}

			}

			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' == 0 && NumInString[2] - '0' != 0) { //_0_
				return stNums.OneToNine[(NumInString[0] - '0') - 1] + " Hundred "
					+ stNums.OneToNine[(NumInString[2] - '0') - 1];
			}
			else if (NumInString[0] - '0' != 0 && NumInString[1] - '0' != 0 && NumInString[2] - '0' != 0) {  //___  

				if (NumInString[1] - '0' == 1) {       //111->919 no zeros - the second is always one
					return stNums.OneToNine[(NumInString[0] - '0') - 1] + " Hundred "
						+ stNums.ElevenToNineteen[(NumInString[2] - '0') - 1];
				}
				else if (NumInString[1] - '0' >= 2) {  //121->999 no zeros
					return stNums.OneToNine[(NumInString[0] - '0') - 1] + " Hundred "
						+ stNums.TenToNinety[(NumInString[1] - '0') - 1]
						+ " " + stNums.OneToNine[(NumInString[2] - '0') - 1];
				}

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

	string NumberToText(long long int Number) {

		string AboveHundred[6] = { "", "Thousand","Million","Billion","Trillion","Quadrillion" };

		vector<string> Groups = ConvertNumInto3DigitsGroups(Number);

		short NumberOfGroups = Groups.size(), Counter = 0;

		string NumberToTextString = "";

		for (string& Group : Groups) {

			if (Group != "000") {
				NumberToTextString += NumberToTextFor3Digits(Group) + " "
					+ AboveHundred[NumberOfGroups - Counter - 1] + " ";
			}

			Counter++;

		}

		while (NumberToTextString.back() == ' ') {
			NumberToTextString.pop_back();
		}

		return NumberToTextString;

	}

	void Task() {

		long long int Number = ReadNumber("Enter a Number? ");

		
		cout << NumberToText(Number) << endl;


	}


}

