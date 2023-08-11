#include <bits/stdc++.h>
using namespace std;

//Given a list of coin denominations and a target sum, return the number of possible ways to 
//make change for that sum.

//Time Complexity: O(N * C), where N is the target value and C is the number of coins

int coinChange(int coins[], int num_coins, int target_sum) {
    if (target_sum == 0) {
        return 1;
    }
    if (target_sum < 0) {
        return 0;
    }
    if (num_coins <= 0) {
        return 0;
    }
    return coinChange(coins, num_coins - 1, target_sum) + coinChange(coins, num_coins, target_sum - coins[num_coins - 1]);
}

int main() {
    int coins[] = {2, 5, 10};
    int length = sizeof(coins) / sizeof(coins[0]);
    int target_sum = 20;
    cout << " " << coinChange(coins, length, target_sum);
    target_sum = 15;
    cout << " " << coinChange(coins, length, target_sum);
}
