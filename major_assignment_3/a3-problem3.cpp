
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
const int MAX_BAR = 50;
const int BORDER_ALLOW = 51;

// initialize the counters array and histogram vector
void initializer(int counters[], vector<vector<char> > &histogram) {
	for (int i = 0; i < C_SIZE; i++) {
		vector<char> bar(0);
		counters[i] = 0;
		histogram.at(i) = bar;
	}
}

// generate a random number between 0 and 1000
double getRandom() {	
	return (rand() % 1000) / 1000.0;
}

// generate REPS random numbers and sort them
void countRandoms(int counters[]) {
	for (int i = 0; i < REPS; i++) {
		double random = getRandom();
		
		if (random < 0.1)
			counters[0]++;
		else if (random < 0.2)
			counters[1]++;
		else if (random < 0.3)
			counters[2]++;
		else if (random < 0.4)
			counters[3]++;
		else if (random < 0.5)
			counters[4]++;
		else if (random < 0.6)
			counters[5]++;
		else if (random < 0.7)
			counters[6]++;
		else if (random < 0.8)
			counters[7]++;
		else if (random < 0.9)
			counters[8]++;
		else
			counters[9]++;
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
// SOMETHING IS WRONG WITH MY ALGORITHM HERE
// should never get a bar of height 51... check much taller bars
// and see if the tallest is always that? (put more whitespace above)
void makeBarGraph(int counters[], vector<vector<char> > &histogram) {
	int ratio = findBiggest(counters) / MAX_BAR;

	cout << ratio << endl;
	for (int i = 0; i < C_SIZE; i++) {
		for (int j = 0; j < BORDER_ALLOW; j++) {
			if (j <= counters[i] / ratio) {	// if the current index is <=
											// the height of this bar
				histogram.at(i).push_back('#');
			}
			else { // if this spot is taller than the bar height, make it a ' '
				histogram.at(i).push_back(' ');
			}
		}
	}
}

// print out the histogram, but like, sideways
// NEED TO ADD SUPPORT FOR TOP _ per bar
// something like:
// if this spot is ' ' and the next spot is '#'
// 		cout a '_' 
// if this spot is ' ' and next spot is ' '
// 		cout three spaces to match "|#|"
void printBarGraph(vector<vector<char> > &histogram) {
	// testing
	cout << histogram.at(0).at(50) + 10 << endl;
	cout << histogram.at(0).size() << endl;
	// /testing
	for (int j = BORDER_ALLOW - 1; j >= 0; j--) { // start at the end
		for (int i = 0; i < C_SIZE; i++) {
			cout << '|'  << histogram.at(i).at(j) << '|';
			if (i < C_SIZE - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

int main() {
	int counters[C_SIZE];
	vector<vector<char> > histogram(C_SIZE);
	int totalChecker = 0; // for testing only. delete from final code

	srand(time(0));
	
	initializer(counters, histogram);
	countRandoms(counters);
	makeBarGraph(counters, histogram);
	printBarGraph(histogram);

	// below is testing stuff
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << counters[i] << endl;
		totalChecker += counters[i];
	}
	cout << endl << "total randoms counted: " << totalChecker << endl;
	histogram.at(0).push_back('g');
	cout << histogram.at(0).at(0) << endl;

	return 0;
}
