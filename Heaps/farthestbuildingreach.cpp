#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int> pq;
        for (int i = 0; i < heights.size(); i++)
        {
            int diff = (heights[i + 1] - heights[i]);
            if (diff > 0)
            {
                pq.push(diff);
            }
            if (pq.size() > ladders)
            {
                bricks = bricks - pq.top();
                pq.pop();
            }
            if (bricks < 0)
            {
                return i;
            }
        }
        return heights.size() - 1;
    }
};