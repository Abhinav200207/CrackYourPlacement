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
    bool check(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (!root && subRoot)
            return false;
        if (root && !subRoot)
            return false;

        if (root->val != subRoot->val)
            return false;

        return check(root->left, subRoot->left) & check(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        if (check(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
    }
};

// int main()
// {
//     Solution solution;
//     solution.isSubtree()
// }