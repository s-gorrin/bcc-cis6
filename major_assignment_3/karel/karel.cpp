
/**
 * File: karel.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-24
 * functions for the Karel class
**/

#include "common.h"

using namespace std;

// initialize variables to start and world size
Karel::Karel(int s) {
	karelRow = 0;
	karelColumn = 0;
	karelFacing = "east";
	worldSize = s;
}

// send Karel's location and direction to cout
void Karel::readout() {
	cout << "Karel is at location (" << karelRow << ", " \
		<< karelColumn << ") facing " << karelFacing << endl;
}

// move Karel one space - returns false for no crash, true for crash
bool Karel::move() {
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

// find new direction for left turn based on current direction
void Karel::turnLeft() {
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

// dialogue for crashed Karel
void Karel::crash(int code) {
	if (code == CRASH_WALL) {
		cout << "Karel tried to move to location (" << karelRow << ", " \
			<< karelColumn << "). Karel has crashed!" << endl;
	}
	else if (code == CRASH_BEEP) {
		cout << "Karel tried to pick a beeper that did not exist. " \
			<< "Karel has crashed!" << endl;
	}
}

// dialogue for intentionally quit Karel
void Karel::cleanQuit() {
	cout << "Karel finished at location (" << karelRow << ", " << \
		karelColumn << ") facing " << karelFacing << \
		". Thank you for not crashing Karel!" << endl;
}

// gets values from Karel
int Karel::get(const int ref) {
	if (ref == ROW_REF) {
		return karelRow;
	}
	if (ref == COL_REF) {
		return karelColumn;
	}
	if (ref == WOR_REF) {
		return worldSize;
	}
	return 0; // if this happens, something has gone very wrong, but without it
			  // I think I might get "control reaches end of non-void function"
}
