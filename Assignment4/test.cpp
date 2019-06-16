//Collaborative filtering - how much two lists "have in common"
//The largest number of inversions a n-elemtn array can have is n(n-1)/2
//Brute force method would be double-nested for loop. This would be O(n^2)
//Could we do better? Yes, divide and conquer
//Classify an inversion in three different ways
    //Left inversion if both of the array indices are at most n/2 - Compute recursively
    //Right inversion if both of these array indices are strictly greater than n/2 -  Compute recursively
    //Split inversion if smaller is less than n/2 but larger is greater than n/2 - Need separate subroutine for these

//High-level algorithm
    //countInversion (array a, length n)
        //If n == 1
            //return 0
        //Else
            //x = Count(1st half of A, n/2)
            //y = Count(2nd half of A, n/2)
            //z = CountSplitInv(A, n)
        //return x+y+z

//Goal is to implement in linear (O(n)) time for z, O(nlogn) overall

//Have recursive calls both count inversions and sort. Merge subroutine naturally uncovers split inversions


/* Test cases - 1) Random array mixed positive and negative numbers 2) Sorted array 3) Reverse sorted array 4) Custom input */
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

const int NUM_ELEM = 15;
const int MAX_VAL = 100;

int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end);

int main(int argc, char **argv)
{
    vector<int> my_vec;
    vector<int>::iterator it;
    srand(time(0)); // Seed for random number generator
    assert(argc == 2);
    switch(atoi(argv[1])) {
        case 1:
                // Input vector of positive and negative random ints
                for (int i = 0; i < NUM_ELEM; i++)
                    my_vec.push_back(rand() % MAX_VAL - (MAX_VAL/2));
                break;
        case 2:
                // Input vector of sorted ints
                for (int i = 0; i < NUM_ELEM; ++i)
                    my_vec.push_back(i);
                break;
        case 3:
                // Input vector of reverse sorted ints
                for (int i = 0; i < NUM_ELEM; ++i)
                    my_vec.push_back(NUM_ELEM-i);
                break;
        case 4:
                // Custom input
                my_vec.push_back(4);
                my_vec.push_back(5);
                my_vec.push_back(6);
                my_vec.push_back(1);
                my_vec.push_back(2);
                my_vec.push_back(3);
                break;
        default:
                cout << "Invalid input" << endl;
                return -1;
        
    }
    
    // Print vector
    for (it = my_vec.begin(); it !=  my_vec.end(); ++it)
        cout << *it << " ";
    cout << endl << endl;
    
    vector<int> sort_vec(my_vec);
    cout << "Number of inversions " << countInv(my_vec, sort_vec, 0, my_vec.size()) << endl;

    // Sorted array
    for (it = sort_vec.begin(); it != sort_vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int countInv(vector<int> &in_vec, vector<int> &out_vec, int begin, int end) {

 // Your code goes here

}