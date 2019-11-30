 
//Program name: Enemy.hpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Header file for the skeleton class. This class contains
//ints for the locationX and locationYumn of the skeleton and a boolean variable to
//say whether the skeleton has moved.
 
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

class Enemy {
private:
	int locationX;
	int locationY;
	bool hasMoved;

public:
	 
	//Constructor for the skeleton class. Row and locationYumn values are required
	//to initialize the object.
	 
	Enemy(int r, int c);

	 
	//Takes a player as a parameter and moves the skeleton one space closer
	//to the player. Randomly chooses to move up or right if the
	//player is both up and right of the skeleton on the gameboard, etc.
	 
	void move(Player& p);

	 
	//Getters and setters for the member variables.
	 
	int getLocationX();

	void setLocationX(int r);

	int getLocationY();

	void setLocationY(int c);

	bool getHasMoved();

	void setHasMoved(bool b);
};

#endif