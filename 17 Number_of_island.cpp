//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid,int n,int m){
        vis[i][j]=1;
        int R[]={0,1,1,1,0,-1,-1,-1};
        int C[]={1,1,0,-1,-1,-1,0,1};
        for(int k=0;k<8;k++){
            int x = i + R[k];
            int y = j + C[k];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]=='1'){
                dfs(x,y,vis,grid,n,m);
            }
        }
    }
};
/*
input:
7 10
1 0 0 0 0 1 0 0 0 1
1 0 1 1 1 1 1 0 0 1
1 1 1 1 1 0 0 0 1 0
1 1 1 0 1 0 0 1 0 1
0 1 0 1 0 0 0 1 0 0
0 0 0 0 0 1 1 1 1 0
0 0 1 1 0 0 0 1 0 0

Expected Output: 
3
    */

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
