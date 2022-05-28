class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1,INT_MAX/2);
        dp[0]=0;
        for(int i=1;i<=amt;i++){
            for(int j=1;j<=coins.size();j++){
                if(coins[j-1]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j-1]]+1);
                }
            }
        }
        return dp[amt]==INT_MAX/2?-1:dp[amt];
    }
};