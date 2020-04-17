#include <iostream>

using namespace std;

bool isMember(int array[], int arraySize, int n) {
	// BASE
	if (arraySize == 0) {
		return false;
	}

	// BASE 2?
	if (array[arraySize - 1] == n) {
		return true;
	}

	// RECURSIVE CASE
	return isMember(array, arraySize - 1, n);
}

int main() {
	int array[] = {1, 2, 3, 5, 8, 13, 21, 34, 55};
	int test;
	cout << "what to look for: ";
	cin >> test;
	cout << isMember(array, 9, test) << endl;

	return 0;
}
