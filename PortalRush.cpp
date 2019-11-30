//  ???????  ??????? ??????? ????????? ?????? ???         ??????? ???   ??????????????  ???
// 	?????????????????????????????????????????????         ???????????   ??????????????  ???
//  ???????????   ???????????   ???   ???????????         ???????????   ???????????????????
//  ??????? ???   ???????????   ???   ???????????         ???????????   ???????????????????
//	???     ????????????  ???   ???   ???  ???????????    ???  ???????????????????????  ???
//	???      ??????? ???  ???   ???   ???  ???????????    ???  ??? ??????? ???????????  ???
//
//Program name: Main.cpp
//Author: Ayran Olckers
//Date: 20/11/2019
//Description: Main function for the skeleton survival game. Calls functions
//to initialize the board, play the game, add skeletons each turn, and print
//outcomes based on progress made at the time of victory or defeat.
 

#include "Enemy.hpp"
#include "Player.hpp"
#include "Space.hpp"
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

using std::vector;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;



int main() {
	//seed rand
	srand(time(nullptr));

	Player mainPlayer;
	Board mainBoard(&mainPlayer);
	bool boardChanged;
	string dummyString;

	//Welcome the player to the game
	printIntro();
	printLegend();

	while (mainBoard.getHasLost() != true && mainBoard.getHasWon() != true) {
		//print game status
		if (mainPlayer.getHelpOrbed() == false) {
			cout << mainBoard.getStepsLose() << " turns remain before the skeleton invasion is complete.\n";
			cout << "Orb has not been used.\n";
		}
		else {
			cout << mainBoard.getStepsLose() << " turns remain before the skeleton invasion is complete.\n";
			cout << "The orb has been used and the world will be saved in " << mainBoard.getStepsWin() << " turns.\n";
		}

		//print the board
		mainBoard.printBoard();

		//continue as long as an skeleton has not moved into the player
		if (mainBoard.getHasLost() != true) {
			//use items, print the board if a bomb or bow was used
			boardChanged = mainPlayer.useItem(mainBoard);
			if (boardChanged == true) {
				mainBoard.printBoard();
			}

			//move the player
			mainBoard.movePlayer(&mainPlayer);

			//if the player didn't move into an skeleton, interact with the spaces
			if (mainBoard.getHasLost() != true) {
				mainBoard.interact(mainPlayer.getXLocation(), mainPlayer.getYLocation(), &mainPlayer);
			}

			//move the skeletons
			mainBoard.moveSkeletons(&mainPlayer);

			//add an skeleton
			mainBoard.placeSkeleton();

			//reduce the time limit
			mainBoard.reduceStepsLose();

			//reduce the time until help arrives, if the orb has been activated
			if (mainPlayer.getHelpOrbed() == true) {
				mainBoard.reduceStepsWin();
			}

			//print the final board if the player won on this turn
			if (mainBoard.getHasWon() == true) {
				mainBoard.printBoard();
			}
		}
	}

	if (mainBoard.getHasLost() == true && mainBoard.getHasWon() == true) {
		cout << "Help arrived right as the skeletons got to you. While you were not saved, your valiant actions allowed the \n";
		cout << "forces of heaven to respond to the skeleton threat in time to stop it. Game over.\n";
	}

	else if (mainBoard.getHasLost() == true && mainBoard.getStepsWin() < 10) {
		cout << "Unfortunately, you were defeated before the forces of Heaven could get to the skeletons. However, your valiant actions\n";
		cout << "to activate the orb and call the forces of Heaven allowed them to respond in time to stop the invasion. Game over.\n";
	}

	else if (mainBoard.getHasLost() == true) {
		cout << "Unfortunately, you were defeated before the forces of Heaven could get to the skeletons. Game over.\n";
	}

	else if (mainBoard.getHasWon() == true) {
		cout << "Help has arrived! Your orb call has saved the workd from the skeleton invasion. Game over.\n";
	}

	//let the user read the output and choose when to leave
	cout << "Press enter to continue:\n";
	getline(cin, dummyString);

	return 0;
}