//	Location.h
//	Name: Khoi Le
//	ID: 200462293

#pragma once
#include <iostream>
using namespace std;

class Location {
	public:
		int row, column;

		// Default constructor
		Location ();

		// Init constructor
		Location (int row1, int column1);
		
		// Equality constructor
		bool operator== (const Location& other) const;
};

ostream& operator<< (ostream& out, const Location& location);