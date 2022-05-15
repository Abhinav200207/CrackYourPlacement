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
    bool checking(TreeNode *l, TreeNode *r)
    {
        if ((l == NULL and r != NULL) or (l != NULL and r == NULL))
            return false;
        else if (l == NULL and r == NULL)
            return true;
        else if (l->val == r->val)
            return (checking(l->left, r->right) and checking(l->right, r->left));
        return false;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return checking(root->left, root->right);
    }
};