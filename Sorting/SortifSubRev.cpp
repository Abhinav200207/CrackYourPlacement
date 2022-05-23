// Check if reversing a sub array make the array sorted
#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> v, int n)
{
    int cnt = 1; // 2
    int diff = v[1] - v[0];
    int cnt = 0;
    int index = 1;
    for (int i = 1; i < n; i++)
    {
        diff = v[i] - v[i - 1];
        if (diff < 0)
        {
            cnt++;
            break;
        }
        index++;
    }
}
// index = 4
// {1, 2, 2, 5, 5, 4, 4, 3}