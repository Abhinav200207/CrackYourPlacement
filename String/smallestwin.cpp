#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        map<char, int> mp;
        for (auto i : p)
        {
            mp[i]++;
        }
        string ans = "";
        int len = INT_MAX;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                int cnt = 0;
                string tempS = "";
                map<char, int> temp = mp;
                for (int j = i; j < s.length(); j++)
                {
                    cnt++;
                    tempS += s[j];
                    if (temp.find(s[j]) != temp.end())
                    {
                        temp[s[j]]--;
                    }
                    if (temp[s[j]] == 0)
                    {
                        temp.erase(s[j]);
                    }
                    if (temp.size() == 0)
                    {
                        break;
                    }
                }
                if (temp.size() == 0 && cnt < len)
                {
                    len = cnt;
                    ans = tempS;
                }
            }
        }
        cout << len << endl;
        return len == INT_MAX ? "-1" : ans;
    }
};

int main()
{
    Solution solve;
    cout << solve.smallestWindow("zoomlazapzo","oza");
}