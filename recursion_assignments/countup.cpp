#include <iostream>

using namespace std;

void countup(int n) {
	if (n > 0)
		countup(n - 1);
	cout << n << endl;
}


int main() {
	int n;
	cout << "enter a small number: ";
	cin >> n;
	countup(n);

	return 0;
}
