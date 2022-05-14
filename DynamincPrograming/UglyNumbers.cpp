#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp;
        dp.push_back(1);
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for (int i = 1; i < n; i++)
        {
            int temp = min(min(dp[index2] * 2, dp[index3] * 3), dp[index5] * 5);
            if (temp == dp[index2] * 2){index2++;}
            if (temp == dp[index3] * 3){index3++;}
            if (temp == dp[index5] * 5){index5++;}
            dp.push_back(temp);
        }
        return dp[n - 1];
    }
};

typedef unsigned long long int ll;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<ll> dp(n + 1, 0);

        dp[0] = 1ll;

        for (int i = 1; i < n; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++)
            {
                if (dp[j] * 2 > dp[i - 1])
                    dp[i] = min(dp[i], dp[j] * 2);
                if (dp[j] * 3 > dp[i - 1])
                    dp[i] = min(dp[i], dp[j] * 3);
                if (dp[j] * 5 > dp[i - 1])
                    dp[i] = min(dp[i], dp[j] * 5);
            }
        }
        return dp[n - 1];
    }
};