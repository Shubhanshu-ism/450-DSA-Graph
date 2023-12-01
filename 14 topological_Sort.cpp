//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 

	vector<int> topoSortDFS(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
	void dfs(int node,vector<int> adj[],int vis[],stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
  vector<int> topoSortBFS(int V, vector<int> adj[]) 
	{
	    vector<int> deg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            deg[it]++;
	        }
	    }
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(deg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it:adj[node]){
	            deg[it]--;
	            if(deg[it]==0) q.push(it);
	        }
	    }
	    return ans;
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res1 = obj.topoSortDFS(N, adj);
        vector <int> res2 = obj.topoSortBFS(N, adj);
        
        cout << check(N, res1, adj) << endl;
        cout << check(N, res2, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
