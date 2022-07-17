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
public:
    int maxdepth(Node *root)
    {
        if (root == NULL)
            return 0;
        int h = 0;
        for (auto child : root->children)
            h = max(h, maxdepth(child));
        return 1 + h;
    }
};