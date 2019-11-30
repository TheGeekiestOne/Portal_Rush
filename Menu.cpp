 
//Program name: Menu.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the instructions functions. These
//functions simply print the scenario, instructions, and legend for
//the game. Function definitions are available in the header file.
 

#include "Menu.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;

void printIntro() {
	cout << "Welcome to Portal Rush.\n\n";

	cout << "The invasio\n";

}

void printLegend() {
	string dummyString;

	cout << "Legend:\n";
	cout << "X - Player\n";
	cout << "^ - Enemy\n";
	cout << "T - Trap\n";
	cout << "O - Portal\n";
	cout << ". - Ammo\n";
	cout << "& - Bomb\n";
	cout << "| - Orb\n";
	cout << "! - Enemy caught player\n\n";

	cout << "Press enter to begin the game.\n";
	getline(cin, dummyString);
}
