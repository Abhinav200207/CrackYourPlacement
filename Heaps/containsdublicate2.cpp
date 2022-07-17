#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, vector<int>> mp;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++)
        {
            // cout << mp[nums[i]].size();
            if (mp[nums[i]].size() == 0)
            {
                mp[nums[i]].push_back(i);
            }
            else if (mp[nums[i]].size() == 1)
            {
                mp[nums[i]].push_back(i);
                if (abs(i - mp[nums[i]][0]) <= k)
                {
                    flag = true;
                }
            }
            else
            {
                mp[nums[i]][0] = mp[nums[i]][1];
                mp[nums[i]][1] = i;
                if (abs(i - mp[nums[i]][0]) <= k)
                {
                    flag = true;
                }
            }
        }
        return flag;
    }
};
