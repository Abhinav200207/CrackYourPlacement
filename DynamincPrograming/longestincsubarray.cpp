#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void printvector(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        // [10,9,2,5,3,7,101,18]
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = -1; // -1
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && temp < dp[j])
                {
                    temp = dp[j];
                }
            }
            if (temp == -1)
            {
                dp[i] = 1;
            }
            dp[i] += temp;
        }
        printvector(dp);
        return *max_element(dp.begin(),dp.end());
    }
};