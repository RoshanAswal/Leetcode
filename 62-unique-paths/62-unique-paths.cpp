class Solution {
public:
    int sol(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m-1 || j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=sol(i+1,j,m,n,dp)+sol(i,j+1,m,n,dp);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return sol(0,0,m,n,dp);
    }
};