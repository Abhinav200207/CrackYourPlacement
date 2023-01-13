#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int s = 0, e = n - 1, cnt = 0;
    while (s <= e)
    {
        if (v[s] + v[e] <= k)
            s++;
        e--;
        cnt++;
    }
    cout << cnt << endl;
}
