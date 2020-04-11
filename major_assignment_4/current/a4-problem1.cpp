/**
 * Filename a3-problem1.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * created by: Seth Gorrin [DATE]
 * Take a list of up to 20 names as input
 * Sort them into alphabetical order
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const int MAX_NAMES = 10;


// prints an array, separated by commas
void printArray(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i][0] = toupper(arr[i][0]); // capitalize first letter of each name
		cout << arr[i];
		if (i < size - 1) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
}

// validate names are only alpha characters and normalize case to lower
bool checkNames(string &name) {
	for (int i = 0; i < name.length(); i++) {
		if (!isalpha(name[i]))
			return false;
		name[i] = tolower(name[i]);
	}

	return true;
}

// populate array from string of names, return size of array
int tokenizeNames(string rawInput, string input[]) {
	int i = 0;
	string name;
	stringstream nameStream(rawInput);

	while (getline(nameStream, name, ' ') && i < MAX_NAMES) {
		if (name.length() > 0 && checkNames(name)) {
			input[i] = name;
			i++;
		}
	}
	cout << "There were " << i << " names\n";

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
	int size;

	size = takeInput(input);
	printArray(input, size);

	return 0;
}

// TODO list
// get input and generate array of names in lowercase
// radix sort names
// 		need to account for dissimilar name lengths
// print array of sorted names
//
// Functions:
// take input
// normalize names, possibly with lower-than-a charcater
// counting sort for letter
// 		generate sorted list from counting sort (helper function?)
// radix sort to loop counting sort
// strip trailing characters and recapitalize first letter
// print list
