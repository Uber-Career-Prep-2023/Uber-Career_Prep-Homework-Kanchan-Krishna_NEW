#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

/*
Technique: Hashing/Hashmap 
Time Complexity: O(n) where n is the # of elements in the arr
Space Complexity: O(n) for map where n is # of elements in the arr
*/

int twoSum(vector<int>& arr, int& k) {
  int count = 0; 
  map<int, int> freq_map; 
  map<int, int>::iterator itr; 
  for (size_t i = 0; i < arr.size(); i++) {
    int complement = k - arr[i];
    itr = freq_map.find(complement);
    if (itr != freq_map.end()) {
      count += itr->second; 
    }
    freq_map[arr[i]]++; 
  }
  return count; 
}

int main() {
  /*vector<int> v = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
  int k = 10;*/
  //int k = 9; 
  vector<int> v = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
  int k = 6; 
  //int k = 1;
  cout << "number of pairs: " << twoSum(v, k) << endl; 
}

/*
This question took me 15 minutes 
*/