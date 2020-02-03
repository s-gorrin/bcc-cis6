/**
 * Filename problem1.cpp
 * ----------
 * created by: Seth Gorrin 2020-01-29
 * multipliction by addition
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

int	main() {
	int num1;
	int num2;
	int safe1;
	int safe2;

	cout << "please enter a number to be multiplied: ";
	cin >> num1;
	cout << "please enter a second number: ";
	cin >> num2;

	safe1 = num1;
	safe2 = num2;

	for (num2; num2 > 1; num2--) {
		num1 += safe1;
	}

	cout << safe1 << " x " << safe2 << " = " << num1 << endl;

	return 0;
}
