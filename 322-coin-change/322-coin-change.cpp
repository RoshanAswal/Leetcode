class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        
        for(int i=1;i<=amount;i++) dp[i] = INT_MAX/2;
        
        for(int i=1;i<=amount;i++){
            // int ss=INT_MAX;
            for(int j=1;j<=n;j++){
                if(coins[j-1]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j-1]]+1);
                }
            }
        }
        if(dp[amount]>=INT_MAX/2)return -1;
        return dp[amount];
    }
};