class Solution {
public:
    int dp[5001][301];
    Solution(){memset(dp,-1,sizeof dp);}
    int sol(int am,int n,vector<int> &coins){
        if(am==0)return 1;
        if(am<=0 || n==0)return 0;
        if(dp[am][n]!=-1)return dp[am][n];
        dp[am][n]=sol(am-coins[n-1],n,coins)+sol(am,n-1,coins);
        return dp[am][n];
    }
    int change(int amount, vector<int>& coins) {
        return sol(amount,coins.size(),coins);
    }
};