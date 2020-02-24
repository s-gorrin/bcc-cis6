/**
 * Filename dmv.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-24
 * gets and checks answers for DMV test
 * for BCC CIS6 Spring 2020
**/

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 15;

bool inputChecker(char input) {
    string options = "ABCD";

    for (int i = 0; i < options.length(); i++) {
        if (options[i] == input)
            return true;
    }
    return false;
}

void initializeArrays(char answers[], int incorrect[]) {
    for (int i = 0; i < SIZE; i++) {
        incorrect[i] = 0;
        answers[i] = '0';
    }
}

void getInput(char answers[]) {
    char input;
    int index = 0;

    while (index < SIZE) {
        cout << "enter an answer: ";
        cin >> input;
        if (inputChecker(input)) {
            answers[index] = input;
            index++;
        }
        else {
            cout << "Please enter a valid input: \"A, B, C, or D\"" << endl;
        }
    }
}

int checkAnswers(char answers[], int incorrect[]) {
    char key[] = { 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D' };
    int correctCount = 0;
    int index = 0;

    for (int i = 0; i < SIZE; i++) {
        if (answers[i] == key[i]) {
            correctCount++;
        }
        else {
            incorrect[index] = (i + 1);
            index++;
        }
    }

    return correctCount;
}

void printResults(int correct, int incorrect[]) {
    int index = 0;

    cout << "Number of correct answers: " << correct << endl <<
        "Number of incorrect answers: " << SIZE - correct << endl;

    if (incorrect[index] != 0) {
        cout << "Questions answered incorrectly: ";
    }

    while (incorrect[index] != 0) {
        cout << incorrect[index];
        index++;
        if (incorrect[index] != 0) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    char answers[SIZE];
    int incorrect[SIZE];
    int correctCount;

    initializeArrays(answers, incorrect);
    getInput(answers);
    correctCount = checkAnswers(answers, incorrect);
    printResults(correctCount, incorrect);

    return 0;
}
