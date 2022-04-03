//	World.cpp
//	Name: Khoi Le
//	ID: 200462293

#include <fstream>
#include <cstdlib>
#include <cassert>
#include "World.h"
#include "Location.h"
using namespace std;

World::World (const string& game_name) {
	loadNodes(game_name + "_grid.txt");
	loadDescriptions(game_name + "_text.txt");
	
	assert(isInvariantTrue());
}

void World::loadNodes (const string& filename) {
	ifstream read_data;
	read_data.open(filename);

	if (!read_data) {
		cerr << "The file \"" << filename << "\" couldn't be opened." << endl;
		exit(1);
	}
	else {
		for (int i = 0; i < ROW_COUNT; i++) {
			for (int j = 0; j < COLUMN_COUNT; j++)
				read_data >> nodes[i][j];
		}
	}

	read_data.close();
}

void World::loadDescriptions (const string& filename) {
	ifstream read_data;
	read_data.open(filename);

	if (!read_data) {
		cerr << "The file \"" << filename << "\" couldn't be opened." << endl;
		exit(1);
	}
	else {
		string temp;
		read_data >> description_count;
		getline(read_data, temp);
		getline(read_data, temp);

		for (int i = 0; i < description_count; i++) {
			getline(read_data, temp);

			while (read_data && temp != "") {
				descriptions[i] += temp + "\n"; //load multiple lines into one spot of the array
				getline(read_data, temp);
			}
		}
	}

	read_data.close();
}

bool World::isInvariantTrue () const {
	if (description_count > MAX_DESCRIPTION_COUNT) 
		return false;

	for (int d = 0; d < description_count; d++) {
		if (descriptions[d] == "")
			return false;
	}

	for (int r = 0; r < ROW_COUNT; r++) {
		for (int c = 0; c < COLUMN_COUNT; c++)
			if (nodes[r][c] >= description_count)
				return false;
	}

	return true;
}

void World::debugPrint () const {
	for (int i = 0; i < ROW_COUNT; i++) {
		for (int j = 0; j < COLUMN_COUNT; j++)
			cout << nodes[i][j] << '\t';
	cout << endl;
	}

	cout << endl << description_count << endl;
	for (int i = 0; i < description_count; i++) {
		cout << descriptions[i] << endl;
	}
}

bool World::isValid (const Location& location) const {
	if (location.row < ROW_COUNT && location.row >= 0) {
		if (location.column < COLUMN_COUNT && location.column >= 0)
			return true;
		else
			return false;
	}
	else 
		return false;
}

bool World::canGoNorth (const Location& location) const {
	assert(isValid(location));

	if (location.row - 1 >= 0 && nodes[location.row - 1][location.column] != 0)
		return true;
	else
		return false;
}

bool World::canGoSouth (const Location& location) const {
	assert(isValid(location));

	if (location.row + 1 < ROW_COUNT && nodes[location.row + 1][location.column] != 0)
		return true;
	else
		return false;
}

bool World::canGoEast (const Location& location) const {
	assert(isValid(location));

	if (location.column + 1 < COLUMN_COUNT && nodes[location.row][location.column + 1] != 0)
		return true;
	else
		return false;
}

bool World::canGoWest (const Location& location) const {
	assert(isValid(location));

	if (location.column - 1 >= 0 && nodes[location.row][location.column - 1] != 0)
		return true;
	else
		return false;
}

Location World::getNorth (const Location& location) const {
	assert(isValid(location) && canGoNorth(location));

	if (location.row - 1 >= 0 && nodes[location.row - 1][location.column] != 0) {
		Location result(location.row - 1, location.column);
		return result;
	}
	else
		return NO_SUCH_VALUE;
}

Location World::getSouth (const Location& location) const {
	assert(isValid(location) && canGoSouth(location));

	if (location.row + 1 >= 0 && nodes[location.row + 1][location.column] != 0) {
		Location result(location.row + 1, location.column);
		return result;
	}
	else
		return NO_SUCH_VALUE;
} 

Location World::getEast (const Location& location) const {
	assert(isValid(location) && canGoEast(location));

	if (location.column + 1 >= 0 && nodes[location.row][location.column + 1] != 0) {
		Location result(location.row, location.column + 1);
		return result;
	}
	else
		return NO_SUCH_VALUE;
}

Location World::getWest (const Location& location) const {
	assert(isValid(location) && canGoWest(location));

	if (location.column - 1 >= 0 && nodes[location.row][location.column - 1] != 0) {
		Location result(location.row, location.column - 1);
		return result;
	}
	else
		return NO_SUCH_VALUE;
}

bool World::isDeath (const Location& location) const {
	assert(isValid(location));

	if (nodes[location.row][location.column] == 3)
		return true;
	else
		return false;
}

bool World::isVictory (const Location& location) const {
	assert(isValid(location));
	
	if (nodes[location.row][location.column] == 5)
		return true;
	else
		return false;
}

Location World::getStart () const {
	Location location1;

	for (int i = 0; i < ROW_COUNT; i++) {
		for (int j = 0; j < COLUMN_COUNT; j++) {
			if (nodes[i][j] == START_NODE) {
				location1.row = i;
				location1.column = j;
				return location1;
			}
		}
	}
	return NO_SUCH_VALUE;
}


void World::printStartMessage () const {
	cout << descriptions[START_MESSAGE] << endl;
}

void World::printEndMessage () const {
	cout << descriptions[END_MESSAGE] << endl;
}

void World::printDescription (const Location& location) const {
	NodeValue temp = nodes[location.row][location.column];
	cout << descriptions[temp] << endl;
}