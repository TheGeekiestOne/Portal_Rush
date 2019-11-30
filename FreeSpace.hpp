 //Program name: FreeSpace.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the FreeSpace class. This class
//derives from the Space class. Interacting with this class involves
//picking up an item if the space contains one, or nothing if the
//space does not contain an item.
 

#ifndef FREESPACE_HPP
#define FREESPACE_HPP

#include "Space.hpp"
#include "Board.hpp"

class FreeSpace : public Space {
public:
	 
	//Default constructor, does nothing for this class. 
	FreeSpace();
 
	//If hasItem == true, gives the player the option to pick up the item.
	void interact(Player* p, Board* b);

	//Prints the space based on the values shown in the legend. 
	void draw();
 
	//returns 'n' for normal
	char getSpaceType();
};

#endif