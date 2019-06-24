//Write a program that takes as input a set of words and returns groups of anagrams for those words. Here's the test program -

//Pseudocode
//vector output
//Insert all characters of originalWord into hashT.
//while(!originalWord.empty())
  //hashT.insert(character, hashT.at(character) + 1)
//while(!comparedWord.empty())
  //const_iterator index = hashT.find(character)
  //if index != hashT.end()
    //if hashT.at(index) > 1
      //hashT.at(index) = hashT.at(index) - 1;
    //else
      //hashT.erase(index)
//if hashT.size() == 0
  //output.insert(comparedWord)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);

int main()
{
  vector<string> word_list = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis"};
   vector<vector<string>> result = findAnagrams(word_list);
   for (auto anagrams: result) {
      for (auto words: anagrams)
         cout << words << " ";
         cout << endl;
    }
   return 0;
}

vector<vector<string>> findAnagrams(const vector<string>& dict)
{
vector<vector<string>> finalOutput;

for (auto originalWord:dict){
  vector<string> anagramVector;
  for (auto comparedWord:dict){
    unordered_map<char, int> hashT;
    //Inserting characters into hashT, with key as char and value as count
    for (auto character:originalWord){
      if (hashT.find(character) == hashT.end()){
        hashT.insert(make_pair(character, 1));
      }
      else{
        hashT.at(character) = hashT.at(character) + 1;
      }
    }

    for (auto character:comparedWord){
      auto index = hashT.find(character);
      if (index != hashT.end()){
        if (index -> second > 1){
          index -> second = index->second - 1;
        }
        else{
          hashT.erase(index->first);
        }
      }
    }

    if (hashT.size() == 0){
      anagramVector.push_back(comparedWord);
    }
  }
  finalOutput.push_back(anagramVector);
}

return finalOutput;
}
