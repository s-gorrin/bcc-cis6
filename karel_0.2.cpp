/**
 * File: a3-problem0.cpp
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

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char EMPTY = '-';
const char ROBOT = 'O';
const char BEEPR = 'X';
const char RANDB = '@';
const int WORLD_SIZE = 15;
const int MAP_INIT = 0;
const int ROW_REF = 1;
const int COL_REF = 2;
const int WOR_REF = 3;
const int CRASH_WALL = 1;
const int CRASH_BEEP = 2;

class Karel {
	private:
		int karelRow;
		int karelColumn;
		string karelFacing;
		int worldSize;

	public:
		void init(int);
		void readout();
		bool move();
		void turnLeft();
		void crash(int);
		void cleanQuit();
		int get(const int);
};

class World {
	private:
		vector<vector<int> > grid;
		int worldSize;

	public:
		void init(int);
		void drawMap(int, int);
		void putBeeper(int, int);
		bool pickBeeper(int, int);

};

void Karel::init(int s) { // initialize variables to start and world size
	karelRow = 0;
	karelColumn = 0;
	karelFacing = "east";
	worldSize = s;
}

void Karel::readout() { // send Karel's location and direction to cout
	cout << "Karel is at location (" << karelRow << ", " \
		<< karelColumn << ") facing " << karelFacing << endl;
}

bool Karel::move() { //  move Karel one space - returns false for no crash, true for crash
	switch (karelFacing[0]) {
		case 'e': ++karelColumn;
						break;
		case 'w': --karelColumn;
						break;
		case 'n': ++karelRow;
						break;
		case 's': --karelRow;
						break;
	}
	if (karelRow >= worldSize || karelColumn >= worldSize) {
		return true;
	}
	else if (karelRow < 0 || karelColumn < 0) {
		return true;
	}
	else{
		return false;
	}
}

void Karel::turnLeft() { // find new direction for left turn based on current direction
	switch (karelFacing[0]) {
		case 'e': karelFacing = "north";
							break;
		case 'w': karelFacing = "south";
							break;
		case 'n': karelFacing = "west";
							break;
		case 's': karelFacing = "east";
							break;
	}
}

void Karel::crash(int code) { // dialogue for crashed Karel
	if (code == CRASH_WALL) {
		cout << "Karel tried to move to location (" << karelRow << ", " \
			<< karelColumn << "). Karel has crashed!" << endl;
	}
	else if (code == CRASH_BEEP) {
		cout << "Karel tried to pick a beeper that did not exist. " \
			<< "Karel has crashed!" << endl;
	}
}

void Karel::cleanQuit() { // dialogue for exited Karel
	cout << "Karel finished at location (" << karelRow << ", " << \
		karelColumn << ") facing " << karelFacing << \
		". Thank you for not crashing Karel!" << endl;
}

int Karel::get(const int ref) { // gets values from Karel
	if (ref == ROW_REF) {
		return karelRow;
	}
	if (ref == COL_REF) {
		return karelColumn;
	}
	if (ref == WOR_REF) {
		return worldSize;
	}
	return 0; // if this happens, something has gone wrong
}

void World::init(int size) { // create map grid with 0-values
	vector<int> rows(size, MAP_INIT);
	vector<vector<int> > temp(size);
	grid = temp;
	worldSize = size;

	for (int i = 0;  i < size; i++) {
		grid[i] = rows;
	}
}

void World::drawMap(int kRow, int kCol) { // draw the map, render symbols
	for (int i = worldSize - 1; i >= 0; i--) { // flips north/south. size - 1 is critical.
		for (int j = 0; j < worldSize; j++) {
			if (i == kRow && j == kCol && grid[i][j] > MAP_INIT ) {
				cout << RANDB;
			}
			else if (i == kRow && j == kCol) {
				cout << ROBOT;
			}
			else if (grid[i][j] > MAP_INIT) {
				cout << BEEPR;
			}
			else {
				cout << EMPTY;
			}
			if (j < worldSize - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

void World::putBeeper(int kRow, int kCol) { // place a beeper on the map
	// IF HANDLING MULTIPLE BEEPERS IS NOT ALLOWED, NEED TO ADD:
	// if (grid[kRow][kCol] == MAP_INIT) { }
	grid[kRow][kCol] += 1;
}

bool World::pickBeeper(int kRow, int kCol) { // pick a beeper, true for crash
	// SEE ABOVE FOR CHANGE IN CASE OF SINGLE BEEPERS ONLY
	grid[kRow][kCol] -= 1;
	if (grid[kRow][kCol] < MAP_INIT) {
		return true;
	}
	return false;
}

string prompt() { // prompt to receive user input
	string input;
	cout << "> ";
	cin >> input;

	return input;
}

void interface(Karel karel, World map) { // get input from the user and run commands
	string input;
	
	cout << "Welcome to Karel.\nPlease enter a command. Your choices are:\n" \
		<< "move(); turnLeft(); putBeeper(); pickBeeper(); quit();" << endl;

	map.drawMap(karel.get(ROW_REF), karel.get(COL_REF));
	input = "";
	while (input != "quit();") {
		bool crash = false;
		bool print = true;
		int crashCode;

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
