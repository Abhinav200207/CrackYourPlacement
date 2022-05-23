#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void fun(vector<vector<char>> &mat, int i, int j, char oldVal, char newVal)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != oldVal)
        {
            return;
        }
        mat[i][j] = newVal;
        fun(mat, i + 1, j, oldVal, newVal);
        fun(mat, i - 1, j, oldVal, newVal);
        fun(mat, i, j + 1, oldVal, newVal);
        fun(mat, i, j - 1, oldVal, newVal);
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O')
                {
                    mat[i][j] == '1';
                }
            }
        }

        for (int i = 0; i < mat.size(); i++)
            if (mat[i][0] == '1')
                fun(mat, i, 0, '-', 'O');
        for (int i = 0; i < mat.size(); i++)
            if (mat[i][mat[0].size() - 1] == '1')
                fun(mat, i, mat[i].size() - 1, '-', 'O');
        for (int i = 0; i < mat[i].size(); i++)
            if (mat[0][i] == '1')
                fun(mat, 0, i, '-', 'O');
        for (int i = 0; i < mat[i].size(); i++)
            if (mat[mat.size() - 1][i] == '-')
                fun(mat, mat.size() - 1, i, '1', 'O');

        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                if (mat[i][j] == '1')
                    mat[i][j] = 'X';
    }
};