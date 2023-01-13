#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> v(n + 1);
    for (long long int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long int ans = 1;
    for (long long int i = 1; i <= n; i++)
    {
        if (ans < v[i])
        {
            break;
        }
        else
        {
            ans += v[i];
        }
    }
    cout << ans << endl;
}
