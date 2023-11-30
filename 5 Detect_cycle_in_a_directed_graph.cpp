//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> path(V,0);
        return bfs(V,adj);
    }
    bool dfs(int V, vector<int> adj[],int node,vector<int> &vis,vector<int>& path){
        vis[node]=path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it] && dfs(V,adj,it,vis,path)) return true;
            if(vis[it] && path[it]) return true;
        }
        path[node]=0;
        return false;
    }
    bool bfs(int V, vector<int> adj[]){
        vector<int> deg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            deg[it]++;
	        }
	    }
	    int cnt=0;
	   // vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(deg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	       // ans.push_back(node);
	       cnt++;
	        q.pop();
	        for(auto it:adj[node]){
	            deg[it]--;
	            if(deg[it]==0) q.push(it);
	        }
	    }
	    if(cnt==V) return false;
	    return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
