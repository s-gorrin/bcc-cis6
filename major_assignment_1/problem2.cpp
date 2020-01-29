#include <iostream>

using namespace std;

int	main() {
	// Seth Gorrin. 29 January 2020
	// only works with correct input
	// rounding is hard
	float due, rec, raw_change;
	int change, dollars, quarters, dimes, nickles, pennies;

	dollars = 0;
	quarters = 0;
	dimes = 0;
	nickles = 0;
	pennies = 0;

	cout << "how much is due? (format: x.yz) ";
	cin >> due;
	cout << "how much did you pay? (format: x.yz) ";
	cin >> rec;

	raw_change = rec - due;
	change = (int)(raw_change * 100);

	if (raw_change < 0) {
		cout << "you have under paid by $" << raw_change << endl;
	}
	else if (change == 0) {
		cout << "you paid exact change" << endl;
	}
	else {
		int temp, cents;
		dollars = change / 100;
		change -= (dollars * 100);
		cents = change;

		// get modulo, store it in temp, subtract it from change, divide by coin
		temp = cents % 25;
		quarters = (cents - temp) / 25;

		cents = temp;
		temp = cents % 10;
		dimes = (cents - temp) / 10;

		cents = temp;
		temp = cents % 5;
		nickles = (cents - temp) / 5;

		pennies = temp;
	}

	cout << "change due:" << endl;
	cout << dollars << " dollars" << endl << quarters << " quarters" << endl << dimes << " dimes" << endl << nickles << " nickles" << endl << pennies << " pennies" << endl;

	return 0;
}
