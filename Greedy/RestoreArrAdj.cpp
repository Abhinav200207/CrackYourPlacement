#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, pair<int, vector<int>>> mp;
    vector<int> startend;
    vector<int> ans;
    vector<int> restoreArray(vector<vector<int>> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i][0]].first++;
            mp[arr[i][0]].second.push_back(i);
            mp[arr[i][1]].first++;
            mp[arr[i][1]].second.push_back(i);
        }
        for (auto i : mp)
        {
            if (i.second.first == 1)
            {
                startend.push_back(i.first);
            }
        }
        int j = 0;
        ans.push_back(startend[0]);
        ans.push_back(arr[mp[startend[0]].second[0]][0] == ans[0] ? arr[mp[startend[0]].second[0]][1] : arr[mp[startend[0]].second[0]][0]);
        mp[startend[0]].first--;
        while (j <= arr.size() + 1)
        {
            j++;
            ans.push_back(arr[mp[j].second[mp[j].first]][0] == ans[j - 1] ? arr[mp[j].second[0]][1] : arr[mp[j].second[0]][0]);
            mp[j].first--;
        }
    }
};