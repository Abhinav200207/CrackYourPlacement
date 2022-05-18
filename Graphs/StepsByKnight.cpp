#include <bits/stdc++.h>
using namespace std;

int dRow[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dCol[] = {-2, 2, -2, 2, -1, 1, -1, 1};

bool isValid(vector<vector<bool>> vis, int n, int row, int col)
{
    if (row < 1 || col < 1 || row > n || col > n)
        return false;
    if (vis[row][col])
        return false;
    return true;
}

int minStepToReachTarget(vector<int> KnightPos, vector<int> TargetPos, int n)
{
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, 0));
    queue<pair<int, int>> q;
    q.push({KnightPos[0], KnightPos[1]});
    vis[KnightPos[0]][KnightPos[1]] = 1;

    while (!q.empty())
    {

        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;

        // cout << x << " " << y << "\n";

        q.pop();

        for (int i = 0; i < 8; i++)
        {

            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(vis, n, adjx, adjy))
            {
                q.push({adjx, adjy});
                vis[adjx][adjy] = vis[x][y] + 1;
            }
        }
    }
    return vis[TargetPos[0]][TargetPos[1]];
}

// Driver Code
int main()
{

    // Declare the visited array

    minStepToReachTarget({4, 5}, {1, 1}, 5);

    return 0;
}
