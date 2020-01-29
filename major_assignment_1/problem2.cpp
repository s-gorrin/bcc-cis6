#include <iostream>
#include <math.h>

using namespace std;

int	main() {
	// Seth Gorrin. 29 January 2020
	// 
	float due, rec, change;
	int dollars, quarters, dimes, nickles, pennies;

	dollars = 0;
	quarters = 0;
	dimes = 0;
	nickles = 0;
	pennies = 0;

	cout << "how much is due? (format: x.yz) ";
	cin >> due;
	cout << "how much did you pay? (format: x.yz) ";
	cin >> rec;

	change = rec - due;
	cout << "change before rounding " << change << endl;
	//PROBLEM IS HERE
	//change = floorf(change * 100) / 100;
	change = (int)((change + .005) * 100) / 100.0;
	cout << "change after rounding " << change << endl;

	if (change < 0) {
		cout << "you have under paid by $" << change << endl;
	}
	else if (change == 0) {
		cout << "you paid exact change" << endl;
	}
	else {
		int temp, cents;
		dollars = (int)change;
		change -= (float)dollars;
		cents = change * 100;

		// get modulo, store it in temp, subtract it from change, divide by coin
		temp = cents % 25;
		quarters = (cents - temp) / 25;
		cout << "temp after 25s " << temp << endl;

		cents = temp;
		temp = cents % 10;
		dimes = (cents - temp) / 10;
		cout << "temp after 10s " << temp << endl;

		cents = temp;
		temp = cents % 5;
		nickles = (cents - temp) / 5;

		cout << "temp after 5s " << temp << endl;

		pennies = temp;
	}

	cout << "change due:" << endl;
	cout << dollars << " dollars" << endl << quarters << " quarters" << endl << dimes << " dimes" << endl << nickles << " nickles" << endl << pennies << " pennies" << endl;

	return 0;
}


// Write a program that directs a cashier how to give change.  
// The program has two inputs: the amount due and the amount received from the customer.  
// Display the dollars, quarters, dimes, nickels, and pennies that the customer should receive.
