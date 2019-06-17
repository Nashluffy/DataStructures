#include <iostream>
#include <string>

using namespace std;

void printBinary(int input){
    if (input > 1){
	    printBinary(input/2);
    }
    cout << input%2;
}

int main(){
    printBinary(2);
    cout << endl;
    printBinary(3);
    cout << endl;
    printBinary(15);
    cout << endl;
    printBinary(46);
    cout << endl;
}
