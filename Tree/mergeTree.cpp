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
    TreeNode *fun(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 != NULL)
        {
            return root2;
        }
        if (root1 != NULL && root2 == NULL)
        {
            return root1;
        }
        if (root1 == NULL && root2 == NULL)
        {
            return NULL;
        }
        root1->val += root2->val;
        root1->left = fun(root1->left, root2->left);
        root1->right = fun(root1->right, root2->right);
        return root1;
    }

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return fun(root1, root2);
    }
};