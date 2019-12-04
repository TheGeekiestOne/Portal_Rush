 //Program name: FreeSpace.hpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for the FreeSpace class. This class derives from the World class. Interacting with this class involves
//picking up an item if the tile contains one, or nothing if the tile does not contain an item.
 

#ifndef FREESPACE_HPP
#define FREESPACE_HPP

#include "World.hpp"
#include "Board.hpp"

class FreeSpace : public World {
public:
	 
	//Default constructor, does nothing for this class. 
	FreeSpace();
 
	//If hasItem == true, gives the player the option to pick up the item.
	void interact(Player* p, Board* b);

	//Prints the tile based on the values shown in the legend. 
	void draw();
 
	//returns 'n' for normal
	char getWorldType();
};

#endif