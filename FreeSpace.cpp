 //Program name: FreeSpace.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the FreeSpace class. This class
//derives from the Space class. Interacting with this class involves
//picking up an item if the space contains one, or nothing if the
//space does not contain an item. Function definitions available in
//header file.

#include "Space.hpp"
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

		if (p->holdingAmmo() == true and p->holdingBomb() == true) {
			cout << "Maximum item capacity has been reached. Would you like to discard an item and take this one?\n";
			cout << "1. Yes, discard ammo\n";
			cout << "2. Yes, discard bomb\n";
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
				p->discardBomb();
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
			cout << "1. Yes, discard bomb\n";
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
				p->discardBomb();
				p->addItem(item);
				hasItem = false;
			}
		}
	}
}

void FreeSpace::draw() {
	if (playerInSpace != nullptr && skeletonInSpace != nullptr) {
		cout << "!";
	}

	else if (playerInSpace != nullptr) {
		cout << "\x1B[105mX\033[0m";
	}

	else if (skeletonInSpace != nullptr) {
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

char FreeSpace::getSpaceType() {
	return 'n';
}