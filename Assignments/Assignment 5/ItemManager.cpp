//
//  ItemManager.cpp
//
//  Student name: Khoi Le
//  Student ID: 200462293
//

#include "ItemManager.h"

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>

#include "Location.h"
#include "Item.h"

using namespace std;

static const unsigned int NO_SUCH_ITEM = 999999999;

ItemManager::ItemManager () {
	itemCount = 0;
	items = new Item[0];

	assert(isInvariantTrue());
}

ItemManager::ItemManager (const string& game_name) {
	items = nullptr;
	load(game_name + "_items.txt");
	sort();

	assert(isInvariantTrue());
}

ItemManager::ItemManager (const ItemManager& to_copy) {
	assert(isInvariantTrue());

	itemCount = to_copy.itemCount;
	items = new Item[to_copy.itemCount];
	for (int i = 0; i < to_copy.itemCount; i++) {
		items[i] = to_copy.items[i];
	}
}

ItemManager::~ItemManager () {
	assert(isInvariantTrue());
	if (items != nullptr)
		delete [] items;
}

ItemManager& ItemManager::operator= (const ItemManager& to_copy) {
	assert(isInvariantTrue());
	if (&to_copy == this) // checks for self assignment
		return *this;
	else {
		if (items != nullptr)
			delete [] items;

		itemCount = to_copy.itemCount;
		items = new Item[to_copy.itemCount];
		for (int i = 0; i < to_copy.itemCount; i++) {
			items[i] = to_copy.items[i];
		}
	}
	
	return *this;	

	assert(isInvariantTrue());
}

unsigned int ItemManager::getCount () const {
	assert(isInvariantTrue());

	return itemCount;
}

int ItemManager::getScore () const {
	assert(isInvariantTrue());

	int score = 0;
	for(unsigned int i = 0; i < itemCount; i++)	{
		score += items[i].getPlayerPoints();
	}
	return score;
}

void ItemManager::printAtLocation (const Location& location) const {
	assert(isInvariantTrue());

	for(unsigned int i = 0; i < itemCount; i++)	{
		if(items[i].isAtLocation(location))
			items[i].printDescription();
	}
}

void ItemManager::printInventory () const {
	assert(isInvariantTrue());

	for(unsigned int i = 0; i < itemCount; i++)	{
		if(items[i].isInInventory())
			items[i].printDescription();
	}
}

bool ItemManager::isInInventory (char id) {
	assert(isInvariantTrue());

	unsigned int item_index = find(id);

	if(item_index == NO_SUCH_ITEM)
		return false;
	else
		return items[item_index].isInInventory();
}

void ItemManager::reset () {
	assert(isInvariantTrue());

	for(unsigned int i = 0; i < itemCount; i++)	{
		items[i].reset();
	}

	assert(isInvariantTrue());
}

void ItemManager::take (char id, const Location& player_location) {
	assert(isInvariantTrue());

	unsigned int item_index = find(id);

	if(item_index != NO_SUCH_ITEM &&
	   items[item_index].isAtLocation(player_location))	{
		items[item_index].moveToInventory();
	}
	else
		cout << "Invalid item." << endl;

	assert(isInvariantTrue());
}

void ItemManager::leave (char id, const Location& player_location) {
	assert(isInvariantTrue());

	unsigned int item_index = find(id);

	if(item_index != NO_SUCH_ITEM &&
	   items[item_index].isInInventory())	{
		items[item_index].moveToLocation(player_location);
	}
	else
		cout << "Invalid item." << endl;

	assert(isInvariantTrue());
}

void ItemManager::load (const string& filename) {
	ifstream read_data;
	read_data.open(filename);
	string temp;
	char id;
	int loc, points;
	string worldDes, invDes;

	if (!read_data) {
		cerr << "The file \"" << filename << "\" couldn't be opened." << endl;
		exit(1);
	}

	else {
		read_data >> itemCount;
		getline(read_data, temp);
		items = new Item[itemCount];

		for (int i = 0; i < itemCount; i++) {
			read_data >> id >> loc >> points;
			getline(read_data, temp);
			getline(read_data, worldDes);
			getline(read_data, invDes);
		
			items[i] = Item (id, loc, points, worldDes, invDes);

			// need another getline
			getline(read_data, temp);
		}
	}
	
	assert (items != nullptr);
}

unsigned int ItemManager::find (char id) const {
	// Binary search
	unsigned int low = 0;
	unsigned int high = itemCount - 1;
	
	while (low <= high) {
		unsigned int mid = (low + high) / 2;

		if (id == items[mid].getId())
			return mid;
		
		else if (id < items[mid].getId())
			high = mid - 1;

		else
			low = mid + 1;
	}

	// found nothing
	return NO_SUCH_ITEM;
}

void ItemManager::sort () { // selection sort
	for (int i = 0; i < itemCount; i++) {
		Item min = items[i];

		for (int j = i + 1; j < itemCount; j++) {
			if (items[j].getId() < items[i].getId()) {
				min = items[j];
				items[j] = items[i];
				items[i] = min;
			}
		}
	}
}

bool ItemManager::isInvariantTrue () const {
	
	for(unsigned int i = 0; i < itemCount; i++) {
		if(!items[i].isInitialized() && items == nullptr)
			return false;
	}

	// Check to see if the items array is sorted or not
	for (unsigned int i = 1; i < itemCount; i++) {
		if (items[i].getId() < items[i - 1].getId())
			return false;
	}

	return true;
}
