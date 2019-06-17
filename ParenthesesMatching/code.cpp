#include <iostream>
#include <stack>

using namespace std;
//Known issues:
    //No open parentheses always makes for a matched case

//Pseudocode for isMatched
//For every open bracket, there has to be a closing bracket
//Assume the string is matched, we will disprove
//The first closing bracket must match the last opened bracket
	//If it does not, then it is not matched
	//If it does,then pop the stack and move to the next element
//There should be no unmatched brackets by the end, meaning the stack is empty. If the stack is not empty, then it is not matched


bool isMatched(string inputString){
    	
    stack<char> expressionStack;
    char currentParen;
    for(int i = 0; i < inputString.length(); i++){
        if (inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{'){
            expressionStack.push(inputString.at(i));
        }
        if (!expressionStack.empty()){
	    switch(inputString.at(i)){     
                case ')':
                    if(expressionStack.top() != '('){
                        return false;
                    }
                    expressionStack.pop();
                    break;
                case '}':
                    if(expressionStack.top() != '{'){
                        return false;
                    }
                    expressionStack.pop();
                    break;
                case ']':
                    if(expressionStack.top() != '['){
                        return false;
                    }
                    expressionStack.pop();
                    break;
            }
	}

    }
    if (expressionStack.empty()){
        return true;
    }
    else{
        return false;
    }

};

int main(){
    cout << isMatched("()") << endl; //Should print true
    cout << isMatched("{()}") << endl; //Should print true
    cout << isMatched("{(])") << endl; //Should print false
    cout << isMatched("]]") << endl;
    cout << isMatched("[{{}}]()") << endl;
    return 0;
}
