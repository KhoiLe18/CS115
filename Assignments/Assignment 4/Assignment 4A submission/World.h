//	World.h
//	Name: Khoi Le
//	ID: 200462293

#pragma once
#include <string>
#include "Location.h"

using namespace std;

int const ROW_COUNT = 10;
int const COLUMN_COUNT = 10;
unsigned int const MAX_DESCRIPTION_COUNT = 1000;
typedef unsigned int NodeValue;

NodeValue const INACCESSIBLE = 0;
NodeValue const START_MESSAGE = 1;
NodeValue const END_MESSAGE = 2;
NodeValue const DEATH_NODE = 3;
NodeValue const START_NODE = 4;
NodeValue const VICTORY_NODE = 5;
Location const NO_SUCH_VALUE(-1, -1);


class World {
	private:
		NodeValue nodes[ROW_COUNT][COLUMN_COUNT];
		string descriptions[MAX_DESCRIPTION_COUNT];
		unsigned int description_count;

		void loadNodes (const string& filename);
		void loadDescriptions (const string& filename);
		bool isInvariantTrue () const;  // new in A3

	public:
		World (const string& game_name);
		// Constructor
		// Purpose: Initialize the item.
		// Parameter(s): the name of a game expressed as a string.
		// Precondition(s): N/A
		// Returns: N/A
		// Side effect: Loads nodes and descriptions

		void debugPrint () const;
		bool isValid (const Location& location) const;
		bool isDeath (const Location& location) const;
		bool isVictory (const Location& location) const;
		Location getStart () const;
		bool canGoNorth (const Location& location) const;
		bool canGoSouth (const Location& location) const;
		bool canGoEast (const Location& location) const;
		bool canGoWest (const Location& location) const;

		Location getNorth (const Location& location) const;  // new in A3
		// Purpose: get the location to the North of the current location.
		// Parameter(s): the Location of a specified location expressed as a Location.
		// Precondition(s): the current location is a valid location and the player can go North from the current location.
		// Returns: the location of the node to the North
		// Side effect: N/A

		Location getSouth (const Location& location) const;  // new in A3
		Location getEast (const Location& location) const;  // new in A3
		Location getWest (const Location& location) const;  // new in A3
		void printStartMessage () const;
		void printEndMessage () const;
		void printDescription (const Location& location) const;
};