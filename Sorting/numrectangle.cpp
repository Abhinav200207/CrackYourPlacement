#include <bits/stdc++.h>
using namespace std;

int next(vector<pair<int,int>> arr, int target, int end)
{
    int start = 0;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid].first < target)
            start = mid + 1;
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        vector<pair<int,int>> v1, v2;
        for (int i = 0; i < rectangles.size(); i++)
        {
            v1.push_back(make_pair(rectangles[i][0],i));
            v2.push_back(make_pair(rectangles[i][1],i));
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<int> ans(points.size(),0);
        for (int i = 0; i < points.size(); i++)
        {
            int temp = v1.size() - next(v1, points[i][0], v1.size());
            
        }
        for (int i = 0; i < points.size(); i++)
        {
            int temp = v2.size() - next(v2, points[i][1], v2.size());
            ans[i] = min(ans[i], temp);
        }
        return ans;
    }
};