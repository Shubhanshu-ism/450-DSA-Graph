void dfs(vector<vector<int>> &adj,vector<int>&vis,vector<int>& ans,int node){
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]) dfs(adj,vis,ans,it);
    }
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> comp;
            dfs(adj,vis,comp,i);
            ans.push_back(comp);
        }
    }
    
    return ans;
}
