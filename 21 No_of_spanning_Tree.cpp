//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countSpanningTrees(vector<vector<int>>&graph, int n, int m){
        //Write your code here   
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<int> deg(n,0);
        for(auto it:graph){
            adj[it[0]][it[1]]=adj[it[1]][it[0]]=-1;
            deg[it[0]]++;
            deg[it[1]]++;
        }
        for(int i=0;i<n;i++){
            adj[i][i]=deg[i];
        }
        vector<vector<int>> subMatrix(n-1,vector<int>(n-1));
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                subMatrix[i-1][j-1]=adj[i][j];
            }
        }
        int ans = determinant(subMatrix);
        return ans;
    }
    int determinant(vector<vector<int>>& subMatrix){
        int n=subMatrix.size();
        if(n==1) return subMatrix[0][0];
        if(n==2) return subMatrix[0][0]*subMatrix[1][1] - subMatrix[0][1]*subMatrix[1][0];
        int ans = 0;
        for(int p=0;p<n;p++)
        {
            vector<vector<int>> minMat;
            for(int i=1;i<n;i++){
                vector<int> row;
                for(int j=0;j<n;j++){
                    if(j!=p) row.push_back(subMatrix[i][j]);
                }
                if(row.size()) minMat.push_back(row);
            }
            ans = ans + subMatrix[0][p] * pow(-1,p) * determinant(minMat);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>>graph(m, vector<int>(2, 0));
	    for(int i = 0 ; i < m; i++){
	        cin >> graph[i][0] >> graph[i][1];
	    }
	    Solution ob;
	    int ans = ob.countSpanningTrees(graph, n, m);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
