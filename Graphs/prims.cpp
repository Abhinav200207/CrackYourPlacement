#include <bits/stdc++.h>
using namespace std;

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> w(V, INT_MAX);
    vector<bool> pro(V, false);

    w[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (pq.size()) // Imp for all queue and priority queue related ques
    {
        int U = pq.top().second;
        pq.pop();
        if (pro[U])  // Imp for clearing TLE
        {
            continue;
        }
        pro[U] = true;

        for (auto i : adj[U])
        {
            if (pro[i[0]] == false && i[1] <= w[i[0]])
            {
                w[i[0]] = i[1];
                pq.push(make_pair(w[i[0]], i[0]));
            }
        }
    }
    return accumulate(w.begin(), w.end(), 0);
}