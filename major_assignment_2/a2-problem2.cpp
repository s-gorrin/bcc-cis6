/**
 * Filename a2-problem2.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-05
 * find the square root of a number
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

double absolute(double n) {
    return (n > 0 ? n : -n);
}

double squareRootFinder(double number) {
    if (number == 0) {
        return 0;
    }
    else if (number < 0) {
        number *= -1;
        cout << "i * ";
    }

    double lg;
    double ng;

    lg = 1.1;
    ng = 1.0;

    while (absolute(lg - ng) > 0.00001) {
        lg = ng;
        ng = 0.5 * (lg + (number / lg));
    }

    return ng;
}

int main() {
    double input;

    cout << "please enter a number to find the square root: ";
    cin >> input;

    cout << squareRootFinder(input) << endl;

    return 0;
}
