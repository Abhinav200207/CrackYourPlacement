#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &v, int i, int j, int n, int m)
{
    int cnt = 0;
    if (i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1] == 1)
    {
        cnt++;
    }
    if (i + 1 < n && j + 1 < m && v[i + 1][j + 1] == 1)
    {
        cnt++;
    }
    if (i - 1 >= 0 && j + 1 < m && v[i - 1][j + 1] == 1)
    {
        cnt++;
    }
    if (i + 1 < n && j - 1 >= 0 && v[i + 1][j - 1] == 1)
    {
        cnt++;
    }
    if (i - 1 >= 0 && v[i - 1][j] == 1)
    {
        cnt++;
    }
    if (i + 1 < n && v[i + 1][j] == 1)
    {
        cnt++;
    }
    if (j + 1 < m && v[i][j + 1] == 1)
    {
        cnt++;
    }
    if (j - 1 >= 0 && v[i][j - 1] == 1)
    {
        cnt++;
    }
    if (v[i][j] != 1 && (cnt == 2 || cnt != 3)){
        return 1;
    }
    if (v[i][j] == 0 && cnt == 3){
        return 1;
    }
    return 0;
}

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (isSafe(board,i,j,n,m))
                    v[i][j] = !v[i][j];
            }
        }
        board = v;
    }
};
