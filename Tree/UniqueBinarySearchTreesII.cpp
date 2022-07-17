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
    vector<TreeNode *> fun(int i, int j)
    {
        if (i > j)
        {
            return {NULL};
        }
        vector<TreeNode *> ans;
        for (int curr = i; curr <= j; curr++)
        {
            vector<TreeNode *> left = fun(i, curr - 1);
            vector<TreeNode *> right = fun(curr + 1, j);
            for (auto x : left)
            {
                for (auto y : right)
                {
                    TreeNode *tempNode = new TreeNode(curr);
                    tempNode->left = x;
                    tempNode->right = y;
                    ans.push_back(tempNode);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return fun(1, n);
    }
};