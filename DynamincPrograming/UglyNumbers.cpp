#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        dp[3] = 4;
        dp[4] = 5;
        int i = 0;
        while (true)
        {
            // int dp[i + 1] = dp[i] * 2;
            // int dp[i + 2] = dp[i] * 3;
            // int dp[i] = dp[i] * 5;
            // i++;
        }
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

typedef unsigned long long int ll;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<ll> ans;
        ans.push_back(1);

        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;

        for (int i = 1; i < n; i++)
        {
            int next = min(
                ans[idx2] * 2,
                min(
                    ans[idx3] * 3,
                    ans[idx5] * 5));

            ans.push_back(next);
            if (next % 2 == 0)
                idx2++;
            if (next % 3 == 0)
                idx3++;
            if (next % 5 == 0)
                idx5++;
        }
        return ans[n - 1];
    }
};

// n = 10;
// 