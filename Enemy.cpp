 //Program name: Enemy.cpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Implementation file for the skeleton class. This class contains ints for the xLocation and locationY of the skeleton and a boolean variable to
//say whether the skeleton has moved. 

#include "Enemy.hpp"
#include "Player.hpp"
#include <cstdlib>

using std::rand;

Enemy::Enemy(int x, int y) {
	xLocation = x;
	yLocation = y;
	hasMoved = false;
}

void Enemy::move(Player& p) {
	if (p.getXLocation() == xLocation && p.getYLocation() < yLocation) {
		yLocation -= 1;
	}

	else if (p.getXLocation() == xLocation && p.getYLocation() > yLocation) {
		yLocation += 1;
	}

	else if (p.getXLocation() < xLocation && p.getYLocation() == yLocation) {
		xLocation -= 1;
	}

	else if (p.getXLocation() > xLocation&& p.getYLocation() == yLocation) {
		xLocation += 1;
	}

	else if (p.getXLocation() < xLocation && p.getYLocation() < yLocation) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			xLocation -= 1;
		}

		else {
			yLocation -= 1;
		}
	}

	else if (p.getXLocation() < xLocation && p.getYLocation() > yLocation) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			xLocation -= 1;
		}

		else {
			yLocation += 1;
		}
	}

	else if (p.getXLocation() > xLocation&& p.getYLocation() < yLocation) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			xLocation += 1;
		}

		else {
			yLocation -= 1;
		}
	}

	else if (p.getXLocation() > xLocation&& p.getYLocation() > yLocation) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			xLocation += 1;
		}

		else {
			yLocation += 1;
		}
	}

	hasMoved = true;
}

int Enemy::getXLocation() {
	return xLocation;
}

void Enemy::setXLocation(int x) {
	xLocation = x;
}

int Enemy::getYLocation() {
	return yLocation;
}

void Enemy::setYLocation(int y) {
	yLocation = y;
}

bool Enemy::getHasMoved() {
	return hasMoved;
}

void Enemy::setHasMoved(bool b) {
	hasMoved = b;
}