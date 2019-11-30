 
//Program name: Trap.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the Trap class. This class
//derives from the Space class. Interacting with this class involves
//picking a direction and destroying all skeletons in that direction
//(provided ammo is remaining in the turret).
 

#ifndef TRAP_HPP
#define TRAP_HPP

class Board;

#include "Space.hpp"

class Trap : public Space {
private:
	int ammo;

public:
	 
	//Default constructor, sets ammo to 5
	 
	Trap();

	 
	//If ammo > 0, gets and validates a direction to fire. Deletes all
	//skeletons in chosen direction, reduces ammo by 1.
	 
	void interact(Player* p, Board* b);

	 
	//Prints the space based on the values shown in the legend.
	 
	void draw();

	 
	//returns 't' for turret
	 
	char getSpaceType();
};

#endif