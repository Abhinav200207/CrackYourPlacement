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
    vector<vector<int>> ans;
    void fun(TreeNode *root, int targetSum, vector<int> tempAns)
    {
        if (!root->left && !root->right)
        {
            if (targetSum - root->val == 0)
            {
                tempAns.push_back(root->val);
                ans.push_back(tempAns);
            }
        }
        tempAns.push_back(root->val);
        if (root->left)
        {
            fun(root->left, targetSum - root->val, tempAns);
        }
        if (root->right)
        {
            fun(root->right, targetSum - root->val, tempAns);
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        fun(root, targetSum, {});
        return ans;
    }
};