/**
 * Filename a3-problem2.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-24 {DATE}
 * find a string in a file and count instances
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// looks for the string in each line and returns the number found
int findString(string find, string line) {
	int j = 0, subLength = 0, found = 0;

	for (int i = 0; i < line.length(); i++) {
		if (line[i] == find[j]) {
			subLength++;
			j++;
		}
		else {
			subLength = 0;
			j = 0;
		}
		if (subLength == find.length()) {
			found++;
			subLength = 0;
			j = 0;
		}
	}
	
	return found;
}

// gets string as input, reads a file, finds instances of the string
void fileReader() {
	ifstream fileIn("input.txt");
	string line, find;
	int lineCounter = 0, totalStrings = 0;

	cout << "Please enter a string to find: ";
	cin >> find;

	if (fileIn) {
		while (getline(fileIn, line)) {
			int temp = 0;
			lineCounter++;
			temp = findString(find, line);
			if (temp > 0) {
				cout << "String found on line " << lineCounter << endl;
				totalStrings += temp;
			}
		}
		fileIn.close();
	}
	else {
		cout << "failed to open file\n";
	}

	cout << "The string was found " << totalStrings << " times in the file.\n";
}

int main() {
	fileReader();

	return 0;
}

/**
 * Write a program that asks the user for a file name and a string for which to search. 
 * The program should search the file for every occurrence of a specified string.
 * When the string is found, the number of the line that contains it should be displayed.
 * After all the occurrences have been located, the program should report the number of times the string appeared in the file.
 *
 * You are expected to define functions to perform the various steps in this program.
**/
