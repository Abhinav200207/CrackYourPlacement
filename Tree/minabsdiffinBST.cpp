// Minimum Absolute Difference in BST

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

class Solution {
    int diff = INT_MAX;
    int prev = INT_MAX;
    void inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            diff = min(diff,abs(prev - root->val));
            prev = root->val;
            inorder(root->right);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return diff;
    }
};