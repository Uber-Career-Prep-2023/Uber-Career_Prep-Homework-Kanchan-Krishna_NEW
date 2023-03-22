#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(n)
Technique: Regular traversing of vector
*/

double maxMeanSubArray(vector<int>& v, int& k){
    double max_mean = 0;
    int max_sum = 0;
    if (v.size() < k){
      return 0;
    }
    for (int i = 0; i < k; i++){
      max_sum += v[i];
    }
    for (int j = 1; j < vec.size() - k - 1; j++){
      if (max_sum < max_sum - vec[j - 1] + vec[j + (k - 1)]){
        max_sum = max_sum - vec[j - 1] + vec[j + ( k - 1)];
      }
    }
    max_mean = (double) max_sum / k;
    return max_mean;
}

int main(){
  vector <int> test = {4, 5, -3, 2, 6, 1};
  int k = 2;
  cout << maxMeanSubArray(test, k) << endl;
}

//This question took me 35 minutes 
