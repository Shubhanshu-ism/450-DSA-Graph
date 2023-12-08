#include <bits/stdc++.h> 
int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
	vector<pair<int,int>> adj[n];  // [node]->{adjNode, cost of travel}
	for(auto i:edgeList)
	{
		adj[i[1]].push_back({i[0],1});  //if there is path then reversal will cost 1
		adj[i[0]].push_back({i[1],0});  //it there is path then it will cost 0
	}
	vector<int> vis(n,0);
	
	vector<int> dist(n,1e9);
	dist[start]=0;

	set<pair<int,int>> s;  //  < distance from start, node >
	s.insert({0,start});   //Dijkstra Algo
	while(!s.empty())
	{
		auto top = *(s.begin());
		int node = top.second;
		int path = top.first;
		vis[node]=1;
		s.erase(top);

		for(auto it:adj[node])
		{
			int adjNode = it.first;
			int wt = it.second;
			if(vis[adjNode]) continue;
			if(dist[adjNode] > path + wt)
			{
				s.erase({dist[adjNode],adjNode});
				dist[adjNode] = path + wt;
				s.insert({dist[adjNode],adjNode});
			}
		}
	}
	if(dist[end]==1e9) return -1;
	return dist[end];
}
