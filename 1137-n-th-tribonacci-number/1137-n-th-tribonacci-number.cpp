class Solution {
public:
    int sol(int n,vector<int> &dp){
        if(n<=0)return 0;
        if(n==1 || n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        dp[n]=sol(n-1,dp)+sol(n-2,dp)+sol(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(38,-1);
        return sol(n,dp);
    }
};