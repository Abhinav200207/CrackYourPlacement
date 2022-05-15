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
public:
    vector<string> v;

    void func(TreeNode *root, string s)
    {

        int val1 = root->val;

        if (root->left == NULL && root->right == NULL)
        {
            s += to_string(val1);
            v.push_back(s);
            return;
        }

        if (root->left)
        {
            func(root->left, s + to_string(val1) + "->");
        }

        if (root->right)
        {
            func(root->right, s + to_string(val1) + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        func(root, "");
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << "\n";
        }
        return v;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);

    root->left = left;
    root->right = right;

    right->left = NULL;
    right->left = NULL;

    left->left = NULL;

    TreeNode *leftchild = new TreeNode(4);

    left->right = leftchild;

    leftchild->right = NULL;
    leftchild->left = NULL;

    Solution obj;
    obj.binaryTreePaths(root);
}