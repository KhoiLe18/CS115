//	Location.cpp
//	Name: Khoi Le
//	ID: 200462293

#include <iostream>
#include "Location.h"
using namespace std;

Location::Location() {
	index = 0;
}

Location::Location (unsigned int index1) {
	index = index1;
}

bool Location::operator== (const Location& other) const {
	if (index == other.index) 
		return true;
	else
		return false;
}

bool Location::isInaccessible () const {
	if (index == 0)
		return true;
	else
		return false;
}

ostream& operator<< (ostream& out, const Location& location) {
	if (location.isInaccessible())
		cout << "(node = INACCESSIBLE)";
	else
		cout << "(node = " << location.index << ")";
	return out;
}