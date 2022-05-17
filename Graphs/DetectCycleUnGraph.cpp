#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(vector<int> adj[], int V, int parent, vector<int> &vis)
    {
        vis[V] = 1;
        cout << V << endl;
        for (auto i : adj[V])
        {
            if (!vis[i])
            {
                if (dfs(adj, i, V, vis))
                {
                    return true;
                }
            }
            else if (vis[i] && i != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(adj, i, -1, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};