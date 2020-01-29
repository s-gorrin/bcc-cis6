#include <iostream>

using namespace std;

int	main() {
	// Seth Gorrin. 29 January 2020
	// I don't really know what "most efficient" means
	// especially not in a multiplication by addition problem
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
