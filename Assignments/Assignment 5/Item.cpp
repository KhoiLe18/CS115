//
//  Item.cpp
//
//  Student name: Khoi Le
//  Student ID: 200462293
//

#include "Item.h"

#include <cassert>
#include <string>
#include <iostream>

using namespace std;



Item :: Item ()
	: id(ID_NOT_INITIALIZED),
	  start(),
	  current(),
	  is_in_inventory(false),
	  points(0),
	  world_description    ("[Item not initialized]"),
	  inventory_description("[Item not initialized]")
{
	assert(!isInitialized());
	assert(isInvariantTrue());
}

Item :: Item (char id1,
              const Location& start1,
              int points1,
              const string& world_description1,
              const string& inventory_description1)
	: id(id1),
	  start(start1),
	  current(start1),
	  is_in_inventory(false),
	  points(points1),
	  world_description    (world_description1),
	  inventory_description(inventory_description1)
{
	assert(id1 != ID_NOT_INITIALIZED);
	assert(world_description1 != "");
	assert(inventory_description1 != "");

	assert(isInitialized());
	assert(isInvariantTrue());
}



void Item :: debugPrint () const
{
	cout << "id:             \t\'"       << id                    << "\'" << endl;
	cout << "start:          \t"         << start                         << endl;
	cout << "current:        \t"         << current                       << endl;
	cout << "is_in_inventory:\t"         << is_in_inventory               << endl;
	cout << "points:         \t"         << points                        << endl;
	cout << "world_description:    \t\"" << world_description     << "\"" << endl;
	cout << "inventory_description:\t\"" << inventory_description << "\"" << endl;
}

bool Item :: isInitialized () const
{
	assert(isInvariantTrue());

	return id != ID_NOT_INITIALIZED;
}

char Item :: getId () const
{
	assert(isInvariantTrue());
	assert(isInitialized());

	return id;
}

bool Item :: isInInventory () const
{
	assert(isInvariantTrue());
	assert(isInitialized());

	return is_in_inventory;
}

bool Item :: isAtLocation (const Location& location) const
{
	assert(isInvariantTrue());
	assert(isInitialized());

	return !is_in_inventory && current == location;
}

int Item :: getPlayerPoints () const
{
	assert(isInvariantTrue());
	assert(isInitialized());

	if(is_in_inventory)
		return points;
	else
		return 0;
}

void Item :: printDescription () const
{
	assert(isInvariantTrue());
	assert(isInitialized());

	if(is_in_inventory)
		cout << inventory_description << endl;
	else
		cout << world_description << endl;
}

// less than operator as a member function
bool Item :: operator< (const Item& other) const
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(other.isInitialized());

	return id < other.id;
}



void Item :: reset ()
{
	assert(isInvariantTrue());
	assert(isInitialized());

	current = start;
	is_in_inventory = false;

	assert(isInvariantTrue());
}

void Item :: moveToInventory ()
{
	assert(isInvariantTrue());
	assert(isInitialized());

	is_in_inventory = true;

	assert(isInvariantTrue());
}

void Item :: moveToLocation (const Location& location)
{
	assert(isInvariantTrue());
	assert(isInitialized());

	current = location;
	is_in_inventory = false;

	assert(isInvariantTrue());
}



bool Item :: isInvariantTrue () const
{
	if(world_description == "")
		return false;
	if(inventory_description == "")
		return false;
	return true;
}


/*
//less than operator as a non-member function
bool operator< (const Item& lhs, const Item& rhs)
{
	assert(lhs.isInitialized());
	assert(rhs.isInitialized());

	return lhs.getId() < rhs.getId();
}
*/