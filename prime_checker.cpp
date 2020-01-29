#include <iostream>

using namespace std;

int     prime(int n, int i){
        // return 1 for not prime
        // return 0 for prime
        if(n < 2){
                return 1;
        }
        if(n % i == 0){
                if(n == i){
                        return 0;
                }
                else{
                        return 1;
                }
        }
        else{
                return (prime(n, ++i));
        }
}

int     main(){
        int input;
        cout << "please enter a numbe to find out if it is prime: ";
        cin >> input;
        int output;
        output = prime(input, 2);
        cout << (output == 1 ? "not prime" : "prime") << endl;
        return 0;
}
