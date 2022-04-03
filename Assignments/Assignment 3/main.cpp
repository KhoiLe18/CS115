//	main.cpp
//	Name: Khoi Le
//	ID: 200462293

#include <string>
#include <iostream>
#include "World.h"
#include "Item.h"
#include "Location.h"
using namespace std;

int main() {
	string gameName = "ghostwood";
	World gameWorld(gameName);
	Location playerLocation = gameWorld.getStart();
	Location locationS(0, 3);
	Location locationC(1, 1);
	Location locationK(2, 0);
	Location locationT(2, 9);
	Location locationB(3, 4);
	Location locationM(5, 5);
	Location locationP(7, 9);
	Location locationD(8, 0);
	Location locationR(9, 6);

	Item itemList[ITEM_COUNT] = {
	// A scarab beetle
	Item('s', locationS, -5,
			 "There is a black scarab beetle (s) here.",
			 "A black scarab beetle (s) is crawling up your arm."),
	
	// A candlestick
	Item('c', locationC, 9,
			 "There is a silver candlestick (c) here.",
			 "You are carrying a silver candlestick (c)."),

	// A key
	Item('k', locationK, 3,
			 "There is an old iron key (k) here.",
			 "You have an old iron key (k) in your pocket."),

	// A tarantula
	Item('t', locationT, -8,
			 "There is a tarantula (t) here.",
			 "There is a tarantula (t) hanging on your shirt."),

	// A book
	Item('b', locationB, 4,
			 "There is a book (b) here with an eye drawn on the cover.",
			 "You have a book (b) under your arm with an eye drawn on the cover."),

	// A moth
	Item('m', locationM, -2,
			 "There is a giant moth (m) sleeping here.",
			 "A giant moth (m) is perched on your shoulder."),

	// An amulet
	Item('p', locationP, 7,
			 "There is a golden pendant (p) here.",
			 "You are wearing a golden pendant (p)."),

	// A dagger
	Item('d', locationD, 1,
			 "There is an rune-carved dagger (d) here.",
			 "You have an rune-carved dagger (d) stuck in your belt."),

	// A ring
	Item('r', locationR, 10,
			 "There is a diamond ring (r) here.",
			 "You are wearing a diamond ring (r).")
	};
	
	gameWorld.printStartMessage();
	gameWorld.printDescription(playerLocation);
	itemPrintDescAtLoc(itemList, playerLocation);
	
	bool continueGame = true;
	while (continueGame) {
		string playerCommand;
		bool canGo, isVic, isDead, validItem;
		cout << "Next? ";
		getline(cin, playerCommand);

		switch (playerCommand[0]) {
			case '#':
				break;

			// Quit
			case 'q':
				cout << "Are you sure you want to quit?(y/n) ";
				getline(cin, playerCommand);
				if (playerCommand[0] == 'y')
					continueGame = false;
				break;

			// Go North
			case 'n':
				canGo = gameWorld.canGoNorth(playerLocation);

				if (canGo) {
					playerLocation = gameWorld.getNorth(playerLocation);
					gameWorld.printDescription(playerLocation);
					itemPrintDescAtLoc(itemList, playerLocation);
				}
				else
					cout << "There is no way to go in that direction" << endl;
				break;

			// Go South
			case 's':
				canGo = gameWorld.canGoSouth(playerLocation);
				if (canGo) {
					playerLocation = gameWorld.getSouth(playerLocation);
					gameWorld.printDescription(playerLocation);
					itemPrintDescAtLoc(itemList, playerLocation);
				}
				else
					cout << "There is no way to go in that direction" << endl;
				break;

			// Go East
			case 'e':
				canGo = gameWorld.canGoEast(playerLocation);
				if (canGo) {
					playerLocation = gameWorld.getEast(playerLocation);
					gameWorld.printDescription(playerLocation);
					itemPrintDescAtLoc(itemList, playerLocation);
				}
				else
					cout << "There is no way to go in that direction" << endl;
				break;

			// Go West
			case 'w':
				canGo = gameWorld.canGoWest(playerLocation);
				if (canGo) {
					playerLocation = gameWorld.getWest(playerLocation);
					gameWorld.printDescription(playerLocation);
					itemPrintDescAtLoc(itemList, playerLocation);
				}	
				else
					cout << "There is no way to go in that direction" << endl;
				break;

			// Take item
			case 't':
				cout << "Take what? ";
				getline(cin, playerCommand);
				for (int i = 0; i < ITEM_COUNT; i++) {
					if (itemList[i].isAtLocation(playerLocation) && playerCommand[0] == itemList[i].getId()) {
						itemList[i].moveToInventory();
						validItem = true;
						break;
					}
					else
						validItem = false;
				}
				if (!validItem)
					cout << "Invalid item ";
				break;

			// Leave item
			case 'l':
				cout << "Leave what? ";
				getline(cin, playerCommand);
				for (int i = 0; i < ITEM_COUNT; i++) {
					if (itemList[i].isInInventory() && playerCommand[0] == itemList[i].getId()) {
						itemList[i].moveToLocation(playerLocation);
						validItem = true;
						break;
					}
					else 
						validItem = false;
				}
				if (!validItem)
					cout << "Invalid item ";
				break;

			// Open inventory
			case 'i':
				for (int i = 0; i < ITEM_COUNT; i++) {
					if (itemList[i].isInInventory())
						itemList[i].printDescription();
				}
				break;

			default:
				cout << "Invalid command!" << endl;
				break;
		}

		// Check if the player is victorious or dead
		isVic = gameWorld.isVictory(playerLocation);
		isDead = gameWorld.isDeath(playerLocation);
		if (isVic || isDead)
			continueGame = false;
	}

	cout << endl;
	gameWorld.printEndMessage();

	// Calculate and print final score
	int finalScore = 0;
	for (int i = 0; i < ITEM_COUNT; i++) {
		finalScore += itemList[i].getPlayerPoints();
	}
	cout << "In this game you scored " << finalScore << " points" << endl;

	return 0;
}