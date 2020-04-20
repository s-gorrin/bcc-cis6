/**
 * Filename a3-problem2.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * created by: Seth Gorrin 12 April 2020
 * implement a dynamic array resizer
 * for BCC CIS6 Spring 2020
 **/

#include <iostream>

using namespace std;

const int SIZE = 5;

// Print an array of ints, separated by spaces
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i < size - 1)
			cout << ' ';
	}
	cout << endl;
}

// Resize an array
int* resizeArray(int array[], int &size) {
	int *resize = new int[size * 2];

	for (int i = 0; i < size; i++) {
		resize[i] = array[i];
	}
	size *= 2;

	delete[] array;
	return resize;
}

int main() {
	int size = SIZE; // SIZE == 5
	int *array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = i * 2;
	}
	printArray(array, 50);
	array[50] = 137;
	cout << array[50] << endl;
	array = resizeArray(array, size);

	array[SIZE + 2] = 56;
	printArray(array, size);

	delete[] array;
	return 0;
}
