class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1)
            return;
        grid[i][j]=1;
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
    }
    int closedIsland(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==0){
                    dfs(i,j,m,n,grid);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(i,j,m,n,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};