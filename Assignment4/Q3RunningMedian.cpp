#include <bits/stdc++.h>
using namespace std; 

//You will be given a stream of numbers, one by one. After each new number, 
//return the median of the numbers so far.

//brute force: sort the elements then find the median

int main() {
    vector<int> test = {1, 11, 4, 15, 12};
    int start = 0; 
    int end = -1; 
    for (int i = 0; i < test.size(); i++) {
        end = i;
        cout << "Running median thus far: " << runningMedian(test, start, end);
    }
}
