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

/*
Errors so Far:
while working on karel, I had a bunch of errors from reading about how different things worked, and then stopping before I actually found out everything they needed to function. Specifically:
pseudocode: I tried to start writing Karel without any and (thankfully very quickly) realized that I was making a bad choice. I did some planning and it was smooth sailing from there.
switches: first I didn't see where it said thy had to be ints, and then I didn't realize that the break; statements were crutial.
classes: I didn't read far enough to find out how to format class functions. At this point, I think what I had would have worked, but the final version is much cleaner.

not karel:
floats: apparently floats are weird. I was having a lot of problems until I found out that in float math, 1.02 - 1.01 = 0.00999999. This is obviously a problem if you're rounding down.
                The answer to this one is to avoid doing math with floating point numbers as much as possible.
*/

/*
Phonebook Algorithm:
Look at the first letter in the name and flip the phone book to that letter.
Look at the second letter and flip the phone book until I find names with the first two letters.
Continue in that fashion until I find an entry with all matching letters.
Look next to the name entry to find the associated number.
*/
