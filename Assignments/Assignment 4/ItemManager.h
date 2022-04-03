// ItemManagement.h
// Name: Khoi Le
// ID: 200462293

#pragma once
#include <string>
#include "Location.h"
#include "Item.h"
using namespace std;

const unsigned int NO_SUCH_ITEM = 999999999;

class ItemManager {
	Item itemList[ITEM_COUNT];

public:
	ItemManager (const string& game_name);
	unsigned int getCount () const;
	int getScore () const;
	void printAtLocation (const Location& location) const;
	void printInventory () const;
	bool isInInventory (char id) const;
	void reset ();
	bool take  (char id, const Location& player_location);
	bool leave (char id, const Location& player_location);

private:
	unsigned int find (char id) const;
	bool isInvariantTrue () const;
};