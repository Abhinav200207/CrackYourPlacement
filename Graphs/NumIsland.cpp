#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void fun(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0' || grid[i][j] == '2')
        {
            return;
        }
        grid[i][j] = '2';
        fun(grid, i - 1, j);
        fun(grid, i + 1, j);
        fun(grid, i, j - 1);
        fun(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    fun(grid, i, j);
                }
            }
        }
        return count;
    }
};