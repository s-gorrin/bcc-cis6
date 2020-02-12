#include <iostream>
#include <vector>

using namespace std;

void doThing(vector<vector<int>>& testVector) {
	int x = 0;
	int y = 0;
	int size = testVector[0].size();

	for (int i = size - 1; i >= 0; i--) { // flips north/south. size - 1 is critical. this is going to complicate crashing
		for (int j = 0; j < size; j++) {
			testVector[i][j] = i + j; // makes it more intreresting
			if (i == y && j == x) {
				cout << '@';
			}
			else if (testVector[i][j] % 3 == 0) {
				cout << 't';
			}
			else if (testVector[i][j] % 2 == 0) {
				cout << 'v';
			}
			else {
				cout << (char)(testVector[i][j] + 100);
			}
			if (j < size - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
	testVector[0][0] = 13;
}

int main() {
	int input;

	cout << "enter world size: ";
	cin >> input;

	vector<int> col(input, 1);
	vector<vector<int>> testVector(input);
	


	for (int i = 0;  i < input; i++) {
		testVector[i] = col;
	}

	cout << testVector[0][0] << endl;
	doThing(testVector);
	cout << testVector[0][0] << endl;

	return 0;
}
