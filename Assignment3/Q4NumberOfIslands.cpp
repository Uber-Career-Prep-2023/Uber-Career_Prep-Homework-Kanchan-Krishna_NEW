// BFS Solution
// TC: O(M*N) & SC:O(min(M, N)) bc if all lands then queue size will grow up to min(M, N)
#include <bits/stdc++.h>
class Solution
{
private:
    void bfs(int i, int j, vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid.at(0).size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != '1')
            {
                continue;
            }
            grid[x][y] = '0';
            for (auto &dir : directions)
            {
                q.push({x + dir.first, y + dir.second});
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid.at(0).size();
        int num_islands = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    bfs(i, j, grid);
                }
            }
        }
        return num_islands;
    }
};