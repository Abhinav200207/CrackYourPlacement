#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void gridTraversal(vector<vector<char>> &grid, int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        gridTraversal(grid,i - 1,j,n,m);
        gridTraversal(grid,i,j - 1,n,m);
        gridTraversal(grid,i + 1,j,n,m);
        gridTraversal(grid,i,j + 1,n,m);
        gridTraversal(grid,i + 1,j + 1,n,m);
        gridTraversal(grid,i - 1,j - 1,n,m);
        gridTraversal(grid,i - 1,j + 1,n,m);
        gridTraversal(grid,i + 1,j - 1,n,m);

    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    gridTraversal(grid, i, j, grid.size(), grid[0].size());
                }
            }
        }
    }
};