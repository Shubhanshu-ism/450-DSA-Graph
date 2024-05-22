//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*

input
6
4 5
1 1

output
3

*/
// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    if(x1==x2 && y1==y2) return 0;
	    
	    vector<vector<int>> steps(N,vector<int>(N,0));
	    
	    int R[]={1,2,2,1,-1,-2,-2,-1};
	    int C[]={2,1,-1,-2,-2,-1,1,2};
	    
	    queue<pair<int,int>> q;
	    q.push({x1-1,y1-1});
	    
	    while(!q.empty())
	    {
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(int i=0;i<8;i++)
	        {
	            int r = x + R[i];
	            int c = y + C[i];
	            if(check(r,c,N,steps))
	            {
	                q.push({r,c});
	                steps[r][c]=steps[x][y]+1;
	            }
	        }
	    }
	    return steps[x2-1][y2-1];
	}
	bool check(int r,int c,int n,vector<vector<int>> & steps){
	    if(r>=0 && r<n && c>=0 && c<n && steps[r][c]==0) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
