
//  ???????  ??????? ??????? ????????? ?????? ???         ??????? ???   ??????????????  ???
// 	?????????????????????????????????????????????         ???????????   ??????????????  ???
//  ???????????   ???????????   ???   ???????????         ???????????   ???????????????????
//  ??????? ???   ???????????   ???   ???????????         ???????????   ???????????????????
//	???     ????????????  ???   ???   ???  ???????????    ???  ???????????????????????  ???
//	???      ??????? ???  ???   ???   ???  ???????????    ???  ??? ??????? ???????????  ???
//
//Program name: Main.cpp
//Grand Creator: Ayran Olckers
//Date: 20/11/2019
//
//Description: 
//Main function for the skeleton survival game. Calls functions to initialize the board, play the game, add skeletons each turn, and draw
//outcomes based on progress made at the time of victory or defeat.
 
#include "Enemy.hpp"		
#include "Player.hpp"
#include "World.hpp"
#include "FreeSpace.hpp"
#include "Portal.hpp"
#include "Trap.hpp"
#include "InputValidator.hpp"
#include "Menu.hpp"
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//cut down on typing -
using std::vector;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;

//the main method for the game, 
int main() {
	//seed rand
	srand(time(nullptr));

	Player mainPlayer;
	Board mainBoard(&mainPlayer);
	bool boardChanged;
	string dummyString;

	//Welcome the player to the game
	printIntro();
	printInstructions();

	while (mainBoard.getHasLost() != true && mainBoard.getHasWon() != true) {
		//draw game status
		if (mainPlayer.getHelpOrbed() == false) {
			cout << mainBoard.getStepsLose() << " turns remaining before the skeletons win.\n";
			cout << "The Orb has not been used yet.\n";
		}
		else {
			cout << mainBoard.getStepsLose() << " turns remain before the skeleton win.\n";
			cout << "The orb has been used!!! the world will be saved in " << mainBoard.getStepsWin() << " turns. Hazzah\n";
		}

		//draw the board
		mainBoard.printBoard();

		//this will continue as long as a skeleton has not moved into the player tile
		if (mainBoard.getHasLost() != true) {
			//use items, draw the board if a grenade or bow was used from the player
			boardChanged = mainPlayer.useItem(mainBoard);
			if (boardChanged == true) {
				mainBoard.printBoard();
			}

			//move the player
			mainBoard.movePlayer(&mainPlayer);

			//if the player didn't move into a skeleton, interact with the tile
			if (mainBoard.getHasLost() != true) {
				mainBoard.interact(mainPlayer.getXLocation(), mainPlayer.getYLocation(), &mainPlayer);
			}

			//move the skeletons
			mainBoard.moveSkeletons(&mainPlayer);

			//add a skeleton
			mainBoard.placeSkeleton();

			//reduce the time limit
			mainBoard.reduceStepsLose();

			//reduce the time until help arrives, if the orb has been activated
			if (mainPlayer.getHelpOrbed() == true) {
				mainBoard.reduceStepsWin();
			}

			//draw the final board if the player won on this turn
			if (mainBoard.getHasWon() == true) {
				mainBoard.printBoard();
			}
		}
	}

	if (mainBoard.getHasLost() == true && mainBoard.getHasWon() == true) {
		cout << "Help arrived right as the skeletons got to you.\n";
	}

	else if (mainBoard.getHasLost() == true && mainBoard.getStepsWin() < 10) {
		cout << "Unfortunately, you were defeated before the forces of Heaven could get to the skeletons.\n";
	}

	else if (mainBoard.getHasLost() == true) {
		cout << "Unfortunately, you were defeated. Game over.\n";
	}

	else if (mainBoard.getHasWon() == true) {
		cout << "Help has arrived! The activation of the orb has saved the workd from the skeletons. The End.\n";
	}

	//let the user read the output and choose when to leave
	cout << "Press enter to continue:\n";
	getline(cin, dummyString);

	return 0;
}