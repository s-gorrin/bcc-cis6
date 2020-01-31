#include <iostream>
#include <string>

using namespace std;

int flipper(string num, int n){
        // I was trying to do something different
        // which I thought would work and be clever
        // but it turns out it didn't work
        // becasue I understand neither recursion
        // nor strings in C++
        // but this seems to work, so here you go
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
