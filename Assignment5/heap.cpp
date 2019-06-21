
//Given: A sequence of numbers x1, x2, ..., xn input one-by-one, find the median as the numbers arrive.
//See Heap lecture - 1 for solution. Solution implemented using a min-heap and max-heap that holds the bottom half and top half of the numbers respectively.

//Heaps are implemented using the priority_queue container from the STL

//The test function is provided below. Also included is a function print_queue if you need to view the contents of the heaps at any point.

//Statistical median is the middle number of a group of numbers that have been arranged in order by size.
//If there is an even number of terms, the median is the average of the two middle names

//Pseudocode
// 1 2 3 4 5 6 7 8 9 10
// 5 + 6 / 2  = = 5.5
//Lower half stored in minHeap -> 1 2 3 4 5
//Upper half stored in maxHeap -> 6 7 8 9 10
//Median would be minHeap.top() + maxHeap.min() / 2

//Need to be able to insert elements and keep heaps balanced
//Since we aren't passing the median in, we have to calculate it each time
//We have a couple different cases,

  //Nothing in either heap (first insert)
    //Goal here is to make heaps unbalanced
    //When we come around to the second element, we will hit unbalanced case which will save us from segfault
    //Doesn't really matter which heap we insert into, rest of the code should fix it

  //Heaps equal size
    //median = maxHeap.top + minHeap.top / 2
    //if num > Median
      //insert into maxHeap
      //median = maxHeap.top
    //else
      //insert into minHeap
      //median = minHeap.top

  //minHeap > maxHeap
    //if num > median
      //maxHeap.push(num)
      //median = maxHeap.top + minHeap.top /2
    //else
      //maxHop.push(minHeap.top)
      //minHeap.pop
      //minHeap.push(num)
      //median = maxHeap.top + minHeap.top /2

  //maxHeap > minHeap
    //if num > Median
      //maxHop.push(minHeap.top)
      //minHeap.pop
      //minHeap.push(num)
      //median = maxHeap.top + minHeap.top /2
    //else
      //minHeap.push(num)
      //median = maxHeap.top + minHeap.top /2

#include <iostream>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;

const int MAX_VAL = 100;
const int NUM_ELEM = 15;

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num);
template<typename T> void print_queue(T& q);

int main() {
    int current_median;
    priority_queue<int> lo; // Bottom half of numbers - max-heap (default)
    priority_queue<int, vector<int>, greater<int> > hi; // Top half of numbers - min-heap
    srand(time(0)); // Seed for random number generator
    for (int i = 0; i < NUM_ELEM; i++) {
        int n = rand() % MAX_VAL;
        current_median = find_median(hi, lo, n);
        cout <<  "Inserted " << n << " Median " << current_median << endl << endl;
    }
    return 0;
}

template<typename T>

void print_queue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        std::cout << q_copy.top() << " ";
        q_copy.pop();
    }
    std::cout << '\n';
}

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num) {
  int median;

  //Nothing in either heap (first insert)
  if ((h_low.size() + h_high.size() )== 0){
    h_low.push(num);
    median = h_low.top();
    return median;
  }

  //Heaps equal size
  if (h_low.size() == h_high.size()){
    median = (h_low.top() + h_high.top()) / 2 ;
    if (num > median){
      h_high.push(num);
      median = h_high.top();
    }
    else{
      h_low.push(num);
      median = h_low.top();
    }
    return median;
  }

  //minHeap > maxHeap
  if (h_low.size() > h_high.size()){
    median = h_low.top();
    if(num > median){
      h_high.push(num);
    }
    else{
      h_high.push(h_low.top());
      h_low.pop();
      h_low.push(num);
    }
    median = (h_low.top() + h_high.top()) / 2 ;
    return median;
  }

  //maxHeap > minHeap
  if (h_high.size() > h_low.size()){
    median = h_high.top();
    if(num > median){
      h_low.push(h_high.top());
      h_high.pop();
      h_high.push(num);
    }
    else{
      h_low.push(num);
    }
    median = (h_low.top() + h_high.top()) / 2 ;
    return median;
  }


}
