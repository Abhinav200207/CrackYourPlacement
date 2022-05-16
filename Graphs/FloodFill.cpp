#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void fun(vector<vector<int>> &grid, int i, int j, int newColor, int oldColor)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == newColor || grid[i][j] != oldColor)
        {
            return;
        }
        grid[i][j] = newColor;
        fun(grid, i - 1, j,newColor, oldColor);
        fun(grid, i + 1, j,newColor, oldColor);
        fun(grid, i, j - 1,newColor, oldColor);
        fun(grid, i, j + 1,newColor, oldColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &grid, int sr, int sc, int newColor)
    {
        fun(grid,sr,sc,newColor,grid[sr][sc]);
        return grid;
    }
};