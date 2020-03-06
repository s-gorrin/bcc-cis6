/**
 * Filename a3-problem4.cpp
 * ----------
 * created by: Seth Gorrin 2020-03-05
 * implement a tic-tac-toe game
 * for BCC CIS6 Spring 2020
 * ----------
 * known bug: I don't know how to test
 * 		for too many user inputs.
**/

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

const int SIZE = 3;
const int USER_I = 1;
const int WIN = 1;
const int TIE = 2;
const int NON = 3;
const int BAD_INPUT = 137;
const int BAD_SQUARE = 42;
const char X_WINS = 'X';
const char O_WINS = 'O';
const char EMPTY = '*';

// initialize a blank tic-tac-toe board
void initBoard(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = EMPTY;
		}
	}
}

// print the board
void printBoard(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << board[i][j];
			if (j < SIZE - 1) { // end spaces are sloppy
				cout << ' ';
			}
		}
		cout << endl;
	}
}

// look for wins. return true for win
bool winChecker(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		if (board[i][0] != EMPTY && // row win
				board[i][0] == board[i][1] && 
				board[i][1] == board[i][2]) {
			return true;
		}
		if (board[0][i] != EMPTY && // column win
				board[0][i] == board[1][i] && 
				board[1][i] == board[2][i]) {
			return true;
		}
	}
	if (board[0][0] != EMPTY && // top left, bottom right diagonal win
			board[0][0] == board[1][1] && 
			board[1][1] == board[2][2]) {
		return true;
	}
	if (board[0][2] != EMPTY && // top right, bottom left diagonal win
			board[0][2] == board[1][1] && 
			board[1][1] == board[2][0]) {
		return true;
	}
	return false;
}

// look for ties. return true for tie
bool tieChecker(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == EMPTY)
				return false;
		}
	}
	return true;
}

// checks game status for wins or ties
int statusChecker(char board[][SIZE]) {
	if (winChecker(board))
		return WIN;
	if (tieChecker(board))
		return TIE;

	return NON;
}

// set up game rules
void intro() {
	cout << "Moves are made by entering two numbers - " <<
		"coordinates from the top left corner of the board." << endl <<
		"For example, top left is [1 1], bottom left is [1 3] " <<
		"and the middle of the board is [2 2]." << endl <<
		"To win, a player must mark three squares in a row " <<
		"in any direction, including diagonal." << endl <<
		"Play is only allowed on an empty square. " << 
		"Empty squares are indicated with the \'*\' character." << endl;
}

// check to see if a move is valid
bool validChecker(string row, string col, int &code,  char board[][SIZE]) {
	if (row.length() != 1 || col.length() != 1) {
		code = BAD_INPUT;
		return false;
	}
	if (!isdigit(row[0]) || !isdigit(col[0])) {
		code = BAD_INPUT;
		return false;
	}
	
	int rowInt = stoi(row);
	int colInt = stoi(col);

	if (rowInt > 3 || rowInt < 1 || colInt > 3 || colInt < 1) {
		code = BAD_INPUT;
		return false;
	}

	if (board[rowInt - USER_I][colInt - USER_I] != '*') {
		code = BAD_SQUARE;
		return false;
	}
	
	return true;
}

// player 1 moves
void xTurn(char board[][SIZE]) {
	int code = 0;
	string row, col;

	cout << "Player 1 move: ";
	cin >> row >> col;
	if (validChecker(row, col, code, board)) {
		board[stoi(row) - USER_I][stoi(col) - USER_I] = 'X';
	}
	else {
		while (!validChecker(row, col, code, board)) {
			cout << "Please enter a valid move.\n";
			if (code == BAD_INPUT) {
				cout << "You did not type correct square coordinates.\n";
			}
			else {
				cout << "That was not an empty square.\n";
			}
			cout << "> ";
			cin >> row >> col;
		} 
		board[stoi(row) - USER_I][stoi(col) - USER_I] = 'X';
	}
}

// player 2 moves
void oTurn(char board[][SIZE]) {
	int code = 0;
	string row, col;

	cout << "Player 2 move: ";
	cin >> row >> col;
	if (validChecker(row, col, code, board)) {
		board[stoi(row) - USER_I][stoi(col) - USER_I] = 'O';
	}
	else {
		while (!validChecker(row, col, code, board)) {
			cout << "Please enter a valid move.\n";
			if (code == BAD_INPUT) {
				cout << "You did not type correct square coordinates.\n";
			}
			else {
				cout << "That was not an empty square.\n";
			}
			cout << "> ";
			cin >> row >> col;
		} 
		board[stoi(row) - USER_I][stoi(col) - USER_I] = 'O';
	}
}

// take user input and determine end conditions
char playGame(char board[][SIZE]) {
	int turnNumber = 1; // saves a few calls to statusChecker

	intro();
	while (true) {
		int gameState = NON;

		printBoard(board);
		xTurn(board);
		gameState = statusChecker(board);
		if (turnNumber >= 3 && gameState != NON) {
			if (gameState == WIN)
				return X_WINS;
			return TIE;
		}
		printBoard(board);
		oTurn(board);
		gameState = statusChecker(board);
		if (turnNumber >= 3 && gameState == WIN) {
			return O_WINS;
		}
		turnNumber++;
	}
	return TIE; // this should never happen
}

// print end of game message
void printResults(int winner) {
	if (winner == X_WINS)
		cout << "PLayer 1 has won with the \'X\'s!\n";
	if (winner == O_WINS)
		cout << "Player 2 has won with the \'O\'s!\n";
	if (winner == TIE)
		cout << "It's a cat's game. Next time try a laser pointer.\n";
}

int main() {
	char board[SIZE][SIZE];
	char winner;

	initBoard(board);
	winner = playGame(board);
	printBoard(board);
	printResults(winner);

	return 0;
}
