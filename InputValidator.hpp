 //Program name: InputValidator.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for input validation functions

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <string>

using std::string;
 
//Takes a reference to an int as a parameter. 
void getValidInt(int& input);

//Takes a reference to a double as a parameter.
void getValidDouble(double& input);
 
//Takes a reference to a char as a parameter.
void getValidChar(char& input);
 
//Takes a reference to a string as a parameter. 
void getValidLine(string& input);
 
//Takes a reference to a string as a parameter.
void getAlphaString(string& input);

#endif