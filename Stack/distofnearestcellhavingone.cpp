#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void printtwovector(vector<vector<int>> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    int dfs(int i, int j, vector<vector<int>> vis, vector<vector<int>> grid, int n, int m, int dist)
    {
        // cout << "now " << i << " " << j << " \n";
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1)
        {
            return INT_MAX;
        }
        if (grid[i][j] == 1)
        {
            return dist;
        }
        vis[i][j] = 1;
        int ans = min(
            min(dfs(i + 1, j, vis, grid, n, m, dist + 1),
                dfs(i - 1, j, vis, grid, n, m, dist + 1)),
            min(dfs(i, j + 1, vis, grid, n, m, dist + 1),
                dfs(i, j - 1, vis, grid, n, m, dist + 1)));
        vis[i][j] = 0;
        return ans;
    }

public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                ans[i][j] = dfs(i, j, vis, grid, n, m, 0);
            }
        }
        printtwovector(ans);
        return ans;
    }

    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if ((i + 1) < n && ans[i][j] + 1 < ans[i + 1][j])
            {
                ans[i + 1][j] = ans[i][j] + 1;
                q.push({i + 1, j});
            }
            if ((i - 1) >= 0 && ans[i][j] + 1 < ans[i - 1][j])
            {
                ans[i - 1][j] = ans[i][j] + 1;
                q.push({i - 1, j});
            }
            if ((j + 1) < m && ans[i][j] + 1 < ans[i][j + 1])
            {
                ans[i][j + 1] = ans[i][j] + 1;
                q.push({i, j + 1});
            }
            if ((j - 1) >= 0 && ans[i][j] + 1 < ans[i][j - 1])
            {
                ans[i][j - 1] = ans[i][j] + 1;
                q.push({i, j - 1});
            }
        }
        return ans;
    }
};

int main()
{
    Solution solver;
    solver.nearest({{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}});
}