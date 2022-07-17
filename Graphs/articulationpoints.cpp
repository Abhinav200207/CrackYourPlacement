#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans;
    void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<int> adj[], vector<bool> &arti)
    {
        static int t = 0;
        low[u] = disc[u] = t;
        t++;
        int childCnt = 0;

        for (auto v : adj[u])
        {
            if (disc[v] == -1)
            {
                childCnt++;
                parent[v] = u;

                dfs(v, disc, low, parent, adj,arti);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && childCnt > 1)
                {
                    arti[v] = true;
                }
                if (parent[u] != -1 && low[v] >= disc[u])
                {
                    arti[v] = true;
                }
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> arti(V, false);

        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                dfs(i, disc, low, parent, adj, arti);
            }
        }
        for (auto i = 0; i < arti.size(); i++){
            if (arti[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};