 
//Program name: Player.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the Player class. Contains integers
//for the locationX and locationY location, and max number of items. Also
//has a vector container to hold items and a boolean to determine if
//help has been orbed for. Functions to pick up, discard, and use
//items are available. Function definitions in header file.
 

#include "Player.hpp"
#include "InputValidator.hpp"
#include "Board.hpp"
#include "Space.hpp"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

Player::Player() {
	locationX = -1;
	locationY = -1;
	maxItems = 10;
	helpOrbed = false;
}

int Player::getMaxItems() {
	return maxItems;
}

void Player::setLocationX(int r) {
	locationX = r;
}

int Player::getLocationX() {
	return locationX;
}

void Player::setLocationY(int c) {
	locationY = c;
}

int Player::getLocationY() {
	return locationY;
}

bool Player::useItem(Board& b) {
	int useItem;
	char itemUsed;
	bool validInt = false;

	if (items.size() == 0) {
		cout << "You are out of items.\n";
		return false;
	}
	else if (items.size() == 1 && items[0] == 'r' && helpOrbed == true) {
		cout << "You are only holding theorb.\n";
	}
	else {
		cout << "Would you like to use an item?\n";
		cout << "1. Yes\n";
		cout << "2. No\n";

		while (validInt == false) {
			getValidInt(useItem);

			if (useItem < 1 || useItem > 2) {
				cout << "Invalid integer - please enter 1 or 2\n";
			}
			else {
				validInt = true;
			}
		}

		if (useItem == 2) {
			return false;
		}

		else {
			itemUsed = this->printPickItems();

			if (itemUsed == 'r') {
				if (helpOrbed == false) {
					helpOrbed = true;
					cout << "You have used the orb\n";
				}
				else {
					cout << "You have already called for help with the orb. Reinforcements are coming as fast as they can!\n";
				}
				return false;
			}

			else if (itemUsed == 'a') {
				this->useBow(b);
				return true;
			}
			else if (itemUsed == 'b') {
				this->useBomb(b);
				return true;
			}
		}
	}
	return false;
}

char Player::printPickItems() {
	char itemToUse;
	bool validChar = false;
	int numBombs = 0;
	int numAmmo = 0;
	bool holdingOrb = false;

	for (int i = 0; i < items.size(); i++) {
		if (items[i] == 'a') {
			numAmmo += 1;
		}
		else if (items[i] == 'b') {
			numBombs += 1;
		}
		else if (items[i] == 'r') {
			holdingOrb = true;
		}
	}

	cout << "You have " << numBombs << " bombs left, " << numAmmo << " bow ammo left, and are";

	if (holdingOrb == false) {
		cout << " not";
	}

	cout << " holding the orb.\n";

	if (helpOrbed == true) {
		cout << " You have already called for help with the orb.\n";
	}
	else if (holdingOrb == true) {
		cout << "You have not yet called for help with the orb.\n";
	}

	cout << "Please choose which item to use. Enter 'r' to use the orb, 'a' to use the bow, 'b' to use a bomb,\n";
	cout << "or 'n' to not use any items.\n";

	while (validChar == false) {
		getValidChar(itemToUse);

		if (itemToUse == 'a' && numAmmo == 0) {
			cout << "Invalid selection - no bow ammo remaining\n";
		}
		else if (itemToUse == 'b' && numBombs == 0) {
			cout << "Invalid selection - no bombs remaining\n";
		}
		else if (itemToUse == 'r' && holdingOrb == false) {
			cout << "Invalid selection - you are not holding the orb\n";
		}
		else {
			if (itemToUse == 'a' || itemToUse == 'b' || itemToUse == 'r' || itemToUse == 'n') {
				validChar = true;
			}
			else {
				cout << "Invalid character - please enter 'a', 'b', 'r', or 'n'\n";
			}
		}
	}

	return itemToUse;
}

void Player::useBow(Board& b) {
	int direction;
	bool skeletonDestroyed = false;
	bool validInt = false;
	Space* tempSpace = b.getPlayerSpace();

	//remove 1 ammo
	this->discardAmmo();

	//get direction to fire
	cout << "Please select a direction to fire\n";
	cout << "1. North\n";
	cout << "2. East\n";
	cout << "3. South\n";
	cout << "4. West\n";

	//validate
	while (validInt == false) {
		getValidInt(direction);

		if (direction < 1 || direction > 4) {
			cout << "Invalid input - please enter an integer between 1 and 4\n";
		}

		else {
			validInt = true;
		}
	}

	//delete skeletons depending on direction chosen
	if (direction == 1) {
		//loop until the edge of the board is reached, or skeleton is destroyed
		while (tempSpace != nullptr && skeletonDestroyed == false) {
			//delete an skeleton if it exists
			if (tempSpace->getSkeletonInSpace() != nullptr) {
				delete tempSpace->getSkeletonInSpace();
				tempSpace->setSkeletonInSpace(nullptr);
				skeletonDestroyed = true;
			}

			//move north
			tempSpace = tempSpace->getNorth();
		}
	}
	else if (direction == 2) {
		//loop until the edge of the board is reached
		while (tempSpace != nullptr && skeletonDestroyed == false) {
			//delete an skeleton if it exists
			if (tempSpace->getSkeletonInSpace() != nullptr) {
				delete tempSpace->getSkeletonInSpace();
				tempSpace->setSkeletonInSpace(nullptr);
				skeletonDestroyed = true;
			}

			//move east
			tempSpace = tempSpace->getEast();
		}
	}
	else if (direction == 3) {
		//loop until the edge of the board is reached
		while (tempSpace != nullptr && skeletonDestroyed == false) {
			//delete an skeleton if it exists
			if (tempSpace->getSkeletonInSpace() != nullptr) {
				delete tempSpace->getSkeletonInSpace();
				tempSpace->setSkeletonInSpace(nullptr);
				skeletonDestroyed = true;
			}

			//move south
			tempSpace = tempSpace->getSouth();
		}
	}
	else if (direction == 4) {
		//loop until the edge of the board is reached
		while (tempSpace != nullptr && skeletonDestroyed == false) {
			//delete an skeleton if it exists
			if (tempSpace->getSkeletonInSpace() != nullptr) {
				delete tempSpace->getSkeletonInSpace();
				tempSpace->setSkeletonInSpace(nullptr);
				skeletonDestroyed = true;
			}

			//move west
			tempSpace = tempSpace->getWest();
		}
	}

	if (skeletonDestroyed == true) {
		cout << "The bow destroyed a skeleton.\n";
	}
	else {
		cout << "The bow missed.\n";
	}
}

void Player::useBomb(Board& b) {
	//remove 1 ammo
	this->discardBomb();

	//call a board function to calculate what is destroyed
	b.useBomb(locationX, locationY);
}

bool Player::holdingAmmo() {
	bool ammoExists = false;

	if (items.empty() == false) {
		for (int i = 0; i < items.size(); i++) {
			if (items[i] == 'a') {
				ammoExists = true;
			}
		}
	}
	return ammoExists;
}

bool Player::holdingBomb() {
	bool bombExists = false;

	if (items.empty() == false) {
		for (int i = 0; i < items.size(); i++) {
			if (items[i] == 'b') {
				bombExists = true;
			}
		}
	}

	return bombExists;
}

void Player::addItem(char c) {
	items.push_back(c);
	cout << "You are now holding " << items.size() << " items out of a maximum of " << maxItems << " items.\n";
}

void Player::discardBomb() {
	bool itemDiscarded = false;

	for (int i = 0; i < items.size(); i++) {
		if (items[i] == 'b' and itemDiscarded == false) {
			vector<char>::iterator tempIterator = items.begin() + i;
			items.erase(tempIterator);
			itemDiscarded = true;
		}
	}
}

void Player::discardAmmo() {
	bool itemDiscarded = false;

	for (int i = 0; i < items.size(); i++) {
		if (items[i] == 'a' and itemDiscarded == false) {
			vector<char>::iterator tempIterator = items.begin() + i;
			items.erase(tempIterator);
			itemDiscarded = true;
		}
	}
}

int Player::getNumItems() {
	return items.size();
}

bool Player::getHelpOrbed() {
	return helpOrbed;
}