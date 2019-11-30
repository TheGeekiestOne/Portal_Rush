 //Program name: Portal.cpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for the Portal class. This class derives from the Space class. Interacting with this class involves
//asking the player if they would like to activate the portal. If they do, they are randomly placed on a space with no adjacent skeletons.

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

void Portal::draw() {
	if (playerInTile != nullptr && skeletonInTile != nullptr) {
		cout << "!";
	}

	else if (playerInTile != nullptr) {
		cout << "X";
	}

	else if (skeletonInTile != nullptr) {
		cout << "^";
	}

	else {
		cout << "\x1B[94mO\033[0m";
	}
}

char Portal::getSpaceType() {
	return 'w';
}