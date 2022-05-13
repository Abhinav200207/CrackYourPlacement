#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> nums)
    {
        int maxnum = 1;
        int ans = *max_element(nums.begin(), nums.end());
        int minnum = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0){
                maxnum = 1;
                minnum = 1;
            }
            int temp = maxnum*nums[i];
            maxnum = max(nums[i]*maxnum,nums[i]*minnum);
            minnum = min(nums[i]*minnum,temp);
            ans = max(maxnum,ans);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.maxProduct({-2, 0, -1});
}