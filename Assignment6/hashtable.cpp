//Write a program that takes as input a set of words and returns groups of anagrams for those words. Here's the test program -

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
vector<vector<string>> output;
unordered_map<string, int> hashT;
int i = 1;
for (auto it:dict){
  hashT.insert(make_pair(it, i++));
}
return output;
}
