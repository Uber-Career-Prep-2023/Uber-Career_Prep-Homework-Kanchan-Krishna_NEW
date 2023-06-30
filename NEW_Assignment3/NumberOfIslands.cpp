// Given a binary matrix in which 1s represent land and 0s represent water. Return the number of islands (contiguous 1s surrounded by 0s or the edge of the matrix).

/*
Time Complexity: O(M*N)
Space Complexity: O(1) only storing the number of islands?
Time Taken: 30 min
Technique Used: BFS
*/

#include <bits/stdc++.h>
using namespace std; 
void bfs(int i, int j, vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid.at(0).size();
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != '1') {
            continue;
        }
        grid[x][y] = '0';
        for (auto &dir : directions) {
            q.push({x + dir.first, y + dir.second});
        }
    }
}

int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid.at(0).size();
    int num_islands = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                num_islands++;
                bfs(i, j, grid);
            }
        }
    }
    return num_islands;
}

int main() {
    vector<vector<char>> graph = {{'1', '0', '1', '1', '1'}, {'1', '1', '0', '1', '1'}, {'0', '1', '0', '0', '0'}, {'0', '0', '0', '1', '0'}, {'0', '0', '0', '0', '0'}};
    cout << numIslands(graph) << endl;
    vector<vector<int>> graph2 = {{1, 1, 1}};
    cout << numIslands(graph) << endl;
}