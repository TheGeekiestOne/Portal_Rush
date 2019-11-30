 //Program name: Trap.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Implementation file for the Trap class. This class derives from the Space class. Interacting with this class involves
//picking a direction and destroying all skeletons in that direction (provided ammo is remaining in the turret).

#include "Space.hpp"
#include "Trap.hpp"
#include "Board.hpp"
#include "InputValidator.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Trap::Trap() {
	ammo = 5;
}

void Trap::interact(Player* p, Board* b) {
	int activateTrap;
	int direction;
	int skeletonsDestroyed = 0;
	bool validInt = false;
	Space* tempSpace = this;

	if (ammo > 0) {
		cout << "The turret has " << ammo << " bolts left. Would you like to use it?\n";
		cout << "1. Yes\n";
		cout << "2. No\n";

		while (validInt == false) {
			getValidInt(activateTrap);

			if (activateTrap < 1 || activateTrap > 2) {
				cout << "Invalid input - please enter 1 or 2\n";
			}

			else {
				validInt = true;
			}
		}

		validInt = false;

		if (activateTrap == 1) {
			ammo -= 1;

			cout << "Please select a direction to fire\n";
			cout << "1. North\n";
			cout << "2. East\n";
			cout << "3. South\n";
			cout << "4. West\n";

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
				//loop until the edge of the board is reached
				while (tempSpace != nullptr) {
					//delete an skeleton if it exists
					if (tempSpace->getSkeletonInSpace() != nullptr) {
						delete tempSpace->getSkeletonInSpace();
						tempSpace->setSkeletonInSpace(nullptr);
						skeletonsDestroyed += 1;
					}

					//move north
					tempSpace = tempSpace->getNorth();
				}
			}
			else if (direction == 2) {
				//loop until the edge of the board is reached
				while (tempSpace != nullptr) {
					//delete an skeleton if it exists
					if (tempSpace->getSkeletonInSpace() != nullptr) {
						delete tempSpace->getSkeletonInSpace();
						tempSpace->setSkeletonInSpace(nullptr);
						skeletonsDestroyed += 1;
					}

					//move east
					tempSpace = tempSpace->getEast();
				}
			}
			else if (direction == 3) {
				//loop until the edge of the board is reached
				while (tempSpace != nullptr) {
					//delete an skeleton if it exists
					if (tempSpace->getSkeletonInSpace() != nullptr) {
						delete tempSpace->getSkeletonInSpace();
						tempSpace->setSkeletonInSpace(nullptr);
						skeletonsDestroyed += 1;
					}

					//move south
					tempSpace = tempSpace->getSouth();
				}
			}
			else if (direction == 4) {
				//loop until the edge of the board is reached
				while (tempSpace != nullptr) {
					//delete an skeleton if it exists
					if (tempSpace->getSkeletonInSpace() != nullptr) {
						delete tempSpace->getSkeletonInSpace();
						tempSpace->setSkeletonInSpace(nullptr);
						skeletonsDestroyed += 1;
					}

					//move west
					tempSpace = tempSpace->getWest();
				}
			}

			if (skeletonsDestroyed == 1) {
				cout << "The turret destroyed " << skeletonsDestroyed << " skeleton.\n";
			}
			else if (skeletonsDestroyed > 1) {
				cout << "The turret destroyed " << skeletonsDestroyed << " skeletons.\n";
			}
			else {
				cout << "The turret missed.\n";
			}
		}
	}

	else {
		cout << "The turret is out of bolts.\n";
	}
}

void Trap::draw() {
	if (playerInSpace != nullptr && skeletonInSpace != nullptr) {
		cout << "!";
	}

	else if (playerInSpace != nullptr) {
		cout << "\x1B[93mX\033[0m\n";
	}

	else if (skeletonInSpace != nullptr) {
		cout << "^";
	}

	else {
		cout << "T";
	}
}

char Trap::getSpaceType() {
	return 't';
}