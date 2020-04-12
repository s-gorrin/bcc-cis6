/**
 * Filename a3-problem1.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * created by: Seth Gorrin 10 April 2020
 * Take a list of up to 20 names as input
 * Sort them into alphabetical order
 * for BCC CIS6 Spring 2020
 **/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const int MAX_NAMES = 20;
const int COUNT_SIZE = 27;
const char PADDING = '`';
const char DIFF = '`';

// prints an array, separated by commas
void arrayPrint(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i < size - 1) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
}

// removes the trailing PADDING characters and capitalized first letter
void cleanup(string arr[], int size) {
	int len = arr[0].length() - 1;

	for (int i = 0; i < size; i++) {
		for (int c = len; c >= 0; c--) {
			if (arr[i][c] == PADDING) {
				arr[i].pop_back();
			}
			if (c == 0) {
				arr[i][c] = toupper(arr[i][c]);
			}
		}
	}
}

// coppies a string from SOURCE to DESTination
void arrayCopy(string source[], string dest[], int size) {
	for (int i = 0; i < size; i++) {
		dest[i] = source[i];
	}
}


// set the count array to all zero values
void zeroCount(int count[]) {
	for (int i = 0; i < COUNT_SIZE; i++) {
		count[i] = 0;
	}
}

// add values in count to get indices of sorted
void addCount(int count[]) {
	for (int i = 1; i < COUNT_SIZE; i++) {
		count[i] += count[i - 1];
	}
}

// Sort a list of strings based on a letter key
void countSort(string unsorted[], string sorted[], int size, int key) {
	int count[COUNT_SIZE];

	zeroCount(count);
	for (int i = 0; i < size; i++) {
		count[(unsorted[i][key] - DIFF)]++;
	}

	addCount(count);
	for (int i = size - 1; i >= 0; i--) { // backwards to retain order
		int countIndex = unsorted[i][key] - DIFF;
		int sortedIndex = count[countIndex] - 1;

		sorted[sortedIndex] = unsorted[i];
		count[countIndex]--;
	}

	if (key) {
		arrayCopy(sorted, unsorted, size);
	}
}

// sorts an array of strings into alphabetical order
void arraySort(string unsorted[], string sorted[], int size) {
	for (int key = unsorted[0].length() - 1; key >= 0; key--) {
		countSort(unsorted, sorted, size, key);
	}

	cleanup(sorted, size);
}

// Below this line is input management, above this line is sorting (mostly)

// make names lowercase and normalize length
void normalizeNames(string arr[], int size) {
	int longest = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < arr[i].length(); j++) {
			arr[i][j] = tolower(arr[i][j]);
		}
		if (arr[i].length() > longest)
			longest = arr[i].length();
	}

	for (int i = 0; i < size; i++) {
		arr[i].append(((longest) - arr[i].length()), PADDING);
	}
}

// validate names are only alpha characters
bool checkName(string &name) {
	for (int i = 0; i < name.length(); i++) {
		if (!isalpha(name[i]))
			return false;
	}

	return true;
}

// populate array from string of names, return size of array
int tokenizeNames(string rawInput, string input[]) {
	int i = 0;
	string name;
	stringstream nameStream(rawInput);

	while (getline(nameStream, name, ' ') && i < MAX_NAMES) {
		if (name.length() > 0 && checkName(name)) {
			input[i] = name;
			i++;
		}
	}

	normalizeNames(input, i); // this will make names lowercase and pad length

	return i;
}

// get list of names as raw input
int takeInput(string input[]) {
	string rawInput;
	int nameCount;

	cout << "Please enter up to twenty names, separated by spaces." << endl;
	getline(cin, rawInput);
	nameCount = tokenizeNames(rawInput, input);

	return nameCount;
}

int main() {
	string input[MAX_NAMES];
	string unsorted[MAX_NAMES];
	string sorted[MAX_NAMES];
	int size;

	size = takeInput(input);
	arrayCopy(input, unsorted, size);
	arraySort(unsorted, sorted, size);
	arrayPrint(sorted, size);

	return 0;
}
