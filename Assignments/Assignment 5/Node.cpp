//
//  Node.cpp
//  Student name: Khoi Le
//  Student ID: 200462293

#include "Node.h"

#include <cassert>
#include <iostream>

#include "Location.h"

using namespace std;



Node :: Node ()
	: description(0),
	  north(0),
	  south(0),
	  east(0),
	  west(0),
	  is_death(false)
{
}

Node :: Node (unsigned int description1,
              unsigned int north1,
              unsigned int south1,
              unsigned int east1,
              unsigned int west1,
              bool is_death1)
	: description(description1),
	  north(north1),
	  south(south1),
	  east(east1),
	  west(west1),
	  is_death(is_death1)
{
}



void Node :: debugPrint () const
{
	if(is_death)
		cout << "D";
	else
		cout << "N";

	cout
		<< "\t" << description
		<< "\t" << north
		<< "\t" << south
		<< "\t" << east
		<< "\t" << west << endl;
}

unsigned int Node :: getDescription () const
{
	return description;
}

Location Node :: getNorth () const
{
	return Location(north);
}

Location Node :: getSouth () const
{
	return Location(south);
}

Location Node :: getEast  () const
{
	return Location(east);
}

Location Node :: getWest  () const
{
	return Location(west);
}

bool Node :: isDeath () const
{
	return is_death;
}


