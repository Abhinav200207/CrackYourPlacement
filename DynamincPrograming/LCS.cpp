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
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        printtwovector(dp);
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    cout << sol.longestCommonSubstr("ABC", "ACB", 3, 3);
}

// 6 6
// ABCDGH
// ACDGHR