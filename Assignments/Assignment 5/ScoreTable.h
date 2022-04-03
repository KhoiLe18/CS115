//
//  ScoreTable.h
//
//  Student name: Khoi Le
//  Student ID: 200462293
//  A module to epresent a node in a linked list of scores.
//

#pragma once

#include <string>

using namespace std;

// Start of Element class
class Element {
public:
	string name;
	int score;
	Element* p_next;

	Element ();
	~Element ();
};

int getAllocatedElementCount ();
Element* copyLinkedList (const Element* p_head1);
void destroyLinkedList (Element* p_head);
// End of Element class

// Start of ScoreTable class
class ScoreTable {
private:
	Element* pHead;

public:
//
// Default constructor
//
// Purpose: to create a new ScoreTable
// Parameter(s): N/A
// Precondition(s): N/A
// Returns: N/A
// Side effect: a new ScoreTable is created with its head pointer pointing to nullptr
//
	ScoreTable ();

//
// Copy constructor
//
// Purpose: to perform a deep copy of a ScoreTable
// Parameter(s): 
//  <1> to_copy: a ScoreTable that will be copied
// Precondition(s): N/A
// Returns: N/A
// Side effect: create a new copy of the to_copy ScoreTable
//
	ScoreTable (const ScoreTable& to_copy);

//
// Destructor
//
// Purpose: to deallocate the linked list
// Parameter(s): N/A
// Precondition(s):
//  <1> the score of the previous element is bigger or equal to the next element
// Returns: N/A
// Side effect: delete the whole linked list
//	
	~ScoreTable ();

//
// Assignment operator
//
// Purpose: to assign a ScoreTable to another ScoreTable
// Parameter(s):
//  <1> to_copy: a ScoreTable that will be copied
// Precondition(s):
//  <1> the score of the previous element is bigger or equal to the next element
// Returns: a pointer to this
// Side effect: deallocate the current linked list and perform a deep copy of the to_copy ScoreTable
//	
	ScoreTable& operator= (const ScoreTable& to_copy);

//
// print
//
// Purpose: to print out the scores and names in the linked list
// Parameter(s): N/A
// Precondition(s):
//  <1> the score of the previous element is bigger or equal to the next element
// Returns: N/A
// Side effect: N/A
//	
	void print () const;

//
// insert
//
// Purpose: to insert a new element into the linked list
// Parameter(s):
//  <1> player_name: the name of a player expressed as a string
//  <2> score: the player's score expressed as an int
// Precondition(s):
//  <1> the score of the previous element is bigger or equal to the next element
// Returns: N/A
// Side effect: a new element is inserted into the linked list
//	
	void insert (const string& player_name, int score);

private:
	bool isInvariantTrue () const;
};
// End of ScoreTable class