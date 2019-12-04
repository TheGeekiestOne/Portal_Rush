 //Program name: Board.cpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Implementation file for the board class. This class contains integers to hold the number of locationXs, locationYs, portals, turrets,
//grenades, and ammo on the board. The initial number of skeletons is also set. Step counters and boolean variables to tell if the player has
//won or lost the game are also available. The board itself is a tile triple pointer called gameBoardLayout.

#include "Board.hpp"
#include "World.hpp"
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
	numRowsX = 20;		// number of rows(X)
	numColsY = 20;		// nuumber on colums(Y) 
	numPortals = 10;	//
	numTraps = 10;	//
	numGrenades = 15;	//
	numAmmo = 25;		//
	numSkeletons = 7;	// start amount of enemies
	stepsLose = 100;	//Turns until loss
	stepsWin = 10;		// once orb is used, turns until win
	hasWon = false;
	hasLost = false;


	//initialize all of the tiles
	gameBoardLayout = new World * *[numRowsX];
	for (int i = 0; i < numRowsX; i++) {
		gameBoardLayout[i] = new World * [numColsY];
	}

	//set the tiles equal to null
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			gameBoardLayout[i][j] = nullptr;
		}
	}

	//Reassign the tiles appropriately
	for (int i = 0; i < numPortals; i++) {
		this->placeTrap();
	}

	for (int i = 0; i < numTraps; i++) {
		this->placePortal();
	}

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j] == nullptr) {
				gameBoardLayout[i][j] = new FreeSpace;
			}
		}
	}

	//Set NESW pointers for the tiles
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			//top left corner
			if (i == 0 && j == 0) {
				gameBoardLayout[i][j]->setEast(gameBoardLayout[i][j + 1]);
				gameBoardLayout[i][j]->setSouth(gameBoardLayout[i + 1][j]);
			}

			//top right corner
			else if (i == 0 && j == numColsY - 1) {
				gameBoardLayout[i][j]->setSouth(gameBoardLayout[i + 1][j]);
				gameBoardLayout[i][j]->setWest(gameBoardLayout[i][j - 1]);
			}

			//top border
			else if (i == 0) {
				gameBoardLayout[i][j]->setEast(gameBoardLayout[i][j + 1]);
				gameBoardLayout[i][j]->setSouth(gameBoardLayout[i + 1][j]);
				gameBoardLayout[i][j]->setWest(gameBoardLayout[i][j - 1]);
			}

			//bottom left corner
			else if (i == numRowsX - 1 && j == 0) {
				gameBoardLayout[i][j]->setNorth(gameBoardLayout[i - 1][j]);
				gameBoardLayout[i][j]->setEast(gameBoardLayout[i][j + 1]);
			}

			//bottom right corner
			else if (i == numRowsX - 1 && j == numColsY - 1) {
				gameBoardLayout[i][j]->setNorth(gameBoardLayout[i - 1][j]);
				gameBoardLayout[i][j]->setWest(gameBoardLayout[i][j - 1]);
			}

			//bottom border
			else if (i == numRowsX - 1) {
				gameBoardLayout[i][j]->setNorth(gameBoardLayout[i - 1][j]);
				gameBoardLayout[i][j]->setEast(gameBoardLayout[i][j + 1]);
				gameBoardLayout[i][j]->setWest(gameBoardLayout[i][j - 1]);
			}

			//left border
			else if (j == 0) {
				gameBoardLayout[i][j]->setNorth(gameBoardLayout[i - 1][j]);
				gameBoardLayout[i][j]->setEast(gameBoardLayout[i][j + 1]);
				gameBoardLayout[i][j]->setSouth(gameBoardLayout[i + 1][j]);
			}

			//right border
			else if (j == numColsY - 1) {
				gameBoardLayout[i][j]->setNorth(gameBoardLayout[i - 1][j]);
				gameBoardLayout[i][j]->setSouth(gameBoardLayout[i + 1][j]);
				gameBoardLayout[i][j]->setWest(gameBoardLayout[i][j - 1]);
			}

			//all interior tiles
			else {
				gameBoardLayout[i][j]->setNorth(gameBoardLayout[i - 1][j]);
				gameBoardLayout[i][j]->setEast(gameBoardLayout[i][j + 1]);
				gameBoardLayout[i][j]->setSouth(gameBoardLayout[i + 1][j]);
				gameBoardLayout[i][j]->setWest(gameBoardLayout[i][j - 1]);
			}
		}
	}

	//Distribute items to the tiles
	for (int i = 0; i < numGrenades; i++) {
		this->placeGrenades();
	}

	for (int i = 0; i < numAmmo; i++) {
		this->placeAmmo();
	}

	this->placeOrb();

	//place skeletons randomly on the tiles
	for (int i = 0; i < numSkeletons; i++) {
		this->placeSkeleton();
	}

	//place player randomly to a tile
	this->placePlayer(p);
}

//place the portals on the tiles
void Board::placePortal() {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j] == nullptr) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoardLayout[i][j] == nullptr) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						gameBoardLayout[i][j] = new Portal;
					}
				}
			}
		}
	}
}

//place the traps/turrets to the tiles
void Board::placeTrap() {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j] == nullptr) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoardLayout[i][j] == nullptr) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						gameBoardLayout[i][j] = new Trap;
					}
				}
			}
		}
	}
}

//place pickeup grenade to rand tiles
void Board::placeGrenades() {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getWorldType() == 'n' && gameBoardLayout[i][j]->getHasItem() == false) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoardLayout[i][j]->getWorldType() == 'n' && gameBoardLayout[i][j]->getHasItem() == false) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						gameBoardLayout[i][j]->setHasItem(true);
						gameBoardLayout[i][j]->setItem('b');
					}
				}
			}
		}
	}
}

//when grenade is used, assign the effect to the tiles, delete enemies if inside the radius
void Board::useGrenade(int x, int y) {
	int skeletonsDestroyed = 0;

	for (int i = (x - 3); i < (x + 4); i++) {
		for (int j = (y - 3); j < (y + 4); j++) {
			if (i > -1 && i < numRowsX && j > -1 && j < numColsY) {
				if (gameBoardLayout[i][j]->getSkeletonInTile() != nullptr) {
					delete gameBoardLayout[i][j]->getSkeletonInTile();
					gameBoardLayout[i][j]->setSkeletonInTile(nullptr);
					skeletonsDestroyed += 1;
				}
			}
		}
	}

	if (skeletonsDestroyed == 1) {
		cout << "The grenade destroyed " << skeletonsDestroyed << " skeleton.\n"; //if 1 skeleton was destroyed
	}
	else if (skeletonsDestroyed > 1) {
		cout << "The grenade destroyed " << skeletonsDestroyed << " skeletons.\n"; //is more than 1 skeleton was destryoed
	}
	else {
		cout << "The grenade missed.\n"; // if not skeleton destroyed
	}
}

//place ammo randomly on the tiles
void Board::placeAmmo() {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getWorldType() == 'n' && gameBoardLayout[i][j]->getHasItem() == false) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoardLayout[i][j]->getWorldType() == 'n' && gameBoardLayout[i][j]->getHasItem() == false) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						gameBoardLayout[i][j]->setHasItem(true);
						gameBoardLayout[i][j]->setItem('a');
					}
				}
			}
		}
	}
}

//place the orba at a random location
void Board::placeOrb() {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getWorldType() == 'n' && gameBoardLayout[i][j]->getHasItem() == false) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoardLayout[i][j]->getWorldType() == 'n' && gameBoardLayout[i][j]->getHasItem() == false) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						gameBoardLayout[i][j]->setHasItem(true);
						gameBoardLayout[i][j]->setItem('r');
					}
				}
			}
		}
	}
}

//place enemies at random locations
void Board::placeSkeleton() {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getPlayerInTile() == nullptr) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 0; i < numRowsX; i++) {
			for (int j = 0; j < numColsY; j++) {
				if (gameBoardLayout[i][j]->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getPlayerInTile() == nullptr) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						Enemy* tempSkeleton = new Enemy(i, j);
						gameBoardLayout[i][j]->setSkeletonInTile(tempSkeleton);
					}
				}
			}
		}
	}
}

//u[date the move of the enemies towars the player
void Board::moveSkeletons(Player* p) {
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getSkeletonInTile() != nullptr && gameBoardLayout[i][j]->getSkeletonInTile()->getHasMoved() == false) {
				//Create a temp skeleton variable, move it
				bool alreadyOccupied = false;
				Enemy* tempSkeleton = gameBoardLayout[i][j]->getSkeletonInTile();
				tempSkeleton->move(*p);
				int tempXLocation = tempSkeleton->getXLocation();
				int tempYLocation = tempSkeleton->getYLocation();

				//test to see whether it moved into another skeleton
				if (gameBoardLayout[tempXLocation][tempYLocation]->getSkeletonInTile() != nullptr) {
					alreadyOccupied = true;
				}

				//If it didn't, move the tempSkeleton to the new tile, set old tile skeleton pointer to null
				if (alreadyOccupied == false) {
					gameBoardLayout[tempXLocation][tempYLocation]->setSkeletonInTile(tempSkeleton);
					gameBoardLayout[i][j]->setSkeletonInTile(nullptr);
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
			if (gameBoardLayout[i][j]->getSkeletonInTile() != nullptr) {
				gameBoardLayout[i][j]->getSkeletonInTile()->setHasMoved(false);
			}
		}
	}
}

void Board::placePlayer(Player* p) {
	int eligibleWorlds = 0;
	int chosenWorld;
	int tempWorld = 0;

	//loop through the interior tiles, find one that is not on or adjacent to an skeleton
	for (int i = 1; i < numRowsX - 1; i++) {
		for (int j = 1; j < numColsY - 1; j++) {
			if (gameBoardLayout[i][j]->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getNorth()->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getEast()->getSkeletonInTile() == nullptr
				&& gameBoardLayout[i][j]->getSouth()->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getWest()->getSkeletonInTile() == nullptr) {
				eligibleWorlds += 1;
			}
		}
	}

	if (eligibleWorlds > 0) {
		chosenWorld = rand() % eligibleWorlds + 1;

		for (int i = 1; i < numRowsX - 1; i++) {
			for (int j = 1; j < numColsY - 1; j++) {
				if (gameBoardLayout[i][j]->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getNorth()->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getEast()->getSkeletonInTile() == nullptr
					&& gameBoardLayout[i][j]->getSouth()->getSkeletonInTile() == nullptr && gameBoardLayout[i][j]->getWest()->getSkeletonInTile() == nullptr) {
					tempWorld += 1;

					if (tempWorld == chosenWorld) {
						//special case if this is the first time the player is being placed (not from portal)
						if (p->getYLocation() == -1 && p->getXLocation() == -1) {
							p->setXLocation(i);
							p->setYLocation(j);
							gameBoardLayout[i][j]->setPlayerInTile(p);
						}
						//If player is coming from portal, 
						else {
							gameBoardLayout[p->getXLocation()][p->getYLocation()]->setPlayerInTile(nullptr);
							p->setXLocation(i);
							p->setYLocation(j);
							gameBoardLayout[i][j]->setPlayerInTile(p);
						}
					}
				}
			}
		}
	}

	else {
		if (p->getYLocation() == -1 && p->getXLocation() == -1) {
			cout << "Error - invalid input conditions. No safe tile to place player object to begin game.\n";
		}
		else {
			cout << "Error - portal could not find a safe tile to place the player. Shutting down portal.\n";
		}
	}
}

//update player being moved to tiles
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
		gameBoardLayout[tempXLocation][tempYLocation]->setPlayerInTile(p);
		gameBoardLayout[p->getXLocation()][p->getYLocation()]->setPlayerInTile(nullptr);
		p->setXLocation(tempXLocation);
		p->setYLocation(tempYLocation);
	}
}

World* Board::getPlayerWorld() {

	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getPlayerInTile() != nullptr) {
				return gameBoardLayout[i][j];
			}
		}
	}

	cout << "Error in Board::getPlayerWorld() - could not find tile with not null player pointer.\n";
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
	if (gameBoardLayout[x][y] != nullptr) {
		gameBoardLayout[x][y]->interact(p, this);
	}
}

void Board::printBoard() {
	//draw top border
	cout << endl;
	for (int i = 0; i < numRowsX + 2; i++) {
		cout << "\x1B[93m-\033[0m";
	}
	cout << endl;

	//draw edges and interior tiles
	for (int i = 0; i < numRowsX; i++) {
		cout << "\x1B[93m|\033[0m";
		for (int j = 0; j < numColsY; j++) {
			gameBoardLayout[i][j]->draw();
			if (gameBoardLayout[i][j]->getSkeletonInTile() != nullptr && gameBoardLayout[i][j]->getPlayerInTile() != nullptr) {
				hasLost = true;
			}
		}
		cout << "\x1B[93m|\033[0m\n";
	}

	//draw bottom border
	for (int i = 0; i < numRowsX + 2; i++) {
		cout << "\x1B[93m-\033[0m";
	}
	cout << endl;
}

Board::~Board() {
	for (int i = 0; i < numRowsX; i++) {
		for (int j = 0; j < numColsY; j++) {
			if (gameBoardLayout[i][j]->getSkeletonInTile() != nullptr) {
				delete gameBoardLayout[i][j]->getSkeletonInTile();
			}
			delete gameBoardLayout[i][j];
		}
	}

	for (int i = 0; i < numRowsX; i++) {
		delete[]gameBoardLayout[i];
	}
	delete[]gameBoardLayout;
}