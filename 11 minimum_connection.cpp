#include <bits/stdc++.h> 
void dfs(int node,vector<int> adj[],vector<int> &vis){
	vis[node]=1;
	for(auto it:adj[node]){
		if(vis[it]==0) dfs(it,adj,vis);
	}
}
int minConnectionChanges(int n, vector<vector<int>> &wires)
{
	int v = wires.size();
	if(v<n-1) return -1;
	vector<int> adj[n+1];
	for(auto i:wires){
		adj[i[0]].push_back(i[1]);
		adj[i[1]].push_back(i[0]);
	}
	vector<int> vis(n+1,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			cnt++;
			dfs(i,adj,vis);
		}
	}
	return cnt-1;
}
