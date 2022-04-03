//	Game.h			
//	Name: Khoi Le 
//	ID: 200462293

#include <string>
#include <cassert>
#include <iostream>
#include "ItemManager.h"
#include "Item.h"
#include "World.h"
#include "Location.h"
using namespace std;

class Game {
	World gameWorld;
	ItemManager gameItemManager;
	Location playerLocation;
	
public:
	Game (const string& game_name);
	bool isOver () const;
	void printStartMessage () const;
	void printEndMessage () const;
	void printDescription () const;
	void printInventory () const;
	void printScore () const;
	void reset ();
	void moveNorth ();
	void moveSouth ();
	void moveEast ();
	void moveWest ();
	void takeItem (char id);
	void leaveItem (char id);

private:
	bool isInvariantTrue () const;
};