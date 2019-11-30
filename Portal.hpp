 
//Program name: Portal.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the Portal class. This class
//derives from the Space class. Interacting with this class involves
//asking the player if they would like to activate the portal. If
//they do, they are randomly placed on a space with no adjacent
//skeletons.
 

#ifndef PORTAL_HPP
#define PORTAL_HPP

class Board;

#include "Space.hpp"

class Portal : public Space {
public:
	 
	//Gets and validates choice to activate portal. Calls placePlayer
	//function if portal is activated.
	 
	void interact(Player* p, Board* b);

	 
	//Prints the space based on the values shown in the legend.
	 
	void draw();

	 
	//Returns 'w' for portal
	 
	char getSpaceType();
};

#endif