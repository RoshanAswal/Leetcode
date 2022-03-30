class Solution {
public:
    int dp[201][201];
    int sol(int i,int j,int m,int n,vector<vector<int>> &grid){
        if(i==m-1 && j==n-1)return grid[i][j];
        if(i<0 || j<0 || i>=m || j>=n)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=min(sol(i+1,j,m,n,grid),sol(i,j+1,m,n,grid))+grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return sol(0,0,grid.size(),grid[0].size(),grid);
    }
};