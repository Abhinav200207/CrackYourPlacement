#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
    int ans = 0;
    int height(Node *root)
    {
        if (!root)
            return 0;
        int maxheight = INT_MIN;
        vector<int> childrenHeight;
        for (auto i : root->children)
        {
            int x = height(i);
            childrenHeight.push_back(i->val);
            if (x >= maxheight)
            {
                maxheight = x;
            }
        }
        sort(begin(childrenHeight), end(childrenHeight));
        ans = max(ans, childrenHeight[childrenHeight.size() - 1] + childrenHeight[childrenHeight.size() - 2]);
        return 1 + maxheight;
    }

public:
    vector<int> dia(Node *root)
    {
    }
};