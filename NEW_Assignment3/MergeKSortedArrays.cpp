//Given an array of k sorted arrays, merge the k arrays into a single sorted array.

/*
Time Complexity: O(N log k)
Space Complexity: O(N)
Time Taken: 40 min
Technique Used: Priority Queue Heap
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> value_index;

vector<int> mergeKSortedArrays(vector<vector<int>>& v) {
    vector<int> res;
    priority_queue<value_index, vector<value_index>, greater<value_index>> pq;
    for (int i = 0; i < v.size(); i++) {
        pq.push({v[i][0], {i, 0}});
    }
    while (!pq.empty()) {
        value_index curr = pq.top();
        pq.pop();
        int i = curr.second.first;
        int j = curr.second.second;
        res.push_back(curr.first);
        if (j + 1 < v[i].size())
            pq.push({v[i][j + 1], {i, j + 1}});
    }
    return res;
}

int main() {
    vector<vector<int>> v = {{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};
    vector<int> res = mergeKSortedArrays(v);
    for (auto ele : res) {
        cout << ele << " ";
    }
}
