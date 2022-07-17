#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        for (auto i : adj[temp.second])
        {
            {
                if (dist[i[0]] > dist[temp.second] + i[1])
                {
                    dist[i[0]] = dist[temp.second] + i[1];
                    pq.push(make_pair(dist[i[0]], i[0]));
                }
            }
        }
    }
    return dist;
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    queue<pair<int, int>> pq;
    pq.push({0, S});
    while (!pq.empty())
    {
        pair<int, int> temp = pq.front();
        pq.pop();
        for (auto i : adj[temp.second])
        {
            if (dist[i[0]] > dist[temp.second] + i[1])
            {
                dist[i[0]] = dist[temp.second] + i[1];
                pq.push(make_pair(dist[i[0]], i[0]));
            }
        }
    }
    return dist;
}