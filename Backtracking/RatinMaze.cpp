#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    void solve(vector<vector<int>> &m, int i, int j, int n, vector<vector<bool>> &vis, string s)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || m[i][j] == 0)
            return;

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            s = "";
            return;
        }

        vis[i][j] = true;
        solve(m, i + 1, j, n, vis, s + 'D');
        solve(m, i, j - 1, n, vis, s + 'L');
        solve(m, i, j + 1, n, vis, s + 'R');
        solve(m, i - 1, j, n, vis, s + 'U');
        vis[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        solve(m, 0, 0, n, vis, "");
        if (ans.size() != 0)
            return ans;
        return {"-1"};
    }
};

int main()
{
}