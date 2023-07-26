#include <bits/stdc++.h>
using namespace std; 

//You will be given a stream of numbers, one by one. After each new number, 
//return the median of the numbers so far.

int findMiddleNum(priority_queue<int, vector<int>, greater<int>>& min_heap) {
    int size = min_heap.size(); 
    int mid = size / 2; 
    int i = 0;
    while (i < mid) {
        min_heap.pop();
        i++;
    }
    return min_heap.front();
}

int runningMedian(vector<int>& nums, int start, int end) {
    //constantly sort in ascending order -> maintain a minimum heap
    priority_queue<int, vector<int>, greater<int>> min_heap; 
    for (int i = start; i <= end; i++) {
        pq.push(nums[i]);
    }
    return findMiddleNum(min_heap)
}

int main() {
    vector<int> test = {1, 11, 4, 15, 12};
    int start = 0; 
    int end = -1; 
    for (int i = 0; i < test.size(); i++) {
        end = i;
        cout << "Running median thus far: " << runningMedian(test, start, end);
    }
}
