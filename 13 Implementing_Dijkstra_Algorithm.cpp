//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> s;
        s.insert({0,S});
        vector<int> dis(V,1e9);
        dis[S]=0;
        while(!s.empty())
        {
            int dist = (*s.begin()).first;
            int node = (*s.begin()).second;
            s.erase(s.begin());
            for(auto it: adj[node]){
                int adjNode = it[0];
                int weight = it[1];
                
                if(dis[adjNode]>dis[node]+weight)
                {
                    if(dis[adjNode]!=1e9) s.erase({dis[adjNode],adjNode,});
                    dis[adjNode]=dis[node]+weight;
                    s.insert({dis[adjNode],adjNode,});
                }
            }
        }
        return dis;
      /*
      vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({S,0});
        vector<int> dis(V,1e9);
        dis[S]=0;
        while(!pq.empty()){
            int node= pq.top().first;
            int wt = pq.top().second;
            pq.pop();
            for(auto it :adj[node]){
                int adjNode= it[0];
                int adjWt = it[1];
                if(dis[node]+adjWt<dis[adjNode]){
                    dis[adjNode]=dis[node]+adjWt;
                    pq.push({adjNode,dis[adjNode]});
                }
            }
        }
        return dis;
      }
      */
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
