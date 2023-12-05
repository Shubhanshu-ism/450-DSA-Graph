#include<bits/stdc++.h>
void dfs(int par, int node, vector<int>& vis,
    int tin[], int low[],vector<int> adj[],vector<vector<int>> &bridge,int &timer){
    
    vis[node]=1;
    low[node]=tin[node]=timer;
    timer++;
    for(auto it:adj[node])
    {
        if(par==it) continue;
        if(vis[it]==0)
        {
            dfs(node,it,vis,tin,low,adj,bridge,timer);
            low[node]=min(low[node],low[it]);
            if(low[it] > tin[node]) bridge.push_back({node,it});
        }
        else
        {
            low[node]=min(low[node],low[it]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<int> vis(v,0);
    int low[v];
    int tin[v];
    vector<vector<int>> bridge;
    int timer=1;
    vector<int> adj[v];
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    dfs(-1,0,vis,tin,low,adj,bridge,timer);
    return bridge;
}
/*
input:
1
6 7
1 2
1 0
0 2
0 4
5 4
5 3
3 4

output:
1
0 4
*/
