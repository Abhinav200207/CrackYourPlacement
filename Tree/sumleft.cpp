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
    int sumOfLeft = 0;
    void fun(TreeNode *root, int flag)
    {
        if (root != NULL)
        {
            if (!root->left && !root->right && flag == 1)
            {
                sumOfLeft += root->val;
            }
            fun(root->left, 1);
            fun(root->right, 0);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return 0;
        }
        fun(root, 0);
        // inorder(root);
        return sumOfLeft;
    }
};