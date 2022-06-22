#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int n)
{
    int cnt = 0;
    bool flag = false;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= nums[i - 1])
        {
            flag = false;
        }
        if (nums[i] < nums[i - 1] && !flag)
        {
            cnt++;
            flag = true;
        }
    }
    cout << cnt << endl;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << solve(v, n);
}