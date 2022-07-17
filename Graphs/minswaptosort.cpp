#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &nums, vector<bool> &vis, int &cnt, int i, vector<pair<int, int>> &v)
{
    vis[i] = true;
    cnt++;
    if (vis[v[i].second])
    {
        return;
    }
    else
    {
        dfs(nums, vis, cnt, v[i].second, v);
    }
}

int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = make_pair(nums[i], i);
    }
    int ans = 0;
    sort(v.begin(), v.end());
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int cnt = 0;
            dfs(nums, vis, cnt, i, v);
            ans += (cnt - 1);
        }
    }
    return ans;
}

