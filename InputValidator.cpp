 //Program name: InputValidator.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Implementation file for input validation functions

#include <iostream>
#include <sstream>
#include "InputValidator.hpp"

using std::endl;
using std::cin;
using std::cout;
using std::getline;
using std::stringstream;

//Takes a reference to an int as a parameter.
void getValidInt(int& input) {
	//initialize variables
	bool whileBool = false;
	char tempChar;
	string tempString;

	//stay in loop until input is validated
	while (whileBool == false) {

		//get a valid line
		getline(cin, tempString);
		stringstream cinBuffer(tempString);

		//attempt to move to input
		cinBuffer >> input;

		//Fail if there is an invalid character
		if (cinBuffer.fail()) {
			cout << "Invalid input - Please re-enter the desired integer:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		//Fail if there is an invalid character
		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - Please re-enter the desired integer:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		//Continue if everything else
		else {
			whileBool = true;
		}
	}
}

//Takes a reference to a double as a parameter.
void getValidDouble(double& input) {
	bool whileBool = false;
	char tempChar;
	string tempString;

	while (whileBool == false) {

		getline(cin, tempString);
		stringstream cinBuffer(tempString);

		cinBuffer >> input;

		if (cinBuffer.fail()) {
			cout << "Invalid input - Please re-enter the desired double:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - Please re-enter the desired double:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else {
			whileBool = true;
		}
	}
}

//Takes a reference to a char as a parameter.
void getValidChar(char& input) {
	bool whileBool = false;
	char tempChar;
	string tempString;

	while (whileBool == false) {

		getline(cin, tempString);
		stringstream cinBuffer(tempString);

		cinBuffer >> input;
		if (cin.fail()) {
			cout << "Invalid input - Please re-enter the desired character:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - Please re-enter the desired character:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else {
			whileBool = true;
		}
	}
}

//Takes a reference to a string as a parameter. The function then gets input from the user and attempts to validate it. The function will
//continue to get input until a valid line is entered.
void getValidLine(string& input) {
	bool whileBool = false;
	string tempString;

	while (whileBool == false) {

		getline(cin, tempString);
		stringstream cinBuffer(tempString);

		cinBuffer >> input;
		if (cin.fail()) {
			cout << "Invalid input - Please re-enter the desired string:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else if (input.length() == 0) {
			cout << "Invalid input - Please re-enter the desired string:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else {
			whileBool = true;
		}
	}
}
 
//Takes a reference to a string as a parameter. 
void getAlphaString(string& input) {
	bool whileBool = false;
	string tempString;
	char tempChar;

	while (whileBool == false) {

		getline(cin, tempString);
		stringstream cinBuffer(tempString);

		cinBuffer >> input;
		if (cin.fail()) {
			cout << "Invalid input - Please re-enter the desired string:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else if (input.length() == 0) {
			cout << "Invalid input - Please re-enter the desired string:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else if (cinBuffer >> tempChar) {
			cout << "Invalid input - Please re-enter the desired string:\n";
			cinBuffer.clear();
			cinBuffer.str("");
		}

		else {
			whileBool = true;
		}
	}
}