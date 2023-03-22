#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Technique: Sort the array then solve? Array is already sorted when given to us
Time Complexity: O(n^2) where n is the # of elements in the arr
Space Complexity: O(1)
*/

// O(n^2) approach
/*vector<int>& dedupArray(vector<int>& arr) {
  //the array is sorted which tells you if duplicate, the difference should be 0 -> watch out for this
  if (arr.size() <= 1) {
    return arr; //edge case
  }
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] - arr[i - 1] == 0) { //presence of duplicate
      arr.erase(arr.begin() + (i - 1));
      i--;
    }
  }
  return arr;
}*/

/*
Technique: Sort the array then solve? Array is already sorted when given to us
Time Complexity: O(n) where n is the # of elements in the arr
Space Complexity: O(1)
*/
// O(n) approach
vector<int> &dedupArray(vector<int> &arr)
{
    //j is idx of last unique 1element we have encountered; assume we have already processed the first element 
    int j = 0; 
    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i - 1] != arr[i]) { //no duplicate 
        j++; 
        arr[j] = arr[i];
      }
    }
    arr.resize(j); 
    /*int j = 0; // store idx of the next unique element
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] != arr[i])
        {
            arr[j] = arr[i];
            j++;
        }
    }
    cout << "Hello";
    arr[j] = arr[arr.size() - 1];
    j++;*/
}

int main()
{
    // vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    // vector<int> v = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
    vector<int> v = {1, 3, 4, 8, 10, 12};
    v = dedupArray(v);
    for (auto ele : v)
    {
        cout << ele << " " << endl;
    }
}

// This question took me 10 minutes to solve the O(n^2) approach
// Took me 15 minutes to solve the O(n) approach
