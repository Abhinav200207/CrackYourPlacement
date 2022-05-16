#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<bool> visited(n,false);
        vector<int> ans;
        dfs(ans,visited,adj,0);
        return ans;
    }
    
    void dfs(vector<int> &ans,vector<bool> &visited,vector<int> adj[],int node){
        if(visited[node])return;
        ans.push_back(node);
        visited[node]=true;
        for(auto nbr:adj[node]){
            dfs(ans,visited,adj,nbr);
        }
    }
};