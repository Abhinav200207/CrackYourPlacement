#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        int maxnum = -1;
        for (auto i : mp)
        {
            maxnum = max(maxnum, i.second);
        }
        vector<int> hash(maxnum + 1);
        for (auto i : mp)
        {
            hash[i.second]++;
        }
        int ans = 0;
        for (auto i : mp)
        {
            if (hash[i.second] == 1)
            {
                // pass
            }
            else
            {
                int j = i.second;
                while (hash[j] != 0 && j > 0)
                {
                    ans++;
                    j--;
                }
                hash[i.second]--;
                hash[j]++;
            }
        }
        return ans;
    }
};