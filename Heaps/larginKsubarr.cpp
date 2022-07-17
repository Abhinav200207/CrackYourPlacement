#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.front()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        // cout << dq.front() << " ";
        ans.push_back(arr[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.front()])
        {
            dq.pop_front();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
}