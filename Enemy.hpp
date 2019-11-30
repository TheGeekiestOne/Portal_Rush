 //Program name: Enemy.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the skeleton class. This class contains
//ints for the xLocation and locationY of the skeleton and a boolean variable to
//say whether the skeleton has moved.
 
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

class Enemy {
private:
	int xLocation;
	int yLocation;
	bool hasMoved;

public:
	 
	//Constructor for the skeleton class. Row and locationY values are required
	//to initialize the object. 
	Enemy(int x, int y);

	//Takes a player as a parameter and moves the skeleton one space closer
	//to the player. Randomly chooses to move up or right if the
	//player is both up and right of the skeleton on the gameboard, etc.
	void move(Player& p);
	 
	//Getters and setters for the member variables.
	int getXLocation();

	void setXLocation(int x);

	int getYLocation();

	void setYLocation(int y);

	bool getHasMoved();

	void setHasMoved(bool b);
};

#endif