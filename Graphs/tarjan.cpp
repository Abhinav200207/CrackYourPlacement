#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    void dfs(int u, vector<int> adj[], vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &presentStack)
    {
        static int t = 0;
        disc[u] = low[u] = t;
        t++;
        st.push(u);
        presentStack[u] = true;

        for (auto v : adj[u])
        {
            if (disc[v] == -1)
            {
                dfs(v, adj, disc, low, st, presentStack);
                low[u] = min(low[u], low[v]);
            }
            else if (presentStack[v])
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u])
        {
            vector<int> temp;
            while (st.top() != u)
            {
                temp.push_back(st.top());
                presentStack[st.top()] = false;
                st.pop();
            }
            temp.push_back(st.top());
            presentStack[st.top()] = false;
            st.pop();
            ans.push_back(temp);
        }
    }

public:
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> presentStack(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                dfs(i, adj, disc, low, st, presentStack);
            }
        }
        return ans;
    }
};