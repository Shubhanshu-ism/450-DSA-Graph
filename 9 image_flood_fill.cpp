vector<int> Row={0,1,0,-1};
vector<int> Col={1,0,-1,0};
void dfs(vector<vector<int>> &image, int r, int c, int newColor,vector<vector<int>> &ans,int intial){
    ans[r][c]=newColor;
    int n=image.size();
    int m=image[0].size();
    
    for(int i=0;i<4;i++){
        int row=r+Row[i];
        int col=c+Col[i];
        if(row>=0 &&col>=0 && row<n&&col<m&&image[row][col]==intial &&ans[row][col]!=newColor) 
        dfs(image,row,col,newColor,ans,intial);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    vector<vector<int>> ans=image;
    int intial=image[x][y];
    dfs(image,x,y,newColor,ans,intial);
    return ans;
}
