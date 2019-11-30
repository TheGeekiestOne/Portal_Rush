/*********************************************************************
//Program name: Board.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the board class. This class contains
//integers to hold the number of locationXs, locationYumns, portals, turrets,
//bombs, and ammo on the board. The initial number of skeletons is also
//set. Step counters and boolean variables to tell if the player has
//won or lost the game are also available. The board itself is a
//space triple pointer called gameBoard.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"
#include "Player.hpp"

class Board {
private:
	Space*** gameBoard;
	int numRowsX;
	int numColsY;
	int numPortals;
	int numTurrets;
	int numBombs;
	int numAmmo;
	int numSkeletons;
	int stepsLose;
	int stepsWin;
	bool hasWon;
	bool hasLost;

public:
	/*********************************************************************
	//Default constructor for the board. Creates a randomized gameboard
	//object, and places a player parameter on that board. The randomized
	//board is based on values for the numbers of turrets, portals,
	//bombs, and ammo. Adjusting these values will change the difficulty
	//of the game.
	*********************************************************************/
	Board(Player* p);

	/*********************************************************************
	//Randomly initializes one of the null gameBoard pointers to a
	//portal.
	*********************************************************************/
	void placePortal();

	/*********************************************************************
	//Randomly initializes one of the null gameBoard pointers to a
	//turret.
	*********************************************************************/
	void placeTurret();

	/*********************************************************************
	//Randomly changes the hasItem and item member variables of one of the
	//gameBoard pointers pointing to a FreeSpace to true and 'b'
	*********************************************************************/
	void placeBombs();

	/*********************************************************************
	//Destroys all skeletons in a 7x7 grid centered on the locationX input r and
	//locationYumn input c.
	*********************************************************************/
	void useBomb(int r, int c);

	/*********************************************************************
	//Randomly changes the hasItem and item member variables of one of the
	//gameBoard pointers pointing to a FreeSpace to true and 'a'
	*********************************************************************/
	void placeAmmo();

	/*********************************************************************
	//Randomly changes the hasItem and item member variables one of the
	//gameBoard pointers pointing to a FreeSpace to true and 'r'
	*********************************************************************/
	void placeOrb();

	/*********************************************************************
	//Randomly changes the skeletonInSpace member variable of one of the
	//gameBoard pointers with null skeletonInSpace and playerInSpace pointers
	//to a new skeleton.
	*********************************************************************/
	void placeSkeleton();

	/*********************************************************************
	//Loops through the gameBoard and calls move on all skeletons on the
	//board. Uses hasMoved boolean member variable of skeleton to verify
	//each skeleton moves only once. The player object parameter must be
	//passed for each skeleton move call.
	*********************************************************************/
	void moveSkeletons(Player* p);

	/*********************************************************************
	//Randomly places the passed player object on a board space with no
	//adjacent skeletons. Prints an error message if this is not possible.
	//Used for both gameBoard initialization and portal interaction.
	*********************************************************************/
	void placePlayer(Player* p);

	/*********************************************************************
	//Gets and validates a direction to move the player. Changes the
	//playerInSpace member variable of the space being pointed to the
	//player based on the desired direction.
	*********************************************************************/
	void movePlayer(Player* p);

	/*********************************************************************
	//Reduces stepsLose member variable by 1
	*********************************************************************/
	void reduceStepsLose();

	/*********************************************************************
	//Reduces stepsWin member variable by 1
	*********************************************************************/
	void reduceStepsWin();

	/*********************************************************************
	//Getters
	*********************************************************************/
	Space* getPlayerSpace();

	int getStepsLose();

	int getStepsWin();

	bool getHasWon();

	bool getHasLost();

	/*********************************************************************
	//Calls the interact function of the space the player is situated on
	*********************************************************************/
	void interact(int r, int c, Player* p);

	/*********************************************************************
	//Loops through the board, calling the print function for each space
	//pointed to by the gameBoard.
	*********************************************************************/
	void printBoard();

	/*********************************************************************
	//Board destructor. Deletes all dynamic memory.
	*********************************************************************/
	~Board();
};

#endif