#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    vector<int> a(m);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    int h = 0, l = 0, cnt = 0;
    while (h < n)
    {
        while (l < m && a[l] < p[h] - k)
            l++;
        if (abs(a[l] - p[h]) <= k)
            cnt++, l++, h++;
        else
                h++;
    }
    cout << cnt;
}