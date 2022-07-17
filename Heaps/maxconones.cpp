#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int cnt = 0, ans = INT_MIN;
    for (j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 0)
        {
            cnt++;
        }
        while (cnt > k)
        {
            if (nums[i] == 0){
                cnt--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}