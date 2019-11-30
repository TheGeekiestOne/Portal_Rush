 //Program name: Board.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Implementation file for the board class. This class contains
//integers to hold the number of locationXs, locationYs, portals, turrets,
//bombs, and ammo on the board. The initial number of skeletons is also
//set. Step counters and boolean variables to tell if the player has
//won or lost the game are also available. The board itself is a
//space triple pointer called gameBoard. Function definitions are
//available in the header file.

#include "Board.hpp"
#include "Space.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "FreeSpace.hpp"
#include "Portal.hpp"
#include "Trap.hpp"
#include "InputValidator.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::rand;

Board::Board(Player* p) {
	numRowsX = 20;
	numColsY = 20;
	numPortals = 10;
	numTurrets = 10;
	numBombs = 15;
	numAmmo = 25;
	numSkeletons = 7;
	stepsLose = 300;
	stepsWin = 11;
	hasWon = false;
	hasLost = false;


	//initialize all of the spaces
	gameBoard = new Space * *[numRowsX];
	for (int i = 0; i < numRowsX; i++) {
		gameBoard[i] = new Space * [numColsY];
	}

	//set the spaces equal to null
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			gameBoard[i][j] = nullptr;
		}
	}

	//Reassign the spaces appropriately
	for (int i = 0; i < numPortals; i++) {
		this->placeTurret();
	}

	for (int i = 0; i < numTurrets; i++) {
		this->placePortal();
	}

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j] == nullptr) {
				gameBoard[i][j] = new FreeSpace;
			}
		}
	}

	//Set NESW pointers for the spaces
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			//top left corner
			if (i == 0 && j == 0) {
				//gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				//gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//top right corner
			else if (i == 0 && j == numColsY - 1) {
				//gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				//gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//top border
			else if (i == 0) {
				//gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//bottom left corner
			else if (i == numRowsX - 1 && j == 0) {
				gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				//gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				//gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//bottom right corner
			else if (i == numRowsX - 1 && j == numColsY - 1) {
				gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				//gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				//gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//bottom border
			else if (i == numRowsX - 1) {
				gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				//gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//left border
			else if (j == 0) {
				gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				//gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//right border
			else if (j == numColsY - 1) {
				gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				//gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}

			//all interior spaces
			else {
				gameBoard[i][j]->setNorth(gameBoard[i - 1][j]);
				gameBoard[i][j]->setEast(gameBoard[i][j + 1]);
				gameBoard[i][j]->setSouth(gameBoard[i + 1][j]);
				gameBoard[i][j]->setWest(gameBoard[i][j - 1]);
			}
		}
	}

	//Distribute items
	for (int i = 0; i < numBombs; i++) {
		this->placeBombs();
	}

	for (int i = 0; i < numAmmo; i++) {
		this->placeAmmo();
	}

	this->placeOrb();

	//place skeletons
	for (int i = 0; i < numSkeletons; i++) {
		this->placeSkeleton();
	}

	//place player
	this->placePlayer(p);
}

//Board::Board(Player p, int locationXs, int locationYs, int portals, int turrets, int bombs, int ammo, int skeletons) { }

void Board::placePortal() {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j] == nullptr) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoard[i][j] == nullptr) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						gameBoard[i][j] = new Portal;
					}
				}
			}
		}
	}
}

void Board::placeTurret() {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j] == nullptr) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoard[i][j] == nullptr) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						gameBoard[i][j] = new Trap;
					}
				}
			}
		}
	}
}

void Board::placeBombs() {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSpaceType() == 'n' && gameBoard[i][j]->getHasItem() == false) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoard[i][j]->getSpaceType() == 'n' && gameBoard[i][j]->getHasItem() == false) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						gameBoard[i][j]->setHasItem(true);
						gameBoard[i][j]->setItem('b');
					}
				}
			}
		}
	}
}

void Board::useBomb(int x, int y) {
	int skeletonsDestroyed = 0;

	for (int i = (x - 3); i < (x + 4); i++) {
		for (int j = (y - 3); j < (y + 4); j++) {
			if (i > -1 && i < numRowsX && j > -1 && j < numColsY) {
				if (gameBoard[i][j]->getSkeletonInSpace() != nullptr) {
					delete gameBoard[i][j]->getSkeletonInSpace();
					gameBoard[i][j]->setSkeletonInSpace(nullptr);
					skeletonsDestroyed += 1;
				}
			}
		}
	}

	if (skeletonsDestroyed == 1) {
		cout << "The bomb destroyed " << skeletonsDestroyed << " skeleton.\n";
	}
	else if (skeletonsDestroyed > 1) {
		cout << "The bomb destroyed " << skeletonsDestroyed << " skeletons.\n";
	}
	else {
		cout << "The bomb missed.\n";
	}
}

void Board::placeAmmo() {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSpaceType() == 'n' && gameBoard[i][j]->getHasItem() == false) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoard[i][j]->getSpaceType() == 'n' && gameBoard[i][j]->getHasItem() == false) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						gameBoard[i][j]->setHasItem(true);
						gameBoard[i][j]->setItem('a');
					}
				}
			}
		}
	}
}

void Board::placeOrb() {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSpaceType() == 'n' && gameBoard[i][j]->getHasItem() == false) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoard[i][j]->getSpaceType() == 'n' && gameBoard[i][j]->getHasItem() == false) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						gameBoard[i][j]->setHasItem(true);
						gameBoard[i][j]->setItem('r');
					}
				}
			}
		}
	}
}

void Board::placeSkeleton() {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getPlayerInSpace() == nullptr) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoard[i][j]->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getPlayerInSpace() == nullptr) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						Enemy* tempSkeleton = new Enemy(i, j);
						gameBoard[i][j]->setSkeletonInSpace(tempSkeleton);
					}
				}
			}
		}
	}
}

void Board::moveSkeletons(Player* p) {
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSkeletonInSpace() != nullptr && gameBoard[i][j]->getSkeletonInSpace()->getHasMoved() == false) {
				//Create a temp skeleton variable, move it
				bool alreadyOccupied = false;
				Enemy* tempSkeleton = gameBoard[i][j]->getSkeletonInSpace();
				tempSkeleton->move(*p);
				int tempXLocation = tempSkeleton->getXLocation();
				int tempYLocation = tempSkeleton->getYLocation();

				//test to see whether it moved into another skeleton
				if (gameBoard[tempXLocation][tempYLocation]->getSkeletonInSpace() != nullptr) {
					alreadyOccupied = true;
				}

				//If it didn't, move the tempSkeleton to the new space, set old space skeleton pointer to null
				if (alreadyOccupied == false) {
					gameBoard[tempXLocation][tempYLocation]->setSkeletonInSpace(tempSkeleton);
					gameBoard[i][j]->setSkeletonInSpace(nullptr);
				}

				//If it did, reset xLocation and yLocation (skeleton doesn't move)
				else {
					tempSkeleton->setXLocation(i);
					tempSkeleton->setYLocation(j);
				}
			}
		}
	}

	//reset hasMoved after looping through the whole board
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSkeletonInSpace() != nullptr) {
				gameBoard[i][j]->getSkeletonInSpace()->setHasMoved(false);
			}
		}
	}
}

void Board::placePlayer(Player* p) {
	int eligibleSpaces = 0;
	int chosenSpace;
	int tempSpace = 0;

	//loop through the interior spaces, find one that is not on or adjacent to an skeleton
	for (int i = 1; i < numRowsX - 1; i++) {
		for (int j = 1; j < numColsY - 1; j++) {
			if (gameBoard[i][j]->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getNorth()->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getEast()->getSkeletonInSpace() == nullptr
				&& gameBoard[i][j]->getSouth()->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getWest()->getSkeletonInSpace() == nullptr) {
				eligibleSpaces += 1;
			}
		}
	}

	if (eligibleSpaces > 0) {
		chosenSpace = rand() % eligibleSpaces + 1;

		for (int i = 1; i < numRowsX - 1; i++) {
			for (int j = 1; j < numColsY - 1; j++) {
				if (gameBoard[i][j]->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getNorth()->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getEast()->getSkeletonInSpace() == nullptr
					&& gameBoard[i][j]->getSouth()->getSkeletonInSpace() == nullptr && gameBoard[i][j]->getWest()->getSkeletonInSpace() == nullptr) {
					tempSpace += 1;

					if (tempSpace == chosenSpace) {
						//special case if this is the first time the player is being placed (not from portal)
						if (p->getYLocation() == -1 && p->getXLocation() == -1) {
							p->setXLocation(i);
							p->setYLocation(j);
							gameBoard[i][j]->setPlayerInSpace(p);
						}
						//If player is coming from portal, 
						else {
							gameBoard[p->getXLocation()][p->getYLocation()]->setPlayerInSpace(nullptr);
							p->setXLocation(i);
							p->setYLocation(j);
							gameBoard[i][j]->setPlayerInSpace(p);
						}
					}
				}
			}
		}
	}

	else {
		if (p->getYLocation() == -1 && p->getXLocation() == -1) {
			cout << "Error - invalid input conditions. No safe space to place player object to begin game.\n";
		}
		else {
			cout << "Error - portal could not find a safe space to place the player. Shutting down portal.\n";
		}
	}
}

void Board::movePlayer(Player* p) {
	int direction;
	bool validInt = false;
	int tempXLocation = p->getXLocation();
	int tempYLocation = p->getYLocation();

	//output menu
	cout << "Pick a direction to move\n";
	cout << "1. North\n";
	cout << "2. East\n";
	cout << "3. South\n";
	cout << "4. West\n";
	cout << "5. Don't move\n";

	//validate input
	while (validInt == false) {
		getValidInt(direction);

		if (direction < 1 && direction > 4) {
			cout << "Invalid input - please enter an integer between 1 and 4\n";
		}
		else if (direction == 1 && tempXLocation == 0) {
			cout << "Invalid input - you are against the top xLocation and cannot move North. Please enter a different direction\n";
		}
		else if (direction == 2 && tempYLocation == numColsY - 1) {
			cout << "Invalid input - you are against the far right locationY and cannot move East. Please enter a different direction\n";
		}
		else if (direction == 3 && tempXLocation == numRowsX - 1) {
			cout << "Invalid input - you are against the bottom xLocation and cannot move South. Please enter a different direction\n";
		}
		else if (direction == 4 && tempYLocation == 0) {
			cout << "Invalid input - you are against the far left locationY and cannot move West. Please enter a different direction\n";
		}
		else {
			validInt = true;
		}
	}

	//change temp xLocation and yLocation based on direction
	if (direction == 1) {
		tempXLocation = tempXLocation - 1;
	}
	if (direction == 2) {
		tempYLocation = tempYLocation + 1;
	}
	if (direction == 3) {
		tempXLocation = tempXLocation + 1;
	}
	if (direction == 4) {
		tempYLocation = tempYLocation - 1;
	}

	//set playerpointer in new location to player, set old pointer to null
	if (direction != 5) {
		gameBoard[tempXLocation][tempYLocation]->setPlayerInSpace(p);
		gameBoard[p->getXLocation()][p->getYLocation()]->setPlayerInSpace(nullptr);
		p->setXLocation(tempXLocation);
		p->setYLocation(tempYLocation);
	}
}

Space* Board::getPlayerSpace() {

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getPlayerInSpace() != nullptr) {
				return gameBoard[i][j];
			}
		}
	}

	cout << "Error in Board::getPlayerSpace() - could not find space with not null player pointer.\n";
	return nullptr;
}

void Board::reduceStepsLose() {
	stepsLose -= 1;
	if (stepsLose == 0) {
		hasLost = true;
	}
}

int Board::getStepsLose() {
	return stepsLose;
}

void Board::reduceStepsWin() {
	stepsWin -= 1;
	if (stepsWin == 0) {
		hasWon = true;
	}
}

int Board::getStepsWin() {
	return stepsWin;
}

bool Board::getHasWon() {
	return hasWon;
}

bool Board::getHasLost() {
	return hasLost;
}

void Board::interact(int x, int y, Player* p) {
	if (gameBoard[x][y] != nullptr) {
		gameBoard[x][y]->interact(p, this);
	}
}

void Board::printBoard() {
	//draw top border
	cout << endl;
	for (int i = 0; i < numRowsX + 2; i++) {
		cout << "-";
	}
	cout << endl;

	//draw edges and interior spaces
	for (int i = 0; i < numRowsX; i++) {
		cout << "|";
		for (int j = 0; j < numColsY; j++) {
			gameBoard[i][j]->draw();
			if (gameBoard[i][j]->getSkeletonInSpace() != nullptr && gameBoard[i][j]->getPlayerInSpace() != nullptr) {
				hasLost = true;
			}
		}
		cout << "|\n";
	}

	//draw bottom border
	for (int i = 0; i < numRowsX + 2; i++) {
		cout << "-";
	}
	cout << endl;
}

Board::~Board() {
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoard[i][j]->getSkeletonInSpace() != nullptr) {
				delete gameBoard[i][j]->getSkeletonInSpace();
			}
			delete gameBoard[i][j];
		}
	}

	for (int i = 0; i < numRowsX; i++) {
		delete[]gameBoard[i];
	}
	delete[]gameBoard;
}