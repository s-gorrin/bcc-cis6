/**
 * File: problem3.cpp
 * ----------
 * created by: Seth Gorrin 2020-01-29
 * invert a number (does not need to store it)
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <string>

using namespace std;

int flipper(string num, int n){
        if(n >= 0){
                cout << num[n];
                return flipper(num, --n);
        }
        return 0;
}

int main(){
        string num; // no number? no problem!

        cout << "Please enter a number: ";
        cin >> num;

        flipper(num, num.length());
        cout << endl;

        return 0;
}
