/**
 * Filename a3-problem3.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * created by: Seth Gorrin 13 April 2020
 * recursive binary search
 * resursive binary search
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

const int SIZE = 1000;

int binarySearch(int sortedArray[], int value, int start, int end) {
	int mid = (start + end) / 2;

	if (start >= end)
		return -1;
	if (sortedArray[mid] == value)
		return mid;

	cout << mid << endl;

	if (value < sortedArray[mid])
		return binarySearch(sortedArray, value, start, mid);
	return binarySearch(sortedArray, value, mid + 1, end);
}

int main() {
	int arr[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	cout << "Search for: ";
	int find;
	cin >> find;
	cout << binarySearch(arr, find, 0, SIZE) << " <-- index of number" << endl;

	return 0;
}
