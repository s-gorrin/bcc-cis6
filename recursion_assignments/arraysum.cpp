#include <iostream>

using namespace std;

int arraySum(int array[], int arraySize) {
	// BASE CASE
	if (arraySize == 0) {
		return 0;
	}
	// RECURSIVE CASE
//	array[arraySize - 2] += array[arraySize - 1];
//	arraySum(array, arraySize - 1);
//	return array[0];
	return array[arraySize - 1] + arraySum(array, arraySize - 1);
}

int main() {
	int array[] = {0, 2, 4, 10};
	cout << arraySum(array, 4) << endl;
	cout << "Was it 16?" << endl;

	return 0;
}
