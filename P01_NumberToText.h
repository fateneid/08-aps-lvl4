#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace P01_NumberToText {

	int ReadNumber(string Message) {
		int Number;
		cout << Message;
		cin >> Number;
		return Number;
	}

	void WriteNumber(int Num, string OneToNine[9], string ElevenToNineteen[10], string ThirtyToNinety[8], string AboveHundred[8]) {

		string ReverseNumberString = ReverseNumberInString(Num);

		if (ReverseNumberString.length() == 1) {

			for (short i = 1; i <= 9; i++) {
				if (stoi(ReverseNumberString) == i) {
					cout << OneToNine[i - 1] << " ";
				}
			}
		}
		//else if()


	}

	void Num(int Num, string OneToNine[9], string ElevenToNineteen[10], string ThirtyToNinety[8], string AboveHundred[8]) {

		//static short Counter = 1;
		string ReverseNumberString = ReverseNumberInString(Num);

	/*	if (Counter == 1) {
			for (short i = 1; i <= 9; i++) {
				if (ReverseNumberString[0] - '0' == i) {
					cout << OneToNine[i - 1] << " ";
				}
			}
		}
		else if (Counter == 2 && ReverseNumberString[1] - '0' == 1) {
			cout<< ElevenToNineteen[(firstNumAsString - '0') -1]
		}*/

		for (short i = 0; i < ReverseNumberString.length(); i++) {

			if (ReverseNumberString.length() == 1) {
				cout << OneToNine[(ReverseNumberString[i] - '0') - 1];
			}
			else if (i == 1 && ReverseNumberString[1] - '0' == 1) {
				cout << ElevenToNineteen[(ReverseNumberString[0] - '0') - 1];
			}
			else if (i == 1 && ReverseNumberString[1] - '0' >= 2 && ReverseNumberString[1] - '0' <= 9) {
				cout << ThirtyToNinety[ReverseNumberString[1] - '0' - 2] << " "
					<< OneToNine[(ReverseNumberString[0] - '0') - 1];
			}
			else if (i == 2 && ReverseNumberString[1] - '0' == 0 && ReverseNumberString[0] - '0' == 0) {
				cout << OneToNine[(ReverseNumberString[2] - '0') - 1] << AboveHundred[0];

			}

		}	

	}

	string ReverseNumberInString(int Num) {

		string sNum = to_string(Num);
		string ReverseNumberString = "";
		for (short i = sNum.length() - 1; i >= 0; i--) {
			ReverseNumberString += sNum[i];
		}
		return ReverseNumberString;
	}


	void Task() {

		int Number = ReadNumber("Enter a Number? ");  //5843

		string OneToNine[9] = { "One", "Two", "Three", "Four", "Five", "six", "Seven", "Eight", "Nine" };
		string ElevenToNineteen[9] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		string ThirtyToNinety[8] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		string AboveHundred[8] = { "Hundred","Thousand","Million","Billion","Trillion" };

		//WriteNumber(Number, OneToNine);
		
		cout << ReverseNumberInString(Number);

		// 0->10 as them 
		// 11->19 the second num 1
		// if the second num 2,3,4,5,6,7,8,9 and the first from 1->9
		// handred  the third num from OneToNine and then the other two from OneToNine, ElevenToNineteen

	}


}

