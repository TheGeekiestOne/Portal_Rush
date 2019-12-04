 //Program name: World.hpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Header file for the World class. This is the base class for the three tile types that appear on the gameBoardLayout. It
//contains pointers to the North, East, South, and West tiles around the tile, boolean and char variables for items, and pointers to
//player or skeleton objects that may occupy the tile. Contains virtual functions to interact, draw, and return the tile type. All other
//member functions are getters and setters.

#ifndef WORLD_HPP
#define WORLD_HPP

#include "Enemy.hpp"
#include "Player.hpp"

class Board;

class World {
protected:
	World * north;
	World * east;
	World * south;
	World * west;
	bool hasItem;
	char item;
	Player * playerInTile;
	Enemy * skeletonInTile;

public:
	 
	//Default constructor, sets all pointers to null and hasItem to false.
	World();

	//Setters and getters
	void setNorth(World* s);
	World* getNorth();

	void setEast(World* s);
	World* getEast();

	void setSouth(World* s);
	World* getSouth();

	void setWest(World* s);
	World* getWest();

	void setHasItem(bool b);
	bool getHasItem();

	void setItem(char c);
	char getItem();

	void setPlayerInTile(Player* p);
	Player* getPlayerInTile();

	void setSkeletonInTile(Enemy* a);
	Enemy* getSkeletonInTile();
	 
	//Pure virtual function to interact
	virtual void interact(Player* p, Board* b) = 0;
	 
	//Pure virtual function to draw
	virtual void draw() = 0;
	 
	//Pure virtual function to return the tile type
	virtual char getWorldType() = 0;
	 
	//Virtual destructor. Needed to correctly delete derived classes.
	virtual ~World();
};

#endif