#include <bits/stdc++.h>
using namespace std; 

//You will be given a stream of numbers, one by one. After each new number, 
//return the median of the numbers so far.

//brute force: sort the elements then find the median
/* alternate solution: first half is max heap, second half is min heap
(difference between the two sizes should always be 1 to ensure you have a median)
*/

//Time Complexity: O(log n)
//Space Complexity: O(n)

class FindMedian {
    public:
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        FindMedian() {

        }
        void addNum(int num) {
            if(max_heap.size() == 0 || max_heap.top() >= num) {
                max_heap.push(num);
            }
            else {
                min_heap.push(num);
            }
            resizeHeaps();
        }
        void resizeHeaps() { //send the elements off to the other queue to maintain size diff of 1
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            } else if (min_heap.size() > max_heap.size() + 1) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        double findMedian() {
            if (max_heap.size() > min_heap.size()) {
                return max_heap.top();
            }
            else if(min_heap.size() > max_heap.size()) {
                return min_heap.top();
            }
            else { //even number of integers
                return (max_heap.top() + min_heap.top()) / 2.0;
            } 
        }
};

int main() {
    FindMedian fm;
    fm.addNum(1);
    cout << "Median: " << fm.findMedian() << endl; 
    fm.addNum(11);
    cout << "Median: " << fm.findMedian() << endl; 
    fm.addNum(4);
    cout << "Median: " << fm.findMedian() << endl; 
    fm.addNum(15);
    cout << "Median: " << fm.findMedian() << endl; 
    fm.addNum(12);
    cout << "Median: " << fm.findMedian() << endl; 
}
