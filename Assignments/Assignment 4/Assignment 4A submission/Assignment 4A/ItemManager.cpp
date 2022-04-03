//	ItemManager.cpp			
//	Name: Khoi Le 
//	ID: 200462293

#include <string>
#include <cassert>
#include <iostream>
#include "ItemManager.h"
#include "Item.h"
#include "World.h"
#include "Location.h"
using namespace std;

ItemManager::ItemManager (const string& game_name) {
	Location locationS(0, 3);
	Location locationC(1, 1);
	Location locationK(2, 0);
	Location locationT(2, 9);
	Location locationB(3, 4);
	Location locationM(5, 5);
	Location locationP(7, 9);
	Location locationD(8, 0);
	Location locationR(9, 6);

	// A scarab beetle
	itemList[0] = Item ('s', locationS, -5,
			 "There is a black scarab beetle (s) here.",
			 "A black scarab beetle (s) is crawling up your arm.");
	
	// A candlestick
	itemList[1] = Item('c', locationC, 9,
			 "There is a silver candlestick (c) here.",
			 "You are carrying a silver candlestick (c).");

	// A key
	itemList[2] = Item('k', locationK, 3,
			 "There is an old iron key (k) here.",
			 "You have an old iron key (k) in your pocket.");

	// A tarantula
	itemList[3] = Item('t', locationT, -8,
			 "There is a tarantula (t) here.",
			 "There is a tarantula (t) hanging on your shirt.");

	// A book
	itemList[4] = Item('b', locationB, 4,
			 "There is a book (b) here with an eye drawn on the cover.",
			 "You have a book (b) under your arm with an eye drawn on the cover.");

	// A moth
	itemList[5] = Item('m', locationM, -2,
			 "There is a giant moth (m) sleeping here.",
			 "A giant moth (m) is perched on your shoulder.");

	// An amulet
	itemList[6] = Item('p', locationP, 7,
			 "There is a golden pendant (p) here.",
			 "You are wearing a golden pendant (p).");

	// A dagger
	itemList[7] = Item('d', locationD, 1,
			 "There is a rune-carved dagger (d) here.",
			 "You have a rune-carved dagger (d) stuck in your belt.");

	// A ring
	itemList[8] = Item('r', locationR, 10,
			 "There is a diamond ring (r) here.",
			 "You are wearing a diamond ring (r).");

	assert(isInvariantTrue());
}

unsigned int ItemManager::getCount () const {
	return ITEM_COUNT;
}

int ItemManager::getScore () const {
	int finalScore = 0;
	for (int i = 0; i < ITEM_COUNT; i++) {
		finalScore += itemList[i].getPlayerPoints();
	}
	return finalScore;
}

void ItemManager::printAtLocation (const Location& location) const {
	for (int i = 0; i < ITEM_COUNT; i++) {
		if (itemList[i].isAtLocation(location))
			itemList[i].printDescription();
	}
}

void ItemManager::printInventory () const {
	for (int i = 0; i < ITEM_COUNT; i++) {
		if (itemList[i].isInInventory())
			itemList[i].printDescription();
	}
}

bool ItemManager::isInInventory (char id) const {
	if (itemList[find (id)].isInInventory())
		return true;
	else
		return false;
}

void ItemManager::reset () {
	assert(isInvariantTrue());
	
	for (int i = 0; i < ITEM_COUNT; i++) {
		itemList[i].reset();
	}

	assert(isInvariantTrue());
}

bool ItemManager::take  (char id, const Location& player_location) {
	assert(isInvariantTrue());

	bool validItem = true;
	for (int i = 0; i < ITEM_COUNT; i++) {
		if (itemList[i].isAtLocation(player_location) && id == itemList[i].getId()) {
			itemList[i].moveToInventory();
			return true;
		}

		else {
			validItem = false;
		}
	}
	return validItem;

	assert(isInvariantTrue());
}

bool ItemManager::leave (char id, const Location& player_location) {
	assert(isInvariantTrue());
	
	bool validItem = true;
	for (int i = 0; i < ITEM_COUNT; i++) {
		if (itemList[i].isInInventory() && id == itemList[i].getId()) {
			itemList[i].moveToLocation(player_location);
			return true;
		}

		else {
			validItem = false;
		}
	}
	return validItem;

	assert(isInvariantTrue());
}

unsigned int ItemManager::find (char id) const {
	unsigned int index = NO_SUCH_ITEM;
	for (int i = 0; i < ITEM_COUNT; i++)
		if (itemList[i].getId() == id)
			index = i;
	return index;
}

bool ItemManager::isInvariantTrue () const {
	bool invariant;
	for (int i = 0; i < ITEM_COUNT; i++) {
		if (itemList[i].isInitialized())
		 	invariant = true;
		else
			return false;
	}
	return invariant;
}