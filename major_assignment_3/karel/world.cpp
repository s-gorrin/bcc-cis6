/**
 * File: world.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-24
 * functions for the World class
**/

#include "common.h"

using namespace std;

// create map grid with 0-values
void World::init(const int size) {
	vector<int> rows(size, MAP_INIT);
	vector<vector<int> > temp(size);
	grid = temp;
	worldSize = size;

	for (int i = 0;  i < size; i++) {
		grid[i] = rows;
	}
}

// draw the map, render symbols
void World::drawMap(int kRow, int kCol) {
	const char EMPTY = '-';
	const char ROBOT = 'O';
	const char BEEPR = 'X';
	const char RANDB = '@';

	for (int i = worldSize - 1; i >= 0; i--) { // flip n/s. size -1 is critical
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

// place a beeper on the map
void World::putBeeper(int kRow, int kCol) {
	// IF HANDLING MULTIPLE BEEPERS IS NOT ALLOWED, NEED TO ADD:
	// if (grid[kRow][kCol] == MAP_INIT) { }
	grid[kRow][kCol] += 1;
}

// pick a beeper, return true for crash
bool World::pickBeeper(int kRow, int kCol) {
	// SEE ABOVE FOR CHANGE IN CASE OF SINGLE BEEPERS ONLY
	grid[kRow][kCol] -= 1;
	if (grid[kRow][kCol] < MAP_INIT) {
		return true;
	}
	return false;
}
