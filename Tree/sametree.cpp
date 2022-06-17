#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int fun(TreeNode *p, TreeNode *q)
    {
        if (p == q)
        {
            if (p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL)
            {
                return 1;
            }
            return fun(p->right, p->right) && fun(p->left, q->left);
        }
        else
        {
            return false;
        }
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return fun(p, q);
    }
};