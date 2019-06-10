#include <iostream>
#include <stack>

using namespace std;

bool isMatched(string inputString){
    stack<char> expressionStack;
    char currentParen;
    for(int i = 0; i < inputString.length(); i++){
        if (inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{'){       //If it's an opening parentheses, push it into the stack
            expressionStack.push(inputString[i]);
        }
        switch(inputString[i]){     
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
    if (expressionStack.empty()){
        return true;
    }


};

int main(){
    cout << isMatched("()") << endl; //Should print true
    cout << isMatched("{()}") << endl; //Should print true
    cout << isMatched("{(])") << endl; //Should print false

    return 0;
}
