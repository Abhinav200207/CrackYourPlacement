#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(map<int, vector<int>> mp, set<int> v, int a, vector<int> ans)
    {
        if (v.find(a) != v.end()) return;
        ans.push_back(a);
        v.insert(a);
        for (auto i:mp[a]) dfs(mp,v,i,ans);
    }

public:
    vector<int> restoreArray(vector<vector<int>> &arr)
    {
        map<int, vector<int>> mp;
        for (auto i : arr)
        {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        int head;
        for (auto i : mp)
        {
            if (i.second.size() == 1)
                head = i.first;
        }
        set<int> s;
        vector<int> ans;

        return ans;
    }
};