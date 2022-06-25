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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }
    bool fun(TreeNode *root)
    {
        if (!root)
            return 1;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && fun(root->left) && fun(root->right) ? true : false;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return fun(root);
    }
};