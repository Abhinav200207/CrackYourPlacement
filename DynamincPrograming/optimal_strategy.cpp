#include <bits/stdc++.h>
using namespace std;

long long int dp[5005][5005];

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (long long int len = 1; len <= n; len++)
    {
        for (long long int i = 0; i <= n - len; i++)
        {
            long long int j = i + len - 1;
            if (i == j)
            {
                dp[i][j] = v[i];
            }
            else
            {
                dp[i][j] = max(
                    v[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                    v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
    }
    cout << dp[0][n - 1];
}
