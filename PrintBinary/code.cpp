#include <iostream>
#include <string>

using namespace std;

string printBinary(int input, string output){
    output = "1";
    if(input/2 >= 1){			
        output = printBinary(input/2, output);		
	if(input%2 > 0){		
            output = "1" + output;
	}
	else{
	    output = "0" + output;
	}
    }
    return output;
}

int main(){
    string output;
    cout << printBinary(2,output) << endl;
    cout << printBinary(3,output) << endl;
    cout << printBinary(15,output) << endl;
    cout << printBinary(46,output) << endl;
}
