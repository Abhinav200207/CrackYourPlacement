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
    int fun(TreeNode *root, int target)
    {
        if (root == NULL)
            return false;
        if (root->right == NULL && root->left == NULL)
        {
            return target - root->val == 0;
        }
        return fun(root->left, target - root->val) || fun(root->right, target - root->val);
    }

public:
    bool
    hasPathSum(TreeNode *root, int targetSum)
    {
        return fun(root, targetSum);
    }
};