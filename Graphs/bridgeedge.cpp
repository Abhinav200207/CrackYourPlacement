#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<int> &vis)
{
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(j, adj, vis);
        }
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    int x = 0;
    for (int i = 0; i < adj[c].size(); i++)
    {
        if (adj[c][i] == d)
        {
            x = i;
            break;
        }
    }
    adj[c].erase(adj[c].begin() + x);
    for (int i = 0; i < adj[d].size(); i++)
    {
        if (adj[d][i] == c)
        {
            x = i;
            break;
        }
    }
    adj[d].erase(adj[d].begin() + x);
    int cnt = 0;
    vector<int> vis(V, false);
    dfs(c, adj, vis);
    return vis[d];
}