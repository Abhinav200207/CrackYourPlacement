#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void colourize(vector<vector<int>> &grid, int n, int i, int j, vector<vector<int>> &vis, int x)
    {
        if (i < 0 || j < 0 || j >= n || i >= n || grid[i][j] == 0 || vis[i][j] == 1)
            return;
        grid[i][j] = x;
        vis[i][j] = 1;
        colourize(grid, n, i + 1, j, vis, x);
        colourize(grid, n, i, j + 1, vis, x);
        colourize(grid, n, i - 1, j, vis, x);
        colourize(grid, n, i, j - 1, vis, x);
        return;
    }

    int dis(vector<vector<int>> &grid, int n, int i, int j, vector<vector<int>> &vis, int x, int val)
    {
        if (i < 0 || j < 0 || j >= n || i >= n || vis[i][j] == 1 || (grid[i][j] != 0 && grid[i][j] != val))
            return x;
        x++;
        vis[i][j] = 1;
        int ans1 = dis(grid, n, i + 1, j, vis, x, val);
        int ans2 = dis(grid, n, i, j + 1, vis, x, val);
        int ans3 = dis(grid, n, i - 1, j, vis, x, val);
        int ans4 = dis(grid, n, i, j - 1, vis, x, val);
        vis[i][j] = 0;
        return min(max(ans1, ans2), max(ans3, ans4));
    }

    void viszero(vector<vector<int>> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                v[i][j] = 0;
            }
        }
    }

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

public:
    void shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int x = 1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] != 0)
                {
                    colourize(grid, n, i, j, vis, x);
                    x++;
                }
            }
        }
        int ans = INT_MAX;
        viszero(vis);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    ans = min(ans, dis(grid, n, i, j, vis, 0, grid[i][j]));
                }
            }
        }
        cout << ans << endl;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> v{{1, 0}, {0, 1}};
    obj.shortestBridge(v);
}