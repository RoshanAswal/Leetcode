class Solution {
public:
    int dp[13][10001];
    int sol(vector<int> &coins,int ind,int amount){
        if(amount>0 && ind<0)return INT_MAX/2;
        if(amount==0)return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int take=INT_MAX/2,nottake=INT_MAX/2;
        if(amount>=coins[ind])take=1+sol(coins,ind,amount-coins[ind]);
        nottake=sol(coins,ind-1,amount);
        dp[ind][amount]=min(take,nottake);
        return dp[ind][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=sol(coins,coins.size()-1,amount);
        return ans==INT_MAX/2?-1:ans;
    }
};