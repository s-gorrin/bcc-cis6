/**
 * Filename a3-problem1.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-24
 * Encrypt/decrypt a file with rot13
 * No second file needed because it would be the same.
 * for BCC CIS6 Spring 2020
**/

#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

char rot13(char c) {
	if (islower(c)) {
		if (c <= 'm')
			return c += 13;
		else
			return c -= 13;
	}

	if (isupper(c)) {
		if (c <= 'M')
			return c += 13;
		else
			return c -= 13;
	}

	if (isdigit(c)) {
		if (c <= '4')
			return c += 5;
		else
			return c -= 5;
	}
	return c;
}

int main() {
	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
	string line;

	if (fileIn && fileOut) {
		while (getline(fileIn, line)) {
			for (int i = 0; i < line.length(); i++) {
				fileOut << rot13(line[i]);
			}
			fileOut << endl;
		}
		fileIn.close();
		fileOut.close();
	}
	else {
		cout << "failed to open file\n";
	}

	return 0;
}
