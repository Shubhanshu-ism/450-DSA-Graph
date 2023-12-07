#include <bits/stdc++.h> 

bool dfs(int node,vector<pair<int,int>>adj[],vector<int>&vis,int k)
{
    vis[node]=1;
    if(k<=0) return true;
    
    for(auto it:adj[node])
    {
        int adjNode = it.first;
        int wt =it.second;
        if(vis[adjNode]) continue;
        if(k<=wt) return true;
        else if(dfs(adjNode,adj,vis,k-wt))return true;
    }
    vis[node]=0;
    return false;
}

string pathMoreThanK(int n, int m, int k, vector<vector<int>>& edges)
{
    vector<pair<int,int>> adj[n];
    for(auto i:edges)
    {
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }
    vector<int> vis(n,0);
    if(dfs(0,adj,vis,k)) return "YES";
    return "NO"; 
}
