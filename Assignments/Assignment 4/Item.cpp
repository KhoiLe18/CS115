//	Item.cpp			
//	Name: Khoi Le 
//	ID: 200462293

#include <string>
#include <cassert>
#include <iostream>
#include "Item.h"
#include "Location.h"
using namespace std;

Item::Item () {
	id = ID_NOT_INITIALIZED;
	Location start_location;
	Location current_location;
	inInven = false;
	points = 0;
	worldDesc = invenDesc = "[Item not initialized]";
	isInvariantTrue();
}


Item::Item (char id1,  const Location& location1, int points1, const string& world_description1, const string& inventory_description1) {
	id = id1;
	start_location = current_location = location1;
	points = points1;
	worldDesc = world_description1;
	invenDesc = inventory_description1;
	inInven = false;

	assert (id != ID_NOT_INITIALIZED);
	assert (worldDesc != "");
	assert (invenDesc != "");
	assert (isInvariantTrue());
}

bool Item::isInvariantTrue() const {
	if (worldDesc == "" || invenDesc == "")
		return false;
	else
		return true;
}

void Item::debugPrint () const {
	cout << "id:\t" << "\'" << id << "\'" << endl
			 << "start_location:\t" << start_location << endl
			 << "current_location:\t" << current_location << endl
			 << "is_in_inventory:\t" << inInven << endl
			 << "points:\t" << points << endl
			 << "world_description:\t" << "\"" << worldDesc << "\"" << endl
			 << "inventory_description:\t" << "\"" << invenDesc << "\"" << endl;
}

bool Item::isInitialized () const {
	if (id == ID_NOT_INITIALIZED)
		return false;
	else
		return true;
}

char Item::getId () const {
	return id;
}

bool Item::isInInventory () const {
	return inInven;
}

bool Item::isAtLocation (const Location& location1) const {
	if (current_location == location1 && !isInInventory())
		return true;
	else
		return false;
}

int Item::getPlayerPoints () const {
	if (isInInventory())
		return points;
	else
		return 0;
}

void Item::printDescription () const {
	if (isInInventory())
		cout << invenDesc << endl;
	else
		cout << worldDesc << endl;
}

bool Item::operator< (const Item& other) const {
	if (id < other.id)
		return true;
	else
		return false;
}

void Item::reset () {
	assert(isInvariantTrue());

	current_location = start_location;
	inInven = false;

	assert(isInvariantTrue());
}

void Item::moveToInventory () {
	inInven = true;

	assert(isInvariantTrue());
}

void Item::moveToLocation (const Location& location1) {
	current_location = location1;
	inInven = false;
	
	assert(isInvariantTrue());
}