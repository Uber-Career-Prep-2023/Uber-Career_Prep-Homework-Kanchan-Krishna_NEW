#include <bits/stdc++.h>
using namespace std; 

//Given a square matrix of 0s and 1s, find the dimension of the largest square consisting only of 1s.
int largestSquaresOf1(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int side_length = 0, pre;
    vector<int> dp(cols);
    for(int i = 0;i < rows; i++) {
        for(int j = 0;j < cols; j++) {
            int temp = dp[j];
            if (i==0 || j==0 || matrix[i][j]=='0') {
                dp[j] = matrix[i][j]-'0';
            }
            else {
                dp[j] = min({dp[j], dp[j-1], pre}) + 1;
            }
            side_length = max(side_length, dp[j]);
            pre = temp;
        }
    }
    return side_length;
}

int main() {
    vector<vector<char>> matrix = {{'0', '1', '0', '1'}, {'0', '0', '1', '1'}, {'0', '1', '1', '1'}, {'0', '0', '1', '1'}};
    int res = largestSquaresOf1(matrix);
    cout << res << endl;
}