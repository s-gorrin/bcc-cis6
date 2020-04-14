/**
 * Filename a3-problem2.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * created by: Seth Gorrin [DATE]
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
// To be honest, I still don't fully understand why it needs a temp
// Maybe I'm doing this wrong, but it seems like there's no point at
// which I am using the temp that couldn't have been the input array
int* resizeArray(int array[], int &size) {
	int *temp = array;
	int *resize = new int[size * 2];

	for (int i = 0; i < size; i++) {
		resize[i] = temp[i];
	}
	size *= 2;

	delete[] temp;
	return resize;
}

// The assignment says to create a main to test the function but
// it does not say if the main should be submitted or not.
int main() {
	int size = SIZE; // SIZE == 5
	int *array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = i * 2;
	}
	printArray(array, 50); // printArray does what it says, (array, size)
	array[50] = 137; // I was expecting this line and above it to seg fault
	cout << array[50] << endl; // They didn't and now I don't know how to test my code
	array = resizeArray(array, size);

	array[SIZE + 2] = 56;
	printArray(array, size);

	delete[] array;
	return 0;
}
