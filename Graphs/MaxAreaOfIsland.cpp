#include <bits/stdc++.h>
using namespace std;

class Solution{
    int cnt;
    void fun(vector<vector<int>> &board, int i, int j, int n, int m){
        if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] != 1){
            return;
        }
        cnt++;
        board[i][j] = 0;
        fun(board, i + 1, j, n, m);
        fun(board, i - 1, j, n, m);
        fun(board, i, j + 1, n, m);
        fun(board, i, j - 1, n, m);
        return;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid){
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    cnt = 0;
                    fun(grid, i, j, n, m);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};