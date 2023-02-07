#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(i);
    }

    long long int sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    sum = sum / 2;

    vector<vector<long long int>> dp(n + 1, vector<long long int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - ans[i - 1] >= 0)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - ans[i - 1]]) % (1000000007);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[n][sum] * 500000004)%(1000000007);
}