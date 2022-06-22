// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

// } Driver Code Ends
class Solution
{
    bool isvalid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < R && j < C);
    }
    struct cell
    {
        int time;
        int x, y;
        cell(int n, int x, int y)
        {
            time = n;
            x = x;
            y = y;
        }
    };

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> grid)
    {
        queue<cell> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    cell c = cell(0, i, j);
                    q.push(c);
                }
            }
        }
        cell c = cell(0, 0, 0);
        while (!q.empty())
        {
            c = q.front();
            if (grid[c.x + 1][c.y] == 1 && isvalid(c.x + 1, c.y))
            {
                q.push(cell(c.time + 1, c.x + 1, c.y));
                grid[c.x + 1][c.y] == 2;
            }
            if (grid[c.x - 1][c.y] == 1 && isvalid(c.x - 1, c.y))
            {
                q.push(cell(c.time + 1, c.x - 1, c.y));
                grid[c.x - 1][c.y] == 2;
            }
            if (grid[c.x][c.y + 1] == 1 && isvalid(c.x, c.y + 1))
            {
                q.push(cell(c.time + 1, c.x, c.y + 1));
                grid[c.x][c.y - 1] == 2;
            }
            if (grid[c.x][c.y - 1] == 1 && isvalid(c.x, c.y - 1))
            {
                q.push(cell(c.time + 1, c.x, c.y - 1));
                grid[c.x][c.y + 1] == 2;
            }
            q.pop();
        }
        cout << c.time;
        return 0;
    }
};

int main()
{
    Solution obj;
    obj.orangesRotting({{0, 1, 2}, {0, 1, 2}, {2, 1, 1}});
}