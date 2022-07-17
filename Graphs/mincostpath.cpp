#include <bits/stdc++.h>
using namespace std;

int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    pair<int, int> direc[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    dist[0][0] = grid[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(dist[0][0], make_pair(0, 0)));

    while (!pq.empty())
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();

        int i = p.second.first;
        int j = p.second.second;

        int distance = p.first;

        for (auto it : direc)
        {
            int new_i = i + it.first;
            int new_j = j + it.second;

            if (new_j < n && new_i < n && new_i >= 0 && new_j >= 0)
            {
                if (dist[i][j] + grid[new_i][new_j] < dist[new_i][new_j])
                {
                    dist[new_i][new_j] = dist[i][j] + grid[new_i][new_j];
                    pq.push({dist[new_i][new_j], {new_i, new_j}});
                }
            }
        }
    }
    return dist[n - 1][n - 1];
}


// Will give TLE
int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    pair<int, int> direc[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    dist[0][0] = grid[0][0];
    queue<pair<int, pair<int, int>>> pq; // , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(dist[0][0], make_pair(0, 0)));

    while (!pq.empty())
    {
        pair<int, pair<int, int>> p = pq.front();
        pq.pop();

        int i = p.second.first;
        int j = p.second.second;

        int distance = p.first;

        for (auto it : direc)
        {
            int new_i = i + it.first;
            int new_j = j + it.second;

            if (new_j < n && new_i < n && new_i >= 0 && new_j >= 0)
            {
                if (dist[i][j] + grid[new_i][new_j] < dist[new_i][new_j])
                {
                    dist[new_i][new_j] = dist[i][j] + grid[new_i][new_j];
                    pq.push({dist[new_i][new_j], {new_i, new_j}});
                }
            }
        }
    }
    return dist[n - 1][n - 1];
}