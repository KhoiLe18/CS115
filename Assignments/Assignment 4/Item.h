// Item.h
// Name: Khoi Le
// ID: 200462293

#pragma once
#include <string>
#include "Location.h"
using namespace std;

const char ID_NOT_INITIALIZED = '\0';
const unsigned int ITEM_COUNT = 9;

class Item {
	private:
		char id;
		Location start_location;
		Location current_location;
		bool inInven;
		int points;
		string worldDesc;
		string invenDesc;

		bool isInvariantTrue() const;  // new in A3
	
	public:
		Item ();  // new in A3
		Item (char id1, const Location& location1, int points1, const string& world_description1, const string& inventory_description1);
		void debugPrint () const;
		bool isInitialized () const;  // new in A3
		char getId () const;
		bool isInInventory () const;
		bool isAtLocation (const Location& location1) const;
		int getPlayerPoints () const;
		void printDescription () const;
		bool operator< (const Item& other) const;  // new in A3
		void reset ();
		void moveToInventory ();
		void moveToLocation (const Location& location1);
};

