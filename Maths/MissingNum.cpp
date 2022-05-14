#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> nums)
    {
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) == nums.size())
            {
                temp = 1;
                continue;
            }
            if (nums[i] == -(nums.size() + 1))
            {
                nums[0] = -nums[0];
                continue;
            }
            if (nums[abs(nums[i])] == 0)
            {
                nums[abs(nums[i])] = -(nums.size() + 1);
                continue;
            }
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        if (temp == 0)
        {
            return nums.size();
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    obj.missingNumber({3, 0, 1});
}