//Program name: Space.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Implementation file for the Space class. This is the base class for the three space types that appear on the gameBoard. It
//contains pointers to the North, East, South, and West spaces around the space, boolean and char variables for items, and pointers to
//player or skeleton objects that may occupy the space. Contains virtual functions to interact, draw, and return the space type. All other
//member functions are getters and setters.

#include "Space.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

Space::Space() {
	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
	hasItem = false;
	playerInSpace = nullptr;
	skeletonInSpace = nullptr;
}

void Space::setNorth(Space* s) {
	north = s;
}

Space* Space::getNorth() {
	return north;
}

void Space::setEast(Space* s) {
	east = s;
}

Space* Space::getEast() {
	return east;
}

void Space::setSouth(Space* s) {
	south = s;
}

Space* Space::getSouth() {
	return south;
}

void Space::setWest(Space* s) {
	west = s;
}

Space* Space::getWest() {
	return west;
}

void Space::setHasItem(bool b) {
	hasItem = b;
}

bool Space::getHasItem() {
	return hasItem;
}

void Space::setItem(char c) {
	item = c;
}

char Space::getItem() {
	return item;
}

void Space::setPlayerInSpace(Player* p) {
	playerInSpace = p;
}

Player* Space::getPlayerInSpace() {
	return playerInSpace;
}

void Space::setSkeletonInSpace(Enemy* a) {
	skeletonInSpace = a;
}

Enemy* Space::getSkeletonInSpace() {
	return skeletonInSpace;
}

Space::~Space() {}