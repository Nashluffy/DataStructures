// Remove duplicate and stop words in a sentence
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


string delDupStop(string s, vector<string>& stop){
    stringstream ss;
    string currentWord, outputString;
    ss << s;
    bool stopDetected;
    while(!ss.eof()){
        ss >> currentWord;
        stopDetected = false;
        for (auto it:stop){
            if(currentWord == it){
                stopDetected = true;
            }
        }
        if (stopDetected == false){
            outputString = outputString + currentWord + " ";
            stop.push_back(currentWord);
        }
    }
    return outputString;
}


int main(){
    vector<string> stop_words = {"a",  "an", "be", "in", "is", "of", "or", "that", "the", "to"}; 
    cout << delDupStop("to be or not to be that is the question", stop_words) << endl; //Should output "not question"
    cout << delDupStop("of all the gin joints in all the towns in all the world she walks into mine", stop_words) << endl; //
}