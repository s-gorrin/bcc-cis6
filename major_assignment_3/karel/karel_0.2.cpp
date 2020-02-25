/**
 * File: karel_0.2.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-13
 * basic implementation for karel, 0.2
 * now with more ascii
 * for BCC CIS6 Spring 2020
 * ----------
 * commands: move(); turnLeft(); putBeeper(); pickBeeper(); quit();
 * variables: int karelRow; int karelColumn; string karelFacing;
 * karelRow = 0; karelColumn = 0; karelFacing = east;
**/

#include "common.h"

using namespace std;

// prompt to receive user input
string prompt() {
	string input;
	cout << "> ";
	cin >> input;

	return input;
}

// get input from the user and run commands
void interface(Karel karel, World map) {
	string input = "";
	
	cout << "Welcome to Karel.\nPlease enter a command. Your choices are:\n" \
		<< "move(); turnLeft(); putBeeper(); pickBeeper(); quit();" << endl;

	map.drawMap(karel.get(ROW_REF), karel.get(COL_REF));
	while (input != "quit();") {
		bool crash = false;
		bool print = true;
		int crashCode = 0;

		karel.readout();
		input = prompt();
		if (input == "move();") {
			crash = karel.move();
			if (crash) {
				crashCode = CRASH_WALL;
			}
		}
		else if (input == "turnLeft();") {
			karel.turnLeft();
		}
		else if (input == "putBeeper();") {
			map.putBeeper(karel.get(ROW_REF), karel.get(COL_REF));
		}
		else if (input == "pickBeeper();") {
			crash = map.pickBeeper(karel.get(ROW_REF), karel.get(COL_REF));
			if (crash) {
				crashCode = CRASH_BEEP;
			}
		}
		else if (input == "quit();") {
			karel.cleanQuit();
			print = false;
		}
		else {
			cout << "syntax error" << endl;
			print = false;
		}
		if (crash) {
			karel.crash(crashCode);
			input = "quit();";
			print = false;
		}
		if (print) {
			map.drawMap(karel.get(ROW_REF), karel.get(COL_REF));
		}
	}
}

int main() {
	Karel karel;
	World map;

	karel.init(WORLD_SIZE);
	map.init(WORLD_SIZE);
	interface(karel, map);

	return 0;
}
