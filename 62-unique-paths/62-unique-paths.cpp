class Solution {
public:
    int dp[101][101];
    Solution(){memset(dp,0,sizeof(dp));}
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)return 1;
        if(dp[m][n]!=0)return dp[m][n];
        if(m-1>0)dp[m][n]+=uniquePaths(m-1,n);
        if(n-1>0)dp[m][n]+=uniquePaths(m,n-1);
        return dp[m][n];
    }
};