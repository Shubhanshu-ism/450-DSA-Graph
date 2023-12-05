//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dis(n,1e8);
	    dis[0]=0;
	    for(int i=0;i<n-1;i++){
	        for(auto it:edges){
	            int u =it[0];
	            int v =it[1];
	            int w =it[2];
	            if(dis[u]+w < dis[v]) dis[v]= dis[u]+w;
	        }
	    }
	    for(auto it:edges)
	    {
	            int u =it[0];
	            int v =it[1];
	            int w =it[2];
	            if(dis[u]+w < dis[v]) return 1;
	        
	    }
	    return 0;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
