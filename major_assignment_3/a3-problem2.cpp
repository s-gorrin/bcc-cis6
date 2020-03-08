/**
 * Filename a3-problem2.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-24
 * find a string in a file and count instances
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FILE_NAME = "input.txt";

/* 
 * I was thinking about this, and decided that you were right,
 * and that indexing through both strings was clunky and ugly.
 * So I did some research and found string.compare() and string.substr().
 * This code now finds two "tomato"s in "tomatomato", and is golfed.
 * Golf may not make code better, but it's pretty slick.
 */ 
// looks for the string in each line and returns the number found
int findString(string find, string line) {
	int found = 0;

	for (int i = 0; i < line.length(); i++) {
		if (line[i] == find[0] &&
				!find.compare(line.substr(i, find.length()))) {
			found++;
		}
	}

	return found;
}

// gets string as input, reads a file, finds instances of the string
void fileReader() {
	ifstream fileIn(FILE_NAME);
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
				cout << "\"" << find << "\" was found on line "
					<< lineCounter << endl;
				totalStrings += temp;
			}
		}
		fileIn.close();
	}
	else {
		cout << "failed to open file\n";
	}

	cout << "The string \"" << find << "\" was found "
		<< totalStrings << (totalStrings == 1 ? " time" : " times")
		<< " in the file.\n"; // apparently ternaries work in cout streams
}

int main() {
	fileReader();

	return 0;
}
