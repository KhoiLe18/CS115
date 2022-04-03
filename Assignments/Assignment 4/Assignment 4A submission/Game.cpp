//	Game.cpp			
//	Name: Khoi Le 
//	ID: 200462293

#include <string>
#include <cassert>
#include <iostream>
#include "Game.h"
#include "ItemManager.h"
#include "Item.h"
#include "World.h"
#include "Location.h"
using namespace std;

Game::Game (const string& game_name):	
	gameWorld(game_name),
	gameItemManager(game_name),
	playerLocation(gameWorld.getStart())
{
	assert(isInvariantTrue());
}

bool Game::isOver () const {
	bool isVic = gameWorld.isVictory(playerLocation);
	bool isDead = gameWorld.isDeath(playerLocation);
	if (isVic || isDead)
		return true;
	else
		return false;
}

void Game::printStartMessage () const {
	gameWorld.printStartMessage();
}

void Game::printEndMessage () const {
	gameWorld.printEndMessage();
}

void Game::printDescription () const {
	gameWorld.printDescription(playerLocation);
	gameItemManager.printAtLocation(playerLocation);
}

void Game::printInventory () const {
	gameItemManager.printInventory();
}

void Game::printScore () const {
		cout << "In this game you scored " << gameItemManager.getScore() << " points" << endl;
}

void Game::reset () {
	assert(isInvariantTrue());

	playerLocation = gameWorld.getStart();
	gameItemManager.reset();

	assert(isInvariantTrue());
}

void Game::moveNorth () {
	assert(isInvariantTrue());
	
	bool canGo = gameWorld.canGoNorth(playerLocation);
	if (canGo) {
		playerLocation = gameWorld.getNorth(playerLocation);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction" << endl;

	assert(isInvariantTrue());
}

void Game::moveSouth () {
	assert(isInvariantTrue());
	
	bool canGo = gameWorld.canGoSouth(playerLocation);
	if (canGo) {
		playerLocation = gameWorld.getSouth(playerLocation);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction" << endl;

	assert(isInvariantTrue());
}

void Game::moveEast () {
	assert(isInvariantTrue());

	bool canGo = gameWorld.canGoEast(playerLocation);
	if (canGo) {
		playerLocation = gameWorld.getEast(playerLocation);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction" << endl;

	assert(isInvariantTrue());
}

void Game::moveWest () {
	assert(isInvariantTrue());
	
	bool canGo = gameWorld.canGoWest(playerLocation);
	if (canGo) {
		playerLocation = gameWorld.getWest(playerLocation);
		printDescription();
	}	
	else
		cout << "There is no way to go in that direction" << endl;

	assert(isInvariantTrue());
}

void Game::takeItem (char id) {
	assert(isInvariantTrue());

	gameItemManager.take(id, playerLocation);
	
	assert(isInvariantTrue());
}

void Game::leaveItem (char id) {
	assert(isInvariantTrue());

	gameItemManager.leave(id, playerLocation);

	assert(isInvariantTrue());
}

bool Game::isInvariantTrue () const {
	return gameWorld.isValid(playerLocation);
}