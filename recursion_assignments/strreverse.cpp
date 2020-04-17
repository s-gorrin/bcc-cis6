#include <iostream>

using namespace std;

string reverser(string input) {
	//BASE CASE - no more string?
	if (input.length() == 0)
		return input;
	
	// RECURSIVE CASE - doing the function plus a thing
	return reverser(input.substr(1)) + input[0];
}

int main() {
	string input;
	cin >> input;
	cout << reverser(input) << endl;

	return 0;
}
