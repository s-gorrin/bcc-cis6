
/**
 * Filename a3-problem3.cpp
 * ----------
 * created by: Seth Gorrin 2020-03-02
 * create a histogram plot for random numbers
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

const int C_SIZE = 10;
const int REPS = 10000;
const int SUM_SET = 10;
const int MAX_BAR = 50;
const int BORDER_ALLOW = 51;
const int DECIMALS = 1;
const int INTEGARS = 2;

// chose to solve part a or part b of the assignment
int pickPart() {
	string part;

	cout << "Show solution for part [a] or part [b]?\n> ";
	cin >> part;
	while (part != "a" && part != "b") {
		cout << "Please enter either \"a\" or \"b\"\n> ";
		cin >> part;
	}
	if (part == "a")
		return DECIMALS;
	return INTEGARS;
}

// initialize the counters array and histogram vector
void initializer(int counters[], vector<vector<char> > &histogram) {
	for (int i = 0; i < C_SIZE; i++) {
		vector<char> bar(0);
		counters[i] = 0;
		histogram.at(i) = bar;
	}
}

// generate a random number between 0 and 1.0000
double getRandom() {	
	return (rand() % 10000) / 10000.0;
}

// generate REPS random numbers and sort them
void countRandoms(int counters[]) {
	for (int i = 0; i < REPS; i++) {
		double random = getRandom();
		
		for (int j = 0; j < C_SIZE; j++) {
			if (random < (j + 1) / 10.0 && random > j / 10.0) {
				counters[j]++;
			}
		}
	}
}

// generate REPS * 10 random numbers, sum groups, and sort
void sumRandoms(int counters[]) {
	for (int i = 0; i < REPS; i++) {
		double setTotal = 0.0;

		for (int j = 0; j < SUM_SET; j++) {
			setTotal += getRandom();
		}
		for (int j = 0; j < C_SIZE; j++) {
			if (setTotal < (j + 1) && setTotal > j) {
				counters[j]++;
			}
		}
	}
}

// find the largest number in counters
int findBiggest(int counters[]) {
	int theBigOne = 0;

	for (int i = 0; i < C_SIZE; i++) {
		if (counters[i] > theBigOne) {
			theBigOne = counters[i];
		}
	}

	return theBigOne;
}

// fill histogram with '#' marks based on counter values
void makeBarGraph(int counters[], vector<vector<char> > &histogram) {
	double ratio = findBiggest(counters) / 50.0; // 50.0 to make a double

	for (int i = 0; i < C_SIZE; i++) {
		for (int j = 0; j < BORDER_ALLOW; j++) {
		// if the current index is <= to the height of this bar, cap at 50
			if (j < counters[i] / ratio && j < MAX_BAR) {
				histogram.at(i).push_back('#');
			}
			else { // if this spot is taller than the bar height, make it a ' '
				histogram.at(i).push_back(' ');
			}
		}
	}
}

// print out the histogram, but like, sideways
void printBarGraph(vector<vector<char> > &histogram) {
	for (int j = BORDER_ALLOW - 1; j >= 0; j--) { // start at the end
		for (int i = 0; i < C_SIZE; i++) {
			if (histogram.at(i).at(j) == '#') {
				cout << '|' << histogram.at(i).at(j) << '|';
			}
			else if (j > 0 && histogram.at(i).at(j - 1) == '#') {
				cout << " _ ";
			}
			else {
				cout << "   ";
			}
			if (i < C_SIZE - 1) { // if not the last bar, print a space
				cout << ' ';
			}
		}
		cout << endl;
	}
}

int main() {
	int counters[C_SIZE];
	vector<vector<char> > histogram(C_SIZE);
	int userChoice = pickPart();
	srand(time(0));

	initializer(counters, histogram);
	if (userChoice == DECIMALS)
		countRandoms(counters);
	else
		sumRandoms(counters);

	makeBarGraph(counters, histogram);
	printBarGraph(histogram);

	return 0;
}
