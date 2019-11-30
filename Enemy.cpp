 
//Program name: Enemy.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Implementation file for the skeleton class. This class contains
//ints for the locationX and locationYumn of the skeleton and a boolean variable to
//say whether the skeleton has moved. Function descriptions are available
//in the header file.
 

#include "Enemy.hpp"
#include "Player.hpp"
#include <cstdlib>

using std::rand;

Enemy::Enemy(int r, int c) {
	locationX = r;
	locationY = c;
	hasMoved = false;
}

void Enemy::move(Player& p) {
	if (p.getLocationX() == locationX && p.getLocationY() < locationY) {
		locationY -= 1;
	}

	else if (p.getLocationX() == locationX && p.getLocationY() > locationY) {
		locationY += 1;
	}

	else if (p.getLocationX() < locationX && p.getLocationY() == locationY) {
		locationX -= 1;
	}

	else if (p.getLocationX() > locationX&& p.getLocationY() == locationY) {
		locationX += 1;
	}

	else if (p.getLocationX() < locationX && p.getLocationY() < locationY) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			locationX -= 1;
		}

		else {
			locationY -= 1;
		}
	}

	else if (p.getLocationX() < locationX && p.getLocationY() > locationY) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			locationX -= 1;
		}

		else {
			locationY += 1;
		}
	}

	else if (p.getLocationX() > locationX&& p.getLocationY() < locationY) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			locationX += 1;
		}

		else {
			locationY -= 1;
		}
	}

	else if (p.getLocationX() > locationX&& p.getLocationY() > locationY) {
		int moveDirection = rand() % 2;

		if (moveDirection == 0) {
			locationX += 1;
		}

		else {
			locationY += 1;
		}
	}

	hasMoved = true;
}

int Enemy::getLocationX() {
	return locationX;
}

void Enemy::setLocationX(int r) {
	locationX = r;
}

int Enemy::getLocationY() {
	return locationY;
}

void Enemy::setLocationY(int c) {
	locationY = c;
}

bool Enemy::getHasMoved() {
	return hasMoved;
}

void Enemy::setHasMoved(bool b) {
	hasMoved = b;
}