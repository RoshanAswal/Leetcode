class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,int m,int n,int &c){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)return;
        grid[i][j]=0;
        c++;
        dfs(i+1,j,grid,m,n,c);
        dfs(i-1,j,grid,m,n,c);
        dfs(i,j+1,grid,m,n,c);
        dfs(i,j-1,grid,m,n,c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int c=0;
                    dfs(i,j,grid,m,n,c);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};