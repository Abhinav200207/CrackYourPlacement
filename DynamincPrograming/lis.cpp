#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp;
    dp.push_back(v[0]);
    for (int i = 0; i < n; i++)
    {
        if (dp.back() < v[i])
        {
            dp.push_back(v[i]);
        }
        else
        {
            int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            dp[idx] = v[i];
        }
    }
    cout << dp.size() << endl;
    return 0;
}
