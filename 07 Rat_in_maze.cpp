//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
/*
input:
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

output:
DDRDRR DRDDRR
  */

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> ans;
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,+1,0};
        if(m[0][0]==1) solve(0,0,m,n,vis,ans,"",di,dj);
        return ans;
    }
    void solve(int i,int j,vector < vector < int >> & arr, int n,vector<vector<int>> &vis,
    vector<string> &ans, string path,int di[],int dj[]){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
    string dir="DLRU";
    for(int ind=0;ind<4;ind++){
        int nexti=i+di[ind];
        int nextj=j+dj[ind];
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && arr[nexti][nextj]==1){
            vis[i][j]=1;
            solve(nexti,nextj,arr,n,vis,ans,path+dir[ind],di,dj);
            vis[i][j]=0;
        }
    }
    
    
    // if(i+1<n && !vis[i+1][j] && arr[i+1][j]==1){
    //     vis[i][j]=1;
    //     solve(i+1,j,arr,n,vis,ans,path+'D');
    //     vis[i][j]=0;
    // }
    // if(j-1>=0 && !vis[i][j-1] && arr[i][j-1]==1){
    //     vis[i][j]=1;
    //     solve(i,j-1,arr,n,vis,ans,path+'L');
    //     vis[i][j]=0;
    // }
    // if(j+1<n && !vis[i][j+1] && arr[i][j+1]==1){
    //     vis[i][j]=1;
    //     solve(i,j+1,arr,n,vis,ans,path+'R');
    //     vis[i][j]=0;
    // }
    // if(i-1>=0 && !vis[i-1][j] && arr[i-1][j]==1){
    //     vis[i][j]=1;
    //     solve(i-1,j,arr,n,vis,ans,path+'U');
    //     vis[i][j]=0;
    // }
}
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
