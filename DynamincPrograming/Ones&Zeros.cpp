#include <bits/stdc++.h>
using namespace std;


int findMaxForm(vector<string> strs, int m, int n)
{
    vector<vector<int>> dp(m + 1,vector<int> (n + 1,0));
    for (string s : strs)
    {
        vector<int> count = countZO(s);
        for (int i = m; i >= count[0]; i--)
            for (int j = n; j >= count[1]; j--)
                dp[i][j] = max(1 + dp[i - count[0]][j - count[1]], dp[i][j]);
    }
    return dp[m][n];
}


vector<int> countZO(string str)
{
    vector<int> res(2);
    for (int i = 0; i < str.length(); i++)
        res[str[i] - '0']++;
    return res;
}