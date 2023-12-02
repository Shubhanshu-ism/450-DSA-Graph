/*
input
4
3
1 0
2 1
3 2

output Yes
*/
class Solution {
public:
	bool isPossibleBFS(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> deg(N,0);
	    vector<int> adj[N];
	    for(auto i:prerequisites){
	        adj[i.first].push_back(i.second);
	        deg[i.second]++;
	    }
	    int cnt=0;
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(deg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        cnt++;
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node]){
	            deg[it]--;
	            if(deg[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return cnt==N;
	}
	bool isPossibleDFS(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto i:prerequisites){
	        adj[i.first].push_back(i.second);
	    }
	    vector<int> vis(N,0);
	    vector<int> path(N,0);
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(dfs(i,adj,vis,path)) return false;
	        }
	    }
	    return true;
	}
	bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &path){
	    vis[node]=path[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it] && dfs(it,adj,vis,path)) return true;
	        if(vis[it] && path[it]) return true;
	    }
	    path[node]=0;
	    return false;
	}
};
