//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> color(n,0);  //to know the color of nth node
                                // as this would be usefull in checking for adjNode color
        if (sol(graph,m,n,0,color)) return true;
        return false;
    }
    bool sol(bool graph[101][101], int m, int n,int node,vector<int> &color){
        if(node==n) return true;
        for(int i=1;i<=m;i++)
        {
            color[node]=i;
            if( isSafe(graph,n,node,color) )
            {
                if(sol(graph,m,n,node+1,color)) return true;
            }
            color[node]=0;
        }
        return false;
    }
    bool isSafe(bool graph[101][101], int n,int node,vector<int> &color){
        for(int i=0;i<n;i++){
            if(i!=node && graph[node][i]==1 && color[i]==color[node]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
