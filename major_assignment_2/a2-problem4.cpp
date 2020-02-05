/**
 * Filename a2-problem4.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-05
 * print the fibonacci sequence to the n-th number 
 * for BCC CIS6 Spring 2020
**/

#include <iostream>

using namespace std;

int fib(int number) {
    int n1, n2;

    n1 = 0;
    n2 = 1;

    for (int i = 0; i < number; i++) {
        int temp;
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }

    return n2;
}

int main() {
    int input;

    cout << "please enter a number to get the fibonacci number of that place: ";
    cin >> input;

    cout << fib(input) << endl;
    
    return 0;
}
