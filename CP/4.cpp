#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &mC)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0] = grid[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    dp[i][j] = min(dp[i][j], mC[grid[i - 1][k]][j] + dp[i - 1][k]);
                }
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};