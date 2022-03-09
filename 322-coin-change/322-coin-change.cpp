class Solution {
public:
    
    int coin(int i,int amt,vector<int> &coins,vector<vector<int>> &dp){
       if(amt==0) return 0;
        if(i>=coins.size()) return INT_MAX/2;
        if(dp[amt][i]!=-1) return dp[amt][i];
        
        if(coins[i]<=amt) return dp[amt][i] =min({1+coin(i,amt-coins[i],coins,dp),coin(i+1,amt,coins,dp)});
        else return dp[amt][i]=coin(i+1,amt,coins,dp);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+3,vector<int>(coins.size()+2,-1));
        int ans = coin(0,amount,coins,dp);
        
        if(ans>=INT_MAX/2) return -1;
        return ans;
        
    }
};