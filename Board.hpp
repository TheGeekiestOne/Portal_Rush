//Program name: Board.hpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for the board class. This class contains integers to hold the number of locationXs, locationYs, portals, turrets,
//grenades, and ammo on the board. The initial number of skeletons is also set. Step counters and boolean variables to tell if the player has
//won or lost the game are also available. The board itself is a tile triple pointer called gameBoardLayout.

#ifndef BOARD_HPP
#define BOARD_HPP

#include "World.hpp"
#include "Player.hpp"

class Board {
private:
	World*** gameBoardLayout;
	int numRowsX;
	int numColsY;
	int numPortals;
	int numTraps;
	int numGrenades;
	int numAmmo;
	int numSkeletons;
	int stepsLose;
	int stepsWin;
	bool hasWon;
	bool hasLost;

public:
	//Default constructor for the board. Creates a randomized gameboard object, and places a player parameter on that board. The randomized
	//board is based on values for the numbers of turrets, portals, grenades, and ammo. Adjusting these values will change the difficulty
	//of the game.
	Board(Player* p);

	//Randomly initializes one of the null gameBoardLayout pointers to a portal.
	void placePortal();

	//Randomly initializes one of the null gameBoardLayout pointers to a turret.
	void placeTrap();

	//Randomly changes the hasItem and item member variables of one of the gameBoardLayout pointers pointing to a FreeSpace to true and 'b'
	void placeGrenades();

	//Destroys all skeletons in a 7x7 grid centered on the xLocation input x and locationY input y.
	void useGrenade(int x, int y);

	//Randomly changes the hasItem and item member variables of one of the gameBoardLayout pointers pointing to a FreeSpace to true and 'a'
	void placeAmmo();

	//Randomly changes the hasItem and item member variables one of the gameBoardLayout pointers pointing to a FreeSpace to true and 'r'
	void placeOrb();

	//Randomly changes the skeletonInTile member variable of one of the gameBoardLayout pointers with null skeletonInTile and playerInTile pointers
	//to a new skeleton.
	void placeSkeleton();

	//Loops through the gameBoardLayout and calls move on all skeletons on the board. Uses hasMoved boolean member variable of skeleton to verify
	//each skeleton moves only once. The player object parameter must be passed for each skeleton move call.
	void moveSkeletons(Player* p);

	//Randomly places the passed player object on a board tile with no adjacent skeletons. Prints an error message if this is not possible.
	//Used for both gameBoardLayout initialization and portal interaction.
	void placePlayer(Player* p);

	//Gets and validates a direction to move the player. Changes the playerInTile member variable of the tile being pointed to the
	//player based on the desired direction.
	void movePlayer(Player* p);

	//Reduces stepsLose member variable by 1
	void reduceStepsLose();

	//Reduces stepsWin member variable by 1
	void reduceStepsWin();

	//Getters
	World* getPlayerWorld();

	int getStepsLose();

	int getStepsWin();

	bool getHasWon();

	bool getHasLost();

	//Calls the interact function of the tile the player is situated on
	void interact(int x, int y, Player* p);

	//Loops through the board, calling the draw function for each tile pointed to by the gameBoardLayout.
	void printBoard();

	//Board destructor. Deletes all dynamic memory.
	~Board();
};

#endif