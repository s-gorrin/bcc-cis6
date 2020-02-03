/**
 * File: problem2.cpp
 * ----------
 * created by: Seth Gorrin 2020-01-29
 * determine change for a money transaction
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

int main() {
        float due, rec, raw_change;
        int change, dollars, quarters, dimes, nickles, pennies;

        // initialize zero values for ease of printing later
        dollars = 0;
        quarters = 0;
        dimes = 0;
        nickles = 0;
        pennies = 0;

        // get user input
        cout << "how much is due? (format: x.yz) ";
        cin >> due;
        cout << "how much did you pay? (format: x.yz) ";
        cin >> rec;

        // convert from float, try not to have rounding errors
        rec *= 100;
        due *= 100;
        raw_change = (rec - due) / 100;
        change = (int)(raw_change * 100); // get change as an int

        // get values
        if (raw_change < 0) {
                cout << "you have under paid by $" << (raw_change * -1) << endl;
        }
        else if (change == 0) {
                cout << "you paid exact change" << endl;
        }
        else {
                int temp, cents; // is this correct scoping?
                dollars = change / 100;
                change -= (dollars * 100);
                cents = change;

                // get modulo, store it in temp, subtract it from cents, divide by coin
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
