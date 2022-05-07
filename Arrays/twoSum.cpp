#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> nums, int target)
    {
        map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[nums[i]]);
                break;
            }
            mp[target - nums[i]] = i;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> v;
    v = obj.twoSum({3,2,4},6);
    cout << v[0] << " " << v[1];
}