#include <bits/stdc++.h> 
bool dfs(int V,vector<int>adj[],int st,vector<int>& vis,int col){
        vis[st]=col;
        for(auto it:adj[st])
        {
            if(vis[it]==-1)
            {
                
                if(dfs(V,adj,it,vis,!col)==false) return false;
            }
            else if(vis[it]==vis[st]) return false;
        }
        return true;
    }
bool twoCliques(int n, vector<vector<int>> &edgeList)
{
	vector<int> comp[n];
	vector<int> adj[n];
	for(auto i:edgeList){
		adj[i[0]].push_back(i[1]);
		adj[i[1]].push_back(i[0]);
	}
	for(int i=0;i<n;i++)
	{
		vector<int> d(n,0);
		d[i]=1;
		for(auto it:adj[i])
		{
			d[it]=1;
		}
		for(int j=0;j<n;j++)
		{
			if(d[j]==0){
				comp[j].push_back(i);
				comp[i].push_back(j);
			}
		}
	}
	vector<int> col(n,-1);
	return dfs(n,comp,0,col,0);

}
