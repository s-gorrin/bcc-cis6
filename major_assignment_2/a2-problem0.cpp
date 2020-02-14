/**
 * File: a2-problem0.cpp
 * ----------
 * created by: Seth Gorrin 2020-02-02
 * basic text-based implementation for karel
 * for BCC CIS6 Spring 2020
 * ----------
 * commands: move(); turnLeft(); quit else: "please input xyz"
 * variables: int karelRow; int karelColumn; string karelFacing;
 * karelRow = 0; karelColumn = 0; karelFacing = east;
**/

#include <iostream>
#include <string>

using namespace std;

const int WORLD_SIZE = 8;

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

void Karel::init(int s){ // initialize variables to start and world size
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

void interface(Karel karel){ // get input from the user and run commands
        string input;
        
        cout << "Welcome to Karel.\nPlease enter a command. Your choices are:\n" \
                << "move(); turnLeft(); quit" << endl;

        input = "";
        while (input != "quit"){
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
                else if (input == "quit"){
                        karel.cleanQuit();
                }
                else {
                        cout << "I don't understand that command." << endl;
                }
                if (crash){
                        karel.crash();
                        input = "quit";
                }
        }
}

int main(){
        Karel karel;

        karel.init(WORLD_SIZE);
        interface(karel);

        return 0;
}
