/**
 * Filename a3-problem4.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~
 * created by: Seth Gorrin 18 April 2020
 * implement Ackermann's Function
 * very small numbers only
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

const int M = 3; // Probably best not to go above 3 on this one
const int N = 13; // Tested up to 15, which seg faulted after 2 minutes

// The Ackermann Function. I tried outputting the values as it ran,
// But 3, 2 was so many lines I quickly decided time made more sense
long ackermann(int m, int n) {
	if (m == 0)
		return n + 1;
	if (n == 0)
		return ackermann(m - 1, 1);

	return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
	cout << "No user input because I want " << 
	   "lots of thinking to go into number choices." << endl
	   << "Change values in consts. Carefully." << endl;

	cout << ackermann(M, N) << endl;

	return 0;
}
