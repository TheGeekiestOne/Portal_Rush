//Program name: World.cpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Implementation file for the World class. This is the base class for the three tile types that appear on the gameBoardLayout. It
//contains pointers to the North, East, South, and West tiles around the tile, boolean and char variables for items, and pointers to
//player or skeleton objects that may occupy the tile. Contains virtual functions to interact, draw, and return the tile type. All other
//member functions are getters and setters.

#include "World.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

World::World() {
	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
	hasItem = false;
	playerInTile = nullptr;
	skeletonInTile = nullptr;
}

void World::setNorth(World* s) {
	north = s;
}

World* World::getNorth() {
	return north;
}

void World::setEast(World* s) {
	east = s;
}

World* World::getEast() {
	return east;
}

void World::setSouth(World* s) {
	south = s;
}

World* World::getSouth() {
	return south;
}

void World::setWest(World* s) {
	west = s;
}

World* World::getWest() {
	return west;
}

void World::setHasItem(bool b) {
	hasItem = b;
}

bool World::getHasItem() {
	return hasItem;
}

void World::setItem(char c) {
	item = c;
}

char World::getItem() {
	return item;
}

void World::setPlayerInTile(Player* p) {
	playerInTile = p;
}

Player* World::getPlayerInTile() {
	return playerInTile;
}

void World::setSkeletonInTile(Enemy* a) {
	skeletonInTile = a;
}

Enemy* World::getSkeletonInTile() {
	return skeletonInTile;
}

World::~World() {}