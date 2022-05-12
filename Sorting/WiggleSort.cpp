#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> sorted(n);

        int end = n - 1;
        int start = end / 2;
        ;

        int i = 0;
        while (i < n)
        {
            sorted[i++] = nums[start--];
            if (i < n)
            {
                sorted[i++] = nums[end--];
            }
        }

        nums = sorted;
    }
};