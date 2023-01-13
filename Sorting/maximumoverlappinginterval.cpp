#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    int curr = v[0].second;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (curr <= v[i].first)
        {
            curr = v[i].second;
            cnt++;
        }
        else
        {
            curr = min(curr, v[i].second);
        }
    }
    cout << cnt << endl;
}
