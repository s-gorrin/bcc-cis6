/**
 * Filename a2-problem3.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-05
 * count the number of vowels and consonants in a word
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int get_type(char c) { // return 1 for vowel, 0 for consonant, -1 for not a letter
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        return 1;
    }
    else if (c > 'a' && c < 'z') {
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    string input;
    int vow, con;

    vow = 0;
    con = 0;

    cout << "Please enter a word: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (get_type(tolower(input[i])) == 1) {
            vow++;
        }
        else if (get_type(tolower(input[i])) == 0) {
            con++;
        }
    }

    cout << "The word " << input << " contains " << vow << " vowels and " << con << " consonants\n";
    return 0;
}
