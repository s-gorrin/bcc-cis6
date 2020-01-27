#include <iostream>
#include <string>

using namespace std;

int main() {
	/**
	 * Short assignment: first C++ program
	 * Seth Gorrin. 27 January 2020
	 * Learning how for loops work in C++
	 * Also that output stream thing is neat.
	 * Very visual and clear.
	**/

	string full = "";
	string annual = "###                         ANNUAL CONFERENCE                        ###\n";
	string empty = "###";
	string name = "### NAME:";
	string org = "### ORGANIZATION:";
	for (int i = 72; i > 0; i--) {
		full.append("#");
	}
	full.append("\n");

	for (int i = 66; i > 0; i--) {
		empty.append(" ");
	}
	empty.append("###\n");

	for (int i = 60; i > 0; i--) {
		name.append(" ");
	}
	name.append("###\n");

	for (int i = 52; i > 0; i--){
		org.append(" ");
	}
	org.append("###\n");

	cout << full << annual << full << name << empty << full << org << empty << full;

	return 0;
}
