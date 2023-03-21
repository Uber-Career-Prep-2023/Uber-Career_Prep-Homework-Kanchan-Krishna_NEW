#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Technique: Sort then solve
Time Complexity: O(n log n) where n is the # of elements in the arr
Space Complexity: O(1) if we do not count the output
*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 1)
    {
        return intervals;
    }
    vector<vector<int>> merged_intervals;
    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
         { return a[0] < b[0]; });
    int i = 0;
    while (i < intervals.size() - 1)
    {
        // overlap
        if (intervals[i][1] >= intervals[i + 1][0])
        {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
        }
        // no overlap - if back of first vector < front of second vector
        else
        {
            merged_intervals.push_back(intervals[i]);
        }
        i++;
    }
    merged_intervals.push_back(intervals[i]);
    return merged_intervals;
}
// wrong - does not pass the middle test case
// the key to this problem is the modification of v in place; do not create mini vectors to pushback to the final output; otherwise, the starting point of the intervals will not be retained in the case that there is overlap among all the intervals
/*vector<vector<int>> mergeIntervals(vector<vector<int>>& v) {
  if (v.size() <= 1) {
    return v;
  }
  sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    return a[0] < b[0];
   });

  vector<vector<int>> res;
  for (int i = 0; i < v.size() - 1; i++) {
    vector<int> curr_interval = v[i];
    if (curr_interval[1] < v[i + 1][0]) { //end time < start
      res.push_back(curr_interval);
    } else {
      vector<int> new_interval;
      new_interval.push_back(curr_interval[0]);
      new_interval.push_back(max(curr_interval[1], v[i + 1][1]));
      res.push_back(new_interval);
      i++; //skip the next interval because you already covered it in the overlap
    }
  }
  res.push_back(v[v.size() - 1]);
  return res;
}*/

int main()
{
    vector<vector<int>> intervals;
    /*intervals.push_back({2, 3});
    intervals.push_back({4, 8});
    intervals.push_back({1, 2});
    intervals.push_back({5, 7});
    intervals.push_back({9, 12});*/
    intervals.push_back({5, 8});
    intervals.push_back({6, 10});
    intervals.push_back({2, 4});
    intervals.push_back({3, 6});
    /*intervals.push_back({10, 12});
    intervals.push_back({5, 6});
    intervals.push_back({7, 9});
    intervals.push_back({1, 3});*/
    vector<vector<int>> merged = mergeIntervals(intervals);
    for (int i = 0; i < merged.size(); i++)
    {
        for (int j = 0; j < merged[i].size(); j++)
        {
            cout << merged[i][j] << " ";
        }
        cout << "" << endl;
    }
}

// This question took me 30 minutes. I did it the wrong way first, then took me some time to figure out the issue and its solution