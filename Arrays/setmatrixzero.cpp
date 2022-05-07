#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &arr)
    {
        set<int> columns;
        set<int> rows;
        int n = arr.size();
        int m = arr[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (rows.find(i) != rows.end() || columns.find(j) != columns.end())
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
};