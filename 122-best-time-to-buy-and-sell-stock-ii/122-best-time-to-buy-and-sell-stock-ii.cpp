class Solution {
public:
    int dp[100005][2];
    int sol(vector<int> &prices,int pos,int buy){
        if(pos>=prices.size())return 0;
        int ans=0;
        if(dp[pos][buy]!=-1)return dp[pos][buy];
        if(buy){
            int a=sol(prices,pos+1,0)-prices[pos];
            int b=sol(prices,pos+1,1);
            ans=max(a,b);
        }else{
            int a=sol(prices,pos+1,1)+prices[pos];
            int b=sol(prices,pos+1,0);
            ans=max(a,b);
        }
        return dp[pos][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return sol(prices,0,1);
    }
};