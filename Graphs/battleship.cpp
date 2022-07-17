#include <bits/stdc++.h>
using namespace std;

void fun(vector<vector<char>> &board, int i, int j, int n, int m)
{
    if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] != 'X')
    {
        return;
    }
    board[i][j] = '.';
    fun(board, i + 1, j, n, m);
    fun(board, i - 1, j, n, m);
    fun(board, i, j + 1, n, m);
    fun(board, i, j - 1, n, m);
    return;
}

int countBattleships(vector<vector<char>> &board)
{
    int cnt = 0;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'X')
            {
                cnt++;
                fun(board, i, j, n, m);
            }
        }
    }
    return cnt;
}
