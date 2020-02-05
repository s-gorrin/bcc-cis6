/**
 * Filename a2-problem1.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-05
 * print stars for 2^n
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

int	raise(int base, int power) {
	int ret;

	ret = base;

	if (power == 0) {
		return 1;
	}

	for (int i = power; i > 1; i--) {
		ret *= base;
	}

	return ret;
}

void printer(int i) {
	for (int j = 0; j < raise(2, i); j++) {
		cout << "*";
	}
}

int main() {
	int pow;
	int i;

	i = 0;

	cout << "enter a value of n for 2^n: ";
	cin >> pow;

	for (; i <= pow; i++) {
		printer(i);	
		cout << endl;
	}

	i -= 2;

	for (; i >= 0; i--) {
		printer(i);
		cout << endl;
	}

	return 0;
}
