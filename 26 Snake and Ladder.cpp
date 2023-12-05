#include<bits/stdc++.h>
pair<int,int> findCord(int num,int n)
{
    int r = n-1 -(num-1)/n;
    int c = (num-1)%n;
    if(r%2 == n%2) c = n-1-c;
    return {r,c};
}
int minDiceThrowToLastCell(int **board, int n)
{
    vector<vector<int>> vis(n,vector<int>(n,0));
    queue<pair<int,int>> q;
    q.push({1,0});     // {intialStep , initailMove}
    int target = n*n;
    while(!q.empty())
    {
        int node = q.front().first;
        int Throw = q.front().second;
        q.pop();

        if(node == target) return Throw;

        for(int i=1;i<=6 ;i++)
        {
            if(node+i > target) continue;

            auto cor = findCord(node+i,n);
            int r = cor.first;
            int c = cor.second;

            if(vis[r][c]) continue;
            vis[r][c]=1;
            
            if(board[r][c]==-1) q.push({node+i,Throw+1});
            else q.push({board[r][c],Throw+1});
        }
    }
    return -1;
}
/*
input:
6
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 35 -1 -1 13 -1
-1 -1 -1 -1 -1 -1
-1 15 -1 -1 -1 -1

output: 4
*/
