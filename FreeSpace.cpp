 //Program name: FreeSpace.cpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for the FreeSpace class. This class derives from the World class. Interacting with this class involves
//picking up an item if the tile contains one, or nothing if the tile does not contain an item.

#include "World.hpp"
#include "FreeSpace.hpp"
#include "InputValidator.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

FreeSpace::FreeSpace() {}

void FreeSpace::interact(Player* p, Board* b) {
	if (hasItem != false && p->getNumItems() < p->getMaxItems()) {
		int pickItem;
		bool validInt = false;

		cout << "Would you like to pick up the item?\n";
		cout << "1. Yes\n";
		cout << "2. No\n";

		while (validInt == false) {
			getValidInt(pickItem);

			if (pickItem < 1 || pickItem > 2) {
				cout << "Invalid input - please enter 1 or 2\n";
			}

			else {
				validInt = true;
			}
		}

		if (pickItem == 1) {
			p->addItem(item);
			hasItem = false;
		}
	}

	else if (hasItem != false) {
		int pickItem;
		bool validInt = false;

		if (p->holdingAmmo() == true and p->holdingGrenade() == true) {
			cout << "Maximum item capacity has been reached. Would you like to discard an item and take this one?\n";
			cout << "1. Yes, discard ammo\n";
			cout << "2. Yes, discard grenade\n";
			cout << "3. No\n";

			while (validInt == false) {
				getValidInt(pickItem);

				if (pickItem < 1 || pickItem > 3) {
					cout << "Invalid input - please enter 1, 2, or 3\n";
				}

				else {
					validInt = true;
				}
			}

			if (pickItem == 1) {
				p->discardAmmo();
				p->addItem(item);
				hasItem = false;
			}

			else if (pickItem == 2) {
				p->discardGrenade();
				p->addItem(item);
				hasItem = false;
			}
		}

		else if (p->holdingAmmo() == true) {
			cout << "Maximum item capacity has been reached. Would you like to discard an item and take this one?\n";
			cout << "1. Yes, discard ammo\n";
			cout << "2. No\n";

			while (validInt == false) {
				getValidInt(pickItem);

				if (pickItem < 1 || pickItem > 2) {
					cout << "Invalid input - please enter 1 or 2\n";
				}

				else {
					validInt = true;
				}
			}

			if (pickItem == 1) {
				p->discardAmmo();
				p->addItem(item);
				hasItem = false;
			}
		}

		else {
			cout << "Maximum item capacity has been reached. Would you like to discard an item and take this one?\n";
			cout << "1. Yes, discard grenade\n";
			cout << "2. No\n";

			while (validInt == false) {
				getValidInt(pickItem);

				if (pickItem < 1 || pickItem > 2) {
					cout << "Invalid input - please enter 1 or 2\n";
				}

				else {
					validInt = true;
				}
			}

			if (pickItem == 1) {
				p->discardGrenade();
				p->addItem(item);
				hasItem = false;
			}
		}
	}
}

void FreeSpace::draw() {
	if (playerInTile != nullptr && skeletonInTile != nullptr) {
		cout << "!";
	}

	else if (playerInTile != nullptr) {
		cout << "\x1B[105mX\033[0m";
	}

	else if (skeletonInTile != nullptr) {
		cout << "\x1B[92m^\033[0m";
	}

	else if (hasItem == false) {
		cout << " ";
	}

	else if (item == 'r') {
		cout << "|";
	}

	else if (item == 'b') {
		cout << "&";
	}

	else if (item == 'a') {
		cout << ".";
	}

	else {
		cout << "Error in FreeSpace::draw()";
	}
}

char FreeSpace::getWorldType() {
	return 'n';
}