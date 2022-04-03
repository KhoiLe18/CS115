//	Node.cpp
//	Name: Khoi Le
//	ID: 200462293

#include <iostream>
#include "Location.h"
#include "Node.h"
using namespace std;

Node::Node () {
	description = north = south = east = west = 0;
	is_death = false;
}

Node::Node (unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, bool is_death1) {
	description = description1;
	north = north1;
	south = south1;
	east = east1;
	west = west1;
	is_death = is_death1;
}

void Node::debugPrint () const {

}

unsigned int Node::getDescription () const {
	return description;
}

Location Node::getNorth () const {
	return north;
}

Location Node::getSouth () const {
	return south;
}

Location Node::getEast  () const {
	return east;
}

Location Node::getWest  () const {
	return west;
}

bool Node::isDeath () const {
	return is_death;
}