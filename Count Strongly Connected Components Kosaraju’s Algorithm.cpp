//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        vector<int> A[V];
        vector<int> rev[V];
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i]){
                A[i].push_back(it);
                rev[it].push_back(i);
            }
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i, vis, A, st);
            }
        }
        for(int i=0;i<V;i++) vis[i]=0;
        int cnt=0;
        while(!st.empty()){
            int node =st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node, vis, rev);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs2(it,vis,adj);
            }
        }
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
