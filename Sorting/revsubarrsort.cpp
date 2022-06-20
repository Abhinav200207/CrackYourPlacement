#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int n)
{
    int cnt = 0;
    int x = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            x++;
        }
        if (nums[i] >= nums[i - 1] && x > 0)
        {
            if (i - x - 2 > 0 && nums[i] < nums[i - x - 2])
            {
                return 0;
            }
            cnt++;
            x = 0;
        }
    }
    if ((cnt == 1 && x == 0) || (cnt == 0 && x != 0) || (cnt == 0 && x == 0))
    {
        return 1;
    }
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
}