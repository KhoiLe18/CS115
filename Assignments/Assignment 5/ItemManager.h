//
//  ItemManager.h
//  Student name: Khoi Le
//  Student ID: 200462293
//  A module to keep track of all the items in the game.
//

#pragma once

#include <string>

#include "Location.h"
#include "Item.h"
using namespace std;

//
//  ItemManager
//
//  A class to keep track of all the items in the game.
//
//  Class Invariant:
//    <1> items[i].isInitialized()
//                                     WHERE 0 <= i < ITEM_COUNT
//
class ItemManager {
private:
	int itemCount;
	Item* items;

public:
// Default constructor	
	ItemManager ();
	
//
//  Constructor
//
//  Purpose: To create an ItemManager for a game with the
//           specified name.
//  Parameter(s):
//    <1> game_name: The game name
//  Precondition(s):
//    <1> game_name != ""
//  Returns: N/A
//  Side Effect: A new ItemManager is created with the items for
//               the game ghostwood.  The game name is ignored.
//               All the items are placed at their respective
//               starting locations.
//
	ItemManager (const std::string& game_name);

//
//  getCount
//
//  Purpose: To determine the number of items stored in this
//           ItemManager.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The number of items.
//  Side Effect: N/A
//
	unsigned int getCount () const;

// Copy constructor	
	ItemManager (const ItemManager& to_copy);

// Destructor	
	~ItemManager ();

// Assignment operator
	ItemManager& operator= (const ItemManager& to_copy);

//
//  getScore
//
//  Purpose: To determine if the player score.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The current player score.
//  Side Effect: N/A
//
	int getScore () const;

//
//  printAtLocation
//
//  Purpose: To print all items at the specified node.
//  Parameter(s):
//    <1> location: The location
//  Precondition(s): N/A
//  Returns: N/A
//  Returns: The description for each item at node location is
//           printed.
//
	void printAtLocation (const Location& location) const;

//
//  printInventory
//
//  Purpose: To print all items in the player invenrtory.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Returns: The description for each item in the player
//           inventory is printed.
//
	void printInventory () const;

//
//  isInInventory
//
//  Purpose: To determine if the item with the specified id is
//           in the player invenrtory.
//  Parameter(s):
//    <1> id: The item id
//  Precondition(s): N/A
//  Returns: Whether the item with id id is in the player
//           inventory.  If there is no such item, false is
//           returned.
//  Side Effect: N/A
//
	bool isInInventory (char id);

//
//  reset
//
//  Purpose: To reset all items.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: All items are moved to their respective
//               starting locations.
//
	void reset ();

//
//  take
//
//  Purpose: To attempt to take the item with the specified id,
//           assuming that the player is at the specified
//           location.
//  Parameter(s):
//    <1> id: The item id
//    <2> player_location: The player location
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: If there is an item with id id location
//               player_location, that item is moved to the
//               player inventory.  Otherwise, a message is
//               printed.
//
	void take  (char id, const Location& player_location);

//
//  leave
//
//  Purpose: To attempt to leave the item with the specified id,
//           assuming that the player is at the specified
//           location.
//  Parameter(s):
//    <1> id: The item id
//    <2> player_location: The player location
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: If there is an item with id id in the player
//               inventory, that item is moved to location
//               player_location.  Otherwise, a message is
//               printed.
//
	void leave (char id, const Location& player_location);

private:
// load
	void load (const string& filename);

//
//  find
//
//  Purpose: To determine the index of the item with the
//           specified id.
//  Parameter(s):
//    <1> id: The item id
//  Precondition(s): N/A
//  Returns: The index of the item with id id.  If there is no
//           such item, NO_SUCH_ITEM (a hidden constant) is
//           returned.  If there is more than one such item, the
//           index of any one of them might be returned.
//  Side Effect: N/A
//
	unsigned int find (char id) const;

// sort
	void sort ();

//
//  isInvariantTrue
//
//  Purpose: To determine if the class invariant is true.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether the class invariant is true.
//  Side Effect: N/A
//
	bool isInvariantTrue () const;	
};

