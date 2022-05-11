#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int area = (end - start)*(min(height[start], height[end]));
        while (start < end)
        {
            if (height[start] < height[end])
            {
                start++;
                area = max(area,(end - start)*(min(height[start], height[end])));
            }
            else
            {
                end--;
                area = max(area,(end - start)*(min(height[start], height[end])));
            }
        }
        return area;
    }
};