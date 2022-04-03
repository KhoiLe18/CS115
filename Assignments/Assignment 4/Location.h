//	Location.h
//	Name: Khoi Le
//	ID: 200462293

#pragma once
#include <iostream>
using namespace std;

class Location {
	public:
		unsigned int index;

		// Default constructor
		Location ();

		// Init constructor
		Location (unsigned int index1);
		
		// Equality constructor
		bool operator== (const Location& other) const;

		bool isInaccessible () const;
};

ostream& operator<< (ostream& out, const Location& location);