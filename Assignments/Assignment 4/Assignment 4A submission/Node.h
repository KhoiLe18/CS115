//	Node.h
//	Name: Khoi Le
//	ID: 200462293

#pragma once
#include <iostream>
#include "Location.h"
using namespace std;

class Node {
private:
	unsigned int description;
	unsigned int north;
	unsigned int south;
	unsigned int east;
	unsigned int west;
	bool is_death;

public:
	Node ();
	Node (unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, bool is_death1);
	void debugPrint () const;
	unsigned int getDescription () const;
	Location getNorth () const;
	Location getSouth () const;
	Location getEast  () const;
	Location getWest  () const;
	bool isDeath () const;
};