/**
 * It's this Karel Struct assignment
 * This one is Seth's
 * I'm sure the existence of this header
 * and also the solution I use have made
 * it generally unnecessary for me to
 * announce myself in this way. Oh well.
**/

#include <iostream>
#include <string>

using namespace std;


const int MAX_ROW = 14;
const int MAX_COLUMN = 14;


enum Direction {
	NORTH, EAST, SOUTH, WEST
};

struct Karel {
	int row;
	int column;
	Direction facing;
	string name;
};

void karelMove(Karel &karel){
	switch (karel.facing) {
		case NORTH: karel.row--;
					break;
		case SOUTH: karel.row++;
					break;
		case EAST: karel.row++;
				   break;
		case WEST: karel.row--;
				   break;
	}
}

void karelTurnLeft(Karel &karel){
	if (karel.facing == NORTH){
		karel.facing = WEST;
	} else if (karel.facing == WEST){
		karel.facing = SOUTH;
	} else if (karel.facing == SOUTH){
		karel.facing = EAST;
	} else if (karel.facing == EAST){
		karel.facing = NORTH;
	}
}

int main(){
	Karel karel;
	karel.row = 15;
	karel.column = 0;
	karel.facing = EAST;
	karel.name = "Karel";

}
