#include <iostream>

using namespace std;

bool isPalindrome(string testString) {
	// BASE CASE: no more string
	if (testString.length() <= 1)
		return true;

	// RECURSIVE CASE: front matches end
	if (testString[0] == testString[testString.length() - 1]) {
		testString.pop_back();
		return isPalindrome(testString.substr(1));
	}

	return false;
}

int main() {
	string test;
	cin >> test;
	cout << "palindrome? 1 for yes, 0 for no: " << isPalindrome(test) << endl;

	return 0;
}
