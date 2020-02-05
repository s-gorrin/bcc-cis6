/**
 * File: a2-problem0.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-02
 * basic text-based implementation for karel
 * for BCC CIS6 Spring 2020
 * ----------
 * commands: move(); turnLeft(); quit(); else: "please input xyz"
 * variables: int karelRow; int karelColumn; string karelFacing;
 * karelRow = 0; karelColumn = 0; karelFacing = east;
**/

#include <iostream>
#include <string>

using namespace std;

class Karel{
        private:
                int karelRow;
                int karelColumn;
                string karelFacing;
                int worldSize;

        public:
                void init(int);
                void readout();
                bool move();
                void turnLeft();
                void crash();
                void cleanQuit();
};

void Karel::init(int s){ // initialize variables
        karelRow = 0;
        karelColumn = 0;
        karelFacing = "east";
        worldSize = s;
}

void Karel::readout(){ // send Karel's location and direction to cout
        cout << "Karel is at location (" << karelRow << ", " \
           << karelColumn << ") facing " << karelFacing << endl;
}

bool Karel::move(){ //  move Karel one space - returns false for no crash, true for crash
        switch (karelFacing[0]){
                case 'e': ++karelColumn;
                                  break;
                case 'w': --karelColumn;
                                  break;
                case 'n': --karelRow;
                                  break;
                case 's': ++karelRow;
                                  break;
        }
        if (karelRow >= worldSize || karelColumn >= worldSize){
                return true;
        }
        else if (karelRow < 0 || karelColumn < 0){
                return true;
        }
        else{
                return false;
        }
}

void Karel::turnLeft(){ // find new direction for left turn based on current direction
        switch (karelFacing[0]){
                case 'e': karelFacing = "north";
                                  break;
                case 'w': karelFacing = "south";
                                  break;
                case 'n': karelFacing = "west";
                                  break;
                case 's': karelFacing = "east";
                                  break;
        }
}

void Karel::crash(){ // dialogue for crashed Karel
        cout << "Karel tried to move to location (" << karelRow << ", " \
                << karelColumn << "). Karel has crashed!" << endl;
}

void Karel::cleanQuit(){ // dialogue for exited Karel
        cout << "Karel finished at location (" << karelRow << ", " << \
                karelColumn << ") facing " << karelFacing << \
                ". Thank you for not crashing Karel!" << endl;
}

string prompt(){ // prompt to receive user input
        string input;
        cout << "> ";
        cin >> input;

        return input;
}

int main(){
        Karel karel;
        string input;

        karel.init(8);

        cout << "Welcome to Karel.\nPlease enter a command. Your choices are:\n" \
                << "move(); turnLeft(); quit" << endl;

        while (input != "exit"){
                int crash;
                crash = false;

                karel.readout();
                input = prompt();
                if (input == "move();"){
                        crash = karel.move();
                }
                else if (input == "turnLeft();"){
                        karel.turnLeft();
                }
                else if (input != "exit"){ // process invalid input
                        cout << "I don't understand that command." << endl;
                }
                else { // anything that's not "move", "turn" or invalid is an exit
                        karel.cleanQuit();
                }
                if (crash){
                        karel.crash();
                        input = "exit";
                }
        }

        return 0;
}
