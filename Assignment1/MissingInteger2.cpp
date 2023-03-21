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
int missingInteger(vector<int> arr, int &n)
{
    int left_ptr = 1;
    int right_ptr = arr.size() - 1;
    for (int i = 1; i <= arr.size(); i++)
    {
        int middle_idx = (left_ptr + right_ptr) / 2;
        if (middle_idx == i)
        {               // no missing integer yet
            left_ptr++; // not sure
        }
        else if (middle_idx > i)
        {
            left = mid - 1;
        }
        else if (middle_idx < i)
        {
            right = mid + 1;
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
    std::cout << "Hello World!\n";
}

// This question took me 15 min for the first approach (optimized) and 5 min for the second approach