#include <bits/stdc++.h> 

void dfs(int node,vector<int>adj[],int par,vector<int>&tin,vector<int>&tout,int &time)
{
    tin[node]=time++;
    
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,adj,node,tin,tout,time);
        }
    }
    tout[node]=time++;
}


bool isSubTree(int x,int y,vector<int> &tin,vector<int> &tout)
{
    return (tin[x]>=tin[y] && tout[x] <= tout[y]);
}


vector<bool> hideAndSeek(vector<vector<int>> &graph, int vertices, vector<vector<int>> &queries) 
{
    
    vector<bool> ans;
    vector<int> adj[vertices+1];

    for(auto i:graph)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> tin(vertices+1,0);
    vector<int> tout(vertices+1,0);
    
    int time=1;
    dfs(1,adj,0,tin,tout,time);

    for(int i=0;i<queries.size();i++)
    {
        int move =queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        bool f=false;
        if(move==0 && isSubTree(x,y,tin,tout) || move ==1 && isSubTree(y,x,tin,tout)) f=true;   
        ans.push_back(f);
    }
        
    return ans;
}
