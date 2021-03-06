//
//  main.cpp
//
//  Student name: Khoi Le
//  Student ID: 200462293
//

#include <string>
#include <iostream>

#include "Game.h"

using namespace std;

const bool WAIT_AT_END = true;

int main () {
	//static const string GAME_NAME = "blizzard";
	//static const string GAME_NAME = "ghostwood";
	static const string GAME_NAME = "jungle";

	Game game(GAME_NAME);
	string username;

	game.printStartMessage();

	cout << endl << "Please enter your name: ";
	getline(cin,username);
	cout << "Hello, " << username << endl;

	game.printDescription();

	bool is_quit = false;
	while(!is_quit && !game.isOver()) {
		cout << "Next? ";

		string line;
		do  // must get some input!
		{
			getline(cin, line);
		}
		while(line == "");

		char command = line[0];
		switch(command)
		{
		case '#':
			// do nothing
			//cout << "Invalid command!" << endl;
			break;

		case 'q':
			cout << "Are you sure you want to quit? ";
			getline(cin, line);
			if(line != "" && line[0] == 'y')
				is_quit = true;
			break;

		case 'n':
			game.moveNorth();
			break;
		case 's':
			game.moveSouth();
			break;
		case 'e':
			game.moveEast();
			break;
		case 'w':
			game.moveWest();
			break;

		case 't':
			cout << "Take what? ";
			getline(cin, line);

			if(line != "")
				game.takeItem(line[0]);
			else
				cout << "Invalid item." << endl;
			break;

		case 'l':
			cout << "Leave what? ";
			getline(cin, line);

			if(line != "")
				game.leaveItem(line[0]);
			else
				cout << "Invalid item." << endl;
			break;

		case 'i':
			game.printInventory();
			break;

		case 'r':
			cout << "Are you sure you want to restart? ";
			getline(cin, line);
			if(line != "" && line[0] == 'y')
			{
				game.printScore();
				game.updateScoreTable(username);
				game.reset();
				game.printDescription();

				cout << endl << "Please enter your name: ";
				getline(cin,username);
				cout << "Hello, " << username << endl;
			}
			break;

		default:
			cout << "Invalid command!" << endl;
			break;
		}
	}

	cout << endl;
	game.printScore();
	game.updateScoreTable(username);
	game.printEndMessage();

	if(WAIT_AT_END)
	{
		cout << endl;
		cout << "Press [ENTER] to continue... ";
		string line;
		getline(cin, line);

		// to wait for a non-empty line instead
		//while(line == "")
		//{
		//	getline(cin, line);
		//}
	}

	return 0;
}
