//
//  ScoreTable.cpp
//
//  Student name: Khoi Le
//  Student ID: 200462293
//

#include "ScoreTable.h"
#include <iostream>

using namespace std;

static int elementCount;

// Start of Element class
Element::Element () {
	name = "";
	score = 0;
	p_next = nullptr;
	elementCount++;
}

Element::~Element () {
	elementCount--;
}

int getAllocatedElementCount () {
	return elementCount;
}

Element* copyLinkedList (const Element* p_head1) {
	if (p_head1 == nullptr)
		return nullptr;

	Element* p_head2 = new Element;
	p_head2 -> name = p_head1 -> name;
	p_head2 -> score = p_head1 -> score;

	const Element* p1 = p_head1;
	Element* p2 = p_head2;

	while (p1 -> p_next != nullptr) {
		p2 -> p_next = new Element;

		p1 = p1 -> p_next;
		p2 = p2 -> p_next;

		p2 -> name = p1 -> name;
		p2 -> score = p1 -> score;
	}

	p2 -> p_next = nullptr;

	return p_head2;
}

void destroyLinkedList (Element* p_head) {
	if (p_head != nullptr) {
		Element* pCurrent = nullptr;
		Element* pNext = p_head;

		while (pNext != nullptr) {
			pCurrent = pNext;
    	pNext = pCurrent -> p_next;
    	delete pCurrent;
		}
	}
}
// End of Element class

// Start of ScoreTable class
ScoreTable::ScoreTable () {
	pHead = nullptr;

	assert(isInvariantTrue());
}

ScoreTable::ScoreTable (const ScoreTable& to_copy) {
	assert(to_copy.isInvariantTrue());

	pHead = copyLinkedList(to_copy.pHead);

	assert(isInvariantTrue());
}

ScoreTable::~ScoreTable () {
	assert(isInvariantTrue());

	destroyLinkedList(pHead);
}

ScoreTable& ScoreTable::operator= (const ScoreTable& to_copy) {
	assert(isInvariantTrue());

	if (&to_copy == this) {
		assert(isInvariantTrue());
		return *this;
	}

	else {
		// Deallocate the current linked list
		destroyLinkedList(pHead);

		// Deep copy
		pHead = copyLinkedList(to_copy.pHead);
		assert(isInvariantTrue());
		return *this;
	}
}

void ScoreTable::print () const {
	assert(isInvariantTrue());

	Element* pTemp = pHead;
	
	cout << "Scores:" << endl;
	
	while (pTemp != nullptr) {
		cout << pTemp -> score << '\t' << pTemp -> name << endl;
		pTemp = pTemp -> p_next;
	}
}

void ScoreTable::insert (const string& player_name, int score) {
	assert(isInvariantTrue());

	// Creating a new Element
	Element* pNew = new Element();
	pNew -> name = player_name;
	pNew -> score = score;

	// Insert into an empty list
	if (pHead == nullptr)
		pHead = pNew;

	else {
		Element* pCurr = pHead;
		Element* pPrev = nullptr;

		// Search Linked List
		while (pCurr != nullptr && pCurr -> score > score) {
			pPrev = pCurr;
			pCurr = pCurr -> p_next;
		}

		if (pPrev == nullptr) {
			// Insert at head
			pNew -> p_next = pHead;
			pHead = pNew;
  	}

		else {
			// Insert after pPrev
			pNew -> p_next = pPrev -> p_next;
			pPrev -> p_next = pNew;
		}
	}
	assert(isInvariantTrue());
}

bool ScoreTable::isInvariantTrue () const {
	if (pHead == nullptr)
		return true;
	
	Element* pPrev = pHead;
	Element* pCurr = pHead -> p_next;

	while (pCurr != nullptr) {
		if (pCurr -> score > pPrev -> score)
			return false;
		pPrev = pCurr;
		pCurr = pCurr -> p_next;
	}
	return true;
}
// End of ScoreTable class