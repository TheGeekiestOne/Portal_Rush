 
//Program name: Portal.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the Portal class. This class
//derives from the Space class. Interacting with this class involves
//asking the player if they would like to activate the portal. If
//they do, they are randomly placed on a space with no adjacent
//skeletons. Function definitions available in the header file.
 

#include "Space.hpp"
#include "Portal.hpp"
#include "Board.hpp"
#include "InputValidator.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Portal::interact(Player* p, Board* b) {
	int activatePortal;
	bool validInt = false;

	cout << "Would you like to activate the portal?\n";
	cout << "1. Yes\n";
	cout << "2. No\n";

	while (validInt == false) {
		getValidInt(activatePortal);

		if (activatePortal < 1 || activatePortal > 2) {
			cout << "Invalid input - please enter 1 or 2\n";
		}

		else {
			validInt = true;
		}
	}

	if (activatePortal == 1) {
		b->placePlayer(p);
	}
}

void Portal::print() {
	if (playerInSpace != nullptr && skeletonInSpace != nullptr) {
		cout << "!";
	}

	else if (playerInSpace != nullptr) {
		cout << "X";
	}

	else if (skeletonInSpace != nullptr) {
		cout << "^";
	}

	else {
		cout << "O";
	}
}

char Portal::getSpaceType() {
	return 'w';
}