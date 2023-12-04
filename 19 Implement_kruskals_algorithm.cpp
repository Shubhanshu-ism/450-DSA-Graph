//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjoint{
    private: vector<int> par,size;
    public:
    disjoint(int V)
    {
        par.resize(V+1,0);
        size.resize(V+1,0);
        for(int i=0;i<=V;i++)
        {
            par[i]=i;
            size[i]=1;
        }
    }
    int ult_p(int v){
        if(v==par[v]) return v;
        else return par[v]=ult_p(par[v]);
    }
    void unionBySize(int u,int v){
        int UP=ult_p(u);
        int VP=ult_p(v);
        if(UP==VP) return;
        if(size[UP]<size[VP]){
            par[UP]=VP;
            size[VP]+=size[UP];
            
        }
        else{
            par[VP]=UP;
            size[UP]+=size[VP];
        }
    }
    void UnionByRank(int u,int v)
    {
        int UltParU = findUltPar(u);
        int UltParV = findUltPar(v);
        if(UltParU==UltParV) return;
        if(size[UltParU] > size[UltParV]){
            parent[UltParV] = UltParU;
        }
        else if(size[UltParU] < size[UltParV]){
            parent[UltParU] = UltParV;
        }
		    else{
			    rank[UltParU]++;
		    }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjnode}});
            }
            
            
        }
        disjoint ds(V);
        sort(edges.begin(),edges.end());
        int ans=0;
        
        for(auto it:edges)
        {
            int wt=it.first;
            int node=it.second.first;
            int adjnode=it.second.second;
            if(ds.ult_p(node)!= ds.ult_p(adjnode) ){
                ans+=wt;
                ds.unionBySize(node,adjnode);
            }
        }
        return ans;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
