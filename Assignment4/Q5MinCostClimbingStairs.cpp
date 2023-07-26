#include <bits/stdc++.h>
using namespace std; 

/*
A staircase on a hiking trail implements a rather unusual toll system to cover trail maintenance costs. 
Each stair in the staircase has a different toll which you only have to pay if you step on that 
stair. Due to the height of the stairs, you can only climb one or two stairs at once. This means 
that from the ground you must initially step on either stair 0 or stair 1 and that, if there are 
n stairs, the last stair you step on can be either stair n-1 or n-2. Given an array representing 
the costs per stair, what is the minimum possible toll you can pay to climb the staircase?
*/

int minCostClimbingStairs(vector<int>& stair_cost) {
    stair_cost.push_back(0);
    for (int i = stair_cost.size() - 3; i >= 0; i--) {
        stair_cost.at(i) += min(stair_cost.at(i + 1), stair_cost.at(i + 2));
    }
    return min(stair_cost.at(0), stair_cost.at(1));
}

int main() {
    vector<int> stair_cost = {4, 1, 6, 3, 5, 8};
    cout << "Min Cost: " << minCostClimbingStairs(stair_cost) << endl;
    stair_cost = {11, 8, 3, 4, 9, 13, 10};
    cout << "Min Cost: " << minCostClimbingStairs(stair_cost) << endl;
}