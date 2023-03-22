#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Technique: Sort then solve
Time Complexity:
Space Complexity:
*/
// cant you also check if the index (1-based) does not match up with the value of the element at the index? if it does not, you know you are missing an integer and you should return the current index
// for ex: [1, 2, 3, 4, 6, 7] has corresponding indices 1, 2, 3, 4, 5, 6 and there is a mismatch at index 5 so return 5
// this would be O(n) though; does not surpass binary search
int missingInteger(vector<int> arr, int &n) {
    int left = 0, int right = arr.size() - 1;
    // n=3, arr=[1,2] : handle upfront
    while(left<right){
        mid = (left+right)/2;
        if (arr[mid]==mid+1){ //everything from left to mid is correct 
            left=mid+1;
        }else{
            right=mid;
        }
    }
}
/*
Technique: Sort then solve
Time Complexity: O(n) where n is the # of eles in arr
Space Complexity: O(1)
*/
// old way
/*int findMissingInteger(vector<int>& arr, int& n) {
  if (arr.size() == 1) {
    return 1 + arr[0];
  }
  int res = 0;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] - arr[i - 1] > 1) {
      res = ((arr[i] + arr[i - 1]) / 2);
    }
  }
  return res;
}*/

int main()
{
    vector<int> input{1, 2, 3, 4, 6, 7};
    cout << MissingInteger(input, 7) << endl;
    
    input = {1};
    cout << MissingInteger(input, 2) << endl;
    
    input = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    cout << MissingInteger(input, 12) << endl;
    
    input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << MissingInteger(input, 12) << endl;
}

// This question took me 15 min for the first approach (optimized) and 5 min for the second approach
