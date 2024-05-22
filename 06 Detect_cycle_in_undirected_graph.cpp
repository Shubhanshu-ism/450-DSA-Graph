//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
input:
5 5
0 1
1 2
1 4
2 3
3 4
*/
// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && dfs(adj,vis,i,-1)) return true;
            //if(!vis[i] && bfs(adj,vis,i)) return true;
        }
        return false;
    }
    bool dfs(vector<int> adj[],vector<int> &vis,int node,int par)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(adj,vis,it,node))
                return true;
            }
            else if(it!=par) return true;
        }
        return false;
    }
    bool bfs(vector<int> adj[],vector<int> &vis,int scr){
        vis[scr]=1;
        queue<pair<int,int>> q;
        q.push({scr,-1});
       
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
