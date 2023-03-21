#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n^2) where n is the number of elements in v
Space Complexity: O(1)
Technique Used: Just regular solving
*/

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
// The optimal approach using hashing took me 30 minutes