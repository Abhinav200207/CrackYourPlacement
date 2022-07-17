#include <bits/stdc++.h>
using namespace std;

void findPreSuc(Node *root, Node *&pre, Node *&suc, int k)
{
    if (root == NULL)
        return;
    Node *temp = root;

    suc = NULL;
    pre = NULL;

    while (temp != NULL)
    {
        if (temp->key <= k)
            temp = temp->right;
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }

    temp = root;
    while (temp != NULL)
    {
        if (temp->key >= k)
            temp = temp->left;
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }
}