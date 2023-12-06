#include<bits/stdc++.h>
#define int   long long int

using namespace std;

void dfs(int node,vector<int> adj[],vector<int>&vis,int &cnt){
    vis[node]=1;
    cnt++;
    for(auto i:adj[node]){
        if(!vis[i]) dfs(i,adj,vis,cnt);
    }
}
int astro(vector<int> adj[],int n,int m)
{
    vector<int> vis(n,0);
    vector<int> com;
    for(int i=0;i<n;i++){
        int cnt=0;
        if(vis[i]==0){
            dfs(i,adj,vis,cnt);
            com.push_back(cnt);
        }
    }
    int ans =(n*n-n)/2;
    int size =com.size();
    for(int i=0;i<size;i++){
        ans = ans - (com[i]*com[i] -com[i])/2;
    }
    return ans;
}
int32_t main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<astro(adj,n,e);
}
