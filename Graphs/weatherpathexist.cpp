#include <bits/stdc++.h>
using namespace std;

bool fun(vector<vector<int>> &grid, int n, int i, int j)
{
    if (i < 0 || j < 0 || i >= n - 1 || j >= n - 1 || grid[i][j] == 0)
    {
        return false;
    }
    if (grid[i][j] == 2)
    {
        return true;
    }
    cout << i << " " << j << endl;
    grid[i][j] == 0;
    return fun(grid, n, i + 1, j) ||
           fun(grid, n, i - 1, j) ||
           fun(grid, n, i, j + 1) ||
           fun(grid, n, i, j - 1);
}

bool is_Possible(vector<vector<int>> &v)
{
    int ans = false;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i][j] == 1)
            {
                ans = fun(v, v.size(), i, j);
                break;
            }
        }
    }
    return ans;
}

void printtwovector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        int a;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        grid.push_back(temp);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    printtwovector(grid);
    cout << endl;
    cout << endl;
    cout << is_Possible(grid);
}