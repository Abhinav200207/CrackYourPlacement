#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int fun(vector<vector<int>> &grid, int x, int y, int n, int m, vector<vector<int>> mp)
    {
        if (x >= n || y >= m)
        {
            return INT_MAX;
        }
        if (mp[x][y] != -1)
        {
            return mp[x][y];
        }
        if (x == n - 1 && y == m - 1)
        {
            return grid[x][y];
        }
        return mp[x][y] = grid[x][y] + min(fun(grid, x + 1, y, n, m, mp), fun(grid, x, y + 1, n, m, mp));
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        return fun(grid, 0, 0, grid.size(), grid[0].size(), dp);
    }
};