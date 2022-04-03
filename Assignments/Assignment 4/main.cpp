//	main.cpp
//	Name: Khoi Le
//	ID: 200462293

#include <string>
#include <iostream>
#include "Game.h"
#include "ItemManager.h"
#include "Item.h"
#include "World.h"
#include "Location.h"
using namespace std;

int main() {
	string gameName = "ghostwood";
	Game game (gameName);
	bool stopGame = game.isOver();
	
	game.printStartMessage();
	game.printDescription();
	
	while (!stopGame) {
		string playerCommand;
		cout << "Next? ";
		getline(cin, playerCommand);

		switch (playerCommand[0]) {
			// Comment
			case '#': break;

			// Quit
			case 'q':
				cout << "Are you sure you want to quit?(y/n) ";
				getline(cin, playerCommand);
				if (playerCommand[0] == 'y')
					stopGame = true;
				break;

			// Reset
			case 'r':
				cout << "Are you sure you want to reset?(y/n) ";
				getline(cin, playerCommand);
				if (playerCommand[0] == 'y')
					game.reset();
				break;

			// Go North
			case 'n':
				game.moveNorth();
				break;

			// Go South
			case 's':
				game.moveSouth();
				break;

			// Go East
			case 'e':
				game.moveEast();
				break;

			// Go West
			case 'w':
				game.moveWest();
				break;

			// Take item
			case 't':
				cout << "Take what? ";
				getline(cin, playerCommand);
				game.takeItem(playerCommand[0]);
				break;

			// Leave item
			case 'l':
				cout << "Leave what? ";
				getline(cin, playerCommand);
				game.leaveItem(playerCommand[0]);
				break;

			// Open inventory
			case 'i':
				game.printInventory();
				break;

			default:
				cout << "Invalid command!" << endl;
				break;
		}

		// Check if the player is victorious or dead
		if (game.isOver())
			stopGame = true;
	}

	cout << endl;
	game.printEndMessage();

	// Calculate and print final score
	game.printScore();

	return 0;
}