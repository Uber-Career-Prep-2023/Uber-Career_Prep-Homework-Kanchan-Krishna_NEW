#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n^2) where n is the number of elements in v
Space Complexity: O(1)
Technique Used: Just regular solving
*/

//optimized
/*
[8, -5, 0, -2, 3, -4]
0 8 3 3 1 4 0 -> make sure to count both pairs (2 lefts and when you have 1 right (value 3)) 
Sum of subarray[l,r] = prefix_sum[r]-prefix_sum[l-1] (0<=l<=r<n)
A subarray [l,r] has sum 0 if prefix_sum[r]==prefix_sum[l-1]
*/

int zeroSumSubArray(vector<int> &v) {
    //generate the prefix sum arr
    vector<int> prefix_sum(v.size() + 1); 
    prefix_sum.push_back(0); 
    int running_sum = 0; 
    for (int i = 0; i < v.size(); i++) {
        running_sum += v[i]; 
        prefix_sum.push_back(running_sum); 
    }
    map<int, int> m; 
    for (auto ele : prefix_sum) {
        m[ele]++; 
    }
    int count = 0; 
    for (auto entry : m) {
        if (m.find(entry.first)) != m.end()) { //means you have seen this prefix sum before 
            count+= entry.second;
        }
    }
    return count; 
}

// brute force solution
int zeroSumSubArray(vector<int> &v)
{
    vector<vector<int>> zero_sum_pairs;
    for (int i = 0; i < v.size(); i++)
    {
        int running_sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            running_sum += v[j];
            if (running_sum == 0)
            {
                zero_sum_pairs.push_back({i, j});
            }
        }
    }
    return zero_sum_pairs.size();
}

int main()
{
    // vector<int> v = {4, 5, 2, -1, -3, -3, 4, 6, -7};
    // vector<int> v = {1, 8, 7, 3, 11, 9};
    vector<int> v = {8, -5, 0, -2, 3, -4};
    cout << "num of zero sum pairs: " << zeroSumSubArray(v);
}

// The brute force approach took me 10 minutes
