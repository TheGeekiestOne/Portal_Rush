 //Program name: Menu.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for the instructions functions. These functions simply draw the scenario, instructions, and legend for the game.

#include "Menu.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;

void printIntro() {


	cout << "\x1B[32m	_|_|_|                          _|                _|      _|_|_|                        _|        \033[0m\t\t\n";
	cout << "\x1B[32m	_|    _|    _|_|    _|  _|_|  _|_|_|_|    _|_|_|  _|      _|    _|  _|    _|    _|_|_|  _|_|_|    \033[0m\t\t\n";
	cout << "\x1B[32m	_|_|_|    _|    _|  _|_|        _|      _|    _|  _|      _|_|_|    _|    _|  _|_|      _|    _|  \033[0m\t\t\n";
	cout << "\x1B[32m	_|        _|    _|  _|          _|      _|    _|  _|      _|    _|  _|    _|      _|_|  _|    _|  \033[0m\t\t\n";
	cout << "\x1B[32m	_|          _|_|    _|            _|_|    _|_|_|  _|      _|    _|    _|_|_|  _|_|_|    _|    _|  \033[0m\t\t\n";

	cout << "Created by \x1B[41m Ayran Olckers \033[0m\t\t\n";
	
	cout << "You are a hunter trapped in a dead world.\n";
	cout << "You are been attaked by the undead and are the only one living. You are armed\n";
	cout << "with a bow, but have already used all your ammo. However, the fallen have dropped ammo\n";
	cout << "and grenades. world is also outfitted with magical portals that randomly change your location,\n";
	cout << "and bolt turrets (Traps) that can destroy all undead in a certain direction.\n";
	cout << "Your bow can only destroy the first undead in a certain direction, while your greanades\n";
	cout << " can destroy undead within a three tile radius of you.\n\n";

	cout << "The invasion is still ongoing, with more undead arriving constantly. However, you\n";
	cout << "can stop the invasion by finding an orb, that wins the game.\n";
	cout << "You need to act quickly, as the invasion will completely destroy the world in 100 turns.\n";
	cout << "You must use all of your resources and skills to accomplish this task!\n\n";

	//cout << "GOOD LUCK, and May the Force be with you!\n\n";
}



void printInstructions() {
	string dummyString;

	cout << "INSTRUCTIONS:\n";
	cout << "================================\n";
	cout << "\x1B[105mX\033[0m - Player\n";
	cout << "^ - Enemy\n";
	cout << "T - Trap/Trap\n";
	cout << "O - Portal\n";
	cout << ". - Ammo\n";
	cout << "& - Grenade\n";
	cout << "| - Orb\n";
	cout << "! - Undead caught player\n\n";

	cout << "Press enter to begin the game.\n";
	getline(cin, dummyString);
}
