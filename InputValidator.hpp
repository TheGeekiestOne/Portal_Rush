 //Program name: InputValidator.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for input validation functions

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <string>

using std::string;
 
//Takes a reference to an int as a parameter. The function then gets
//input from the user and attempts to validate it. The function will
//continue to get input until a valid int is entered.
void getValidInt(int& input);

//Takes a reference to a double as a parameter. The function then gets
//input from the user and attempts to validate it. The function will
//continue to get input until a valid double is entered.
void getValidDouble(double& input);
 
//Takes a reference to a char as a parameter. The function then gets
//input from the user and attempts to validate it. The function will
//continue to get input until a valid char is entered.
void getValidChar(char& input);
 
//Takes a reference to a string as a parameter. The function then gets
//input from the user and attempts to validate it. The function will
//continue to get input until a valid line is entered.
void getValidLine(string& input);
 
//Takes a reference to a string as a parameter. The function then gets
//input from the user and attempts to validate it. The function will
//continue to get input until a valid line is entered.
void getAlphaString(string& input);

#endif