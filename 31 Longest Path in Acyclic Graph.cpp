//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void topSort(int node ,int vis[] ,vector<pair<int,int>>adj[],stack<int>&st){
          
          vis[node] = 1;
          
          for(auto& vec : adj[node]){
              
              int adjNode = vec.first;
              
              if(!vis[adjNode]){
                  topSort(adjNode,vis,adj,st);
              }
          }
          
          st.push(node);
      }
    
      vector<int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            
            vector<pair<int,int>>adj[v];
            
            for(int i=0; i<e; i++){
                int u = edges[i][0], v = edges[i][1] , weight = edges[i][2]; 
                adj[u].push_back({v,-weight});
            }
            
            
            stack<int>st;
            
            vector<int>dist(v,1e9);
            int vis[v] = {0};
            
            dist[src] = 0;
            
            for(int i=0; i<v; i++){
                if(!vis[i]){
                    topSort(i,vis,adj,st);
                }
            }
            
            
            while(!st.empty()){
                int node = st.top();
                st.pop();
                
                if(dist[node] != 1e9){
                    
                    for(auto& vec : adj[node]){
                    int adjNode = vec.first;
                    int adjNodeDist = vec.second;
                    
                    if(dist[node]+adjNodeDist < dist[adjNode]){
                        
                        dist[adjNode] = dist[node]+adjNodeDist;
                        
                    }
                 }
                
                }
            }
            
            
      for(int i=0; i<dist.size(); i++){
          
          if(dist[i] == 1e9) dist[i] = INT_MIN;
          else dist[i] = -dist[i];
      }        
            
            return dist;
            
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends
