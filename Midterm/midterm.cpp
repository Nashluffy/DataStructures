//Part 1 

//Overview

//Heapsort involves putting the set of numbers into a heap
//Then, take the top element of the heap (minimum in the list) and push_back the output vector
//Pop the top element, leaving you with the second smallest number in the set
//Repeat until the heap is empty

//Pseudocode

//for (auto it:input)
    //heap.insert(it)
//while(!heap.empty())
    //output.push_back(heap.top())
    //heap.pop()

#include <iostream>
#include <queue>


using namespace std;

void heapSort(vector<int> &input){
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for (auto it:input){
        minHeap.push(it);
    }
    input.clear();
    while(!minHeap.empty()){
        input.push_back(minHeap.top());
        minHeap.pop();
    }
}

int main(){
    vector<int> v{95, 249, 965, 760, 819, 108, 555, 42};
    heapSort(v);
    for(auto it:v){
        cout << it << endl;
    }
    return 0;
}


/*Part 2

Q2.1
    Runtime Complexity:
         O(nlogn)
    Line-by-line...
        Merge-sort has runtime... O(nlogn) 
        Looping... O(nlogn + n/2 + n/2)
        Dominated by O(nlogn)...
        Overall... O(nlogn)

Q2.2
    Runtime Complexity:
        O(n)

Q2.3
    Runtime Complexity: 
        O(nk Log nk)
    Line-by-line:
        Insert into min heap... O(logn)
        Do the following for n*k times ... O(nk Log n)
            Get min element... O(1) so O(logn)
            Insert into min heap again.... O(Logk) so O(nk log nk)
    
Q2.4
    Runtime Complexity:
        O(nlogn + mlogm)
    Line-by-line:
        Using mlogm sort... We get O(mlogm)
        Binary search is logn, for each element... O(mlogm + nlogn)
    
Q2.5
    Runtime Complexity:
        O(3^n)
    Line-by-line:
        T(n) = 3T(n-1) if n>0, 1 otherwise
        Substitute T(n-2)
            3 (3T(n-2))
            3^2 T(n-2)
            3^3 T(n-3)
            3^4 T(n-4)
            ....
            3^nT(n-n) -> 3^n T(0)
            3^n
*/
