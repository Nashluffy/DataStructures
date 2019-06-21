
//Given: A sequence of numbers x1, x2, ..., xn input one-by-one, find the median as the numbers arrive.
//See Heap lecture - 1 for solution. Solution implemented using a min-heap and max-heap that holds the bottom half and top half of the numbers respectively.

//Heaps are implemented using the priority_queue container from the STL

//The test function is provided below. Also included is a function print_queue if you need to view the contents of the heaps at any point.

//Statistical median is the middle number of a group of numbers that have been arranged in order by size.
//If there is an even number of terms, the median is the average of the two middle names

//Pseudocode
//Median is the max of min heap and max
// 1 2 3 4 5 6 7 8 9 10
// 5 + 6 / 2  = = 5.5
//Lower half stored in minHeap -> 1 2 3 4 5
//Upper half stored in maxHeap -> 6 7 8 9 10
//Median would be minHeap.top() + maxHeap.min() / 2

//Insert a new element, 11, and calculate the Median

//Find median element before insert
      //If (minHeap.size()%2 == 0)
        //return median = minHeap.top()
      //Else If (maxHeap.size()%2 == 0)
        //return median = maxHeap.top()
      //Else
        //return median = minHeap.top() + maxHeap.top() / 2

//Insert new element based on median

    //If medianEle <= newElement
        // minHeap.insert(newElement)
    //If medianEle >= newElement
        //maxHeap.insert(newElement)

//Calculate new median
    //If (minHeap.size()%2 == 0)
      //return median = minHeap.top()
    //Else If (maxHeap.size()%2 == 0)
      //return median = maxHeap.top()
    //Else
      //return median = minHeap.top() + maxHeap.top() / 2

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

int calcMedian(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num){
  int median;
  if ((h_low.size() + h_high.size() )== 0){
    median = 0;
    return median;
  }
  if (h_low.size()%2 != 0){
    median = h_low.top();
    return median;
  }
  else if (h_high.size()%2 != 0){
    median = h_high.top();
    return median;
  }
  else{
    median = h_low.top() + h_high.top() / 2 ;
    return median;
  }
}

int find_median(priority_queue<int, vector<int>, greater<int>>& h_high, priority_queue<int>& h_low, int num) {
int median;
median = calcMedian(h_high, h_low, num);

if(median <= num){
  h_low.push(num);
}
if(median >= num){
  h_high.push(num);
}

median = calcMedian(h_high, h_low, num);

return median;
}
