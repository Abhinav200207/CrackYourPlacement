#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> prev(vector<int> &h)
    {
        vector<int> p;
        stack<int> st;
        for (int i = 0; i < h.size(); i++)
        {

            while (!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                p.push_back(-1);
            }
            else
            {
                p.push_back(st.top());
            }
            st.push(i);
        }
        return p;
    }
    vector<int> next(vector<int> &h)
    {
        vector<int> p;
        stack<int> st;
        for (int i = h.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                p.push_back(h.size());
            }
            else
            {
                p.push_back(st.top());
            }
            st.push(i);
        }
        reverse(p.begin(), p.end());
        return p;
    }

public:
    int largestRectangleArea(vector<int> heights)
    {
        vector<int> p = prev(heights);
        vector<int> n = next(heights);
        int area = INT_MIN;
        for (int i = 0; i < p.size(); i++)
        {
            area = max(area,(n[i] - p[i] - 1)*heights[i]);
        }
        return area;
    }
};