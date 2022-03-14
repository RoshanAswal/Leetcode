class Solution {
public:
    int sol(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i>=m || j>=n || grid[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=sol(i+1,j,m,n,grid,dp)+sol(i,j+1,m,n,grid,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sol(0,0,m,n,grid,dp);
    }
};